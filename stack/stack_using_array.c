#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct stack{
int size;
int top;
int *array;
};
int empty(struct stack*ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    return 0;

}
int full(struct stack*ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    return 0;
    

}
int main()
{
    // struct stack s;
    // s.size=50;
    // s.top=-1;
    // s.array=(int*)malloc(s.size*sizeof(int));
    struct stack *s;
    s->size=50;
    s->top=-1;
    s->array=(int*)malloc(s->size*sizeof(int));
    //manually input
    s->array[0]=10;
    s->top++;
    // printf("The first element of our stack with manual value is %d\n",s->array[0]);
    //stack is empty or not
   if(empty(s))//1->true  0->false    true aate he loop chalega false mai nahi chalega
   {
       printf("The stack is empty\n");

   }
   else{
       printf("The stack is not empty");
   }



    
    return 0;
}