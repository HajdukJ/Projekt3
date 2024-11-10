#include <iostream>
#include "mergeSort.h"

int main()
{
	int tab[] = { 41, 45, 5, 19, 18, 45, 45, 24, 192, 204 };   // <--- Test dzialania, przykladowa tablica
	int n = 10;
	sortowanie sort;
	sort.sortowanie_przez_scalanie(tab, 0, n - 1);
	for (int i = 0; i < n; i++) {
		std::cout << tab[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}