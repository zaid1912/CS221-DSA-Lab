#include<iostream>
using namespace std;

template<class T>
class binary_tree{
    private:
    int size; //number of nodes a tree contains

    struct node{
    T val;  //each node in the tree has a value stored in it
    node *left;  //each node has a pointer to its next left node
    node *right;  //each pointer in the tree has a pointer to its next right node
    node(T elem){
        val = elem;
        left = nullptr;
        right = nullptr;
    }
    };
    node *root;

    public:

    binary_tree(){  //constructor
        size = 0;  //initially a tree is empty to its size is 0
        root = nullptr;
    }

    void add(T elem){

       
        node *temp_node = new node(elem);  //creating a temporary new node
        
        if(root == nullptr){  //for the very first node of the tree, root node is null so set temp node equal to root node
            root = temp_node;
            cout<<"\nroot\n";  //for own testing purposes, please ignore
            ++size;
            return;
        }

        node *current_node = root;  //created a new node which initially contains root node

        while(current_node != nullptr){ 
            if(elem <= current_node->val){
                cout<<"\ngoing left\n";  //for own testing purposes. please ignore
                if(current_node->left == nullptr){
                    current_node->left = temp_node;
                    ++size;
                    cout<<"\nleft...."<<endl; //for own testing purposes. please ignore
                    return;
                }
                else{
                    current_node = current_node->left;
                }
            }
            else{
                cout<<"\ngoing right\n";  //for own testing purposes. please ignore
                if(current_node->right == nullptr){
                    current_node->right = temp_node;
                    ++size;
                    cout<<"\nright...."<<endl;
                    return;
                }
                else{
                    current_node = current_node->right;
                }
            }
        }

    }

    void search_node(T elem){
        node *temp = root;
        if(root == nullptr){
            cout<<"\nTree is empty\n";
            return;
        }
        else if(elem == root->val){
            cout<<"\nValue is at the root\n";
            return;
        }
        while(1){
            if(elem<=temp->val){
                temp = temp->left;
                if(temp == nullptr){
                    cout<<"\nvalue not found\n";
                    return;
                }
                else if(temp->val == elem){
                    cout<<"\nValue found\n";
                    return;
                }
            }
            else{
                temp = temp->right;
                if(temp == nullptr){
                    cout<<"\nvalue not found\n";
                    return;
                }
                else if(temp->val == elem){
                    cout<<"\nvalue found\n";
                    return;
                }
                
            }
        }
    }

    int tree_size(){  //returns the size(number of nodes) of the tree
        return size;
    }

};

int main(){

        //        8
        //       /\
        //      3  10
        //     / \
        //   1    6
        //       /
        //      4 


    binary_tree<int> tree;
    tree.add(8);
    tree.add(3);
    tree.add(10);
    tree.add(1);
    tree.add(6);
    tree.add(4);
    cout<<tree.tree_size();
    tree.search_node(5);
    return 0;
}