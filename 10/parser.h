#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

int GetG (const char* expression);
int GetE (const char* expression, size_t* index);
int GetT (const char* expression, size_t* index);
int GetP (const char* expression, size_t* index);
int GetN (const char* expression, size_t* index);

void pass_space (const char* expression, size_t* index);
void strn_tolower (char* str, const size_t N);

#endif //PARSER_H