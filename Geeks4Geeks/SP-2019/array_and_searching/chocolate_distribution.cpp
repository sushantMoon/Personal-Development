// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0/?ref=self

#include <iostream>
#define MIN(a, b) (a>b)?b:a
#define MAX(a, b) (a>b)?a:b

using namespace std;

int asc_compare(const void * a, const void * b){
    return (*(long long int *)a - *(long long int *)b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k;
    long long int *A;
    cin >> t;
    while(t--){
        cin >> n;
        A = new(nothrow) long long int[n]{0};
        for (int i = 0; i < n; i++){
            cin >> A[i];
        }
        qsort(A, n, sizeof(long long int), asc_compare);
        cin >> k;
        long long int min=A[k-1] - A[0];

        for (int i = 0; i < n; i++){
            if (i+k-1 < n){
                min = MIN(min, A[i+k-1] - A[i]);
                // cout << min << "(Updates)" << endl;
            }
        }

        cout << min << "\n";

        delete[] A;
    }
    return 0;
}
