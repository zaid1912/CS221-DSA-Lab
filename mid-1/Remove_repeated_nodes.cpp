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
    void remove_repeated_nodes(){
        node *temp1 = head;
        node *temp2 = head->next;
        while(temp2 != NULL){
            if(temp2->data != temp1->data){
                temp1->next = temp2;
                temp2->prev = temp1;
                temp1 = temp2;
            }
            temp2 = temp2->next;
        }
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
    l.remove_repeated_nodes();
    cout<<"\nafter deleting duplicate: ";
    l.display();

}