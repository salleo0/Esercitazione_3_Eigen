#include <iostream>
#include <Eigen/Eigen>	// strumento per calcolo numerico ~ MATLAB

using namespace std;
using namespace Eigen;


int main()
{
	// creazione matrice 2x2 di tipo int
	Matrix2i A; 	// se scrivessi Matrix5i mi da errore: guardare come funziona
					// A è una matrice fissa, non posso modificare la dimensione
					
	// creazione matrice dinamica
	MatrixXd B; 	// la dimensione è un'incognita
	
	// come inizializzare matrici
	Matrix2i C = Matrix2i::Ones();	// matrice di tutti 1
	// c'è overload degli operatori
	cout << "C: " << endl;
	cout << C << endl;
	
	MatrixXd D = MatrixXd::Identity(3,4)	// matrice 3x4
	//D.resize(5,5)							// annulla tutto il contenuto della matrice
	B.conservativeResize(5,5);
	
	Vector2i w = Vector2i::Ones();
	VectorXd w1 = VectorXd::Zeros(3);
	
	cout << "w1 come vettore colonna: " << endl;	// definito come tale
	cout << w1 << endl;
	cout << "w1 come vettore riga: " << endl;
	cout << w1.transpose() << endl;
	
	RowVectorXd w2 = RowVectorXd::Zeros(3);
	
	MatrixXi A = MatrixXi::Identity(2);
	cout << A * w << endl;
	
    return 0;
}
