/* 
*	NIM/Nama	: 13511001/Thea Olivia
*	Nama file	: Deck.h
*	Topik		: ADT Deck
*	Tanggal		: Selasa, 6 Oktober 2015
*	Deskripsi 	: Header Deck.c
*/

#ifndef CARDS_H
#define CARDS_H
#include "boolean.h"
#include "arrayofkata.h"
#include "ArrayOfCards.h"
#include "kata.h"
#include "../../globalvariable.h"
#include "player.h"
#include <stdlib.h>
#include <stdio.h>


/*
	Buatlah ADT Deck yang diimplementasikan dengan tabel kontigu dengan alokasi dinamik dalam bahasa C dengan representasi 
	alternatif III yaitu dengan HEAD dan TAIL yang “berputar”mengelilingi indeks tabel (lihat kembali diktat “Struktur Data”). 
	Jika Deck kosong, HEAD dan TAIL menunjuk indeks 0. 

	Elemen tabel efektif dimulai pada indeks ke-1,
	Dari pernyataan ini berarti elemen yang digunakan berada pada indeks dari 1..MaxEl, dan yang harus dialokasi adalah sebanyak MaxEl+1
*/

#define Nil 0
typedef int Address;

typedef struct {
	int cardID;
	Kata cardName;
	Kata cardDescription;
} InfoKartu;

typedef struct {
	InfoKartu TabCards[8];
	int Neff;
} ArrayOfCards;

//selektor
#define GetID(C) (C).cardID
#define GetName(C) (C).cardName
#define GetDesc(C) (C).cardDescription

#define GetCards(T) (T).TabCards[8]

//pemeriksaan kondisi Deck
void CreateEmptyDeck(ArrayOfCards *T);

boolean isMemberDeck(ArrayOfCards T, int K);

int SearchIdxAOI(ArrayOfCards T, int K);

void PrintAOI(ArrayOfCards T);

void AddAOI(ArrayOfCards *T, int K);

void DeleteAOI(ArrayOfCards *T, int K);

void FreeTax(InfoKartu C, AddressOfPetak *P, ArrayOfCards T);

void FreePrison(InfoKartu C, AddressOfPetak *P, ArrayOfCards T);

void GetPrison(InfoKartu C, InfoPlayer *X, ArrayOfCards T);

void GoToRandomPetak(InfoKartu C, AddressOfPetak P, ArrayOfCards T);

void GoNLangkah(InfoKartu C, ArrayOfCards T);

int Bday(InfoKartu C, InfoPlayer P);

void DoubledMove(InfoKartu C, ArrayOfCards T, AddressOfPetak P);

boolean BlackOut(InfoKartu C, AddressOfPetak P);

void ProtFromBlackOut(InfoKartu C, AddressOfPetak P);

void ReadDesc();


#endif
