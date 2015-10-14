/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char smallest_character(char *input ,char c) {
    while(*input!='\0'){
	if(*input < c){
	    *input++;
	}
	else{
	    break;
	}
    }
    
    return *input;
}
int main()
{
    char input[]={'c','f','j','p','v'},c='m',output;
    
    assert((smallest_character(input,c)) && "function error!\n");
    output = smallest_character(input, c);
    printf("result : %c\n",output);
    return 0;
}
