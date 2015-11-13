#include "../header/mesinkarakter.h"
#include "../body/mesinkarakter.c"

int main()
{
	START("../../data/urutanPetak.txt");
	while(!EOP())
	{
		putchar(CC);
		ADV();
	}
	return 0;
}
