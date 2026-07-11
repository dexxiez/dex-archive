#include "dxa.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DxaArchive {
  FILE    *file_ptr;
  uint32_t version;
  uint64_t toc_offset;
};

struct DxaArchiveHeader {
  char     magic[4] __attribute__((nonstring));
  uint32_t version;
  uint64_t toc_offset;
};

DxaCtx *dxa_open(const char *filepath) {

  FILE *f = fopen(filepath, "r+b");
  if (!f)
    return NULL;

  struct DxaArchive *ctx = malloc(sizeof(struct DxaArchive));

  struct DxaArchiveHeader header;

  fread(&header, sizeof(struct DxaArchiveHeader), 1, f);

  if (memcmp(header.magic, "DEXA", 4) != 0) {
    printf("Error: Not a valid DEXA file!\n");
    fclose(f);
    return NULL;
  }

  ctx->file_ptr = f;
  ctx->version = header.version;
  ctx->toc_offset = header.toc_offset;

  return ctx;
}

int dxa_new(const char *filepath) {

  FILE *f = fopen(filepath, "wb");
  if (!f)
    return -1;

  struct DxaArchiveHeader header = {
      .magic = "DEXA", .version = 67, .toc_offset = 0};

  size_t items_written = fwrite(&header, sizeof(struct DxaArchiveHeader), 1, f);

  if (items_written != 1) {
    printf("Error writing to file.\n");
  } else {
    printf("Struct written to file successfully!\n");
  }

  fclose(f);
  return 0;
}

uint32_t dxa_get_version(DxaCtx *ctx) { return ctx->version; }

void dxa_close(DxaCtx *ctx) {
  if (ctx) {
    if (ctx->file_ptr)
      fclose(ctx->file_ptr);
    free(ctx);
  }
}
