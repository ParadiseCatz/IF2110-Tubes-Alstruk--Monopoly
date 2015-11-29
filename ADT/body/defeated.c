#include "../header/defeated.h"
#include "../header/player.h"

void CreateEmptyS(StackOfPlayer *S) {
    Top(*S)=Nil;
}

void Push (StackOfPlayer *S, InfoPlayer X) {
    AddressOfPlayer P=Alokasi(X);
	if(P!=Nil){
		Next(P)=Top(*S);
		Top(*S)=P;
	}
}

void Pop (StackOfPlayer *S, InfoPlayer *X){
    *X=InfoTop(*S);
	AddressOfPlayer P=Top(*S);
	Top(*S)=Next(P);
	Dealokasi(&P);
}
