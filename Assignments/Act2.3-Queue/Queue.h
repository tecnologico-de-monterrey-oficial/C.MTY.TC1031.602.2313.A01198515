#ifndef Queue_h
#define Queue_h


template<class T>
class Queue{
    private:
    Node<T>* front;
    Node<T>* tail;
    public:
    Queue();
    void push(Tdata); //agrega un elemento final de la fila 
    void pop();//elimina el primer eleme 67nto de la fila 
    T front()
}


#endif
