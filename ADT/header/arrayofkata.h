#ifndef ARRAYOFKATA_H
#define ARRAYOFKATA_H
#include <stdio.h>
#include "kata.h"
#include "boolean.h"

typedef struct {
	Kata T[105];
	int	 Neff;
} ArrayOfKata;
// Keterangan : Penyimpanan dilakukan mulai indeks 1 s/d Neff
// indeks ke 0 sengaja dikosongkan

void CreateEmptyAOK(ArrayOfKata *A);

int NbElmtAOK(ArrayOfKata A);

boolean isMemberAOK(ArrayOfKata A, Kata K);

int SearchIdxAOK(ArrayOfKata A, Kata K);

void PrintAOK(ArrayOfKata A);

void AddAOK(ArrayOfKata *A, Kata K);

void DeleteAOK(ArrayOfKata *A, Kata K);

#endif
