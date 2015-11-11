#ifndef KATA_H
#define KATA_H
#define NMAX 105
#include <stdio.h>

//definisi tipe kata
typedef struct {
	char TabKata[NMax];
	int	 Length;
} Kata;

int Size(Kata K);

void Copy(Kata in, Kata *out);

boolean IsKataSama(Kata K1, Kata K2);

void PrintKata(Kata K);

int KataToInt(Kata K);

double KataToDouble(Kata K);

#endif
