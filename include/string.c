#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "./string.h"

void strcat_memcpy(string* a,string* b){
    string* tmp = calloc(1,sizeof(string));
    tmp -> value = a -> value;
    tmp -> length = a -> length;
    if(!((a -> length += b -> length) > tmp -> length)) { printf("(a -> length += b -> length) was not bigger than tmp -> length"); abort(); }
    a -> value = calloc(a -> length,sizeof(char));
    memcpy(a -> value,tmp -> value,tmp -> length);
    free(tmp -> value);
    memcpy(a -> value + tmp -> length,b -> value,b -> length);
    free(tmp);
}