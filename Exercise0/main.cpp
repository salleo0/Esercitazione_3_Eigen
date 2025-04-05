#include <iostream>
#include <Eigen/Eigen>	// strumento per calcolo numerico ~ MATLAB

using namespace std;
using namespace Eigen;

// passage by reference allows for multiple outputs and to savve memory storage
void foo(const int j, // by value
         int d, // by value
         int &i, // by reference
         double &s) // by reference
{
    i+= d * j;
    s = 3.0 * j;
}



int main()
{
	// Const qualifier
	//    	const int k; 	// error: k is unintialized const
	const int i = 12;
	// 		i = 4;			// error: attempt to write const object
	int val = 24;
	int copyVal = val;		// copy of val
	int &refVal = val;		// alias for val
	// 		int &refVal1;	// error: a reference must be initialized
	
	refVal = 5;
	cout << "val: " << val << endl;
	val = 7;
	cout << "refVal: " << refVal << endl;
	
	// 		int &refVal2 = 10;		// error: cannot initialize reference with literal
	double d = 3.14;
	//		int &refVal3 = da		// error: initializer must be integer
	const int& refVal3 = d;			// ad eccezione di referenze costanti. Attenzione, modificare d in questo caso non significa modificare refVal3
	
	cout << "refVal3: " << refVal3 << endl;
	d = 4.17;
	cout << "refVal3: " << refVal3 << endl;
	
	// function void result
	double s1 = 0.0;
	int ii = 2.0;
	foo(1,ii,val,s1);
	cout << "result of functionVoid: " << val << " and " << s1 << endl;
	// Pay attention: I cannot write "cout << functionVoid(val) << endl;" since functionVoid does not return any value
	
	// Function call:
    // Step 1: intialize function's parameters:
    // const int j = 1; // j cannot be edit by foo
    // int d = ii; // copy
    // int &i = val; // i is a reference for val
    // double &s = s1; // s1 and i can be thought as output since they can be edited by foo
	
	
	
	// Eigen library: documentation available at https://eigen.tuxfamily.org/dox/GettingStarted.html
	
	// Matrix
	Matrix2d Ad = Matrix2d::Identity();		// fixed dimensional matrix 2x2 of double: initialized as the identity matrix
	Matrix2i Ai = Matrix2i::Zero(); 		// fixed dimensions available: 2x2 3x3 4x4
	
	cout << "2x2 double identity matrix: " << endl << Ad << endl;
	
	MatrixXd B = MatrixXd::Ones(3,3); 	// variable dimensional matrix
	cout << "B matrix: " << endl;
	cout << B << endl;					// overload of <<
	
	B.resize(4,4);		// a dynamic matrix can be resized -> resize is not conservative!
						// try the conservativeResize() method
	cout << endl << B << endl;
	B.resize(2, 2);
	cout << endl << B << endl;
	B = MatrixXd::Ones(2,2);
	B.conservativeResize(4, 3);
	cout << endl << B << endl;
    B.conservativeResize(2, 1);
	cout << endl << B << endl;
    // Ad.resize(1, 1); // error: Ad has no dynamic size
	
	MatrixXd C = MatrixXd::Constant(2,2,1.5); 	// input: numRows, numCols
	cout << endl << "Constant matrix with inputs (2,2,1.5): " << endl;
	cout << C << endl;
	
	srand(4);			// sets seed for random matrix initilization
	MatrixXd D = MatrixXd::Random(2,2);
	
	cout << "D matrix: " << endl;
	cout << D << endl;
	
	// comma initilization
	D << 2.0, 3.0,
		1.0, 4.0;
	cout << "D matrix after comma initialization: " << endl;
	cout << D << endl;
	
	// Column vector
	Vector2d v1 = Vector2d::Ones();
	VectorXd v2 = VectorXd::LinSpaced(10,0.0,90.0);		// 10 equispaced numbers between 0 and 90
	
	cout << "v2 (column vector): " << endl;
	cout << v2 << endl;
	
	// Row vector
	RowVector2d v3 = RowVector2d::Ones();
	RowVectorXd v4(2);
	v4 << 1.0, 2.0;
	
	cout << "v4 row vector: " << endl;
	cout << v4 << endl;
	
	// Some useful operation 
	cout << "C * v1: " << endl << C * v1 << endl;
	cout << "C * v3': " << endl << C * v3.transpose() << endl;
	
	// Block operation: https://eigen.tuxfamily.org/dox/group__TutorialBlockOperations.html

    // https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html
	
    return 0;
}
