#include "../header/reader.h"
#include "stdio.h"
void read_with_limit(int mins, int maks, int * in)
{
	scanf("%d", in);
	while ( (*in) < mins || (*in) > maks)
	{
		printf("Input salah, silahkan masukan lagi\n");
		scanf("%d", in);
	}
}
