#include<iostream>
using namespace std;

class list{
    private:
    struct node{
        node *next;
        int val;

    };
    node *headptr;

    public:
    list(){
        headptr = NULL;
    }
    void insertAtHead(int key){
        node *newnode = new node;
        newnode->val = key;
        newnode->next = headptr;
        headptr = newnode;
        // delete newnode;
    }
    void reverseElems(){
        list l2;
        node *temp1 = headptr;
        int current = 1;
        node *temp2 = headptr->next;
        while(temp2->next != NULL){
            int tempVal= temp1->val;
            temp1->val = temp2->val;
            temp2->val = tempVal;

            temp2 = temp2->next;
            temp2 = temp2->next;

            temp1 = temp1->next;
            temp1 = temp1->next;
        }

        int tempVal= temp1->val;
        temp1->val = temp2->val;
        temp2->val = tempVal;
    }

    void display(){  //displays all the elements in list
        node *temp = headptr;
        do{
            cout<<temp->val<<" -> ";
            temp = temp->next;
        }while(temp != NULL);
    }
};

int main(){
    list l;
    l.insertAtHead(6);
    l.insertAtHead(5);
    l.insertAtHead(4);
    l.insertAtHead(3);
    l.insertAtHead(2);
    l.insertAtHead(1);
    cout<<"\nbefore: ";
    l.display();
    cout<<"\n";
    l.reverseElems();
    cout<<"\nAfter: ";
    l.display();
    cout<<"\n";
}