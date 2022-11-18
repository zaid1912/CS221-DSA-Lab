#include <iostream>
using namespace std;

class list
{
    struct node
    {
        int data;
        node *next;
        node *prev;
    };
    node *head;

public:
    list()
    {
        head = NULL;
    }

    void insert(int key)
    {
        node *newnode = new node;
        newnode->data = key;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            node *traverse = head;
            node *temp = head->next;
            while (temp != NULL)
            {
                temp = temp->next;
                traverse = traverse->next;
            }
            temp = newnode;
            traverse->next = temp;
            temp->prev = traverse;
        }
    }
    void display(){
        node *traverse = head;
        while(traverse != NULL){
            cout<<traverse->data<<" ";
            traverse = traverse->next;
        }
    }
    void find_last_divisible(int k){
        int num = head->data;
        node *traverse = head;
        while(traverse != NULL){
            if(traverse->data % k == 0){
                num = traverse->data;
            }
            traverse = traverse->next;
        }
        cout<<"\nLast element in the linked list that is divisible by k is: "<<num<<endl;
    }
};

int main(){
    list l;
    int size = 10;
    int *arr = new int[size];
    cout<<"\nEnter the elements in ascending order: ";

    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    for(int i = 0; i<size; i++){
        l.insert(arr[i]);
    }

    cout<<"\ndisplaying: ";
    l.display();
    l.find_last_divisible(3);

}