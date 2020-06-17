#include <stdio.h>
#include <stdlib.h>

int solvable(int mat[][9], int row, int col, int num){
  int row2 = (row/3) * 3;
  int col2 = (col/3) * 3;
  int i=0;
  while(i<9){
    if (mat[row][i] == num || mat[i][col] == num || mat[row2 + (i%3)][col2 + (i/3)] == num){
      return 0;
    }
    i++;
  }
  return 1;
}

int solve(int mat[][9], int row, int col){
  int counter=0;
  if(row<9 && col<9){
    if(mat[row][col] == 0){
      int i=0;
	counter++;
      while(i<9){
        if(solvable(mat, row, col, i+1)){
          mat[row][col] = i+1;
	counter++;
            if((col+1)<9){
              if(solve(mat, row, col+1)){
                return 1;
		counter++;
              }
              else{
                mat[row][col] = 0;
		counter++;
              }
            }
            else if((row+1)<9){
              if(solve(mat, row+1, 0)){
                return 1;
		counter++;
              }
              else{
                mat[row][col] = 0;
		counter++;
              }
            }
          else{
            return 1;
		counter++;
          }
        }
        i++;
	counter++;
      }
    }
    else{
      if((col+1)<9){
        return solve(mat, row, col+1);
	counter++;
      }
      else if((row+1)<9){
        return solve(mat, row+1, 0);
	counter++;
      }
      else{
        return 1;
	counter++;
      }
    }
    return 0;
	counter++;
  }
  else{
    return 1;
	counter++;
  }
}

int main(int argc, char **argv){
    int i, j;
	FILE* fp=fopen(argv[1],"r");
	if (fp==0){
		return 0;
	}
	if (argc<2 || fp==NULL){
		printf("error\n");
		return 0;
	}
	int mat[9][9];
	char nice;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			fscanf(fp,"%c\t",&nice);
			if(nice=='-'){
				mat[i][j]=0;
			}
			else{
				mat[i][j]=nice-'0';
			}
		}
	}
	fclose(fp);
    if(solve(mat, 0, 0)==0){
        printf("no-solution\n");
	return 0;
    }
    else{
	for(i=0; i<9; ++i){
            for(j=0; j<9; ++j){
		 printf("%d\t", mat[i][j]);
	    }
            printf("\n");
        }
    }
    return 0;
}
