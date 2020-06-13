#include <iostream>
#include <vector>
#include <string>
#include "matrix.h"

int main(){
	std::vector<std::vector<double>> v{{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}, {7.7, 8.8, 9.9}};
	
	Matrix V(v);
	
	V.print();
	
	std::cout << "\n";
	
	Matrix A = V + V;
	
	A.print();

	return 0;
}
