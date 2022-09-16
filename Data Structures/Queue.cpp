#include<iostream>
using namespace std;

template<class T>

class queue{
    private:

    int len;
    struct node{
        T data;
        node *next;
    };
    node *headptr;

    public:

    queue(){
        len = 0;  //initially the length of queue is 0
        headptr = NULL;  //head pointer is set to null initially
    }

    void enqueue(T val){  //adding in a new element in queue (exact same eimplementation as done in linked list Adding element at head)
        ++len;  //pre-increment of length of queue when a new element is added to queue
        node *newptr = new node;
        newptr->next = headptr;
        newptr->data = val;
        headptr = newptr;
    }
    void display(){  //displays all the elements in queue
        node *temp = headptr;
        do{
            cout<<temp->data<<endl;
            temp = temp->next;
        }while(temp != NULL);
    }
    void dequeue(){   //removing an element from queue on the FIFO principle
        --len; //decrement in the length by one when an element is removed from the queue
        node *temp1 = headptr;
        node *temp2 = headptr->next;
        while(temp2->next != NULL){
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp1->next = NULL;
    }

    int size(){  //returns the size/length of queue
        return len;
    }
    bool is_empty(){  //returns whether the queue is empty or not
        return(len() == 0);
    }

    ~queue(){  //destructor
        node *prev_pointer;
        while(headptr != NULL){
            prev_pointer = headptr;
            headptr = headptr->next;
            delete prev_pointer;
        }
    }

};

int main(){
    queue<int> q;
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(1);
    q.enqueue(4);
    q.enqueue(2);
    q.enqueue(9);
    q.enqueue(0);
    q.enqueue(11);
    q.display();
    cout<<endl;
    q.dequeue();
    q.dequeue();
    q.display();
    cout<<endl<<q.size();
}