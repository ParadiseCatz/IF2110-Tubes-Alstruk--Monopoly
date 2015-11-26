#ifndef PLAYER_H
#define PLAYER_H
#include "boolean.h"
#include "arrayofint.h"
#include "arrayofkata.h"
#include <stdio.h>
#include <stdlib.h>
#include "kata.h"
#include "petak.h"
#include "defeated.h"
#include "../../globalvariable.h"

void CreateEmptyLPlayer (ListPlayer *L);
//membuat ListOfPlayer

boolean IsLPlayerEmpty (ListPlayer L);
//mengecek apakah List kosong

void PrintElmtPlayer (InfoPlayer X);
//Mencetak informasi dari suatu pemain

AddressOfPlayer Alokasi (InfoPlayer X);
//Alokasi

void Dealokasi(AddressOfPlayer *P);
//Dealokasi

void InsVLast (ListPlayer *L, InfoPlayer X);
/*Menambahkan pemain ke ListPlayer ketika awal permainan. Jumlah pemain yang diperbolehkan
	yaitu N>=1 dan N<=7
*/

void InsertFirst (ListPlayer *L, AddressOfPlayer P);
void InsertAfter (ListPlayer *L, AddressOfPlayer P, AddressOfPlayer Prec);
void InsertLast (ListPlayer *L, AddressOfPlayer P);

void Del (ListPlayer *L, InfoPlayer *X, int id);
/*Menghapus pemain dari ListPlayer ketika pemain sudah kalah dalam permainan
 */

AddressOfPlayer SearchPrec (ListPlayer L, int id);
/*Mencari Alamat sebelum alamat pemain dari ListPlayer. Pencarian dilakukan
	dengan menggunakan id player*/

AddressOfPlayer SearchidPlayer (ListPlayer L, int id);
/*Mencari Alamat pemain dari ListPlayer. Pencarian dilakukan
	dengan menggunakan id player*/

boolean IsPenjara (InfoPlayer X);
/*Mengecek apakah pemain ada di penjara atau tidak*/

void MasukPenjara (InfoPlayer *X, ListPetak L);
/*Memasukkan pemain kedalam penjara karena mendapatkan kartu chance*/

void KeluarPenjara (InfoPlayer *X);
/*Mengeluarkan pemain dari penjara karena menggunakan kartu bebas penjara*/

boolean isGetKartuPenjara (int X);
/*Mengecek apakah pemain mendapatkan kartu penjara atau tidak*/

int HitungHartaPlayer (InfoPlayer X);
/*Menghitung semua aset milik pemain (uang+kota)*/

void MajuNLangkah (InfoPlayer *X, ListPetak L, int N);
/*Mengubah posisi pemain sebanyak N langkah kedepan.*/

void LompatKe (InfoPlayer *X, AddressOfPetak Pt);
/*Mengubah posisi pemain menuju ke petak 'pt' karena berhenti di world travel*/

void AddKota (InfoPlayer *X, Kata K);
/*Menambahkan aset pemain. Kota dapat diperoleh dengan cara membeli dari bank
 atau membeli paksa dari pemain lain.*/

void DelKota (InfoPlayer *X, Kata K);
/*Menghapus aset pemain karena menjual kota ke bank maupun kota dibeli paksa oleh
 pemain lain.*/

boolean IsMember (InfoPlayer X, Kata K);
/*Mengecek apakah sebuah kota tertentu telah dimiliki oleh pemain*/

int NbElmtPlayer (ListPlayer L);
//Mengembalikan banyak pemain dalam permainan

#endif
