#include <iostream>
#include <vector>
#include <random>

#include <string>
#include <windows.h>
using namespace std;

class Box
{
public:

	int value;


	Box()
	{
		this->value = 0;

	}

	~Box()
	{

	}
};

class Grid
{
public:

	int size;
	vector<vector<Box>> grid;

	Grid(int size)
	{
		this->size = size;
		grid = vector<vector<Box>>(size, vector<Box>(size));

		for (size_t i = 0; i < size*size; i++)
		{
			grid[i / 4][i % 4] = Box();
		}
	}

	~Grid()
	{

	}


	void Print() {
		system("cls");
		cout << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (grid[i][j].value > 1000) {
					cout << "  " << grid[i][j].value << " ";
				}
				else if (grid[i][j].value > 100) {
					cout << "  " << grid[i][j].value << "  ";
				}
				else if (grid[i][j].value > 10) {
					cout << "   " << grid[i][j].value << "  ";
				}
				else {
					cout << "   " << grid[i][j].value << "   ";
				}
				
			}
			cout << endl;
		}
		cout << endl;
	}


	int PlaceNumber() {
		vector<Box> empty;
		int numberZero = 0;
		int randomPos = 0;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (grid[i][j].value == 0)
				{
					numberZero += 1;
					empty.push_back(grid[i][j]);
				}
			}
		}

		randomPos = GenerateRandomNumber(numberZero);

		SpawnNumber(randomPos);

		return numberZero;
	}

	int GenerateRandomNumber(int randomNumber) {
		random_device rd;
		mt19937 generator(rd());
		uniform_int_distribution<int> distribution(1, randomNumber);

		return distribution(generator);
	}

	void SpawnNumber(int& randomNumber) {
		int numberZero = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (grid[i][j].value == 0)
				{
					numberZero += 1;
					if (numberZero == randomNumber)
					{
						grid[i][j].value = GenerateRandomNumber(2) * 2;
					}
				}
			}
		}
	}

	void moveHorizontal(string move) {
		for (int i = 0; i < size; i++) {
			vector<int> row;

			for (int j = 0; j < size; j++) {
				if (grid[i][j].value != 0) {
					row.push_back(grid[i][j].value);
				}
			}
			if (move == "left") {
				while (row.size() < size) {
					row.push_back(0); 
				}
				for (int j = 0; j < size - 1; j++) {
					if (row[j] == row[j + 1] && row[j] != 0) { // a changer pour que la valeur soit bonne pour vers la droite
						row[j] *= 2;
						row[j + 1] = 0;
					}
				}
			}else {
				while (row.size() < size) {
					row.insert(row.begin(), 0); 
				}
				for (int j = size - 1; j > 0; j--) {
					if (row[j] == row[j - 1] && row[j] != 0) { // a changer pour que la valeur soit bonne pour vers la droite
						row[j] *= 2;
						row[j - 1] = 0;
					}
				}
			}



			// Glissement des chiffres vers la gauche
			vector<int> newRow;
			for (int j = 0; j < size; j++) {
				if (row[j] != 0) {
					newRow.push_back(row[j]);
				}
			}

			if (move == "left") {
				while (newRow.size() < size) {
					newRow.push_back(0);
				}
			}
			else {
				while (newRow.size() < size) {
					newRow.insert(newRow.begin(), 0);
				}
				
			}

			for (int j = 0; j < size; j++) {
				grid[i][j].value = newRow[j];
			}
		}

		PlaceNumber();
		Print();

	}

	void moveVertical(string move) {
		for (int i = 0; i < size; i++) {
			vector<int> column;

			for (int j = 0; j < size; j++) {
				if (grid[j][i].value != 0) {
					column.push_back(grid[j][i].value);
				}
			}
			if (move == "up") {
				while (column.size() < size) {
					column.push_back(0);
				}
				for (int j = 0; j < size - 1; j++) {
					if (column[j] == column[j + 1] && column[j] != 0) { // a changer pour que la valeur soit bonne pour vers la droite
						column[j] *= 2;
						column[j + 1] = 0;
					}
				}
			}
			else {
				while (column.size() < size) {
					column.insert(column.begin(), 0);
				}
				for (int j = size - 1; j >= 1; j--) {
					if (column[j] == column[j - 1] && column[j] != 0) {
						column[j] *= 2;
						column[j - 1] = 0;
					}
				}
			}


			// Glissement des chiffres vers le bas
			vector<int> newColumn;
			for (int j = 0; j < size; j++) {
				if (column[j] != 0) {
					newColumn.push_back(column[j]);
				}
			}
			if (move == "up") {
				while (newColumn.size() < size) {
					newColumn.push_back(0);
				}
			}
			else {
				while (newColumn.size() < size) {
					newColumn.insert(newColumn.begin(), 0);
				}
			}
			for (int j = 0; j < size; j++) {
				grid[j][i].value = newColumn[j];
			}
		}

		PlaceNumber();
		Print();

	}


	void Defeat(bool& ifDefeat) {
		int zero = 0;
		for (int i = 0;i < size;i++) {
			for (int y = 0; y < size;y++) {
				if (grid[i][y].value == 0) {
					zero += 1;
				}
			}
		}
		if (zero == 0) {
			ifDefeat = true;
		}
	}
	void Win(bool& win) {
		for (int i = 0;i < size;i++) {
			for (int y = 0; y < size;y++) {
				if (grid[i][y].value == 64) {
					win = true;
					break;
				}
			}
		}

	}
};







void InputSize(int& size) {
    cout << "Entrez la taille du tableau ";
    cin >> size;
}



int main()
{



	int size = 0;
	bool defeat = false;
	bool win = false;
	InputSize(size);
	
	Grid * grid = new Grid(size);

	grid->Print();



    int numberZero = 0;
	int randomNumber = 0;
	bool leftArrowKeyPressed = false;
	bool rightArrowKeyPressed = false;
	bool upArrowKeyPressed = false;
	bool downArrowKeyPressed = false;

	grid->PlaceNumber();
	grid->PlaceNumber();
	grid->Print();
	while (!defeat && !win) {
		if (GetKeyState(VK_LEFT) & 0x8000) {
			if (!leftArrowKeyPressed) {
				leftArrowKeyPressed = true;
				grid->moveHorizontal("left");
			}
		}
		else {
			leftArrowKeyPressed = false;
		}
		if (GetKeyState(VK_RIGHT) & 0x8000) {
			if (!rightArrowKeyPressed) {
				rightArrowKeyPressed = true;
				grid->moveHorizontal("right");
			}
		}
		else {
			rightArrowKeyPressed = false;
		}
		if (GetKeyState(VK_UP) & 0x8000) {
			if (!upArrowKeyPressed) {
				upArrowKeyPressed = true;
				grid->moveVertical("up");
			}
		}
		else {
			upArrowKeyPressed = false;
		}
		if (GetKeyState(VK_DOWN) & 0x8000) {
			if (!downArrowKeyPressed) {
				downArrowKeyPressed = true;
				grid->moveVertical("down");
			}
		}
		else {
			downArrowKeyPressed = false;
		}
		grid->Defeat(defeat);
		grid->Win(win);
	}

	if (defeat) {
		cout << "Vous avez perdu !!!!";
	}
	else {
		cout << "Vous avez gagne !!!!";
	}

	delete grid;
}

