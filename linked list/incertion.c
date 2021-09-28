#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data; //struct mai hamesh sirf initialize he karte hai define nahi karte hai data ko yaad rakhna
    struct Node *next;
   
};
void traversing_a_linked_list(struct Node*ptr)
{
    while(ptr!=  NULL)
    // while(ptr->next!=  NULL)
    {
        printf("Element is: %d\n",ptr->data);
        ptr=ptr->next;

    }
    printf("\n\n");
}
struct Node* insertion_on_first_node(struct Node* head,int data)
{
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;


}
struct Node* insertion_in_between(struct Node* head,int data, int index)
{
    int i=0;
    struct Node *p;
    p=head;
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;

    


}
struct Node* insertion_at_the_end(struct Node* head,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p;
   
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;

    return head;
}
struct Node* insertion_after_node(struct Node* head,struct Node* node,int data)
{
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=node->next;
    node->next=ptr;
    return head;


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
    printf("Linked list before insertion\n");
    traversing_a_linked_list(head);
    printf("Linked list after insertion\n");
    // head=insertion_on_first_node(head,1);
    // traversing_a_linked_list(head);
    // head=insertion_in_between(head,44,1);
    // traversing_a_linked_list(head);

    // insertion_at_the_end(head,100);
    // traversing_a_linked_list(head);
    insertion_after_node(head,first,999);
    traversing_a_linked_list(head);

    
    return 0;
}