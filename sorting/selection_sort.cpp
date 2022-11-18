#include<iostream>
using namespace std;

//selection sort

int main(){
    int arr[5] = {12, 32, 4, 1, 6};
    int n = 5;
    int i, j, min_index;
 
    // One by one move boundary of
    // unsorted subarray
    
    for(int i = 0; i< n-1; i++){
        min_index = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
} 