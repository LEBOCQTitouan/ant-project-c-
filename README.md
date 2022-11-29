# ant-project-cpp

## Project configuration

### Requirements

* a modern C++17 compiler (gcc-8, clang-6.0, MSVC 2017 or above)
* cmake 3.10+
* conan 1.28+ (optional)
* cppcheck (optional)
* clang-format (optional)

### Features

* CMake-based project management, including dependencies
* Conan support for dependency management in CMake, completely optional
* Additional tools such as clang-format and cppcheck

### Repository layout

```plain
-- conanfile.txt                - the main `conan` configuration file listing dependencies
-- cppcheck_suppressions.txt    - optional list of suppressions for cppcheck
-- CMakeLists.txt               - the main `CMake` Project configuration file
-- .dockerignore                - files to be excluded by Docker
-- .gitignore                   - files to be excluded by git

+- `cmake/`                     - CMake modules
  | -- clang-format.cmake       - CMake target definitions for clang-format
  | -- compiler-options.cmake   - Common compiler options for major platforms/compilers
  | -- cpack.cmake              - Packaging configuration with CPack
  | -- dependencies.cmake       - Project dependencies, CMake-Style
+- `src/`                       - the source files for the C++ project
  | -- CMakeLists.txt
+- `build/`                     - working directory for the build
```

### Available CMake Options

* BUILD_TESTING     - builds the tests (requires doctest)
* BUILD_SHARED_LIBS - enables or disables the generation of shared libraries
* BUILD_WITH_MT     - valid only for MSVC, builds libraries as MultiThreaded DLL

If you activate the BUILD_TESTING flag, you need to perform in advance a conan install step, just to fetch the doctest dependency. Another dependency (OpenSSL) is used in this project as a demonstration of including a third-party library in the process, but it is totally optional and you can activate it only if you run conan in advance.

### Build the project

```bash
cd /path/to/this/project
mkdir -p build # md build (on Windows)
cd build
conan install .. --build=missing # install debs and build missing one
cmake -DBUILD_TESTING=TRUE -DBUILD_SHARED_LIBS=TRUE ..
cmake --build .
cmake --build . --target format
cmake --build . --target package
```

## Project informations
