#include "../header/kata.h"

int Size(Kata K)
{
	return K.Length;
}

void Copy(Kata in, Kata *out)
{
	// Kamus Lokal
	int i;
	// Algoritma
	(*out).Length = in.Length;
	for(i=0; i<in.Length; i++)
	{
		(*out).TabKata[i] = in.TabKata[i];
	}
}

boolean IsKataSama(Kata K1, Kata K2)
{
	// Kamus Lokal
	int i;
	// Algoritma
	if(K1.Length == K2.Length)
	{
		i = 0;
		while(i < K1.Length-1 && K1.TabKata[i] == K2.TabKata[i]) i++;

		return (K1.TabKata[i] == K2.TabKata[i]);
		
	}
	else return false;
}

void BacaKata(Kata *K)
{
	Kata tmp;
	scanf("%s",&tmp.TabKata);
	tmp.Length = strlen(tmp.TabKata);
	
	*K = tmp;
}

void PrintKata(Kata K)
{
	// Kamus Lokal
	int i;
	// Algoritma
	for(i=0; i<K.Length; i++)
	{
		printf("%c", K.TabKata[i]);
	}
	printf("\n");
}

int KataToInt(Kata K)
{
	// Kamus Lokal
	int i, res;
	boolean sign;
	// Algoritma
	sign = false; i = 0; res = 0;
	if(K.TabKata[i] == '-')
	{
		i++; sign = true;
	}
	for(; i<K.Length; i++)
	{
		res = (res*10) + (K.TabKata[i]-'0');
	}
	if(sign) return -res;
	else return res;
}

double KataToDouble(Kata K)
{
	// Kamus Lokal
	int i, counter;
	boolean sign;
	double res;
	// Algoritma
	sign = false; i = 0; res = 0.0;
	if(K.TabKata[i] == '-')
	{
		i++; sign = true;
	}
	for(; i<K.Length && K.TabKata[i] != '.'; i++)
	{
		res = (res*10.0) + (K.TabKata[i]-'0');
	}
	i++; counter = 0;
	for(; i<K.Length; i++)
	{
		res = (res*10.0) + (K.TabKata[i]-'0');
		counter++;
	}
	for(i=0; i<counter; i++) res /= 10.0;
	
	if(sign) return -res;
	else return res;
}

char KataToChar(Kata K)
{
	return K.TabKata[0];
}
