#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-11\\Input.txt");
	string line;

	if (!in.fail()) {
		getline(in, line);
		in.close();
	}

	int n = 0, nw = 0, ne = 0, sw = 0, s = 0, se = 0;

	unsigned int k = 0;
	for (unsigned int i = 0; i < line.size(); i++) {
		if (line.at(i) == ',') {
			string direction = line.substr(k, i - k);
			if (direction == "n") n++;
			else if (direction == "nw") nw++;
			else if (direction == "ne") ne++;
			else if (direction == "sw") sw++;
			else if (direction == "s") s++;
			else if (direction == "se") se++;
			k = i + 1;
		}
		else if (i == line.size() - 1) {
			string direction = line.substr(k, i - k + 1);
			if (direction == "n") n++;
			else if (direction == "nw") nw++;
			else if (direction == "ne") ne++;
			else if (direction == "sw") sw++;
			else if (direction == "s") s++;
			else if (direction == "se") se++;
		}
	}

	cout << "n = " << n << "\nnw = " << nw << "\nne = " << ne << "\nsw = " << sw << "\ns = " << s << "\nse = " << se << "\n\n";

	sw -= se;
	s += se;
	se = 0;
	nw -= ne;
	n += ne;
	ne = 0;

	cout << "n = " << n << "\nnw = " << nw << "\nne = " << ne << "\nsw = " << sw << "\ns = " << s << "\nse = " << se << "\n\n";

	s -= n;
	n = 0;

	cout << "n = " << n << "\nnw = " << nw << "\nne = " << ne << "\nsw = " << sw << "\ns = " << s << "\nse = " << se << "\n\n";
	
	/*711 to low*/

	s -= nw;
	sw += nw;
	nw = 0;

	cout << "n = " << n << "\nnw = " << nw << "\nne = " << ne << "\nsw = " << sw << "\ns = " << s << "\nse = " << se << "\n\n";

	cout << "Total = " << sw + s << endl;
	
	
	return 0;
}