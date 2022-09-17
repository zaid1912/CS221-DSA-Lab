#include<iostream>
using namespace std;
//dynamic array

void callByPointer(int *x, int *y){
    // cout<<endl<<x<<endl<<y;
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;


}

int main(){
    int a, b;
    cout<<"enter first number: ";
    cin>>a;
    cout<<"\nenter second number: ";
    cin>>b;
    callByPointer(&a, &b);
    cout<<endl<<"After Swapping: "<<endl<<"a = "<<a<<endl<<"b = "<<b<<endl;


}

// 2 4    temp = 2
// 