#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data; //struct mai hamesh sirf initialize he karte hai define nahi karte hai data ko yaad rakhna
    struct Node *next;
    struct Node *prev;
   
};
void traversing_a_linked_list(struct Node*ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
   
}
void traversing_a_linked_list_reverse(struct Node*ptr)
{
    struct Node*p=ptr;
    while(p->next!= NULL)
    {
        p=p->next;
    
    }
    while(p!=NULL)
    {
         printf("%d\n",p->data);
        p=p->prev;
    }

}
struct Node* insert_at_the_biggining(struct Node*head,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    head->prev=ptr;
    ptr->prev=NULL;
    head=ptr;
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
    head->prev=NULL;
    head->next = first;
//link first, second and third node
    first->data=20;
    first->prev=head;
    first->next=second;
    
//link second, third and fourth node
    second->data=30;
    second->prev=first;
    second->next=third;
//Terminate the fourth node with NULL and link with third
    third->data=40;
    third->prev=second;
    third->next=NULL;
    traversing_a_linked_list(head);
    printf("\n");
    traversing_a_linked_list_reverse(head);
    printf("\n");
    head=insert_at_the_biggining(head,1);
    traversing_a_linked_list(head);
     printf("\n");
    traversing_a_linked_list_reverse(head);
    
    return 0;
}

//Now all insertion and delition and also search are all similiar with linked list and circular linked list here we perform one but all of the rest are similiar.