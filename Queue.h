#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

template <class T>
class Queue {
    struct Node {
        T data;
        Node *next = nullptr;
    };
    Node *m_first;
    Node *m_last;
    int m_count = 0;

public:

    class EmptyQueue {
    };

    class Iterator;

    class ConstIterator;

    Iterator begin();

    Iterator end();

    ConstIterator begin() const;

    ConstIterator end() const;

    /**
     * @brief Construct an empty Queue
     */

    Queue();

    void pushBack(T data);


    T front();

    void popFront();

    int size();



};

template <class T>
Queue<T> filter(const Queue<T> queue, bool (*func));

template <class T>
void transform(Queue<T> queue, void (*func));

template <class T>
class Queue<T>::Iterator{
    Queue<T> queue;
    int index;
    Iterator(const Queue<T>* queue, int index);
    friend class Queue<T>;


public:
    const T& operator*() const;
    Iterator operator++();

    bool operator!=(const Iterator& iterator) const;

    Iterator(const Iterator&)= default;
    Iterator& operator=(const Iterator&) = default;

    class InvalidOperation{};
};


template <class T>
class Queue<T>::ConstIterator{
    const Queue<T> queue;
    int index;
    ConstIterator(const Queue<T>* queue, int index);
    friend class Queue<T>;


public:
    const T& operator*() const;
    ConstIterator operator++();

    bool operator!=(const ConstIterator& iterator) const;

    ConstIterator(const ConstIterator&)= default;
    ConstIterator& operator=(const ConstIterator&) = default;

    class InvalidOperation{};
};

#endif //EX3_QUEUE_H
