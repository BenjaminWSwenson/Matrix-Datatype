#include <vector>
#include <iostream>
#include <stdexcept>
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
		
		int getRows() const{
			return rows;
		}
		
		int getColumns() const{
			return columns;
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
				throw std::invalid_argument("Matrices are not of the same dimensions");
			}
			Matrix result(obj.matrix);
			for(int i = 0; i < rows; i++){
				for(int j = 0; j < columns; j++){
					result.matrix[i][j] += matrix[i][j];
				}
			}
			return result;
		}
		
		Matrix operator * (const Matrix &obj){
			// Checks to see if columns of first matrix match rows of th second
			if(columns != obj.rows){
				throw std::invalid_argument("Matrices are not of multipliable dimensions");
			}
			Matrix result(std::vector<std::vector<double>>(rows, std::vector<double>(obj.columns)));
			for(int i = 0; i < rows; i++){
				for(int j = 0; j < obj.columns; j++){
					for(int k = 0; k < columns; k++){
						result.matrix[i][j] += matrix[i][k] * obj.matrix[k][j];
					}
				}
			}
			return result;
		}
};

// Scalar * overloading functions defined outside of class to achieve communitivity
Matrix operator * (const Matrix &mtx, const double &obj){
	Matrix result(mtx.matrix);
	for(int i = 0; i < mtx.getRows(); i++){
		for(int j = 0; j < mtx.getColumns(); j++){
			result.matrix[i][j] *= obj;
		}
	}
	return result;
}
		
Matrix operator * (const double &obj, const Matrix &mtx){
	return mtx * obj;
}
		
Matrix operator * (const int &obj, const Matrix &mtx){
	Matrix result(mtx.matrix);
	for(int i = 0; i < mtx.getRows(); i++){
		for(int j = 0; j < mtx.getColumns(); j++){
			result.matrix[i][j] *= obj;
		}
	}
	return result;
}
		
Matrix operator * (const Matrix &mtx, const int &obj){
	return obj * mtx;
}
