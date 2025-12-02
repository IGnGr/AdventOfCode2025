#include "Header.h"
#include "Utils.h"
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

using namespace std;

cpp_int day2(std::string path) {


	std::ifstream in(path); // the in flag is optional

	if (!in.is_open()) {
		return -1;
	}
	

	cpp_int ans = 0;

	char separator = ',';
	string line;
	vector<string> tokens;

	while (getline(in, line)) {

		vector<string> lineTokens = split(line, separator);
		for (string s : lineTokens) tokens.push_back(s);

	}

	
	for (string token : tokens) {

		vector<string> range = split(token, '-');

		long long  begin = stoll(range[0]);
		long long  end = stoll(range[1]);
		
		for (long long  i = begin;  i <= end; ++i) {

			int digits[10] = { };

			string number = to_string(i);

			if (number.substr(0,1) == "0") {
				continue;
			}

			/*			for (char c : number) digits[(c - '0')]++;


			for (int n : digits) {
				if (n == 2) {
					ans+=i;
					cout << "number added: " << i << endl;
					break;
				}
				 
			}*/

			if (number.substr(0, number.length() / 2) == number.substr(number.length() / 2)) {
				ans += i;
			}

		}
		
		



	}



	return ans;

}

cpp_int day2_2(std::string path) {

	std::ifstream in(path); // the in flag is optional

	if (!in.is_open()) {
		return -1;
	}


	cpp_int ans = 0;

	char separator = ',';
	string line;
	vector<string> tokens;

	while (getline(in, line)) {

		vector<string> lineTokens = split(line, separator);
		for (string s : lineTokens) tokens.push_back(s);

	}


	for (string token : tokens) {

		vector<string> range = split(token, '-');

		long long  begin = stoll(range[0]);
		long long  end = stoll(range[1]);

		for (long long i = begin; i <= end; ++i) {

			int digits[10] = { };

			string number = to_string(i);

			if (number.substr(0, 1) == "0") {
				continue;
			}

			/*			for (char c : number) digits[(c - '0')]++;


			for (int n : digits) {
				if (n == 2) {
					ans+=i;
					cout << "number added: " << i << endl;
					break;
				}

			}*/

			for (int j = 2; j <= number.length(); ++j) {
				if (repeatString(number.substr(0, number.length() / j), j) == number) {
					//cout << i << endl;
					ans += i;
					break;
				}
			}


		}




	}



	return ans;
}