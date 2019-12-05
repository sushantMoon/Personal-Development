#include <iostream>
#include <vector>

#define MIN(a, b) (a>b)?b:a
#define MAX(a, b) (a>b)?a:b

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >> t;
    while(t--){
        int n, maxW;
        cin >> n;
        cin >> maxW;
        int V[n], W[n];
        for (int i = 0; i < n; i++){
            cin >> V[i];
        }
        for (int i = 0; i < n; i++){
            cin >> W[i];
        }


        int M[n+1][maxW+1];

        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= maxW; j++){
               M[i][j] = 0;
            }
        }

        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= maxW; j++){
                if (i == 0 || j == 0){
                    M[i][j] = 0;
                }
                else if (W[i-1] <= j){
                    M[i][j] = MAX(
                        V[i-1] + M[i-1][j-W[i-1]],
                        M[i-1][j]
                    );
                }
                else{
                    M[i][j] = M[i-1][j];
                }

            }
        }
        cout << M[n][maxW] << endl;
    }

    return 0;
}
