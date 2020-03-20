#include "bst.cpp"

template<typename T>
class Queue{

private:

    struct Element{

    T data;
    Element * after {nullptr};
    Element(T value) : data(value), after(nullptr){} 
    };

Element * first {nullptr};
Element * last  {nullptr};

void addPrivately(Element * &first, Element  * &last, T idata);
void findByValuePrivately(T ivalue)const;
void removePrivately();

public:

void add(T idata){ addPrivately(first, last, idata);}
void print()const;
void findByValue(T ivalue)const{findByValuePrivately(ivalue);}
void remove() {removePrivately();}
unsigned countElements()const;
};

template<typename T>
unsigned Queue<T>::countElements()const{

Element * temp = first;

unsigned iter = 0;

while(temp != nullptr){

iter++;
temp = temp->after;    
}

return iter;
}

template<typename T>
void Queue<T>::addPrivately(Element  * &first, Element  * &last, T idata){

Element * elem = new Element(idata);

if(first == nullptr){

    first = last =  elem;
}
else{

    last -> after = elem;
    last = elem;

}

}

template<typename T>
void Queue<T>::print()const{

Element * temp = first;

while(temp!= nullptr){

std::cout << temp->data << " ";
temp = temp->after; 
}

}

template<typename T>
void Queue<T>::findByValuePrivately(T ivalue)const{

Element * temp = first;

while(temp != nullptr){

    if(temp->data == ivalue) std::cout << "Found " << temp->data << " ";

temp = temp->after;
}

}

template<typename T>
void Queue<T>::removePrivately(){

Element * temp = this->last;

if(last == nullptr) return;

T tempV = first->data; 
std::cout << "Removing " << tempV;
first = first->after;

}
