#include "../header/petak.h"
#include "../header/player.h"
#include "../header/arrayofint.h"

void PrintOwner(AddressOfPetak P)
{
<<<<<<< HEAD

=======
	int id;
	char own;
	
	switch (Info(P).pemilik)
		{
			case 1 :
				own = 'A';
				break;
			case 2 :
				own	= 'B';
				break;
			case 3 :
				own = 'C';
				break;
			case 4 :
				own = 'D';
				break;
			default:
				own = ' ';
		}
		id = Info(P).level;
		printf("   %c%d    |",own,id);
>>>>>>> origin/master
}

void PrintPosition(AddressOfPetak P,TabInt T)
{
	int n, i;
	
	for (i=0;i<=T.eff;i++)
	{
		if (Info(P).id_petak == T.T[i])
		{
			switch (i)
			{
				case 0:
					printf("A ");
					break;
				case 1:
					printf("B ");
					break;
				case 2:
					printf("C ");
					break;
				case 3:
					printf("D ");
					break;
			}
		}
		else
			printf("  ");
	}
	if (T.eff < 4)
	{
		n = 4 - T.eff;
		for(i=1;i<=n;i++)
		{
			printf("  ");
		}
	}
	printf("| ");
}

void PrintMid(AddressOfPetak PAcc, AddressOfPetak PPos, TabInt T)
{
	PrintOwner(PAcc);
	printf("                                                                     |");
	PrintOwner(PPos);
	printf("\n|");
	PrintPosition(PAcc,T);
	printf("                                                                    | ");
	PrintPosition(PPos,T);
	printf("\n");
}

