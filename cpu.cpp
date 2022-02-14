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

const Node * Cpu::getStack() {
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
//            cout << "New Node created with value: " << linkedStack.push(val) << endl;
        }
        commandMap.push_back(make_pair(command, val));
        if (!linkedStack.isEmpty())
            cout << "The stack is not empty" << endl;
        maxIndex++;

    }
    setStack(linkedStack.getPointer());
    maxIndex--;
}

int Cpu::Run() {
    while (index <= maxIndex)
        Next();
    topStack = linkedStack.getTopPointer();
    return topStack->getValue();
}

int Cpu::Next() {
    if (index > maxIndex)
        return -1;
    string commandString = commandMap[index].first;
    int valueInt = commandMap[index].second;
//    cout << commandString << ": " << valueInt << endl;
    index++;

    if (commandString == "PSH")
        linkedStack.push(valueInt);

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
void Cpu::Print() {
    linkedStack.printList();
}

ostream& operator<<(ostream &os, Cpu cpu) {
    cpu.topStack = linkedStack.getTopPointer();
    os << "Value is " << cpu.topStack->getValue() << endl;
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
        push(1);
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

void LinkedList::printList() {
    LinkedList tempList;

    while (this->isEmpty() == false) {
        tempList.push(this->topPtr->getValue());
        this->pop();
    }
    while (tempList.isEmpty() == false) {
        int val = tempList.topPtr->getValue();
        cout << val << endl;
        tempList.pop();

        this->push(val);
    }
}

Node* LinkedList::getPointer() {
    return topPtr;
}