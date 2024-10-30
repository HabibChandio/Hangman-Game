#include <stdio.h>
#include "functions.h"

int main(){
	int choice;
	
	printf("------------------------HANGMAN------------------------\n\n");
	do{
		printf("1. Start game\n2. View leaderboard\n3. Quit");
		scanf("%d", &choice);		
		
		switch(choice) 
		{			
			case 1:
				//start case
				break;
			case 2:
				//leaderboard
				break;
			case 3:
				printf("Thanks for playing!!!\n");
				return 0;
				break;
			default:
				printf("Incorrect input!\n");
				continue;			
		}
	}while(//);
	return 0;
}
