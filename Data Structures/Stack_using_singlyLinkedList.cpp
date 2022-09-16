#include<iostream>
using namespace std;

template<class T>
class stack{
    private:
    int len; //length of stack. Value of this is updated when new element is added or when an element is deleted
    struct node{  //struct of node(same as in linked list)
        T data;
        node *next;
    };

    node *headptr = NULL;

    public:
    stack(){
        len = 0;  //initially the length of stack is 0
        headptr = NULL;  //head pointer is set to null initially
    }

    void push(T elem){  //pushing in a new element in stack (exact same implementation as done in linked list Adding element at head)
        ++len;  //pre-increment of length of stack when a new element is pushed into stack
        node *temp = new node;
        temp->data = elem;
        temp->next = headptr;
        headptr = temp;
    }

    void pop(){  //popping an element fromt he stack on the LIFO principle
        --len; //decrement in the length by one when an element is removed from the stack
        headptr->data = NULL;
        headptr = headptr->next;
    }

    int size(){  //returns the size/length of stack
        return len;
    }
    bool is_empty(){  //returns whether the stack is empty or not
        return(len() == 0);
    }

    void display(){  //displays the whole stack values
        node *temp = headptr;
        do{
            cout<<temp->data<<endl;
            temp = temp->next;
        }while(temp != NULL);
    }

    T top(){  //returns the value at the top of stack
        return(headptr->data);
    }

    ~stack(){  //destructor
        node *prev_pointer;
        while(headptr != NULL){
            prev_pointer = headptr;
            headptr = headptr->next;
            delete prev_pointer;
        }
    }

};

int main(){
    stack<int> stack1;
    stack1.push(0);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.display();
    cout<<endl<<stack1.top();
    cout<<endl<<stack1.size();
}