#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
	FILE* fp=fopen(argv[1],"r");
	if (argc!=2 || fp==NULL){
		printf("error\n");
		return 0;
	}
	int side;
	int nice;
	int temp;
	int sum=0;
	int sum2=0;
	fscanf(fp,"%d",&side);
	if(side==1){
		printf("magic\n");
	}
	int **ms = (int**)malloc(side*sizeof(int*));
	for (temp=0; temp<side;temp++){
		ms[temp]=(int *)malloc(side*sizeof(int));
	}
	int i=0;
	int j=0;
	while(i<side){
		while(j<side){
			fscanf(fp,"%d\t",&nice);
			ms[i][j]=nice;
			j++;
		}
		j=0;
		i++;
	}
	int k,m;
	int counter=0;
	for(i=0; i<side; i++){
		for(j=0; j<side; j++){
			for(k=0; i<side; i++){
				for(m=0; j<side; j++){
					if(i==k && j==m){
						continue;
					}
					if(ms[i][j]==ms[k][m]){
						counter=counter+1;
					}
				}
			}
		}
	}
	if(counter!=0){
		printf("not-magic\n");
		return 0;
	}
	for(i=0; i<side; i++){
		sum=sum+(ms[0][i]);
	}
	for(i=1; i<side; i++){
		for(j=0; j<side; j++){
			sum2=sum2+(ms[i][j]);
		}
		if(sum!=sum2){
			printf("not-magic\n");
			return 0;
		}
		sum2=0;
	}
	for(i=0; i<side; i++){
		for(j=0; j<side; j++){
			sum2=sum2+(ms[j][i]);
		}
		if(sum!=sum2){
			printf("not-magic\n");
			return 0;
		}
		sum2=0;
	}
	for(i=0; i<side; i++){
		sum2=sum2+(ms[i][i]);
	}
	if(sum!=sum2){
		printf("not-magic\n");
		return 0;
	}
	sum2=0;
	for(i=0; i<side; i++){
		sum2=sum2+(ms[i][side-i-1]);
	}
	if(sum!=sum2){
		printf("not-magic\n");
		return 0;
	}
	printf("magic\n");
	fclose(fp);
	return 0;
}
