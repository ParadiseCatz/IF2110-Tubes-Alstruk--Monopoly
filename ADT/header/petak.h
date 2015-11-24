#ifndef PETAK_H
#define PETAK_H
#include "boolean.h"
#include "kata.h"

#include <stdio.h>
#include <stdlib.h>

//Konstanta
#ifndef Nil
#define Nil 0
#endif
#include "player.h"
typedef struct
{
    Kata jenis_petak;
    int id_petak;
    Kata nama_petak;
    int biaya_sewa;
    int biaya_ambil_alih;
    int biaya_upgrade;
    int level;
    double multiplier_sewa;
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
#define FirstPetak(L) (L).first
#define NextPetak(P) (P)->next
#define InfoPetak(P) (P)->info
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



void PrintBoard();
// cetak kondisi board

void PrintMap();
// cetak peta board

// PENGLOLAAN LIST PETAK

void CreateListPetak(ListPetak *L);
// Membuat list petak kosong

void AddLastPetak(ListPetak *L, AddressOfPetak P);
// Memasukkan P pada list petak (harus alokasi dulu

AddressOfPetak AlokasiPetak(InfoPetak P);
// menghasilkan address hasil alokasi P

AddressOfPetak SearchPetak(ListPetak L, Kata namapetak);
// output address petak

AddressOfPetak SearchPetakByID(ListPetak L, int id);
// output address petak

// PREDIKAT

boolean isKota(AddressOfPetak P);
// mengembalikan true jika p merupakan petak kota

boolean isTempatWisata(AddressOfPetak P);
// mengembalikan true jika p merupakan petak tempat wisata

// LEVEL UP BANGUNAN

void UpdateMultiplier(AddressOfPetak *L);
// mengupdate multiplier jika ada perubahan kondisi bangunan

//TRANSAKSI DENGAN BANK

int HargaJualKeBank(Kata namapetak);
// output harga jual ke bank

void BeliPetak();
// membeli petak dari bank

//SEWA

int WorldCupMultiplier();
// mengembalikan multiplier akibat worldcup

int BlokMultiplier();
// mengembalikan multiplier akibat blok

int BlackoutMultiplier();
//mengembalikan multiplier akibat blackout

int HargaSewa();
// output harga sewa total, termasuk perhitungan level

//BELI PAKSA

int HargaBeliPaksa();
// ouput harga beli paksa

void BeliPaksa();
//Eksekusi beli paksa

/////////////////////////////////////////////////////NON-COMMAND INSTRUCTION/////////////////////////////////////////////////////


//=====================================================================================sewa

void BayarSewa();
// eksekusi pembayaran sewa

//======================================================================================tax

void PayTax();
//Membayar uang tax

//====================================================================================bonus

void GetBonus();
// Memberikan bonus pada player yang mendarat di petak bonus

//====================================================================================start

void ExecuteStart();
//Mengeksekusi apa yang harus dilakukan jika berhenti/melewati petak start

///////////////////////////////////////////////////////COMMAND INSTRUCTION///////////////////////////////////////////////////////

//========================================================================info <nama petak>

void PrintPetak(Kata namapetak);
// cetak info petak

//======================================================================================buy

void Buy();
//membeli petak yang ditempati

//========================================================================sell <nama petak>

void SalePetak(Kata namapetak);
// menjual petak secara offer (pasang harga offer)

//======================================================================unsell <nama petak>

void UnsalePetak(Kata namapetak);
// membatalkan sale petak

//===================================================================sell bank <nama petak>

void JualKeBank(Kata namapetak);
// menjual petak ke bank (lepas kepemilikan, update uang pemilik)

//=============================================================================show offered

void PrintSale();
// mencetak daftar petak yang di sale ke layar

//==============================================================================buy offered

void BeliSale(Kata namapetak);
// membeli petak yg di-sale

//==================================================================================upgrade

void LevelUp();
// meningkatkan level bangunan pada petak

//====================================================================================board

  //Bagiannya Resa

//=========================================================================host <nama kota>

void AppointWorldCup(Kata namapetak);
// Menunjuk petak worldcup

//======================================================================travel <nama petak>

void WorldTravel(Kata namapetak);
//Berpindah ke petak tujuan worldtravel

#endif
