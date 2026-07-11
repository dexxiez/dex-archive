# dex-archive Conventions

Format: `.clang-format` (LLVM base, 2-space indent, aligned consecutive decls). Run clang-format before commit.

## Naming

- **Public prefix**: `dxa` (matches lib/file name `dxalib`/`dxa.h`), not `dexa` (that's reserved for the on-disk format name/magic "DEXA").
- **Types**: `PascalCase`, prefixed `Dxa` — e.g. `DxaCtx`, `DxaArchive`, `DxaAssetEntry`, `DxaArchiveHeader`.
- **Opaque handles**: `struct DxaArchive` (internal, in dxa.c) exposed as typedef `DxaCtx` (public, in dxa.h).
- **Functions**: `snake_case`, prefixed `dxa_` — e.g. `dxa_open`, `dxa_new`, `dxa_close`, `dxa_get_version`.
- **Variables**: `snake_case` — e.g. `file_ptr`, `toc_offset`, `items_written`.
- **Constants/macros**: `UPPER_SNAKE_CASE` — e.g. header guard `LIB_DXA_H`.

## Structure

- Public API + types live in `src/dxalib/dxa.h`.
- Implementation in `src/dxalib/dxa.c`; internal-only structs (not needed by callers) stay in the `.c` file, not the header.
- CLI entry point in `src/cli/main.c`, includes `dxa.h` only — never reaches into internal structs.
