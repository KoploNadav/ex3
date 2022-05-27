#include "Queue.h"

template<class T>
void Queue<T>::pushBack(T data){
    Node temp = new Node(data, nullptr);
    if(this->front() == nullptr){
        this->m_first = temp;
        this->m_last = temp;
        this->m_count++;
    }
    else{
        this->m_last->next = &temp;
        this->m_last = temp;
        this->m_count++;
    }
}

template <class T>
T Queue<T>::front() {
    if(!this->m_first){
        throw Queue<T>::EmptyQueue();
    }
    return this->m_first->data;
}

template <class T>
void Queue<T>::popFront(){
    if(!this->m_first){
        throw Queue<T>::EmptyQueue();
    }
    Node temp = this->m_first;
    this->m_first = this->m_first->next;
    //delete temp;
    this->m_count--;
}

template <class T>
int Queue<T>::size(){
    return this->m_count;
}

template <class T>
Queue<T> filter(const Queue<T> queue, bool (*func)){
    Queue<T> newQueue;
    for(typename Queue<T>::ConstIterator it = queue.begin(); it!=queue.end(); it++){
        if(func(it.data)){
            newQueue.pushBack(it.data);
        }
    }
    return newQueue;
}

template <class T>
void transform(Queue<T> queue, void (*func)){
    for(typename Queue<T>::Iterator it = queue.begin(); it!=queue.end(); it++){
        func(it.data);
    }
}

template <class T>
typename Queue<T>::Iterator Queue<T>::begin(){
    return Iterator(this->queue.m_first);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end(){
    return nullptr;
}

template <class T>
Queue<T>::Iterator::Iterator(const Queue<T> *queue, int index):
    queue(queue),
    index(index)
    {}

template <class T>
const T& Queue<T>::Iterator::operator*() const {
    assert(index >= 0 && index < queue->size());
    return queue->data[index];
}

template <class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++() {
    ++index;
    return *this;
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Iterator& i) const {
    assert(queue != i.queue);
    return index = i.index;
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const{
    return ConstIterator(this->queue.m_first);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::end() const{
    return nullptr;
}

template <class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T> *queue, int index):
        queue(queue),
        index(index)
{}

template <class T>
const T& Queue<T>::ConstIterator::operator*() const {
    assert(index >= 0 && index < queue->size());
    return queue->data[index];
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++() {
    ++index;
    return *this;
}

template <class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& i) const {
    assert(queue != i.queue);
    return index = i.index;
}