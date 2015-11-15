#ifndef PETAK_H
#define PETAK_H
#include "boolean.h"
#include "kata.h"
#include <stdio.h>
#include <stdlib.h>

//Konstanta
#define Nil NULL

typedef struct
{
    Kata jenis_petak;
    int id_petak;
    Kata nama_petak;
    int biaya_sewa;
    int biaya_ambil_alih;
    int biaya_upgrade;
    int level;
    int multiplier_sewa;
    int pemilik;
    char blok;
    boolean blackout;
    int harga_jual;
} InfoPetak;

typedef struct TElmtListPetak *Address;

typedef Address AddressOfPetak;

typedef struct TElmtListPetak {
	InfoPetak 	info;
	AddressOfPetak 	next;
} ElmtPetak;

typedef struct {
	AddressOfPetak		first;
} ListPetak;

#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info
#define Jenis_Petak(P) Info(P) -> jenis_petak
#define Nama_Petak(P) Info(P) -> nama_petak
#define Biaya_Sewa(P) Info(P) -> biaya_sewa
#define Biaya_Ambil_Alih(P) Info(P) -> biaya_ambil_alih
#define Biaya_Upgrade(P) Info(P) -> biaya_upgrade
#define Level(P) Info(P) -> level
#define Multiplier_Sewa(P) Info(P) -> multiplier_sewa
#define Pemilik(P) Info(P) -> pemilik
#define Blok(P) Info(P) -> blok
#define Blackout(P) Info(P) -> blackout
#define Harga_Jual(P) Info(P) -> harga_jual

void PrintPetak(Address P);
// cetak info petak

void PrintBoard(ListPetak L);
// cetak kondisi board

void PrintMap();
// cetak peta board

int HargaSewa(ListPetak L, Kata namapetak);
// output harga sewa total, termasuk perhitungan level

int HargaJualKeBank(ListPetak L, Kata namapetak);
// output harga jual ke bank

int HargaBeliPaksa(ListPetak L, Kata namapetak);
// ouput harga beli paksa

Address SearchPetak(ListPetak L, Kata namapetak);
// output address petak

void SalePetak(AddressOfPetak *L);
// menjual petak secara offer (pasang harga offer

void JualKeBank(AddressOfPetak *L);
// menjual petak ke bank (lepas kepemilikan, update uang pemilik)

void LevelUp(AddressOfPetak *L);
// meningkatkan level bangunan pada petak

void BeliPetak(AddressOfPetak *L, AddressOfPlayer *P);
// membeli petak

void UpdateMultiplier(AddressOfPetak *L);
// mengupdate multiplier jika ada perubahan kondisi bangunan

void PrintSale(ListPetak L);
// mencetak daftar petak yang di sale ke layar
#endif
