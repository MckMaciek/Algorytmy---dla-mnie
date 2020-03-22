#include <iostream>

template<typename T>
class List{

private:

struct Element{
    
Element * after {nullptr};
T data;
Element(T Idata) : data(Idata), after(nullptr){}

};

public:

Element * first;
Element * last;

void print()const;

void add(unsigned long pos, T Idata);


//-------------------------------------GETPOSITION

Element * getPosition(unsigned int pos)const{

unsigned long int iter = 0;
if( pos < 1 || pos > sizeL()) return nullptr;

Element * temp = first;

while(iter++ < pos){
temp = temp-> after;
}

return temp;
}

//----------------------------------------SIZEOF


int sizeL() const{

Element * temp = this->first;
unsigned long i = 0;

while(temp != nullptr){
    
    i++;
    temp = temp->after;    
}

return i;
}

};

//-----------------------------------------PRINT

template<typename T>
void List<T>::print()const{

Element * temp = first;

while(temp != nullptr){

std::cout << temp->data << "->";

temp = temp->after;    
}

std::cout << "nullptr\n";

}


//------------------------------------------ADD

template<typename T>
void List<T>::add(unsigned long pos, T Idata){


Element * n = new Element(Idata);

if (sizeL() == 0){

    this->first = n;
    this->last =  n;
}

else if((pos == 0) || (pos == 1)){

    n->after = this->first;
    this->first  = n;
}

else if(pos > this->sizeL()){

    this->last->after = n;
    this->last = n;

}
else{

    Element * bef = getPosition(pos-1);

    n -> after = bef->after; 
    bef->after = n;

}
}

int main(){

List<int>lista;

lista.add(0,4);
lista.add(1,5);
lista.print();

return 0;
}