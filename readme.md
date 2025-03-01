# Results

## Desktop Language Comparison

In order to run this benchmark [NodeJS](https://nodejs.org), [Python](https://www.python.org/), [Lua](https://www.lua.org/), [LuaJIT](https://luajit.org/), and [WASM3](https://github.com/wasm3/wasm3) need to be available in the path.

Linux Fibonacchi(40)
|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|    1,886,656,339.00 |                0.53 |    0.0% |     20.79 | `Clang 18.1.3 Mizu(file) fib(40)`
|    1,892,165,759.00 |                0.53 |    0.2% |     20.93 | `Clang 18.1.3 Mizu fib(40)`
|    1,894,406,996.00 |                0.53 |    0.5% |     20.85 | `Clang 18.1.3 Mizu(file + loading) fib(40)`
|          783,967.00 |            1,275.56 |    8.5% |      0.01 | `APE(native) fib(40)`
|      396,016,565.00 |                2.53 |    0.3% |      4.38 | `Node v18.19.1 fib(40)`
|      562,648,738.00 |                1.78 |    0.8% |      6.23 | `LuaJIT 2.1.1736781742 fib(40)`
|    3,703,573,604.00 |                0.27 |    0.5% |     38.85 | `Lua 5.4.6 fib(40)`
|    3,442,506,976.00 |                0.29 |    0.2% |     37.87 | `Python 3.12.3 fib(40)`
|    9,826,000,712.00 |                0.10 |    0.1% |    108.02 | `WASM3(c) v0.5.0 fib(40)`

Linux Bubble-Sort(100)
|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|           67,043.30 |           14,915.73 |    0.9% |      0.01 | `Clang 18.1.3 Mizu(file + loading) bubble(100)`
|           68,544.06 |           14,589.16 |    0.5% |      0.01 | `Clang 18.1.3 Mizu(file + loading + data loading) bubble(100)`
|          531,774.00 |            1,880.50 |    5.8% |      0.01 | `APE(native) bubble(100)`
|       48,751,463.00 |               20.51 |    9.3% |      0.52 | `Node v18.19.1 bubble(100)`
|        1,076,501.00 |              928.94 |    4.1% |      0.01 | `LuaJIT 2.1.1736781742 bubble(100)`
|        2,433,660.00 |              410.90 |   39.7% |      0.03 | `Lua 5.4.6 bubble(100)`
|       18,527,142.00 |               53.97 |   17.0% |      0.20 | `Python 3.12.3 bubble(100)`
|        1,196,641.00 |              835.67 |    5.3% |      0.01 | `WASM3(c) v0.5.0 bubble(100)`



Windows Fibonacchi(40)
|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|    1,886,075,700.00 |                0.53 |    0.3% |     20.91 | `Mizu(file) fib(40)`
|    1,883,608,400.00 |                0.53 |    0.1% |     20.74 | `Mizu fib(40)`
|    1,881,302,200.00 |                0.53 |    0.1% |     20.72 | `Mizu(file + loading) fib(40)`
|      107,768,900.00 |                9.28 |    3.2% |      1.19 | `EXE(native) fib(40)`
|      367,994,100.00 |                2.72 |    0.2% |      4.07 | `Node fib(40)`
|      271,162,900.00 |                3.69 |    1.9% |      2.98 | `LuaJIT fib(40)`
|    2,872,786,800.00 |                0.35 |    1.1% |     32.49 | `Lua fib(40)`
|    3,345,244,700.00 |                0.30 |    0.2% |     37.08 | `Python fib(40)`
|    5,975,159,500.00 |                0.17 |    0.1% |     65.79 | `WASM3(c) fib(40)`

Windows Bubble-Sort(100)
|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|          753,700.00 |            1,326.79 |    6.9% |      0.01 | `Mizu(file + loading) bubble(100)`
|       41,054,600.00 |               24.36 |    5.0% |      0.47 | `EXE(native) bubble(100)`
|       37,495,300.00 |               26.67 |    2.2% |      0.42 | `Node bubble(100)`
|       13,400,800.00 |               74.62 |    4.5% |      0.16 | `LuaJIT bubble(100)`
|       10,486,200.00 |               95.36 |    6.1% |      0.14 | `Lua bubble(100)`
|       26,733,200.00 |               37.41 |   13.1% |      0.31 | `Python bubble(100)`
|       55,586,500.00 |               17.99 |    4.6% |      0.64 | `WASM3(c) bubble(100)`



M3 Mac Fibonacchi(40)
|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|    2,951,522,916.00 |                0.34 |    0.1% |     32.56 | `Apple Clang 15.0.0 Mizu(file) fib(40)`
|    2,951,555,708.00 |                0.34 |    0.0% |     32.47 | `Apple Clang 15.0.0 Mizu fib(40)`
|    2,964,114,500.00 |                0.34 |    0.2% |     32.81 | `Apple Clang 15.0.0 Mizu(file + loading) fib(40)`
|      170,608,583.00 |                5.86 |    0.2% |      2.05 | `EXE(native) fib(40)`
|      419,975,458.00 |                2.38 |    0.2% |      4.62 | `Node v23.7.0 fib(40)`
|      443,358,458.00 |                2.26 |    1.9% |      4.89 | `LuaJIT 2.1.1736781742 fib(40)`
|    3,608,061,375.00 |                0.28 |    0.3% |     39.12 | `Lua 5.4.7 fib(40)`
|    6,642,663,500.00 |                0.15 |    0.2% |     73.02 | `Python 3.13.2 fib(40)`
|    2,078,485,583.00 |                0.48 |    0.1% |     22.87 | `Wasm3(c) v0.5.0 fib(40)`

M3 Mac Bubble-Sort(100)
|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|          117,995.44 |            8,474.90 |    2.2% |      0.01 | `Apple Clang 15.0.0 Mizu(file + loading) bubble(100)`
|        2,691,500.00 |              371.54 |    9.6% |      0.17 | `EXE(native) bubble(100)`
|       21,740,542.00 |               46.00 |    1.5% |      0.25 | `Node v23.7.0 bubble(100)`
|        2,391,542.00 |              418.14 |    2.3% |      0.03 | `LuaJIT 2.1.173678174 bubble(100)`
|        2,512,958.00 |              397.94 |    2.7% |      0.03 | `Lua 5.4.7 bubble(100)`
|       16,242,208.00 |               61.57 |    1.0% |      0.18 | `Python 3.13.2 bubble(100)`
|        2,784,708.00 |              359.10 |    4.2% |      0.03 | `Wasm3(c) v0.5.0 bubble(100)`


## Web Benchmarks

PC (linux)
|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|   19,851,700,000.00 |                0.05 |    0.1% |    218.49 | `Mizu(WASM/Chrome) fib(40)`
|    8,278,000,000.00 |                0.12 |    0.1% |     91.14 | `Mizu(WASM/Firefox) fib(40)`
|        2,284,705.88 |              437.69 |   24.4% |      1.82 | `Mizu(WASM/Chrome) bubble(100)`
|        2,545,454.55 |              392.86 |   21.9% |      2.04 | `Mizu(WASM/Firefox) bubble(100)`



# Running The Benchmark

cmake .. -DCMAKE_TOOLCHAIN_FILE=/home/joshuadahl/Dev/wasi-sdk/build/install/share/cmake/wasi-sdk.cmake -DBENCHMARK_MODE=wasi -DMIZU_ENABLE_LIB_FFI=off -DMIZU_NO_EXCEPTIONS=on -DCMAKE_BUILD_TYPE=Release
emcmake cmake .. -DBENCHMARK_MODE=web -DMIZU_NO_EXCEPTIONS=on -DCMAKE_BUILD_TYPE=Release

CC=/nix/store/wb8gf373j9isni6b0bwhf5bvmcmr4cbi-avr-gcc-wrapper-13.3.0/bin/avr-gcc CXX=/nix/store/wb8gf373j9isni6b0bwhf5bvmcmr4cbi-avr-gcc-wrapper-13.3.0/bin/avr-g++ cmake .. -DBENCHMARK_MODE=arduino -DFP_FETCH_EXTERNAL_CPPSTL=on -DMIZU_ENABLE_HARDWARE_THREADS=off -DMIZU_NO_EXCEPTIONS=on -DCMAKE_BUILD_TYPE=MinSizeRel

avr-objcopy -O ihex arduino.bubble arduino.hex 

make arduino.fib
avr-objcopy -O ihex arduino.fib arduino.hex 
avrdude -v -patmega2560 -cwiring -P/dev/ttyACM0 -D -Uflash:w:arduino.hex
screen /dev/ttyACM0 9600
