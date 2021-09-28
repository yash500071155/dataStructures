#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct stack
{
    int size;
    int top;
    int *array;
};
int empty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
int full(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}
int push(struct stack *ptr, int value)
{
    if (full(ptr))
    {
        printf("stack overflow: the value %d is not pushed into stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->array[ptr->top] = value;//call by reference hai to ye main mai bhi value update karega call by value hota toa nahi karta value upadate
    }
}
int pop(struct stack *ptr)
{
    if (empty(ptr))
    {
        printf("stack underflow!!\n");
    }
    else
    {
        int value=ptr->array[ptr->top];
        ptr->top--;
        return value;
    }
}
int main()
{
   
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));//instance of a stack inside heap 
    sp->size = 8;
    sp->top =-1;
    sp->array = (int *)malloc(sp->size * sizeof(int));
    push(sp,10);
    push(sp,20);
    push(sp,30);
    push(sp,40);
    push(sp,50);
    push(sp,60);
    push(sp,70);
    push(sp,80);
    push(sp,90);
    printf("%d\n",full(sp));
    printf("%d\n",empty(sp));
    printf("The stack after push is:\n\n");

  
    printf("The stack after pop is:\n\n");
    printf("The value %d is poped from the stack\n",pop(sp));
    printf("The value %d is poped from the stack\n",pop(sp));
    printf("The value %d is poped from the stack\n",pop(sp));
    printf("The value %d is poped from the stack\n",pop(sp));
   push(sp,222);
   push(sp,333);
   push(sp,444);
   push(sp,555);
   
 printf("%d\n",full(sp));
    printf("%d\n",empty(sp));
    return 0;
}