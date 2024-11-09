#include <iostream>
#include "mergeSort.h"

void sortowanie::scalanie(int tab[], int lewa, int srodek, int prawa) {
	int x = lewa;
	int y = srodek + 1;
	int i = lewa;
	int* pomocnicza = new int[prawa - lewa + 1];
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
	delete[] pomocnicza;
};
void sortowanie::sortowanie_przez_scalanie(int tab[], int lewa, int prawa) {
	if (lewa >= prawa) {
		return;
	}
	int srodek;
	srodek = (prawa + lewa) / 2;
	sortowanie_przez_scalanie(tab, lewa, srodek);
	sortowanie_przez_scalanie(tab, srodek + 1, prawa);
	scalanie(tab, lewa, srodek, prawa);
};