// https://practice.geeksforgeeks.org/problems/reversal-algorithm/0/?track=sp-arrays-and-searching&batchId=152

#include <iostream>

using namespace std;

int main(){
    int t, n;
    int *A, *B;
    int d, j;
    cin >> t;
    while(t--){
        cin >> n >> d;
        A = new(nothrow) int[n];
        B = new(nothrow) int[n];
        for (int i = 0; i < n; i++){
            cin >> A[i];
        }
        j = d%n;
        for (int i = 0; i < n; i++){
            B[i] = A[j];
            j++;
            j %= n;
        }

        for (int i = 0; i < n; i++){
            cout << B[i] << " ";
        }
        cout << "\n";

        delete[] A;
        delete[] B;
    }
    return 0;
}
