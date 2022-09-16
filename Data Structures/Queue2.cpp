#include<iostream>
using namespace std;

template<class T>

class queue{
    private:
    struct EachNode{
        T data;
        EachNode *next;
        // EachNode *prev;
    };

    EachNode *rear, *front;
    int len;

    public:

    queue(){ //constructor to initially set front and rear = null and length of queue is initially 0
        rear =  front = NULL;
        len = 0;
    }

    void enqueue(T val){
        EachNode * temp = new EachNode;
        temp->data = val;
        if(rear == NULL){  //when the queue is empty
            temp->next = NULL;
            // temp->prev = NULL;
            front = rear = temp;
        }
        else{
            temp->next = rear;
            // temp->prev = NULL;
            rear = temp;
        }
    }

    void dequeue(){  //works fine but bad time complexity since whole queue is being traversed till front of the queue is accessed/reached
        if(front == NULL){
            cout<<"\nQUEUE IS EMPTY\n";
            return;
        }
        EachNode *temp = rear;
        while(temp->next != front){
            temp = temp->next;
        }
        front = temp;
        front->next = NULL;
        
    }

    void display(){
        EachNode *temp = rear;
        cout<<endl<<"Queue: \n";
        do{
            cout<<temp->data<<endl;
            temp = temp->next;
        }while(temp != NULL);
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
    // cout<<endl<<q.size();
}