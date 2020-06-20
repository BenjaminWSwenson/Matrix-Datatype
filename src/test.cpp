#include <iostream>
#include <vector>
#include "Matrix.hpp"

// This file serves as a test file for the time being

int main(){
	std::vector<std::vector<double>> v{{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}, {7.7, 8.8, 9.9}};
	std::vector<std::vector<double>> b{{1.0, 2.0}, {3.0, 4.0}};
	
	Matrix V(v);
	Matrix B(b);
	
	Matrix A = V + V;
	
	A.print(5);
	
	std::cout << "\n";
	
	A = V - V;
	
	A.print(5);
	
	std::cout << "\n";
	
	Matrix C = B * 2.0;
	
	C.print(3);
	
	std::cout << "\n";
	
	C = B * 2;
	
	C.print(3);
	
	std::cout << "\n";
	
	C = 2.0 * B;
	
	C.print(3);
	
	std::cout << "\n";
	
	std::vector<std::vector<double>> u {{1, 2, 3}, {3, 2, 1}, {2, 1, 3}, {3, 1, 2}};
	std::vector<std::vector<double>> w {{1, 2, 3}, {2, 4, 1}, {1, 3, 2}};
	
	Matrix U(u);
	Matrix W(w);
	
	U.print(3);
	
	std::cout << "\n";
	
	W.print(3);
	
	std::cout << "\n";
	
	Matrix X = U * W;
	
	X.print(3);
	
	std::cout << "\n";
	
	X = U.T();
	
	X.print(3);
	
	std::cout << "\n";
	
	Matrix P = I(5);
	
	P.print(1);
	
	std::cout << "\n";
	
	double num = P[3][3];
	
	std::cout << num << "\n";
	
	num = B.det();

	std::cout << num << "\n";

	return 0;
}
