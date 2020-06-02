enum error_code { EC_OK, EC_INVALID_PARAM, EX_SYS};

int read_file(const char* path, long *file_size, char **out) {
  int status = EC_OK;
  FILE *in = NULL;
  *out = NULL;
  if (path == NULL){
    status=EC_INVALID_PARAM;
    goto fail;
  }
  if ((in=fopen(path, "rb"))==NULL) {
    status=EC_SYS+errno;
    goto fail;
  }
  if (fseek(in, 0, SEEK_END)!=0) {
    status=EC_SYS+errno;
    goto fail;
  }
  if ((*file_size = ftell(in))==-1) {
    status=EC_SYS+errno;
    goto fail;
  }
  if (fseek(in, 0, SEEK_SET)==-1) {
    status=EC_SYS+errno;
    goto fail;
  }
  if ((*out=malloc(*file_size))==NULL) {
    status=EC_SYS+errno;
    goto fail;
  }
  const int read = fread(*out, 1, *file_size, in);
  if (read!=*file_size && ferror(in)) {
    status=EC_SYS+errno;
    goto fail;
  }
  if (fclose(in) != 0) {
    status=EC_SYS+errno;
    goto fail;
  }
  return 0;
 fail:
  free(*out);
  if (in != NULL) {
    fclose(in);
  }
  return status;
}
