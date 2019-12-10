#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList ll = LinkedList(1);
    ll.push_back(2);
    ll.push_back(3);
    //ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    cout << "Current List: " << endl;
    ll.print();
    cout << "Pushing back the 4 in order." << endl;
    ll.orderedPushBack(4);
    ll.print();
    cout << "Execution finished with no errors." << endl;
    exit(0);
}