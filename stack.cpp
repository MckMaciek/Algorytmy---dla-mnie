#include "bst.cpp"

template<typename T>
class Stack{

private:
T data;
Stack * under {nullptr};
Stack * top   {nullptr}; 

void addPrivately(T data, Stack * &top);
void listPrivately(Stack * top)const;
T popPrivately(Stack * &top);

public:

void add(T data) { addPrivately(data,top);}
void list() { listPrivately(top);}
T pop() { return(popPrivately(top));}

};

template<typename T>
void Stack<T>::addPrivately(T idata, Stack * &top){

Stack * temp = new Stack;
temp->data = idata;
temp->under = top;
top = temp;

}

template<typename T>
void Stack<T>::listPrivately(Stack * top)const{

while(top!=nullptr){

std::cout << top->data << " ";
top = top->under;

}

}

template<typename T>
T Stack<T>::popPrivately(Stack * &top){

if(top == nullptr) return 0;

Stack * temp = top;
T tempData = top->data; 
top = top->under; 
delete temp;
return tempData;

}