void PrintBoard(ListPetak L, ListPlayer P)
// cetak peta board
{
	AddressOfPetak PPos, PAcc;
	AddressOfPlayer PPlay;
	int A,B,C,D;
	int i, eff;
	TabInt T;
	
	printf(" __________________________________________________________________________________________\n");
	printf("|  Start  | Beijing |  Bonus  | Jakarta |  Ancol  | Taipei  |New Delhi|  Seoul  |Deserted |\n");
	printf("|         |  120K   |         |  100K   |  160K   |   90K   |  100K   |  150K   |Island   |\n");
	PAcc = Next(First(L));
	while (Info(PAcc).id_petak != 9)
	{
		PrintOwner(PAcc);
		PAcc = Next(PAcc);
	}
	printf("         |\n|");
	PPlay = First(P);
	i = 0; T.eff = 0;
	while (PPlay != Nil)
	{
		PPos = Info(PPlay).posisi;
		T.T[i] = Info(PPos).id_petak;
		PPlay = Next(PPlay);
		T.eff = T.eff + 1;
		i = i + 1;
	}
	PPos = First(L);
	while (Info(PPos).id_petak != 10)
	{
		PrintPosition(PPos,T);
		PPos = Next(PPos);
	}
	printf("\n");
	
	printf("|_________________________________________________________________________________________|\n");
	printf("| Bangkok |                                                                     | Hawaii  |\n");
	printf("|  200 K  |                                                                     |  200K   |\n|");
	PAcc = PPos;
	while (Info(PAcc).id_petak != 32)
		PAcc = Next(PAcc);
	PrintMid(PAcc,PPos,T);
	PPos = Next(PPos);
	
	printf("|__________                                                                     __________|\n");
	printf("|   Tax   |                                                                     | Tokyo   |\n");
	printf("|         |                                                                     |  200K   |\n|");
	PAcc = PPos;
	while (Info(PAcc).id_petak != 31)
		PAcc = Next(PAcc);
	printf("|         |                                                                     |");
	PrintOwner(PPos);
	printf("\n| ");
	PrintPosition(PAcc,T);
	printf("                                                                    | ");
	PrintPosition(PPos,T);
	printf("\n");
	PPos = Next(PPos);
	
	printf("|__________                                                                     __________|\n");
	printf("|New York |                                                                     |  Sydney  |\n");
	printf("|  300 K  |                                                                     |   200K   |\n|");
	PAcc = PPos;
	while (Info(PAcc).id_petak != 30)
		PAcc = Next(PAcc);
	PrintMid(PAcc,PPos,T);
	PPos = Next(PPos);
	
	printf("|__________                                                                     ___________|\n");
	printf("| Chance  |                                                                     |  Chance  |\n");
	printf("|         |                                                                     |          |\n|");
	PAcc = PPos;
	while (Info(PAcc).id_petak != 29)
		PAcc = Next(PAcc);
	printf("|         |                                                                     |          |\n| ");
	PrintPosition(PAcc,T);
	printf("                                                                    | ");
	PrintPosition(PPos,T);
	printf("\n");
	PPos = Next(PPos);
		
	printf("|__________                                                                     ___________|\n");
	printf("|  Paris  |                                                                     |Singapura |\n");
	printf("|  190 K  |                                                                     |   100K   |\n|");
	PAcc = PPos;
	while (Info(PAcc).id_petak != 28)
		PAcc = Next(PAcc);
	PrintMid(PAcc,PPos,T);
	PPos = Next(PPos);
	
	printf("|__________                                                                     ___________|\n");
	printf("| London  |                                                                     | Senggigi |\n");
	printf("|  210 K  |                                                                     |   160K   |\n|");
	PAcc = PPos;
	while (Info(PAcc).id_petak != 27)
		PAcc = Next(PAcc);
	PrintMid(PAcc,PPos,T);
	PPos = Next(PPos);
	
	printf("|__________                                                                     ___________|\n");
	printf("|  Kuta   |                                                                     |Sao Paolo |\n");
	printf("|  200 K  |                                                                     |   200K   |\n|");
	PAcc = PPos;
	while (Info(PAcc).id_petak != 26)
		PAcc = Next(PAcc);
	PrintMid(PAcc,PPos,T);
	PPos = Next(PPos);
	
	printf("|__________________________________________________________________________________________|\n");
	printf("| World   |  Rome   | Moscow  | Geneva  | Chance  | Berlin  | Bintan  | Denmark | World    |\n");
	printf("| Travel  |  200K   |  150K   |  150K   |         |  220K   |  150K   |  200K   | Cup      |\n");
	PAcc = PPos;
	while (Info(PAcc).id_petak != 24)
	{
		PAcc = Next(PAcc);
	}
	PrintOwner(PAcc);
	PAcc = PPos;
	while (Info(PAcc).id_petak != 23)
	{
		PAcc = Next(PAcc);
	}
	PrintOwner(PAcc);
	PAcc = PPos;
	while (Info(PAcc).id_petak != 22)
	{
		PAcc = Next(PAcc);
	}
	PrintOwner(PAcc);
	printf("         |");
	PAcc = PPos;
	while (Info(PAcc).id_petak != 20)
	{
		PAcc = Next(PAcc);
	}
	PrintOwner(PAcc);
	PAcc = PPos;
	while (Info(PAcc).id_petak != 19)
	{
		PAcc = Next(PAcc);
	}
	PrintOwner(PAcc);
	PAcc = PPos;
	while (Info(PAcc).id_petak != 18)
	{
		PAcc = Next(PAcc);
	}
	PrintOwner(PAcc);
	printf("         |\n|");
	PAcc = PPos;
	while (Info(PPos).id_petak != 25)
	{
		PPos = Next(PPos);
	}
	PrintPosition(PPos,T);
	PAcc = PPos;
	while (Info(PPos).id_petak != 24)
	{
		PPos = Next(PPos);
	}
	PrintPosition(PPos,T);
	PAcc = PPos;
	while (Info(PPos).id_petak != 23)
	{
		PPos = Next(PPos);
	}
	PrintPosition(PPos,T);
	PAcc = PPos;
	while (Info(PPos).id_petak != 22)
	{
		PPos = Next(PPos);
	}
	PrintPosition(PPos,T);
	printf("        | ");
	PAcc = PPos;
	while (Info(PPos).id_petak != 20)
	{
		PPos = Next(PPos);
	}
	PrintPosition(PPos,T);
	PAcc = PPos;
	while (Info(PPos).id_petak != 19)
	{
		PPos = Next(PPos);
	}
	PrintPosition(PPos,T);
	PAcc = PPos;
	while (Info(PPos).id_petak != 18)
	{
		PPos = Next(PPos);
	}
	PrintPosition(PPos,T);
	PAcc = PPos;
	while (Info(PPos).id_petak != 17)
	{
		PPos = Next(PPos);
	}
	PrintPosition(PPos,T);
	printf("\n");
	printf("|__________________________________________________________________________________________|\n");
}

// HARGA PETAK (untuk hitungaset)

int hargapetak(AddressOfPetak P)
// Menghitung harga petah (bangunan dan harga dasar)
{
    return Harga_Dasar(P) + (Level(P) - 1)*(Level(P))*Biaya_Upgrade(P) ;
}



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
    tempat_wisata.TabKata[9] = 's';
    tempat_wisata.TabKata[10] = 'a';
    tempat_wisata.TabKata[11] = 't';
    tempat_wisata.TabKata[12] = 'a';
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
    harga = (int) Level(p)*(Level(p)-1)/2*Biaya_Upgrade(p) + Harga_Dasar(p);
    harga = (int) 9/10*harga;

    return harga;
}

