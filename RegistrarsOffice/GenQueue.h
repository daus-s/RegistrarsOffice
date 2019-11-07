#include "DoubleLinkedList.h"
#include <iostream>

using namespace std;

#ifndef GenQueue_H
#define GenQueue_H

template<class Element> class GenQueue
{
    /*This version of the queue uses a doubly linked list but has all
     *the same functionalities as a normal queue and needs not be circular
     *because it is based of a list
     */
    public:
        GenQueue()
        {}
        ~GenQueue()
        {
            delete dll;
        }

        void insert(Element* e)
        {
            cout << "genqueue insert" << endl;
            head++;
            dll->insertFront(e);
        }
        Element* remove()
        {
            if (!isEmpty())
            {
                tail++;
                return dll->deleteBack();
            }
        }
        Element* peek()
        {
            return dll->back;
        }

        bool isEmpty()
        {
            return head == tail;
        }
        int getSize()
        {
            return head - tail;
        }

    private:
        int head;
        int tail;
        DoubleLinkedList<Element>* dll;
};
#endif
