#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void viewLeaderboard();
int checkName(char* name);
void addToLeaderboard(char* name, int score);
void sortLeaderboard();
char* getWord(int line);
int randInteger(int max, int min);
void printHangman(int lives);
char* getHint(char* currentWord, char* guessWord);
#endif
