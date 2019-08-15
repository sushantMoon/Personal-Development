// https://practice.geeksforgeeks.org/problems/kth-smallest-element/0/?ref=self

#include <iostream>
#define MIN(a, b) (a>b)?b:a
#define MAX(a, b) (a>b)?a:b

using namespace std;

int main(){
    int t, n, k;
    int *A, *H;
    cin >> t;
    while(t--){
        cin >> n;
        int min=999999, max=-1;
        A = new(nothrow) int[n];
        for (int i = 0; i < n; i++){
            cin >> A[i];
            min = MIN(A[i], min);
            max = MAX(A[i], max);
        }
        for (int i = 0; i < n; i++){
            A[i] -= min;
        }
        H = new(nothrow) int[max-min+1]{0};
        for (int i = 0; i < n; i++){
            H[A[i]] += 1;
        }

        cin >> k;

        for (int i = 0; i < max-min+1; i++){
            if (H[i] > 0){
                k--;
                if (k == 0){
                    cout << i+min << endl;
                }
            }
        }

        delete[] A;
        delete[] H;
    }
    return 0;
}
