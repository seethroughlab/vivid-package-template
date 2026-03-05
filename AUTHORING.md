# Package Authoring Guide

This guide defines recommended conventions for Vivid package maintainers.

## Naming Conventions

- Repository name: `vivid-<domain-or-feature>` (for example `vivid-geometry`, `vivid-rhythms`).
- Manifest package name (`vivid-package.json` `name`): match repository name.
- Operator target names in CMake: lowercase snake_case and stable over time.
- Operator type names (`kName`): PascalCase; avoid collisions with core/package operators.

## Versioning Conventions

- Use SemVer for package `version` in `vivid-package.json`.
- Bump policy:
  - Patch (`x.y.Z`): bug fixes, behavior-preserving internal changes.
  - Minor (`x.Y.z`): additive operator params/ops, backward-compatible graph behavior.
  - Major (`X.y.z`): breaking graph/param/operator changes.
- Keep `vivid_core` range current (for example `>=0.1.0 <2.0.0`).

## Dependency Guidance

- Prefer self-contained packages with minimal dependencies.
- If using vendored headers/libraries, include them under package-local `deps/` and declare under `dependencies.vendor`.
- If depending on other Vivid packages, declare under `dependencies.packages` and verify install order/compatibility.
- Avoid heavy transitive dependency trees unless clearly justified.

## Release Tagging

- Tag releases as `v<version>` (for example `v0.3.1`).
- Ensure tag version matches `vivid-package.json` `version` exactly.
- Add release notes summarizing operator additions/fixes and any compatibility impact.

## Compatibility Notes

Each release should state:

- Supported `vivid_core` range.
- Breaking changes (if any) and migration notes.
- Whether existing saved graphs require edits.

## Pre-Release Checklist

- [ ] `vivid-package.json` name/version/vivid_core validated
- [ ] Graph smoke passes (`test_demo_graphs ./graphs`)
- [ ] Package tests pass (`ctest` with `BUILD_PACKAGE_TESTS=ON`, if present)
- [ ] Install/rebuild/uninstall flow validated locally
- [ ] Git tag created and pushed (`vX.Y.Z`)
