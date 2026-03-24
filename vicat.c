#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {

  for (int i = 1; i < argc; i++) {

    FILE *file = fopen(argv[i], "r");
    if (!file) {
      printf("File not found");
      return EXIT_FAILURE;
    }

    int c;
    while ((c = fgetc(file)) != EOF) {
      putchar(c);
    }

    fclose(file);
  }
  return EXIT_SUCCESS;
}
