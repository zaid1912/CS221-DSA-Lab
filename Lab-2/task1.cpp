#include<iostream>
using namespace std;

struct person{
    string name;
    int age;
    float salary;
};
void display(person p){
    cout<<"\nname = "<<p.name;
    cout<<"\nage = "<<p.age;
    cout<<"\nsalary = "<<p.salary<<endl;

}

int main(){
    person p1;
    person *p = &p1;

    cout<<"\nenter the name of the person: ";
    cin>>p->name;

    cout<<"\nenter the age of the person: ";
    cin>>p->age;

    cout<<"\nenter the salary of the person: ";
    cin>>p->salary;
    display(*p);
    return 0;

}