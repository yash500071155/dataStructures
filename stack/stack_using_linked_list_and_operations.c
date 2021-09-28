//is program ko bade dhyan se dekhe isme local global variable ka khel hai aur pointer to pointer (**) and address (&) ka bhi khel hai.................so be alert
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
// struct Node*top=NULL;
void traversing_a_linked_list(struct Node *ptr)
{
    while (ptr != NULL)
    // while(ptr->next!=  NULL)
    {
        printf("Element is: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}
int peek(struct Node*ptr, int position)
{
    struct Node *p=ptr;
    for(int i=1;(i<=position-1 && p!=NULL);i++)
    {
        p=p->next;
    }
    if(p!= NULL)
    {
        return p->data;
    }
    else{
        return 0;
    }
}
int stackTop()
{
    return top->data;
}
int stackBottom()
{
    struct Node *ptr=top;
    while(ptr->next!= NULL)
    {
        ptr=ptr->next;
    }
    return ptr->data;
}
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct Node *top)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Node *push(struct Node *top, int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (isfull(top))
    {
        printf("stack overflow\n");
    }
    else
    {
        n->data = data;
        n->next = top;
        top = n;
        return top;
    }
}
int pop(struct Node *tp)
{
    struct Node *n;
    if (isEmpty(tp))
    {
        printf("stack underflow\n");
    }
    else
    {
        struct Node *n = tp;
        top = tp->next;
        int x = n->data;

        free(n);
        return x;
    }
}
// int pop(struct Node**top )
// {
//     struct Node*n;
//     if(isEmpty(*top))
//     {
//         printf("stack underflow\n");
//     }
//     else{
//         struct Node*n=*top;
//         *top=(*top)->next;
//         int x=n->data;

//        free(n);
//         return x;

//     }
// }
int main()
{

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    int element = pop(top);
    // int element=pop(&top);
    printf("popped element is %d\n", element);
    // traversing_a_linked_list(top);
    int peek_data = peek(top,1);
printf("peeked element is %d\n", peek_data);
printf("%d\n",stackTop());
printf("%d\n",stackBottom());
    return 0;
}