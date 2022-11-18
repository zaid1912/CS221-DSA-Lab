#include<iostream>
using namespace std;

//insertion sort

int main(){
    int arr[5] = {12, 32, 4, 1, 6};
    int n = 5;
    int i, j, key;
    for(int i = 1; i<n; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
} 