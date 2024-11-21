#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void viewLeaderboard();
int checkName(char* name);
void addToLeaderboard(char* name, int score);
void sortLeaderboard();
void getWord(char* word, int line);
int randInteger(int max, int min);
void printHangman(int lives);
void getHint(char* currentWord, char* guessWord);
#endif