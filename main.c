#include <stdio.h>
#include "functions.h"

int main(){
	int choice, score = 0;
	char name[50];
	
	printf("------------------------HANGMAN------------------------\n\n");
	do{
		printf("1. Start game\n2. View leaderboard\n3. Quit\n");
		scanf("%d", &choice);		
		
		switch(choice) 
		{			
			case 1:
				printf("Enter Your Name: ");
				getchar();
				fgets(name, 50, stdin);
				addToLeaderboard(name, score);
				break;
			case 2:
				viewLeaderboard();
				break;
			case 3:
				printf("Thanks for playing!!!\n");
				return 0;
				break;
			default:
				printf("Incorrect input!\n");
				continue;			
		}
	}while(1);
	return 0;
}
