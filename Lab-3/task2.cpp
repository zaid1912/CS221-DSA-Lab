#include<iostream>
using namespace std;

class circularList{
    private:
    struct node{
        node *next;
        int data;
    };
    node *headptr;

    public:

    circularList(){
        headptr = NULL;
    }

    void insertAtHead(int key){
        node *newnode = new node;
        newnode->data = key;
        newnode->next = headptr;
        headptr = newnode;
        // delete newnode;
    }

    void insertAtTail(int key){ //time complexity?????
        node *temp = new node;
        node *traverse = headptr;
        temp->data = key;
        temp->next = NULL;
        if(headptr == NULL){
            headptr = temp;
            return;
        }
        while(traverse->next != NULL){
            traverse = traverse->next;
        }
        traverse->next = temp;
        // delete temp;
        // delete traverse;
    }

    void makeCircular(){
        node *traverse = headptr;
        while(traverse->next != NULL){
            traverse = traverse->next;
        }
        traverse->next = headptr;
        cout<<"\ncircular\n";
    }

    bool detectCycle(){
        node *traverse = headptr;
        bool circular = false;
        while(1){
            traverse = traverse->next;
            if(traverse->next == headptr){
                return true;
            }
            if(traverse->next == NULL){
                return false;
            }
        }
    }

    void removeCycle(){
        node *traverse = headptr;
        while(traverse->next != headptr){
            traverse = traverse->next;
        }
        traverse->next = NULL;
        cout<<"\nCycle removed\n";
    }

};

int main(){
    circularList l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);

    l.makeCircular();
    if(l.detectCycle()){
        cout<<"\nCycle found in the linked list\n";
    }
    else{
        cout<<"\nCycle not found in the linked list\n";
    }
    l.removeCycle();

    return 0;

}