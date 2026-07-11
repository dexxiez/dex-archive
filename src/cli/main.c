#include "dxa.h"
#include "stdio.h"
#include <stdint.h>

int main(void) {

  if (dxa_new("yeet.dexa") != 0) {
    printf("Error: File couldn't be created!\n");
    return 1;
  }

  DxaCtx *ctx = dxa_open("yeet.dexa");
  if (ctx == NULL) {

    printf("Error: File couldn't be opened!\n");
    return 1;
  }

  uint32_t ver = dxa_get_version(ctx);

  printf("Version: %u\n", ver);

  dxa_close(ctx);
}
