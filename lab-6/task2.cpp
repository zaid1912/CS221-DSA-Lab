#include<iostream>
using namespace std;

struct date{
    int day;
    int month;
    int year;
};

int main(){
    int size;
    cout<<"\nHow many dates do you want to store?: ---> ";
    cin>>size;
    date *arr = new date[size];
    for(int i = 0; i<size; i++){
        cout<<"\nenter day(between 1 and 31): ";
        cin>>arr[i].day;
        while(arr[i].day<1 || arr[i].day > 31){
            cout<<"\nIncorrect day entered. enter again between 1 and 31: ";
            cin>>arr[i].day;
        }

        cout<<"\nenter month(between 1 and 12): ";
        cin>>arr[i].month;
        while(arr[i].month<1 || arr[i].month > 12){
            cout<<"\nIncorrect month entered. enter again between 1 and 12: ";
            cin>>arr[i].month;
        }

        cout<<"\nenter year(between 2000 and 2022): ";
        cin>>arr[i].year;
        while(arr[i].year<2000 || arr[i].year > 2022){
            cout<<"\nIncorrect day entered. enter again between 2000 and 2022: ";
            cin>>arr[i].year;
        }

        cout<<"\ndate stored\n";
    }

    int i, j, min_index;
    for(int i = 0; i<size-1; i++){
        min_index = i;
        for(int j = i+1; j<size; j++){
            if(arr[i].year > arr[j].year){
                swap(arr[i], arr[j]);
            }
            else if(arr[i].year == arr[j].year && arr[i].month > arr[j].month){
                swap(arr[i], arr[j]);
            }
            else if(arr[i].year == arr[j].year && arr[i].month == arr[j].month && arr[i].day > arr[j].day){
                swap(arr[i], arr[j]);
            }
        }
    }
    cout<<"\nDates in ascending order: \n";
    for(int i = 0; i<size; i++){
        cout<<arr[i].day<<"/"<<arr[i].month<<"/"<<arr[i].year<<endl;
    }
    return 0;
}