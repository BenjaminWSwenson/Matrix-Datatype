#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

class Matrix{
	private:
		int rows;
		int columns;
		static void multi();
	public:
		std::vector<std::vector<double>> matrix;
		Matrix();
		Matrix(std::vector<std::vector<double>> input);
		int getRows() const{ return rows; }
		int getColumns() const{ return columns; }
		void print(int decimal);
		std::vector<double> operator [] (int i);
		Matrix operator + (const Matrix &ob);
		Matrix operator - (const Matrix &obj);
		Matrix operator * (const Matrix &obj);
		Matrix T();
		double det();
};
Matrix I(int size);
// Scalar * overloading functions defined outside of class to achieve communitivity
Matrix operator * (const Matrix &mtx, const double &obj);
Matrix operator * (const double &obj, const Matrix &mtx);	
Matrix operator * (const int &obj, const Matrix &mtx);
Matrix operator * (const Matrix &mtx, const int &obj);
#endif
