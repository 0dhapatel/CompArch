#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv){
    FILE *fp=fopen(argv[1],"r");
    if (fp==NULL||argc!=2){
        printf("error\n");
        return 0;
    }
    int num;
    fscanf(fp,"%d", &num);
    int iput[num];
    int i1;
    for (i1=0; i1<num; i1++){
        fscanf(fp,"%d\t", &iput[i1]);
    }
    int tempp;
    int pre=0, ptr=1;
    int l=0, r=num-1;
    int i=0;
    int input[num];
    while(i<num){
      input[i]=0;
      i++;
    }
    i=0;
    while(i<num){
      if(iput[i]%2==0){
        input[l]=iput[i];
        l++;
      }
      else{
        input[r]=iput[i];
        r--;
      }
      i++;
    }    
    int even=0;
    int in=0;
    while(in<num){
        if(input[in]%2==0){
            even++;
        }
        in++;
    }
    while(pre<even){
        while(ptr<even){
            if(input[pre]<input[ptr]){
                tempp=input[pre];
                input[pre]=input[ptr];
                input[ptr]=tempp;
            }
            ptr++;
        }
        ptr=0;
        pre++;
    }
    int pre2=even;
    int ptr2=even+1;
    while(pre2<num){
        while(ptr2<num){
            if(input[pre2]<input[ptr2]){
                tempp=input[pre2];
                input[pre2]=input[ptr2];
                input[ptr2]=tempp;
            }
            ptr2++;
        }
        ptr2=even;
        pre2++;
    }
    for(i=0;i<num;i++){
        printf("%d\t",input[i]);
    }
    printf("\n");
    //fclose(fp);
    return 0;
}
