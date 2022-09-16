#include<iostream>
using namespace std;


template<class T>  //template
class list{
    private:
    struct node{  //nude struct
        T data;
        node *next;
    };

    node *headptr;  //creating a pointer to head node

    public:

    list(){ //constructor
        headptr = NULL;  //since there are no values stored in the list when object is created, headptr is set to NULL
    }

    void AddNodeAtHead(T val){  //adds node at the head of list (used in stack and queue)
        node *temp = new node;
        temp->data = val;
        temp->next = headptr;
        headptr = temp;
        // delete temp;
    }

    void AddNodeAtTail(T val){  //adds node at the tail of the list 
        node *temp = headptr;
        node *new_node = new node;
        new_node->next = NULL;
        new_node->data = val;
        if(headptr == NULL){
            headptr = new_node;
            return;
        }
        temp = headptr;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display(){  //displays all the elements in list
        node *temp = headptr;
        do{
            cout<<temp->data<<endl;
            temp = temp->next;
        }while(temp != NULL);
    }
    void delete_node(T val){  //deletes a specific node having a value= = val from the list
        node *temp1 = headptr;
        node *temp2 = headptr->next;
        while(temp2->next != NULL && temp2->data != val){
            temp1 = temp2;
            temp2 = temp2->next;
        }
        if(temp2->data == val){
            cout<<"\nValue Deleted Successfully\n";
            temp1->next = temp2->next;
        }
        // if(temp2->next == NULL){
        //     cout<<"\nNOT FOUND\n";
        // }
        else{
            cout<<"\nValue to be deleted is not found in the linked list\n";
        }
        
    }

    void display_specific_node(T val){  //displays the value of some specific node
        node *temp = headptr;
        while(temp != NULL && temp->data != val){
            temp = temp->next;
        }
        if(temp == NULL){
            cout<<"\nElement not found in the list\n";
        }
        else{
            cout<<"\nData(value) for node is: "<<temp->data<<endl;
        }
    }
    ~list(){  //destuctor. clears whole list
        node *prev_pointer;
        while(headptr != NULL){
            prev_pointer = headptr;
            headptr = headptr->next;
            delete prev_pointer;
        }
    }
};

int main(){
    list<int> list1;  //list of type integer is created
    list1.AddNodeAtTail(0);
    list1.AddNodeAtTail(1);
    list1.AddNodeAtTail(2);
    list1.AddNodeAtTail(3);
    list1.AddNodeAtTail(4);
    list1.display();
    list1.AddNodeAtHead(-1);
    list1.display();
    list1.delete_node(3);
    list1.display();
    list1.AddNodeAtTail(9);
    list1.display();
}