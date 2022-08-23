#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "../include/count.h"

bool matchRGBA(Code a,Code b){
	return !memcmp(a,b,sizeof(Code));
}

void append(Code c,ResultArray* ra){
	size_t l = ra -> length;
	size_t s = sizeof(*(ra -> arr));
	
void append(unsigned char* color,void* result,size_t* result_size){
	const size_t append_size = sizeof(Count) * 1;
	realloc(result,*(size_t*)result_size + append_size);
	memcpy((result + *(size_t*)result_size),color,sizeof(Code));
	*(size_t*)result_size += append_size;
	realloc(ra -> arr,s * (l + 1));
	memcpy(
		ra -> arr + s * l,
		c,
		sizeof(Code)
	);
	ra -> length++;
}

void count(Code c,ResultArray* ra){
	int i = search(c, ra);
	if(i == -1){
		append(c, ra);
		count(c, ra);
	} else {
		(*(ra -> arr + i)).count += 1;
		return;
	}
}

int search(Code c, ResultArray* ra){
	int _i = -1;
	for(int i = 0;i < ra -> length;i++){
		if(!matchRGBA(
			(c),
			(ra -> arr + i) -> rgba
		)) { 
			continue;
		} else {
			return i;
		}
	}
	return _i;
}
