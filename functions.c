#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
		fprintf(file, "%-20s %5d\n", name, score);
		sortLeaderboard();
		fclose(file);
	}
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
	FILE* file = fopen("Files/name.txt", "r");
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
