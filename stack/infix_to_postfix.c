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
int stackTop(struct stack *ptr)
{
    return ptr->array[ptr->top];
}
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
int precidence(char oprt)
{
    if (oprt == '*' || oprt == '/')
    {
        return 2;
    }
    else if (oprt == '+' || oprt == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isoperator(char oprt)
{
    if (oprt == '*' || oprt == '/' || oprt == '+' || oprt == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack)); //hamesha stack ka instance banana jaroori haui nahi toa sirf pointer he bana reh jayega value kaime store karenge
    sp->size = 50;
    sp->top = -1;
    sp->array = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; //for infix traversing
    int j = 0; //for postfix append
    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precidence(infix[i]) > precidence(stackTop(sp)))
            {
                push(sp, infix[i]); //hamesha i ko increase karna padega nahi toa infix aage he nahi badhega toa stack mai opetaror kaise jayenge
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!empty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "x-y/z-k*d";
    printf("The postfix expression is %s\n", infixToPostfix(infix));

    return 0;
}