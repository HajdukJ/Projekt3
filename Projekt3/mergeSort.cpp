#include <iostream>
#include "mergeSort.h"

void sortowanie::scalanie(int tab[], int lewa, int srodek, int prawa) {
	int x = lewa;   // <--- Poczatek lewej czesci tablicy
	int y = srodek + 1;   // <--- Poczatek prawej czesci tablicy
	int i = lewa;   // <--- Miejsce w tablicy, gdzie wstawimy posortowany element
	int* pomocnicza = new int[prawa - lewa + 1];   // <--- Pomocnicza tablica, ktora bedzie przechowywac elementy do posortowania
	for (int j = lewa; j <= prawa; j++) {
		pomocnicza[j - lewa] = tab[j];   // <--- Kopiowanie danych z tablicy do tablicy pomocniczej
	}
	/// Scalanie elementow z lewej oraz prawej czesci tablicy
	while (x <= srodek) {   // <--- Dopoki elementy sa w lewej czesci tablicy
		if (y > prawa) {   // <--- Jesli prawa czesc jest pusta
			tab[i++] = pomocnicza[x - lewa];   // <--- Przenosimy elementy z lewej czesci do glownej tablicy
			x++;   // <--- Nastepnie przechodzimy do nastepnego elementu w lewej czesci
		}
		else if (pomocnicza[x - lewa] <= pomocnicza[y - lewa]) {   // <--- Jesli element znajdujacy sie po lewej czesci jest mniejszy albo rowny prawemu
			tab[i++] = pomocnicza[x - lewa];   // <--- Przenosimy mniejszy element z lewej czesci tablicy do glownej
			x++;   // <--- Nastepnie przechodzimy do nastepnego elementu w lewej czesci
		}
		else {   // <--- W przeciwnym wypadku, jesli element z prawej czesci tablicy jest mniejszy 
			tab[i++] = pomocnicza[y - lewa];   // <--- Przenosimy ten mniejszy element z prawej czesci tablicy do glownej
			y++;   // <--- Przechodzimy do nastepnego elementu, ktory jest w prawej czesci
		}
	}
	while (y <= prawa) {   // <--- Dopoki elementy sa w prawej czesci tablicy
		tab[i++] = pomocnicza[y - lewa];   // <--- Przenosimy elementy, ktore pozostaly w prawej czesci tablicy
		y++;   // <--- Przechodzimy do nastepnego elementu w prawej czesci
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