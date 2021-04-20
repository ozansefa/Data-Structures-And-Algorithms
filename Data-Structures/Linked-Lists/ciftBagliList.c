#include<stdio.h>
#include<stdlib.h>

struct n{
	int data;
	n *next;
	n *prev;
};
typedef struct n node;

void bastir(node *iter){
	while(iter != NULL){
		printf("%d ",iter->data);
		iter = iter -> next;
	}
	printf("\n");
}

node *sil(node *r, int x){
	node *temp;
	node *iter = r;
	if(r->data == x){
		temp = r;
		r = r->next;
		free(temp);
		return r;
	}
	while(iter->next != NULL && iter->next->data != x){
		iter = iter->next;	
	}
	if(iter->next == NULL){
		printf("Sayi bulunamadi\n");
		return r;
	}		
	temp = iter->next;
	iter->next = iter->next->next;
	if(iter -> next != NULL){
		iter -> next -> prev = iter;
	}
	free(temp);
	return r;
}
 
node *ekleSirali(node *r, int x){
	if(r == NULL){
		r = (node *)malloc(sizeof(node));
		r -> next = NULL;
		r -> prev = NULL;
		r -> data = x;
		return r;
	}
	if(r->data > x){
		node *temp = (node*)malloc(sizeof(node));
		temp -> data = x;
		temp -> next = r;
		r -> prev = temp;
		return temp;
	}
	node *iter = r;
	while(iter->next != NULL && iter -> next -> data <x){
		iter = iter -> next;
	}	
	node *temp = (node*)malloc(sizeof(node));
	temp -> next = iter -> next;
	iter -> next = temp;
	temp -> prev = iter;
	if(temp->next != NULL){
		temp -> next -> prev = temp;
	}
	temp -> data = x; 
	return r;
} 

int main(){
	node *root = NULL;	
	root = ekleSirali(root,400);
	root = ekleSirali(root,40);
	root = ekleSirali(root,4);
	root = ekleSirali(root,450);
	root = ekleSirali(root,50);				
	bastir(root);
	
	root = sil(root,450);
		bastir(root);
	root = sil(root,50);
		bastir(root);
	root = sil(root,400);
		bastir(root);
	root = sil(root,999);
		bastir(root);
	root = sil(root,40);
		bastir(root);
}
