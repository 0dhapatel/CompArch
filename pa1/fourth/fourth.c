#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
	FILE* fp=fopen(argv[1],"r");
	if (argc<2 || fp==NULL){
		printf("error\n");
		return 0;
	}
	int v1r;
	int v1c;
	int v2r;
	int v2c;
	int nice;
	int temp;
	fscanf(fp,"%d\t%d",&v1r,&v1c);
	int **m1 = (int**)malloc(v1r*sizeof(int*));
	for (temp=0; temp<v1r;temp++){
		m1[temp]=(int *)malloc(v1c*sizeof(int));
	}
	int i=0;
	int j=0;
	while(i<v1r){
		while(j<v1c){
			fscanf(fp,"%d\t",&nice);
			m1[i][j]=nice;
			j++;
		}
		j=0;
		i++;
	}
	fscanf(fp,"%d\t%d",&v2r,&v2c);
	int **m2 = (int**)malloc(v2r*sizeof(int*));
	for (temp=0; temp<v2r;temp++){
		m2[temp]=(int *)malloc(v2c*sizeof(int));
	}
	j=0;
	i=0;
	while(i<v2r){
		while(j<v2c){
			fscanf(fp,"%d\t",&nice);
			m2[i][j]=nice;
			j++;
		}
		j=0;
		i++;
	}
	if(v1c!=v2r){
		printf("bad-matrices\n");
		return 0;
	}
	int **ans = (int**)malloc(v1r*sizeof(int*));
	for (temp=0; temp<v1r;temp++){
		ans[temp]=(int *)malloc(v2c*sizeof(int));
	}
	int r1=0;
	int r2=0;
	int c2=0;
	int answ=0;
	while (r1<v1r){
		while(c2<v2c){
			while(r2<v2r){
				answ=answ+(m1[r1][r2]*m2[r2][c2]);
				r2++;
			}
			r2=0;
			ans[r1][c2]=answ;
			answ=0;
			c2++;	
		}
		c2=0;
		r1++;
	}
	for(i=0; i<v1r; i++){
		for(j=0;j<v2c;j++){
			printf("%d\t",ans[i][j]);
		}
		printf("\n");
	}
	fclose(fp);
	return 0;
}

