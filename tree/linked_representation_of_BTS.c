#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}node;

node* creation_node(int data)//baar baar node banane se aacha hai ek he baar mai uska function banalo fir bahut dara code likhne se aacha hai uss function ko he call karlo
{
    node *n=(node*)malloc(sizeof(node));
    n->left=NULL;
    n->right=NULL;
    n->data=data;
    return n;
}
int main()
{
    node*p=creation_node(10);
    node*p1=creation_node(20);
    node*p2=creation_node(30);
    p->left=p1;
    p->right=p2;

    printf("%d ",p->data);
    printf("%d ",p->left->data);
    printf("%d ",p->right->data);

    
    
    return 0;
}

