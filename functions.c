#include <stdio.h>
#include <string.h>
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
	char line[100], copy[100];
	int count = 0;
	FILE* file = fopen("Files/leaderboard.txt", "r");
	if (file == NULL) { 
		perror("Error opening file"); 
		return 0;
	}
	while(fgets(line, sizeof(line), file)){
		strncpy(copy, line, strlen(name));
		if(strcmp(name, copy) == 0)
			return 1;
	}
	return 0;
}

void addToLeaderboard(char* name, int score){
	if(checkName(name) == 1){
		printf("Name already exists.\n");
		return;
	}
	FILE* file = fopen("Files/leaderboard.txt", "a");
	if (file == NULL) { 
		perror("Error opening file"); 
		return;
	}
	name[strcspn(name, "\n")] = 0;
	fprintf(file, "%s: %d\n", name, score);
	fclose(file);
}
