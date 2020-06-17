#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct node {
	int input;
	struct node* left;
	struct node* right;
}node;

node * insert(node * head, int num, int size) {
	if (head == NULL) {
		node * temp = (node*) malloc( sizeof(node) );
		temp->input = num;
		temp->left = temp->right = NULL;
		printf("inserted %d\n", size);
		return temp;
	}
	if (num < head->input)
		head->left = insert(head->left, num, size+1);
	else if (num > head->input)
		head->right = insert(head->right, num, size+1);
	else if (num == head->input) {
		printf("duplicate\n");
		return head;
	}
	return head;
}

node * search(node * head, int num, int size) {
	if (head == NULL) {
		printf("absent\n");
		return head;
	}
	else if (num == head->input) {
		printf("present %d\n", size);
		return head;
	}
	else if (num < head->input){
		search(head->left, num, size+1);
	}
	else if (num > head->input){
		search(head->right, num, size+1);
	}
	return head;
}

int main(int argc, char* argv[]) {
	char cha;
	int num;
	node * head = NULL;
	if (argc!=2){
		printf("error\n");
	}
    FILE *fp = fopen(argv[1], "r");
	if (fp==NULL){
		printf("error\n");
	}
    int check;
	while ( !feof(fp) ) {
		check = fscanf(fp, "%c %d", &cha, &num);
		if (check == 2) {
			if (cha == 'i') {
				head = insert(head, num, 1);
			}
			else if (cha == 's') {	
				head = search(head, num, 1);
			}
		}
	}
	fclose(fp);
	return 0;
}
