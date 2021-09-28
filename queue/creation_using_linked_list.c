#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct ll_queue *f = NULL;
struct ll_queue *b = NULL;
struct ll_queue
{
    int data;

    struct ll_queue *next;
};
void traversing_a_linked_list(struct ll_queue *ptr)
{
    while (ptr != NULL)
    {

        printf("Element is : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// int isFull()
// {
//     struct ll_queue*n=(struct ll_queue *)malloc(sizeof(struct ll_queue));
//     if(n==NULL)
//     {
//         return 1;
//     }
//     return 0;

// }
// int isEmpty(struct ll_queue *f)
// {
//     if (f == NULL)
//     {
//         return 1;
//     }
//     return 0;
// }
int enqueue(int data)
{
    struct ll_queue *n = (struct ll_queue *)malloc(sizeof(struct ll_queue));

    if (n == NULL)
    {
        printf("Queue overflow\n");
    }
    else
    {
        n->data = data;
        n->next = NULL;
        if (f == NULL)
        {
            f = b = n; ////special case for first insertion when both are at null
        }
        else
        {
            b->next = n;
            b = n;
        }
    }
}
int dequeue()
{
    int val;
    struct ll_queue *ptr = f;
    if (f==NULL)
    {
        printf("queue overflow\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
}

int main()
{

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    // dequeue(f);
    printf("dequeue element is %d\n",dequeue());
    traversing_a_linked_list(f);

    return 0;
}