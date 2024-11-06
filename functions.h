#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void viewLeaderboard();
int checkName(char* name);
void addToLeaderboard(char* name, int score);
void sortLeaderboard();
char* getWord(int line);
int randIndex(int wordCount,int max);
#endif
