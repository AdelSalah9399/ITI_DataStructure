#include <stdio.h>
#include "stack.h"


stack_ds_t stack1;
stack_ds_t stack2;

//void Stack_test(stack_ds_t * Copy_Stack,u32 Copy_Data);

void main()
{
	u32 x,y;
	//Stack_test(&stack1,55);
	return_status_t ret =R_NOK;

	ret = Stack_Init(&stack1);
    if (ret == R_NOK)
    {
        printf("error stack1 init\n");
    }
	else{
		ret = Stack_Push(&stack1,11);
		ret = Stack_Push(&stack1,22);
		ret = Stack_Push(&stack1,33);
		ret = Stack_Push(&stack1,44);
		ret = Stack_Push(&stack1,55);
		Stack_Pop(&stack1,&x);
		Stack_Pop(&stack1,&x);
		Stack_Pop(&stack1,&x);
		Stack_Pop(&stack1,&x);
		Stack_Pop(&stack1,&x);
		//Stack_Size(&stack1,&y);
		Stack_Display(&stack1);
		//Stack_Top(&stack1,&y);
		//printf("%d",y);
		//ret = Stack_Push(&stack1,66);
		//ret = Stack_Push(&stack1,77);

		}
	
	
	
    ret = Stack_Init(&stack2);
    if (ret == R_NOK)
    {
        printf("error stack2 init\n");
    }
}
/*
void Stack_test(stack_ds_t * Copy_Stack,u32 Copy_Data)
{
		Copy_Stack->SP++;						  //1-increment SP
		printf("sp=(%d)\n",Copy_Stack->SP);
}
*/