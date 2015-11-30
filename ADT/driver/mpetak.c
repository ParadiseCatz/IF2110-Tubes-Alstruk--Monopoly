#include"../Header/petak.h"
#include"../Header/kata.h"
#include"../Header/cards.h"
#include"../Header/player.h"
#include"../Header/arrayofkata.h"
#include"../Header/arrayofint.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int opt;
    InfoPetak P;
    InfoPlayer PP;
    Kata Beijing, Jakarta, Taipei, New_Delhi, Seoul, Hawai, Tokyo, Sydney, Singapura, Sao_Paolo, Denmark, Berlin, Geneva, Moscow, Rome, London, Paris, New_York, Bangkok;
    Kata Ancol, Senggigi, Bintan, Kuta;
    Kata Kota, Tempat_Wisata, Chance, Start, Bonus, World_Travel, Deserted_Island, World_Cup, Tax;
    Kata errorword;

    errorword.TabKata[0] = '7';
    errorword.TabKata[1] = '6';
    errorword.TabKata[2] = '0';
    errorword.TabKata[3] = '2';
    errorword.Length = 4;

    {
        CreateListPetak(&global.listOfPetak);

        Beijing.TabKata[0] = 'B';
        Beijing.TabKata[1] = 'e';
        Beijing.TabKata[2] = 'i';
        Beijing.TabKata[3] = 'j';
        Beijing.TabKata[4] = 'i';
        Beijing.TabKata[5] = 'n';
        Beijing.TabKata[6] = 'g';
        Beijing.Length = 7;

        Jakarta.TabKata[0] = 'J';
        Jakarta.TabKata[1] = 'a';
        Jakarta.TabKata[2] = 'k';
        Jakarta.TabKata[3] = 'a';
        Jakarta.TabKata[4] = 'r';
        Jakarta.TabKata[5] = 't';
        Jakarta.TabKata[6] = 'a';
        Jakarta.Length = 7;

        Taipei.TabKata[0] = 'T';
        Taipei.TabKata[1] = 'a';
        Taipei.TabKata[2] = 'i';
        Taipei.TabKata[3] = 'p';
        Taipei.TabKata[4] = 'e';
        Taipei.TabKata[5] = 'i';
        Taipei.Length = 6;

        New_Delhi.TabKata[0] = 'N';
        New_Delhi.TabKata[1] = 'e';
        New_Delhi.TabKata[2] = 'w';
        New_Delhi.TabKata[3] = '_';
        New_Delhi.TabKata[4] = 'D';
        New_Delhi.TabKata[5] = 'e';
        New_Delhi.TabKata[6] = 'l';
        New_Delhi.TabKata[7] = 'h';
        New_Delhi.TabKata[8] = 'i';
        New_Delhi.Length = 9;

        Seoul.TabKata[0] = 'S';
        Seoul.TabKata[1] = 'e';
        Seoul.TabKata[2] = 'o';
        Seoul.TabKata[3] = 'u';
        Seoul.TabKata[4] = 'l';
        Seoul.Length = 5;

        Hawai.TabKata[0] = 'H';
        Hawai.TabKata[1] = 'a';
        Hawai.TabKata[2] = 'w';
        Hawai.TabKata[3] = 'a';
        Hawai.TabKata[4] = 'i';
        Hawai.Length = 5;

        Tokyo.TabKata[0] = 'T';
        Tokyo.TabKata[1] = 'o';
        Tokyo.TabKata[2] = 'k';
        Tokyo.TabKata[3] = 'y';
        Tokyo.TabKata[4] = 'o';
        Tokyo.Length = 5;

        Sydney.TabKata[0] = 'S';
        Sydney.TabKata[1] = 'y';
        Sydney.TabKata[2] = 'd';
        Sydney.TabKata[3] = 'n';
        Sydney.TabKata[4] = 'e';
        Sydney.TabKata[5] = 'y';
        Sydney.Length = 6;

        Singapura.TabKata[0] = 'S';
        Singapura.TabKata[1] = 'i';
        Singapura.TabKata[2] = 'n';
        Singapura.TabKata[3] = 'g';
        Singapura.TabKata[4] = 'a';
        Singapura.TabKata[5] = 'p';
        Singapura.TabKata[6] = 'u';
        Singapura.TabKata[7] = 'r';
        Singapura.TabKata[8] = 'a';
        Singapura.Length = 9;

        Sao_Paolo.TabKata[0] = 'S';
        Sao_Paolo.TabKata[0] = 'a';
        Sao_Paolo.TabKata[0] = 'o';
        Sao_Paolo.TabKata[0] = '_';
        Sao_Paolo.TabKata[0] = 'P';
        Sao_Paolo.TabKata[0] = 'a';
        Sao_Paolo.TabKata[0] = 'o';
        Sao_Paolo.TabKata[0] = 'l';
        Sao_Paolo.TabKata[0] = 'o';
        Sao_Paolo.Length = 9;

        Denmark.TabKata[0] = 'D';
        Denmark.TabKata[1] = 'e';
        Denmark.TabKata[2] = 'n';
        Denmark.TabKata[3] = 'm';
        Denmark.TabKata[4] = 'a';
        Denmark.TabKata[5] = 'r';
        Denmark.TabKata[6] = 'k';
        Denmark.Length = 7;

        Berlin.TabKata[0] = 'B';
        Berlin.TabKata[1] = 'e';
        Berlin.TabKata[2] = 'r';
        Berlin.TabKata[3] = 'l';
        Berlin.TabKata[4] = 'i';
        Berlin.TabKata[5] = 'n';
        Berlin.Length = 6;

        Geneva.TabKata[0] = 'G';
        Geneva.TabKata[1] = 'e';
        Geneva.TabKata[2] = 'n';
        Geneva.TabKata[3] = 'e';
        Geneva.TabKata[4] = 'v';
        Geneva.TabKata[5] = 'a';
        Geneva.Length = 6;

        Moscow.TabKata[0] = 'M';
        Moscow.TabKata[1] = 'o';
        Moscow.TabKata[2] = 's';
        Moscow.TabKata[3] = 'c';
        Moscow.TabKata[4] = 'o';
        Moscow.TabKata[5] = 'w';
        Moscow.Length = 6;

        Rome.TabKata[0] = 'R';
        Rome.TabKata[1] = 'o';
        Rome.TabKata[2] = 'm';
        Rome.TabKata[3] = 'e';
        Rome.Length = 4;

        London.TabKata[0] = 'L';
        London.TabKata[1] = 'o';
        London.TabKata[2] = 'n';
        London.TabKata[3] = 'd';
        London.TabKata[4] = 'o';
        London.TabKata[5] = 'n';
        London.Length = 6;

        Paris.TabKata[0] = 'P';
        Paris.TabKata[1] = 'a';
        Paris.TabKata[2] = 'r';
        Paris.TabKata[3] = 'i';
        Paris.TabKata[4] = 's';
        Paris.Length = 5;

        New_York.TabKata[0] = 'N';
        New_York.TabKata[1] = 'e';
        New_York.TabKata[2] = 'w';
        New_York.TabKata[3] = '_';
        New_York.TabKata[4] = 'Y';
        New_York.TabKata[5] = 'o';
        New_York.TabKata[6] = 'r';
        New_York.TabKata[7] = 'k';
        New_York.Length = 8;

        Bangkok.TabKata[0] = 'B';
        Bangkok.TabKata[1] = 'a';
        Bangkok.TabKata[2] = 'n';
        Bangkok.TabKata[3] = 'g';
        Bangkok.TabKata[4] = 'k';
        Bangkok.TabKata[5] = 'o';
        Bangkok.TabKata[6] = 'k';
        Bangkok.Length = 7;

        Ancol.TabKata[0] = 'A';
        Ancol.TabKata[1] = 'n';
        Ancol.TabKata[2] = 'c';
        Ancol.TabKata[3] = 'o';
        Ancol.TabKata[4] = 'l';
        Ancol.Length = 5;

        Senggigi.TabKata[0] = 'S';
        Senggigi.TabKata[1] = 'e';
        Senggigi.TabKata[2] = 'n';
        Senggigi.TabKata[3] = 'g';
        Senggigi.TabKata[4] = 'g';
        Senggigi.TabKata[5] = 'i';
        Senggigi.TabKata[6] = 'g';
        Senggigi.TabKata[7] = 'i';
        Senggigi.Length = 8;

        Bintan.TabKata[0] = 'B';
        Bintan.TabKata[1] = 'i';
        Bintan.TabKata[2] = 'n';
        Bintan.TabKata[3] = 't';
        Bintan.TabKata[4] = 'a';
        Bintan.TabKata[5] = 'n';
        Bintan.Length = 6;

        Kuta.TabKata[0] = 'K';
        Kuta.TabKata[1] = 'u';
        Kuta.TabKata[2] = 't';
        Kuta.TabKata[3] = 'a';
        Kuta.Length = 4;

        Kota.TabKata[0] = 'K';
        Kota.TabKata[1] = 'o';
        Kota.TabKata[2] = 't';
        Kota.TabKata[3] = 'a';
        Kota.Length = 4;

        Tempat_Wisata.TabKata[0] = 'T';
        Tempat_Wisata.TabKata[1] = 'e';
        Tempat_Wisata.TabKata[2] = 'm';
        Tempat_Wisata.TabKata[3] = 'p';
        Tempat_Wisata.TabKata[4] = 'a';
        Tempat_Wisata.TabKata[5] = 't';
        Tempat_Wisata.TabKata[6] = '_';
        Tempat_Wisata.TabKata[7] = 'W';
        Tempat_Wisata.TabKata[8] = 'i';
        Tempat_Wisata.TabKata[9] = 's';
        Tempat_Wisata.TabKata[10] = 'a';
        Tempat_Wisata.TabKata[11] = 't';
        Tempat_Wisata.TabKata[12] = 'a';
        Tempat_Wisata.Length = 13;

        Chance.TabKata[0] = 'C';
        Chance.TabKata[0] = 'h';
        Chance.TabKata[0] = 'a';
        Chance.TabKata[0] = 'n';
        Chance.TabKata[0] = 'c';
        Chance.TabKata[0] = 'e';
        Chance.Length = 6;

        Start.TabKata[0] = 'S';
        Start.TabKata[1] = 't';
        Start.TabKata[2] = 'a';
        Start.TabKata[3] = 'r';
        Start.TabKata[4] = 't';
        Start.Length = 5;

        Bonus.TabKata[0] = 'B';
        Bonus.TabKata[1] = 'o';
        Bonus.TabKata[2] = 'n';
        Bonus.TabKata[3] = 'u';
        Bonus.TabKata[4] = 's';
        Bonus.Length = 5;

        World_Travel.TabKata[0] = 'W';
        World_Travel.TabKata[1] = 'o';
        World_Travel.TabKata[2] = 'r';
        World_Travel.TabKata[3] = 'l';
        World_Travel.TabKata[4] = 'd';
        World_Travel.TabKata[5] = '_';
        World_Travel.TabKata[6] = 'T';
        World_Travel.TabKata[7] = 'r';
        World_Travel.TabKata[8] = 'a';
        World_Travel.TabKata[9] = 'v';
        World_Travel.TabKata[10] = 'e';
        World_Travel.TabKata[11] = 'l';
        World_Travel.Length = 12;

        Deserted_Island.TabKata[0] = 'D';
        Deserted_Island.TabKata[1] = 'e';
        Deserted_Island.TabKata[2] = 's';
        Deserted_Island.TabKata[3] = 'e';
        Deserted_Island.TabKata[4] = 'r';
        Deserted_Island.TabKata[5] = 't';
        Deserted_Island.TabKata[6] = 'e';
        Deserted_Island.TabKata[7] = 'd';
        Deserted_Island.TabKata[8] = '_';
        Deserted_Island.TabKata[9] = 'I';
        Deserted_Island.TabKata[10] = 's';
        Deserted_Island.TabKata[11] = 'l';
        Deserted_Island.TabKata[12] = 'a';
        Deserted_Island.TabKata[13] = 'n';
        Deserted_Island.TabKata[14] = 'd';
        Deserted_Island.Length = 15;

        World_Cup.TabKata[0] = 'W';
        World_Cup.TabKata[1] = 'o';
        World_Cup.TabKata[2] = 'r';
        World_Cup.TabKata[3] = 'l';
        World_Cup.TabKata[4] = 'd';
        World_Cup.TabKata[5] = '_';
        World_Cup.TabKata[6] = 'C';
        World_Cup.TabKata[7] = 'u';
        World_Cup.TabKata[8] = 'p';
        World_Cup.Length = 9;

        Tax.TabKata[0] = 'T';
        Tax.TabKata[1] = 'a';
        Tax.TabKata[2] = 'x';
        Tax.Length = 3;

        CreateListPetak(&(global.listOfPetak));

        P.jenis_petak = Start;
        P.id_petak = 1;
        P.nama_petak = Start;
        P.biaya_sewa = -1;
        P.harga_dasar = -1;
        P.biaya_upgrade = -1;
        P.level = -1;
        P.multiplier_sewa = -1;
        P.pemilik = 0;
        P.blok = '-';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 2;
        P.nama_petak = Beijing;
        P.biaya_sewa = 12000;
        P.harga_dasar = 120000;
        P.biaya_upgrade = 120000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'A';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Bonus;
        P.id_petak = 3;
        P.nama_petak = Bonus;
        P.biaya_sewa = -1;
        P.harga_dasar = -1;
        P.biaya_upgrade = -1;
        P.level = -1;
        P.multiplier_sewa = -1;
        P.pemilik = 0;
        P.blok = '-';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 4;
        P.nama_petak = Jakarta;
        P.biaya_sewa = 10000;
        P.harga_dasar = 100000;
        P.biaya_upgrade = 100000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'A';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Tempat_Wisata;
        P.id_petak = 5;
        P.nama_petak = Ancol;
        P.biaya_sewa = 16000;
        P.harga_dasar = 160000;
        P.biaya_upgrade = 160000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'T';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 6;
        P.nama_petak = Taipei;
        P.biaya_sewa = 9000;
        P.harga_dasar = 90000;
        P.biaya_upgrade = 90000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'B';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 7;
        P.nama_petak = New_Delhi;
        P.biaya_sewa = 10000;
        P.harga_dasar = 100000;
        P.biaya_upgrade = 100000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'B';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 8;
        P.nama_petak = Seoul;
        P.biaya_sewa = 15000;
        P.harga_dasar = 150000;
        P.biaya_upgrade = 150000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'B';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Deserted_Island;
        P.id_petak = 9;
        P.nama_petak = Deserted_Island;
        P.biaya_sewa = -1;
        P.harga_dasar = -1;
        P.biaya_upgrade = -1;
        P.level = -1;
        P.multiplier_sewa = -1;
        P.pemilik = 0;
        P.blok = '-';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 10;
        P.nama_petak = Hawai;
        P.biaya_sewa = 20000;
        P.harga_dasar = 200000;
        P.biaya_upgrade = 200000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'C';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 11;
        P.nama_petak = Tokyo;
        P.biaya_sewa = 20000;
        P.harga_dasar = 200000;
        P.biaya_upgrade = 200000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'C';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 12;
        P.nama_petak = Sydney;
        P.biaya_sewa = 20000;
        P.harga_dasar = 200000;
        P.biaya_upgrade = 200000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'C';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Chance;
        P.id_petak = 13;
        P.nama_petak = Chance;
        P.biaya_sewa = -1;
        P.harga_dasar = -1;
        P.biaya_upgrade = -1;
        P.level = -1;
        P.multiplier_sewa = -1;
        P.pemilik = 0;
        P.blok = '-';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 14;
        P.nama_petak = Singapura;
        P.biaya_sewa = 10000;
        P.harga_dasar = 100000;
        P.biaya_upgrade = 100000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'D';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Tempat_Wisata;
        P.id_petak = 15;
        P.nama_petak = Senggigi;
        P.biaya_sewa = 16000;
        P.harga_dasar = 160000;
        P.biaya_upgrade = 160000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'T';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 16;
        P.nama_petak = Sao_Paolo;
        P.biaya_sewa = 20000;
        P.harga_dasar = 200000;
        P.biaya_upgrade = 200000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'D';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = World_Cup;
        P.id_petak = 17;
        P.nama_petak = World_Cup;
        P.biaya_sewa = -1;
        P.harga_dasar = -1;
        P.biaya_upgrade = -1;
        P.level = -1;
        P.multiplier_sewa = -1;
        P.pemilik = 0;
        P.blok = '-';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 18;
        P.nama_petak = Denmark;
        P.biaya_sewa = 20000;
        P.harga_dasar = 200000;
        P.biaya_upgrade = 200000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'E';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Tempat_Wisata;
        P.id_petak = 19;
        P.nama_petak = Bintan;
        P.biaya_sewa = 15000;
        P.harga_dasar = 150000;
        P.biaya_upgrade = 150000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'T';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 20;
        P.nama_petak = Berlin;
        P.biaya_sewa = 22000;
        P.harga_dasar = 220000;
        P.biaya_upgrade = 220000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'E';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Chance;
        P.id_petak = 21;
        P.nama_petak = Chance;
        P.biaya_sewa = -1;
        P.harga_dasar = -1;
        P.biaya_upgrade = -1;
        P.level = -1;
        P.multiplier_sewa = -1;
        P.pemilik = 0;
        P.blok = '-';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 22;
        P.nama_petak = Geneva;
        P.biaya_sewa = 15000;
        P.harga_dasar = 150000;
        P.biaya_upgrade = 150000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'F';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 23;
        P.nama_petak = Moscow;
        P.biaya_sewa = 15000;
        P.harga_dasar = 150000;
        P.biaya_upgrade = 150000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'F';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 24;
        P.nama_petak = Rome;
        P.biaya_sewa = 20000;
        P.harga_dasar = 200000;
        P.biaya_upgrade = 200000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'F';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = World_Travel;
        P.id_petak = 25;
        P.nama_petak = World_Travel;
        P.biaya_sewa = -1;
        P.harga_dasar = -1;
        P.biaya_upgrade = -1;
        P.level = -1;
        P.multiplier_sewa = -1;
        P.pemilik = 0;
        P.blok = '-';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Tempat_Wisata;
        P.id_petak = 26;
        P.nama_petak = Kuta;
        P.biaya_sewa = 20000;
        P.harga_dasar = 200000;
        P.biaya_upgrade = 200000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'T';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 27;
        P.nama_petak = London;
        P.biaya_sewa = 21000;
        P.harga_dasar = 210000;
        P.biaya_upgrade = 210000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'G';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 28;
        P.nama_petak = Paris;
        P.biaya_sewa = 19000;
        P.harga_dasar = 190000;
        P.biaya_upgrade = 190000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'G';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Chance;
        P.id_petak = 29;
        P.nama_petak = Chance;
        P.biaya_sewa = -1;
        P.harga_dasar = -1;
        P.biaya_upgrade = -1;
        P.level = -1;
        P.multiplier_sewa = -1;
        P.pemilik = 0;
        P.blok = '-';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 30;
        P.nama_petak = New_York;
        P.biaya_sewa = 30000;
        P.harga_dasar = 300000;
        P.biaya_upgrade = 300000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'H';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Tax;
        P.id_petak = 31;
        P.nama_petak = Tax;
        P.biaya_sewa = -1;
        P.harga_dasar = -1;
        P.biaya_upgrade = -1;
        P.level = -1;
        P.multiplier_sewa = -1;
        P.pemilik = 0;
        P.blok = '-';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));

        P.jenis_petak = Kota;
        P.id_petak = 32;
        P.nama_petak = Bangkok;
        P.biaya_sewa = 20000;
        P.harga_dasar = 200000;
        P.biaya_upgrade = 200000;
        P.level = 1;
        P.multiplier_sewa = 1;
        P.pemilik = 0;
        P.blok = 'H';
        P.blackout = false;
        P.harga_jual = -1;
        AddLastPetak(&(global.listOfPetak), AlokasiPetak(P));
   }

    {
        CreateEmptyLPlayer(&global.listOfPlayer);

        PP.id = 1;
        PP.posisi = FirstPetak(global.listOfPetak);
        PP.nama.TabKata[0] = 'A';
        PP.nama.Length = 1;
        PP.uang = 2000000;
        PP.penjara = false;
        CreateEmptyAOK(&PP.kota);
        CreateEmptyAOI(&PP.idKartu);
        InsVLast(&global.listOfPlayer, PP);

        PP.id = 2;
        PP.posisi = FirstPetak(global.listOfPetak);
        PP.nama.TabKata[0] = 'B';
        PP.nama.Length = 1;
        PP.uang = 0;
        PP.penjara = false;
        CreateEmptyAOK(&PP.kota);
        CreateEmptyAOI(&PP.idKartu);
        InsVLast(&global.listOfPlayer, PP);

        PP.id = 3;
        PP.posisi = FirstPetak(global.listOfPetak);
        PP.nama.TabKata[0] = 'C';
        PP.nama.Length = 1;
        PP.uang = 2000000;
        PP.penjara = true;
        CreateEmptyAOK(&PP.kota);
        CreateEmptyAOI(&PP.idKartu);
        InsVLast(&global.listOfPlayer, PP);

    }

    do
    {
        printf("\n");
        printf("Menu\n");
        printf("\n");
        printf("\t0.  Exit\n");
        printf("\t1.  BayarSewa\n");
        printf("\t2.  PayTax\n");
        printf("\t3.  GetBonus\n");
        printf("\t4.  ExecuteStart\n");
        printf("\t5.  PrintPetak\n");
        printf("\t6.  Buy\n");
        printf("\t7.  SalePetak\n");
        printf("\t8.  UnsalePetak\n");
        printf("\t9.  JualKeBank\n");
        printf("\t10. PrintSale\n");
        printf("\t11. BeliSale\n");
        printf("\t12. LevelUp\n");
        printf("\t13. PrintBoard\n");
        printf("\t14. AppointWorldCup\n");
        printf("\t15. WorldTravel\n");
        printf("\n");
        do
        {
            printf("input : ");
            scanf("%d", &opt);
            printf("\n");
            if (opt > 16 || opt < 0)
            {
                printf("Invalid input\n\n");
            }
        } while (opt > 16 || opt < 0);
        printf("\n");

        switch (opt)
        {
            case 1  :
                        {
                            printf("\nCurrent Player A\n");
                            printf("Posisi Paris\n");

                            global.currentPlayer = SearchidPlayer(global.listOfPlayer, 1);
                            (*global.currentPlayer).info.posisi = SearchPetak(global.listOfPetak,Paris);

                            printf("\nA di petak milik bank\n");
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));
                            (*(*global.currentPlayer).info.posisi).info.pemilik = 0;
                            BayarSewa();
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));

                            printf("\nA di petak milik sendiri\n");
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));
                            (*(*global.currentPlayer).info.posisi).info.pemilik = 1;
                            BayarSewa();
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));

                            printf("\nA di petak milik B, Level 1, tidak blok penuh, tidak mati lampu, tidak world cup\n");
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));
                            printf("Uang awal B : %i\n", Infouang(SearchidPlayer(global.listOfPlayer, 2)));
                            (*(*global.currentPlayer).info.posisi).info.pemilik = 2;
                            BayarSewa();
                            printf("Uang akhir A : %i\n", Infouang(global.currentPlayer));
                            printf("Uang akhir B : %i\n", Infouang(SearchidPlayer(global.listOfPlayer, 2)));
                            Infouang(SearchidPlayer(global.listOfPlayer, 1)) = 2000000;
                            Infouang(SearchidPlayer(global.listOfPlayer, 2)) = 0;

                            printf("\nA di petak milik B, Level 3, blok penuh, tidak mati lampu, tidak world cup\n");
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));
                            printf("Uang awal B : %i\n", Infouang(SearchidPlayer(global.listOfPlayer, 2)));
                            Level((*global.currentPlayer).info.posisi) = 3;
                            Multiplier_Sewa((*global.currentPlayer).info.posisi) = 2;
                            Pemilik(SearchPetak(global.listOfPetak, London)) = 2;
                            BayarSewa();
                            printf("Uang akhir A : %i\n", Infouang(global.currentPlayer));
                            printf("Uang akhir B : %i\n", Infouang(SearchidPlayer(global.listOfPlayer, 2)));
                            Infouang(SearchidPlayer(global.listOfPlayer, 1)) = 2000000;
                            Infouang(SearchidPlayer(global.listOfPlayer, 2)) = 0;

                            printf("\nA di petak milik B, Level 3, blok penuh, mati lampu, tidak world cup\n");
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));
                            printf("Uang awal B : %i\n", Infouang(SearchidPlayer(global.listOfPlayer, 2)));
                            Blackout((*global.currentPlayer).info.posisi) = true;
                            BayarSewa();
                            printf("Uang akhir A : %i\n", Infouang(global.currentPlayer));
                            printf("Uang akhir B : %i\n", Infouang(SearchidPlayer(global.listOfPlayer, 2)));

                            printf("\nA di petak milik B, Level 3, blok penuh, tidak mati lampu, world cup\n");
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));
                            printf("Uang awal B : %i\n", Infouang(SearchidPlayer(global.listOfPlayer, 2)));
                            Blackout((*global.currentPlayer).info.posisi) = false;
                            global.currentWorldCup = SearchPetak(global.listOfPetak, Paris);
                            BayarSewa();
                            printf("Uang akhir A : %i\n", Infouang(global.currentPlayer));
                            printf("Uang akhir B : %i\n", Infouang(SearchidPlayer(global.listOfPlayer, 2)));


                            (*(*global.currentPlayer).info.posisi).info.pemilik = 0;
                            Multiplier_Sewa((*global.currentPlayer).info.posisi) = 1;
                            Pemilik(SearchPetak(global.listOfPetak, London)) = 0;
                            Infouang(SearchidPlayer(global.listOfPlayer, 1)) = 2000000;
                            Infouang(SearchidPlayer(global.listOfPlayer, 2)) = 0;
                            (*global.currentPlayer).info.posisi = FirstPetak(global.listOfPetak);

                            break;
                        }
            case 2  :
                        {
                            printf("\nCurrent Player A\n");
                            global.currentPlayer = SearchidPlayer(global.listOfPlayer, 1);

                            printf("\nAset : Taipei lv 1, New Delhi lv 3, Senggigi\n");
                            printf("Tidak ada kartu free tax\n");
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));
                            AddAOK(&(*global.currentPlayer).info.kota, Taipei);
                            AddAOK(&(*global.currentPlayer).info.kota, New_Delhi);
                            Level(SearchPetak(global.listOfPetak, New_Delhi)) = 3;
                            AddAOK(&(*global.currentPlayer).info.kota, Senggigi);
                            PayTax();
                            printf("Uang akhir A : %i\n", Infouang(global.currentPlayer));
                            Infouang(SearchidPlayer(global.listOfPlayer, 1)) = 2000000;

                            printf("\nAset : Taipei lv 1, New Delhi lv 3, Senggigi\n");
                            printf("Ada kartu free tax\n");
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));
                            AddAOI(&(*global.currentPlayer).info.idKartu, 1);
                            AddAOK(&(*global.currentPlayer).info.kota, Taipei);
                            AddAOK(&(*global.currentPlayer).info.kota, New_Delhi);
                            Level(SearchPetak(global.listOfPetak, New_Delhi)) = 3;
                            AddAOK(&(*global.currentPlayer).info.kota, Senggigi);
                            PayTax();
                            printf("Uang akhir A : %i\n", Infouang(global.currentPlayer));

                            Infouang(SearchidPlayer(global.listOfPlayer, 1)) = 2000000;
                            DeleteAOI(&(*global.currentPlayer).info.idKartu, 1);
                            DeleteAOK(&(*global.currentPlayer).info.kota, Taipei);
                            DeleteAOK(&(*global.currentPlayer).info.kota, New_Delhi);
                            Level(SearchPetak(global.listOfPetak, New_Delhi)) = 1;
                            DeleteAOK(&(*global.currentPlayer).info.kota, Senggigi);

                            break;
                        }
            case 3  :
                        {
                            printf("\nCurrent Player A\n");
                            global.currentPlayer = SearchidPlayer(global.listOfPlayer, 1);
                            printf("\nUang awal A : %i\n", Infouang(global.currentPlayer));
                            GetBonus();
                            printf("Uang akhir A : %i\n", Infouang(global.currentPlayer));
                            Infouang(SearchidPlayer(global.listOfPlayer, 1)) = 2000000;

                            break;
                        }
            case 4  :
                        {
                            global.currentPlayer = SearchidPlayer(global.listOfPlayer, 1);
                            printf("\nCurrent Player A\n");
                            printf("\nUang awal A : %i\n", Infouang(global.currentPlayer));
                            printf("Petak Taipei milik A mati lampu\n");
                            printf("Petak Geneva milik B mati lampu\n");
                            Blackout(SearchPetak(global.listOfPetak, Taipei)) = true;
                            Pemilik(SearchPetak(global.listOfPetak, Taipei)) = 1;
                            Blackout(SearchPetak(global.listOfPetak, Geneva)) = true;
                            Pemilik(SearchPetak(global.listOfPetak, Geneva)) = 2;
                            ExecuteStart();
                            printf("Uang akhir A : %i\n", Infouang(global.currentPlayer));

                            Infouang(SearchidPlayer(global.listOfPlayer, 1)) = 2000000;
                            Blackout(SearchPetak(global.listOfPetak, Taipei)) = false;
                            Pemilik(SearchPetak(global.listOfPetak, Taipei)) = 0;
                            Blackout(SearchPetak(global.listOfPetak, Geneva)) = false;
                            Pemilik(SearchPetak(global.listOfPetak, Geneva)) = 0;

                            break;
                        }
            case 5  :
                        {
                            printf("\nTidak ada petak yang sesuai pada board\n");
                            PrintPetak(errorword);
                            printf("\nPetak non kota dan non pariwisata\n");
                            PrintPetak(World_Cup);
                            printf("\nPemilik petak Geneva adalah bank\n");
                            PrintPetak(Geneva);
                            printf("\nPemilik petak Geneva lv 3 adalah B\n");
                            Level(SearchPetak(global.listOfPetak, Geneva)) = 4;
                            Pemilik(SearchPetak(global.listOfPetak, Geneva)) = 2;
                            PrintPetak(Geneva);

                            Level(SearchPetak(global.listOfPetak, Geneva)) = 1;
                            Pemilik(SearchPetak(global.listOfPetak, Geneva)) = 0;

                            break;
                        }
            case 6  :
                        {

                            global.currentPlayer = SearchidPlayer(global.listOfPlayer, 1);
                            printf("\nCurrent Player A\n");

                            printf("\nMembeli petak Ancol milik bank, uang cukup\n");
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));
                            (*global.currentPlayer).info.posisi = SearchPetak(global.listOfPetak, Ancol);
                            Buy();
                            printf("Uang akhir A : %i\n", Infouang(global.currentPlayer));
                            if (isMemberAOK((*global.currentPlayer).info.kota, Ancol))
                            {
                                printf("Salah satu petak yang dimiliki A adalah Ancol\n");
                            }
                            else
                            {
                                printf("Gagal memasukkan New York ke daftar petak milik A\n");
                            }
                            if (isMemberAOK((*global.currentPlayer).info.kota, Ancol))
                            {
                                DeleteAOK(&(*global.currentPlayer).info.kota, Ancol);
                            }
                            Pemilik(SearchPetak(global.listOfPetak, Ancol)) = 0;

                            printf("\nMembeli petak Ancol milik bank, uang tidak cukup\n");
                            Infouang(global.currentPlayer) = 159000;
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));
                            (*global.currentPlayer).info.posisi = SearchPetak(global.listOfPetak, Ancol);
                            Buy();
                            printf("Uang akhir A : %i\n", Infouang(global.currentPlayer));
                            Infouang(global.currentPlayer) = 2000000;

                            printf("\nMembeli petak World Cup\n");
                            (*global.currentPlayer).info.posisi = SearchPetak(global.listOfPetak, World_Cup);
                            Buy();

                            printf("\nMembeli petak milik sendiri\n");
                            (*global.currentPlayer).info.posisi = SearchPetak(global.listOfPetak, Ancol);
                            Pemilik(SearchPetak(global.listOfPetak, Ancol)) = 1;
                            Buy();
                            Pemilik(SearchPetak(global.listOfPetak, Ancol)) = 0;

                            printf("\nMembeli petak New York lv 3 milik B, uang cukup\n");
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));
                            printf("Uang awal B : %i\n", Infouang(SearchidPlayer(global.listOfPlayer, 2)));
                            (*global.currentPlayer).info.posisi = SearchPetak(global.listOfPetak, New_York);
                            AddAOK(&(*global.currentPlayer).info.kota, New_York);
                            Pemilik(SearchPetak(global.listOfPetak, New_York)) = 2;
                            Level(SearchPetak(global.listOfPetak, New_York)) = 3;
                            Buy();
                            printf("Uang Akhir A : %i\n", Infouang(global.currentPlayer));
                            printf("Uang Akhir B : %i\n", Infouang(SearchidPlayer(global.listOfPlayer, 2)));
                            if (isMemberAOK((*global.currentPlayer).info.kota, New_York))
                            {
                                printf("Salah satu petak yang dimiliki A adalah New York\n");
                            }
                            else
                            {
                                printf("Gagal memasukkan New York ke daftar petak milik A\n");
                            }
                            if (!isMemberAOK((*SearchidPlayer(global.listOfPlayer, 2)).info.kota, New_York))
                            {
                                printf("Saat ini B tidak memiliki petak New York\n");
                            }
                            else
                            {
                                printf("Gagal memasukkan New York ke daftar petak milik A\n");
                            }
                            if (isMemberAOK((*SearchidPlayer(global.listOfPlayer, 2)).info.kota, New_York))
                            {
                                DeleteAOK(&(*SearchidPlayer(global.listOfPlayer, 2)).info.kota, New_York);
                            }
                            if (isMemberAOK((*global.currentPlayer).info.kota, New_York))
                            {
                                DeleteAOK(&(*global.currentPlayer).info.kota, New_York);
                            }
                            Pemilik(SearchPetak(global.listOfPetak, New_York)) = 0;
                            Infouang(SearchidPlayer(global.listOfPlayer, 1)) = 2000000;
                            Infouang(SearchidPlayer(global.listOfPlayer, 2)) = 0;

                            printf("\nMembeli petak New York lv 3 milik B, uang tidak cukup\n");
                            Infouang(global.currentPlayer) = 599000;
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));
                            printf("Uang awal B : %i\n", Infouang(SearchidPlayer(global.listOfPlayer, 2)));
                            (*global.currentPlayer).info.posisi = SearchPetak(global.listOfPetak, New_York);
                            AddAOK(&(*global.currentPlayer).info.kota, New_York);
                            Pemilik(SearchPetak(global.listOfPetak, New_York)) = 2;
                            Level(SearchPetak(global.listOfPetak, New_York)) = 3;
                            Buy();
                            printf("Uang Akhir A : %i\n", Infouang(global.currentPlayer));
                            printf("Uang Akhir B : %i\n", Infouang(SearchidPlayer(global.listOfPlayer, 2)));
                            if (isMemberAOK((*global.currentPlayer).info.kota, New_York))
                            {
                                printf("Salah satu petak yang dimiliki A adalah New York\n");
                            }
                            else
                            {
                                printf("Gagal memasukkan New York ke daftar petak milik A\n");
                            }
                            if (!isMemberAOK((*SearchidPlayer(global.listOfPlayer, 2)).info.kota, New_York))
                            {
                                printf("Saat ini B tidak memiliki petak New York\n");
                            }
                            else
                            {
                                printf("Gagal memasukkan New York ke daftar petak milik A\n");
                            }
                            if (isMemberAOK((*SearchidPlayer(global.listOfPlayer, 2)).info.kota, New_York))
                            {
                                DeleteAOK(&(*SearchidPlayer(global.listOfPlayer, 2)).info.kota, New_York);
                            }
                            if (isMemberAOK((*global.currentPlayer).info.kota, New_York))
                            {
                                DeleteAOK(&(*global.currentPlayer).info.kota, New_York);
                            }
                            Pemilik(SearchPetak(global.listOfPetak, New_York)) = 0;
                            Infouang(SearchidPlayer(global.listOfPlayer, 1)) = 2000000;
                            Infouang(SearchidPlayer(global.listOfPlayer, 2)) = 0;

                            printf("\nMembeli petak New York lv 5 milik B\n");
                            (*global.currentPlayer).info.posisi = SearchPetak(global.listOfPetak, New_York);
                            AddAOK(&(*global.currentPlayer).info.kota, New_York);
                            Pemilik(SearchPetak(global.listOfPetak, New_York)) = 2;
                            Level(SearchPetak(global.listOfPetak, New_York)) = 5;
                            Buy();
                            if (isMemberAOK((*global.currentPlayer).info.kota, New_York))
                            {
                                DeleteAOK(&(*global.currentPlayer).info.kota, New_York);
                            }
                            Pemilik(SearchPetak(global.listOfPetak, New_York)) = 0;
                            Infouang(SearchidPlayer(global.listOfPlayer, 1)) = 2000000;
                            Infouang(SearchidPlayer(global.listOfPlayer, 2)) = 0;

                            printf("\nMembeli petak Ancol milik player lain\n");
                            (*global.currentPlayer).info.posisi = SearchPetak(global.listOfPetak, Ancol);
                            Pemilik(SearchPetak(global.listOfPetak, Ancol)) = 2;
                            Buy();
                            Pemilik(SearchPetak(global.listOfPetak, Ancol)) = 0;

                            break;
                        }
            case 7  :
                        {
                            global.currentPlayer = SearchidPlayer(global.listOfPlayer, 1);

                            printf("\nMenjual petak yang tidak ada di board\n");
                            SalePetak(errorword);

                            printf("\nMenjual petak Beijing milik bank\n");
                            SalePetak(Beijing);

                            printf("\nMenjual petak Senggigi milik sendiri\n");
                            Pemilik(SearchPetak(global.listOfPetak, Senggigi)) = 1;
                            SalePetak(Senggigi);
                            Pemilik(SearchPetak(global.listOfPetak, Senggigi)) = 0;
                            Harga_Jual(SearchPetak(global.listOfPetak, Senggigi)) = -1;

                            break;
                        }
            case 8  :
                        {
                            global.currentPlayer = SearchidPlayer(global.listOfPlayer, 1);

                            printf("\nMelepas petak yang tidak ada pada board dari daftar offer\n");
                            UnsalePetak(errorword);

                            printf("\nMelepas petak bukan milik sendiri dari daftar offer\n");
                            UnsalePetak(Berlin);

                            printf("\nMelepas petak milik sendiri yang tidak ada di daftar offer\n");
                            Pemilik(SearchPetak(global.listOfPetak, Berlin)) = 1;
                            UnsalePetak(Berlin);

                            printf("\nMelepas petak milik sendiri yang terdapat di daftar offer\n");
                            Harga_Jual(SearchPetak(global.listOfPetak, Berlin)) = 0;
                            UnsalePetak(Berlin);

                            Pemilik(SearchPetak(global.listOfPetak, Berlin)) = 0;

                            break;
                        }
            case 9  :
                        {
                            global.currentPlayer = SearchidPlayer(global.listOfPlayer, 1);

                            printf("\nMenjual petak yang tidak ada di board ke bank\n");
                            JualKeBank(errorword);

                            printf("\nMenjual petak bukan milik sendiri ke bank\n");
                            JualKeBank(Sao_Paolo);

                            printf("\nMenjual petak Sao Paolo lv 3 milik sendiri ke bank\n");
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));
                            Pemilik(SearchPetak(global.listOfPetak, Sao_Paolo)) = 1;
                            Level(SearchPetak(global.listOfPetak, Sao_Paolo)) = 3;
                            AddAOK(&(*global.currentPlayer).info.kota, Sao_Paolo);
                            JualKeBank(Sao_Paolo);
                            printf("Uang akhir A : %i\n", Infouang(global.currentPlayer));

                            Infouang(global.currentPlayer) = 2000000;

                            break;
                        }
            case 10 :
                        {
                            printf("\nDaftar offer kosong\n");
                            PrintSale();

                            printf("\nDaftar offer berisi Bintan(A/5/5000), Bangkok(B/3/10000), Beijing(C/1/15000)\n");
                            Harga_Jual(SearchPetak(global.listOfPetak, Bintan)) = 5000;
                            Harga_Jual(SearchPetak(global.listOfPetak, Bangkok)) = 10000;
                            Harga_Jual(SearchPetak(global.listOfPetak, Beijing)) = 15000;
                            Level(SearchPetak(global.listOfPetak, Bintan)) = 5;
                            Level(SearchPetak(global.listOfPetak, Bangkok)) = 3;
                            Level(SearchPetak(global.listOfPetak, Beijing)) = 1;
                            Pemilik(SearchPetak(global.listOfPetak, Bintan)) = 1;
                            Pemilik(SearchPetak(global.listOfPetak, Bangkok)) = 2;
                            Pemilik(SearchPetak(global.listOfPetak, Beijing)) = 3;
                            PrintSale();

                            Harga_Jual(SearchPetak(global.listOfPetak, Bintan)) = -1;
                            Harga_Jual(SearchPetak(global.listOfPetak, Bangkok)) = -1;
                            Harga_Jual(SearchPetak(global.listOfPetak, Beijing)) = -1;
                            Level(SearchPetak(global.listOfPetak, Bintan)) = 1;
                            Level(SearchPetak(global.listOfPetak, Bangkok)) = 1;
                            Level(SearchPetak(global.listOfPetak, Beijing)) = 1;
                            Pemilik(SearchPetak(global.listOfPetak, Bintan)) = 0;
                            Pemilik(SearchPetak(global.listOfPetak, Bangkok)) = 0;
                            Pemilik(SearchPetak(global.listOfPetak, Beijing)) = 0;

                            break;
                        }
            case 11 :
                        {
                            global.currentPlayer = SearchidPlayer(global.listOfPlayer, 1);

                            printf("\nMembeli saat dipenjara\n");
                            (*global.currentPlayer).info.penjara = true;
                            BeliSale(Moscow);

                            printf("\nMembeli petak yang tidak ada di board\n");
                            (*global.currentPlayer).info.penjara = false;
                            BeliSale(errorword);

                            printf("\nMembeli petak yang tidak terdapat di daftar offer\n");
                            BeliSale(Moscow);

                            printf("\nMembeli petak milik sendiri dalam list offer\n");
                            Pemilik(SearchPetak(global.listOfPetak, Moscow)) = 1;
                            BeliSale(Moscow);

                            printf("\nMembeli petak dalam list offer namun uang tidak mencukupi\n");
                            Pemilik(SearchPetak(global.listOfPetak, Moscow)) = 2;
                            Harga_Jual(SearchPetak(global.listOfPetak, Moscow)) = 200000;
                            Infouang(global.currentPlayer) = 199000;
                            BeliSale(Moscow);

                            printf("\nMembeli petak dalam list offer dan uang mencukupi\n");
                            Infouang(global.currentPlayer) = 2000000;
                            printf("Uang awal A : %i\n", Infouang(global.currentPlayer));
                            printf("Uang awal B : %i\n", Infouang(SearchidPlayer(global.listOfPlayer, 2)));
                            Pemilik(SearchPetak(global.listOfPetak, Moscow)) = 2;
                            BeliSale(Moscow);
                            printf("Uang Akhir A : %i\n", Infouang(global.currentPlayer));
                            printf("Uang Akhir B : %i\n", Infouang(SearchidPlayer(global.listOfPlayer, 2)));
                            if (isMemberAOK((*global.currentPlayer).info.kota, Moscow))
                            {
                                printf("Salah satu petak yang dimiliki A adalah Moscow\n");
                            }
                            else
                            {
                                printf("Gagal memasukkan Moscow ke daftar petak milik A\n");
                            }
                            if (!isMemberAOK((*SearchidPlayer(global.listOfPlayer, 2)).info.kota, Moscow))
                            {
                                printf("Saat ini B tidak memiliki petak Moscow\n");
                            }
                            else
                            {
                                printf("Gagal memasukkan New York ke daftar petak milik A\n");
                            }
                            if (isMemberAOK((*SearchidPlayer(global.listOfPlayer, 2)).info.kota, Moscow))
                            {
                                DeleteAOK(&(*SearchidPlayer(global.listOfPlayer, 2)).info.kota, Moscow);
                            }
                            if (isMemberAOK((*global.currentPlayer).info.kota, Moscow))
                            {
                                DeleteAOK(&(*global.currentPlayer).info.kota, Moscow);
                            }
                            Pemilik(SearchPetak(global.listOfPetak, Moscow)) = 0;
                            Infouang(SearchidPlayer(global.listOfPlayer, 1)) = 2000000;
                            Infouang(SearchidPlayer(global.listOfPlayer, 2)) = 0;

                            break;
                        }
            case 12 :
                        {
                            global.currentPlayer = SearchidPlayer(global.listOfPlayer, 1);

                            printf("\nMengupgrade petak yang bukan milik sendiri\n");
                            (*global.currentPlayer).info.posisi = SearchPetak(global.listOfPetak, London);
                            LevelUp();

                            printf("\nMengupgrade petak milik sendiri yang belum mencapai level maksimum dan uang cukup\n");
                            printf("Multiplier awal : %f\n", Multiplier_Sewa((*global.currentPlayer).info.posisi));
                            printf("Level awal : %d\n", Level((*global.currentPlayer).info.posisi));
                            Pemilik((*global.currentPlayer).info.posisi) = 1;
                            LevelUp();
                            printf("Multiplier akhir : %f\n", Multiplier_Sewa((*global.currentPlayer).info.posisi));
                            printf("Level akhir : %d\n", Level((*global.currentPlayer).info.posisi));

                            printf("\nMengupgrade petak milik sendiri yang belum mencapai level maksimum dan uang tidak cukup\n");
                            Level((*global.currentPlayer).info.posisi) = 1;
                            Multiplier_Sewa((*global.currentPlayer).info.posisi) = 1;
                            Infouang(global.currentPlayer) = 209000;
                            printf("Multiplier awal : %f\n", Multiplier_Sewa((*global.currentPlayer).info.posisi));
                            printf("Level awal : %d\n", Level((*global.currentPlayer).info.posisi));
                            Pemilik((*global.currentPlayer).info.posisi) = 1;
                            LevelUp();
                            printf("Multiplier akhir : %f\n", Multiplier_Sewa((*global.currentPlayer).info.posisi));
                            printf("Level akhir : %d\n", Level((*global.currentPlayer).info.posisi));

                            printf("\nMengupgrade petak milik sendiri yang sudah mencapai level maksimum\n");
                            Level((*global.currentPlayer).info.posisi) = 5;
                            Multiplier_Sewa((*global.currentPlayer).info.posisi) = 3;
                            printf("Multiplier awal : %f\n", Multiplier_Sewa((*global.currentPlayer).info.posisi));
                            printf("Level awal : %d\n", Level((*global.currentPlayer).info.posisi));
                            LevelUp();
                            printf("Multiplier akhir : %f\n", Multiplier_Sewa((*global.currentPlayer).info.posisi));
                            printf("Level akhir : %d\n", Level((*global.currentPlayer).info.posisi));

                            Level((*global.currentPlayer).info.posisi) = 1;
                            Multiplier_Sewa((*global.currentPlayer).info.posisi) = 1;
                            Pemilik((*global.currentPlayer).info.posisi) = 0;
                            Infouang(SearchidPlayer(global.listOfPlayer, 1)) = 2000000;
                            (*global.currentPlayer).info.posisi = FirstPetak(global.listOfPetak);

                            break;
                        }
            case 13 :
                        {
                            printf("\nPlayer tersebar\n");
                            (*SearchidPlayer(global.listOfPlayer, 1)).info.posisi = SearchPetakByID(global.listOfPetak, 9);
                            (*SearchidPlayer(global.listOfPlayer, 2)).info.posisi = SearchPetakByID(global.listOfPetak, 13);
                            (*SearchidPlayer(global.listOfPlayer, 3)).info.posisi = SearchPetakByID(global.listOfPetak, 27);
                            Level(SearchPetak(global.listOfPetak, Bintan)) = 5;
                            Level(SearchPetak(global.listOfPetak, Bangkok)) = 3;
                            Level(SearchPetak(global.listOfPetak, Beijing)) = 1;
                            Pemilik(SearchPetak(global.listOfPetak, Bintan)) = 1;
                            Pemilik(SearchPetak(global.listOfPetak, Bangkok)) = 2;
                            Pemilik(SearchPetak(global.listOfPetak, Beijing)) = 3;
                            PrintBoard(global.listOfPetak, global.listOfPlayer);

                            printf("\nPlayer terkumpul\n");
                            (*SearchidPlayer(global.listOfPlayer, 1)).info.posisi = SearchPetakByID(global.listOfPetak, 22);
                            (*SearchidPlayer(global.listOfPlayer, 2)).info.posisi = SearchPetakByID(global.listOfPetak, 22);
                            (*SearchidPlayer(global.listOfPlayer, 3)).info.posisi = SearchPetakByID(global.listOfPetak, 22);
                            Level(SearchPetak(global.listOfPetak, Bintan)) = 5;
                            Level(SearchPetak(global.listOfPetak, Bangkok)) = 3;
                            Level(SearchPetak(global.listOfPetak, Beijing)) = 1;
                            Pemilik(SearchPetak(global.listOfPetak, Bintan)) = 1;
                            Pemilik(SearchPetak(global.listOfPetak, Bangkok)) = 2;
                            Pemilik(SearchPetak(global.listOfPetak, Beijing)) = 3;
                            PrintBoard(global.listOfPetak, global.listOfPlayer);

                            (*SearchidPlayer(global.listOfPlayer, 1)).info.posisi = First(global.listOfPetak);
                            (*SearchidPlayer(global.listOfPlayer, 2)).info.posisi = First(global.listOfPetak);
                            (*SearchidPlayer(global.listOfPlayer, 3)).info.posisi = First(global.listOfPetak);
                            Level(SearchPetak(global.listOfPetak, Bintan)) = 1;
                            Level(SearchPetak(global.listOfPetak, Bangkok)) = 1;
                            Level(SearchPetak(global.listOfPetak, Beijing)) = 1;
                            Pemilik(SearchPetak(global.listOfPetak, Bintan)) = 0;
                            Pemilik(SearchPetak(global.listOfPetak, Bangkok)) = 0;
                            Pemilik(SearchPetak(global.listOfPetak, Beijing)) = 0;

                            break;
                        }
            case 14 :
                        {
                            global.currentPlayer = SearchidPlayer(global.listOfPlayer, 1);

                            printf("\nMemilih petak saat tidak di petak world cup\n");
                            AppointWorldCup(Sydney);

                            printf("\nMemilih petak yang tidak ada di board\n");
                            (*global.currentPlayer).info.posisi = SearchPetak(global.listOfPetak, World_Cup);
                            AppointWorldCup(errorword);

                            printf("\nMemilih petak yang bukan milik sendiri\n");
                            AppointWorldCup(Sydney);

                            printf("\nMemilih petak non kota milik sendiri\n");
                            Pemilik(SearchPetak(global.listOfPetak, Kuta)) = 1;
                            AppointWorldCup(Kuta);
                            Pemilik(SearchPetak(global.listOfPetak, Kuta)) = 0;

                            printf("\nMemilih petak kota milik sendiri\n");
                            Pemilik(SearchPetak(global.listOfPetak, Sydney)) = 1;
                            AppointWorldCup(Sydney);
                            printf("Petak World Cup saat ini : ");
                            PrintKata(Nama_Petak(global.currentWorldCup));
                            printf("\n");

                            global.currentWorldCup = Nil;
                            Pemilik(SearchPetak(global.listOfPetak, Sydney)) = 0;
                            (*global.currentPlayer).info.posisi = FirstPetak(global.listOfPetak);

                            break;
                        }
            case 15 :
                        {
                            global.currentPlayer = SearchidPlayer(global.listOfPlayer, 1);

                            printf("\nMemilih petak saat tidak di petak world travel\n");
                            WorldTravel(Singapura);

                            printf("\nMemilih petak yang tidak ada di board\n");
                            (*global.currentPlayer).info.posisi = SearchPetak(global.listOfPetak, World_Travel);
                            WorldTravel(errorword);

                            printf("\nMemilih petak non kota dan non tempat pariwisata\n");
                            WorldTravel(Bonus);

                            printf("\nMemilih petak kota atau pariwisata\n");
                            WorldTravel(Singapura);
                            printf("Saat ini anda berada di petak ");
                            PrintKata(Nama_Petak((*global.currentPlayer).info.posisi));
                            printf("\n");

                            (*global.currentPlayer).info.posisi = FirstPetak(global.listOfPetak);

                            break;
                        }

        }

    }while (opt != 0);
    return 0;
}
