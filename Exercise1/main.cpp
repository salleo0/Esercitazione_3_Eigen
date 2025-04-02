#include <iostream>
#include <Eigen/Eigen>

using namespace std;
using namespace Eigen;

MatrixXd Shape(unsigned int n) {
	VectorXd v = VectorXd::LinSpaced(n*n,1,n*n);
	MatrixXd A = v.reshaped<RowMajor>(n,n);
	
	cout << "Shape: " << endl;
	cout << A << endl;
	
	return A;
}

MatrixXd Random(unsigned int n) {
	MatrixXd A = MatrixXd::Random(n,n) + MatrixXd::Ones(n,n);
	// altrimenti : MatrixXd A = MatrixXd::Random(n,n).array() + 1.0;
	
	cout << "Random: " << endl;
	cout << A << endl;
	
	return A;
}

MatrixXd Hilbert(unsigned int n) {
	MatrixXd A = MatrixXd::Zero(n,n);
	for (unsigned int j = 0; j < n; j++) 
		A.col(j) = VectorXd::LinSpaced(n, j + 1, n + j);
	
	A = A.cwiseInverse();
	
	cout << "Hilbert: " << endl;
	cout << A << endl;
	return A;
}

int main()
{
	MatrixXd S = Shape(4);
	MatrixXd R = Random(4);
	MatrixXd H = Hilbert(4);
	
	double d = S.determinant();
	
	cout << d << endl;
	if (abs(d) < 1.0e-12)
		cout << "The matrix is singular" << endl;
	else
		cout << "The matrix is not singular" << endl;
	
	JacobiSVD<MatrixXd> f(S);
	VectorXd s = f.singularValues();
	cout << s.maxCoeff() / s.minCoeff() << endl;

	
    return 0;
}

