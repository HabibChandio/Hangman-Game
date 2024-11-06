#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
	int lives = 6, wordCount = 30, max = 0;
    char name[50];  
    char alpha;
    int choice;
	int count=0;
    char guessWord[50];
	int flag, correct = 0;;
	char* word = (char*)malloc(20*sizeof(char));
	
	printf("-------------WELCOME TO HANGMAN-------------\n\n");
	do{
		printf("1. Start\n2. Leaderboard\n3. Quit\n");
		scanf("%d",&choice);
		if(choice == 1) {		
			for(int i=0; i<20 && lives>0; i++){
				if (i>4 && i<12){
					wordCount = 30;
					max = 30;
    			}
    			else if (i>11){
					wordCount = 40;
					max = 60;
    			}
    			strcpy(word, getWord(randIndex(wordCount, max)));
				for (int o=0;o<strlen(word)-1;o++){			
					   	guessWord[o] = '_';
				}    
				guessWord[strlen(word)-1] = '\0'; 
				printf("%s\n", guessWord);	
    			puts(word);
    			word[strcspn(word, "\n")] = 0;
    			guessWord[strcspn(guessWord, "\n")] = 0;
				while(lives>0) {
		       		flag = 0;
		       		printf("\n");
		        	scanf(" %c", &alpha);   
		        	for (int k = 0; k < strlen(guessWord); k++){
				        if (alpha == word[k]){
				            flag = 1;
				            guessWord[k]=alpha;
		                }
		        	}
		        		
					printf("%s",guessWord);
					if (flag == 0) {
				        lives--;
				    }		
					// Check if out of lives and break out of the loop
					if (lives <= 0) {
				        break;
				    }
				    if(strcmp(guessWord,word)==0){
				        printf("\n");
				        break;
					}   		  
				}
			}
		}
		else if(choice == 2){
			viewLeaderboard();
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
