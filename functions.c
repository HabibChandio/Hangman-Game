#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void viewLeaderboard(){
	char line[100];
	int count = 1;
	FILE* file = fopen("Files/leaderboard.txt", "r");
	if (file == NULL) { 
		perror("Error opening file"); 
		return;
	}
	while(fgets(line, sizeof(line), file)){
		printf("%s", line);
		count++;
		if(count == 10){
			fclose(file);
			return;
		}
	}
	fclose(file);
}

int checkName(char* name){
	char line[100], copy[50];
	FILE* file = fopen("Files/leaderboard.txt", "r");
	if (file == NULL) { 
		perror("Error opening file"); 
		return NULL;
	}
	while(fgets(line, sizeof(line), file)){
		sscanf(line, "%49s", copy);
		name[strcspn(name, "\n")] = 0;
		if(strcmp(name, copy) == 0){
			return 1;
		}
	}
	return 0;
}

void addToLeaderboard(char* name, int score){
	FILE* file = fopen("Files/leaderboard.txt", "a");
	if (file == NULL) { 
		perror("Error opening file"); 
		return;
	}
	name[strcspn(name, "\n")] = 0;
	fprintf(file, "%-20s %5d\n", name, score);
	fclose(file);
	sortLeaderboard();
}


void sortLeaderboard(){
	char names[100][50], line[100], tempChar[50];
	int scores[100], lineNo = 0, tempInt = 0, index = 0;
	FILE* file = fopen("Files/leaderboard.txt", "r");
	if (file == NULL) { 
		perror("Error opening file"); 
		return;
	}
	while(fgets(line, sizeof(line), file)){
		sscanf(line, "%49s\t%d", names[lineNo], &scores[lineNo]);
		lineNo++;
	}
	fclose(file);
	for(int i = 0; i < lineNo; i++){
		for(int j = i + 1; j < lineNo; j++){
			if(scores[i] < scores[j]){
				tempInt = scores[i];
				scores[i] = scores[j];
				scores[j] = tempInt;
				strcpy(tempChar, names[i]);
				strcpy(names[i], names[j]);
				strcpy(names[j], tempChar);
			}
		}
	}
	file = fopen("Files/leaderboard.txt", "w");
	if (file == NULL) { 
		perror("Error opening file"); 
		return;
	}
	while(index < lineNo){
		fprintf(file, "%-20s %5d\n", names[index], scores[index]);
		index++;
	}
	fclose(file);
}

char* getWord(int line){
	char* word = (char*)malloc(20*sizeof(char));
	int currentLine = 1;
	FILE* file = fopen("Files/words.txt", "r");
	if (file == NULL){ 
		perror("Error opening file"); 
		return NULL;
	}
	while(fgets(word, 20, file)){
		if(currentLine == line){
			fclose(file);
    		return word;
		}
		currentLine++;
	}
	printf("getWord(): Incorrect Index.\n");
	return NULL;
}

int randInteger(int max, int min){
	return (rand() % (max - min + 1)) + min;
}

void printHangman(int lives){
    switch(lives) {
        case 6:
            printf("  +---+\n"
                   "  |   |\n"
                   "      |\n"
                   "      |\n"
                   "      |\n"
                   "      |\n"
                   "=========\n");
            break;
        case 5:
            printf("  +---+\n"
                   "  |   |\n"
                   "  O   |\n"
                   "      |\n"
                   "      |\n"
                   "      |\n"
                   "=========\n");
            break;
        case 4:
            printf("  +---+\n"
                   "  |   |\n"
                   "  O   |\n"
                   "  |   |\n"
                   "      |\n"
                   "      |\n"
                   "=========\n");
            break;
        case 3:
            printf("  +---+\n"
                   "  |   |\n"
                   "  O   |\n"
                   " /|   |\n"
                   "      |\n"
                   "      |\n"
                   "=========\n");
            break;
        case 2:
            printf("  +---+\n"
                   "  |   |\n"
                   "  O   |\n"
                   " /|\\  |\n"
                   "      |\n"
                   "      |\n"
                   "=========\n");
            break;
        case 1:
            printf("  +---+\n"
                   "  |   |\n"
                   "  O   |\n"
                   " /|\\  |\n"
                   " /    |\n"
                   "      |\n"
                   "=========\n");
            break;
        case 0:
            printf("  +---+\n"
                   "  |   |\n"
                   "  O   |\n"
                   " /|\\  |\n"
                   " / \\  |\n"
                   "      |\n"
                   "=========\n");
            break;
        default:
            printf("Invalid number of lives!\n");
            break;
    }
    

}
char* getHint(char* currentWord, char* guessWord) {
 	int j=0;
	do{
    int i = rand() % strlen(currentWord); 
    guessWord[i] = currentWord[i];
    j++;
    for (int k = 0; k < strlen(guessWord); k++){
		if (currentWord[k] == currentWord[i]){
			guessWord[k]=currentWord[i];
		}
	}}
	while ((strlen(currentWord)/3)>j);
    return guessWord;
}
