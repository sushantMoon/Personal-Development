// https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0/?track=sp-arrays-and-searching&batchId=152

#include <iostream>
#define MIN(a, b) (a>b)?b:a
#define MAX(a, b) (a>b)?a:b

using namespace std;

void reverse_array(int *A, int starting, int ending){
    // for (int i = starting; i <= ending; i++){
    //     cout << A[i] << " ";
    // }
    // cout << " (input to reverse) \n";

    while (starting < ending){
        // cout << "swaps : "<< A[starting] << " " << A[ending] << endl;
        int temp = A[ending];
        A[ending] = A[starting];
        A[starting] = temp;
        starting++;
        ending--;
    }
}

int main(){
    int t, n, k;
    int count;
    int *A;
    cin >> t;
    while(t--){
        count = 0;
        cin >> n >> k;
        A = new(nothrow) int[n];
        for (int i = 0; i < n; i++){
            cin >> A[i];
        }
        if (k >= n){
            reverse_array(A, 0, n-1);
        }
        else{
            for (int i = 0; i < n; i += k){
                if (i < n-n%k){
                    reverse_array(A, i, i+k-1);
                }
                else{
                    reverse_array(A, i, n-1);
                }
            }
        }

        for (int i = 0; i < n; i++){
            cout << A[i] << " ";
        }
        cout << "\n";

        delete[] A;
    }
    return 0;
}
