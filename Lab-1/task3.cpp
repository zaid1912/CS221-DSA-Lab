#include<iostream>
using namespace std;

int main(){
    int len;
    cout<<"\nHow many numbers do you want to store in the array?---> ";
    cin>>len;
    int *arr = new int[len];
    cout<<endl;
    cout<<"\nEnter the values to be stored in the array: ";
    for(int i = 0; i<len; i++){
        cin>>arr[i];
    }
    cout<<"\nArray elements in reverse order: \n";
    for(int i = len-1; i>=0; i--){
        cout<<arr[i]<<endl;
    }
    return 0;
}