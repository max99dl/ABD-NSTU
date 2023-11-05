#include "matrix.h"

namespace matrix {

//to access matrix(i,j) element
constexpr size_t to_index(size_t i, size_t j, size_t ncol) {
	return i * ncol + j;
}

void print_matrix(const std::vector<int>& matrix, const size_t n, const size_t precision) {
	bool flag = false;

	for(size_t i = 0; i < n; ++i) {
		for(size_t j = 0; j < n; ++j) {
			if(flag) {
				std::cout << ' ';
			}
			std::cout << std::setprecision(precision)
								<< std::fixed
								<< std::setw(6)
								<< matrix[to_index(i,j,n)];
			flag = true;
		}
		std::cout << '\n';
		flag = false;
	}
}


void print_matrix(const std::vector<double>& matrix, const size_t n, const size_t precision) {
	bool flag = false;

	for(size_t i = 0; i < n; ++i) {
		for(size_t j = 0; j < n; ++j) {
			if(flag) {
				std::cout << ' ';
			}
			std::cout << std::setprecision(precision)
								<< std::fixed
								<< std::setw(6)
								<< matrix[to_index(i,j,n)];
			flag = true;
		}
		std::cout << '\n';
		flag = false;
	}
}


//generate a real matrix NxN size
void generate_real(std::vector<double>& m, size_t n,
																	const std::pair<double, double> range) {
	std::random_device rnd;
	std::mt19937 gen(rnd());
	std::uniform_real_distribution<double> dis(range.first, range.second);
	m.resize(n*n); //NxN matrix
	std::generate_n(m.begin(), m.size(), [&](){ return dis(gen); }); //fill matrix with elements dis(gen)
}


//generate an integer matrix NxN size
void generate_int(std::vector<int>& m, size_t n,
																	const std::pair<int, int> range) {
	std::random_device rnd;
	std::mt19937 gen(rnd());
	std::uniform_int_distribution<int> dis(range.first, range.second);
	m.resize(n*n); //NxN matrix
	std::generate_n(m.begin(), m.size(), [&](){ return dis(gen); }); //fill matrix with elements dis(gen)
}

/*
template<typename T>
static void matrix::naive_multiplication(const std::vector<T>& m1,
																 const std::vector<T>& m2,
																 std::vector<T>& result,
																 const size_t n) {
	for(size_t i = 0; i < n; ++i) {
		for(size_t j = 0; j < n; ++j) {
			result[to_index(i,j,n)] = 0.0;
			for(size_t k = 0; k < n; ++k) {
				result[to_index(i,j,n)] += m1[to_index(i,k,n)] * m2[to_index(k,j,n)];
			}
		}
	}
}
*/

void reverse_multiplication(const std::vector<int>& m1,
																 const std::vector<int>& m2,
																 std::vector<int>& result,
																 const size_t n) {
	std::fill(result.begin(), result.end(), 0);
	for(size_t i = 0; i < n; ++i) {
		for(size_t k = 0; k < n; ++k) {
			for(size_t j = 0; j < n; ++j) {
				result[to_index(i,j,n)] += m1[to_index(i,k,n)] * m2[to_index(k,j,n)];
			}
		}
	}
}


void reverse_multiplication(const std::vector<double>& m1,
																 const std::vector<double>& m2,
																 std::vector<double>& result,
																 const size_t n) {
	std::fill(result.begin(), result.end(), 0.0);
	for(size_t i = 0; i < n; ++i) {
		for(size_t k = 0; k < n; ++k) {
			for(size_t j = 0; j < n; ++j) {
				result[to_index(i,j,n)] += m1[to_index(i,k,n)] * m2[to_index(k,j,n)];
			}
		}
	}
}



void multy_thread_multiplication(const std::vector<int>& m1,
																				const std::vector<int>& m2,
																				std::vector<int>& result,
																				const size_t n) {
	size_t count_of_threads = std::min(n, static_cast<size_t>(std::thread::hardware_concurrency()));
	
	if(!count_of_threads) {
		count_of_threads = 1;
	}
	size_t rows_per_thread = n / count_of_threads;
	std::vector<std::future<void>> tasks;

	for(size_t t = 0; t < count_of_threads; ++t) {
		tasks.emplace_back(std::async(std::launch::async,
											 						[&](size_t from, size_t to){
			for(size_t i = from; i < to; ++i) {
				for(size_t j = 0; j < n; ++j) {
					for(size_t k = 0; k < n; ++k) {
						result[to_index(i,j,n)] += m1[to_index(i,k,n)] * m2[to_index(k,j,n)];
					}
				}
			}
		}, t*rows_per_thread, (t+1)*rows_per_thread));
	}
	
	for(auto& f: tasks) {
		f.wait();
	}
}


void multy_thread_multiplication(const std::vector<double>& m1,
																				const std::vector<double>& m2,
																				std::vector<double>& result,
																				const size_t n) {
	size_t count_of_threads = std::min(n, static_cast<size_t>(std::thread::hardware_concurrency()));
	
	if(!count_of_threads) {
		count_of_threads = 1;
	}
	size_t rows_per_thread = n / count_of_threads;
	std::vector<std::future<void>> tasks;

	for(size_t t = 0; t < count_of_threads; ++t) {
		tasks.emplace_back(std::async(std::launch::async,
											 						[&](size_t from, size_t to){
			for(size_t i = from; i < to; ++i) {
				for(size_t j = 0; j < n; ++j) {
					for(size_t k = 0; k < n; ++k) {
						result[to_index(i,j,n)] += m1[to_index(i,k,n)] * m2[to_index(k,j,n)];
					}
				}
			}
		}, t*rows_per_thread, (t+1)*rows_per_thread));
	}
	
	for(auto& f: tasks) {
		f.wait();
	}
}

}
