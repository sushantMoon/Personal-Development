// http://www.spoj.com/problems/TETRA/
/*
We shall be using the hint given in the comments,
As i failed to find the relation of irregular tetrahedron to its insphere

```
pranjalikumar9: 2016-05-20 21:07:29 
Calculate area of faces using herons formula and then radius of insphere is a simple formula r=3*v/(a1+a2+a3+a4) 
where v is volume of tetrahedron.. Solve pyramids before this question
```

// Volume for tetrahedron is taken from here
// http://mathforum.org/dr.math/faq/formulas/faq.irreg.tetrahedron.html
// https://github.com/t3nsor/SPOJ/blob/master/pir.cpp
// http://www.geeksforgeeks.org/determinant-of-a-matrix/

Heron's Formula
http://www.mathwarehouse.com/geometry/triangles/area/herons-formula-triangle-area.php
*/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

#define N 5

void printMatrix(double matrix[N][N]){
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void getCofactor(double matrix[N][N], double tempMatrix[N][N], int row, int position, int n){
    int k=0;
    int l=0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // copying the data from matrix to tempMatrix 
            // also making sure that we do not touch the data 
            // from row and column of the number for which we 
            // are finding co factor matrix
            if ((i != row) && (j != position)){
                tempMatrix[k][l] = matrix[i][j];
                // increasing the column number 
                l++;
                // checking of column number reached
                // limit for the column number
                if (l == n-1){
                    // increasing the row number
                    l = 0;
                    k++;
                }
            }
        }
    }
}

double determinant(double matrix[N][N], int n){
    // printMatrix(matrix);
    // result variable
    double D = 0;

    // Base case 
    if (n==1)
        return matrix[0][0];

    int sign = -1;              /* MULTIPLIER SIGN */
    double tempMatrix[N][N];   /*to store the co-factor matrix*/

    // iterating over the first row for calculating the determinant
    for (int i = 0; i < n; ++i)
    {
        // cofactor for matrix[0][i]
        getCofactor(matrix,tempMatrix,0,i,n);
        D += pow(sign,(1+(i+1))) * matrix[0][i] * determinant(tempMatrix,n-1);
    }
    return D;
}


inline double volume(double d12,double d13,double d14,double d23,double d24,double d34){

	double mat[N][N];

	// http://mathforum.org/dr.math/faq/formulas/faq.irreg.tetrahedron.html
	// defining the matrix for determinant calculation
	mat[0][0] = 0; mat[0][1] = 1; 			mat[0][2] = 1; 			mat[0][3] = 1; 			mat[0][4] = 1;
	mat[1][0] = 1; mat[1][1] = 0; 			mat[1][2] = pow(d12,2); mat[1][3] = pow(d13,2); mat[1][4] = pow(d14,2);
	mat[2][0] = 1; mat[2][1] = pow(d12,2); 	mat[2][2] = 0; 			mat[2][3] = pow(d23,2); mat[2][4] = pow(d24,2);
	mat[3][0] = 1; mat[3][1] = pow(d13,2); 	mat[3][2] = pow(d23,2); mat[3][3] = 0; 			mat[3][4] = pow(d34,2);
	mat[4][0] = 1; mat[4][1] = pow(d14,2); 	mat[4][2] = pow(d24,2); mat[4][3] = pow(d34,2); mat[4][4] = 0;

	return sqrt((double)determinant(mat,N)/288.0);
}

// Heron's formula for triangle area, has been simplified a bit
inline double surface(double a, double b, double c) {
	return sqrt((a + b + c) * (-a + b + c) * (a - b + c) * (a + b - c)) / 4.0;
}


int TETRA(){
	double sumSurfaceArea,radius;
	double d12,d13,d14,d23,d24,d34;
	cin >> d12 >> d13 >> d14 >> d23 >> d24 >> d34;

	sumSurfaceArea = surface(d12,d13,d23) + surface(d34,d13,d14) + surface(d34,d24,d23) + surface(d12,d14,d24);
	radius = (3.0 * volume(d12, d13, d14, d23, d24, d34))/sumSurfaceArea;
	
	std::cout << setprecision(4) << std::fixed;
	cout << radius << endl;
}

int main() {
	int cases;
	cin >> cases;
	while(cases--)
		TETRA();
	return 0;
}