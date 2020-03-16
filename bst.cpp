
#include<iostream>
#include <memory>

template<typename T>
class Tree{

private:

    struct Node{

    Node *lptr;
    Node *rptr;
    Node *parent;
    T value;
    
    };

Node *root = nullptr;
   
public:


void addPrivately(T tempV, Node *node);
void inOrderPrivately(Node *node);
void postOrderPrivately(Node *node);
void preOrderPrivately(Node *node);
void lookForValuePrivately(Node *node, T Svalue);
int heightPrivately(Node *node);
int minimumPrivate(Node *node);
int maximumPrivate(Node *node);
void predecessorPrivately(Node *node,Node *prec,T value);
void removeValuePrivately(Node *node, T value);
void printBinaryTreePrivately(Node *node, int counter);
void removeRootPrivately(Node *node);
void removeMatchingNode(Node *parent, Node * node, int num);

Node * minimumPrivatelyRetPoint(Node *node){

if(node->lptr == nullptr){

        return node;
    }
    
        minimumPrivate(node->lptr); 
        
        return nullptr;
}


Node * maximumPrivatelyRetPoint(Node *node){

 if(node->rptr == nullptr){

        return node;
    }
    
        maximumPrivate(node->rptr);
 
        return nullptr;
}


Node * newNode(T Tvaluer){

Node *n = new Node;
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
inline void predecessor(T value) { Node *prec=nullptr; predecessorPrivately(root,prec,value);}
inline void removeValue(T value) { removeValuePrivately(root,value);}
inline void printBinaryTree() { printBinaryTreePrivately(root,10); }
};

//-------------------------------------------REMOVINGNODE-------------------------------------------------------

template<typename T>
void Tree<T>::removeMatchingNode(Node *parent, Node * node, int num){

if(root != nullptr){

    Node * del = new Node;
    T matchKey = node->value;
    T smallestInr;

       //**** // 1 - to left ,     0 - to right. *****

        // Matching node does not have left and right children

        if((node->lptr == nullptr) && (node->rptr == nullptr)){

                del = node;
                if(num == 1) parent->lptr = nullptr;
                else if(num ==0) parent->rptr = nullptr;
                delete del;
        }    

        // Matching node does have right children, but does not have left child.

        else if((node->lptr == nullptr) && (node->rptr != nullptr)){

                if(num == 1) parent->lptr = node->rptr;
                else if(num ==0) parent->rptr = node->rptr;
                node->rptr = nullptr;
                del = node;
                delete del;
        }         

        // Matching node does have left children, but does not have right child.

        else if((node->lptr != nullptr) && (node->rptr == nullptr)){

                if(num == 1) parent->lptr = node->lptr;
                else if(num ==0) parent->rptr = node->lptr;
                node->lptr = nullptr;
                del = node;
                delete del;
        }         

        // Matching node does have left and right child.
        
        else{

        T smallestInr = minimumPrivate(node->rptr);
        removeValuePrivately(node, smallestInr);
        node -> value = smallestInr; 
        }

}
}

//-------------------------------------------REMOVINGROOT-------------------------------------------------------

template<typename T>
void Tree<T>::removeRootPrivately(Node * node){

if(node != nullptr){
     
        Node * del = root;
        T smallestInR;

                // node(root) has no childrens

                if((root->lptr == nullptr) && (root->rptr == nullptr)){
                    root = nullptr;
                    delete del;
                }

                // node(root) has 1 child (right children)

                else if((root->lptr == nullptr) && (root->rptr != nullptr)){
                    
                    root = root->rptr;
                    del->rptr = nullptr;
                    delete del;
                }

                // node(root) has 1 child (left children) 
                 
                else if((root->lptr != nullptr) && (root->rptr == nullptr)){
                    
                    root = root->lptr;
                    del->lptr = nullptr;
                    delete del;
                }

                // node(root) has 2 children
                
                else{

                    smallestInR = minimumPrivate(root->rptr);
                    removeValuePrivately(root,smallestInR);
                    root->value = smallestInR;
                }

}


}

//-------------------------------------------PRINTING-------------------------------------------------------
template<typename T>
void Tree<T>::printBinaryTreePrivately(Node *node, int counter){

if(node != nullptr){

counter += 10;

printBinaryTreePrivately(node->rptr,counter);

std::cout << "\n";

    for(int i = 10; i < counter; ++i) std::cout << " ";
    std::cout << node->value << "\n";   

printBinaryTreePrivately(node->lptr,counter);   

}
}


//-------------------------------------------REMOVING-------------------------------------------------------
template<typename T>
void Tree<T>::removeValuePrivately(Node * node, T value){

if(root != nullptr){    
    
    
    if(node->value == value) removeRootPrivately(node);
  
    /*
    else if((node->value > value) && (node->lptr != nullptr)){
                
                if (node->lptr->value == value){
                    removeMatchingNode(node,node->lptr,0);
                }
                else{
                removeValuePrivately(node->lptr,value);
                }
      
    }
    */
    else if((node->value < value) && (node->rptr != nullptr)){
                
                if (node->rptr->value == value){
                    removeMatchingNode(node,node->rptr,1);
                }
                else{
                removeValuePrivately(node->rptr,value);
                }
            
    }
    else{
            std::cout << "Value "<< value  <<" not found";
    }

 
}  
}

//-------------------------------------------LOOKINGFORPREDECESSOR-------------------------------------------------------

template<typename T>
void Tree<T>::predecessorPrivately(Node *node,Node *prec,T Ivalue){

    if(node != nullptr){


	    if (node->value == Ivalue){
	
		    if (node->lptr != nullptr){
             
             prec = maximumPrivatelyRetPoint(node->lptr);
             std::cout << prec->value;
            }        
        
        }

	    else if (Ivalue < node->value){
	
		predecessorPrivately(node->lptr, prec, Ivalue);
	        }


	    else{
		prec = node;
		predecessorPrivately(node->rptr, prec, Ivalue);
	    }
        
    }

}

//-------------------------------------------MINIMALVALUE-------------------------------------------------------


template<typename T>
int Tree<T>::maximumPrivate(Node *node){

 if(node->rptr == nullptr){

        return node->value;
    }
    
        return maximumPrivate(node->rptr);
 
}

//-------------------------------------------MAXIMUMVALUE-------------------------------------------------------

template<typename T>
int Tree<T>::minimumPrivate(Node *node){

    if(node->lptr == nullptr){

        return node->value;
    }
    
        return minimumPrivate(node->lptr);
 
}

//-------------------------------------------TREEHEIGHT-------------------------------------------------------


template<typename T>
int Tree<T>::heightPrivately(Node *node){

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

//-------------------------------------------SEARCHFORVALUE-------------------------------------------------------

template<typename T>
void Tree<T>::lookForValuePrivately(Node *node,T Svalue){


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

//-------------------------------------------PREORDERTRAVEL-------------------------------------------------------

template<typename T>
void Tree<T>::preOrderPrivately(Node *node){

 if(node != nullptr){

    std::cout << node->value << ", ";
    inOrderPrivately(node->lptr);
    inOrderPrivately(node->rptr);
    }

}

//-------------------------------------------POSTORDERTRAVEL-------------------------------------------------------

template<typename T>
void Tree<T>::postOrderPrivately(Node *node){

 if(node != nullptr){

    inOrderPrivately(node->lptr);
    inOrderPrivately(node->rptr);
    std::cout << node->value << ", ";
    }

}

//-------------------------------------------INORDERTRAVEL-------------------------------------------------------

template<typename T>
void Tree<T>::inOrderPrivately(Node *node){

    if(node != nullptr){

    inOrderPrivately(node->lptr);
    std::cout << node->value << ", ";
    inOrderPrivately(node->rptr);
    }


}

//-------------------------------------------ADDTOTHETREE-------------------------------------------------------

template<typename T>
void Tree<T>::addPrivately(T tempV, Node *node){

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

//-------------------------------------------MAIN-------------------------------------------------------

int main(){

    Tree<int>Drzewo;
   
    Drzewo.insert(3);
    Drzewo.insert(40);
    Drzewo.insert(4);
    Drzewo.insert(2);
    Drzewo.insert(43);
    Drzewo.insert(443);
    Drzewo.insert(1);

    //Drzewo.inOrder();
    //std::cout << "\n";
    //Drzewo.preOrder();
    //std::cout << "\n";
    //Drzewo.postOrder();
    //std::cout << "\n";
   
    Drzewo.printBinaryTree();

    Drzewo.removeValue(3);

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";


    Drzewo.printBinaryTree();
    

    //std::cout << Drzewo.minimum() << "\n";
    //std::cout << Drzewo.maximum() << "\n";
    //Drzewo.preOrder();
    //Drzewo.lookForValue(11);
    //std::cout << Drzewo.height();


    return 0;
}