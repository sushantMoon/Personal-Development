// https://practice.geeksforgeeks.org/problems/find-the-fine/0/?track=sp-arrays-and-searching&batchId=152

#include <iostream>
#define MIN(a, b) (a>b)?b:a
#define MAX(a, b) (a>b)?a:b

using namespace std;

int asc_compare(const void * a, const void * b){
    return (*(int *)a - *(int *)b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, d;
    int *A, *P;
    cin >> t;
    while(t--){
        cin >> n >> d;
        A = new(nothrow) int[n]{0};
        P = new(nothrow) int[n]{0};
        for (int i = 0; i < n; i++){
            cin >> A[i];
        }
        for (int i = 0; i < n; i++){
            cin >> P[i];
        }
        int penalty=0;
        for (int i = 0; i < n; i++)
        {
            if( ((d%2 == 0) && (A[i]%2==1)) || ((d%2 == 1) && (A[i]%2 == 0)) ){
                penalty += P[i];
            }
        }
        cout << penalty << endl;

        delete[] A;
        delete[] P;
    }
    return 0;
}
