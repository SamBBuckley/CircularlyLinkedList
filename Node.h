#ifndef NODE_H
#define NODE_H

//////////////////////////////////////////////////////////////////////////////
//                      Decleration of a simple Node holding an int         //
//                  Could be abstracted for any data type using typing      //
//////////////////////////////////////////////////////////////////////////////

struct Node {
    int value;
    Node* next;
    
    Node(int value) :
     value(value), next(nullptr) {}
};

//////////////////////////////////////////////////////////////////////////////
//                       helper function declarations                       //
//////////////////////////////////////////////////////////////////////////////
 bool operator==(const Node& rhs, const Node& lhs);
 bool operator!=(const Node& rhs, const Node& lhs);
 bool operator<(const Node& rhs, const Node& lhs);
 bool operator<=(const Node& rhs, const Node& lhs);
 bool operator>(const Node& rhs, const Node& lhs);
 bool operator>=(const Node& rhs, const Node& lhs);

 #endif