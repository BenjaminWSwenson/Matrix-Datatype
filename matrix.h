#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>

class Matrix{
	private:
		int rows;
		int columns;
	public:
		std::vector<std::vector<double>> matrix;
		
		Matrix(){
			matrix = std::vector<std::vector<double>> {{}};
			rows = 0;
			columns = 0;
		}
		
		Matrix(std::vector<std::vector<double>> input){
			matrix = input;
			rows = matrix.size();
			columns = matrix[0].size();
		}
		
		void print(int decimal){
			std::cout << std::fixed;
			std::cout << std::setprecision(decimal);
			for(int i = 0; i < rows; i++){
				for(int j = 0; j < columns; j++){
					std::cout << matrix[i][j] << " ";
				}
				std::cout << "\n";
			}
		}
		
		Matrix operator + (const Matrix &obj){
			// Checks to see if matricies are the same size
			if(rows != obj.rows || columns != obj.columns){
				throw std::invalid_argument("Matricies are not of the same dimensions");
			}
			Matrix result(obj.matrix);
			for(int i = 0; i < rows; i++){
				for(int j = 0; j < columns; j++){
					result.matrix[i][j] += matrix[i][j];
				}
			}
			return result;
		}
};
