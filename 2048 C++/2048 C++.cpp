
#include <iostream>
#include <vector>

using namespace std;

void inputSize(int& size) {
    cout << "Entrez la taille du tableau ";
    cin >> size;

}

void printGril(vector<vector<int>> gril, int& size) {
	cout << endl;
    for (int i = 0; i < size; i++) {
        for (int y = 0; y < size; y++) {

            cout << " " << gril[i][y] << " ";
        }
        cout << endl;
	}
    
	cout << endl;
}

int main()
{
    int size = 4;
    inputSize(size);
    vector<vector<int>> gril(size, vector<int>(size, 0));
    printGril(gril, size);
    

}

