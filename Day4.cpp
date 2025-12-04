#include "Header.h"

using namespace std;



int day4(std::string path) {

	int ans = 0;

	std::ifstream in(path); // the in flag is optional

	if (!in.is_open()) {
		return -1;
	}

	string line;

	vector<string> grid;

	while (getline(in, line)) {

		grid.push_back(line);

	}

	for (int i = 0; i < grid.size(); ++i) {

		for (int j = 0; j < grid[i].size(); ++j) {

			int papers = 0;

			if (grid[i].substr(j, 1) == "@") {

				if ((i - 1) >= 0 && (j - 1) >= 0)							papers += grid[i - 1].substr(j - 1, 1) == "@" ? 1 : 0;
				if ((i - 1) >= 0)										papers += grid[i - 1].substr(j, 1) == "@" ? 1 : 0;
				if ((i - 1) >= 0 && (j + 1) < grid[i - 1].size())		papers += grid[i - 1].substr(j + 1, 1) == "@" ? 1 : 0;
				if ((j - 1) >= 0)										papers += grid[i].substr(j - 1, 1) == "@" ? 1 : 0;
				if ((j + 1) < grid[i].size())							papers += grid[i].substr(j + 1, 1) == "@" ? 1 : 0;
				if ((i + 1) < grid.size() && (j - 1) >= 0)				papers += grid[i + 1].substr(j - 1, 1) == "@" ? 1 : 0;
				if ((i + 1) < grid.size())								papers += grid[i + 1].substr(j, 1) == "@" ? 1 : 0;
				if ((i + 1) < grid.size() && (j + 1) < grid[i].size())	papers += grid[i + 1].substr(j + 1, 1) == "@" ? 1 : 0;



				if (papers < 4) ans++;


			}




		}


	}



	return ans;

}


int day4_2(std::string path) {



	int ans = 0;

	std::ifstream in(path); // the in flag is optional

	if (!in.is_open()) {
		return -1;
	}

	string line;

	vector<string> grid;
	vector<string> grid2;

	while (getline(in, line)) {

		grid.push_back(line);

	}

	bool isPaperFound = true;
	grid2 = grid;

	while (isPaperFound) {

		grid = grid2;
		isPaperFound = false;

		for (int i = 0; i < grid.size(); ++i) {

			for (int j = 0; j < grid[i].size(); ++j) {

				int papers = 0;

				if (grid[i].substr(j, 1) == "@") {

					if ((i - 1) >= 0 && (j - 1) >= 0)							papers += grid[i - 1].substr(j - 1, 1) == "@" ? 1 : 0;
					if ((i - 1) >= 0)										papers += grid[i - 1].substr(j, 1) == "@" ? 1 : 0;
					if ((i - 1) >= 0 && (j + 1) < grid[i - 1].size())		papers += grid[i - 1].substr(j + 1, 1) == "@" ? 1 : 0;
					if ((j - 1) >= 0)										papers += grid[i].substr(j - 1, 1) == "@" ? 1 : 0;
					if ((j + 1) < grid[i].size())							papers += grid[i].substr(j + 1, 1) == "@" ? 1 : 0;
					if ((i + 1) < grid.size() && (j - 1) >= 0)				papers += grid[i + 1].substr(j - 1, 1) == "@" ? 1 : 0;
					if ((i + 1) < grid.size())								papers += grid[i + 1].substr(j, 1) == "@" ? 1 : 0;
					if ((i + 1) < grid.size() && (j + 1) < grid[i].size())	papers += grid[i + 1].substr(j + 1, 1) == "@" ? 1 : 0;



					if (papers < 4) {
						grid2[i][j] = '.';
						isPaperFound = true;
						ans++;
					} 


				}

			}


		}
	}




	return ans;

}