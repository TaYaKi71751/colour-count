#ifndef __COUNT_H__
#define __COUNT_H__

typedef unsigned char Code[4];

typedef struct {
	Code rgba;
	unsigned int count;
} Result;

typedef struct {
	Result* arr;
	size_t length;
} ResultArray;

extern char* to_json(ResultArray* ra);

extern bool matchRGBA(Code a,Code b);

extern void append(Code c, ResultArray* ra);

extern void count(Code c, ResultArray* ra);

extern int search(Code c, ResultArray* ra);

#endif
