## Purpose

This file tells AI coding assistants how this repository is organized and the concrete workflows they should follow to be productive immediately.

## High-level architecture (big picture)

- Language: C++ (project-wide standard is C++17). Compiler flags are set in the top-level `CMakeLists.txt` (`-std=c++17 -Wall`).
- Layout:
  - `inc/` — shared headers and third-party single-file libs (Catch v2 single-header at `inc/catch.hpp`).
  - `src/` — primary source code. Two main subtrees:
    - `src/examples/` — instructor examples, each topic in a numeric-prefixed folder (e.g. `00_hello_world`, `01_data_types`). Each subfolder contains its own `CMakeLists.txt` and `add_executable` targets named like `ex_01_01_exe`.
    - `src/homework/` — student/homework programs, similar structure and naming but targets prefixed with `hw_`.
  - `test/` — unit tests mirror the `src` substructure with `test/examples/` and `test/homework/`; tests use Catch and are exposed to CTest using `add_test` with targets named `ex_XX_tests` or `hw_XX_tests`.
- Top-level CMake behavior:
  - `CMakeLists.txt` includes `inc` and runs a `HEADER_DIRECTORIES` macro that recursively finds `*.h` files and adds their directories to include paths. Expect headers anywhere under the repo to be automatically added to include dirs.
  - `enable_testing()` and `ADD_SUBDIRECTORY(test)` are used so `ctest`/`make test` runs the Catch test targets.

## Important developer workflows (concrete commands)

- Local full build + tests (from repo root):

```bash
mkdir -p build
cd build
cmake ..
cmake --build . -- -j
ctest --output-on-failure
```

- Build & run a single example or test target (from `build`):

```bash
cmake --build . --target ex_00_01_exe -j
# example binary will be located under the build tree, e.g.:
./src/examples/00_hello_world/ex_00_01_exe

# run a single test target that was added with add_test:
ctest -R ex_05_tests --output-on-failure
```

- CI: GitHub Actions runs `.github/build.sh` and `.github/unit_tests.sh`.
  - `build.sh` sets `CC=clang CXX=clang++`, creates `../build`, runs `cmake ../*` from the `.github` dir and `make`.
  - `unit_tests.sh` runs `cd ../build && make test`.

## Project-specific conventions and patterns

- Numeric prefixes for ordering: folders in `src/examples` and `src/homework` use `NN_description` (e.g. `05_functions`) — keep that naming when adding content.
- Executable naming pattern:
  - Examples: `ex_<chapter>_<item>_exe` (e.g. `ex_05_01_exe`).
  - Homework: `hw_<chapter>_exe` or `hw_tic_tac_toe_exe` depending on the folder.
  - Test targets: `ex_XX_tests` or `hw_XX_tests`; test CMake files call `add_test(NAME <target> COMMAND <target> -s)` so test output is shown when running `ctest`.
- Headers: the top-level `HEADER_DIRECTORIES` macro auto-discovers `*.h` and adds directories. When adding headers, you normally do not need to manually add include dirs unless you intend a non-standard layout.
- Tests use the Catch single-header (`inc/catch.hpp`). Many test source files include `#define CATCH_CONFIG_MAIN` once per test target (or tests provide a main via CMake test executables).

## Integration points & external dependencies

- Catch2 single-header is vendored at `inc/catch.hpp` (Catch v2.13.9) — tests depend on this file.
- CI uses `clang` by default in `.github/build.sh`, but the CMake toolchain is flexible and will respect `CC`/`CXX` env vars.

## How to add new code / tests (quick examples)

- Add a new example:
  1. Create `src/examples/NN_new_topic/` with `main.cpp` and any sources.
  2. Add a `CMakeLists.txt` in that folder with `add_executable(ex_NN_XX_exe "main.cpp" ...)`.
  3. Add `ADD_SUBDIRECTORY(NN_new_topic)` to `src/examples/CMakeLists.txt` (consistent ordering by numeric prefix).

- Add a new test:
  1. Create `test/examples/NN_new_topic/NN_new_topic_tests.cpp` and include `catch.hpp`.
  2. In that test folder's `CMakeLists.txt` create `add_executable(ex_NN_tests "NN_new_topic_tests.cpp")` and `add_test(NAME ex_NN_tests COMMAND ex_NN_tests -s)`.

## Files to inspect first when debugging or changing behavior

- `CMakeLists.txt` (root) — compiler flags and macros like `HEADER_DIRECTORIES`.
- `src/CMakeLists.txt` and `src/examples/CMakeLists.txt` — where example subdirs are wired.
- `test/CMakeLists.txt` and the per-test `CMakeLists.txt` — test targets and `add_test` usage.
- `inc/catch.hpp` — vendored test framework.
- `.github/build.sh` and `.github/unit_tests.sh` — reflect CI behavior (clang usage, where build dir is created).

## What not to change without coordination

- The `HEADER_DIRECTORIES` macro behavior (it auto-adds include directories) — changing it may break how headers are resolved across many small example/homework folders.
- The numeric ordering in `src/examples` and the names used by CMake subdirectory inclusion; renaming without updating `src/examples/CMakeLists.txt` will exclude content from builds.

## Quick checklist for an AI agent submitting code changes

1. Build locally in `build/` and run `ctest` until green.
2. New examples should follow the numeric prefix + `ex_` naming convention; new tests must use Catch and be wired with `add_test`.
3. If you need new include dirs, prefer placing headers under the repo tree so `HEADER_DIRECTORIES` picks them up.

---
If anything here is unclear or you'd like the instructions to include more examples (for instance the exact path to run an exe from the build tree on your machine), tell me which section and I'll expand it.
