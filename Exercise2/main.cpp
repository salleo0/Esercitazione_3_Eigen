#include <iostream>
#include <Eigen/Eigen>
#include <iomanip>
using namespace std;
using namespace Eigen;

bool MatrixIsSingular(const MatrixXd& A)
{
    JacobiSVD<MatrixXd> svd(A);
    VectorXd singularValuesA = svd.singularValues();

    if( singularValuesA.minCoeff() < 1e-16)
        return false;
    else
        return true;
}

VectorXd solveLinearSystem(const MatrixXd& A, const VectorXd& b) 
{
	if (!MatrixIsSingular(A)) 
		return A.partialPivLu().solve(b);
	else
		return A.colPivHouseholderQr().solve(b);
}

int main()
{
	const unsigned int n = 2;
	MatrixXd A1(n,n);
	A1 << 5.547001962252291e-01, -3.770900990025203e-02,
		8.320502943378437e-01, -9.992887623566787e-01;
	
	MatrixXd A2(n,n);
	A2 << 5.547001962252291e-01, -5.540607316466765e-01,
		8.320502943378437e-01, -8.324762492991313e-01;
	
	MatrixXd A3(n,n);
	A3 << 5.547001962252291e-01, -5.547001955851905e-01,
		8.320502943378437e-01, -8.320502947645361e-01;
	
	VectorXd b1(n);
	b1 << -5.169911863249772e-01, 1.672384680188350e-01;
	
	VectorXd b2(n);
	b2 << -6.394645785530173e-04, 4.259549612877223e-04;
	
	VectorXd b3(n);
	b3 << -6.400391328043042e-10, 4.266924591433963e-10;
	
	VectorXd exact_sol(n);
	exact_sol << -1.0e+0, -1.0e+00;
	
	VectorXd sol1 = solveLinearSystem(A1, b1);
	cout << "---First system---" << endl;
	cout << "Solution: " << endl;
	cout << scientific << setprecision(16) << sol1 << endl;
	cout << scientific << setprecision(16) << "Relative error: " << (exact_sol - sol1).norm() / exact_sol.norm() << endl;
	
	VectorXd sol2 = solveLinearSystem(A2, b2);
	cout << "---Second system---" << endl;
	cout << "Solution: " << endl;
	cout << scientific << setprecision(16) << sol2 << endl;
	cout << scientific << setprecision(16) << "Relative error: " << (exact_sol - sol2).norm() / exact_sol.norm() << endl;
	
	VectorXd sol3 = solveLinearSystem(A3, b3);
	cout << "---Third system---" << endl;
	cout << "Solution: " << endl;
	cout << scientific << setprecision(16) << sol3 << endl;
	cout << scientific << setprecision(16) << "Relative error: " << (exact_sol - sol3).norm() / exact_sol.norm() << endl;
	
    return 0;
}
