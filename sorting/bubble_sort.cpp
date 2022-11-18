#include<iostream>
using namespace std;

int main(){
    int arr[5] = {12, 32, 4, 1, 6};
    int n = 5;
    for(int i = 0; i < n-1; i++){
        for(int j = i; j >= 0; j--){
            if(arr[j]>arr[j+1]){
                // int temp = arr[j+1];
                // arr[j+1] = arr[j];
                // arr[j] = temp;
                swap(arr[j], arr[j+1]);

            }
        }
    }
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
} 