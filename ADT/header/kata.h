#ifndef KATA_H
#define KATA_H
#include <stdio.h>
#include <string.h>
#include "boolean.h"

typedef struct {
	char TabKata[105];
	int	 Length;
} Kata;

int Size(Kata K);

void Copy(Kata in, Kata *out);

boolean IsKataSama(Kata K1, Kata K2);

void BacaKata(Kata *K);

void PrintKata(Kata K);

int KataToInt(Kata K);

double KataToDouble(Kata K);

#endif
