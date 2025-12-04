#include "Header.h"

using namespace std;



int day3(std::string path) {

	int ans = 0;

	std::ifstream in(path); // the in flag is optional

	if (!in.is_open()) {
		return -1;
	}

	string line;

	while (getline(in, line)) {

		bool found = false;

		
		cout << line << endl;

		for (int i = 9; i > 0; i--) {

			if (found) break;

			size_t greatestFirst = line.find_first_of(to_string(i));

				if (greatestFirst != std::string::npos) {

					for (int j = 9; j > 0; j--) {

						if (line.find_first_of(to_string(j), greatestFirst+1) != std::string::npos) {

							ans += i * 10 + j;
							cout << ans << endl;

							found = true;
							break;
						}
					}
				}

		}



	}

	return ans;

}


int day3_2(std::string path){


	unsigned long long ans = 0;

	std::ifstream in(path); // the in flag is optional

	if (!in.is_open()) {
		return -1;
	}

	string line;

	cout << line << endl;

	while (getline(in, line)) {

		string current = "";
		int leftIndex = 0;

		cout << line << endl;

		for (int k = 0; k < 11; k++) {


			for (int i = current.length(); i < line.length() ; ++i) {

				int n =(char) (line[i] -  '0');

				auto greatest = find_if(line.begin()+ i + current.length(), line.end() - current.length(), [n](int element) { return (n > element); });

				if (greatest != line.end()) {


					current += to_string(n);

					break;
						
					
				}

			}



		}
		cout << current << endl;

		ans += stoll(current);


	}

	return ans;


}