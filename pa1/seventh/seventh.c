#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char ** argv){
	int num;
	char *let;
	for(num=1; num<argc; num++){
		let=argv[num];
		int ptr=strlen(let);
		while(*(let+ptr)!='\0'){
			ptr++;
		}
		printf("%c",let[ptr-1]);
	}
	printf("\n");
	return 0;
}
