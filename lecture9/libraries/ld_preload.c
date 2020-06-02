#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>

FILE *fopen(const char *path, const char *mode) {
  fprintf(stderr, "Opening file: %s\n", path);
  FILE *(*real_fopen)(const char *path, const char *mode);
  real_fopen = dlsym(RTLD_NEXT, "fopen");
  return real_fopen(path, mode);
}

//setenv ld_preload /homes/dilan-sheth/cLectures/lectur9/libraries/ld_preload.so
