#include<stdio.h>
#include<stdlib.h>

struct Node{
    int num;
    struct Node* next;
};


struct Node *insert(struct Node *head, int numb){
    struct Node *pre;
    if(head == NULL){
        head = malloc(sizeof(struct Node));
        head->num = numb;
        head->next = NULL;
    }
    
    else if(head->num > numb){
        struct Node *inN = malloc(sizeof(struct Node));
        inN->num = numb;
        inN->next = head;
        return inN;
    }
    else{
        struct Node *temp = head;
        while(temp != NULL){
            if(temp->num == numb){
                return head;
            }
            else if(temp->num > numb){
                struct Node *inN;
                inN = malloc(sizeof(struct Node));
                inN->num = numb;
                inN->next = pre->next;
                pre->next = inN;
                return head;
            }
            pre = temp;
            temp = temp->next;
        }
        
        struct Node *inN;
        inN = malloc(sizeof(struct Node));
        inN->num = numb;
        inN-> next = NULL;
        pre->next = inN;
        return head;
    }
	return head;
}

struct Node *delete(struct Node *head, int numb){
    struct Node *temp = head;
    struct Node *pre = head;
    
    if (head == NULL){
        return head;
    }
    
    if(head->num == numb){
        return head->next;
    }
    while(temp != NULL){
        if(temp->num == numb){
            pre->next = temp->next;
            return head;
        }
        pre = temp;
        temp = temp->next;
    }
    return head;
}

int count(struct Node* head){
	int numb=0;
	struct Node *temp=head;
	while(temp!=NULL){
		numb++;
		temp=temp->next;
	}
	return numb;
}

int main(int argc, char** argv){
    struct Node *head=NULL;
    if (argc != 2){
        return 0;
    }
    FILE *fp = fopen(argv[1], "r");
    char cha;
    int num;
    if (fp == NULL){
        printf("error\n");
        return 0;
    }
    while(fscanf(fp, "%c\t%d\n", &cha, &num) == 2 ){
        if(cha == 'i'){
            head = insert(head, num);
        }
        
        else if(cha == 'd'){
            head = delete(head, num);
        }
        
        else {
            printf("error\n");
            return 0;
        }
    }

    if(!feof(fp)){
      printf("error\n");
      return 0;
    }
	int cou=count(head);
	printf("%d\n",cou);
    
    while (head != NULL){
      printf("%d\t", head->num);
      head = head->next;
    }
    
    fclose(fp);
    free(head);
    return 0;    
}
