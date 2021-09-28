#include<stdio.h>
#include<stdlib.h>
typedef struct abstractArray{
    int reserved_memory;
    int usable_memory;
    int *ptr;

}absarr;

int create_an_array(absarr *marks,int fixed_memory,int usable_memory)
{
    // (*marks).reserved_memory=fixed_memory;
    // (*marks).usable_memory=usable_memory;
    // (*marks).ptr=(int*)malloc(fixed_memory*sizeof(int));
    marks->reserved_memory=fixed_memory;
    marks->usable_memory=usable_memory;
    marks->ptr=(int*)malloc(fixed_memory*sizeof(int));


 
}
int get_values_in_array(absarr *marks)

{
    // for(int i=0;i<(*marks).usable_memory;i++)
    for(int i=0;i<marks->usable_memory;i++)
    {
    scanf("%d",&(*marks).ptr[i]);

    }

}
int print_values_of_array(absarr *marks)

{
    // for(int i=0;i<(*marks).usable_memory;i++)
    for(int i=0;i<marks->usable_memory;i++)
    {
    printf("%d\t",(*marks).ptr[i]);

    }

}
int main()
{
    absarr marks;
    create_an_array(&marks,10,4);
    printf("now call get function\n");
    get_values_in_array(&marks);
    printf("now call print function\n");
    print_values_of_array(&marks);

    return 0;

}