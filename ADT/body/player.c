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

void InsVLast (ListPlayer *L, InfoPlayer X)
/*	I.S. L mungkin kosong
	F.S. X ditambahkan sebagai elemen terakhir L
	Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
	elemen terakhir yang baru bernilai X jika alokasi berhasil.
	Jika alokasi gagal: I.S.= F.S.
*/
{
    AddressOfPlayer P=Alokasi(X);
    InsertLast(&*L,P);
}

void InsertFirst (ListPlayer *L, AddressOfPlayer P)
/*	I.S. Sembarang, P sudah dialokasi
	F.S. Menambahkan elemen ber-Address P sebagai elemen pertama
*/
{
    Next(P) = First(*L) ;
    First(*L) = P;
}
void InsertAfter (ListPlayer *L, AddressOfPlayer P, AddressOfPlayer Prec)
/*	I.S. Prec pastilah elemen list dan bukan elemen terakhir,
	P sudah dialokasi
	F.S. Insert P sebagai elemen sesudah elemen beralamat Prec
*/
{
    Next(P)=Next(Prec);
    Next(Prec)=P;
}
void InsertLast (ListPlayer *L, AddressOfPlayer P)
/*	I.S. Sembarang, P sudah dialokasi
	F.S. P ditambahkan sebagai elemen terakhir yang baru
*/
{
    if (IsLPlayerEmpty(*L)){
        InsertFirst(&*L,P);
    }
    else
    {
        AddressOfPlayer Last=First(*L);
        while (Next(Last)!=Nil){
            Last=Next(Last);
        }
        InsertAfter(&*L,P,Last);
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
	if (IsLPlayerEmpty(L))
	{
		return Nil;
	}
	else
	{
		AddressOfPlayer P=First(L);
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
	if (X.penjara==true)
		return true;
	else
		return false;
}

void MasukPenjara (InfoPlayer *X, ListPetak L)
/*Memasukkan pemain kedalam penjara karena mendapatkan kartu chance*/
{
	(*X).penjara=true;
	LompatKe(&*X,SearchPetakByID(L,9));
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
	int i,sum=X.uang;
	AddressOfPetak P;
	for (i=0;i<NbElmtAOK(X.kota);i++)
	{
		P=SearchPetak(global.listOfPetak,X.kota.T[i]);
		sum+=hargapetak(P);
	}
	return sum;
}

void MajuNLangkah (InfoPlayer *X, ListPetak L, int N)
/*Mengubah posisi pemain sebanyak N langkah kedepan.
 Jumlah langkah tergantung dari roll dadu (N>=2 dan N<=12). */
{
	int i;
	AddressOfPetak P=(*X).posisi;
	for (i=0;i<N;i++)
	{
		if (P==Nil)
			P=First(L);
		else
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

int NbElmt (ListPlayer L)
//Mengembalikan banyaknya pemain
{
	AddressOfPlayer P=First(L);
	int cnt=0;
	while (P!=Nil)
	{
		cnt++;
	}
	return cnt;
}
