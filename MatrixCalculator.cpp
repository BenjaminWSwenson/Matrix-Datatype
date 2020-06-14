#include <iostream>
#include <vector>
#include "matrix.h"

int main(){
	std::vector<std::vector<double>> v{{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}, {7.7, 8.8, 9.9}};
	std::vector<std::vector<double>> b{{1.0, 2.0}, {3.0, 4.0}};
	
	Matrix V(v);
	Matrix B(b);
	
	V.print(5);
	
	std::cout << "\n";
	
	Matrix A = V + V;
	
	A.print(5);
	
	// Should abort after this line, as V is 3x3 and B is 2x2
	Matrix Q = V + B;

	return 0;
}
