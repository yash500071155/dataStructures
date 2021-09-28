#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data; //struct mai hamesh sirf initialize he karte hai define nahi karte hai data ko yaad rakhna
    struct Node *next;
   
};
void traversing_a_linked_list(struct Node*ptr)
{
    while(ptr!=NULL)
    {
        printf("Element of a linked list are : %d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node*)malloc(sizeof(struct Node));
    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
//link first and second nodes
    head->data=10;
    head->next = first;
//link second and third node
    first->data=20;
    first->next=second;
//link third and fourth node
    second->data=30;
    second->next=third;
//Terminate the fourth node with NULL
    third->data=40;
    third->next=NULL;
    traversing_a_linked_list(head);

    
    return 0;
}