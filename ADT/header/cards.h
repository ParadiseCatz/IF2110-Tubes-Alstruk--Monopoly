/* 
*	NIM/Nama	: 13511001/Thea Olivia
*	Nama file	: Deck.h
*	Topik		: ADT Deck
*	Tanggal		: Selasa, 6 Oktober 2015
*	Deskripsi 	: Header Deck.c
*/

#ifndef CARDS_H
#define CARDS_H
#include "../header/boolean.h"
#include "../header/arrayofkata.h"
#include "../header/arrayofint.h"
#include "../header/kata.h"
#include "../header/player.h"
#include <stdlib.h>
#include <stdio.h>


/*
	Buatlah ADT Deck yang diimplementasikan dengan tabel kontigu dengan alokasi dinamik dalam bahasa C dengan representasi 
	alternatif III yaitu dengan HEAD dan TAIL yang “berputar”mengelilingi indeks tabel (lihat kembali diktat “Struktur Data”). 
	Jika Deck kosong, HEAD dan TAIL menunjuk indeks 0. 

	Elemen tabel efektif dimulai pada indeks ke-1,
	Dari pernyataan ini berarti elemen yang digunakan berada pada indeks dari 1..MaxEl, dan yang harus dialokasi adalah sebanyak MaxEl+1
*/

#ifndef Nil
#define Nil 0
#endif

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
