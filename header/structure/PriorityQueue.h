//
// Created by Ian on 09-Jan-18.
//

#ifndef COMPRESSOR_PRIORITYQUEUE_H
#define COMPRESSOR_PRIORITYQUEUE_H

template <class T>
struct Node{
    T* value;
    int priority;
};

template <class T>
class PriorityQueue{
private:
    Node<T>* queue[10];
    int size;
    int arraySize;
    const int ENLARGING_SIZE = 10;

    void exchange(int firstIndex, int secondIndex);
    void sift();
public:
    PriorityQueue();
    virtual ~PriorityQueue();
    void enqueue(T* value, int priority);
    T* dequeue();
    int getSize();
    void print();
    void enlarge();
};

template <class T>
PriorityQueue<T>::PriorityQueue(){
    this->size = 0;
    this->arraySize = 10;
}

template <class T>
PriorityQueue<T>::~PriorityQueue() {
    delete this->queue;
}

template <class T>
int PriorityQueue<T>::getSize() {
    return this->size;
}

template <class T>
void PriorityQueue<T>::enqueue(T* value, int priority){
    if(this->size + 1 == this->arraySize){
        this->enlarge();
    }
    Node<T>* newNode = new Node<T>();
    newNode->value = value;
    newNode->priority = priority;
    this->queue[this->size] = newNode;
    this->size++;
    if(this->size > 1){
        int currIndex = size - 1;
        while(currIndex > 0 && this->queue[currIndex]->priority < this->queue[(currIndex / 2)]->priority){
            this->exchange(currIndex, (currIndex/2));
            currIndex = (currIndex/2);
        }
    }
}

template <class T>
T* PriorityQueue<T>::dequeue() {
    T* toReturn = 0;
    if(this->size > 0) {
        this->exchange(0, size - 1);
        toReturn = this->queue[size]->value;
        size--;
        this->sift();
    }
    return toReturn;
}

template <class T>
void PriorityQueue<T>::exchange(int firstIndex, int secondIndex) {
    Node<T>* tempNode = this->queue[firstIndex];
    this->queue[firstIndex] = this->queue[secondIndex];
    this->queue[secondIndex] = tempNode;
}

template <class T>
void PriorityQueue<T>::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << *queue[i]->value << std::endl;
    }
}

template<class T>
void PriorityQueue<T>::sift() {
    for(int i = 0, j = (2*i)+1; j < size; i = j, j = i<<1){
        if(j + 1 < this->size && this->queue[j + 1]->priority < this->queue[j]->priority)
            j++;

        if(this->queue[i]->priority > this->queue[j]->priority)
            exchange(i, j);
    }
}

template<class T>
void PriorityQueue<T>::enlarge(){
    Node<T>* newQueue[this->arraySize + this->ENLARGING_SIZE];
    for(int i = 0; i < this->arraySize; i++){
        newQueue[i] = this->queue[i];
    }
    *this->queue = *newQueue;
    this->arraySize += this->ENLARGING_SIZE;
}
#endif //COMPRESSOR_PRIORITYQUEUE_H
