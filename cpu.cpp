//
// Created by rodho on 2/3/2022.
//
#include "cpu.h"
#include "node.h"
#include <fstream>
#include <sstream>

Cpu::Cpu() {};

LinkedList stackedList;
void Cpu::LoadProgram(string fileName) {
    LinkedList linkedStack;
    ifstream file(fileName);
    string line;
    string command;
    int num;

    while (!file.eof()){
        getline(file, line);
        int secIndex = line.find(' ');
        command = line.substr(0, secIndex);
//        cout << command << endl;

        if (command == "PSH") {
            string numValue;
            int val;
            numValue = line.substr(secIndex, line.length());

            stringstream convert(numValue);
            convert >> val;

            cout << "New Node created with value: " <<linkedStack.push(val) << endl;
        }

    }
}


LinkedList::LinkedList() : topPtr(nullptr) {}

int LinkedList::push(const int& intVal) {
    Node* newNode = new Node(intVal, topPtr);
    topPtr = newNode;
    newNode = nullptr;
    return intVal;
}