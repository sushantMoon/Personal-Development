// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0/?track=sp-arrays-and-searching&batchId=152
// this solution was not accepted
#include <iostream>
#define MIN(a, b) (a>b)?b:a
#define MAX(a, b) (a>b)?a:b

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int *A = new(nothrow) int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int max=0, i=0;
        for (i = 0; i < n-k+1; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (A[i+j] > max)
                {
                    max = A[i+j];
                }
            }
            cout << max << " ";
            max = 0;
        }
        cout << endl;
        delete[] A;
    }
    return 0;
}