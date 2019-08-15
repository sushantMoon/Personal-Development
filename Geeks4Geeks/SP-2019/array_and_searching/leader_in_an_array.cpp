// https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0/?ref=self

#include <iostream>

using namespace std;

int main(){
    int t, n;
    int count;
    int *A, *B;
    cin >> t;
    while(t--){
        count = 0;
        cin >> n;
        A = new(nothrow) int[n];
        B = new(nothrow) int[n];
        for (int i = 0; i < n; i++){
            cin >> A[i];
        }
        B[count] = A[n-1];
        for (int i = n-2; i > -1; i--){
            if (A[i] >= B[count]){
                count++;
                B[count] = A[i];
            }
        }
        for (int i = count; i > -1; i--){
            cout << B[i] << " ";
        }
        cout << "\n";

        delete[] A;
        delete[] B;
    }
    return 0;
}
