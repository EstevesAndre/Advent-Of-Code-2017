#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool not_found(string newregister, vector<pair<string, int> > registers) {
	for (unsigned int i = 0; i < registers.size(); i++) {
		if (registers.at(i).first == newregister)
			return false;
	}
	return true;
}

void update_register(string reg, string inc_dec, int value, string reg_cond, string signal, int value_cond, vector<pair<string, int> > &registers) {

	for (unsigned int i = 0; i < registers.size(); i++)
	{
		if (registers.at(i).first == reg) //registor to be set
		{
			for (unsigned int j = 0; j < registers.size(); j++)
			{
				if (registers.at(j).first == reg_cond) // registor to be compared
				{
					if (signal == "==")
					{
						if (registers.at(j).second == value_cond) // comparation
						{
							if (inc_dec == "inc") { //increment
								registers.at(i).second += value;
							}
							else // decrement
							{
								registers.at(i).second -= value;
							}
						}
					}
					else if (signal == "<=")
					{
						if (registers.at(j).second <= value_cond) // comparation
						{
							if (inc_dec == "inc") { //increment
								registers.at(i).second += value;
							}
							else // decrement
							{
								registers.at(i).second -= value;
							}
						}
					}
					else if (signal == ">=")
					{
						if (registers.at(j).second >= value_cond) // comparation
						{
							if (inc_dec == "inc") { //increment
								registers.at(i).second += value;
							}
							else // decrement
							{
								registers.at(i).second -= value;
							}
						}
					}
					else if (signal == "<")
					{
						if (registers.at(j).second < value_cond) // comparation
						{
							if (inc_dec == "inc") { //increment
								registers.at(i).second += value;
							}
							else // decrement
							{
								registers.at(i).second -= value;
							}
						}

					}
					else if (signal == ">")
					{
						if (registers.at(j).second > value_cond) // comparation
						{
							if (inc_dec == "inc") { //increment
								registers.at(i).second += value;
							}
							else // decrement
							{
								registers.at(i).second -= value;
							}
						}
					}
					else if (signal == "!=")
					{
						if (registers.at(j).second != value_cond) // comparation
						{
							if (inc_dec == "inc") { //increment
								registers.at(i).second += value;
							}
							else // decrement
							{
								registers.at(i).second -= value;
							}
						}
					}
					else
					{
						//do nothing;
					}
					return;
				}
			}
		}
	}
}

int main() {
	ifstream in("C:\\Users\\André\\Documents\\GitHub\\Advent-Of-Code-2017\\Day-8\\Input.txt");

	if (in.fail()) {
		cout << "Failed to open the file\n";
	}

	int max_value = 0; // assuming that the maximum value is greater that 0;

	vector<pair<string, int> > registers;
	string line;

	while (!in.eof()) {
		getline(in, line);
		stringstream part(line);
		string newregister, inc_dec, iff, regist_cond, signal_compar;
		int value, value_cond;
		part >> newregister;
		part >> inc_dec;
		part >> value;
		part >> iff; // ignored
		part >> regist_cond;
		part >> signal_compar;
		part >> value_cond;

		if (not_found(newregister, registers)) { // add the register if it is the first time, set count to 0
			pair<string, int> reg = make_pair(newregister, 0);
			registers.push_back(reg);
		}
		if (not_found(regist_cond, registers)) { // add the register if it is the first time, set count to 0
			pair<string, int> reg = make_pair(regist_cond, 0);
			registers.push_back(reg);
		}

		update_register(newregister, inc_dec, value, regist_cond, signal_compar, value_cond, registers);
		for (unsigned int i = 0; i < registers.size(); i++) {
			if (registers.at(i).second > max_value)
				max_value = registers.at(i).second;
		}
	}
	in.close();

	cout << "Max Value = " << max_value << endl;

	return 0;
}