#include "Header.h"

int day1(std::string path) {
	
	int ans = 0;
	int dial = 50;
	std::ifstream in(path); // the in flag is optional

	if (!in.is_open()) {
		return -1;
	}

	char letter;
	long n;

	while (in >> letter >> n) {

		if (letter == 'L') {



			dial = (dial - n) % 100;

		}
		else {
			
			dial = (dial + n) % 100;
		}
		 

		if (dial == 0) {
			ans++; 
			 
		} 


	}



	return ans;
} 

int day1_2(std::string path) {

	int ans = 0;
	int dial = 50;
	std::ifstream in(path); // the in flag is optional

	if (!in.is_open()) {
		return -1;
	}

	char letter;
	long n;
	int lastDial = dial;

	while (in >> letter >> n) {


		if (letter == 'L') {

			dial -=n ;

			if (dial <= -100) {
				ans += abs(dial) / 100;
			}

		} else {

			dial += n ;

			if (dial >= 100) {
				ans += dial / 100;
			}
		}



		if (dial == 0) {
			ans++;

		}
		if (lastDial > 0 && dial < 0 || lastDial < 0 && dial > 0) ans++;

		dial %= 100;


		lastDial = dial;


	}
	return ans;
	 
}