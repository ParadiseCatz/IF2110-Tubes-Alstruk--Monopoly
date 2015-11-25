/* 
*	NIM/Nama	: 13511001/Thea Olivia
*	Nama file	: Deck.h
*	Topik		: ADT Deck
*	Tanggal		: Selasa, 6 Oktober 2015
*	Deskripsi 	: Header Deck.c
*/

#ifndef CARDS_H
#define CARDS_H
#include "ADT/header/boolean.h"
#include "ADT/header/arrayofkata.h"
#include "ADT/header/arrayofint.h"
#include "ADT/header/kata.h"
#include "../../globalvariable.h"
#include "ADT/header/player.h"
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
	InfoKartu TabCards[MaxCards];
	int Neff;
} ArrayOfCards;

//selektor
#define GetID(C) (C).cardID
#define GetName(C) (C).cardName
#define GetDesc(C) (C).cardDescription

#define GetNeff(Card) (Card).Neff

#define gift 100000
#define MaxCards 8

void DrawCards();

void PrintCard (InfoKartu C);
/* print id, judul dan deskripsi */


// METHOD UNTUK JENIS CHANCE CARD
void FreeTax();

void FreePrison();

void GetPrison();

void MajuRandLangkah();

void Bday();

void DoubledMove();

void BlackOut();

void ProtFromBlackOut();


#endif
