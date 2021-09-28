#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct stack
{
    int size;
    int top;
    char *array;
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
void push(struct stack *ptr, char value)
{
    if (full(ptr))
    {
        printf("stack overflow: the value %c is not pushed into stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->array[ptr->top] = value; //call by reference hai to ye main mai bhi value update karega call by value hota toa nahi karta value upadate
    }
}
char pop(struct stack *ptr)
{
    if (empty(ptr))
    {
        printf("stack underflow!!\n");
        return -1;
    }
    else
    {
        char value = ptr->array[ptr->top];
        ptr->top--;
        return value;
    }
}
int pm(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->array = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (empty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
        if (empty(sp))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    
}
int main()
{
    char *arr = "((((((((((((((((((())))))))))))))))))";
    // char *arr = "2+(2-3)-33(3-0))";
    // char *arr = "2+(2-3)-33(3-0)";

    if (pm(arr))
    {
        printf("The parenthis are matching\n");
    }
    else
    {
        printf("The parenthisis are not matching\n");
    }

    return 0;
}