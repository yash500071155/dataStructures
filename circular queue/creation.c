#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct queue{
    int size;
    int f;
    int b;
    int *array;
};
int isEmpty(struct queue*q)
{
    if(q->b==q->f)
    {
        return 1;
    }
    return 0;

}
int isFull(struct queue *q)
{
    if((q->b+1)%q->size==q->f)
    {
        return 1;
    }
    return 0;

}
int deque(struct queue *q)
{
    int value;
    if(isEmpty(q))
    {
        printf("The queue is empty not able to dequeue\n");
    }
    else{
        q->f=(q->f+1)%q->size;
        value=q->array[q->f];
        return value;

    }
return 0;
    
}
void enque(struct queue *q,int data)
{
     if(isFull(q))
    {
        printf("The queue is full not able to enqueue\n");
    }
    else{
        q->b=(q->b+1)%q->size;
        q->array[q->b]=data;
    }

}
int main()
{
    struct queue q;
    q.size=100;
    q.f=q.b=0;
    q.array=(int*)malloc(q.size*sizeof(int));
    enque(&q,10);
    enque(&q,20);
    enque(&q,30);
    enque(&q,40);
    enque(&q,50);
     printf("isfull %d\n",isFull(&q));
    printf("isempty %d\n",isEmpty(&q));
    printf("dequed element is %d\n",deque(&q));
    printf("dequed element is %d\n",deque(&q));
    printf("dequed element is %d\n",deque(&q));
    printf("dequed element is %d\n",deque(&q));
    printf("dequed element is %d\n",deque(&q));
    printf("isfull %d\n",isFull(&q));
    printf("isempty %d\n",isEmpty(&q));
    
    return 0;
}