#include <stdlib.h>
#include <stdio.h>

struct node{
	int input;
	struct node* right;
	struct node* left;
};

int size(struct node* head, int num, int siz){
		if(head == NULL){
			return 0;
		}
		if(head->input == num){
			return siz;
		}
		int si = size(head->left, num, siz+1);
		if(si != 0){
			return si;
		}
		si = size(head->right, num, siz+1);
		return si;
}

struct node* insert(int num, struct node* head){
	if(head == NULL){
		struct node *temp = (struct node*) malloc(sizeof(struct node));
		temp->left = temp->right = NULL;
		temp->input = num;
		return temp;
	}
	if(num < head->input){
		head->left = insert(num, head->left);
	}else if(num > head->input){
		head->right = insert(num, head->right);
	}
	return head;
}

struct node* look(struct node* head){
	struct node* temp = head;
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

int search(int num, struct node* head){
	if(head == NULL){
		return 0;
	}else{
		if(head->input==num){
			return 1;
		}else{
			int re = search(num, head->left);
			int re2 = search(num, head->right);
			
			if(re == 1 || re2==1){
				return 1;
			}
		}
	return 0;
	}
}

struct node* delete(struct node* head, int num){
	if(num<head->input){
		head->left = delete(head->left, num);
	}else if(num>head->input){
		head->right = delete(head->right, num);
	}else{
		if(head->left == NULL && head->right == NULL){
			struct node* temp = head->right;
			free(head);
			printf("success\n");
			return temp;
		}else if((head->left == NULL && head->right != NULL)){
			struct  node* temp = head->right;
			free(head);
			printf("success\n");
			return temp;
		}else if((head->left != NULL && head->right == NULL)){
			struct node* temp = head->left;
			free(head);
			printf("success\n");
			return temp;
		}else{
			struct node* temp = look(head->right);
			head->input = temp->input;
			head->right = delete(head->right, temp->input);
		}
	}
	return head;
}

void make(struct node* head){
	if(head!=NULL){
		make(head->left);
		make(head->right);
		free(head);
	}
}

int main(int argc, char** argv){
	if(argc !=2){
		printf("error\n");
		return 0;
	}
	struct node* head = NULL;
	char cha;
	int num;
	FILE* fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("error\n");
		return 0;
	}	
	while(!feof(fp)){
		fscanf(fp, "%c %d", &cha, &num);
		if(cha == 'i'){
			int same = search(num, head);
			if(same == 1){
				printf("duplicate\n");
			}else{
			head = insert(num, head);
			int siz = size(head, num, 1);
			printf("inserted %d\n", siz);
			}
		}else if(cha == 's'){
			if(search(num, head) == 1){
				int siz = size(head, num, 1);
				printf("present %d\n", siz);
			}else{
				printf("absent\n");
			}
		}else if(cha == 'd'){
			if(search(num, head) == 0){
				printf("fail\n");
			}else{
				head = delete(head, num);
			}
		}
	}
	make(head);
	fclose(fp);
	return 0;	
}
