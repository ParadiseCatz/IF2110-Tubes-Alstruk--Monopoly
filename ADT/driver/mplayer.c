#include "../../globalvariable.h"
int main(){
	ListPlayer L;
	ListPetak Pt;
	Kata K;
	int i;
	InfoPlayer X;
	ArrayOfInt d;
	ArrayOfKata w;
	StackOfPlayer S;
	CreateEmptyS(&S);
	CreateEmptyAOI(&d);
	CreateEmptyAOK(&w);
	CreateEmptyLPlayer(&L);
	CreateListPetak(&Pt);
	for (i=0;i<4;i++)
	{
		printf("Masukkan nama pemain ke-%d : ",i+1);
		BacaKata(&K);
		X.nama=K;
		X.id=i+1;
		X.idKartu=d;
		X.kota=w;
		X.posisi=First(Pt);
		X.penjara=false;
		X.uang=1000;
		InsVLast(&L,X);
	}
	AddressOfPlayer P=First(L);
	while (P!=Nil)
	{
		PrintElmtPlayer(Info(P));
		P=Next(P);
	}
	P=SearchidPlayer(L,1);
	InfoPlayer temp=Info(P);
	MajuNLangkah(&temp,Pt,4);
	for (i=0;i<4;i++)
	{
		BacaKata(&K);
		AddKota(&temp,K);
	}
	PrintAOK(temp.kota);
	Del(&L,&X,2);
	Push(&S,X);
	Pop(&S,&X);
	PrintElmtPlayer(X);
	PrintAOK(temp.kota);
	return 0;
}
