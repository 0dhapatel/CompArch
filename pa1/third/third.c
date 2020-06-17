#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000

typedef struct Node{
int input;
struct Node *next;
}Node;

struct Node *hasharr[SIZE];
int hashfun(int key, int num);
char *insert(int key);
char *search(int key);

int hashfun(int key, int num){
  int fun = key % num;
  if(fun < 0){
    fun = abs(fun);
  }
  return fun;
}

char *insert(int key){
  struct Node *temp = malloc(sizeof(struct Node));
  temp->input = key;
  temp->next = NULL;
  char *TRUE = "inserted";
  int in = hashfun(key, 10000);
  if(hasharr[in] == NULL){
    hasharr[in] = temp;
    return "inserted";
  }
  else{
    struct Node *cur = hasharr[in];
    struct Node *pre = cur;
    while(cur != NULL){
        pre = cur;
        cur = cur->next;
        if(pre->input == temp->input){
          TRUE = "duplicate";
        }
    }
    pre->next = temp;
    return TRUE;
  }
  return TRUE;
}

char *search(int key){
  char *TRUE = "present";
  char *FALSE = "absent";
  int in = hashfun(key, 10000);
  if(hasharr[in] == NULL){
    return FALSE;
  }
  else{
    struct Node *cur = hasharr[in];
    while(cur->input != key){
      cur = cur->next;
      if(cur == NULL){
        break;
      }
    }
    if(cur == NULL){
     return FALSE;
    }
    else if(cur->input == key){
      return TRUE;
    }
  }
  return TRUE;
}
 
int main(int argc, char** argv){
  FILE *fp;
  char cha;
  int num;
  fp = fopen(argv[1], "r");
  if(argc!=2){
    printf("error\n");
  }
  if(fp == NULL){
    printf("error\n");
  }
  while(!feof(fp)){
    fscanf(fp,"%c\t%d", &cha, &num);
    if(cha == 'i'){
      printf("%s\n",insert(num));
    }else if(cha == 's'){
      printf("%s\n",search(num));
    }
  }
return 0;
}
