#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "../include/count.h"
#include "../include/string.h"

bool matchRGBA(Code a,Code b){
	return !memcmp(a,b,sizeof(Code));
}

string* to_json(ResultArray* ra){
	string *json,*tmp;
	json = calloc(1,sizeof(string));
	tmp = calloc(1,sizeof(string));

	json -> length = tmp -> length = 0;

	tmp -> value = calloc(tmp -> length,sizeof(char));
	json -> value = calloc(json -> length,sizeof(char));

	for(int i = 0;i < ra -> length;i++){
		char * tmp_value;
		tmp = calloc(1,sizeof(string));

		tmp -> length = sprintf(tmp_value,
			"%s{\"rgba\":\"#%.2x%.2x%.2x%.2x\",\"count\":%u}%s",
			0 == i ? "[" : "",
			*((*(ra -> arr + i)) -> rgba + 0),
			*((*(ra -> arr + i)) -> rgba + 1),
			*((*(ra -> arr + i)) -> rgba + 2),
			*((*(ra -> arr + i)) -> rgba + 3),
			((*(ra -> arr + i)) -> count),
			ra -> length - 1 == i ? "]" : ","
		);
		tmp -> value = calloc(tmp -> length,sizeof(char));
		memcpy(tmp -> value,tmp_value,tmp -> length);

		strcat_memcpy(json,tmp);
		free(tmp -> value);
		free(tmp);
	}

	return json;
}

void append(Code c,ResultArray* ra){
	size_t l = ra -> length;
	size_t s = sizeof(Result*);
	Result** tmp = calloc(l,s);
	Result** free_target = ra -> arr;
	memcpy(tmp,ra -> arr,s * l);
	ra -> arr = calloc(l + 1, s);
	*(ra -> arr + l) = calloc(1,sizeof(Result));
	free(free_target);
	memcpy(ra -> arr,tmp,s * l);
	free(tmp);
	memcpy(*(ra -> arr + l),c,sizeof(Code));
	(*(ra -> arr + l)) -> count = 0;
	ra -> length++;
}

void count(Code c,ResultArray* ra){
	int i = search(c, ra);
	if(i == -1){
		append(c, ra);
		count(c, ra);
	} else {
		(*(ra -> arr + i)) -> count++;
		return;
	}
}

int search(Code c, ResultArray* ra){
	int _i = -1;
	for(int i = 0;i < ra -> length;i++){
		if(!matchRGBA(
			(c),
			(*(ra -> arr + i)) -> rgba
		)) { 
			continue;
		} else {
			return i;
		}
	}
	return _i;
}
