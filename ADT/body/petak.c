#include "../header/petak.h"
#include "../header/player.h"

void PrintBoard();
// cetak kondisi board

void PrintMap();
// cetak peta board





// PENGLOLAAN LIST PETAK

void CreateListPetak(ListPetak *L)
// Membuat list petak kosong
{
    FirstPetak(*L) = Nil;
}

void AddLastPetak(ListPetak *L, AddressOfPetak P)
// Memasukkan P pada list petak (harus alokasi dulu
{
    AddressOfPetak p;

    if (FirstPetak(*L) == Nil)
    {
        FirstPetak(*L) = P;
        NextPetak(FirstPetak(*L)) = FirstPetak(*L);
    }
    else
    {
        p = FirstPetak(*L);
        do
        {
            p = NextPetak(p);
        } while (NextPetak(p) != FirstPetak(*L));
        NextPetak(p) = P;
        NextPetak(NextPetak(p)) = FirstPetak(*L);
    }
}

AddressOfPetak AlokasiPetak(InfoPetak P)
// menghasilkan address hasil alokasi P
{
    AddressOfPetak p;

    p = malloc(sizeof(ElmtPetak));
    NextPetak(p) = Nil;
    (*p).info = P;

    return p;
}

AddressOfPetak SearchPetak(ListPetak L, Kata namapetak)
// output address petak
{
    AddressOfPetak p;

    p = FirstPetak(L);
    do
    {
        p = NextPetak(p);
    }
    while(!(IsKataSama(namapetak, Nama_Petak(p))) && p != FirstPetak(L));

    if (IsKataSama(namapetak, Nama_Petak(p)))
    {
        return p;
    }
    else
    {
        return Nil;
    }
}

AddressOfPetak SearchPetakByID(ListPetak L, int id)
// output address petak
{
    AddressOfPetak p;

    p = FirstPetak(L);
    do
    {
        p = NextPetak(p);
    }
    while(id == ID_Petak(p) && p != FirstPetak(L));

    if (id == ID_Petak(p))
    {
        return p;
    }
    else
    {
        return Nil;
    }
}



// PREDIKAT

boolean isKota(AddressOfPetak P)
// mengembalikan true jika p merupakan petak kota
{
    Kata kota;

    kota.TabKata[0] = 'K';
    kota.TabKata[1] = 'o';
    kota.TabKata[2] = 't';
    kota.TabKata[3] = 'a';
    kota.Length = 4;

    return IsKataSama(Jenis_Petak(P), kota);
}

boolean isTempatWisata(AddressOfPetak P)
// mengembalikan true jika p merupakan petak tempat wisata
{
    Kata tempat_wisata;

    tempat_wisata.TabKata[0] = 'T';
    tempat_wisata.TabKata[1] = 'e';
    tempat_wisata.TabKata[2] = 'm';
    tempat_wisata.TabKata[3] = 'p';
    tempat_wisata.TabKata[4] = 'a';
    tempat_wisata.TabKata[5] = 't';
    tempat_wisata.TabKata[6] = '_';
    tempat_wisata.TabKata[7] = 'W';
    tempat_wisata.TabKata[8] = 'i';
    tempat_wisata.TabKata[10] = 's';
    tempat_wisata.TabKata[11] = 'a';
    tempat_wisata.TabKata[12] = 't';
    tempat_wisata.TabKata[13] = 'a';
    tempat_wisata.Length = 13;

    return IsKataSama(Jenis_Petak(P), tempat_wisata);
}

// LEVEL UP BANGUNAN

void UpdateMultiplier(AddressOfPetak *L)
// mengupdate multiplier jika ada perubahan kondisi bangunan
{
    Multiplier_Sewa(*L) = (Level(*L) + 1)/2;
}

//TRANSAKSI DENGAN BANK

int HargaJualKeBank(Kata namapetak)
// output harga jual ke bank
{
    int harga;
    AddressOfPetak p;

    p = SearchPetak(global.listOfPetak, namapetak);
    harga = (int) Level(p)*(Level(p)-1)/2*Biaya_Upgrade(p) + Biaya_Ambil_Alih(p);
    harga = (int) 9/10*harga;

    return harga;
}

