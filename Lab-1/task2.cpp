#include<iostream>
using namespace std;

int main(){
    int numArr[5];
    cout<<"\nEnter 5 numbers to be stored in the array: ";
    for(int i = 0; i<5; i++){
        cin>>*(numArr + i);
    }
    int sum = 0;
    for(int i = 0; i<5; i++){
        sum += *(numArr + i);
    }
    cout<<"\nSum = "<<sum<<endl;
    return 0;
}