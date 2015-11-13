#include "../header/kata.h"
#include "../body/kata.c"
#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	Kata K;
	BacaKata(&K);
	PrintKata(K);
	printf("Panjangnya : %d\n", Size(K));
	
	puts("\nTest Copy");
	Kata K1;
	Copy(K, &K1);
	puts("Copy Berhasil! Hasilnya :");
	PrintKata(K); PrintKata(K1); // PrintKata sudah menggunakan K1.Length
	
	puts("\nTest KataToInt");
	puts("Masukan integer :");
	BacaKata(&K);
	PrintKata(K);
	int res = KataToInt(K);
	printf("Hasil konversi : %d\n", res);
	
	puts("\nTest KataToDouble");
	puts("Masukan double :");
	BacaKata(&K);
	PrintKata(K);
	double resDouble = KataToDouble(K);
	printf("Hasil konversi : %.4lf\n", resDouble);
	
}
