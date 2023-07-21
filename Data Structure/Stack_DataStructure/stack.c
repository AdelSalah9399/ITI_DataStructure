#include <stdio.h>
#include "stack.h"



/************************************** Static Func Prototype *******************************************/
/*
 *@brief  function to chek the full state of a stack
 *@param  Copy_Stack  pointer to struct type (stack)
 *@retval enum value status_status_t
 */
static stack_status_t Stack_Is_Full(stack_ds_t * Copy_Stack);
/*
 *@brief  function to chek the empty state of a stack
 *@param  Copy_Stack  pointer to struct type (stack)
 *@retval enum value status_status_t
 */
static stack_status_t Stack_Is_Empty(stack_ds_t * Copy_Stack);


/************************************** func Implementation *********************************************/

/*
 *@brief  function to init the stack
 *@param  Copy_Stack  pointer to struct type (stack)
 *@retval enum value return_status_t
 */
return_status_t Stack_Init(stack_ds_t * Copy_Stack)
{
	return_status_t ret =R_NOK;
	if(Copy_Stack != NULL)
	{	
		ret = R_OK;
		(Copy_Stack->SP) = -1;
	}
	else{
		ret = R_NOK;
	}
	return ret;
}
/*
 *@brief  function to push data to stack
 *@param  Copy_Stack  pointer to struct type (stack) & Copy_Data  u32 data
 *@retval enum value return_status_t
 */
return_status_t Stack_Push(stack_ds_t * Copy_Stack, u32 Copy_Data)
{	
	return_status_t ret = R_NOK;
	// Check for Stack full and NULL pointer
	if ((Stack_Is_Full(Copy_Stack) == STACK_FULL) || (Copy_Stack == NULL))
	{
		ret = R_NOK;
		if((Stack_Is_Full(Copy_Stack) == STACK_FULL))
		printf("!!!!!!! Pushing Error STACK IS FULL !!!!!!!\n");
		if((Copy_Stack == NULL))
		printf("!!!!!!! Pushing Error NULL PASSED STRUCT !!!!!!!\n");
	}
	else
	{
		(Copy_Stack->SP)++;  								  // Increment the SP
		#if SHOW_STACK_STATUES
		printf("sp=(%d)\n", Copy_Stack->SP);
		#endif
		Copy_Stack->stack_Array[Copy_Stack->SP] = Copy_Data;  // Push the data to stack at SP index
		#if SHOW_STACK_STATUES
		printf("value (%d) pushed  to the stack successfully\n", Copy_Data);
		#endif
		ret = R_OK;
	}
	return ret;
}
/*
 *@brief  function to pop data from stack
 *@param  Copy_Stack  pointer to struct type (stack) & ret_Data  pointer to u32 poped data
 *@retval enum value return_status_t
 */
return_status_t Stack_Pop(stack_ds_t * Copy_Stack,u32 * ret_Data)
{
	return_status_t ret =R_NOK;
	//check stack is empty or not and NULL check
	if((Stack_Is_Empty(Copy_Stack)==STACK_EMPTY) || Copy_Stack==NULL || ret_Data==NULL)
	{
		ret = R_NOK;
		if((Stack_Is_Empty(Copy_Stack)==STACK_EMPTY))
		printf("!!!!!!! poping Error STACK IS EMPTY !!!!!!!\n");
		if((Copy_Stack == NULL))
		printf("!!!!!!! poping Error NULL PASSED STRUCT !!!!!!!\n");
		if((ret_Data == NULL))
		printf("!!!!!!! poping Error NULL PASSED RET_DATA VARIABLE !!!!!!!\n");
	}
	else{
		*ret_Data=Copy_Stack->stack_Array[Copy_Stack->SP];
		#if SHOW_STACK_STATUES
		printf("value (%d) poped from the stack successfully\n", *ret_Data);
		#endif
		(Copy_Stack->SP)--;
		#if SHOW_STACK_STATUES
		printf("sp=(%d)\n", Copy_Stack->SP);
		#endif
		ret = R_OK;
	}
	return ret;
}
/*
 *@brief  function to get the top of stack
 *@param  Copy_Stack  pointer to struct type (stack) & ret_Top  pointer to u32 top stack data
 *@retval enum value return_status_t
 */
return_status_t Stack_Top(stack_ds_t * Copy_Stack,u32 * ret_Top)
{
	return_status_t ret =R_NOK;
	//check stack is empty or not and NULL check
	if((Stack_Is_Empty(Copy_Stack)==STACK_EMPTY) || Copy_Stack==NULL || ret_Top==NULL)
	{
		ret = R_NOK;
		if((Stack_Is_Empty(Copy_Stack)==STACK_EMPTY))
		printf("!!!!!!! Error STACK IS EMPTY !!!!!!!\n");
		if((Copy_Stack == NULL))
		printf("!!!!!!! Error NULL PASSED STRUCT !!!!!!!\n");
		if((ret_Top == NULL))
		printf("!!!!!!! Error NULL PASSED RET_فخح VARIABLE !!!!!!!\n");
	}
	else{
		*ret_Top=Copy_Stack->stack_Array[Copy_Stack->SP];
		#if SHOW_STACK_STATUES
		printf("value (%d) is the top of stack \n", *ret_Top);
		#endif
		printf("sp=(%d)\n", Copy_Stack->SP);
		ret = R_OK;
	}
	return ret;
}
/*
 *@brief  function to get the size of stack
 *@param  Copy_Stack  pointer to struct type (stack) & ret_Size  pointer to u32 top stack size
 *@retval enum value return_status_t
 */
return_status_t Stack_Size(stack_ds_t * Copy_Stack,u32 * ret_Size)
{
{	
	return_status_t ret = R_NOK;
	// Check for Stack full and NULL pointer
	if ((Copy_Stack == NULL) || (ret_Size == NULL))
	{
		ret = R_NOK;
		if((ret_Size == NULL))
		printf("!!!!!!! Error NULL PASSED RET_SIZE !!!!!!!\n");
		if((Copy_Stack == NULL))
		printf("!!!!!!! Error NULL PASSED STRUCT !!!!!!!\n");
	}
	else
	{
		*ret_Size = (Copy_Stack->SP)+1;
		#if SHOW_STACK_STATUES
		printf("stack size is (%d) \n", *ret_Size);
		#endif
		ret = R_OK;
	}
	return ret;
}
}
/*
 *@brief  function to displat whole stack
 *@param  Copy_Stack  pointer to struct type (stack)
 *@retval enum value return_status_t
 */
return_status_t Stack_Display(stack_ds_t * Copy_Stack)
{
	if(Stack_Is_Empty(Copy_Stack)==STACK_EMPTY)
	{
		printf("stack is EMPTY\n");
	}
	else{
		u32 i;
		for(i=0;i<=Copy_Stack->SP;i++)
		{
			printf("element with index %d is (%d)\n",i,Copy_Stack->stack_Array[i]);
		}
	}
}

/************************************** Static Func Implementation **************************************/
static stack_status_t Stack_Is_Full(stack_ds_t * Copy_Stack)
{
	if(((Copy_Stack->SP)==MAX_SIZE-1) && (Copy_Stack != NULL))
	{
		return STACK_FULL;
	}
	else{
		return STACK_NOT_FULL;
	}
}
static stack_status_t Stack_Is_Empty(stack_ds_t * Copy_Stack)
{
	if(((Copy_Stack->SP)==-1) && (Copy_Stack != NULL))
	{
		return STACK_EMPTY;
	}
	else{
		return STACK_NOT_FULL;
	}
}
