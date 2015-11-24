#include "cards.h"

int main(){

	InfoKartu Ctemp;
	Deck Qtemp;
	int choice;
	
	printf("Masukkan pilihan : \n");
	printf("=================================");
	printf("1. Face-Down Position\n");
	printf("2. Activate Card\n");

	switch(choice){
		case '1' :
			break;
		case '2' :
			Dealokasi(Qtemp);
			GetID(Qtemp);

			switch(GetID(*Htemp)){
				case '1':
					break;
				case '2':
					break;
				case '3':
					break;
				case '4':
					break;
				case '5':
					break;
			}

		default :
			printf("Silahkan memasukkan pilihan 1, 2, 3, atau 4\n");
	}
	
	return 0;
}