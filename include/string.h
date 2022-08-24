#ifndef __STRING_H__
#define __STRING_H__

typedef struct {
    char* value;
    size_t length;
} string;

extern void strcat_memcpy(string* a,string* b);

#endif