void BeliPetak()
// membeli petak dari bank
{
    AddressOfPetak p;

    p = (*global.currentPlayer).posisi;

    if (!isKota(p) && !isTempatWisata(p))
    {
        printf("Petak ini bukan petak yang bisa dibeli\n");
    }
    else if(Pemilik(p) != 0)
    {
        printf("Petak ini bukan milik bank\n");
    }
    else
    {
        if ((*global.currentPlayer).uang < Biaya_Ambil_Alih(p))
        {
            printf("Uang anda tidak mencukupi untuk membeli petak ini\n");
        }
        else
        {
            (*global.currentPlayer).uang -= Biaya_Ambil_Alih(p);
            Pemilik(p) = (*global.currentPlayer).id;
            AddKota(global.currentPlayer, Nama_Petak(p));
            printf("Pembelian berhasil, petak ");
            PrintKata(Nama_Petak(p));
            printf(" sekarang menjadi milik anda\n");
        }
    }
}

//SEWA

int WorldCupMultiplier()
// mengembalikan multiplier akibat worldcup
{
    AddressOfPetak p;

    p = (*global.currentPlayer).posisi;
    if (global.currentWorldCup == &(*p).info)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

int BlokMultiplier()
// mengembalikan multiplier akibat blok
{
    boolean blokbonus;
    AddressOfPetak p, P;

    P = (*global.currentPlayer).posisi;
    p = (*global.currentPlayer).posisi;
    blokbonus = true;
    do
    {
        p = NextPetak(p);
        if (Blok(p) == Blok(P) && Pemilik(p) != Pemilik(P))
        {
            blokbonus = false;
        }
    } while(p != P && blokbonus);
    if (blokbonus)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

int BlackoutMultiplier()
//mengembalikan multiplier akibat blackout
{
    if(Blackout((*global.currentPlayer).posisi))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int HargaSewa()
// output harga sewa total, termasuk perhitungan level
{
    AddressOfPetak p;
    int sewa;

    p = (*global.currentPlayer).posisi;
    sewa = (int) Biaya_Sewa(p) * Multiplier_Sewa(p) * WorldCupMultiplier(p) * BlokMultiplier(p) * BlackoutMultiplier(p);

    return sewa;
}

//BELI PAKSA

int HargaBeliPaksa()
// ouput harga beli paksa
{
    int harga;
    AddressOfPetak p;

    p = (*global.currentPlayer).posisi;
    harga = (int) Level(p)*(Level(p)-1)/2*Biaya_Upgrade(p) + Biaya_Ambil_Alih(p);

    return harga*2;
}

void BeliPaksa()
//Eksekusi beli paksa
{
    AddressOfPetak p;
    AddressOfPlayer P;

    p = (*global.currentPlayer).posisi;
    P = SearchidPlayer(global.listOfPlayer, Pemilik(p));

    if (Pemilik(p) == (*global.currentPlayer).id)
    {
        printf("Petak ini adalah milik anda sendiri\n");
    }
    else if (Pemilik(p) == 0)
    {
        printf("Petak ini bukan milik player, anda tidak bisa membeli paksa petak ini\n");
    }
    else if (Level(p) == 5)
    {
        printf("Petak ini tidak bisa dibeli karena sudah memiliki landmark\n");
    }
    else if ((*global.currentPlayer).uang < HargaBeliPaksa())
    {
        printf("Uang anda tidak mencukupi untuk membeli petak ini\n");
    }
    else
    {
        (*global.currentPlayer).uang -= HargaBeliPaksa();
        Infouang(P) += HargaBeliPaksa();

        DelKota(&((*P).info), Nama_Petak(p));
        AddKota(global.currentPlayer, Nama_Petak(p));

        Pemilik(p) = (*global.currentPlayer).id;
        Harga_Jual(p) = -1;
        Level(p) = 1;
        UpdateMultiplier(&p);

        printf("Pembelian berhasil, petak ");
        PrintKata(Nama_Petak(p));
        printf(" sekarang menjadi milik anda\n");
    }
}

/////////////////////////////////////////////////////NON-COMMAND INSTRUCTION/////////////////////////////////////////////////////


//=====================================================================================sewa

void BayarSewa()
// eksekusi pembayaran sewa
{
    int sewa;
    AddressOfPlayer owner;

    owner = SearchidPlayer(global.listOfPlayer, Pemilik((*global.currentPlayer).posisi));

    if (&(*owner).info == global.currentPlayer)
    {
        printf("Anda berhenti di petak milik anda sendiri\n");
        printf("Tidak ada biaya sewa yang perlu anda bayar dipetak ini\n");
    }
    else if (owner == 0)
    {
        printf("Petak tempat anda berhenti bukan milik player\n");
        printf("Tidak ada biaya sewa yang perlu anda bayar dipetak ini\n");
    }
    else
    {
        (*global.currentPlayer).uang -= HargaSewa();
        Infouang(owner) += HargaSewa();

        printf("Anda membayar sewa kepada ");
        PrintKata((*owner).info.nama);
        printf("sebesar %i\n", HargaSewa());
    }
}

//======================================================================================tax

void PayTax()
//Membayar uang tax
{
    int tax;

    tax = (int) HitungHartaPlayer((*global.currentPlayer))/10;
    (*global.currentPlayer).uang -= tax;
    printf("Anda membayar tax sebesar %i\n", tax);
}

//===================================================================================chance

void GetBonus()
// Memberikan bonus pada player yang mendarat di petak bonus
{
    int bonus[10];
    int random;

    bonus[0] = 10000;
    bonus[1] = 20000;
    bonus[2] = 30000;
    bonus[3] = 40000;
    bonus[4] = 50000;
    bonus[5] = 60000;
    bonus[6] = 70000;
    bonus[7] = 80000;
    bonus[8] = 90000;
    bonus[9] = 100000;

    srand(9);
    random = rand();
    (*global.currentPlayer).uang += bonus[random];
    printf("Anda mendapat bonus sebesar %i\n", bonus[random]);
}

//====================================================================================start

void ExecuteStart()
//Mengeksekusi apa yang harus dilakukan jika berhenti/melewati petak start
{
    int valstart;
    AddressOfPetak p;

    valstart = 200000;
    (*global.currentPlayer).uang += valstart;
    printf("Anda melewati start\n");
    printf("Anda mendapatkan uang sebesar %i", valstart);
    p = FirstPetak(global.listOfPetak);
    do
    {
        if (Pemilik(p) == (*global.currentPlayer).id && Blackout(p))
        {
            Blackout(p) = false;
            printf("Petak ");
            PrintKata(Nama_Petak(p));
            printf(" terlepas dari status mati lampu\n");
        }
        p = NextPetak(p);
    } while (p != FirstPetak(global.listOfPetak));
}

///////////////////////////////////////////////////////COMMAND INSTRUCTION///////////////////////////////////////////////////////

//========================================================================info <nama petak>

void PrintPetak(Kata namapetak)
// cetak info petak
{
    AddressOfPetak p;
    AddressOfPlayer P;

    p = SearchPetak(global.listOfPetak, namapetak);
    if (p == Nil)
    {
        printf("Tidak ada petak bernama");
        PrintKata(namapetak);
        printf(" pada board\n");
    }
    else if(!isKota(p) && !isTempatWisata(p))
    {
        printf("Nama Petak : ");
        PrintKata(namapetak);
        printf("\n");
    }
    else
    {
        printf("Nama petak\t\t: ");
        PrintKata(Nama_Petak(p));
        printf("\n");

        printf("Pemilik\t\t: ");
        if (Pemilik(p) == 0)
        {
            printf("tidak ada\n");
            printf("Harga\t\t: %i\n", Biaya_Ambil_Alih(p));
        }
        else
        {
            P = SearchidPlayer(global.listOfPlayer, Pemilik(p));
            PrintKata((*P).info.nama);
            printf("\n");
            printf("Harga Beli Paksa\t: %i\n", HargaBeliPaksa(p));
        }
    }
}
//======================================================================================buy

void Buy()
{
    if ((*global.currentPlayer).penjara)
    {
        printf("Anda tidak bisa menggunakan command ini saat sedang dipenjara\n");
    }
    else if (Pemilik((*global.currentPlayer).posisi) == 0)
    {
        BeliPetak();
    }
    else
    {
        BeliPaksa();
    }
}

//========================================================================sell <nama petak>

void SalePetak(Kata namapetak)
// menjual petak secara offer (pasang harga offer)
{
    int price;
    AddressOfPetak p;

    p = SearchPetak(global.listOfPetak, namapetak);
    if (p == Nil)
    {
        printf("Tidak ada petak bernama ");
        PrintKata(namapetak);
        printf(" pada board\n");
    }
    else if(Pemilik(p) == (*global.currentPlayer).id)
    {
        printf("Masukkan harga jual yang diinginkan : ");
        scanf("%i", &price);
        printf("/n");
        if (price >= 0)
        {
            Harga_Jual(p) = price;
            printf("Petak berhasil dimasukkan ke dalam daftar offered\n");
        }
        else
        {
            printf("Petak gagal dimasukkan ke dalam daftar offered\n");
            printf("Harga jual offered tidak boleh negatif\n");
        }
    }
    else
    {
        printf("Petak gagal dimasukkan ke dalam daftar offered\n");
        printf("Anda hanya bisa menjual petak milik anda sendiri\n");
    }
}

//======================================================================unsell <nama petak>

void UnsalePetak(Kata namapetak)
// membatalkan sale petak
{
    AddressOfPetak p;
    p = SearchPetak(global.listOfPetak, namapetak);

    if (p == Nil)
    {
        printf("Tidak ada petak bernama ");
        PrintKata(namapetak);
        printf(" pada board\n");
    }
    else if(Pemilik(p) == (*global.currentPlayer).id)
    {
        if (Harga_Jual(p) != -1)
        {
            Harga_Jual(p) = -1;
            printf("Petak berhasil dilepas dari daftar offered\n");
        }
        else
        {
            printf("Petak tidak terdapat pada daftar offered\n");
        }
    }
    else
    {
        printf("Petak gagal dilepas dari daftar offered\n");
        printf("Anda hanya bisa melepas petak milik anda sendiri dari daftar offered\n");
    }
}

//===================================================================sell bank <nama petak>

void JualKeBank(Kata namapetak)
// menjual petak ke bank (lepas kepemilikan, update uang pemilik)
{
    AddressOfPetak p;
    p = SearchPetak(global.listOfPetak, namapetak);

    if (p == Nil)
    {
        printf("Tidak ada petak bernama ");
        PrintKata(namapetak);
        printf(" pada board\n");
    }
    else if (Pemilik(p) != (*global.currentPlayer).id)
    {
        printf("Petak bukan milik anda, anda hanya bisa menjual petak milik sendiri\n");
    }
    else
    {
        Pemilik(p) = 0;
        DelKota(global.currentPlayer, Nama_Petak(p));
        (*global.currentPlayer).uang += HargaJualKeBank(Nama_Petak(p));
        Level(p) = 1;
        Harga_Jual(p) = -1;
        UpdateMultiplier(&p);
        Blackout(p) = false;
        printf("Penjualan berhasil");
    }
}

//=============================================================================show offered

void PrintSale()
// mencetak daftar petak yang di sale ke layar
{

    AddressOfPetak p;

    p = FirstPetak(global.listOfPetak);

    printf("\n");
    do
    {
        p = NextPetak(p);
        if ((isKota(p) || isTempatWisata(p)) && Harga_Jual(p) >= 0)
        {
            printf("\n");
            printf("\t"); PrintKata(Nama_Petak(p)); printf("\n");
            printf("\t\tOwner\t: %c\n", Pemilik(p));
            printf("\t\tLevel\t: %i\n", Level(p));
            printf("\t\tPrice\t: %i\n", Harga_Jual(p));
        }
    } while (p != FirstPetak(global.listOfPetak));
    printf("\n");
}

//==============================================================================buy offered

void BeliSale(Kata namapetak)
// membeli petak yg di-sale
{
    AddressOfPetak p;
    AddressOfPlayer P;

    p = SearchPetak(global.listOfPetak, namapetak);


    if ((*global.currentPlayer).penjara)
    {
        printf("Anda tidak bisa menggunakan command ini saat sedang dipenjara\n");
    }
    else if (p == Nil)
    {
        printf("Tidak ada petak bernama ");
        PrintKata(namapetak);
        printf(" pada board\n");
    }
    else if (Harga_Jual(p) == -1)
    {
        printf("Petak yang anda inginkan tidak termasuk dalam daftar offered");
    }
    else if (Pemilik(p) == (*global.currentPlayer).id)
    {
        printf("Petak ini adalah milik anda sendiri\n");
    }
    else if ((*global.currentPlayer).uang < Harga_Jual(p))
    {
        printf("Uang anda tidak mencukupi untuk membeli petak ini\n");
    }
    else
    {
        P = SearchidPlayer(global.listOfPlayer, Pemilik(p));

        (*global.currentPlayer).uang -= Harga_Jual(p);
        Infouang(P) += Harga_Jual(p);

        DelKota(&((*P).info), Nama_Petak(p));
        AddKota(global.currentPlayer, Nama_Petak(p));

        Pemilik(p) = (*global.currentPlayer).id;
        Harga_Jual(p) = -1;

        printf("Pembelian berhasil, petak");
        PrintKata(Nama_Petak(p));
        printf("sekarang menjadi milik anda\n");
    }
}

//==================================================================================upgrade

void LevelUp()
// meningkatkan level bangunan pada petak
{
    int harga;
    AddressOfPetak p;

    p = (*global.currentPlayer).posisi;

    if ((*global.currentPlayer).penjara)
    {
        printf("Anda tidak bisa menggunakan command ini saat sedang dipenjara\n");
    }
    else if (Pemilik(p) != (*global.currentPlayer).id)
    {
        printf("Petak bukan milik anda, anda hanya bisa meningkatkan level bangunan petak milik sendiri\n");
    }
    else if ((isTempatWisata(p) && Level(p) == 1) || (isKota(p) && Level(p) == 5))
    {
        printf("Petak telah mencapai level bangunan maksimum");
    }
    else
    {
        harga = Biaya_Upgrade(p)*Level(p);


        if ((*global.currentPlayer).uang < harga)
        {
            printf("Uang anda tidak mencukupi untuk ungrade bangunan\n");
        }
        else
        {
            Level(p)++;
            (*global.currentPlayer).uang -= harga;
            UpdateMultiplier(&p);

            printf("Upgrade bangunan berhasil, bangunan pada petak ");
            PrintKata(Nama_Petak(p));
            printf(" menjadi level %i\n", Level(p));
        }
    }
}

//====================================================================================board

  //Bagiannya Resa

//=========================================================================host <nama kota>

void AppointWorldCup(Kata namapetak)
// Menunjuk petak worldcup
{
    Kata world_cup;
    AddressOfPetak p;

    world_cup.TabKata[0] = 'W';
    world_cup.TabKata[1] = 'o';
    world_cup.TabKata[2] = 'r';
    world_cup.TabKata[3] = 'l';
    world_cup.TabKata[4] = 'd';
    world_cup.TabKata[5] = '_';
    world_cup.TabKata[6] = 'C';
    world_cup.TabKata[7] = 'u';
    world_cup.TabKata[8] = 'p';
    world_cup.Length = 9;

    if ((*global.currentPlayer).penjara)
    {
        printf("Anda tidak bisa menggunakan command ini saat sedang dipenjara\n");
    }
    else if (!IsKataSama(Jenis_Petak((*global.currentPlayer).posisi),world_cup))
    {
        printf("Anda sedang tidak berada di petak World Cup");
    }
    else
    {
        p = SearchPetak(global.listOfPetak, namapetak);

        if (p == Nil)
        {
            printf("Tidak ada petak bernama ");
            PrintKata(namapetak);
            printf(" pada board\n");
        }
        else if (Pemilik(SearchPetak(global.listOfPetak, namapetak)) != (*global.currentPlayer).id)
        {
            printf("Anda hanya bisa menunjuk petak milik anda untuk menjadi petak World Cup\n");
        }
        else if (!isKota(SearchPetak(global.listOfPetak, namapetak)))
        {
            printf("Anda hanya bisa menunjuk petak kota untuk menjadi petak World Cup\n");
        }
        else
        {
            global.currentWorldCup = &(*SearchPetak(global.listOfPetak, namapetak)).info;
            printf("Petak ");
            PrintKata(namapetak);
            printf(" saat ini telah menjadi petak World Cup\n");
        }
    }
}

//======================================================================travel <nama petak>

void WorldTravel(Kata namapetak)
//Berpindah ke petak tujuan worldtravel
{
    Kata world_travel;
    AddressOfPetak p;

    world_travel.TabKata[0] = 'W';
    world_travel.TabKata[1] = 'o';
    world_travel.TabKata[2] = 'r';
    world_travel.TabKata[3] = 'l';
    world_travel.TabKata[4] = 'd';
    world_travel.TabKata[5] = '_';
    world_travel.TabKata[6] = 'T';
    world_travel.TabKata[7] = 'r';
    world_travel.TabKata[8] = 'a';
    world_travel.TabKata[9] = 'v';
    world_travel.TabKata[10] = 'e';
    world_travel.TabKata[11] = 'l';
    world_travel.Length = 12;

    if ((*global.currentPlayer).penjara)
    {
        printf("Anda tidak bisa menggunakan command ini saat sedang dipenjara\n");
    }
    else if (!IsKataSama(Jenis_Petak((*global.currentPlayer).posisi), world_travel))
    {
        printf("Anda sedang tidak berada di petak World Travel");
    }
    else
    {
        p = SearchPetak(global.listOfPetak, namapetak);

        if (p == Nil)
        {
            printf("Tidak ada petak bernama ");
            PrintKata(namapetak);
            printf(" pada board\n");
        }
        else if (!isKota(SearchPetak(global.listOfPetak, namapetak)) && !isTempatWisata(SearchPetak(global.listOfPetak, namapetak)))
        {
            printf("Anda hanya bisa melakukan World Travel ke petak kota atau petak tempat wisata\n");
        }
        else
        {
            (*global.currentPlayer).posisi = SearchPetak(global.listOfPetak, namapetak);
            printf("Anda telah melakukan world travel ke petak ");
            PrintKata(namapetak);
            printf("\n");
        }
    }
}
