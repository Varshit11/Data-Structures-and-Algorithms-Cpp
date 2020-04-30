/* C program to reverse words in a given string */

#include<stdio.h>

void reverse(char* begin, char* end){
	char temp;
	while(begin<end){
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}

void reverse_words(char* s){
	char* temp = s;
	char* w = s;
	while(*temp){
		if(*temp == ' '){
			reverse(w, temp-1);
			w = temp+1;
		}
		else if(!*(temp+1)){
			reverse(w, temp);
		}
		temp++;
	}
	reverse(s, temp-1);
}

int main(){
	char s[] = "i love algorithms";
	reverse_words(s);
	printf("%s", s);
	return 0;
}

