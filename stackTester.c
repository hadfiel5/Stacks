#include"stack.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void freeStack(struct stackNode *stack){

	if(stack == NULL){return;}

	struct stackNode *temp = stack;

	stack = stack->next;

	temp->next = NULL;
	free(temp);
	temp = NULL;
	
	freeStack(stack);

}

int main(){

	char *command = malloc(sizeof(char) * 6);
	struct stackNode **stack = malloc(sizeof(struct stackNode*));
	*stack = NULL;
	float *kitten = malloc(sizeof(float));

	do{

		printf("Command: ");
		scanf("%s", command);

		if(!strcmp(command, "push")){

			float puppy;

			printf("Number: ");
			scanf("%f", &puppy);

			if(!Push(stack, puppy)){

				printf("Push successful\n");

			}else{

				printf("Push unsuccessful\n");
			}

		}else if(!strcmp(command, "pop")){
		
			if(!Pop(stack, kitten)){

				printf("Element popped: %.2f\n", *kitten);

			}else{

				printf("Nothing to pop - stack is empty\n");
			}
			
		}else if(!strcmp(command, "peek")){
			
			if(!Peek(*stack, kitten)){

				printf("Top element is: %.2f\n", *kitten);

			}else{

				printf("Nothing to peek at - stack is empty\n");

			}

		}else if(!strcmp(command, "print")){

			if(PrintStack(*stack)){

				printf("Cannot print an empty stack!");
			
			}
			printf("\n");
	
		}else if(!strcmp(command, "quit")){}

		else{

			printf("Invalid Command\n");

		}

	}while(strcmp(command, "quit"));

	free(kitten);
	freeStack(*stack);
	free(stack);
	stack = NULL;
	free(command);
}
