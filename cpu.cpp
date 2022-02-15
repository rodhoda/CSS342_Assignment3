//
// Created by rodho on 2/3/2022.
//
#include "cpu.h"
#include "node.h"
#include <fstream>
#include <sstream>

Cpu::Cpu() {};

LinkedList linkedStack;

void Cpu::setStack(Node* stackedList) {
    topStack = stackedList;
}

Node * Cpu::getStack() {
    return topStack;
}

void Cpu::LoadProgram(string fileName) {
    index = 0;
    maxIndex = 0;
    ifstream file(fileName);
    string line;
    string command;
    int val;
    int num;

    if (!linkedStack.isEmpty() || !commandMap.empty()) {
        linkedStack.clear();
        commandMap.clear();
    }

    while (!file.eof()){
        getline(file, line);
        int secIndex = line.find(' ');
        command = line.substr(0, secIndex);
//        cout << command << endl;

        if (command == "PSH") {
            string numValue;
            numValue = line.substr(secIndex, line.length());

            stringstream convert(numValue);
            convert >> val;
//            cout << "New Node created with value: " << linkedStack.push(val) << endl;
        }
        commandMap.emplace_back(command, val);

        maxIndex++;

    }

    maxIndex--;
}

int Cpu::Run() {
    while (index <= maxIndex)
        Next();
    topStack = linkedStack.getTopPointer();
    if (topStack->getNext() != nullptr)
        cerr << "There is more than one value left in the stack" << endl;
    return topStack->getValue();
}

int Cpu::Next() {
    if (index > maxIndex)
        return -1;
    string commandString = commandMap[index].first;
    int valueInt = commandMap[index].second;
//    cout << commandString << ": " << valueInt << endl;
    index++;

    if (commandString == "PSH") {
        linkedStack.push(valueInt);
        setStack(linkedStack.getPointer());
    }

    else if (commandString == "ADD") {
        linkedStack.add();
    }
    else if (commandString == "SUB") {
        linkedStack.sub();
    }
    else if (commandString == "MULT") {
        linkedStack.mult();
    }
    else if (commandString == "DIV") {
        linkedStack.div();
    }
    else if (commandString == "CMP") {
        linkedStack.cmp();
    }
    return 0;
}

ostream& operator<<(ostream &os, Cpu cpu) {
    cpu.topStack = linkedStack.getTopPointer();
    for (int i = 0; i <= cpu.maxIndex; i++) {
        os << "Value is " << cpu.topStack->getValue() << endl;
        cpu.topStack = cpu.topStack->getNext();
        if (cpu.topStack == nullptr)
            break;
    }
    return os;
}

LinkedList::LinkedList() : topPtr(nullptr) {}

Node* LinkedList::getTopPointer() {
    return topPtr;
}

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
    int firstValue = pop();
    int secondValue = pop();
    int newValue = firstValue + secondValue;
    push(newValue);
}

int LinkedList::sub() {
    int firstValue = pop();
    int secondValue = pop();
    int newValue = secondValue - firstValue;
    push(newValue);
}

int LinkedList::mult() {
    int firstValue = pop();
    int secondValue = pop();
    int newValue = firstValue * secondValue;
    push(newValue);
}

int LinkedList::div() {
    int firstValue = pop();
    int secondValue = pop();
    if (firstValue == 0)
        cerr << "Cannot divide with Zero." << endl;
    int newValue = secondValue / firstValue;
    push(newValue);
}

int LinkedList::cmp() {
    int firstValue = pop();
    int secondValue = pop();
    if (firstValue > secondValue)
        push(5);
    else if (firstValue < secondValue)
        push(-1);
    else
        push(0);
}

bool LinkedList::isEmpty() {
    if (!topPtr)
        return true;
    else
        return false;
}



Node* LinkedList::getPointer() {
    return topPtr;
}

void LinkedList::clear() {
    topPtr = nullptr;
}