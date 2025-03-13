#define F_CPU 16000000UL  // Assuming 16 MHz clock frequency
#define BAUD 9600

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <cstdint>

volatile uint64_t overflow_count = 0;

ISR(TIMER0_OVF_vect) {
	overflow_count++; // Increment overflow count every time Timer0 overflows
}

void timer0_init() {
	// Set Timer0 to Normal mode
	TCCR0A = 0x00;

	// Set prescaler to 64 (16MHz / 64 = 250 kHz timer clock, 4 us per tick)
	TCCR0B = (1 << CS01) | (1 << CS00);

	// Enable Timer0 overflow interrupt
	TIMSK0 = (1 << TOIE0);

	// Enable global interrupts
	sei();
}

uint64_t micros() {
	uint64_t elapsed;
	uint8_t tcnt;

	cli(); // Disable interrupts to ensure atomic access
	elapsed = overflow_count * 256UL * 4; // Each overflow is 256 ticks, each tick is 4 us
	tcnt = TCNT0; // Read current timer value
	sei(); // Re-enable interrupts

	elapsed += (uint64_t)tcnt * 4; // Add the elapsed time since last overflow
	return elapsed;
}

void init_uart(unsigned int ubrr) {
	// Set the baud rate
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;

	// Enable transmitter
	UCSR0B = 1 << 3;

	// Set frame format: 8 data bits, 1 stop bit
	UCSR0C = 1 << 2 | 1 << 1;
}

void uart_transmit_byte(unsigned char data) {
	// Wait for the transmit buffer to be empty
	while (!(UCSR0A & (1 << 5)));

	// Put data into the transmit buffer
	UDR0 = data;
}

void uart_send(const char* str) {
	while (*str) {
		uart_transmit_byte(*str);
		str++;
	}
}



// #define MIZU_ENABLE_TRACING
#define MIZU_IMPLEMENTATION
#ifdef BENCHMARK_BUBBLE
	#define BENCHMARK_BUBBLE_ONE_HUNDRED
	#include "bubble_program.h"
#else
	#include "fib_program.h"
#endif
// namespace mizu { extern void delay(std::chrono::microseconds time, opcode*& pc, uint64_t& storage_register) { /*Not Implemented!*/ } }

// C++ overrides
_GLIBCXX_NODISCARD __attribute__((__externally_visible__)) void* operator new(std::size_t size) _GLIBCXX_THROW (std::bad_alloc) {
	return malloc(size);
}
inline void operator delete  (void* p, size_t) _GLIBCXX_USE_NOEXCEPT {
	return free(p);
}

void *__dso_handle __attribute__ ((__visibility__ ("hidden"))) = 0;





void print_results(uint64_t total_microseconds) {
	uint64_t total_nanoseconds = total_microseconds * 1000;
	uint64_t total_seconds = total_nanoseconds / 1000000000;
#ifdef BENCHMARK_BUBBLE
	auto str = fp_string_format("| %lu | %lu | ??? | %lu | `Mizu(ATmega2560) bubble(100)`\n\r\n\r", total_nanoseconds, total_seconds, total_seconds);
#else
	auto str = fp_string_format("| %lu | %lu | ??? | %lu | `Mizu(ATmega2560) fib(40)`\n\r\n\r", total_nanoseconds, total_seconds, total_seconds);
#endif
	uart_send(str);
	fp_string_free_and_null(str);
}

registers_and_stack env = {};

int main(void) {
	init_uart(F_CPU / 16 / BAUD - 1);
	timer0_init();

	while(true) {

		uart_send("|               ns/op |                op/s |    err% |     total | benchmark\n\r"
			"|--------------------:|--------------------:|--------:|----------:|:----------\n\r");

		// auto start = micros();
		// auto micros_time = micros() - start;


		// for(size_t i = 0; i < 100; ++i) {
			auto start = micros();

			std::memset(env.memory.data(), 0, env.memory.size() * sizeof(env.memory[0]));
			setup_enviornment(env);

#ifdef BENCHMARK_BUBBLE
			MIZU_START_FROM_ENVIORNMENT(bubble_program, env);
#else
			MIZU_START_FROM_ENVIORNMENT(fib_program, env);
#endif

			auto end = micros();
			auto total = end - start; //- micros_time;

			// auto str = fp_string_format("%lu\n\r", i);
			// uart_send(str);
			// fp_string_free(str);
		// }
		print_results(total);
	}

	return 0;
}