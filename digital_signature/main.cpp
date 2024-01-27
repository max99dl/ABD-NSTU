#include <iostream>
#include <string>
#include "Digital_Signature.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	//in command line arguments you do not need to specify output file, there will automatically generate result.txt
	//create file, which file name from command line arguments or from user input
	fstream file = (argc < 2) ? get_file_from_user_input() : get_file_from_arguments(argv[1]);
	//check for correct open
	if(!file) {
		cout << "Some problems with file." << endl;
		exit(EXIT_FAILURE);
	}
	//create digital signature
	Digital_Signature dig_signa;
	
	//check for signature existence in file
	bool check_ok = dig_signa.check_for_file(file);
	
	if(check_ok) {
		cout << "file already has digital signature.\n";
		cout << "Enter: 1 if you want to delete the digital signature.\n"
				 << "Enter: 0 if you do not want to delete the digital signature.\n";
		int result;
		cin >> result;
		if(result) {
			//create copy of file but without signature
			create_file_without_signature(file);
		} else {
			//create copy of file
			create_file_without_changes(file);
		}
	} else {
		cout << "there are not digital signature in file\n";
		cout << "Enter: 1 if you want to create a digital signature.\n"
			 << "Enter: 0 if you do not want to create a digital siganture.\n";
		int result;
		cin >> result;
		if(result) {
			//create copy of file but add signature
			create_file_with_signature(file, dig_signa.create());
		} else {
			//create copy of file
			create_file_without_changes(file);
		}
	}
}
