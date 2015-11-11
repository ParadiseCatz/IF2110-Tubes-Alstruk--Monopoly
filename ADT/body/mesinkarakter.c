/* 
*	NIM/Nama 	: 13514061/Robert Sebastian Herlim
*	Nama file 	: mesinkarakter.c
*	Topik 		: Mesin Karakter & Mesin Kata
*	Tanggal 	: 25 September 2015
*	Deskripsi 	:
*/
#include "../header/mesinkarakter.h"
#include <stdio.h>

void START(char *inputFile)
/* 	I.S. sembarang
	F.S. CC adalah karakter pertama pita (stdin)
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/
{
	fp = fopen(inputFile, "r");
	CC = fgetc(fp);
}

void ADV()
/*	I.S. CC!=mark
	F.S. CC adalah karakter berikutnya yang dapat diakuisisi
		 contoh untuk pita "IF", bila CC menunjuk 'I', maka CC berikutnya adalah 'F' 
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/
{
	CC = fgetc(fp);
}

boolean EOP()
/*	true jika CC==mark */
{
	if(CC==mark)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void END()
{
	fclose(fp);
}
