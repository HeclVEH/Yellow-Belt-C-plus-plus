#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <exception>

using namespace std;

// Реализуйте здесь

// * класс Matrix
class Matrix {	
public:
	Matrix() {
		rows = 0;
		cols = 0;		
	}
	Matrix(const int& rs, const int cs) {		
		Reset(rs, cs);	
	}
	void Reset(int rs, int cs) {
		if (rs < 0) {
			throw out_of_range("Rows must be >= 0");
		}
		if (cs < 0) {
			throw out_of_range("Columns must be >= 0");
		}
		if (rs == 0 || cs == 0) {
			rs = cs = 0;
		}
		rows = rs;
		cols = cs;		
		matr.assign(rows, vector<int>(cols));
	}	
	int At(const int& i, const int& j) const{
		return matr.at(i).at(j);
	}
	int& At(const int& i, const int& j) {
		return matr.at(i).at(j);
	}
	int GetNumRows() const {
		return rows;
	}
	int GetNumColumns() const {
		return cols;
	}
private:
	int rows, cols;
	vector<vector<int>> matr;
};
// * оператор ввода для класса Matrix из потока istream
istream& operator >> (istream& stream, Matrix& matr) {
	int rows, cols;
	stream >> rows >> cols;
	matr.Reset(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			stream >> matr.At(i, j);
		}
	}
	return stream;
}
// * оператор вывода класса Matrix в поток ostream
ostream& operator << (ostream& stream, const Matrix& matr) {
	int rows, cols;
	rows = matr.GetNumRows();
	cols = matr.GetNumColumns();
	stream << rows << " " << cols << endl;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (j > 0) {
				stream << " ";
			}
			stream << matr.At(i, j);
		}
		stream << endl;
	}
	return stream;
}
// * оператор проверки на равенство двух объектов класса Matrix
bool operator == (const Matrix& rhs, const Matrix& lhs) {
	if (rhs.GetNumRows() != lhs.GetNumRows() && rhs.GetNumColumns() != lhs.GetNumColumns()) {
		return false;
	}
	for (int i = 0; i < rhs.GetNumRows(); ++i) {
		for (int j = 0; j < rhs.GetNumColumns(); ++j) {
			if (rhs.At(i, j) != lhs.At(i, j)) {
				return false;
			}
		}
	}
	return true;
}
// * оператор сложения двух объектов класса Matrix
Matrix operator + (const Matrix& rhs, const Matrix& lhs) {
	if (rhs.GetNumRows() != lhs.GetNumRows()) {
		throw invalid_argument("Error rows");
	}
	if (rhs.GetNumColumns() != lhs.GetNumColumns()) {
		throw invalid_argument("Error columns");
	}
	int rows, cols;
	rows = rhs.GetNumRows();
	cols = rhs.GetNumColumns();
	Matrix result(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			result.At(i, j) = rhs.At(i, j) + lhs.At(i, j);
		}
	}
	return result;
}

int main() {
	Matrix m1(0, 5), m2(3, 0);
	cout << boolalpha << (m1 == m2) << endl;
	return 0;
}
/*
int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two << endl;
	return 0;
}
*/