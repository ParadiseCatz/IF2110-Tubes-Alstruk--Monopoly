#include "../header/player.h"
#include "../header/boolean.h"
#include "../header/arrayofint.h"
#include "../header/arrayofkata.h"
#include "../header/kata.h"

void CreateEmptyLPlayer (ListPlayer *L)
{
	First(*L)=Nil;
}

boolean IsLPlayerEmpty (ListPlayer L)
{
	return (First(L)==Nil);
}

void PrintElmtPlayer (InfoPlayer X)
{
	int i,N=Size(X.nama);
	Kata temp=X.nama;
	for (i=0;i<N;i++){
		printf("%c",temp.TabKata[i]);
	}
	printf("\n");
	printf("%d\n",X.uang);
}

AddressOfPlayer Alokasi (InfoPlayer X)
{
	AddressOfPlayer P = (AddressOfPlayer)malloc(sizeof(ElmtPlayer));
	if (P!=Nil)
	{
		Info(P)=X;
		Next(P)=Nil;
	}
	return P;
}

void Dealokasi(AddressOfPlayer *P)
{
	free(*P);
}

void Add (ListPlayer *L, InfoPlayer X)
{
	AddressOfPlayer P=Alokasi(X);
	if (IsLPlayerEmpty(*L))
	{
		First(*L)=P;
		Next(First(*L))=Nil;
	}
	else
	{
		AddressOfPlayer last=First(*L);
		while (last!=Nil) 
		{
			last=Next(last);
		}
		Next(last)=P;
		Next(Next(last))=Nil;
	}
}

void Del (ListPlayer *L, InfoPlayer *X, int id)
{
	AddressOfPlayer Prec, P;
    if (!IsLPlayerEmpty(*L))
    {
        if (id == Infoid(First(*L)))
        {
            P = First(*L);
            *X = Info(First(*L));
            First(*L) = Next(First(*L));
            Dealokasi(&P);
        }
        else
        {
            Prec = SearchPrec(*L,id);
            if (Infoid(Next(Prec))==id)
            {
                P = Next(Prec);
                Next(Prec) = Next(Next(Prec));
                *X=Info(P);
                Dealokasi(&P);
            }
        }
    }
}

AddressOfPlayer SearchPrec (ListPlayer L, int id)
{
	AddressOfPlayer Prec,P;
    P=First(L);
    Prec=Nil;
    if (IsLPlayerEmpty(L))
    {
        return Nil;
    }
    else
    {
        while (P!=Nil && Infoid(P)!=id)
        {
            Prec=P;
            P=Next(P);
        }
        if (Infoid(P)==id)
            return Prec;
        else
            return Nil;
    }
}

AddressOfPlayer SearchidPlayer (ListPlayer L, int id)
{
	AddressOfPlayer P;
	P=First(L);
	if (IsLPlayerEmpty(L))
	{
		return Nil;
	}
	else
	{
		while (P!=Nil && Infoid(P)!=id)
		{
			P=Next(P);
		}
		if (Infoid(P)==id)
			return P;
		else
			return Nil;
	}
}

boolean IsPenjara (InfoPlayer X)
{
	return true;
}

void MasukPenjara (ListPlayer *L, int id)
{
	
}

void KeluarPenjara (ListPlayer *L, int id)
{}

int HitungHartaPlayer (InfoPlayer X)
{
	return X.uang;
}

void AddKota (InfoPlayer *X, Kata K)
{
	AddAOK(&(*X).kota,K);
}

void DelKota (int id, Kata K)
{}

boolean IsMember (InfoPlayer X, Kata K)
{
	if (isMemberAOK(X.kota,K))
		return true;
	else
		return false;
}

