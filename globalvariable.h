#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H
#include "ADT/header/boolean.h"
#include "ADT/header/kata.h"
#include "ADT/header/arrayofint.h"
#include "ADT/header/arrayofkata.h"
#include "constant.h"
#include <stdio.h>
#include <stdlib.h>

//Konstanta
typedef struct TElmtListPetak *AddressOfPetak;

typedef struct TElmtListPlayer *AddressOfPlayer;

typedef struct {
    int             id;
    int             uang;
    ArrayOfInt      idKartu;
    Kata        nama;
    ArrayOfKata kota;
    AddressOfPetak     posisi;
    boolean     penjara;
} InfoPlayer;

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

typedef struct
{
    Kata jenis_petak;
    int id_petak;
    Kata nama_petak;
    int biaya_sewa;
    int harga_dasar;
    int biaya_upgrade;
    int level;
    double multiplier_sewa;
    int pemilik;
    char blok;
    boolean blackout;
    int harga_jual; //harga jual Sale
} InfoPetak;

typedef struct TElmtListPetak {
	InfoPetak 	info;
	AddressOfPetak 	next;
} ElmtPetak;

typedef struct {
	AddressOfPetak		first;
} ListPetak;

#define FirstPetak(L) (L).first
#define NextPetak(P) (P)->next
#define InfoPetak(P) (P)->info
#define ID_Petak(P) Info(P).id_petak
#define Jenis_Petak(P) Info(P).jenis_petak
#define Nama_Petak(P) Info(P).nama_petak
#define Biaya_Sewa(P) Info(P).biaya_sewa
#define Harga_Dasar(P) Info(P).harga_dasar
#define Biaya_Upgrade(P) Info(P).biaya_upgrade
#define Level(P) Info(P).level
#define Multiplier_Sewa(P) Info(P).multiplier_sewa
#define Pemilik(P) Info(P).pemilik
#define Blok(P) Info(P).blok
#define Blackout(P) Info(P).blackout
#define Harga_Jual(P) Info(P).harga_jual

typedef int Address;

typedef struct {
    int cardID;
    Kata cardName;
    Kata cardDescription;
} InfoKartu;

typedef struct {
    InfoKartu TabCards[MAX_CARDS];
    int Neff;
} ArrayOfCards;

typedef struct {
    AddressOfPlayer     top;
} StackOfPlayer;

typedef struct {
	ListPlayer listOfPlayer;
	ListPetak listOfPetak;
	InfoPlayer *currentPlayer;
	InfoPetak *currentWorldCup;
	ArrayOfCards arrayOfCards;
	StackOfPlayer stackOfDefeated;
} GlobalVariable;

GlobalVariable global;

#endif
