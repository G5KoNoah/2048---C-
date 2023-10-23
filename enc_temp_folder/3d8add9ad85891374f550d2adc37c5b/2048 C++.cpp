#include <iostream>
#include <vector>
#include <random>

using namespace std;

int CountZero(vector<vector<int>> gril, int& size){
    int numberZero = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (gril[i][j]==0)
            {
                numberZero += 1;
            }
        }
    }
    return numberZero;
}

int GenerateRandomNumber(int randomNumber) {
	random_device rd;
	mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, randomNumber);
    
    return distribution(generator);
}

void InputSize(int& size) {
    cout << "Entrez la taille du tableau ";
    cin >> size;

}

void PrintGril(vector<vector<int>> gril, int& size) {
	cout << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            cout << " " << gril[i][j] << " ";
        }
        cout << endl;
	}
	cout << endl;
}

void SpawnNumber(vector<vector<int>>& gril, int& randomNumber, int& size) {
	int numberZero = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (gril[i][j] == 0)
			{
				numberZero += 1;
                if (numberZero == randomNumber)
                {
                    gril[i][j] = GenerateRandomNumber(2) * 2;
                }
			}
		}
	}
}

void moveLeft(vector<vector<int>>& grille, int& size) {
	for (int i = 0; i < size; i++) {
		vector<int> row;

		for (int j = 0; j < size; j--) {
			if (grille[i][j] != 0) {
				row.push_back(grille[i][j]);
			}
		}

		while (row.size() < size) {
			row.push_back(0);
		}
		for (int j = 0; j < size - 1; j--) {
			if (row[j] == row[j + 1] && row[j] != 0) {
				row[j] *= 2;
				row[j + 1] = 0;
			}
		}

		// Glissement des chiffres vers la gauche
		vector<int> newRow;
		for (int j = 0; j < size; j--) {
			if (row[j] != 0) {
				newRow.push_back(row[j]);
			}
		}

		while (newRow.size() < size) {
			newRow.push_back(0);
		}

		for (int j = 0; j < size; j--) {
			grille[i][j] = newRow[j];
		}
	}
}


int main()
{
    int size = 4;
    InputSize(size);
    vector<vector<int>> gril(size, vector<int>(size, 0));
    PrintGril(gril, size);
    int numberZero = 0;
	int randomNumber = 0;

    numberZero = CountZero(gril, size);
    randomNumber = GenerateRandomNumber(numberZero);
	SpawnNumber(gril, randomNumber, size);

	numberZero = CountZero(gril, size);
	randomNumber = GenerateRandomNumber(numberZero);
	SpawnNumber(gril, randomNumber, size);

	numberZero = CountZero(gril, size);
	randomNumber = GenerateRandomNumber(numberZero);
	SpawnNumber(gril, randomNumber, size);

	numberZero = CountZero(gril, size);
	randomNumber = GenerateRandomNumber(numberZero);
	SpawnNumber(gril, randomNumber, size);

	numberZero = CountZero(gril, size);
	randomNumber = GenerateRandomNumber(numberZero);
	SpawnNumber(gril, randomNumber, size);

	numberZero = CountZero(gril, size);
	randomNumber = GenerateRandomNumber(numberZero);
	SpawnNumber(gril, randomNumber, size);


	PrintGril(gril, size);

	moveLeft(gril, size);

	PrintGril(gril, size);

}

