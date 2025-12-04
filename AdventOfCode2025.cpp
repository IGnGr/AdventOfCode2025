
#include "Header.h"

int main(int argc, char* argv[])
{

	if(argc != 2 ) {
		std::cout << "Usage: AdventOfCode2025 <input_file>" << std::endl;
		return 1;
	}


	std::cout << "answer 1:" << day4(argv[1]) << std::endl;;
	std::cout << "answer 2:" << day4_2(argv[1]) << std::endl;;

	return 0;


}
