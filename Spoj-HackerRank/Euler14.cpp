#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
#define SIZE 5000010
#define uli unsigned long int
int mapping[SIZE];
int maxlength[SIZE];

bool exists(uli& value) {
    if (value < SIZE){
        if (value == 1 || value == 0)
            return 1;  
        else if (value > 1)
            return (mapping[value] != 0); 
        else
            return 0;
    }
    return 0;
}

int formula(uli n){
    if(n > 1) {
        if (n%2 == 0){
            if (exists(n)){
                return mapping[n];
            }
            mapping[n] = 1 + formula(n>>1);
        }
        else{
            if (exists(n)){
                return mapping[n];
            }
            uli new_number = (3*n) +1;
            int count = 1;
            while(new_number>SIZE){
                if (new_number%2 == 0) {
                    new_number /= 2;
                }
                else {
                    new_number = (3*new_number) + 1;
                }
                count += 1;
            }
            mapping[n] = count + formula(new_number);
        }
        return mapping[n];
    }
    else {
        return 0;
    }
}

void precompute(int start, int end, int increment){
    int z = 0;
    int index; 
    for(int i=start; i<=end ; i+=increment){
        int cur_length = formula(i);
        if (cur_length >= z){
            z = cur_length;
            index = i;
        }
        maxlength[i] = index;
    }
}

int main() {
    int test;
    cin >> test;
    mapping[0] = 0;
    mapping[1] = 0;
    precompute(2, SIZE, 1);
    while(test--){
        int n;
        cin >> n;
        // int max = 0;t
        // int index = 1;
        // for(int i=n; i>=1 ; i--){
        //     int length = mapping[i];
        //     if (length > max){
        //         max = length;
        //         index = i;
        //     }
        // }
        // // cout << n << " " << index << " " << max << endl;
        // cout << index << endl;
        cout << maxlength[n] << endl;
    };
    
    return 0;    
}
