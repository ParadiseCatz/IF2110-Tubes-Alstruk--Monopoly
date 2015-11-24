
#ifndef PETAK_H
#define PETAK_H
#include "../../globalvariable.h"

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
