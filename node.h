//
// Created by rodho on 2/11/2022.
//
#pragma once

class Node
{
private:
    int val;
    Node* next;
public:
    Node();
    Node(const int&);
    Node(const int&, Node*);
    void setItem(const int&);
    void setNext(Node*);
    int getValue() const;
    Node* getNext() const;

};

