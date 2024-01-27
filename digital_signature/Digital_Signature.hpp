#pragma once

#include <iostream>
#include <ctime>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>

//DECLARATION
std::fstream get_file_from_user_input();
std::fstream get_file_from_arguments(const std::string& file_name);
void write_to_the_file(std::fstream& from, std::ofstream& to);
bool check_numbers_format(const std::string line);
void create_file_without_signature(std::fstream& file);
void create_file_with_signature(std::fstream& file, const std::string& signature);
void create_file_without_changes(std::fstream& file);
void reset_file_to_the_beginning(std::fstream& file);


struct Digital_Signature {
    bool check_for_file(std::fstream& file);
    std::string create();
};



//DEFINITION
std::fstream get_file_from_arguments(const std::string& file_name) {
    return std::fstream(file_name);
}


std::fstream get_file_from_user_input() {
    std::cout << "Enter file name: ";
    std::string file_name;
    std::cin >> file_name;
    return std::fstream(file_name);
}

//copy information from to
void write_to_the_file(std::fstream& from, std::ofstream& to) {
    std::string line;
    while (std::getline(from, line))
    {
        to << line << '\n';
    }  
}

//format line example: SatJan2716:30:332024, but we need only 2716:30:332024
bool check_numbers_format(const std::string line) {
    //correct format for new line is: number:number:number
    //if new line is not format like: number:number:number - return false
    std::istringstream input( {line.begin() + 6, line.end()} );

    int number;
    bool flag = false;
    int count_of_numbers = 3;
    for (size_t i = 0; i < count_of_numbers; ++i)
    {
        if(flag) {
            if(input.peek() != ':') { return false; }
            input.ignore(1);
        }
        if( !(input >> number) ) { return false; }
        flag = true;
    }

    //format correct
    return true;
}

//file shifted of one line, which contains digital signature, so we can copy to new file directly
void create_file_without_signature(std::fstream& file) {
    std::ofstream output("result.txt");
    write_to_the_file(file, output);
}


void create_file_with_signature(std::fstream& file, const std::string& signature) {
    std::ofstream output("result.txt");
    output << signature << '\n';
    //we take fisrt line from file, so we must return it
    reset_file_to_the_beginning(file);
    write_to_the_file(file, output);
}

void create_file_without_changes(std::fstream& file) {
	std::ofstream output("result.txt");
    //we take fisrt line from file, so we must return it
    reset_file_to_the_beginning(file);
    write_to_the_file(file, output);
}


void reset_file_to_the_beginning(std::fstream& file) {
    file.clear();
    file.seekg(0, std::ios::beg);
}


//take first line from file, and check is it digital signature or not
bool Digital_Signature::check_for_file(std::fstream& file) {
    std::string first_line;

    //check for file not empty
    if(!std::getline(file, first_line)) {
        return false;
    }

    //check for correct format of day and month, see function create_for_file for more detalization
    if (
        !(std::isupper(first_line[0]) && std::isupper(first_line[3]))
    ) { return false;}

    //65 - A, 122 - z
    bool flag = 
        std::all_of(
            first_line.begin(), first_line.begin()+6, [](char s) {return s > 64 && s < 123;}
        );
    if (!flag) { return false; }
    
    flag = check_numbers_format(first_line);
    if (!flag) { return false; }

    //finaly on this line we have correct digital signature
    return true;
}


//we gonna use current date as the digital signature, every second there are new date and can create new signature
//format of date example: Sat Jan 27 16:30:33 2024
//but we sholud remove spaces from date string, because we do not want to confuse signature as date
std::string Digital_Signature::create() {
	using system_clock =  std::chrono::system_clock;
	std::time_t time = system_clock::to_time_t(system_clock::now());
	std::string result = std::ctime(&time);

	//now result consist extra '\n' symbol at the end, we should remove it
	result.erase(result.size() - 1);
	
	//also, we gonna remove all spaces from string
	auto new_end = std::remove(result.begin(), result.end(), ' ');
	result.erase(new_end, result.end());

	return std::move(result);
}
