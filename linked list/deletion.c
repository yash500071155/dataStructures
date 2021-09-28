#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void traversal_of_linked_list(struct Node *head)
{
    while (head != NULL)
    {
        printf("The Element is : %d\n", head->data);
        head = head->next;
    }
}
struct Node *deletion_of_the_first_node(struct Node *head)

{

    struct Node *p;
    p = head;
    p = head->next;
    // head=p;
    free(head);
    return p;
}
struct Node *deletion_in_between(struct Node *head, int index)
{
    int i = 0;
    struct Node *p;
    struct Node *q;
    p = head;
    q = p->next;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct Node *deletion_from_end(struct Node *head)
{
    struct Node *p;
    struct Node *q;
    p = head;

    q = head->next;
    while (q->next != NULL)

    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct Node *deletion_on_specific_value(struct Node *head, int value)
{
    struct Node *p;
    struct Node *q;
    p = head;
    q = head->next;
    while ((q->data != value) && (q->next != NULL)) //(q->next!=NULL)) ye chack karna bhi jaroori hai agar humara number iss list mai nahi mila toa vo fir bhi run kardega while loop ko aur aage ki values bhi update hoa jayegi iss case mai koi galat node bhi delete hoa sakti hai..........Savdhan rahe satark rahe....
    {
        p = p->next;
        q = q->next;
    }
    if(q->data==value)//if condition isliye check karna jaroori hai agar while loop execute he nahi hua to fir niche ki statements chal jayegi .......aur fir humari band baj jayegi to firse bol raha hu...............savdhan rahe satark rahen.
    {p->next = q->next;
    free(q);}
    return head;
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    //link first and second nodes
    head->data = 10;
    head->next = first;
    //link second and third node
    first->data = 20;
    first->next = second;
    //link third and fourth node
    second->data = 30;
    second->next = third;
    //Terminate the fourth node with NULL
    third->data = 40;
    third->next = NULL;
    printf("Linked list before deletion is :-\n");
    traversal_of_linked_list(head);
    printf("Linked list after deletion is :-\n");
    // head=deletion_of_the_first_node(head);
    // traversal_of_linked_list(head);

    // head=deletion_in_between(head,1);
    // traversal_of_linked_list(head);

    // head=deletion_from_end(head);
    // traversal_of_linked_list(head);

    head = deletion_on_specific_value(head, 30);
    traversal_of_linked_list(head);

    return 0;
}