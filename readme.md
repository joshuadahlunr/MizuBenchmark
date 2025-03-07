# Results

## Desktop Language Comparison

In order to run this benchmark [NodeJS](https://nodejs.org), [Python](https://www.python.org/), [Numba](https://github.com/numba/numba), [DotNet](https://dotnet.microsoft.com/en-us/) [Lua](https://www.lua.org/), [LuaJIT](https://luajit.org/), and [WASM3](https://github.com/wasm3/wasm3) need to be available in the path.

Additionally the bubble sort test requires 30kb of virtual stack space, thus line 71 in MizuVM/mizu/opcode.hpp must be tweaked to multiply by 30 instead of 5.

Linux Fibonacchi(40)
|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|    1,934,220,740.00 |                0.52 |    0.0% |     21.30 | `GCC 13.3.0 Mizu(file) fib(40)`
|    1,973,094,603.00 |                0.51 |    0.8% |     21.67 | `GCC 13.3.0 Mizu fib(40)`
|    1,934,022,423.00 |                0.52 |    0.0% |     21.33 | `GCC 13.3.0 Mizu(file + loading) fib(40)`
|    1,984,024,460.00 |                0.50 |    0.1% |     21.98 | `Clang 18.1.3 Mizu(file) fib(40)`
|    1,936,542,839.00 |                0.52 |    0.0% |     21.32 | `Clang 18.1.3 Mizu fib(40)`
|    1,937,856,961.00 |                0.52 |    0.2% |     21.50 | `Clang 18.1.3 Mizu(file + loading) fib(40)`
|          659,612.23 |            1,516.04 |    4.6% |     81.94 | `APE(native) fib(40)`
|      394,396,350.00 |                2.54 |    0.3% |      4.33 | `Node v18.19.1 fib(40)`
|      245,554,699.39 |                4.07 |    0.1% |    292.95 | `C# dotnet8.0.112 fib(40)`
|      565,252,299.00 |                1.77 |    1.4% |      6.22 | `LuaJIT 2.1.1736781742 fib(40)`
|    3,311,031,864.00 |                0.30 |    0.7% |     37.63 | `Lua 5.4.6 fib(40)`
|    3,414,371,980.00 |                0.29 |    0.1% |     37.62 | `Python 3.12.3 fib(40)`
|    3,599,891,078.00 |                0.28 |    0.3% |     39.66 | `Numba 0.61.0 fib(40)`
|    9,744,831,833.00 |                0.10 |    0.2% |    107.23 | `WASM3(c) v0.5.0 fib(40)`

Linux Bubble-Sort(1100)
|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|        8,647,514.46 |              115.64 |    0.1% |     10.32 | `GCC 13.3.0 Mizu(file + loading) bubble(1100)`
|        8,652,469.56 |              115.57 |    0.0% |     10.34 | `GCC 13.3.0 Mizu(file + loading + data loading) bubble(1100)`
|        8,691,832.29 |              115.05 |    0.1% |     10.39 | `Clang 18.1.3 Mizu(file + loading) bubble(1100)`
|        8,687,456.57 |              115.11 |    0.1% |     10.37 | `Clang 18.1.3 Mizu(file + loading + data loading) bubble(1100)`
|        2,045,363.01 |              488.91 |    3.7% |    240.43 | `APE(native) bubble(1100)`
|       51,025,729.66 |               19.60 |    0.6% |     60.97 | `Node v18.19.1 bubble(1100)`
|       23,865,895.32 |               41.90 |    2.6% |     28.50 | `C# dotnet8.0.112 bubble(1100)`
|       16,243,793.76 |               61.56 |    3.7% |     19.36 | `LuaJIT 2.1.1736781742 bubble(1100)`
|       21,355,307.02 |               46.83 |    1.6% |     25.18 | `Lua 5.4.6 bubble(1100)`
|       78,802,228.60 |               12.69 |    0.3% |     94.07 | `Python 3.12.3 bubble(1100)`
|      255,981,218.39 |                3.91 |    0.2% |    305.49 | `Numba 0.61.0 bubble(1100)`
|       21,067,719.54 |               47.47 |    2.0% |     25.02 | `WASM3(c) v0.5.0 bubble(1100)`



Windows Fibonacchi(40)
|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|    1,878,512,500.00 |                0.53 |    0.1% |     20.66 | `MSYS UCRT64 GCC 14.2.0 Mizu(file) fib(40)`
|    1,879,747,000.00 |                0.53 |    0.1% |     20.67 | `MSYS UCRT64 GCC 14.2.0 Mizu fib(40)`
|    1,881,879,700.00 |                0.53 |    0.2% |     20.75 | `MSYS UCRT64 GCC 14.2.0 Mizu(file + loading) fib(40)`
|      107,768,900.00 |                9.28 |    3.2% |      1.19 | `EXE(native) fib(40)`
|      367,994,100.00 |                2.72 |    0.2% |      4.07 | `Node v22.14.0 fib(40)`
|      271,162,900.00 |                3.69 |    1.9% |      2.98 | `LuaJIT 2.1.ROLLING fib(40)`
|    2,872,786,800.00 |                0.35 |    1.1% |     32.49 | `Lua 5.4.2 fib(40)`
|    3,345,244,700.00 |                0.30 |    0.2% |     37.08 | `Python 3.13.2 fib(40)`
|    5,975,159,500.00 |                0.17 |    0.1% |     65.79 | `WASM3(c) v0.5.1 fib(40)`

Windows Bubble-Sort(1100)
|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|        8,519,995.41 |              117.37 |    0.2% |     10.16 | `MSYS UCRT64 GCC 14.2.0 Mizu(file + loading) bubble(1100)`
|        8,558,027.52 |              116.85 |    0.2% |     10.23 | `MSYS UCRT64 GCC 14.2.0 Mizu(file + loading + data loading) bubble(1100)`
|       41,054,600.00 |               24.36 |    5.0% |      0.47 | `EXE(native) bubble(1100)`
|       37,495,300.00 |               26.67 |    2.2% |      0.42 | `Node v22.14.0 bubble(1100)`
|       13,400,800.00 |               74.62 |    4.5% |      0.16 | `LuaJIT 2.1.ROLLING bubble(1100)`
|       10,486,200.00 |               95.36 |    6.1% |      0.14 | `Lua 5.4.2 bubble(1100)`
|       26,733,200.00 |               37.41 |   13.1% |      0.31 | `Python 3.13.2 bubble(1100)`
|       55,586,500.00 |               17.99 |    4.6% |      0.64 | `WASM3(c) v0.5.1 bubble(1100)`



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

M3 Mac Bubble-Sort(1100)
|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|       12,218,798.64 |               81.84 |    0.1% |    145.95 | `Apple Clang 15.0.0 Mizu(file + loading) bubble(1100)`
|       12,161,291.67 |               82.23 |    0.2% |     14.52 | `Mizu(file + loading + data loading) bubble(1100)`
|        2,457,126.17 |              406.98 |    0.2% |    294.83 | `EXE(native) bubble(1100)`
|       25,122,511.29 |               39.80 |    0.2% |     31.15 | `Node v23.7.0 bubble(1100)`
|        4,370,484.72 |              228.81 |    0.3% |      5.29 | `LuaJIT 2.1.173678174 bubble(1100)`
|       22,244,247.14 |               44.96 |    0.1% |     26.53 | `Lua 5.4.7 bubble(1100)`
|      121,415,521.84 |                8.24 |    0.1% |    144.83 | `Python 3.13.2 bubble(1100)`
|       25,943,372.47 |               38.55 |    0.2% |     31.00 | `Wasm3(c) v0.5.0 bubble(1100)`


## WASM Benchmarks

PC (linux)
|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|   20,178,235,000.00 |                0.05 |    0.1% |    221.57 | `Mizu(Emscripten/Linux Chrome) fib(40)`
|   45,185,000,000.00 |                0.02 |    0.7% |    496.62 | `Mizu(Emscripten/Linux Firefox) fib(40)`
|   13,429,288,639.00 |                0.07 |    0.1% |    147.80 | `Mizu(WASI/Linux NodeJS) fib(40)`
|       81,240,595.24 |               12.31 |    1.2% |    105.62 | `Mizu(Emscripten/Linux Chrome) bubble(1100)`
|      207,782,321.43 |                4.81 |    1.2% |    271.04 | `Mizu(Emscripten/Linux Firefox) bubble(1100)`
|       57,434,897.81 |               17.41 |    0.0% |     74.88 | `Mizu(WASI/Linux NodeJS) bubble(1100)`



### Running The Benchmark

emcmake cmake .. -DBENCHMARK_MODE=web -DMIZU_NO_EXCEPTIONS=on -DCMAKE_BUILD_TYPE=Release
emrun web.html

cmake .. -DCMAKE_TOOLCHAIN_FILE=/home/joshuadahl/Dev/wasi-sdk/build/install/share/cmake/wasi-sdk.cmake -DBENCHMARK_MODE=wasi -DMIZU_ENABLE_LIB_FFI=off -DMIZU_NO_EXCEPTIONS=on -DCMAKE_BUILD_TYPE=Release
node --experimental-wasm-return_call ../wasi_exec.js wasi
