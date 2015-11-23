#include "cards.h"

int main(){

	InfoKartu Ctemp;
	Deck Qtemp;
	*Hand *Htemp;
	int choice;
	
	printf("Masukkan pilihan : \n");
	printf("=================================");
	printf("1. Face-Down Position\n");
	printf("2. Activate Card\n");
	printf("3. Sell Card\n")
	printf("4. Buy Card\n");

	switch(choice){
		case '1' :
			break;
		case '2' :
			Dealokasi(Qtemp);

			GetID(Qtemp);

			switch(GetID(*Htemp)){


			}

			break;
		case '3' :
			break;
		case '4' :
			break:
		default :
			printf("Silahkan memasukkan pilihan 1, 2, 3, atau 4\n");
	}
	
	return 0;
}