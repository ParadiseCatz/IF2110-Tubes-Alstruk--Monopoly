#include "../header/petak.h"
#include "../header/player.h"

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
	int i,N=X.nama.Length;
	Kata temp=X.nama;
	for (i=0;i<N;i++){
		printf("%c",temp.TabKata[i]);
	}
	printf("\n");
	printf("%d\n",X.uang);
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

void Add (ListPlayer *L, InfoPlayer X)
/*Menambahkan pemain ke ListPlayer ketika awal permainan. Jumlah pemain yang diperbolehkan
	yaitu N>=1 dan N<=7
*/
{

	AddressOfPlayer P=Alokasi(X);
	if (IsLPlayerEmpty(*L))
	{
		First(*L)=P;
		Next(First(*L))=Nil;
	}
	else
	{
		AddressOfPlayer last=First(*L);
		while (last!=Nil)
		{
			last=Next(last);
		}
		Next(last)=P;
		Next(Next(last))=Nil;
	}
}

void Del (ListPlayer *L, InfoPlayer *X, int id)
/*Menghapus pemain dari ListPlayer ketika pemain sudah kalah dalam permainan
 */
{
	AddressOfPlayer Prec, P;
    if (!IsLPlayerEmpty(*L))
    {
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
    }
}

AddressOfPlayer SearchPrec (ListPlayer L, int id)
/*Mencari Alamat sebelum alamat pemain dari ListPlayer. Pencarian dilakukan
	dengan menggunakan id player*/
{
	AddressOfPlayer Prec,P;
    P=First(L);
    Prec=Nil;
    if (IsLPlayerEmpty(L))
    {
        return Nil;
    }
    else
    {
        while (P!=Nil && Infoid(P)!=id)
        {
            Prec=P;
            P=Next(P);
        }
        if (Infoid(P)==id)
            return Prec;
        else
            return Nil;
    }
}

AddressOfPlayer SearchidPlayer (ListPlayer L, int id)
/*Mencari Alamat pemain dari ListPlayer. Pencarian dilakukan
	dengan menggunakan id player*/
{
	AddressOfPlayer P;
	P=First(L);
	if (IsLPlayerEmpty(L))
	{
		return Nil;
	}
	else
	{
		while (P!=Nil && Infoid(P)!=id)
		{
			P=Next(P);
		}
		if (Infoid(P)==id)
			return P;
		else
			return Nil;
	}
}

boolean IsPenjara (InfoPlayer X)
/*Mengecek apakah pemain ada di penjara atau tidak*/
{
	return X.penjara==1;
}

void MasukPenjara (InfoPlayer *X, ListPetak L)
/*Memasukkan pemain kedalam penjara karena mendapatkan kartu chance*/
{
	(*X).penjara=1;
	Kata namapetak;
	AddressOfPetak P = SearchPetak(L, namapetak);
	(*X).posisi=P;
}

void KeluarPenjara (InfoPlayer *X)
/*Mengeluarkan pemain dari penjara karena menggunakan kartu bebas penjara*/
{
	if (IsPenjara(*X)){
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
	}
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
	return X.uang;
}

void MajuNLangkah (InfoPlayer *X, ListPetak L, int N)
/*Mengubah posisi pemain sebanyak N langkah kedepan.
 Jumlah langkah tergantung dari roll dadu (N>=2 dan N<=12). */
{
	int i;
	AddressOfPetak P=(*X).posisi;
	for (i=0;i<4;i++)
	{
		if (P==Nil)
			P=First(L);
		P=Next(P);
	}
	(*X).posisi=P;
}

void LompatKe (InfoPlayer *X, AddressOfPetak Pt)
/*Mengubah posisi pemain menuju ke petak 'pt' karena berhenti di world travel*/
{
	(*X).posisi=Pt;
}
void AddKota (InfoPlayer *X, Kata K)
/*Menambahkan aset pemain. Kota dapat diperoleh dengan cara membeli dari bank
 atau membeli paksa dari pemain lain.*/
{
	AddAOK(&(*X).kota,K);
}

void DelKota (InfoPlayer *X, Kata K)
/*Menghapus aset pemain karena menjual kota ke bank maupun kota dibeli paksa oleh
 pemain lain.*/
{
	DeleteAOK(&(*X).kota,K);
}

boolean IsMember (InfoPlayer X, Kata K)
/*Mengecek apakah sebuah kota tertentu telah dimiliki oleh pemain*/
{
	return (isMemberAOK(X.kota,K));
}

