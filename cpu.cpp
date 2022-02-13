//
// Created by rodho on 2/3/2022.
//
#include "cpu.h"
#include "node.h"
#include <fstream>
#include <sstream>

Cpu::Cpu() {};

LinkedList linkedStack;

void Cpu::LoadProgram(string fileName) {
    index = 0;
    maxIndex = 0;
    ifstream file(fileName);
    string line;
    string command;
    int val;
    int num;

    while (!file.eof()){
        getline(file, line);
        int secIndex = line.find(' ');
        command = line.substr(0, secIndex);
//        cout << command << endl;

        if (linkedStack.isEmpty())
            cout << "The stack is empty" << endl;


        if (command == "PSH") {
            string numValue;
            numValue = line.substr(secIndex, line.length());

            stringstream convert(numValue);
            convert >> val;
            cout << "New Node created with value: " << linkedStack.push(val) << endl;
        }
        else if (command == "ADD") {
            linkedStack.add();
        }
        else if (command == "SUB") {
            linkedStack.sub();
        }
        else if (command == "MULT") {
            linkedStack.mult();
        }
        else if (command == "DIV") {
            linkedStack.div();
        }
        else if (command == "CMP") {
            linkedStack.cmp();
        }
        else if (!linkedStack.isEmpty())
            cout << "The stack is not empty" << endl;
        commandMap.push_back(make_pair(command, val));
        maxIndex++;

    }
    maxIndex--;
    cout << "Value that was popped: " << linkedStack.pop() << endl;
}

int Cpu::Run() {

    while (index <= maxIndex)
        Next();
    return 0;
}

int Cpu::Next() {
    if (index > maxIndex)
        return -1;
    string commandString = commandMap[index].first;
    int valueInt = commandMap[index].second;
    cout << commandString << ": " << valueInt << endl;
    index++;
    return 0;

};

LinkedList::LinkedList() : topPtr(nullptr) {}

int LinkedList::push(const int& intVal) {
    Node* newNode = new Node(intVal, topPtr);
    topPtr = newNode;
    newNode = nullptr;
    return intVal;
}

int LinkedList::pop() {
    Node* deleteNode = topPtr;
    int val = deleteNode->getValue();
    topPtr = topPtr->getNext();
    delete deleteNode;
    return val;
}

int LinkedList::add() {
    return 0;
}

int LinkedList::sub() {
    return 0;
}

int LinkedList::mult() {
    return 0;
}

int LinkedList::div() {
    return 0;
}

int LinkedList::cmp() {
    return 0;
}

bool LinkedList::isEmpty() {
    if (!topPtr)
        return true;
    else
        return false;
}