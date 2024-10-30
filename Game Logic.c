#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int lives = 6;
    char name[50];  
    char currentWord[50];  
    char *words[20] = {
        "DOG", "CAT", "ELEPHANT", "CROCODILE", "HIPPOPOTAMUS", "TORTOISE", "TIGER", "FISH", "SEAGULL", "SEAL",
        "MONKEY", "KANGAROO", "ZEBRA", "GIRAFFE", "RABBIT", "HORSE", "PENGUIN", "BEAR", "SQUIRREL", "HAMSTER"
    };
    int wordCount = 20;
    char alpha;
    int choice;
    char guessWord[50];


    // Random word generation
    srand(time(NULL));
    int randomIndex = rand() % wordCount;
    strcpy(currentWord, words[randomIndex]);
    
    // Initial design
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("\t   HANGMAN\n");
    printf("\tGUESS THE WORD\n");
    
    for (int o=0;o<strlen(currentWord);o++)
    {
    	guessWord[o] ='_';
	}
    printf("\n");
    guessWord[strlen(currentWord)] = '\0'; 
    printf("%s\n", guessWord);

    // Game loop
    while(lives>0) {
        choice = 0;
        scanf(" %c", &alpha);   
        for (int k = 0; k < strlen(currentWord); k++) {
            if (alpha == currentWord[k]) {
                choice = 1;
                guessWord[k]=alpha;
                
            }
        }
        printf("%s",guessWord);
        if (choice == 0) {
            lives--;
        }

        // Check if out of lives and break out of the loop
        if (lives <= 0) {
            break;
        }
        if(strcmp(guessWord,currentWord)==0){
        	break;
		}        
    }

    if (lives > 0) {
        printf("\nVOALAH ! %s \nYOU GUESSED IT WITH %d LIVES REMAINING\nThe word was %s", name, lives,currentWord);
    } else {
        printf("\nYOU FAILED :( The word was %s\n", currentWord);
    }

    return 0;
}
