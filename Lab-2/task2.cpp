#include<iostream>
using namespace std;

struct address{
    int houseno;
    string city;
};

struct student{
    int rollno;
    string name;
    int age;
    address add;

};

void age14(student students[], int size){
    for(int i = 0; i<size;i++){
        if(students[i].age == 14){
            cout<<students[i].name<<endl;
        }
    }
}

void evenroll(student students[], int size){
    for(int i = 0; i<size;i++){
        if(students[i].rollno % 2 == 0){
            cout<<students[i].name<<endl;
        }
    }
}

void set(student  students[], int size){
    for(int i = 0; i<size; i++){
        // cin.ignore();
        cout<<"\nEnter the sudent "<<i+1<<" name: ";
        // getline(cin, students[i].name);
        cin>>students[i].name;
        
        cout<<"\nEnter the roll no of student "<<i+1<<": ";
        cin>>students[i].rollno;

        cout<<"\nEnter the age no of student "<<i+1<<": ";
        int input_age = 0;
        cin>>input_age;
        while(input_age < 11 || input_age>14){
            cout<<"\nAge must be between 11 and 14. Re-enter: ";
            cin>>input_age;
        }
        students[i].age = input_age;

        cout<<"\nEnter the address(house number) of student "<<i+1<<": ";
        cin>>students[i].add.houseno;
        cout<<"\nEnter the address(city) of student "<<i+1<<": ";
        cin>>students[i].add.city;
    }
}

void search(student students[], int size){
    int roll;
    cout<<"\nenter the roll number to be searched: ";
    cin>>roll;
    int i = 0;
    bool found = false;
    for(i = 0; i<size; i++){
        if(roll == students[i].rollno){
            found = true;
            break;
        }
    }
    if(found == false){
        cout<<"\nno student with this roll number exists\n";
    }
    else{
        cout<<"\ndetails of this student: ";
        cout<<endl<<students[i].name<<endl<<students[i].age<<endl<<students[i].rollno<<endl<<students[i].add.city<<endl<<students[i].add.houseno<<endl;
    }
}



int main(){
    // int size = 4;
    // student s[4];
    student *s;
    int size;
    cout<<"\nenter the number of students to be entered: ";
    cin>>size;
    s = new student[size];
    set(s, size);
    age14(s, size);
    evenroll(s, size);
    search(s, size);
    return 0;


}