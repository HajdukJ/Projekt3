#include "pch.h"
#include "../Projekt3/mergeSort.cpp"

TEST(Sortowanie_przez_scalanie, Niezmieniona_tablica) {
	int tab[] = { 1, 5, 8, 12, 15, 29, 44 };
	int n = 7;
	sortowanie sort;
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	int tab_oczekiwana[] = { 1, 5, 8, 12, 15, 29, 44 };
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(tab[i], tab_oczekiwana[i]);
	}
}

TEST(Sortowanie_przez_scalanie, Sortowanie_odwrotniej_kolejnosci) {
	int tab[] = { 44, 29, 15, 12, 8, 5, 1 };
	int n = 7;
	sortowanie sort;
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	int tab_oczekiwana[] = { 1, 5, 8, 12, 15, 29, 44 };
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(tab[i], tab_oczekiwana[i]);
	}
}

TEST(Sortowanie_przez_scalanie, Sortowanie_losowej_tablicy) {
	int tab[] = { 15, 41, 31, 19, 4, 88, 102, 44, 55, 75 };
	int n = 10;
	sortowanie sort;
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	int tab_oczekiwana[] = { 4, 15, 19, 31, 41, 44, 55, 75, 88, 102 };
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(tab[i], tab_oczekiwana[i]);
	}
}

TEST(Sortowanie_przez_scalanie, Sortowanie_tylko_ujemnymi) {
	int tab[] = { -1, -5, -3, -18, -28, -19, -49, -11 };
	int n = 8;
	sortowanie sort;
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	int tab_oczekiwana[] = { -49, -28, -19, -18, -11, -5, -3, -1};
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(tab[i], tab_oczekiwana[i]);
	}
}

TEST(Sortowanie_przez_scalanie, Sortowanie_ujemne_i_dodatnie) {
	int tab[] = { -11, 5, 2, -5, -28, 14, 29, -6 };
	int n = 8;
	sortowanie sort;
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	int tab_oczekiwana[] = { -28, -11, -6, -5, 2, 5, 14, 29 };
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(tab[i], tab_oczekiwana[i]);
	}
}

TEST(Sortowanie_przez_scalanie, Obsluga_pustej_tablicy) {
	int* tab = nullptr;
	int n = 0;
	sortowanie sort;
	EXPECT_NO_THROW(sort.sortowanie_przez_scalanie(tab, 0, n - 1));
}

TEST(Sortowanie_przez_scalanie, Tablica_jednoelementowa) {
	int tab[] = { 5 };
	int n = 1;
	sortowanie sort;
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	EXPECT_EQ(tab[0], 5);
}

TEST(Sortowanie_przez_scalanie, Sortowanie_z_duplikatami) {
	int tab[] = { 72, 18, 19, 25, 25, 18, 4, 102 };
	int n = 8;
	sortowanie sort;
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	int tab_oczekiwana[] = { 4, 18, 18, 19, 25, 25, 72, 102 };
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(tab[i], tab_oczekiwana[i]);
	}
}

TEST(Sortowanie_przez_scalanie, Sortowanie_ujemnej_z_duplikatami) {
	int tab[] = { -1, -5, -1, -1, -18, -3, -27, -4, -4, -5 };
	int n = 10;
	sortowanie sort;
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	int tab_oczekiwana[] = { -27, -18, -5, -5, -4, -4, -3, -1, -1, -1 };
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(tab[i], tab_oczekiwana[i]);
	}
}

TEST(Sortowanie_przez_scalanie, Sortowanie_z_duplikatami_ujemnymi_dodatnimi) {
	int tab[] = { 5, 18, 4, 3, 5, 5, -1, -5, -1, -1, -18, 19, 5, -3, -27, -4, -4, 19, -5 };
	int n = 19;
	sortowanie sort;
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	int tab_oczekiwana[] = { -27, -18, -5, -5, -4, -4, -3, -1, -1, -1, 3, 4, 5, 5, 5, 5, 18, 19, 19 };
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(tab[i], tab_oczekiwana[i]);
	}
}

TEST(Sortowanie_przez_scalanie, Sortowanie_tablicy_z_dwoma_elementami) {
	int tab[] = { 7, -8 };
	int n = 2;
	sortowanie sort;
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	int tab_oczekiwana[] = { -8, 7 };
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(tab[i], tab_oczekiwana[i]);
	}
}

TEST(Sortowanie_przez_scalanie, Sortowanie_tablicy_100_elementowej) {
	const int n = 100;
	int tab[n];
	int tab_oczekiwana[n];
	sortowanie sort;
	for (int i = 0; i < n; i++) {
		tab[i] = rand() % 200;
		tab_oczekiwana[i] = tab[i];
	}
	sort.sortowanie_przez_scalanie(tab_oczekiwana, 0, n - 1);
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(tab[i], tab_oczekiwana[i]);
	}
}

TEST(Sortowanie_przez_scalanie, Sortowanie_tablicy_100_elementowej_z_ujemnymi_dodatnimi_duplikatami) {
	const int n = 100;
	int tab[n];
	int tab_oczekiwana[n];
	sortowanie sort;
	for (int i = 0; i < n; i++) {
		tab[i] = rand() % 200 - 100;
		tab_oczekiwana[i] = tab[i];
	}
	sort.sortowanie_przez_scalanie(tab_oczekiwana, 0, n - 1);
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(tab[i], tab_oczekiwana[i]);
	}
}