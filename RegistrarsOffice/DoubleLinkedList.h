#include <string>
#include <iostream>
#include "ListNode.h"
#include <iostream>

using namespace std;

#ifndef DoubleLinkedList_H
#define DoubleLinkedList_H

template<class Element> class DoubleLinkedList
{
    public:
        ListNode<Element>* head;
        ListNode<Element>* back;
        int size;


        //Adds an element at the beginning of the list.
        void insertFront(Element* node)
        {
            cout << "DLL insert front" << endl;
            ListNode<Element>* insert = new ListNode<Element>(node);
            cout << "empty list check" << endl;
            if (&head == NULL)
            {
                //empty list op.
                cout << "empty list" << endl;
                head = insert;
                back = insert;
                cout << "post assignment" << endl;
            }
            else
            {
                //standard op
                cout << "getting there, standard op" << endl;
                head->prev = insert;
                insert.next = head;
                head = insert;

            }
            size++;
        }

        //Adds an element at the end of the list.
        void insertBack(Element* node)
        {
            ListNode<Element> insert = new ListNode<Element>(node);
            //empty list case
            if (head == NULL)
            {
                head = node;
                back = node;
            }
            else
            {
                node->prev = back;
                back->next = node;
                back = node;
            }
            size++;
        }

        Element* remove(Element e) //Deletes/but delete is a keyword, so this one is remove/ an element from the list using the key.
        {

            ListNode<Element>* curr = head;
            while(curr->ele != e && curr!=NULL)
            {
                curr = curr->next;
            }
            if (curr != NULL)
            {
                curr->next->prev = curr->prev;
                curr->prev->next = curr->next;
                curr = NULL;
                size--;
            }
            return e;
        }
        //Deletes an element at the beginning of the list.
        Element* deleteFront()
        {
            if (size == 0)
            {
                //should check if there are elements first in the DLL
                exit(12);
            }
            if (size == 1)
            {
                head = NULL;
                back = NULL;
            }

            head = head->next;
            Element e = head->prev->ele;
            head->prev = NULL;
            return e;
        }


        Element* deleteBack() //Deletes an element from the end of the list.
        {
            if (size == 0)
            {
                //should check if there are elements first in the DLL
                exit(12);
            }
            if (size == 1)
            {
                head = NULL;
                back = NULL;
            }

            back = back->prev;
            Element* e = back->next->ele;
            back->next = NULL;
            return e;
        }



        ///Searches for and returns the value of the
        Element* search(Element value)
        {
            ListNode<Element> curr = head;
            //empty DLL case
            if (head == NULL)
            {
                return NULL;
            }
            if (head->ele == value)
            {
                return head;
            }
            while (curr->next->ele != value)
            {
                curr = curr->next;
            }
            return curr->next;
        }

        DoubleLinkedList()
        {
            head = NULL;
            back = NULL;
            size = 0;
        }

        ~DoubleLinkedList()
        {
            ListNode<Element>* node = head;
            while (node->next != NULL)
                delete node;
        }
};

#endif
