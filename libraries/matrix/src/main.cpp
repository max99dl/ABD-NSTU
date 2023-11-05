#include "matrix.h"
#include<iostream>
#include<vector>
#include<utility>


int main() {
			{
	std::size_t n = 10;
	std::vector<double> m1, m2, m3(n*n);
	std::pair<double, double> range = {0.0, 1.0};
	matrix::generate_real(m1, n, range);
	matrix::generate_real(m2, n, range);
	matrix::reverse_multiplication(m1, m2, m3, n);
	matrix::print_matrix(m1, n, 2);
	}

	{
	std::size_t n = 10;
	std::vector<int> m1, m2, m3(n*n);
	std::pair<int, int> range = {0, 5};
	matrix::generate_int(m1, n, range);
	matrix::generate_int(m2, n, range);
	matrix::reverse_multiplication(m1, m2, m3, n);
	matrix::print_matrix(m1, n, 2);
	}

	return 0;
}
