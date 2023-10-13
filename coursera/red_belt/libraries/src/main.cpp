#include<iostream>
#include<utility>
#include "SimpleVector.h"

int main() {
	SimpleVector<int> first(5);
	SimpleVector<int> second;
	second = std::move(first);
	std::cout << first.size() << ' ' << second.size() << std::endl;
	return 0;
}
