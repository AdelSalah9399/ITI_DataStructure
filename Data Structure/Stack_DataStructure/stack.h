
#ifndef _STACK_H_
#define _STACK_H_
/************************************** INCLUDES ***************************************************/
#include "STD_TYPES.h"
/************************************** MACROS *****************************************************/
//config>>>>>>>>>
#define MAX_SIZE  5
/************************************** -DEBUG MODE- ***********************************************/
/**********************/
#define SHOW      1
#define HIDE      0
/**********************/
//config>>>>>>>>>
#define SHOW_STACK_STATUES     SHOW
/************************************** user define datatypes **************************************/
typedef enum {
	R_NOK,
	R_OK
}return_status_t;

typedef enum {
	STACK_EMPTY,
	STACK_FULL,
	STACK_NOT_FULL
}stack_status_t;

typedef struct{
	s32 SP;
	u32 stack_Array[MAX_SIZE];
}stack_ds_t;

/************************************** Prototypes**************************************************/

/*
 *@brief  function to init the stack
 *@param  Copy_Stack  pointer to struct type (stack)
 *@retval enum value return_status_t
 */
return_status_t Stack_Init(stack_ds_t * Copy_Stack);
/*
 *@brief  function to push data to stack
 *@param  Copy_Stack  pointer to struct type (stack) & Copy_Data  u32 data
 *@retval enum value return_status_t
 */
return_status_t Stack_Push(stack_ds_t * Copy_Stack,u32 Copy_Data);
/*
 *@brief  function to pop data from stack
 *@param  Copy_Stack  pointer to struct type (stack) & ret_Data  pointer to u32 poped data
 *@retval enum value return_status_t
 */
return_status_t Stack_Pop(stack_ds_t * Copy_Stack,u32 * ret_Data);
/*
 *@brief  function to get the top of stack
 *@param  Copy_Stack  pointer to struct type (stack) & ret_Top  pointer to u32 top stack data
 *@retval enum value return_status_t
 */
return_status_t Stack_Top(stack_ds_t * Copy_Stack,u32 * ret_Top);
/*
 *@brief  function to get the size of stack
 *@param  Copy_Stack  pointer to struct type (stack) & ret_Size  pointer to u32 top stack size
 *@retval enum value return_status_t
 */
return_status_t Stack_Size(stack_ds_t * Copy_Stack,u32 * ret_Size);
/*
 *@brief  function to displat whole stack
 *@param  Copy_Stack  pointer to struct type (stack)
 *@retval enum value return_status_t
 */
return_status_t Stack_Display(stack_ds_t * Copy_Stack);


#endif //_STACK_H_
