#include <iostream>
#include <Eigen/Eigen>

using namespace std;
using namespace Eigen;

// Shape(n) is the n-by-n matrix with elements from 1 to n * n.
MatrixXd Shape(const unsigned int& n) 
{
	VectorXd v = VectorXd::LinSpaced(n*n,1,n*n);
	MatrixXd A = v.reshaped<RowMajor>(n,n);
	
	cout << "Shape: " << endl;
	cout << A << endl;
	
	return A;
}

// Random(n) is the n-by-n matrix with random elements.
MatrixXd Random(const unsigned int& n) 
{
	srand(5);
	
	// Random: Numbers are uniformly spread and in the [-1,1] range for floating point scalar
	MatrixXd A = MatrixXd::Random(n,n) + MatrixXd::Ones(n,n);
	// altrimenti : MatrixXd A = MatrixXd::Random(n,n).array() + 1.0;
	
	cout << "Random: " << endl;
	cout << A << endl;
	
	return A;
}

// Hilbert(n) is the n-by-n matrix with elements 1/(i+j-1).
MatrixXd Hilbert(const unsigned int& n) 
{
	MatrixXd A = MatrixXd::Zero(n,n);
	for (unsigned int j = 0; j < n; j++) 
		A.col(j) = VectorXd::LinSpaced(n, j + 1, n + j);
	
	A = A.cwiseInverse();
	
	cout << "Hilbert: " << endl;
	cout << A << endl;
	return A;
}

/* MatrixIsSingular(A) compute the determinant and the condition number of A,
*  determining if A is invertible or not
*  detA the determinant of A
*  condA the condition number of A
*  return true if the matrix A is invertible, else it returns false */
bool MatrixIsSingular(const MatrixXd& A,
                      double& detA,
                      double& condA)
{
    JacobiSVD<MatrixXd> svd(A);
    VectorXd singularValuesA = svd.singularValues();
    condA = singularValuesA.maxCoeff() / singularValuesA.minCoeff();

    detA = A.determinant();

    if( singularValuesA.minCoeff() < 1e-16)
        return false;
    else
        return true;
}

int main()
{
	
	const unsigned int n = 4;
	
	MatrixXd S = Shape(n);
	MatrixXd R = Random(n);
	MatrixXd H = Hilbert(n);

	double detAS, condAS;
	cout << "---shape matrix---" << endl;
	cout << S << endl;
    if(MatrixIsSingular(S, detAS, condAS))
        cout<< scientific<< "DetA: "<< detAS << ", RCondA: " << 1.0 / condAS << endl;
    else
        cout << scientific<< "DetA: "<< detAS << ", RCondA: " << 1.0 / condAS << " (Matrix is singular)"<< endl;

    double detAR, condAR;
	cout << endl << "---random matrix---" << endl;
	cout << R << endl;
    if(MatrixIsSingular(R, detAR, condAR))
        cout<< scientific<< "DetA: "<< detAR << ", RCondA: " << 1.0 / condAR << endl;
    else
        cout<< scientific<< "DetA: "<< detAR << ", RCondA: " << 1.0 / condAR << " (Matrix is singular)"<< endl;

    double detAH, condAH;
	cout << endl << "---hilbert matrix---" << endl;
	cout << H << endl;
    if(MatrixIsSingular(H, detAH, condAH))
        cout<< scientific<< "DetA: "<< detAH<< ", RCondA: "<< 1.0 / condAH << endl;
    else
        cout<< scientific<< "DetA: "<< detAH<< ", RCondA: "<< 1.0 / condAH << " (Matrix is singular)"<< endl;
	
    return 0;
}

