#include <stdio.h>


char *read_file_errorProne(const char* path) {
  FILE *in = fopen(path, "rb");
  fseek(in, 0, SEEK_END);
  const long file_size = ftell(in);
  fseek(in, 0, SEEK_SET);
  char *data = malloc(file_size);
  fread(data, 1, file_size, in);
  fclose(in);
  return data;
}


int read_file_noEnum(const char* path, int *size, char **out) {
  FILE *in = fopen(path, "rb");
  if (in == NULL) {
    return -1;
  }
  
  int res = fseek(in, 0, SEEK_END);
  if (res == -1) {
    fclose(in);
    return -1;
  }
  
  const long file_size = ftell(in);
  if (file_size == -1) {
    fclose(in);
    return -1;
  }
  
  res = fseek(in, 0, SEEK_SET);
  if (res == -1) {
    fclose(in);
    return -1;
  }
  
  *out = malloc(file_size);
  if (*out == NULL) {
    fclose(in);
    return -1;
  }
  
  res = fread(*out, 1, file_size, in);
  if (res < file_size && ferror(in)) {
    free(*out);
    fclose(in);
    return -1;
  }
  
  if (fclose(in) != 0) {
    free(*out);
    return -1;
  }
  
  return 0;
}

enum error_code { EC_OK, EC_INVALID_PARAM, EX_SYS};

int read_file_enum(const char* path, long *file_size, char **out) {
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

#define EC_FROM_SYS_ERROR(e) (EC_SYS + e)
#define EC_TO_SYS_ERROR(e) (e - EC_SYS)
#define EC_IS_SYS_ERROR(e) (e >= EC_SYS)

#define FAIL_PRED(pred, status)\
  do { if (pred) { _status = status; goto fail; } } while(0)
#define FAIL_SYS(pred)\
  do { if (pred) { _status = EC_FROM_SYS_ERROR(errno); goto fail; } }	\
  while(0)
#define FAIL_FORWARD(expr)\
  do { _status = expr; if (_status != EC_OK) goto fail; } while(0)

int read_file(const char* path, long *file_size, char **out) {
  int _status = EC_OK;
  FILE *in = NULL;
  *out = NULL;
  FAIL_PRED(path == NULL, EC_INVALID_PARAM);
  FAIL_SYS((in=fopen(path, "rb")) == NULL);
  FAIL_SYS(fseek(in, 0, SEEK_END)!=0);
  FAIL_SYS((*file_size = ftell(in)) == -1);
  FAIL_SYS(fseek(in, 0, SEEK_SET) == -1);
  FAIL_SYS((*out=malloc(*file_size)) == NULL);
  const int read = fread(*out, 1, *file_size, in);
  FAIL_SYS(read != *file_size && ferror(in));
  FAIL_SYS(fclose(in) != 0);
  return 0;
 fail:
  free(*out);
  if (in != NULL) {fclose(in)};
  return _status;
}

struct error_string{
  int code;
  const char *message;
};

static struct error_string error_string[] = {
  {EC_OK, "No error encountered"},
  {EC_INVALID_PARAM, "Invalid parameter"}
};

void ec_strerror(const int status, char* buffer, const size_t buffer_length) {
  if (EC_IS_SYS_ERROR(status)){
    strerror_r(EC_TO_SYS_ERROR(status), buffer, buffer_length);
    printf("%s\n",buffer);
  } else {
    size_t str_cnt = sizeof(error_strings) / sizeof(struct error_string);
    for(size_t i=0; i < str_cnt; ++i) {
      if (error_strings[i].code == status){
	  strncpy(buffer, error_strings[i].message, buffer_length);
	  return;
	}
    }
    strncpy(buffer, "An invalid/unhandled error code was encountered. Please report.", buffer_length);
  }
}