void BeliPetak()
// membeli petak dari bank
{
    AddressOfPetak p;

    p = Info(global.currentPlayer).posisi;

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
        if (Infouang(global.currentPlayer) < Harga_Dasar(p))
        {
            printf("Uang anda tidak mencukupi untuk membeli petak ini\n");
        }
        else
        {
            Infouang(global.currentPlayer) -= Harga_Dasar(p);
            Pemilik(p) = Infoid(global.currentPlayer);
            AddKota(&Info(global.currentPlayer), Nama_Petak(p));
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

    p = Info(global.currentPlayer).posisi;
    if (global.currentWorldCup == p)
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

    P = Info(global.currentPlayer).posisi;
    p = Info(global.currentPlayer).posisi;
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
    if(Blackout(Info(global.currentPlayer).posisi))
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

    p = Info(global.currentPlayer).posisi;
    sewa = (int) Biaya_Sewa(p) * Multiplier_Sewa(p) * WorldCupMultiplier(p) * BlokMultiplier(p) * BlackoutMultiplier(p);

    return sewa;
}

//BELI PAKSA

int HargaBeliPaksa()
// ouput harga beli paksa
{
    int harga;
    AddressOfPetak p;

    p = Info(global.currentPlayer).posisi;
    harga = (int) Level(p)*(Level(p)-1)/2*Biaya_Upgrade(p) + Harga_Dasar(p);

    return harga*2;
}

void BeliPaksa()
//Eksekusi beli paksa
{
    AddressOfPetak p;
    AddressOfPlayer P;

    p = Info(global.currentPlayer).posisi;
    P = SearchidPlayer(global.listOfPlayer, Pemilik(p));

    if (Pemilik(p) == Infoid(global.currentPlayer))
    {
        printf("Petak ini adalah milik anda sendiri\n");
    }
    else if (Pemilik(p) == 0)
    {
        printf("Petak ini bukan milik player, anda tidak bisa membeli paksa petak ini\n");
    }
    else if (isTempatWisata(p))
    {
        printf("Petak yang bisa dibeli paksa hanya petak kota\n");
    }
    else if (Level(p) == 5)
    {
        printf("Petak ini tidak bisa dibeli karena sudah memiliki landmark\n");
    }
    else if (Infouang(global.currentPlayer) < HargaBeliPaksa())
    {
        printf("Uang anda tidak mencukupi untuk membeli petak ini\n");
    }
    else
    {
        Infouang(global.currentPlayer) -= HargaBeliPaksa();
        Infouang(P) += HargaBeliPaksa();

        DelKota(&((*P).info), Nama_Petak(p));
        AddKota(&Info(global.currentPlayer), Nama_Petak(p));

        Pemilik(p) = Infoid(global.currentPlayer);
        Harga_Jual(p) = -1;

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

    owner = SearchidPlayer(global.listOfPlayer, Pemilik(Info(global.currentPlayer).posisi));

    if (owner == global.currentPlayer)
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
        Infouang(global.currentPlayer) -= HargaSewa();
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

    if (isMemberAOI(Info(global.currentPlayer).idKartu, 1))
    {
        DeleteAOI(&Info(global.currentPlayer).idKartu, 1);
        printf("Anda memiliki kartu bebas pajak\n");
        printf("Anda tidak perlu membayar pajak\n");
        printf("Anda telah menggunakan satu kartu bebas pajak anda\n");
    }
    else
    {
        tax = (int) HitungHartaPlayer(Info(global.currentPlayer))/10;
        Infouang(global.currentPlayer) -= tax;
        printf("Anda membayar tax sebesar %i\n", tax);
    }
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
    Infouang(global.currentPlayer) += bonus[random];
    printf("Anda mendapat bonus sebesar %i\n", bonus[random]);
}

//====================================================================================start

void ExecuteStart()
//Mengeksekusi apa yang harus dilakukan jika berhenti/melewati petak start
{
    int valstart;
    AddressOfPetak p;

    valstart = 200000;
    Infouang(global.currentPlayer) += valstart;
    printf("Anda melewati start\n");
    printf("Anda mendapatkan uang sebesar %i", valstart);
    p = FirstPetak(global.listOfPetak);
    do
    {
        if (Pemilik(p) == Infoid(global.currentPlayer) && Blackout(p))
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
            printf("Harga\t\t: %i\n", Harga_Dasar(p));
        }
        else
        {
            P = SearchidPlayer(global.listOfPlayer, Pemilik(p));
            PrintKata((*P).info.nama);
            printf("\n");
            printf("Harga Beli Paksa\t: %i\n", 2*hargapetak(p));
        }
    }
}
//======================================================================================buy

void Buy()
{
    if (Info(global.currentPlayer).penjara)
    {
        printf("Anda tidak bisa menggunakan command ini saat sedang dipenjara\n");
    }
    else if (Pemilik(Info(global.currentPlayer).posisi) == 0)
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
    AddressOfPetak p;

    p = SearchPetak(global.listOfPetak, namapetak);
    if (p == Nil)
    {
        printf("Tidak ada petak bernama ");
        PrintKata(namapetak);
        printf(" pada board\n");
    }
    else if(Pemilik(p) == Infoid(global.currentPlayer))
    {
        Harga_Jual(p) = hargapetak(p);
        printf("Petak berhasil dimasukkan ke dalam daftar offered dengan harga %i\n", hargapetak(p));
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
    else if(Pemilik(p) == Infoid(global.currentPlayer))
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
    else if (Pemilik(p) != Infoid(global.currentPlayer))
    {
        printf("Petak bukan milik anda, anda hanya bisa menjual petak milik sendiri\n");
    }
    else
    {
        Pemilik(p) = 0;
        DelKota(&Info(global.currentPlayer), Nama_Petak(p));
        Infouang(global.currentPlayer) += HargaJualKeBank(Nama_Petak(p));
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


    if (Info(global.currentPlayer).penjara)
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
    else if (Pemilik(p) == Infoid(global.currentPlayer))
    {
        printf("Petak ini adalah milik anda sendiri\n");
    }
    else if (Infouang(global.currentPlayer) < Harga_Jual(p))
    {
        printf("Uang anda tidak mencukupi untuk membeli petak ini\n");
    }
    else
    {
        P = SearchidPlayer(global.listOfPlayer, Pemilik(p));

        Infouang(global.currentPlayer) -= Harga_Jual(p);
        Infouang(P) += Harga_Jual(p);

        DelKota(&((*P).info), Nama_Petak(p));
        AddKota(&Info(global.currentPlayer), Nama_Petak(p));

        Pemilik(p) = Infoid(global.currentPlayer);
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

    p = Info(global.currentPlayer).posisi;

    if (Info(global.currentPlayer).penjara)
    {
        printf("Anda tidak bisa menggunakan command ini saat sedang dipenjara\n");
    }
    else if (Pemilik(p) != Infoid(global.currentPlayer))
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


        if (Infouang(global.currentPlayer) < harga)
        {
            printf("Uang anda tidak mencukupi untuk ungrade bangunan\n");
        }
        else
        {
            Level(p)++;
            Infouang(global.currentPlayer) -= harga;
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

    if (Info(global.currentPlayer).penjara)
    {
        printf("Anda tidak bisa menggunakan command ini saat sedang dipenjara\n");
    }
    else if (!IsKataSama(Jenis_Petak(Info(global.currentPlayer).posisi),world_cup))
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
        else if (Pemilik(SearchPetak(global.listOfPetak, namapetak)) != Infoid(global.currentPlayer))
        {
            printf("Anda hanya bisa menunjuk petak milik anda untuk menjadi petak World Cup\n");
        }
        else if (!isKota(SearchPetak(global.listOfPetak, namapetak)))
        {
            printf("Anda hanya bisa menunjuk petak kota untuk menjadi petak World Cup\n");
        }
        else
        {
            global.currentWorldCup = SearchPetak(global.listOfPetak, namapetak);
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

    if (Info(global.currentPlayer).penjara)
    {
        printf("Anda tidak bisa menggunakan command ini saat sedang dipenjara\n");
    }
    else if (!IsKataSama(Jenis_Petak(Info(global.currentPlayer).posisi), world_travel))
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
            Info(global.currentPlayer).posisi = SearchPetak(global.listOfPetak, namapetak);
            printf("Anda telah melakukan world travel ke petak ");
            PrintKata(namapetak);
            printf("\n");
        }
    }
}

int NbElmtPetak (ListPetak L)
//Mengembalikan banyaknya pemain
{
    AddressOfPetak P=First(L);
    int cnt=0;
    while (P!=Nil)
    {
        cnt++;
    }
    return cnt;
}
