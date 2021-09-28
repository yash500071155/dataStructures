#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data; //struct mai hamesh sirf initialize he karte hai define nahi karte hai data ko yaad rakhna
    struct Node *next;
   
};
void traversing_a_linked_list(struct Node*ptr)
{
    struct Node*p=ptr;
   do{
       printf("Element is : %d\n",p->data);
       p=p->next;
   }while(p!=ptr);
}
struct Node* insertion_at_first(struct Node*head,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;

}
struct Node* insertion_in_between(struct Node*head,int data, int index)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
   int i=0;
   while(i!=index-1)
   {
       p=p->next;
       i++;
   }
    ptr->next=p->next;
    p->next=ptr;
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
    third->next=head;
    traversing_a_linked_list(head);
    printf("\n\n");
    // head=insertion_at_first(head,300);
    // head=insertion_at_first(head,30);
    // head=insertion_at_first(head,3);
    head=insertion_in_between(head,555,2);
    traversing_a_linked_list(head);

    
    return 0;
}



//here we perform two insertion (at starting),(and at between) they also similiar as singly linked list but we perform for practice 
//rest of 2 were also similiar
//only we have to simple take pen and paper and design steps and perform the code.
//and also have similiar deletion also.