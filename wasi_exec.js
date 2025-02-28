const fs = require('fs');
const { WASI } = require('wasi');
const { argv } = require('process');
const { readFileSync } = require('fs');
const { join } = require('path');

if (argv.length < 3) {
    console.error('Usage: node wasi_exec.js <wasi_wasm_file>');
    process.exit(1);
}

const wasmFile = argv[2];

// Initialize WASI
const wasi = new WASI({
    args: argv.slice(3), // Pass additional command-line arguments to the WASM binary
    env: process.env,    // Pass the environment variables
    preopens: {
        '/': process.cwd() // Allow the WASI module to access the current directory
    }
});

// Load and run the WASM binary
(async () => {
    try {
        const wasmBuffer = readFileSync(wasmFile);
        const wasmModule = await WebAssembly.compile(wasmBuffer);
        const instance = await WebAssembly.instantiate(wasmModule, {
            wasi_snapshot_preview1: wasi.wasiImport
        });

        // Start the WASI program
        wasi.start(instance);
    } catch (e) {
        console.error(`Error executing WASI binary: ${e.message}`);
    }
})();