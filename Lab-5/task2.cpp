// 1 2 3 4 5 6 7 8
// 1 2 3 4    5 6 7 8
// 1 5 2 6 3 7 

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

    int dequeue(){  //works fine but bad time complexity since whole queue is being traversed till front of the queue is accessed/reached
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
// int queue::len = 0;
int main(){
    queue<int> q;

    int count = 0;
    int l = 0;
    q.enqueue(1);
    count++;
    q.enqueue(2);
    count++;
    q.enqueue(3);
    count++;
    q.enqueue(4);
    count++;
    q.enqueue(5);
    count++;
    q.enqueue(6);
    count++;
    q.enqueue(7);
    count++;
    q.enqueue(8);
    count++;
    
    
    q.display();
    // cout<<endl<<count;

    int *arr = new int[count];

    for(int i = 0; i<count; i++){
        int temp = q.dequeue();
        arr[i] = temp;
    }

    int *temparr1 = new int[count/2];
    int *temparr2 = new int[count/2];

    for(int i = 0; i < count<2; i++){
        temparr1[i] = arr[i];
    }

    for(int i = count/2; i < count; i++){
        temparr2[i] = arr[i];
    }

    queue<int> q2;

    for(int i = 0; i< count/2; i++){
        q2.enqueue(temparr1[i]);
        q2.enqueue(temparr2[i]);
    }
    
}