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
	Result* tmp = calloc(l + 1,sizeof(Result));
	memcpy(tmp,ra -> arr,s * l);
	ra -> arr = calloc(l + 1,sizeof(Result));
	memcpy(ra -> arr,tmp,s * l);
	memcpy(ra -> arr + l,c,sizeof(Code));
	(ra -> arr + l) -> count = 0;
	ra -> length++;
}

void count(Code c,ResultArray* ra){
	int i = search(c, ra);
	if(i == -1){
		append(c, ra);
		count(c, ra);
	} else {
		(ra -> arr + i) -> count++;
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
