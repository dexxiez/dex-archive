#ifndef LIB_DXA_H
#define LIB_DXA_H

#include <stdint.h>

typedef struct DxaArchive DxaCtx;

typedef struct {
  uint32_t asset_id;
  char     asset_path[124];
  char     mime_type[128];
  uint64_t offset;
  uint64_t compressed_size;
  uint64_t uncompressed_size;
} DxaAssetEntry;

int      dxa_new(const char *filepath);
DxaCtx  *dxa_open(const char *filepath);
void     dxa_close(DxaCtx *ctx);
uint32_t dxa_get_version(DxaCtx *ctx);

#endif /* LIB_DXA_H */
