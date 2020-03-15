#include<iostream>
#include <memory>

template<typename T>
class Tree{

private:

    struct Node{

    std::shared_ptr<Node>lptr;
    std::shared_ptr<Node>rptr;
    std::shared_ptr<Node>parent;
    T value;
    
    };

std::shared_ptr<Node>root;
   
public:


void addPrivately(T tempV, std::shared_ptr<Node>node);
void inOrderPrivately(std::shared_ptr<Node>node);
void postOrderPrivately(std::shared_ptr<Node>node);
void preOrderPrivately(std::shared_ptr<Node>node);
void lookForValuePrivately(std::shared_ptr<Node>node, T Svalue);
int heightPrivately(std::shared_ptr<Node>node);
int minimumPrivate(std::shared_ptr<Node>node);
int maximumPrivate(std::shared_ptr<Node>node);
void predecessorPrivately(std::shared_ptr<Node>node,std::shared_ptr<Node>prec,T value);
void removeValuePrivately(std::shared_ptr<Node>node, T value);
void printBinaryTreePrivately(std::shared_ptr<Node>node, int counter);
void removeRootPrivately(std::shared_ptr<Node>node);

std::shared_ptr<Node> minimumPrivatelyRetPoint(std::shared_ptr<Node>node){

if(node->lptr == nullptr){

        return node;
    }
    
        minimumPrivate(node->lptr); 
        
        return nullptr;
}


std::shared_ptr<Node> maximumPrivatelyRetPoint(std::shared_ptr<Node>node){

 if(node->rptr == nullptr){

        return node;
    }
    
        maximumPrivate(node->rptr);
 
        return nullptr;
}


std::shared_ptr<Node> newNode(T Tvaluer){

std::shared_ptr<Node>n = std::make_shared<Node>();
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
inline void predecessor(T value) { std::shared_ptr<Node>prec; predecessorPrivately(root,prec,value);}
inline void removeValue(T value) { removeValuePrivately(root,value);}
inline void printBinaryTree() { printBinaryTreePrivately(root,10); }
};

//-------------------------------------------REMOVINGROOT-------------------------------------------------------

template<typename T>
void Tree<T>::removeRootPrivately(std::shared_ptr<Node> node){

if(node != nullptr){
     
        std::shared_ptr del = std::make_shared<Node>(node);
        T rootKey = node->value;
        T smallestInR;

                // node(root) has no childrens

                if((node->lptr == nullptr) && (node->rptr == nullptr)){
                    node = nullptr;
                    del = nullptr;
                }

                // node(root) has 1 child (right children)

                else if((node->lptr == nullptr) && (node->rptr != nullptr)){
                    
                    node = node->rptr;
                    del = nullptr; 
                    std::cout << rootKey << " has been removed";
                }

                // node(root) has 1 child (left children) 
                 
                else if((node->lptr != nullptr) && (node->rptr == nullptr)){
                    
                    node = node->lptr;
                    del = nullptr; 
                    std::cout << rootKey << " has been removed";
                }

                // node(root) has 2 children
                
                else{

                    smallestInR = minimumPrivate(node->rptr);
                    removeValuePrivately(node,smallestInR);
                    node->value = smallestInR;
                }

}


}

//-------------------------------------------PRINTING-------------------------------------------------------
template<typename T>
void Tree<T>::printBinaryTreePrivately(std::shared_ptr<Node>node, int counter){

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
void Tree<T>::removeValuePrivately(std::shared_ptr<Node> node, T value){

    if(node->value == value){

    removeRootPrivately(node);

    }
    
}
    /*
    else if{

        if((node->value > value) && (node->lptr != nullptr)){

                if (node->lptr->value == value){

                }
                else{
                removeValuePrivately(node->lptr,value);
                }
      
        }

        else if((node->value < value) && (node->rptr != nullptr)){

                if (node->rptr->value == value){
                    
                }
                else{
                removeValuePrivately(node->rptr,value);
                }

            
        }
        else{
            std::cout << "Value "<< value  <<" not found";
        }

    }
*/

//-------------------------------------------LOOKINGFORPREDECESSOR-------------------------------------------------------

template<typename T>
void Tree<T>::predecessorPrivately(std::shared_ptr<Node>node,std::shared_ptr<Node>prec,T Ivalue){

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
int Tree<T>::maximumPrivate(std::shared_ptr<Node>node){

 if(node->rptr == nullptr){

        return node->value;
    }
    
        return maximumPrivate(node->rptr);
 
}

//-------------------------------------------MAXIMUMVALUE-------------------------------------------------------

template<typename T>
int Tree<T>::minimumPrivate(std::shared_ptr<Node>node){

    if(node->lptr == nullptr){

        return node->value;
    }
    
        return minimumPrivate(node->lptr);
 
}

//-------------------------------------------TREEHEIGHT-------------------------------------------------------


template<typename T>
int Tree<T>::heightPrivately(std::shared_ptr<Node>node){

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
void Tree<T>::lookForValuePrivately(std::shared_ptr<Node>node,T Svalue){


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
void Tree<T>::preOrderPrivately(std::shared_ptr<Node>node){

 if(node != nullptr){

    std::cout << node->value << ", ";
    inOrderPrivately(node->lptr);
    inOrderPrivately(node->rptr);
    }

}

//-------------------------------------------POSTORDERTRAVEL-------------------------------------------------------

template<typename T>
void Tree<T>::postOrderPrivately(std::shared_ptr<Node>node){

 if(node != nullptr){

    inOrderPrivately(node->lptr);
    inOrderPrivately(node->rptr);
    std::cout << node->value << ", ";
    }

}

//-------------------------------------------INORDERTRAVEL-------------------------------------------------------

template<typename T>
void Tree<T>::inOrderPrivately(std::shared_ptr<Node>node){

    if(node != nullptr){

    inOrderPrivately(node->lptr);
    std::cout << node->value << ", ";
    inOrderPrivately(node->rptr);
    }


}

//-------------------------------------------ADDTOTHETREE-------------------------------------------------------

template<typename T>
void Tree<T>::addPrivately(T tempV, std::shared_ptr<Node>node){

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
    Drzewo.printBinaryTree();

    //std::cout << Drzewo.minimum() << "\n";
    //std::cout << Drzewo.maximum() << "\n";
    //Drzewo.preOrder();
    //Drzewo.lookForValue(11);
    //std::cout << Drzewo.height();


    return 0;
}