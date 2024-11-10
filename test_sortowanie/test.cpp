#include "pch.h"
#include "../Projekt3/mergeSort.cpp"

TEST(Sortowanie_przez_scalanie, Niezmieniona) {
	int tab[] = { 1, 5, 8, 12, 15, 29, 44 };
	int n = 7;
	sortowanie sort;
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	int tab_oczekiwana[] = { 1, 5, 8, 12, 15, 29, 44 };
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(tab[i], tab_oczekiwana[i]);
	}
}

TEST(Sortowanie_przez_scalanie, Sortowanie_Odwrotniej_Kolejnosci) {
	int tab[] = { 44, 29, 15, 12, 8, 5, 1 };
	int n = 7;
	sortowanie sort;
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	int tab_oczekiwana[] = { 1, 5, 8, 12, 15, 29, 44 };
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(tab[i], tab_oczekiwana[i]);
	}
}