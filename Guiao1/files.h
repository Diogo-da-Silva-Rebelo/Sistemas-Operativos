#ifndef SISTEMAS_OPERATIVOS_FILES_H
#define SISTEMAS_OPERATIVOS_FILES_H
#define BUF_SIZE 1000
#define LINE_SIZE 100
#include <sys/types.h>
#include <unistd.h>

/* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* O_RDONLY, O_WRONLY, O_CREAT, O_*
int open(const char *path, int oflag [, mode]);
ssize_t read(int fildes, void *buf, size_t nbyte);
ssize_t write(int fildes, const void *buf, size_t nbyte);
off_t lseek(int fd, off_t offset, int whence);
close(int fildes);*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t myreadln(int fd, char* line, size_t size);
ssize_t myreadln2(int fd, char* line, size_t size);

#endif //SISTEMAS_OPERATIVOS_FILES_H
