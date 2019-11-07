#include <stdlib.h>

#ifndef ListNode_H
#define ListNode_H


template<class Element> class ListNode
{
    public:
        Element* ele;
        ListNode<Element>* next;
        ListNode<Element>* prev;

        ListNode<Element>()
        {
            ele = 0;
        }
        ListNode<Element>(Element* e)
        {
            ele = e;
        }

        ~ListNode()
        {

        }
};
#endif
