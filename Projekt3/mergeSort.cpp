#include "mergeSort.h"

void sortowanie::scalanie(int tab[], int lewa, int srodek, int prawa) {
	int indeksLewa = lewa;   // <--- Poczatek lewej czesci tablicy
	int indeksPrawa = srodek + 1;   // <--- Poczatek prawej czesci tablicy
	int indeksPosortowany = lewa;   // <--- Miejsce w tablicy, gdzie wstawimy posortowany element
	int rozmiarLewegoPodzbioru = srodek - lewa + 1;   // <--- Rozmiar lewej czesci
	int rozmiarPrawegoPodzbioru = prawa - srodek;   // <--- Rozmiar prawej czesci
	int* lewyPodzbior = new int[rozmiarLewegoPodzbioru];   // <--- Pomocnicza tablica dla lewej czesci
	int* prawyPodzbior = new int[rozmiarPrawegoPodzbioru];   // <--- Pomocnicza tablica dla prawej czesci
	for (int j = 0; j < rozmiarLewegoPodzbioru; j++) {
		lewyPodzbior[j] = tab[lewa + j];   // <--- Kopiowanie lewej czesci do lewego podzbioru
	}
	for (int j = 0; j < rozmiarPrawegoPodzbioru; j++) {
		prawyPodzbior[j] = tab[srodek + 1 + j];   // <--- Kopiowanie prawej czesci do prawego podzbioru
	}
	/// Scalanie elementow z lewej oraz prawej czesci tablicy
	while (indeksLewa <= srodek && indeksPrawa <= prawa) {   // <--- Dopoki elementy sa w lewej czesci tablicy oraz w prawej
		int wartoscLewa = lewyPodzbior[indeksLewa - lewa];   // <--- Pobiera wartosc elementu z lewej tablicy
		int wartoscPrawa = prawyPodzbior[indeksPrawa - srodek - 1];   // <--- Pobiera wartosc elementu z prawej tablicy
		if (wartoscLewa <= wartoscPrawa) {   // <--- Jesli element z lewej jest mniejsz lub rowny prawemu
			tab[indeksPosortowany] = wartoscLewa;   // <--- Element z lewej wstawia do glownej tablicy
			indeksLewa++;   // <--- Przechodzi do kolejnego elementu w lewej tablicy
		}
		else {
			tab[indeksPosortowany] = wartoscPrawa;   // <--- W przeciwnym razie wstawia element z prawej czesci do glownej tablicy
			indeksPrawa++;   // <--- Przechodzi do kolejnego elementu w prawej tablicy
		}
		indeksPosortowany++;   // <--- Przechodzi do kolejnego elementu w glownej tablicy
	}
	while (indeksLewa <= srodek) {   // <--- Dopoki elementy sa w lewej czesci tablicy
		tab[indeksPosortowany++] = lewyPodzbior[indeksLewa - lewa];   // <--- Przenosimy elementy, ktore pozostaly w lewej czesci tablicy
		indeksLewa++;   // <--- Przechodzimy do nastepnego elementu w lewej czesci
	}
	while (indeksPrawa <= prawa) {   // <--- Dopoki elementy sa w prawej czesci tablicy
		tab[indeksPosortowany++] = prawyPodzbior[indeksPrawa - srodek - 1];   // <--- Przenosimy elementy, ktore pozostaly w prawej czesci tablicy
		indeksPrawa++;   // <--- Przechodzimy do nastepnego elementu w prawej czesci
	}
	delete[] lewyPodzbior;   // <--- Zwolnienie pamieci dla pomocniczej tablicy lewej
	delete[] prawyPodzbior;   // <--- Zwolnienie pamieci dla pomocniczej tablicy prawej
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