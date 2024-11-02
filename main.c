#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){
	int choice, score = 0;
	char name[50];
	char* word = (char*)malloc(20*sizeof(char));
	
	printf("------------------------HANGMAN------------------------\n\n");
	do{
		printf("1. Start game\n2. View leaderboard\n3. Quit\n");
		getchar();
		scanf("%d", &choice);		
					
			if(choice == 1) {
				printf("Enter Your Name: ");
				getchar();
				fgets(name, 50, stdin);
				addToLeaderboard(name, score);
				word = getWord(3);
				puts(word); 			
			}		
			else if(choice == 2) {
				viewLeaderboard();
			}
			else if(choice == 3) {
				printf("Thanks for playing!!!\n");
				return 0;
			}
			else {
				printf("Incorrect input!\n");
				continue;
			}
		}
	}while(1);
	return 0;
}
