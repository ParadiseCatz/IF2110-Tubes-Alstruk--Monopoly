#include "../header/petak.h"
#include "../header/player.h"
#include "../header/cards.h"

void CreateEmptyLPlayer (ListPlayer *L)
//membuat ListOfPlayer
{
	First(*L)=Nil;
}

boolean IsLPlayerEmpty (ListPlayer L)
//mengecek apakah List kosong
{
	return (First(L)==Nil);
}

void PrintElmtPlayer (InfoPlayer X)
//Mencetak informasi dari suatu pemain
{
    printf("======================== "); PrintKata(X.nama); printf(" ========================"); puts("");
	printf("Nama\t\t\t: "); PrintKata(X.nama); puts("");
	printf("ID Player\t\t: "); printf("%d",X.id); puts("");
	printf("Uang\t\t\t: "); printf("%d",X.uang); puts("");
	printf("Kartu yang dimiliki\t: "); PrintAOI(X.idKartu); 
	printf("Petak yang dimiliki\t: "); PrintAOK(X.kota);
}

AddressOfPlayer Alokasi (InfoPlayer X)
//Alokasi
{
	AddressOfPlayer P = (AddressOfPlayer)malloc(sizeof(ElmtPlayer));
	if (P!=Nil)
	{
		Info(P)=X;
		Next(P)=Nil;
	}
	return P;
}

void Dealokasi(AddressOfPlayer *P)
//Dealokasi
{
	free(*P);
}

void InsVLast (ListPlayer *L, InfoPlayer X)
/*	I.S. L mungkin kosong
	F.S. X ditambahkan sebagai elemen terakhir L
	Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
	elemen terakhir yang baru bernilai X jika alokasi berhasil.
	Jika alokasi gagal: I.S.= F.S.
*/
{
    AddressOfPlayer P=Alokasi(X);
    InsertLast(L,P);
}

void InsertFirst (ListPlayer *L, AddressOfPlayer P)
/*	I.S. Sembarang, P sudah dialokasi
	F.S. Menambahkan elemen ber-Address P sebagai elemen pertama
*/
{
	if(IsLPlayerEmpty(*L))
	{
		First(*L) = P;
		Next(P) = P;
	}
	else
	{
		Next(P) = First(*L) ;
    	First(*L) = P;
	}
}
void InsertAfter (ListPlayer *L, AddressOfPlayer P, AddressOfPlayer Prec)
/*	I.S. Prec pastilah elemen list dan bukan elemen terakhir,
	P sudah dialokasi
	F.S. Insert P sebagai elemen sesudah elemen beralamat Prec
*/
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (ListPlayer *L, AddressOfPlayer P)
/*	I.S. Sembarang, P sudah dialokasi
	F.S. P ditambahkan sebagai elemen terakhir yang baru
*/
{
    if (IsLPlayerEmpty(*L)){
        InsertFirst(L,P);
    }
    else
    {
        AddressOfPlayer Last=First(*L);
        while (Next(Last)!=First(*L))
        {
            Last=Next(Last);
        }
        Next(Last) = P;
        Next(P) = First(*L);
    }
}

void Del (ListPlayer *L, InfoPlayer *X, int id)
/*Menghapus pemain dari ListPlayer ketika pemain sudah kalah dalam permainan
 */
{
	AddressOfPlayer Prec, P;
    if (!IsLPlayerEmpty(*L))
    {
    	if(NbElmtPlayer(*L) == 1)
    	{
    		P = First(*L);
    		if(Info(P).id == id)
    		{
    			*X = Info(P);
    			Next(P) = Nil;
    			First(*L) = Nil;
    			Dealokasi(&P);
    		}
    	}
    	else
    	{
    		P = SearchidPlayer(*L, id);
    		if(P == Nil) return;

    		Prec = SearchPrec(*L, id);
    		Next(Prec) = Next(P);
    		if(First(*L) == P) First(*L) = Next(P);
    		Next(P) = Nil;
    		Dealokasi(&P);
    	}
    	/*
        if (id == Infoid(First(*L)))
        {
            P = First(*L);
            *X = Info(First(*L));
            First(*L) = Next(First(*L));
            Dealokasi(&P);
        }
        else
        {
            Prec = SearchPrec(*L,id);
            if (Infoid(Next(Prec))==id)
            {
                P = Next(Prec);
                Next(Prec) = Next(Next(Prec));
                *X=Info(P);
                Dealokasi(&P);
            }
        }
        */
    }
}

