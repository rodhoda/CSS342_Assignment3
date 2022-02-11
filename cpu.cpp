//
// Created by rodho on 2/3/2022.
//
#include "cpu.h"
#include "node.h"

LinkedList::LinkedList() : topPtr(nullptr) {}

int LinkedList::push(const int& intVal) {
    Node* newNode = new Node(intVal, topPtr);
    topPtr = newNode;
    newNode = nullptr;
    return intVal;
}