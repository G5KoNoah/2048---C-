#pragma once  // Utilisez #pragma once pour éviter l'inclusion multiple
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <windows.h>

using namespace std;
class Grid
{
public:
	Grid(int size);
	~Grid();
	void Print();
	int PlaceNumber();
	int GenerateRandomNumber(int randomNumber);
	void moveHorizontal(string move);
	void moveVertical(string move);
	void Defeat(bool& ifDefeat);
	void Win(bool& win);
};