#include <iostream>
#include "mergeSort.h"

int main()
{
	int tab[] = { 41, 45, 5, 19, 18, 45, 45, 24, 192, 204 };   // <--- Test dzialania, przykladowa tablica
	int n = 10;
	std::cout << "Tablica przed sortowaniem: " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << tab[i] << " ";
	}
	std::cout << std::endl;
	sortowanie sort;
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	std::cout << "Tablica po sortowaniu: " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << tab[i] << " ";
	}
	std::cout << std::endl;

	const int m = 100;   // <--- Test dzialania, przykladowa tablica 100-elementowa
	int tab1[m];
	sortowanie sort1;
	for (int i = 0; i < m; i++) {
		tab1[i] = rand() % 200 - 100;
	}
	std::cout << "Tablica przed sortowaniem: " << std::endl;
	for (int i = 0; i < m; i++) {
		std::cout << tab1[i] << " ";
	}
	std::cout << std::endl;
	sort1.sortowanie_przez_scalanie(tab1, 0, m - 1);
	std::cout << "Tablica po sortowaniu: " << std::endl;
	for (int i = 0; i < m; i++) {
		std::cout << tab1[i] << " ";
	}
	return 0;
}