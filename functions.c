#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

void viewLeaderboard(){
	char line[100];
	FILE* file = fopen("Files/leaderboard.txt", "r");
	if (file == NULL) { 
		perror("Error opening file"); 
		return;
	}
	while(fgets(line, sizeof(line), file)){
		printf("%s", line);
	}
	fclose(file);
}

int checkName(char* name){
	char line[100], copy[50];
	FILE* file = fopen("Files/leaderboard.txt", "r");
	if (file == NULL) { 
		perror("Error opening file"); 
		return 0;
	}
	while(fgets(line, sizeof(line), file)){
		sscanf(line, "%49s", copy);
		printf("copy: %s, name: %s", copy, name);
		name[strcspn(name, "\n")] = 0;
		if(strcmp(name, copy) == 0){
			printf(", copy: %s", copy);
			return 1;
		}
	}
	return 0;
}

void addToLeaderboard(char* name, int score){
	if(checkName(name) == 1){
		printf("Name already exists.\n");
		return;
	}
	else{
		FILE* file = fopen("Files/leaderboard.txt", "a");
		if (file == NULL) { 
			perror("Error opening file"); 
			return;
		}
		name[strcspn(name, "\n")] = 0;
		fprintf(file, "%s\t%d\n", name, score);
		fclose(file);
	}
}

char* getWord(int line){
	char* word = (char*)malloc(20*sizeof(char));
	int currentLine = 1;
	FILE* file = fopen("Files/words.txt", "r");
	if (file == NULL) { 
		perror("Error opening file"); 
		return NULL;
	}
	while(fgets(word, sizeof(word), file)){
		if(currentLine == line){
			fclose(file);
    		return word;
		}
		currentLine++;
	}
	printf("getWord(): Incorrect Index.\n");
	return NULL;
}
