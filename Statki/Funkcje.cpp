#include "Header.h"
#include <iostream>
#include <random>
using namespace std;

extern int plansza[10][10];

bool testKierunku(int t, int x, int y)
{
	if (t == 1) // góra
	{
		if (x - 4 >= 0)
			return true;
		else
			return false;
	}
	else
	{
		if (t == 2) // prawo
		{
			if (y + 4 <= 9)
				return true;
			else
				return false;
		}
		else
			if (t == 3) // dó³
			{
				if (x + 4 <= 9)
					return true;
				else
					return false;
			}
			else // lewo
			{
				if (y - 4 >= 0)
					return true;
				else
					return false;
			}
	}
}
bool testKierunkuO(int x, int y, int maszt)
{
	if (x - maszt + 1 >= 0 && plansza[x - maszt + 1][y] == 0)
		return true;
	else
		if (y + maszt - 1 <= 9 && plansza[x][y + maszt - 1] == 0)
			return true;
		else
			if (x + maszt - 1 <= 9 && plansza[x + maszt - 1][y] == 0)
				return true;
			else
				if (y - maszt + 1 >= 0 && plansza[x][y - maszt + 1] == 0)
					return true;
				else
					return false;
}
bool testKierunku321(int t, int x, int y, int maszt)
{
	if (t == 1) // góra
	{
		if (x - maszt +1 >= 0 && plansza[x-maszt+1][y] == 0)
			return true;
		else
			return false;
	}
	else
	{
		if (t == 2) // prawo
		{
			if (y + maszt-1 <= 9 && plansza[x][y + maszt - 1] == 0)
				return true;
			else
				return false;
		}
		else
			if (t == 3) // dó³
			{
				if (x + maszt -1 <= 9 && plansza[x + maszt - 1][y] == 0)
					return true;
				else
					return false;
			}
			else // lewo
			{
				if (y - maszt +1 >= 0 && plansza[x][y-maszt+1] == 0)
					return true;
				else
					return false;
			}
	}
}
void czteroMasztowiec(int x, int y, int k)
{
	if (k == 1)// w góre
	{
		plansza[x - 1][y] = 4;
		plansza[x - 2][y] = 4;
		plansza[x - 3][y] = 4;

		if (y - 1 >= 0) // zakazane pola po lewej
		{
			plansza[x][y - 1] = -1;
			plansza[x - 1][y - 1] = -1;
			plansza[x - 2][y - 1] = -1;
			plansza[x - 3][y - 1] = -1;
			if (x + 1 <= 9) // zakazane pole pod
			{
				plansza[x + 1][y - 1] = -1;
			}
			if (x - 4 >= 0) // zakazane pole nad
			{
				plansza[x - 4][y - 1] = -1;
			}
		}
		if (y + 1 <= 9) // zakazane pola po prawej
		{
			plansza[x][y + 1] = -1;
			plansza[x - 1][y + 1] = -1;
			plansza[x - 2][y + 1] = -1;
			plansza[x - 3][y + 1] = -1;
			if (x + 1 <= 9) // zakazane pole pod
			{
				plansza[x + 1][y + 1] = -1;
			}
			if (x - 4 >= 0) // zakazane pole nad
			{
				plansza[x - 4][y + 1] = -1;
			}
		}
		if (x + 1 <= 9) // zakazane pole pod
		{
			plansza[x + 1][y] = -1;
		}
		if (x - 4 >= 0) // zakazane pole nad
		{
			plansza[x - 4][y] = -1;
		}
	}
	else
		// w prawo
		if (k == 2)
		{
			plansza[x][y + 1] = 4;
			plansza[x][y + 2] = 4;
			plansza[x][y + 3] = 4;

			if (x - 1 >= 0) // zakazane pola nad
			{
				plansza[x - 1][y] = -1;
				plansza[x - 1][y + 1] = -1;
				plansza[x - 1][y + 2] = -1;
				plansza[x - 1][y + 3] = -1;
				if (y - 1 >= 0) // zakazane pole po lewej
				{
					plansza[x - 1][y - 1] = -1;
				}
				if (y + 4 <= 9) // zakazane pole po prawej
				{
					plansza[x - 1][y + 4] = -1;
				}
			}
			if (x + 1 <= 9) // zakazane pola pod
			{
				plansza[x + 1][y] = -1;
				plansza[x + 1][y + 1] = -1;
				plansza[x + 1][y + 2] = -1;
				plansza[x + 1][y + 3] = -1;
				if (y - 1 >= 0) // zakazane pole po lewej
				{
					plansza[x + 1][y - 1] = -1;
				}
				if (y + 4 <= 9) // zakazane pole po prawej
				{
					plansza[x + 1][y + 4] = -1;
				}
			}
			if (y - 1 >= 0) // zakazane pole po lewej
			{
				plansza[x][y - 1] = -1;
			}
			if (y + 4 <= 9) // zakazane pole po prawej
			{
				plansza[x][y + 4] = -1;
			}
		}
		else
			//w dó³
			if (k == 3)// w góre
			{
				plansza[x + 1][y] = 4;
				plansza[x + 2][y] = 4;
				plansza[x + 3][y] = 4;

				if (y - 1 >= 0) // zakazane pola po lewej
				{
					plansza[x][y - 1] = -1;
					plansza[x + 1][y - 1] = -1;
					plansza[x + 2][y - 1] = -1;
					plansza[x + 3][y - 1] = -1;
					if (x + 4 <= 9) // zakazane pole pod
					{
						plansza[x + 4][y - 1] = -1;
					}
					if (x - 1 >= 0) // zakazane pole nad
					{
						plansza[x - 1][y - 1] = -1;
					}
				}
				if (y + 1 <= 9) // zakazane pola po prawej
				{
					plansza[x][y + 1] = -1;
					plansza[x + 1][y + 1] = -1;
					plansza[x + 2][y + 1] = -1;
					plansza[x + 3][y + 1] = -1;
					if (x + 4 <= 9) // zakazane pole pod
					{
						plansza[x + 4][y + 1] = -1;
					}
					if (x - 1 >= 0) // zakazane pole nad
					{
						plansza[x - 1][y + 1] = -1;
					}
				}
				if (x + 1 <= 9) // zakazane pole pod
				{
					plansza[x + 4][y] = -1;
				}
				if (x - 1 >= 0) // zakazane pole nad
				{
					plansza[x - 1][y] = -1;
				}
			}
			else
				// w lewo
				if (k == 4)
				{
					plansza[x][y - 1] = 4;
					plansza[x][y - 2] = 4;
					plansza[x][y - 3] = 4;

					if (x - 1 >= 0) // zakazane pola nad
					{
						plansza[x - 1][y] = -1;
						plansza[x - 1][y - 1] = -1;
						plansza[x - 1][y - 2] = -1;
						plansza[x - 1][y - 3] = -1;
						if (y - 4 >= 0) // zakazane pole po lewej
						{
							plansza[x - 1][y - 4] = -1;
						}
						if (y + 1 <=9) // zakazane pole po prawej
						{
							plansza[x - 1][y + 1] = -1;
						}
					}
					if (x + 1 <= 9) // zakazane pola pod
					{
						plansza[x + 1][y] = -1;
						plansza[x + 1][y - 1] = -1;
						plansza[x + 1][y - 2] = -1;
						plansza[x + 1][y - 3] = -1;
						if (y - 4 >= 0) // zakazane pole po lewej
						{
							plansza[x + 1][y - 4] = -1;
						}
						if (y + 1 <= 9) // zakazane pole po prawej
						{
							plansza[x + 1][y + 1] = -1;
						}
					}
					if (y - 4 >= 0) // zakazane pole po lewej
					{
						plansza[x][y - 4] = -1;
					}
					if (y + 1 <= 9) // zakazane pole po prawej
					{
						plansza[x][y + 1] = -1;
					}
				}
}
void Masztowce321(int maszt, int x, int y, int k)
{
	if (k == 1)// w góre
	{
		for (int i = maszt-1; i>=0 ; i--) //zapis pól statku
			plansza[x - i][y] = maszt;

		if (y - 1 >= 0) // zakazane pola po lewej
		{
			for (int i = maszt-1; i >= 0; i--)
				plansza[x-i][y - 1] = -1;
			
			if (x + 1 <= 9) // zakazane pole pod
				plansza[x + 1][y - 1] = -1;
			
			if (x - maszt >= 0) // zakazane pole nad
				plansza[x - maszt][y - 1] = -1;
		}
		if (y + 1 <= 9) // zakazane pola po prawej
		{
			for (int i = maszt - 1; i >= 0; i--)
				plansza[x - i][y + 1] = -1;
			if (x + 1 <= 9) // zakazane pole pod
				plansza[x + 1][y + 1] = -1;
			if (x - maszt >= 0) // zakazane pole nad
				plansza[x - maszt][y + 1] = -1;
		}
		if (x + 1 <= 9) // zakazane pole pod
			plansza[x + 1][y] = -1;
		if (x - maszt >= 0) // zakazane pole nad
			plansza[x - maszt][y] = -1;
	}
	else
		// w prawo
		if (k == 2)
		{
			for (int i = maszt - 1; i >= 0; i--)
				plansza[x][y+i] = maszt;
			if (x - 1 >= 0) // zakazane pola nad
			{
				for (int i = maszt - 1; i >= 0; i--)
					plansza[x - 1][y + i] = -1;
				if (y - 1 >= 0) // zakazane pole po lewej
					plansza[x - 1][y - 1] = -1;
				if (y + maszt <= 9) // zakazane pole po prawej
					plansza[x - 1][y + maszt] = -1;
			}
			if (x + 1 <= 9) // zakazane pola pod
			{
				for (int i = maszt - 1; i >= 0; i--)
					plansza[x+1][y + i] = -1;
				if (y - 1 >= 0) // zakazane pole po lewej
					plansza[x + 1][y - 1] = -1;
				if (y + maszt <= 9) // zakazane pole po prawej
					plansza[x + 1][y + maszt] = -1;
			}
			if (y - 1 >= 0) // zakazane pole po lewej
				plansza[x][y - 1] = -1;
			if (y + maszt <= 9) // zakazane pole po prawej
				plansza[x][y + maszt] = -1;
		}
		else
			//w dó³
			if (k == 3)
			{
				for (int i = maszt - 1; i >= 0; i--) //zapis pól statku
					plansza[x + i][y] = maszt;

				if (y - 1 >= 0) // zakazane pola po lewej
				{
					for (int i = maszt - 1; i >= 0; i--)
						plansza[x + i][y - 1] = -1;

					if (x + maszt <= 9) // zakazane pole pod
						plansza[x + maszt][y - 1] = -1;

					if (x - 1 >= 0) // zakazane pole nad
						plansza[x - 1][y - 1] = -1;
				}
				if (y + 1 <= 9) // zakazane pola po prawej
				{
					for (int i = maszt - 1; i >= 0; i--)
						plansza[x + i][y + 1] = -1;
					if (x + maszt <= 9) // zakazane pole pod
						plansza[x + maszt][y + 1] = -1;
					if (x - 1 >= 0) // zakazane pole nad
						plansza[x - 1][y + 1] = -1;
				}
				if (x + maszt <= 9) // zakazane pole pod
				{
					plansza[x + maszt][y] = -1;
				}
				if (x - 1 >= 0) // zakazane pole nad
				{
					plansza[x - 1][y] = -1;
				}
			}
			else
				// w lewo
				if (k == 4)
				{
					for (int i = maszt - 1; i >= 0; i--)
						plansza[x][y - i] = maszt;
					if (x - 1 >= 0) // zakazane pola nad
					{
						for (int i = maszt - 1; i >= 0; i--)
							plansza[x-1][y - i] = -1;
						if (y - maszt >= 0) // zakazane pole po lewej
							plansza[x - 1][y - maszt] = -1;
						if (y + 1 <= 9) // zakazane pole po prawej
							plansza[x - 1][y + 1] = -1;
					}
					if (x + 1 <= 9) // zakazane pola pod
					{
						for (int i = maszt - 1; i >= 0; i--)
							plansza[x+1][y - i] = -1;
						if (y - maszt >= 0) // zakazane pole po lewej
							plansza[x + 1][y - maszt] = -1;
						if (y + 1 <= 9) // zakazane pole po prawej
							plansza[x + 1][y + 1] = -1;
					}
					if (y - maszt >= 0) // zakazane pole po lewej
						plansza[x][y - maszt] = -1;
					if (y + 1 <= 9) // zakazane pole po prawej
						plansza[x][y + 1] = -1;
				}
}