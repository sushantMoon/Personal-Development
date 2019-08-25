// https://practice.geeksforgeeks.org/problems/sort-in-specific-order/0/?track=sp-arrays-and-searching&batchId=152

#include <iostream>
#define MIN(a, b) (a>b)?b:a
#define MAX(a, b) (a>b)?a:b

using namespace std;

int asc_compare(const void * a, const void * b){
    return (*(int *)a - *(int *)b);
}

int des_compare(const void * a, const void * b){
    return (*(int *)b - *(int *)a);
}

int main(){
    int t, n, even, odd;
    int *A1, *A2;
    cin >> t;
    while(t--){
        cin >> n;
        even = 0;
        odd = 0;
        A1 = new(nothrow) int[n];
        A2 = new(nothrow) int[n];
        for (int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            if (temp%2 == 0){
                A2[even++] = temp;
            }
            else{
                A1[odd++] = temp;
            }
        }
        qsort(A1, odd, sizeof(int), des_compare);
        qsort(A2, even, sizeof(int), asc_compare);
        for (int i = 0; i < odd; i++){
            cout << A1[i] << " ";
        }
        for (int i = 0; i < even; i++){
            cout << A2[i] << " ";
        }
        cout << "\n";

        delete[] A1;
        delete[] A2;
    }
    return 0;
}
