#include<iostream>
using namespace std;

class union_find{
    private:
    int size, num_of_components;

    int *size_arr, *id_arr;
    //size_arr contains size of each component, initaially = 1
    //id_arr contains the values of components

    public:

    union_find(int len){
        size = num_of_components = len;
        size_arr = new int[len];
        id_arr = new int[len];
        for(int i = 0; i<size; i++){
            size_arr[i] = 1;  //iniatially, size of each node/component is 1
            id_arr[i] = i;  //link to itself
        }
    }

    int find(int elem){
        int root = elem;
        while(root != id_arr[root]){
            root = id_arr[root];
        }

        while(elem != root){
            int next = id_arr[elem];
            id_arr[elem] = root;
            elem = next;
        }
        return root;
    }

    void unify(int p, int q){
        int root1 = find(p);
        int root2 = find(q);
        if(root1 == root2)
            return;
        //merge smaller component/set into the larger one
        if(size_arr[root1] < size_arr[root2]){
            size_arr[root2] += size_arr[root1];
            id_arr[root1] = root2;
        }
        else{
            size_arr[root1] += size_arr[root2];
            id_arr[root2] = root1;
        }  
        num_of_components--;
    }

    bool connected(int p, int q){
        return(find(p) == find(q));
    }

    int cluster_size(int p){
        return(size_arr[p]);
    }
};

int main(){
    union_find UF(6);
    UF.unify(3, 4);
    UF.unify(0, 1);
    UF.unify(1, 3);
    cout<<endl<<UF.find(4)<<endl;
    cout<<endl<<UF.connected(0, 3);
}