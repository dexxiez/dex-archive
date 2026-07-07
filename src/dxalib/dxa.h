#ifndef LIB_DXA_H
#define LIB_DXA_H

#include <stdint.h>

typedef struct DexArchive DexaCtx;

typedef struct {
  uint32_t asset_id;
  char     asset_path[124];
  char     mime_type[128];
  uint64_t offset;
  uint64_t compressed_size;
  uint64_t uncompressed_size;
} DxaAssetEntry;

int      dexa_new(const char *filepath);
DexaCtx *dexa_open(const char *filepath);
void     dexa_close(DexaCtx *ctx);
uint32_t dexa_get_version(DexaCtx *ctx);

#endif /* LIB_DXA_H */
