#ifndef LIB_STRING_H
#define LIB_STRING_H

typedef unsigned int size_t;
typedef size_t uintptr_t;

void *memcpy(void *dst, void *src, size_t n);
void *memset(void *str, int a, size_t n);

#endif
