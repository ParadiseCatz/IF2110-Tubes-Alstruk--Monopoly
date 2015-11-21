#include "../header/arrayofkata.h"
#include "../body/arrayofkata.c"
#include "../header/kata.h"
#include "../body/kata.c"
#include <stdio.h>
#include <string.h>

int main()
{
	ArrayOfKata A;
	CreateEmptyAOK(&A);
	int N, i;
	Kata X;
	scanf("%d",&N);
	for(i=0; i<N; i++)
	{
		Kata tmp;
		BacaKata(&tmp);
		AddAOK(&A, tmp);
	}
	puts("\nTest PrintAOK");
	PrintAOK(A);
	
	puts("\nTest isMemberAOK");
	BacaKata(&X);
	if(isMemberAOK(A,X)) puts("Ya, X adalah member");
	else puts("Tidak, X bukan member");
	
	puts("\nTest SearchIdxAOK");
	BacaKata(&X);
	printf("X ditemukan di : %d\n", SearchIdxAOK(A,X));
	
	puts("\nTest DeleteAOK");
	BacaKata(&X);
	DeleteAOK(&A, X);
	PrintAOK(A);
	BacaKata(&X);
	DeleteAOK(&A, X);
	PrintAOK(A);
	
}
