#ifndef __COUNT_H__
#define __COUNT_H__

typedef struct {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
} Code;

typedef struct {
	unsigned char rgba[4];
	long long count;
} Count;

extern bool matchRGBA(unsigned char* a,unsigned char* b);

extern void append(unsigned char* color,void* result,size_t* result_size);

extern void count(unsigned char* color,void* result,size_t* result_size);

extern int search(unsigned char* color, void* result, size_t* result_size);

#endif
