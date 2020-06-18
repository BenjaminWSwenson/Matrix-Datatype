#include <vector>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <atomic>
#include <thread>
#include "Matrix.hpp"

// Global variables for threading
std::vector<std::vector<double>> multiSecond;
std::vector<std::vector<double>> multiResult;
std::vector<std::vector<double>> multiFirst;
std::atomic_int step_i(0);

void Matrix::multi(){
	int core = step_i++;
			
	for(int i = core; i < core + 1; i++){
		for(int j = 0; j < multiSecond[0].size(); j++){
			for(int k = 0; k < multiFirst[0].size(); k++){
				multiResult[i][j] += multiFirst[i][k] * multiSecond[k][j];
			}
		}
	}
}
Matrix::Matrix(){
	matrix = std::vector<std::vector<double>> {{}};
	rows = 0;
	columns = 0;
}
		
Matrix::Matrix(std::vector<std::vector<double>> input){
	matrix = input;
	rows = matrix.size();
	columns = matrix[0].size();
}
		
void Matrix::print(int decimal){
	std::cout << std::fixed;
	std::cout << std::setprecision(decimal);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}
		
Matrix Matrix::operator + (const Matrix &obj){
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
		
Matrix Matrix::operator - (const Matrix &obj){
	// Checks to see if matricies are the same size
	if(rows != obj.rows || columns != obj.columns){
		throw std::invalid_argument("Matrices are not of the same dimensions");
	}
	Matrix result(matrix);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			result.matrix[i][j] -= obj.matrix[i][j];
		}
	}
	return result;
}
		
Matrix Matrix::operator * (const Matrix &obj){
	if(columns != obj.rows){
		throw std::invalid_argument("Matrices are not of multipliable dimensions");
	}
	multiResult = std::vector<std::vector<double>>
		(rows, std::vector<double>(obj.columns));
	multiSecond = obj.matrix;
	multiFirst = matrix;
	std::vector<std::thread> threads(rows);
	step_i = 0;
	
	for(int i = 0; i < rows; i++) { 
		threads[i] = std::thread(multi);
	}
	
	for(int i = 0; i < rows; i++){  
		threads[i].join();
	}
	Matrix product(multiResult);
	return product;
}
		
Matrix Matrix::T(){
	Matrix result(std::vector<std::vector<double>> 
		(columns, std::vector<double>(rows)));
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			result.matrix[j][i] = matrix[i][j];
		}
	}
	return result;
}
		
double Matrix::det(){
	if(rows != columns){
		throw std::invalid_argument("Matrix is not square");
	}
			
}

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
