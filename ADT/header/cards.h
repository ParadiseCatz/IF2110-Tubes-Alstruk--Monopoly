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
typedef int Address;

typedef struct {
	int cardID;
	Kata cardName;
	Kata cardDescription;
} InfoKartu;

typedef struct Deck *Hand;

#include "../../globalvariable.h"
//selektor
#define GetTail(Q) (Q).tail
#define	GetMax(Q) (Q).maxCard
#define GetHead(Q) (Q).head
#define GetCard(Q) (Q).card
#define	InfoHead(Q) (Q).T[GetHead(Q)]
#define	InfoTail(Q) (Q).T[GetTail(Q)]

#define GetID(C) (C).cardID
#define GetName(C) (C).cardName
#define GetDesc(C) (C).cardDescription

//pemeriksaan kondisi Deck
boolean IsEmpty(Deck Q);
/*	Mengirim true jika Q kosong yaitu HEAD dan TAIL sama dengan nil */

boolean IsFull(Deck Q);
/*	Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung MaxEl elemen */

int NbElmt(Deck Q);
/*	Mengirimkan banyaknya elemen Deck. Mengirimkan 0 jika Q kosong. */


//konstruktor
void CreateEmpty(Deck *Q, int max);
/*	I.S. Max terdefinisi
	F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb :
	Jika alokasi berhasil, tabel memori dialokasi berukuran Max
	atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0
	Proses : Melakukan alokasi memori dan membuat sebuah Q kosong
*/

//destruktor
void Dealokasi(Deck *Q);
/*	Proses : Mengembalikan memori Q
	I.S. Q pernah dialokasi
	F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) juga diset 0
		Head dan Tail diset menjadi Nil
		Jangan lupa untuk membebaskan (free) memori yang telah dialokasikan untuk tabel
*/
typedef struct {
	InfoKartu TabCards[MaxCards];
	int Neff;
} ArrayOfCards;

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
