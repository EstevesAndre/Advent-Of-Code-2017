#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int calculate_distance(int n, int nw, int ne, int sw, int s, int se) {
	if (sw > se) {
		sw -= se;
		s += se;
		se = 0;
	}
	else {
		se -= sw;
		s += sw;
		sw = 0;
	}

	if (ne > nw) {
		ne -= nw;
		n += nw;
		nw = 0;
	}
	else {
		nw -= ne;
		n += ne;
		ne = 0;
	}
	//1-> ne == 0 && sw == 0
	if (ne == 0 && sw == 0) {
		if (nw > se) {
			nw -= se;
			se = 0;
		}
		else {
			se -= nw;
			nw = 0;
		}

		if (n > s) {
			n -= s;
			s = 0;
			if (se == 0) {
				return n + nw;
			}
			else if (nw == 0) {
				if (se > n)
					return se;
				else
					return n;
			}
		}
		else {//s > n
			s -= n;
			n = 0;
			if (se == 0) {
				if (nw > s)
					return nw;
				else
					return s;
			}
			else if (nw == 0) {
				return s + se;
			}
		}
	}
	
	//2-> ne == 0 && se == 0
	if (ne == 0 && se == 0) {
		if (n > s) {
			n -= s;
			s = 0;
			if (n > sw) {
				n -= sw;
				nw += sw;
				sw = 0;
				return nw + n;
			}
			else {
				sw -= n;
				nw += n;
				n = 0;
				return nw + sw;
			}
		}
		else {
			s -= n;
			n = 0;
			if (s > nw) {
				s -= nw;
				sw += nw;
				nw = 0;
				return s + sw;
			}
			else {
				nw -= s;
				sw += s;
				s = 0;
				return sw + nw;
			}
		}
	}

	//3-> nw == 0 && sw == 0
	if (nw == 0 && sw == 0) {
		if (n > s) {
			n -= s;
			s = 0;
			if (n > se) {
				n -= se;
				ne += se;
				se = 0;
				return ne + n;
			}
			else {
				se -= n;
				ne += n;
				n = 0;
				return ne + se;
			}
		}
		else {
			s -= n;
			n = 0;
			if (s > ne) {
				s -= ne;
				se += ne;
				ne = 0;
				return s + se;
			}
			else {
				ne -= s;
				se += s;
				s = 0;
				return se + ne;
			}
		}
	}

	//4-> nw == 0 && se == 0
	if (nw == 0 && se == 0) {
		if (ne > sw) {
			ne -= sw;
			sw = 0;
		}
		else {
			sw -= ne;
			ne = 0;
		}

		if (n > s) {
			n -= s;
			s = 0;
			if (sw == 0) {
				return ne + n;
			}
			else if (ne == 0) {
				if (sw > n)
					return sw;
				else
					return n;
			}
		}
		else { // s>n
			s -= n;
			n = 0;
			if (sw == 0) {
				if (ne > s)
					return ne;
				else
					return s;
			}
			else if (ne == 0) {
				return sw + s;
			}
		}
	}
}

int main() {

	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-11\\Input.txt");
	string line;

	if (!in.fail()) {
		getline(in, line);
		in.close();
	}

	int n = 0, nw = 0, ne = 0, sw = 0, s = 0, se = 0;
	vector<int> distances;

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

		distances.push_back(calculate_distance(n, nw, ne, sw, s, se));

	}

	int max_distance = 0;
	for (unsigned int i = 0; i < distances.size(); i++) {
		if (distances.at(i) > max_distance)
			max_distance = distances.at(i);
	}
	
	cout << "Max distance = " << max_distance << endl;
	return 0;
}