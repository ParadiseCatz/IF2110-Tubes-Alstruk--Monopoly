#include "../header/arrayofkata.h"

void CreateEmptyAOK(ArrayOfKata *A)
{
	(*A).Neff = 0;
}


int NbElmtAOK(ArrayOfKata A)
{
	return A.Neff;
}

boolean isMemberAOK(ArrayOfKata A, Kata K)
{
	// Kamus Lokal
	int i;
	boolean Found;
	// Algoritma
	i = 1; Found = false;
	while(i<=NbElmtAOK(A) && !Found)
	{
		if(IsKataSama(A.T[i], K)) Found = true;
		else i++;
	}
	if(Found) return true;
	else return false;
}

int SearchIdxAOK(ArrayOfKata A, Kata K)
{
	// Kamus Lokal
	int i;
	boolean Found;
	// Algoritma
	i = 1; Found = false;
	while(i<=NbElmtAOK(A) && !Found)
	{
		if(IsKataSama(A.T[i], K)) Found = true;
		else i++;
	}
	if(Found) return i;
	else return -1;
}

void PrintAOK(ArrayOfKata A)
{
	// Kamus Lokal
	int i;
	// Algoritma
	printf("[");
	for(i=1; i<=NbElmtAOK(A); i++)
	{
		if(i==1) PrintKata(A.T[i]);
		else
		{
			printf(", ");
			PrintKata(A.T[i]);
		}
	}
	printf("]\n");
}

void BacaKataWithValidation(Kata *K, ArrayOfKata S)
{
	Kata tmp;
	do
	{
		scanf("%s",tmp.TabKata);
		tmp.Length = strlen(tmp.TabKata);
		
		if(!isMemberAOK(S,tmp)) printf("Masukan salah, ulangi!\n");
		
	} while(!isMemberAOK(S, tmp));
	*K = tmp;
}

void AddAOK(ArrayOfKata *A, Kata K)
{
	(*A).Neff++;
	(*A).T[NbElmtAOK(*A)] = K;
}

void DeleteAOK(ArrayOfKata *A, Kata K)
{
	// Kamus Lokal
	int i;
	// Algoritma
	i = SearchIdxAOK(*A, K);
	for(;i<NbElmtAOK(*A); i++)
	{
		(*A).T[i] = (*A).T[i+1];
	}
	(*A).Neff--;
}
