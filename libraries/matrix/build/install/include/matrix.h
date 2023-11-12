#pragma once

#include<vector>
#include<iostream>
#include<algorithm>
#include<thread>
#include<random>
#include<iomanip>
#include<future>
#include<utility>

namespace matrix{
	constexpr size_t to_index(size_t row, size_t column, size_t number_of_columns);
	
	void print_matrix(const std::vector<int>& matrix, const size_t number_of_columns,
										const size_t precision=2);

	void print_matrix(const std::vector<double>& matrix, const size_t number_of_columns,
										const size_t precision=2);

	void generate_int(std::vector<int>& matrix, size_t number_of_columns,
													 const std::pair<int, int> min_max_range);

	void generate_real(std::vector<double>& matrix, size_t number_of_columns,
														const std::pair<double, double> min_max_range);

/*	template<typename T>
	static void naive_multiplication(const std::vector<T>& matrix1,
																	 const std::vector<T>& matrix2,
																	 const std::vector<T>& result_matrix,
																	 const size_t number_of_columns);
*/
	void reverse_multiplication(const std::vector<int>& matrix1,
															const std::vector<int>& matrix2,
															std::vector<int>& result_matrix,
															const size_t number_of_columns);

	void reverse_multiplication(const std::vector<double>& matrix1,
															const std::vector<double>& matrix2,
															std::vector<double>& result_matrix,
															const size_t number_of_columns);

	void multy_thread_multiplication(const std::vector<int>& matrix1,
																	 const std::vector<int>& matrix2,
																	 std::vector<int>& result_matrix,
																	 const size_t number_of_columns);

	void multy_thread_multiplication(const std::vector<double>& matrix1,
																	 const std::vector<double>& matrix2,
																	 std::vector<double>& result_matrix,
																	 const size_t number_of_columns);
}

//#include "matrix.cpp"
