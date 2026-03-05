# your-package-name

Multi-operator package template with demos/tests.

## Install

```bash
./build/vivid install https://github.com/your-org/your-package-name.git
```

## Test

```bash
# Graph smoke (from vivid-core build)
../vivid/build/test_demo_graphs ./graphs

# Package-local tests
cmake -B build-ci -S . -DVIVID_SRC_DIR=../vivid -DBUILD_PACKAGE_TESTS=ON
cmake --build build-ci --target test_package_placeholder
ctest --test-dir build-ci --output-on-failure
```
