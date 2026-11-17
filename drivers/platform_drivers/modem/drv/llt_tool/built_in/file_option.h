#ifndef ST_FILE_OPTION_H
#define ST_FILE_OPTION_H

#ifdef __cplusplus
extern "C" {
#endif

int create_file(char* path);
int write_to_file(char* path, unsigned char* info, unsigned int size, unsigned long long offset);
int read_from_file(char* path, unsigned char* info, unsigned int size, unsigned long long offset);
int open_directory(char* dir);
int create_directory(char* dir);

#ifdef __cplusplus
}
#endif

#endif