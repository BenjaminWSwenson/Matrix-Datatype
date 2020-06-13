#include <vector>

class Matrix{
	private:
		int rows;
		int columns;
		
	public:
		std::vector<std::vector<double>> matrix;
		
		Matrix(){
			matrix = std::vector<std::vector<double>> ();
			rows = 0;
			columns = 0;
		}
		
		Matrix(std::vector<std::vector<double>> input){
			matrix = input;
			rows = matrix.size();
			columns = matrix[0].size();
		}
};
