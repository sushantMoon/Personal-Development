// https://practice.geeksforgeeks.org/problems/print-an-array-in-pendulum-arrangement/0/?track=sp-arrays-and-searching&batchId=152

#include <iostream>
#define MIN(a, b) (a>b)?b:a
#define MAX(a, b) (a>b)?a:b

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
    int t, n;
    int *A, *B;
    cin >> t;
    while(t--){
        cin >> n;
        A = new(nothrow) int[n];
        B = new(nothrow) int[n];
        for (int i = 0; i < n; i++){
            cin >> A[i];
        }
        qsort(A, n, sizeof(int), compare);
        // for (size_t i = 0; i < n; i++){
        //     cout << A[i] << " ";
        // }
        // cout << "\n";

        int starting = 0;
        int ending = n-1;
        for (int i = n-1; i > -1; i--){
            if (i%2 == 0){
                B[starting] = A[i];
                starting++;
            }
            else{
                B[ending] = A[i];
                ending--;
            }
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
