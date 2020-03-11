#include<iostream>
#include <memory>

template<typename T>
class Tree{

private:

    struct Node{

    Node * lptr; 
    Node * rptr; 
    Node * parent;
    T value;
    
    };

Node * root = nullptr;
   
public:


void addPrivately(T tempV, Node * node);
void inOrderPrivately(Node * node);
void postOrderPrivately(Node * node);
void preOrderPrivately(Node * node);
void lookForValuePrivately(Node * node, T Svalue);
int heightPrivately(Node * node);
int minimumPrivate(Node * node);
int maximumPrivate(Node * node);


Node * newNode(T Tvaluer){

Node * n = new Node;
n->lptr = nullptr;
n->rptr = nullptr;
n->value = Tvaluer;

return n;
}

inline void inOrder(){ inOrderPrivately(root);}
inline void preOrder() {preOrderPrivately(root);}
inline void postOrder() {postOrderPrivately(root);}
inline void lookForValue(T value) { lookForValuePrivately(root,value);}
inline void insert(T tempV) { addPrivately(tempV,root);}
inline int height(){  unsigned v = heightPrivately(root); return v;}
inline int minimum() { int min = minimumPrivate(root); return min;}
inline int maximum() { int max = maximumPrivate(root); return max;}

};

template<typename T>
int Tree<T>::maximumPrivate(Node * node){

 if(node->rptr == nullptr){

        return node->value;
    }
    
        return maximumPrivate(node->rptr);
 
}

template<typename T>
int Tree<T>::minimumPrivate(Node * node){

    if(node->lptr == nullptr){

        return node->value;
    }
    
        return minimumPrivate(node->lptr);
 
}


template<typename T>
int Tree<T>::heightPrivately(Node * node){

if (root != nullptr){

    if(node==nullptr) return 0;

    else{

    int left = heightPrivately(node->lptr);
    int right = heightPrivately(node->rptr);

    return(left>right ? left+1 : right+1);
    }
}

return -1;
}

template<typename T>
void Tree<T>::lookForValuePrivately(Node * node,T Svalue){


if(node->value != Svalue){
    
    if(node->lptr != nullptr){
     lookForValuePrivately(node->lptr,Svalue);       
    }   

    if(node->rptr != nullptr){
     lookForValuePrivately(node->rptr,Svalue);
    }
}
else{
    std::cout << "Value found\n";
}

}

template<typename T>
void Tree<T>::preOrderPrivately(Node * node){

 if(node != nullptr){

    std::cout << node->value << "\n";
    inOrderPrivately(node->lptr);
    inOrderPrivately(node->rptr);
    }

}


template<typename T>
void Tree<T>::postOrderPrivately(Node * node){

 if(node != nullptr){

    inOrderPrivately(node->lptr);
    inOrderPrivately(node->rptr);
    std::cout << node->value << "\n";
    }

}

template<typename T>
void Tree<T>::inOrderPrivately(Node *  node){

    if(node != nullptr){

    inOrderPrivately(node->lptr);
    std::cout << node->value << "\n";
    inOrderPrivately(node->rptr);
    }


}

template<typename T>
void Tree<T>::addPrivately(T tempV, Node * node){

    if(root == nullptr)  root = newNode(tempV);
    
    else if(tempV <=  node->value){
        
        if(node->lptr != nullptr) addPrivately(tempV, node->lptr); 
        else node->lptr = newNode(tempV);
    }

    else if(tempV >= node->value){

        if(node->rptr != nullptr) addPrivately(tempV,node->rptr);
        else node->rptr = newNode(tempV);
    }

} 



int main(){

    Tree<int>Drzewo;
    Drzewo.insert(3);
    Drzewo.insert(40);
    Drzewo.insert(4);
    Drzewo.insert(2);
    Drzewo.insert(43);
    Drzewo.insert(443);
    Drzewo.insert(412);


    //std::cout << Drzewo.minimum() << "\n";
    //std::cout << Drzewo.maximum() << "\n";
    std::cout << Drzewo.height() << "\n";
    //Drzewo.preOrder();
    //Drzewo.lookForValue(11);
    //std::cout << Drzewo.height();


    return 0;
}