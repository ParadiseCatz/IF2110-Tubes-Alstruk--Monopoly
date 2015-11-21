#include "../header/arrayofint.h"
#include "../body/arrayofint.c"
#include <stdio.h>

int main()
{
	ArrayOfInt A;
	CreateEmptyAOI(&A);
	int N, i, X;
	scanf("%d",&N);
	for(i=0; i<N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		AddAOI(&A, tmp);
	}
	puts("\nTest PrintAOI");
	PrintAOI(A);
	
	puts("\nTest isMemberAOI");
	scanf("%d",&X);
	if(isMemberAOI(A,X)) puts("Ya, X adalah member");
	else puts("Tidak, X bukan member");
	
	puts("\nTest SearchIdxAOI");
	scanf("%d",&X);
	printf("X ditemukan di : %d\n", SearchIdxAOI(A,X));
	
	puts("\nTest DeleteAOI");
	scanf("%d",&X);
	DeleteAOI(&A, X);
	PrintAOI(A);
	scanf("%d",&X);
	DeleteAOI(&A, X);
	PrintAOI(A);
	
}
