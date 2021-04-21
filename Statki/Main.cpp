#include <random>
#include <iostream>
#include "Header.h"
using namespace std;

int plansza[10][10]{};

int main()
{
	char poz = 205, pion = 186, lgr = 201, pgr = 187, pdl= 188, ldl= 200;
	// pole
	random_device doPola;
	mt19937 pole(doPola());
	uniform_int_distribution <int> disPole(0, 9);
	// kierunek
	random_device doKierunku;
	mt19937 kierunek(doKierunku());
	uniform_int_distribution <int> disKierunek(1, 4);
	// *************************************************************************   4 masztowiec
	int x, y, k; // losowanie miejsca pocz¹tkowego
	x = disPole(pole);
	y = disPole(pole);
	// cout << x << " i " << y << endl;
	plansza[x][y] = 4;
	//ustawianie w odpowiednim kierunku
	k = disKierunek(kierunek);

	//sprawdzam mo¿liwoœæ zaisnienia okreœlonego 
	while (testKierunku(k, x, y) == 0)
		k = disKierunek(kierunek);

	czteroMasztowiec(x, y, k);
	// *************************************************************************   3, 2 i 1 masztowiec
	for (int l = 2, m = 3; l >= 1; l--) // wstawianie 3 trzymasztowców
	{
		x = disPole(pole);
		y = disPole(pole);
		while (plansza[x][y] != 0 || testKierunkuO(x, y, m) == 0) //sprawdzam czy pole jest wolne
		{
			x = disPole(pole);
			y = disPole(pole);
		}
		k = disKierunek(kierunek); // losowanie kierunku zwrotu
		while (testKierunku321(k, x, y, m) == 0)//sprawdzam mo¿liwoœæ stworzenia statku wzglêdem odpowiedniego kierunku
			k = disKierunek(kierunek);
		Masztowce321(m, x, y, k);
	}
	for (int l = 3, m = 2; l >= 1; l--) // wstawianie 2 dwómasztowców
	{
		while (plansza[x][y] != 0 || testKierunkuO(x, y, m) == 0) //sprawdzam czy pole jest wolne
		{
			x = disPole(pole);
			y = disPole(pole);
		}
		k = disKierunek(kierunek); // losowanie kierunku zwrotu
		while (testKierunku321(k, x, y, m) == 0)//sprawdzam mo¿liwoœæ zaistnienia okreœlonego statku wzglêdem kierunku
			k = disKierunek(kierunek);
		Masztowce321(m, x, y, k);
	}
	for (int l = 4, m = 1; l >= 1; l--)
	{
		x = disPole(pole);
		y = disPole(pole);
		while (plansza[x][y] != 0) //sprawdzam czy pole jest wolne
		{
			x = disPole(pole);
			y = disPole(pole);
		}
		Masztowce321(m, x, y, 1);
	}
	// ****************************************************************** rysowanie planszy na ekranie
	char ABC = 65;

	for (int i = 0; i <= 9; i++)
	{
		if (i == 0) // tylko pierwszy wiersz
		{
			for (int j = 0; j <= 10; j++)
			{
				if (j != 0)
				{
					cout.width(3);
					cout << j;
				}
				else
					cout << "   ";
			}
			cout << endl;
			for (int j = 0; j <= 11; j++)
			{
				if (j == 1)
					cout << "   " << lgr;
				if (j>=2)
					cout << poz << poz << poz;
				if (j == 11)
					cout << pgr;
			}
			cout << endl;
		}
		cout.width(3);
		cout << ABC++ << pion;
		for (int j = 0; j <= 9; j++)
		{
			if (plansza[i][j] > 0)
			{
				cout.width(2);
				cout.fill(' ');
				cout << plansza[i][j] << " ";
			}
			else
			{
				cout.width(2);
				cout.fill(' ');
				cout << "-" << " ";
			}
		}
		cout << pion;
		cout << endl;
	}
	for (int j = 0; j <= 11; j++)
	{
		if (j == 1)
			cout << "   " << ldl;
		if (j >= 2)
			cout << poz << poz << poz;
		if (j == 11)
			cout << pdl;
	}
	cout << endl;
	cout << endl;
	system("pause");
}