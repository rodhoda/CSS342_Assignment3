//
// Created by rodho on 2/11/2022.
//
#include "node.h"

Node::Node() : next(nullptr) {}

Node::Node(const int& aValue) : val(aValue), next(nullptr) {}

Node::Node(const int& aValue, Node* nextNodePointer) : val(aValue), next(nextNodePointer) {}

void Node::setItem(const int& aValue) {
    val = aValue;
}

void Node::setNext(Node* nextPtr) {
    next = nextPtr;
}

int Node::getValue() const {
    return val;
}

Node* Node::getNext() const {
    return next;
}