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

    T dequeue(){  //works fine but bad time complexity since whole queue is being traversed till front of the queue is accessed/reached
        if(front == NULL){
            cout<<"\nQUEUE IS EMPTY\n";
            return -1;
        }
        EachNode *temp = rear;
        while(temp->next != front){
            temp = temp->next;
        }
        int a = front->data;
        front = temp;
        front->next = NULL;  
        return a; 
    }

    void display(){
        EachNode *temp = rear;
        cout<<endl<<"Queue: \n";
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != NULL);
    }
};

int main(){
    queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    
    q.display();

    int num = 0;
    cout<<"\nenter the number of elements you want to reverse: ";
    cin>>num;
    int *arr = new int[num];
    for(int i = num-1; i>=0; i--){
        int temp = q.dequeue();
        arr[i] = temp;
    }

    q.display();
    for(int i = num-1; i>=0; i--){
        cout<<arr[i]<<" ";
    }

    // cout<<endl<<q.size();
}