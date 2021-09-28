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
void preorderTraversal(node*root)
{
    if(root!= NULL)
    {
        printf("%d ",root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

    }

}
void postorderTraversal(node*root)
{
    if(root!= NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ",root->data);

    }

}
void inorderTraversal(node*root)
{
    if(root!= NULL)
    {
        inorderTraversal(root->left);
        printf("%d ",root->data);
        inorderTraversal(root->right);

    }

}
int main()
{
    node*p=creation_node(4);
    node*p1=creation_node(1);
    node*p2=creation_node(6);
    node*p3=creation_node(5);
    node*p4=creation_node(2);
   
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    // preorderTraversal(p);
    // postorderTraversal(p);
    inorderTraversal(p);




    
    
    return 0;
}

