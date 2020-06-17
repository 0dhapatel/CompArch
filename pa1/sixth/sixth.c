#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void con(char *let){
	int val=0;
	int len=strlen(let);
	while(val<len){
		if(let[val]=='a'||let[val]=='e'||let[val]=='i'||let[val]=='o'||let[val]=='u'){
			int i;
			for(i=val; i<len;i++){
				printf("%c",let[i]);
			}
			for(i=0; i<val; i++){
				printf("%c",let[i]);
			}
			printf("ay");
			break;
		}
		val++;
	}
	return;
}

int main(int argc, char** argv){
	int num;
	if(argv[1][0]=='a'||argv[1][0]=='e'||argv[1][0]=='i'||argv[1][0]=='o'||argv[1][0]=='u'||argv[1][0]=='A'||argv[1][0]=='E'||argv[1][0]=='I'||argv[1][0]=='O'||argv[1][0]=='U'){
		printf("%syay", argv[1]);
	}
	else{
		con(argv[1]);
	}
	if (argc>1){
		for(num=2; num<argc; num++){
			printf(" ");
			if(argv[num][0]=='a'||argv[num][0]=='e'||argv[num][0]=='i'||argv[num][0]=='o'||argv[num][0]=='u'||argv[num][0]=='A'||argv[num][0]=='E'||argv[num][0]=='I'||argv[num][0]=='O'||argv[num][0]=='U'){
				printf("%syay", argv[num]);
			}
			else{
				con(argv[num]);
			}
		}
	}
	printf("\n");
	return 0;
}

