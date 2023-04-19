#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

char *decryptWord(char word[]);
char readCaracter();
int generateRandomNum();
char *generateWord(FILE* f);

#endif // HEADER_H_INCLUDED
