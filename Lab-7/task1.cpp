#include<iostream>
#include "quicksort.h"
using namespace std;

class list{
    public:
    struct node{
        int data;
        node *next;
    };
    node *head;
    list(){
        head = NULL;
    }
    void insert(int key){
        node *newnode = new node;
        newnode->data = key;
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
        }
        else{
            node *traverse = head;
            while(traverse->next!=NULL){
                traverse = traverse->next;
            }
            traverse->next = newnode;
        }
    }


    void print_list(){
        cout<<endl<<"items stored in list: ";
        node *traverse = head;
        while(traverse!=NULL){
            cout<<traverse->data<<" ";
            traverse = traverse->next;
        }
        cout<<endl;
    }
    int remove_head(){

    }
    
};

int main(){
    list l;
    int size;
    cout<<"how many numbers do you want to enter in linked list? ";
    cin>>size;
    int *arr = new int[size];
    cout<<"\nenter data to be inserted: ";
    for(int i = 0; i<size; i++){
        int data;
        cin>>data;
        arr[i] = data;
        l.insert(data);
    }

    l.print_list();

    quickSort(arr, 0, size-1);
    l.head->next = NULL;
    l.head = NULL;
    for(int i = 0; i<size; i++){
        l.insert(arr[i]);
    }
    cout<<"\nAfter sorting: ";
    l.print_list();
}
