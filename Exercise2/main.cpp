#include <iostream>
#include <Eigen/Eigen>
#include <iomanip>
using namespace std;
using namespace Eigen;

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
	
	VectorXd sol1_LU = A1.partialPivLu().solve(b1);
	VectorXd sol1_QR = A1.colPivHouseholderQr().solve(b1);
	cout << "---First system---" << endl;
	cout << "Solution through PA=LU fafctorization: " << endl;
	cout << scientific << setprecision(16) << sol1_LU << endl;
	cout << scientific << setprecision(16) << "Relative error: " << (exact_sol - sol1_LU).norm() / exact_sol.norm() << endl;
	cout << "Solution through QR fafctorization: " << endl;
	cout << scientific << setprecision(16) << sol1_QR << endl;
	cout << scientific << setprecision(16) << "Relative error: " << (exact_sol - sol1_QR).norm() / exact_sol.norm() << endl;
	
	VectorXd sol2_LU = A2.partialPivLu().solve(b2);
	VectorXd sol2_QR = A2.colPivHouseholderQr().solve(b2);
	cout << endl << "---Second system---" << endl;
	cout << "Solution through PA=LU fafctorization: " << endl;
	cout << scientific << setprecision(16) << sol2_LU << endl;
	cout << scientific << setprecision(16) << "Relative error: " << (exact_sol - sol2_LU).norm() / exact_sol.norm() << endl;
	cout << "Solution through QR fafctorization: " << endl;
	cout << scientific << setprecision(16) << sol2_QR << endl;
	cout << scientific << setprecision(16) << "Relative error: " << (exact_sol - sol2_QR).norm() / exact_sol.norm() << endl;
	
	VectorXd sol3_LU = A3.partialPivLu().solve(b3);
	VectorXd sol3_QR = A3.colPivHouseholderQr().solve(b3);
	cout << endl << "---Third system---" << endl;
	cout << "Solution through PA=LU fafctorization: " << endl;
	cout << scientific << setprecision(16) << sol3_LU << endl;
	cout << scientific << setprecision(16) << "Relative error: " << (exact_sol - sol3_LU).norm() / exact_sol.norm() << endl;
	cout << "Solution through QR fafctorization: " << endl;
	cout << scientific << setprecision(16) << sol3_QR << endl;
	cout << scientific << setprecision(16) << "Relative error: " << (exact_sol - sol3_QR).norm() / exact_sol.norm() << endl;
	
    return 0;
}
