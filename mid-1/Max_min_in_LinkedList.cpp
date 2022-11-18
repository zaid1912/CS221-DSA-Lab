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
    void max_min(){
        int max = head->data;
        int min = head->data;
        node *traverse = head;
        while(traverse != NULL){
            if(traverse->data > max){
                max = traverse->data;
            }
            if(traverse->data < min){
                min = traverse->data;
            }
            traverse = traverse->next;
        }
        cout<<"\nMaximum element in the linked list: "<<max<<endl;
        cout<<"\nMinimum element in the linked list: "<<min<<endl;
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
    l.max_min();

}