#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n *next;
};
typedef struct n node;

node *ekleSirali(node *r, int x){
	if(r == NULL){  //linklist boþsa
		r = (node *)malloc(sizeof(node));
		r -> next = NULL;
		r -> data = x;
		return r;
	}
	if(r->data > x){
		node *temp = (node*)malloc(sizeof(node));
		temp -> data = x;
		temp -> next = r;
		return temp;
	}
	node *iter = r;
	while(iter->next != NULL && iter->next->data < x){
		iter = iter -> next;
	}
	node *temp = (node *)malloc(sizeof(node));
	temp -> next = iter -> next;
	iter -> next = temp;
	temp -> data = x;
	return r;
}

void bastir(node *r){
	while(r!=NULL){
		printf("%d ",r->data);
		r = r -> next;
	}
}

int main(){
	node *root = NULL;	
	root = ekleSirali(root,400);
	root = ekleSirali(root,40);
	root = ekleSirali(root,4);
	root = ekleSirali(root,450);
	root = ekleSirali(root,50);				
	bastir(root);
}