AddressOfPlayer SearchPrec (ListPlayer L, int id)
/*Mencari Alamat sebelum alamat pemain dari ListPlayer. Pencarian dilakukan
	dengan menggunakan id player*/
{
	AddressOfPlayer P = SearchidPlayer(L, id);
	if(P == Nil) return Nil;
	AddressOfPlayer Prec = First(L);
	while(Next(Prec) != P)
	{
		Prec = Next(Prec);
	}
	return Prec;
}

AddressOfPlayer SearchidPlayer (ListPlayer L, int id)
/*Mencari Alamat pemain dari ListPlayer. Pencarian dilakukan
	dengan menggunakan id player*/
{
	if (IsLPlayerEmpty(L))
	{
		return Nil;
	}
	else
	{
		AddressOfPlayer P = First(L);
		boolean Found = false;
		do
		{
			if(Info(P).id == id) Found = true;
			else P = Next(P);
		}
		while(P != First(L) && !Found);

		if(Found) return P;
		else return Nil;
	}
}


AddressOfPlayer SearchByName (ListPlayer L, Kata name)
/*Mencari Alamat pemain dari ListPlayer. Pencarian dilakukan
	dengan menggunakan id player*/
{
	if (IsLPlayerEmpty(L))
	{
		return Nil;
	}
	else
	{
		AddressOfPlayer P = First(L);
		boolean Found = false;
		do
		{
			if(IsKataSama(Info(P).nama, name)) Found = true;
			else P = Next(P);
		}
		while(P != First(L) && !Found);

		if(Found) return P;
		else return Nil;
	}
}

boolean IsPenjara (InfoPlayer X)
/*Mengecek apakah pemain ada di penjara atau tidak*/
{
	if (X.penjara==true)
		return true;
	else
		return false;
}

void MasukPenjara (InfoPlayer *X, ListPetak L)
/*Memasukkan pemain kedalam penjara karena mendapatkan kartu chance*/
{
	(*X).penjara=true;

	AddressOfPetak P = SearchPetakByID(L,9);
	LompatKe(X, P);
	printf("Anda masuk penjara\n");
}

void KeluarPenjara (InfoPlayer *X)
/*Mengeluarkan pemain dari penjara karena menggunakan kartu bebas penjara*/
{
	(*X).penjara = false;
	printf("Anda keluar dari penjara\n");
	/*if (IsPenjara(*X))
	{
		int i=0;
		boolean found=false;
		while (i<(*X).idKartu.Neff&&!found) //mencari apakah pemain punya kartu bebas penjara
		{
			if ((*X).idKartu.T[i]==2)
				found=true;
			else
				i++;
		}
		if (found) //jika punya maka akan ditanya apakah ingin menggunakan
		{
			char pil;
			printf("Anda memiliki kartu bebas penjara, gunakan ? (Y/N) : ");
			scanf("%c",&pil);
			if (pil=='Y'||pil=='y')
				(*X).penjara=0;
			else if (pil=='N'||pil=='n')
				(*X).penjara=1;
		}
	}*/
}

boolean isGetKartuPenjara (int X)
/*Mengecek apakah pemain mendapatkan kartu penjara atau tidak*/
{
	if (X==3)//misal 3 adalah id kartu penjara
		return true;
	else return false;
}

int HitungHartaPlayer (InfoPlayer X)
/*Menghitung semua aset milik pemain (uang+kota)*/
{
	int i, sum = X.uang;
	AddressOfPetak P;
	for (i=1; i<=NbElmtAOK(X.kota); i++)
	{
		P = SearchPetak(global.listOfPetak,X.kota.T[i]);
		sum += hargapetak(P);
	}
	return sum;
}

void MajuNLangkah (InfoPlayer *X, ListPetak L, int N)
/*Mengubah posisi pemain sebanyak N langkah kedepan.
 Jumlah langkah tergantung dari roll dadu (N>=2 dan N<=12). */
{
	int i;
	AddressOfPetak P = (*X).posisi;
	for(i=0; i<N; i++)
	{
		P = Next(P);
		if(Info(P).id_petak == 1) ExecuteStart();
	}

	(*X).posisi = P;
	printf("\nAnda melangkah dan sampai ke petak "); PrintKata(InfoPetak(P).nama_petak); puts("");
	if(Info(P).id_petak == 3) GetBonus();
	else if(Info(P).id_petak == 9) MasukPenjara(X, L);
	else if(Info(P).id_petak == 13 || Info(P).id_petak == 21 || Info(P).id_petak == 29) DrawCards();
	else if(Info(P).id_petak == 31) PayTax();
	else if(isKota(P) || isTempatWisata(P))
	{
		printf("Saat ini anda berada di:\n");
		PrintPetak(Info(Info(global.currentPlayer).posisi).nama_petak);
		BayarSewa();
	}
	else if (isWorldCup(P))
	{
		printf("Saat ini anda berada di Petak World Cup\n");
	}
	else if (isWorldTravel(P))
	{
		printf("Saat ini anda berada di Petak World Travel.\n");
	}

}

