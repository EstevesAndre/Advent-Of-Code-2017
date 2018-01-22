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
	
	vector<int> connected = { 0 };
	for (unsigned int i = 0; i < pipes.at(0).second.size(); i++) {
		connected.push_back(pipes.at(0).second.at(i));
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
	} while (size != connected.size() );
	
	cout << "size = " << connected.size() << endl;

	return 0;
}