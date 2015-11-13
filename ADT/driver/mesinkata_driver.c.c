#include "../header/mesinkata.h"
#include "../body/mesinkata.c"
#include "../header/mesinkarakter.h"
#include "../body/mesinkarakter.c"
#include "../header/kata.h"
#include "../body/kata.c"

int main()
{
	STARTKATA("../../data/dataPetak.txt");
	while(!EndKata)
	{
		PrintKata(CKata);
		ADVKATA();
	}
	return 0;
}
