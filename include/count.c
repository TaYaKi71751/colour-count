#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "../include/count.h"

bool matchRGBA(unsigned char* a,unsigned char* b){
	return !memcmp(a,b,sizeof(Code));
}

void append(unsigned char* color,void* result,size_t* result_size){
	const size_t append_size = sizeof(Count) * 1;
	realloc(result,*(size_t*)result_size + append_size);
	memcpy((result + *(size_t*)result_size),color,sizeof(Code));
	*(size_t*)result_size += append_size;
}

void count(unsigned char* color,void* result,size_t* result_size){
	int search_index = search(color, result, result_size);
	if(search_index == -1){
		append(color,result,result_size);
		count((unsigned char*)color,result,result_size);
	} else {
		*((long long*)(result + search_index * sizeof(Count) + 4)) += 1;
	}
}

int search(unsigned char* color, void* result, size_t* result_size){
	int result_length = *(size_t*)result_size / sizeof(Count);
	int search_index = -1;
	for(int i = 0;i < result_length;i++){
		if(!matchRGBA(
			(color),
			(result + i * sizeof(Count))
		)) { 
			continue;
		} else {
			return (search_index = i); 
		}
	}
	return search_index;
}
