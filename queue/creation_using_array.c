#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct queue
{
    int size;
    int f;
    int b;
    int *array;
};
int isFull(struct queue *q)
{
    if(q->b==q->size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q)
{
    if(q->f==q->b)
    {
        return 1;
    }
    return 0;
}
void enque(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("queue is full not able to enque\n");
    }
    else
    {
        q->b++;
        q->array[q->b] = data;
    }
}
int deque(struct queue *q)
{
    int a = 0;
    if (isEmpty(q))
    {
        printf("The queue is already empty not able to deque the value\n");
    }
    else
    {
         q->f++;
        a = q->array[q->f];
        return a;
    }
    return 0;
}
int main()
{
    struct queue q;      //agar yaha (struct queue *q;) pointer lete tab hum (->) use kar sakte the aur niche jab humne enque ko call kiya hai tab humne usme (&) address pass kiya hai q ka nahi toa agar veh pointer hota toa direct he q pass kardete koi address pass karne ki jaroorat nahi hoti aur agar hum bina ponter banaye he aur bina address pass kare he q ko pass kar dete toa vo harbaar uski actul value ko update karta rehta jisse baadme lafde hoa jate.
    q.size = 100;
    q.f = q.b = -1;
    q.array = (int *)malloc(q.size * sizeof(int));
    enque(&q,10); 
    enque(&q,20);
    enque(&q,30);
    enque(&q,40);
    printf("isfull %d\n",isFull(&q));
    printf("isempty %d\n",isEmpty(&q));
    printf("dequed element is %d\n",deque(&q));
    printf("dequed element is %d\n",deque(&q));
    printf("dequed element is %d\n",deque(&q));
    printf("dequed element is %d\n",deque(&q));
    printf("isfull %d\n",isFull(&q));
    printf("isempty %d\n",isEmpty(&q));
    return 0;
}