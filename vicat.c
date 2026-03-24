#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {

  if (argc <= 1) {
    printf("Input file needed\n");
    return EXIT_FAILURE;
  }

  for (int i = 1; i < argc; i++) {

    FILE *file = fopen(argv[i], "rb");
    if (!file) {
      perror("fopen");
      exit(EXIT_FAILURE);
    }
    unsigned char buffer[4096];
    size_t ret; 

    while ((ret = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, ret, stdout);
    }

    fclose(file);
  }
  return EXIT_SUCCESS;
}
