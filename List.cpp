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
void remove(unsigned long pos);
void addP(unsigned long pos, T Idata);


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

//------------------------------------------REMOVE

template<typename T>
void List<T>::remove(unsigned long pos){

if(sizeL() == 0 || pos == 0){ std::cout << "Nothing to remove\n";return;}


else if(sizeL() == 1){

    this->first = nullptr;
    this->last = nullptr;
    delete first;
}

else if( pos == 1){

    Element * temp = first;
    this->first = this->first->after;
    delete temp;

}


else if( pos == sizeL()){

    Element * bef = getPosition(sizeL()-1);
    delete bef->after; 
    bef->after = nullptr;
    this->last =  bef;
}

else{

    Element * bef = getPosition(pos-1);
    Element * temp = getPosition(pos);

    bef->after = temp->after;
    delete temp;
}

}
//-----------------------------------------PRINT

template<typename T>
void List<T>::print()const{

Element * temp = first;

std::cout << "HEAD = ";
while(temp != nullptr){

std::cout << temp->data << "<-";

temp = temp->after;    
}

std::cout << "nullptr\n";

}


//------------------------------------------ADD

template<typename T>
void List<T>::addP(unsigned long pos, T Idata){


Element * n = new Element(Idata);

if(pos == 0) {std::cout << "Invalid range\n"; exit(-1);}

else if (sizeL() == 0){

    this->first = n;
    this->last =  n;
}


else if(pos == 1){

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

lista.addP(1,99);


lista.remove(0);
lista.print();

return 0;
}
