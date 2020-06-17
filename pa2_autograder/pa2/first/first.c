#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void freem (double **fm, int row){
	int i;
	for(i=0; i<row; i++){
		free(fm[i]);
	}
	free(fm);
	return;
}

double **createm(int row, int col){
	int i;
	double **temp=(double**)malloc(row*sizeof(double*));
	for (i=0; i<row;i++){
		temp[i]=(double *)malloc(col*sizeof(double));
	}
	return temp;
}

void divider(double *mat, int col, double num){
	int i;
	for (i=0; i<col; i++){
		mat[i]=mat[i]/num;
	}
	return;
} 

double **multiply (double **x, double **y, int row, int col, int row2, int col2){
	double **ans = createm(row,col2);
	int r1,r2,c2;
	for (r1=0; r1<row; r1++){
		for(c2=0; c2<col2; c2++){
			ans[r1][c2]=0.000000;
			for(r2=0; r2<row2; r2++){
				ans[r1][c2]+=x[r1][r2]*y[r2][c2];
			}
		}
	}
	return ans;
}

double **subtractr(double **mat, int row, int num, int col, double num2){
    double **temp = createm(col, col);
    temp = mat;
    int i;
    for(i = 0; i < col; i++){
        temp[row][i] = mat[row][i] - (num2 * (mat[num][i]));
    }
    return temp;
}

double **inverse(double **mat, int col){
    int i, j, k;
    double **imat = createm(col, col);
for(i = 0; i < col; i++){
    for(j = 0; j <col; j++){
        if(i == j)
            imat[i][j] = 1;
        else
            imat[i][j] = 0;
    }
}
    double **temp = mat;
    double num = 0;
    for(i = 0; i < col; i++){
        for(j = i +1; j < col; j++){
            if(fabs(temp[j][i]) > 10e-7){
                int num2 = j - 1;
                while(fabs(temp[num2][i]) < 10e-7){
                    num2--;
                }
                num = temp[j][i]/temp[num2][i];
                temp = subtractr(temp,j, num2, col, num);
                imat = subtractr(imat,j, num2, col, num);
            }
        }
    }
    for(j = 0; j < col-1; j++){
        int num2 = j+1;
        for(i = j + 1; i < col; i++){
            num = temp[j][i]/temp[num2][i];
            temp = subtractr(temp, j, num2, col, num);
            imat = subtractr(imat, j, num2, col, num);
            num2++;
        }
    }
    for(j = 0; j < col; j++){
        for(i = 0; i < col; i++){
            if(j == i){
                if(temp[j][i] != 1){
                    num = 1/(temp[j][i]);
                    for(k = 0; k < col; k++){
                        temp[j][k] = num * (temp[j][k]);
                        imat[j][k] = num * (imat[j][k]);
                    }
                }
            }
        }
    }
    return imat;
}

int main (int argc, char** argv){
	FILE* fp=fopen(argv[1],"r");
	FILE* fp2=fopen(argv[2],"r");
	if (fp==0||fp2==0){
		return 0;
	}
	if (argc<3 || fp==NULL || fp2==NULL){
		printf("error\n");
		return 0;
	}
	int row, col, row2;
	double nice;
	fscanf(fp,"%d",&col);
	fscanf(fp,"%d",&row);
	col=col+1;
	double **x = createm(row,col);
	double **y = createm(row,1);
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col+1;j++){
			if(j==0){
				x[i][0]=1.000000;
			}
			else if(j==1){
				fscanf(fp,"%lf",&nice);
				if(nice<0){
					printf("error\n");
					return 0;
				}
				x[i][j]=nice;
			}
			else if(j==col){
				fscanf(fp,",%lf",&nice);
				if(nice<0){
					printf("error\n");
					return 0;
				}
				y[i][0]=nice;
			}
			else{
				fscanf(fp,",%lf",&nice);
				if(nice<0){
					printf("error\n");
					return 0;
				}
				x[i][j]=nice;
			}
		}
	}
	fscanf(fp2,"%d",&row2);
	double **w = createm(row2,col);
	for(i=0; i<row2; i++){
		for (j=0;j<col;j++){
			if(j==0){
				w[i][0]=1.000000;
			}
			else if(j==1){
				fscanf(fp2,"%lf",&nice);
				if(nice<0){
					printf("error\n");
					return 0;
				}
				w[i][j]=nice;
			}
			else{
				fscanf(fp2,",%lf",&nice);
				if(nice<0){
					printf("error\n");
					return 0;
				}
				w[i][j]=nice;
			}
		}
	}
	fclose(fp);
	fclose(fp2);
	double ** xt= createm(col,row);
	for(i=0; i<col; i++){
		for(j=0; j<row; j++){
			xt[i][j]=x[j][i];
		}
	}
	double ** xm= multiply(xt,x,col,row,row,col);
	freem(x,row);
	double ** xi=inverse(xm,col);
	freem(xm,col);
	double ** xm2=multiply(xi, xt, col, col, col, row);
	freem(xi,col);
	freem(xt,col);
	double ** xy=multiply(xm2, y, col, row, row, 1);
	freem(xm2,col);
	freem(y,row);
	double ** xyw=multiply(w, xy, row2, col, col, 1);
	for(i=0; i<row2; i++){
		printf("%0.0lf\n",xyw[i][0]);
	}
	freem(w,row2);
	freem(xy,col);
	freem(xyw,row2);
	return 0;
}
