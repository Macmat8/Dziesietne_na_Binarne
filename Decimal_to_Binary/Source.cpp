#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

#define DLC 40000
#define N 16

int dodawanie(int i, int* t1, int* t2, int miejsca, int liczba1, int liczba2)
{
	int g = 0;
	int r = 0;
	int* suma = NULL;
	suma = (int*)malloc(miejsca * sizeof(int));
	for (int i = 0; i <= miejsca; i++)
	{
		int s = 0;
		suma[i] = 0;
		s = t1[i] + t2[i] + r;
		if (s == 0)
		{
			suma[i] = 0;
			r = 0;
		}
		if (s == 1)
		{
			suma[i] = 1;
			r = 0;
		}
		if (s == 2)
		{
			suma[i] = 0;
			r = 1;
		}
		if (s == 3)
		{
			suma[i] = 1;
			r = 1;
		}
	}

	int result = (liczba1 + liczba2) >= 65536 ? g : suma[i];
	return result;
}

int odejmowanie(int i, int* t1, int* t2, int miejsca, int liczba1, int liczba2)
{
	int h = 0;
	int p = 0;
	int* roznica = NULL;
	roznica = (int*)malloc(miejsca*sizeof(int));
	for (int i = 0; i <= miejsca; i++)
	{
		int r = t1[i] - t2[i] + p;
		roznica[i] = 0;
		if (r == -1)
		{
			roznica[i] = 1;
			p = -1;
		}
		if (r == 0)
		{
			roznica[i] = 0;
			p = 0;
		}
		if (r == 1)
		{
			roznica[i] = 1;
			p = 0;
		}
	}
	int result = (liczba1 - liczba2) < 0 ? h : roznica[i];
	return result;
}

int main()
{
	int tab1[N] = { 0 };
	int tab2[N] = { 0 };
	srand(time(NULL));
	int i = 0;
	int k = 0;
	int j;
	unsigned int one = rand() % DLC;
	unsigned int two = rand() % DLC;
	printf("%d \n%d \n \n", one, two); //wypiuje liczby 1 i 2
	int pierw = one;
	int druga = two;
	while (one > 0)
	{
		tab1[i] = one % 2;
		i += 1;
		one = one / 2;
	}
	printf("Postac binarna %d to: ", pierw);
	for (j = i - 1; j >= 0; j--)
	{
		printf("%d", tab1[j]);
	}

	//zamiana pierwszej liczby dziesietnej na binarn¹

	printf("\n\n");

	while (two > 0)
	{
		tab2[k] = two % 2;
		k += 1;
		two = two / 2;
	}
	printf("Postac binarna %d to: ", druga);
	for (j = k - 1; j >= 0; j--)
	{
		printf("%d", tab2[j]);
	}
	//zamiana drugiej liczby na binarn¹
	int licznik;
	if (i > k)
	{
		licznik = i++;
	}
	else
	{
		licznik = k++;
	}
	printf("\n\n");

	int* tab3 = NULL;
	tab3 = (int*)malloc(licznik*sizeof(int));
	for (int j = 0; j <= licznik; j++)
	{
		tab3[j] = dodawanie(j, tab1, tab2, licznik, pierw, druga);
	}
	for (j = licznik; j >= 0; j--)
	{
		printf("%d", tab3[j]);
	}
	printf("\n\n");

	int* tab4 = NULL;
	tab4 = (int*)malloc(licznik*sizeof(int));
	for (int j = 0; j <= licznik; j++)
	{
		tab4[j] = odejmowanie(j, tab1, tab2, licznik, pierw, druga);
	}
	for (j = licznik; j >= 0; j--)
	{
		printf("%d", tab4[j]);
	}


	printf("\n\n");
	printf("Obliczamy:");
	printf("\n\n");

	int tab11[N] = { 0 };
	for (int j = 0; j <= licznik; j++)
	{
		tab11[j] = dodawanie(j, tab1, tab1, licznik, pierw, pierw);
	}

	int wynik1[N] = { 0 };
	int trzecia = pierw + pierw;
	for (int j = 0; j <= licznik; j++)
	{
		wynik1[j] = odejmowanie(j, tab11, tab2, licznik, trzecia, druga);
	}
	printf("Wynik dzialania t1 + t1 - t2 = ");
	for (j = licznik; j >= 0; j--)
	{
		printf("%d", wynik1[j]);
	}

	printf("\n\n");

	int tab12[N] = { 0 };
	for (int j = 0; j <= licznik; j++)
	{
		tab12[j] = odejmowanie(j, tab1, tab2, licznik, pierw, druga);
	}
	int wynik2[N] = { 0 };
	int czwarta = pierw - druga;
	for (int j = 0; j <= licznik; j++)
	{
		wynik2[j] = dodawanie(j, tab12, tab1, licznik, czwarta, pierw);
	}
	printf("Wynik dzialania t1 - t2 + t1 = ");
	for (j = licznik; j >= 0; j--)
	{
		printf("%d", wynik2[j]);
	}
	return 0;
}