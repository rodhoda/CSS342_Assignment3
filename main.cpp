#include <iostream>
#include "cpu.h"
using namespace std;

int main() {

    Cpu myCpu;
    string file1 = R"(C:\Users\rodho\CLionProjects\Assignment3\Prog1.asm)";
    string file2 = R"(C:\Users\rodho\CLionProjects\Assignment3\Prog2.asm)";
    myCpu.LoadProgram(file1);
//    myCpu.Print();

//    cout << myCpu << endl;
//    cout << myCpu.Run() << endl;
//    cout << endl;
////    myCpu.Print();
//    myCpu.LoadProgram(file1);
    while(myCpu.Next() == 0)
        cout << myCpu << endl;

    cout << "\nEnd of file 1\n" << endl;

//    myCpu.LoadProgram(file2);
//    cout << myCpu.Run() << endl;
    myCpu.LoadProgram(file2);
    while (myCpu.Next() == 0) {
        cout << myCpu << endl;
    }
    cout << endl;
    return 0;

}
