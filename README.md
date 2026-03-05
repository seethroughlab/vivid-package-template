# Vivid Package Template

Official package skeletons for Vivid package authors.

## Included templates

- `single-operator/`: minimal package with one operator
- `multi-operator/`: package with multiple operators, demo graphs, and tests

## Standard files included

Both templates include:

- `vivid-package.json`
- `CMakeLists.txt`
- `README.md`
- `LICENSE`
- `AGENTS.md`
- `.github/workflows/smoke.yml`

## Usage

1. Copy one template directory.
2. Replace placeholder names/metadata.
3. Build/test in your package repo.
4. Validate with vivid:
   - `./build/vivid link ../your-package`
   - `./build/vivid rebuild your-package-name`

## Notes

- Keep `vivid-package.json` operator entries in sync with `operators/`.
- Keep smoke CI passing against vivid-core.
