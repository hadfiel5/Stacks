#include<stdlib.h>
#include<stdio.h>
#include"stack.h"
#include<string.h>


//Fucking Recursion
void freeStack(struct stackNode *stack){

	if(stack == NULL){return;}

	struct stackNode *temp = stack;

	stack = stack->next;

	temp->next = NULL;
	free(temp);
	temp = NULL;
	
	freeStack(stack);

}


int RPN(char *command, float *result){

	struct stackNode **stack = malloc(sizeof(struct stackNode *));
	*stack = NULL;
	int firstop = 1;
	float total = 0, *helper = malloc(sizeof(float));
	for(int i = 0; i < strlen(command); i++){

		char thing = command[i];

		if(thing == '+' || thing == '-' || thing == '/' || thing == '*'){

			if(firstop){

				if(Pop(stack, helper)){

					freeStack(*stack);
					free(stack);
					free(helper);
					helper = NULL;
					return -1;
				}
				firstop = 0;
				total = *helper;						

			}

			if(Pop(stack, helper)){
			
				freeStack(*stack);
				free(stack);
				free(helper);
				helper = NULL;
				return -1;
			}
		}

		switch(thing){

			case '+':

				
				total += *helper;
				break;

			case '-':
	
				total -= *helper;
				break;

			case'*':

				total *= *helper;
				break;

			case'/':

				total /= *helper;
				break;

			case ' ':
				
				break;

			default:

				Push(stack, (float)atof(&thing));
				break;	

		}

	}
	
	if(!Peek(*stack, helper)){

		freeStack(*stack);
		free(stack);
		free(helper);
		helper = NULL;
		return -1;

	}
	else{

		*result = total;
		free(stack);
		free(helper);
		helper = NULL;
		return 0;
	}
}

int main(){

	char command[80];
	float *answer = malloc(sizeof(float));

	do{
	
		int i = 0;

		printf("Expression: ");
		
		command[i] = (char)getchar();
		while(i < 80 && command[i] != '\n'){

			i++;
			command[i] = (char)getchar();

		}

		command[i] = '\0';

		if(!strcmp(command, "quit")){break;}
		if(!RPN(command, answer)){

			printf("Result: %d\n\n", (int)*answer);

		}else{

			printf("Invalid Command\n");

		}

	}while(strcmp(command, "quit"));

	free(answer);
}
