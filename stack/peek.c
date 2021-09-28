 //peek is a function which returns the value at the asked position from the stack starts from top(uppar se itne number ki value bta de bhai peek)bus yahi hai
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
int peek(struct stack *ptr,int position_i)
{
    if((ptr->top-position_i+1)<0)
    {
        printf("'The position is invalid ~~'\n");
        return -1;

    }
    else{
        return ptr->array[ptr->top-position_i+1];
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
int stack_top(struct stack *ptr)
{return ptr->array[ptr->top];}

int stack_bottom(struct stack *ptr)
{return ptr->array[0];}
int main()
{
   
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));//instance of a stack inside heap 
    sp->size = 8;
    sp->top =-1;
    sp->array = (int *)malloc(sp->size * sizeof(int));
    push(sp,10);//-->position 1
    push(sp,20);//-->position 2
    push(sp,30);//-->position 3
    push(sp,40);//-->position 4
    push(sp,50);//-->position 5                    // kuki stack mai last in first out hota hai toa jo last mai jayeg avhi toa uppar rahega na isliye positions niche se di hai
    push(sp,60);//-->position 6
    push(sp,70);//-->position 7
    push(sp,80);//-->position 8
    push(sp,90);//-->not pushed into stack stack overflow because stack size is 8 and it's a 9th element
    // printf("%d\n",peek(sp,4));
    // printf("%d\n",peek(sp,9));//position_i is invalid 

/*
      for(int i=0;i<=(sp->size-1);i++)
    {
        printf("The element %d of stack is : %d\n",i+1,sp->array[i]);
    }
*/

//stack hota hai khada array LIFO toa agar hum for loop use karenge toa vo aaray ki tareh values print karke dega 
//aur stack ke liye vo values reverse hoa jayegi 
//isliye humne PEEK padha hai ys stack ke hisab se print karega


  for(int i=1;i<=sp->top+1;i++)//array ke 0 index tak he print karana chah rahe hai vaha (pisition_i = 0) hoa jaygi to (top-i+1 = top+1) hoa jayega toa vahin tak loop chalaya hai

    {
        printf("The element %d of stack is : %d\n",i,peek(sp,i));
    }
    printf("\n\n");
    printf("The value of stack top is %d\n",stack_top(sp));
    printf("The value of stack bottom is %d\n",stack_bottom(sp));
return 0;
}