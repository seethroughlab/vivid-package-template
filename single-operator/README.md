# your-package-name

Single-operator Vivid package.

## Install

```bash
./build/vivid install https://github.com/your-org/your-package-name.git
```

## Dev loop

```bash
./build/vivid link ../your-package-name
./build/vivid rebuild your-package-name
```

## CI expectations

- Graph smoke via `test_demo_graphs ./graphs`
- Package C++ test placeholder via `ctest` when `BUILD_PACKAGE_TESTS=ON`
