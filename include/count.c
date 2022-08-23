#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "../include/count.h"

bool matchRGBA(Code a,Code b){
	return !memcmp(a,b,sizeof(Code));
}

char* to_json(ResultArray* ra){
	int length = 0, tmp_length = 0;
	char* json = calloc(length,sizeof(char));
	char* json_tmp = calloc(length + tmp_length,sizeof(char));
	char* tmp = calloc(tmp_length,sizeof(char));

	tmp_length = sprintf(tmp,"%s","[");
//STRCAT
	json_tmp = calloc(length,sizeof(char));
	memcpy(json_tmp,json,length);
	json = calloc(length + tmp_length,sizeof(char));
	memcpy(json,json_tmp,length);
	memcpy(json + length,tmp,tmp_length);
	length += tmp_length;

	for(int i = 0;i < ra -> length;i++){
		tmp_length = sprintf(tmp,
			"{\"rgba\":\"#%.2x%.2x%.2x%.2x\",\"count\":%u}%s",
			*((ra -> arr + i) -> rgba + 0),
			*((ra -> arr + i) -> rgba + 1),
			*((ra -> arr + i) -> rgba + 2),
			*((ra -> arr + i) -> rgba + 3),
			((ra -> arr + i) -> count),
			ra -> length - 1 == i ? "" : ","
		);

//STRCAT
		json_tmp = calloc(length,sizeof(char));
		memcpy(json_tmp,json,length);
		json = calloc(length + tmp_length,sizeof(char));
		memcpy(json,json_tmp,length);
		memcpy(json + length,tmp,tmp_length);
		length += tmp_length;
	}

	tmp_length = sprintf(tmp,"%s","]");

// STRCAT
	json_tmp = calloc(length,sizeof(char));
	memcpy(json_tmp,json,length);
	json = calloc(length + tmp_length,sizeof(char));
	memcpy(json,json_tmp,length);
	memcpy(json + length,tmp,tmp_length);
	length += tmp_length;

	return json;
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
