#include "dxa.h"
#include "stdio.h"
#include <stdint.h>

int main(void) {

  if (dexa_new("yeet.dexa") != 0) {
    printf("Error: File couldn't be created!\n");
    return 1;
  }

  DexaCtx *ctx = dexa_open("yeet.dexa");
  if (ctx == NULL) {

    printf("Error: File couldn't be opened!\n");
    return 1;
  }

  uint32_t ver = dexa_get_version(ctx);

  printf("Version: %u\n", ver);

  dexa_close(ctx);
}
