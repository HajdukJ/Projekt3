#include <iostream>
#include "mergeSort.h"

void sortowanie::scalanie(int tab[], int lewa, int srodek, int prawa) {
	int x = lewa;
	int y = srodek + 1;
	int i = lewa;
	int* pomocnicza = new int[prawa - lewa + 1];   // <--- Pomocnicza tablica, ktora bedzie przechowywac elementy do posortowania
	for (int j = lewa; j <= prawa; j++) {
		pomocnicza[j - lewa] = tab[j];
	}
	while (x <= srodek) {
		if (y > prawa) {
			tab[i++] = pomocnicza[x - lewa];
			x++;
		}
		else if (pomocnicza[x - lewa] <= pomocnicza[y - lewa]) {
			tab[i++] = pomocnicza[x - lewa];
			x++;
		}
		else {
			tab[i++] = pomocnicza[y - lewa];
			y++;
		}
	}
	while (y <= prawa) {
		tab[i++] = pomocnicza[y - lewa];
		y++;
	}
	delete[] pomocnicza;   // <--- Zwolnienie pamieci dla pomocniczej tablicy
};
void sortowanie::sortowanie_przez_scalanie(int tab[], int lewa, int prawa) {
	if (lewa >= prawa) {   // <--- Jesli nie ma juz elementow do sortowania, zawiera tylko jeden element
		return;   // <--- Zakoncz dzialanie 
	}
	int srodek;
	srodek = (prawa + lewa) / 2;   // <--- Wyliczanie srodka w tablicy, by podzielic ja na dwie mniejsze czesci
	sortowanie_przez_scalanie(tab, lewa, srodek);   // <--- Rekurencyjnie sortuje lewa czesc
	sortowanie_przez_scalanie(tab, srodek + 1, prawa);   // <--- Rekurencyjnie sortuje prawa czesc
	scalanie(tab, lewa, srodek, prawa);   // <--- Scala obie posortowane czesci w porzadku rosnacym
};