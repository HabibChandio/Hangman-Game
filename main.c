#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "functions.h"

int main()
{
	int lives = 6, wordCount = 30, max = 0, flag = 0, choice = 0, score = 0;
    char name[20], alpha, guessWord[50];
	char* word = (char*)malloc(20*sizeof(char));
	
	do{
		printf("-------------WELCOME TO HANGMAN-------------\n\n");
		printf("1. Start\n2. Leaderboard\n3. Quit\n");
		printf("Selection(1 - 3): ");
		scanf("%d",&choice);
		system("cls"); 
		if(choice == 1){
			do{	
				printf("Enter your name: ");
				getchar();
				gets(name);
				if(checkName(name) == 1){
					printf("Name already exists.\n");
				}
				else
					break;
			}while(1);
			system("cls");	
			for(int i = 0; i < 10 && lives > 0; i++){
				if (i == 2){
					wordCount = 30;
					max = 30;
    			}
    			else if (i == 5){
					wordCount = 40;
					max = 60;
    			}
    			strcpy(word, getWord(randIndex(wordCount, max)));
				for (int j = 0; j < strlen(word) - 1; j++){			
					   	guessWord[j] = '_';
				}    
				guessWord[strlen(word) - 1] = '\0'; 
    			word[strcspn(word, "\n")] = 0;
    			guessWord[strcspn(guessWord, "\n")] = 0;
				while(lives>0) {
		       		flag = 0;
		       		if(i < 2)
				        	printf("DIFFICULTY: EASY\n");
				        else if(i < 5)
				        	printf("DIFFICULTY: MEDIUM\n");
				        else
				        	printf("DIFFICULTY: HARD\n");
				    printHangman(lives);
		       		printf("\n%s\n\n",guessWord);
		       		printf("Guess a character: ");
		        	scanf(" %c", &alpha);   
		        	for (int k = 0; k < strlen(guessWord); k++){
				        if (alpha == word[k]){
				            flag = 1;
				            guessWord[k]=alpha;
		                }
		        	}
					system("cls"); 
					if (flag == 0){
						lives--;
				    }		
					// Check if out of lives and break out of the loop
					if (lives <= 0){
				        break;
				    }
				    if(strcmp(guessWord,word)==0){
				        if(i < 2)
				        	score += 5;
				        else if(i < 5)
				        	score += 10;
				        else
				        	score += 15;
				        break;
					}   		  
				}
			}
			printf("You scored: %d!!!!\n", score);
			addToLeaderboard(name, score);
			printf("--------Leaderboard--------\n\n");
			printf("%-20s %5s\n\n", "NAMES", "SCORE");
			viewLeaderboard();
			printf("\n");
			lives = 6;
		}
		else if(choice == 2){
			printf("--------Leaderboard--------\n\n");
			printf("%-20s %5s\n\n", "NAMES", "SCORE");
			viewLeaderboard();
			printf("\n");
		} 
		else if(choice == 3){
			printf("Thanks for playing.\n");
			return 0;
		}
			
		else
			printf("Invalid input\n");
	  }while(1);
	    
	return 0;
}
