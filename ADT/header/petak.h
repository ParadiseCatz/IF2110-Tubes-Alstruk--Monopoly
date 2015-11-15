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
    int harga_jual; //harga jual Sale
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
#define ID_Petak(P) Info(P) -> id_petak
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

void PrintPetak(AddressOfPetak P);
// cetak info petak

void PrintBoard(ListPetak L);
// cetak kondisi board

void PrintMap();
// cetak peta board

Address SearchPetak(ListPetak L, Kata namapetak);
// output address petak

void LevelUp(AddressOfPetak *L);
// meningkatkan level bangunan pada petak



//TRANSAKSI DENGAN BANK

int HargaJualKeBank(ListPetak L, Kata namapetak);
// output harga jual ke bank

void BeliPetak(AddressOfPetak *L, AddressOfPlayer *P);
// membeli petak dari bank

void JualKeBank(AddressOfPetak *L);
// menjual petak ke bank (lepas kepemilikan, update uang pemilik)



//SEWA

int WorldCupMultiplier(AddressOfPetak P);
// mengembalikan multiplier akibat worldcup

int BlokMultiplier(AddressOfPetak P);
// mengembalikan multiplier akibat blok

int BlackoutMultiplier(AddressOfPetak P);
//mengembalikan multiplier akibat blackout

int HargaSewa(ListPetak L, Kata namapetak);
// output harga sewa total, termasuk perhitungan level

void UpdateMultiplier(AddressOfPetak *L);
// mengupdate multiplier jika ada perubahan kondisi bangunan

void BayarSewa(AddressOfPlayer *P);
// eksekusi pembayaran sewa



//BELI PAKSA

int HargaBeliPaksa(ListPetak L, Kata namapetak);
// ouput harga beli paksa

void BeliPaksa(AddressOfPlayer *current);
//Eksekusi beli paksa



//SALE

void SalePetak(AddressOfPetak *L);
// menjual petak secara offer (pasang harga offer)

void UnsalePetak(AddressOfPetak *L);
// membatalkan sale petak

void BeliSale(AddressOfPetak *L, AddressOfPlayer *P);
// membeli petak yg di-sale

void PrintSale(ListPetak L);
// mencetak daftar petak yang di sale ke layar

#endif
