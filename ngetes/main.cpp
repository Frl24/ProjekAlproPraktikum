#include <bits/stdc++.h>
using namespace std;

void min_max(int* min, int* max, int nilai[],int n){
    for(int i=1; i<n; i++){
        if(nilai[i] > *max){
            *max = nilai[i];
        } else if (nilai[i] < *min){
            *min = nilai[i];
        }
    }
}

int main() {
    int nilai[] = {12345,4,20,30,50,11,23,6,99,5};
    int min = nilai[0];
    int max = nilai[0];
    int n=10;
    min_max(&min, &max, nilai,n);
    cout << min << "  " << max;
}