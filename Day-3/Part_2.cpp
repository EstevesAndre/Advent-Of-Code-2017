#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

void display_matrix(int m[11][11]) {
	for (unsigned int i = 0; i < 11; i++) {
		for (unsigned int j = 0; j < 11; j++) {
			cout << setw(7) << m[i][j];
		}
		cout << endl << endl;
	}
	cout << "---------------------------------------------------\n";
}
int main() {

	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-3\\Input.txt");

	string val;
	getline(in, val);

	int value = stoi(val);

	int m[11][11] = {};
	m[5][5] = 1, m[5][6] = 1, m[5][4] = 10, m[5][3] = 330, m[5][7] = 54;
	m[4][3] = 304, m[4][4] = 5, m[4][5] = 4, m[4][6] = 2, m[4][7] = 57;
	m[3][3] = 147, m[3][4] = 142, m[3][5] = 133, m[3][6] = 122, m[3][7] = 59;
	m[6][3] = 351, m[6][4] = 11, m[6][5] = 23, m[6][6] = 25, m[6][7] = 26;
	m[7][3] = 362, m[7][4] = 747, m[7][5] = 806;

	//display_matrix(m);
	char direction = 'E';
	int x = 7, y = 6;

	while (m[1][1] == 0) {
		switch (direction) {
		case 'E': m[x][y] = m[x - 1][y - 1] + m[x - 1][y] + m[x - 1][y + 1] + m[x][y - 1] + m[x][y + 1] + m[x + 1][y - 1] + m[x + 1][y] + m[x + 1][y + 1];
			if (m[x - 1][y] == 0) {
				x = x - 1;
				direction = 'N';
			}
			else
				y = y + 1;
			break;
		case 'S': m[x][y] = m[x - 1][y - 1] + m[x - 1][y] + m[x - 1][y + 1] + m[x][y - 1] + m[x][y + 1] + m[x + 1][y - 1] + m[x + 1][y] + m[x + 1][y + 1];
			if (m[x][y + 1] == 0) {
				y = y + 1;
				direction = 'E';
			}
			else
				x = x + 1;
			break;
		case 'N': m[x][y] = m[x - 1][y - 1] + m[x - 1][y] + m[x - 1][y + 1] + m[x][y - 1] + m[x][y + 1] + m[x + 1][y - 1] + m[x + 1][y] + m[x + 1][y + 1];
			if (m[x][y-1] == 0) {
				y = y - 1;
				direction = 'O';
			}
			else
				x = x - 1;
			break;
		case 'O': m[x][y] = m[x - 1][y - 1] + m[x - 1][y] + m[x - 1][y + 1] + m[x][y - 1] + m[x][y + 1] + m[x + 1][y - 1] + m[x + 1][y] + m[x + 1][y + 1];
			if (m[x + 1][y] == 0) {
				x = x + 1;
				direction = 'S';
			}
			else
				y = y - 1;
			break;
		default:
			break;
		}
		
		
	}
	display_matrix(m);
	return 0;

}