void LompatKe (InfoPlayer *X, AddressOfPetak Pt)
/*Mengubah posisi pemain menuju ke petak 'pt' karena berhenti di world travel*/
{
	(*X).posisi = Pt;
	if(Info(Pt).id_petak == 1) ExecuteStart();
	else if(Info(Pt).id_petak == 3) GetBonus();
	else if(Info(Pt).id_petak == 9) Info(global.currentPlayer).penjara = true;
	else if(Info(Pt).id_petak == 13 || Info(Pt).id_petak == 21 || Info(Pt).id_petak == 29) DrawCards();
	else if(Info(Pt).id_petak == 31) PayTax();
	else if(isKota(Pt) || isTempatWisata(Pt)) BayarSewa();
}
void AddKota (InfoPlayer *X, Kata K)
/*Menambahkan aset pemain. Kota dapat diperoleh dengan cara membeli dari bank
 atau membeli paksa dari pemain lain.*/
{
	AddAOK(&(*X).kota, K);
}

void DelKota (InfoPlayer *X, Kata K)
/*Menghapus aset pemain karena menjual kota ke bank maupun kota dibeli paksa oleh
 pemain lain.*/
{
	DeleteAOK(&(*X).kota, K);
}

boolean IsMember (InfoPlayer X, Kata K)
/*Mengecek apakah sebuah kota tertentu telah dimiliki oleh pemain*/
{
	return (isMemberAOK(X.kota,K));
}

int NbElmtPlayer (ListPlayer L)
//Mengembalikan banyaknya pemain
{
	if(IsLPlayerEmpty(L)) return 0;
	else
	{
		AddressOfPlayer P = First(L);
		int cnt = 0;
		do
		{
			cnt++;
			P = Next(P);
		} while(P != First(L));
		return cnt;
	}
	
}

int countTourismSpots(InfoPlayer X)
{
	int i, count=0;
	for(i=1; i<=NbElmtAOK(X.kota); i++)
	{
		Kata now = X.kota.T[i];
		AddressOfPetak P = SearchPetak(global.listOfPetak, now);
		if(isTempatWisata(P)) count++;
	}
	return count;
}

boolean IsTourismMonopoly(InfoPlayer X)
{
	if(countTourismSpots(X) >= 3) return true;
	else return false;
}

int countCompleteBlock(InfoPlayer X)
{
	int i, count=0;
	int cntHuruf[10];
	for(i=0; i<10; i++) cntHuruf[i] = 0;

	for(i=1; i<=NbElmtAOK(X.kota); i++)
	{
		Kata now = X.kota.T[i];
		AddressOfPetak P = SearchPetak(global.listOfPetak, now);
		char blokNow = Info(P).blok;

		if(blokNow != 'T')
		{
			cntHuruf[blokNow-'A']++;
		}
	}

	for(i=0; i<8; i++)
	{
		if((i == 0 || i == 3 || i == 6 || i == 7) && cntHuruf[i] == 2) count++;
		else if(((i == 1 || i == 2 || i == 4 || i == 5) && cntHuruf[i] == 3)) count++;
	}
	return count;
}

boolean IsTripleMonopoly(InfoPlayer X)
{
	return (countCompleteBlock(X) >= 3);
}

void PrintInfoPlayer(Kata K)
{
	if (SearchByName(global.listOfPlayer, K))
	{
		InfoPlayer X = Info(SearchByName(global.listOfPlayer, K));
		PrintElmtPlayer(X);
		return;
	}
	AddressOfPlayer P = Top(global.stackOfDefeated);
	while (P != Nil)
	{
		if (IsKataSama(Info(P).nama, K))
		{
			break;
		}
		P = Next(P);
	}
	if (P)
	{
		printf("Player ");
		PrintKata(Info(P).nama);
		printf(" sudah kalah\n");
	}
	else
	{
		printf("Tidak ada player ");
		PrintKata(K);
		printf("\n");
	}
}