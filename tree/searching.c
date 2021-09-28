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
node* search(node*root,int key)
{
    if(root==NULL)
    {
        return NULL;

    }
    if(root->data==key)
    return root;
    else if(root->data>key)
    {
        return search(root->left,key);
    }
    else if(root->data<key)
    {
        return search(root->right,key);
    }

}
int main()
{
    node*p=creation_node(10);
    node*p1=creation_node(20);
    node*p2=creation_node(30);
    p->left=p1;
    p->right=p2;
    node*n=search(p,40);
    if(n!=NULL)
    {
        printf("found %d:\n",n->data);
    }
    else{
        printf("element not found\n");
    }


    
    
    return 0;
}

