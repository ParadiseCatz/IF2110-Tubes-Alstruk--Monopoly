/* Nama/ NIM		:
 * Nama file		:
 * Topik		    :
 * Tanggal		    :
 * Deskripsi		:
*/

#ifndef PLAYER_H
#define PLAYER_H
#include "boolean.h"
#include "arrayofint.h"
#include "arrayofkata.h"
#include <stdio.h>
#include <stdlib.h>
#include "kata.h"
#include "petak.h"
//Konstanta
#define Nil NULL

typedef struct {
    int             id;
    int             uang;
    ArrayOfInt      idKartu;
    Kata        nama;
    ArrayOfKata kota;
    AddressOfPetak     posisi;
    boolean     penjara;
} InfoPlayer;
typedef struct TElmtListPlayer *AddressOfPlayer;

typedef struct TElmtListPlayer {
	InfoPlayer 	info;
	AddressOfPlayer 	next;
} ElmtPlayer;

typedef struct {
	AddressOfPlayer		first;
} ListPlayer;

#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info
#define Infoid(P) (P)->info.id
#define Infouang(P) (P)->info.uang

void CreateEmptyLPlayer (ListPlayer *L);
boolean IsLPlayerEmpty (ListPlayer L);
void PrintElmtPlayer (InfoPlayer X);
AddressOfPlayer Alokasi (InfoPlayer X);
void Dealokasi(AddressOfPlayer *P);
void Add (ListPlayer *L, InfoPlayer X);
void Del (ListPlayer *L, InfoPlayer *X, int id);
AddressOfPlayer SearchPrec (ListPlayer L, int id);
AddressOfPlayer SearchidPlayer (ListPlayer L, int id);
boolean IsPenjara (InfoPlayer X);
void MasukPenjara (ListPlayer *L, int id);
void KeluarPenjara (ListPlayer *L, int id);
int HitungHartaPlayer (InfoPlayer X);
void MajuNLangkah (InfoPlayer *X, int N);
void LompatKe (InfoPlayer *X, AddressOfPetak Pt);
void AddKota (InfoPlayer *X, Kata K);
void DelKota (int id, Kata X);
boolean IsMember (InfoPlayer X, Kata K);

#endif
