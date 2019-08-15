// https://practice.geeksforgeeks.org/problems/immediate-smaller-element/0/?track=sp-arrays-and-searching&batchId=152
#include <iostream>

using namespace std;

int main(){
    int t;
    int n;
    int *A;
    cin >> t;
    while(t--){
        cin >> n;
        A = new(nothrow) int[n];
        for (int i = 0; i < n; i++){
            cin >> A[i];
        }

        for (int i = 0; i < n-1; i++){
            if (A[i+1] < A[i]){
                cout << A[i+1] << " ";
            }
            else{
                cout << "-1 ";
            }
        }
        cout << "-1\n";
        delete[] A;
    }
    return 0;
}