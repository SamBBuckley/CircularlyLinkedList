#include <iostream>
#include "Node.h"

//////////////////////////////////////////////////////////////////////////////
//  A simple decleration of a LinkedList this one will only use integers    //
//  However it could be made more abstract by using 'typing'                //
//////////////////////////////////////////////////////////////////////////////
class LinkedList {
    Node* head;
    unsigned int size;
public:
    //My Constructors
    LinkedList() : head(nullptr), size(0) {}
    LinkedList(int value);

    //Big Three
    LinkedList(const LinkedList& ll); // Where ll is a LinkedList
    LinkedList& operator=(const LinkedList& rhs); // Where rhs is the LinkedList on the right side of =
    ~LinkedList();

    //Helper Functions
    void clear();
    void push_back(int value);


    //Public functions
    void print();
    void orderedPushBack(int value);

private:
//Private Helper Functions
    void copy(const LinkedList& src);
};

//////////////////////////////////////////////////////////////////////////////
//                       Decleration of Helper Functions                    //
//////////////////////////////////////////////////////////////////////////////
void LinkedList::copy(const LinkedList& src) {
    Node* srcCur = src.head;
    Node* cur = head;
    while(srcCur->next != src.head) {
        Node* newNode = new Node(srcCur->value);
        if(head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            cur->next = newNode;
        }
        cur = cur->next;
        srcCur = srcCur->next;
    }
    size = src.size;
}

void LinkedList::clear() {
    Node* delNode = nullptr;
    Node* startDel = head->next;
    while(startDel != head) {
        delNode = head;
        head = head->next;
        delete delNode;
    }
    head = nullptr;
    size = 0;
}

//TODO:
//Impliment so that it is circular
void LinkedList::push_back(int value) {
   Node* newNode = new Node(value);
   //Empty edge case
   if(head == nullptr) {
       head = newNode;
       newNode->next = newNode;
       return;
   } else {
       Node* cur = head;
       while(cur->next != head) {
           cur = cur->next;
       }
       cur->next = newNode;
       newNode->next = head;
   }
}

//////////////////////////////////////////////////////////////////////////////
//                         Decleration of all constructors                  //
//////////////////////////////////////////////////////////////////////////////
LinkedList::LinkedList(int value) :
    head(nullptr), size(0) {
        push_back(value);
    }

//////////////////////////////////////////////////////////////////////////////
//                          Decleration of the Big Three                    //
//////////////////////////////////////////////////////////////////////////////
LinkedList::LinkedList(const LinkedList& ll) {
    copy(ll);
}

LinkedList& LinkedList::operator=(const LinkedList& rhs) {
    if(this != &rhs) {
        clear();
        copy(rhs);
    }
    return *this;
}

LinkedList::~LinkedList() {
    clear();
}


//////////////////////////////////////////////////////////////////////////////
//                          Decleration of public functions                 //
//////////////////////////////////////////////////////////////////////////////
void LinkedList::print() {
    if(head == nullptr) {
        std::cout << "List empty" << std::endl;
        return;
    }
    Node* cur = head;
    while(cur->next != head) {
        std::cout << cur->value << "->";
        cur = cur->next;
    }
    std::cout << std::endl;
    return;
}

void LinkedList::orderedPushBack(int value) {
    Node* newNode = new Node(value);

    if(head == nullptr) {//Base case empty list
        head = newNode;
        head->next = newNode;
        return;
    } else if(value < head->value) { // Base Case value is less than head
        Node* cur = head;
        while(cur->next != head) { // Find the tail
            cur = cur->next;
        } // Make the new node the tail
        cur->next = newNode;
        newNode->next = head;
        head = newNode;
    } else {
        Node* cur = head;
        while(cur->next != head && cur->next->value < value) {
            cur = cur->next;
        }

        // If there was a spot found it would go there. Otherwise this would place at the end.
        newNode->next = cur->next;
        cur->next = newNode;
    }

}