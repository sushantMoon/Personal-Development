// https://practice.geeksforgeeks.org/problems/longest-common-increasing-subsequence/0/?track=sp-arrays-and-searching&batchId=152

#include <iostream>
#include <vector>
#define MIN(a, b) (a>b)?b:a
#define MAX(a, b) (a>b)?a:b

using namespace std;


int lcs(int *A, int *B, int n1, int n2)
{
    int M[n1+1][n2+1];
    for (int i = 0; i < n1+1; i++)
    {
        for (int j = 0; j < n2+1; j++)
        {
            if (i == 0 || j == 0)
            {
                M[i][j] = 0;
            }
            else if (A[i-1] == B[j-1])
            {
                M[i][j] = 1 + M[i-1][j-1];
            }
            else
            {
                M[i][j] = MAX(M[i-1][j], M[i][j-1]);
            }
        }
    }
    cout << M[n1][n2] << endl;
    return M[n1][n2];
}


int lis(int *A, int n)
{
    int _lis[n];
    for (int i = 0; i < n; i++)
    {
        _lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j] && _lis[i] < _lis[j]+1)
            {
                _lis[i] = _lis[j]+1;
            }
        }
    }
    int max=0;
    for (int i = 0; i < n; i++)
    {
        if (max < _lis[i])
        {
            max = _lis[i];
        }
    }

    cout << max << endl;
    return max;
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2;
        cin >> n1;
        int *A = new(nothrow) int[n1];
        for (int i = 0; i < n1; i++)
        {
            cin >> A[i];
        }

        cin >> n2;
        int *B = new(nothrow) int[n2];
        for (int i = 0; i < n2; i++)
        {
            cin >> B[i];
        }

        int *M = new(nothrow) int[n2]{0};
        for (int i = 0; i < n1; i++)
        {
            int current = 0;
            for (int j = 0; j < n2; j++)
            {
                if ((A[i]==B[j]) && (current+1 > M[j]))
                {
                    M[j] = current+1;
                }
                if ((A[i] > B[j]) && (M[j] > current))
                {
                    current = M[j];
                }
            }
        }
        int result=0;
        for (int i = 0; i < n2; i++)
        {
            if (result < M[i])
            {
                result = M[i];
            }
        }
        cout << result << endl;
        // int _lcs = lcs(A, B, n1, n2);
        // int _lis_a = lis(A, n1);
        // int _lis_b = lis(B, n2);
        delete[] M;
    }

    return 0;
}
