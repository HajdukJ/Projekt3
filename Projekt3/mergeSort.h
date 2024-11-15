#pragma once

/// @class sortowanie
/// @brief Klasa reprezentujaca algorytm sortowania przez scalanie

class sortowanie {
private:

public:
    /// @brief Scala dwie czesci tablicy w jedna posortowana
	/// @param tab Tablica
	/// @param lewa Indeks poczatkowy lewej czesci
	/// @param srodek Indeks koncowy lewej czesci oraz poczatek prawej czesci
	/// @param prawa Indeks koncowy prawej czesci
	void scalanie(int tab[], int lewa, int srodek, int prawa);
	/// @brief Sortuje tablice
	/// @param tab Tablica liczb calkowitych do posortowania
	/// @param lewa Indeks poczatkowy (zakres) do sortowania
	/// @param prawa Indeks koncowy do sortowania
	void sortowanie_przez_scalanie(int tab[], int lewa, int prawa);
};