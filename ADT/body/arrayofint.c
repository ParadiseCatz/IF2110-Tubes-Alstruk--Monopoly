#include "../header/arrayofint.h"

void CreateEmptyAOI(ArrayOfInt *A)
{
	(*A).Neff = 0;
}

int NbElmtAOI(ArrayOfInt A)
{
	return A.Neff;
}

boolean isMemberAOI(ArrayOfInt A, int K)
{
	// Kamus Lokal
	int i;
	boolean Found;
	// Algoritma
	i = 1; Found = false;
	while(i<=NbElmtAOI(A) && !Found)
	{
		if(A.T[i] == K) Found = true;
		else i++;
	}
	if(Found) return true;
	else return false;
}

int SearchIdxAOI(ArrayOfInt A, int K)
{
	// Kamus Lokal
	int i;
	boolean Found;
	// Algoritma
	i = 1; Found = false;
	while(i<=NbElmtAOI(A) && !Found)
	{
		if(A.T[i] == K) Found = true;
		else i++;
	}
	if(Found) return i;
	else return -1;
}

void PrintAOI(ArrayOfInt A)
{
	// Kamus Lokal
	int i;
	// Algoritma
	printf("[");
	for(i=1; i<=NbElmtAOI(A); i++)
	{
		if(i==1) printf("%d", A.T[i]);
		else printf(", %d", A.T[i]);
	}
	printf("]\n");
}

void AddAOI(ArrayOfInt *A, int K)
{
	(*A).Neff++;
	(*A).T[NbElmtAOI(*A)] = K;
}

void DeleteAOI(ArrayOfInt *A, int K)
{
	// Kamus Lokal
	int i;
	// Algoritma
	i = SearchIdxAOI(*A, K);
	for(;i<NbElmtAOI(*A); i++)
	{
		(*A).T[i] = (*A).T[i+1];
	}
	(*A).Neff--;
}
