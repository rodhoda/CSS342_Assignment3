//
// Created by rodho on 2/3/2022.
//
#pragma once
#include "node.h"
#include <list>
using namespace std;
#include <string>
#include <iostream>
#include <vector>

#ifndef ASSIGNMENT3_CPU_H
#define ASSIGNMENT3_CPU_H


class Cpu {
private:
    vector<pair<string, int>> commandMap;
    int index;
    int maxIndex;
public:
    Node* topStack;
    Cpu();

    void setStack(Node*);
    Node * getStack();

    // Takes a .csm filename as a parameter
    // Ensures the stack is empty and previous program is removed
    void LoadProgram(string);

    // Runs the program parsed from the .csm file
    // Returns the final value that's left in the stack
    // If there is more than one value left, throw error

    // Essentially calls run for the length of programs in the file
    int Run();

    // Runs the next program line and returns 0.
    //If there are no more lines, return -1.
    int Next();

    friend ostream& operator<<(ostream& os, Cpu);
};

class LinkedList {
private:
    int num;
    Node* topPtr;


public:
    LinkedList();
    LinkedList(const LinkedList&);

    Node* getTopPointer();

    int push(const int&);
    int pop();
    int add();
    int sub();
    int mult();
    int div();
    int cmp();
    bool isEmpty();
    void printList();
    Node* getPointer();
    void clear();
};

#endif //ASSIGNMENT3_CPU_H
