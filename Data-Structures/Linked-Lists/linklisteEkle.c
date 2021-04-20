#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n *next;
};

typedef struct n node;

node *append(node *iter, int x){
    if(iter == NULL){
        iter = (node *)malloc(sizeof(node));
        iter -> data = x;
        iter -> next = NULL;
        return iter;
    }
    else{
        node *temp = iter;
        while(temp->next != NULL){
            temp  = temp -> next;
        }
        temp -> next = (node *)malloc(sizeof(node));
        temp -> next -> data = x;
        temp -> next -> next = NULL;
        return iter;
    }
}

void display(node *iter){
    while(iter != NULL){
        printf("%d ",iter->data);
        iter = iter -> next;
    }
}

int main(){
    node *root = NULL;
    root  = append(root,1);
    root  = append(root,3);
    root  = append(root,3);
    root  = append(root,7);
    display(root);
}
