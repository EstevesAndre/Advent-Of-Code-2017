#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool not_found(int n_pipe, vector<int> connected) {

	for (unsigned int i = 0; i < connected.size(); i++) {
		if (connected.at(i) == n_pipe)
			return false;
	}

	return true;
}
bool found(int n_pipe, vector<int> connected) {

	for (unsigned int i = 0; i < connected.size(); i++) {
		if (connected.at(i) == n_pipe)
			return true;
	}

	return false;
}


int main() {

	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-12\\Input.txt");

	vector<pair<int, vector<int> > > pipes;

	if (!in.fail()) {
		string line;
		while (!in.eof()) {
			getline(in, line);
			stringstream pipe(line);
			int number;
			string equiv;
			pipe >> number;
			pipe >> equiv;

			vector<int> val;
			while (!pipe.eof()) {
				string aux;
				pipe >> aux;
				if (aux.at(aux.size() - 1) == ',') {
					aux = aux.substr(0, aux.size() - 1);
				}
				val.push_back(stoi(aux));
			}

			pair<int, vector<int> > pipee = make_pair(number, val);

			pipes.push_back(pipee);
		}
		in.close();
	}

	cout << pipes.size() << endl;


	vector<int> connected2 = { 0 };
	for (unsigned int i = 0; i < pipes.at(0).second.size(); i++) {
		connected2.push_back(pipes.at(0).second.at(i));
	}

	unsigned int size = connected2.size();
	do {
		size = connected2.size();
		for (unsigned int i = 0; i < connected2.size(); i++) {
			for (unsigned int j = 0; j < pipes.size(); j++) {
				if (pipes.at(j).first == connected2.at(i)) {
					for (unsigned int k = 0; k < pipes.at(j).second.size(); k++) {
						if (not_found(pipes.at(j).second.at(k), connected2)) {
							connected2.push_back(pipes.at(j).second.at(k));
						}
					}
				}
			}
		}
	} while (size != connected2.size());

	int n_groups = 1;
	vector<vector<int> > groups;
	groups.push_back(connected2);
	for ( int n = 0; n < pipes.size(); n++) {
		bool falta = true;
		for (unsigned int m = 0; m < groups.size(); m++) {
			if (found(n, groups.at(m)))
				falta = false;
		}
		if (falta) {
			vector<int> connected = { n };
			for (unsigned int i = 0; i < pipes.at(n).second.size(); i++) {
				connected.push_back(pipes.at(n).second.at(i));
			}

			unsigned int size = connected.size();
			do {
				size = connected.size();
				for (unsigned int i = 0; i < connected.size(); i++) {
					for (unsigned int j = 0; j < pipes.size(); j++) {
						if (pipes.at(j).first == connected.at(i)) {
							for (unsigned int k = 0; k < pipes.at(j).second.size(); k++) {
								if (not_found(pipes.at(j).second.at(k), connected)) {
									connected.push_back(pipes.at(j).second.at(k));
								}
							}
						}
					}
				}
			} while (size != connected.size());

			n_groups++;
			groups.push_back(connected);
		}
	}

	cout << "number of groups = " << n_groups << endl;

	return 0;
}