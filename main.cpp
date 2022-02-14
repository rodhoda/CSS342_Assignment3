#include <iostream>
#include "cpu.h"
using namespace std;

int main() {

    Cpu myCpu;
    string file = R"(C:\Users\rodho\CLionProjects\Assignment3\Prog1.asm)";
    myCpu.LoadProgram(file);
//    myCpu.Print();

//    cout << myCpu << endl;
    cout << myCpu.Run() << endl;
//    myCpu.Print();
    myCpu.LoadProgram(file);
    while(myCpu.Next() == 0)
        cout << myCpu << endl;

}
