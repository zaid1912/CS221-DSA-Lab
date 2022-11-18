#include<iostream>
using namespace std;
//array used for testing: [99, 30, 45, 40, 20, 35, 27, 31, 30]
//expected output: [20, 40, 27, 35, 30, 31, 45, 30, 90] supposing that index 0 is even

int * ascending_insertion(int *even, int size){
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = even[i];
        j = i - 1;

        while (j >= 0 && even[j] > key)
        {
            even[j + 1] = even[j];
            j = j - 1;
        }
        even[j + 1] = key;
    }
    
    return even;
}
int * descending_insertion(int *odd, int size){
    
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = odd[i];
        j = i - 1;
 
        while (j >= 0 && odd[j] < key)
        {
            odd[j + 1] = odd[j];
            j = j - 1;
        }
        odd[j + 1] = key;
    }
   
    return odd;
}
int main(){
    int size;
    
    cout<<"enter the number of elements that you want to store in the array: ";
    cin>>size;
    int odd_q_size, even_q_size;
    if(size%2 == 0){
        odd_q_size = size/2;
        even_q_size = even_q_size/2;
    }
    else{
        even_q_size = (size/2) + 1;
        odd_q_size = (size/2);
    }
    cout<<"\neven = "<<even_q_size<<"    odd = "<<odd_q_size<<endl;
    int *arr = new int[size];
    int *even = new int[even_q_size];
    int *odd = new int[odd_q_size];
    
    for(int i = 0; i<size; i++){
        cout<<"\nenter the value: ";
        cin>>arr[i];
    }
    for(int i = 0; i<size; i++){
        if(i%2 == 0){
            even[i/2] = arr[i];
        }
        else{
            odd[i/2] = arr[i];
        }
    }
    int *even_arr = ascending_insertion(even, even_q_size);
    int *odd_arr = descending_insertion(odd, odd_q_size);

    cout<<"even indexed elements of the array in ascending order:\n";
    for(int i = 0; i<even_q_size; i++){
        cout<<even_arr[i]<<" ";
    }
    cout<<endl;

    cout<<"odd indexed elements of the array in desceding order:\n";
    for(int i = 0; i<odd_q_size; i++){
        cout<<odd_arr[i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i<size; i++){
        if(i%2 == 0){
            arr[i] = even_arr[i/2];
        }
        else{
            arr[i] = odd_arr[i/2];
        }
    }

    cout<<"FINAL ARRAY: \n";
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}