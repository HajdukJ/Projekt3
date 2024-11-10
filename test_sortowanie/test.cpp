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
// dopisac metody !!!!!!!!!!!!!!!!!
TEST(Sortowanie_przez_scalanie, Obsluga_pustej_tablicy) {
	;
}

TEST(Sortowanie_przez_scalanie, Tablica_jednoelementowa) {
	;
}

TEST(Sortowanie_przez_scalanie, Sortowanie_z_duplikatami) {
	;
}

TEST(Sortowanie_przez_scalanie, Sortowanie_ujemnej_z_duplikatami) {
	;
}

TEST(Sortowanie_przez_scalanie, Sortowanie_z_duplikatami_ujemnymi_dodatnimi) {
	;
}

TEST(Sortowanie_przez_scalanie, Sortowanie_tablicy_z_dwoma_elementami) {
	;
}

TEST(Sortowanie_przez_scalanie, Sortowanie_tablicy_100_elementowej) {
	;
}

TEST(Sortowanie_przez_scalanie, Sortowanie_tablicy_100_elementowej_z_ujemnymi_dodatduplikatami) {
	;
}