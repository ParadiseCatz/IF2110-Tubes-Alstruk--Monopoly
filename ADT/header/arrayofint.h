#ifndef ARRAYOFINT_H
#define ARRAYOFINT_H

#include "boolean.h"

typedef struct {
	int T[105];
	int	 Neff;
} ArrayOfInt;
// Keterangan : Penyimpanan dilakukan mulai indeks 1 s/d Neff
// indeks ke 0 sengaja dikosongkan

void CreateEmptyAOI(ArrayOfInt *A);

boolean isMemberAOI(ArrayOfInt A, int K);

int SearchIdxAOI(ArrayOfInt A, int K);

void PrintAOI(ArrayOfInt A);

void AddAOI(ArrayOfInt *A, int K);

void DeleteAOI(ArrayOfInt *A, int K);

#endif
