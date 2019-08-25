// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits/0/?track=sp-arrays-and-searching&batchId=152

#include <iostream>
#define MIN(a, b) (a>b)?b:a
#define MAX(a, b) (a>b)?a:b

using namespace std;

void recursive_sentence_former(int position, int limit, char **H, int *A){
    if (position < limit){
        
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    int *A;
    char **H = new(nothrow) char*[7];
    H[0] = "abc";
    H[1] = "def";
    H[2] = "ghi";
    H[3] = "jkl";
    H[4] = "mno";
    H[5] = "pqrs";
    H[6] = "tuv";
    H[7] = "wxyz";

    cin >> t;
    while(t--){
        cin >> n;
        A = new(nothrow) int[n]{0};
        for (int i = 0; i < n; i++){
            cin >> A[i];
        }


        delete[] A;
    }

    for (int i = 0; i < 7; i++)
    {
        delete[] H[i];
    }
    delete[] H;
    return 0;
}
