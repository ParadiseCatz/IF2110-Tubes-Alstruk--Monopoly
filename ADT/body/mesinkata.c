/* 
*	NIM/Nama 	: 13514061/Robert Sebastian Herlim
*	Nama file 	: mesinkata.c
*	Topik 		: Mesin Karakter & Mesin Kata
*	Tanggal 	: 25 September 2015
*	Deskripsi 	:
*/
#include <stdio.h>
#include "../header/mesinkata.h"

/* Primitif-primitif mesin kata */
void Ignore_Blank()
/*	Mengabaikan satu atau beberapa BLANK
	I.S. : CC sembarang
	F.S. : CC != BLANK atau CC == MARK
*/
{
	while(CC==blank || CC==newline)
	{
		ADV();
	}// CC != Blank && CC != newline
}	

void STARTKATA(char *inputFile)
/*	I.S. : CC sembarang
	F.S  : Salah satu dari dua kondisi dibawah.
		1. EndKata = true dan CC == Mark
		2. EndKata = false, CKata adalah kata yang sudah diakuisisi, dan CC adalah satu karakter setelah karakter terakhir kata

		Keterangan: CC mengacu pada yang disebut pada mesinkarakter
*/
{
	START(inputFile);
	Ignore_Blank();
	if(CC==mark)
	{
		EndKata = true;
		END();
	}
	else
	{
		EndKata = false;
		SalinKata();
	}
}

void ADVKATA()
/*	I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
	dari kata yg sudah diakuisisi
	F.S. : Jika CC == MARK, maka EndKata == true
	atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
	CC karakter pertama sesudah karakter terakhir kata
*/
{
	Ignore_Blank();
	if(CC==mark)
	{
		EndKata = true;
	}
	else
	{
		//EndKata = false;
		SalinKata();
	}
}

void SalinKata()
/*	Mengakuisisi kata, menyimpan dalam CKata
	I.S. : CC adalah karakter pertama dari kata
	F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
	NMax, sisa "kata" dibuang; CC == BLANK atau CC == MARK; CC adalah
	karakter sesudah karakter terakhir yang diakuisisi
*/
{
	// Kamus Lokal
	int i;

	// Algoritma
	i = 0;
	do
	{
		CKata.TabKata[i] = CC;
		ADV(); i++;
	} while(CC!=mark && CC!=blank && CC!=newline);

	CKata.Length = i;

	if(CC == mark) EndKata = true;
}


