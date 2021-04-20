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
	free(temp);
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
