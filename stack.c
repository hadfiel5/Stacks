#include"stack.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct stackNode node;

static node *NewStackNode(float item){

	node *temp = malloc(sizeof(node));

	temp->data = item;
	temp->next = NULL;

	return temp;

}


int Push(node **stack, float item){

	if(*stack == NULL){

		*stack = NewStackNode(item);
		return 0;
	
	}else{

		node *temp = *stack;

		*stack = NewStackNode(item);

		if(*stack == NULL){

			*stack = temp;
			return -1;

		} 

		(*stack)->next = temp;
		temp = NULL;
		return 0;
	}
}

int Pop(node **stack, float *item){

	if(*stack == NULL){return -1;}

	*item = (*stack)->data;

	node *temp = (*stack);

	*stack = (*stack)->next;

	temp->next = NULL;
	free(temp);

	return 0;

}

int Peek(node *stack, float *item){

	if(stack == NULL){return -1;}

	*item = stack->data;

	return 0;

}

int PrintStack(node *stack){

	if(stack == NULL){return -1;}

	node *temp = stack;

	while(temp != NULL){

		printf("%.2f  ", temp->data);
		temp = temp->next;

	}
	return 0;
}
