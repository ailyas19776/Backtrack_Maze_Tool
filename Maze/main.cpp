#include <iostream>
#include "getopt.h"
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include "stackQueue.h" 
using namespace std;
int main(int argc, char *argv[] ) {
    ios_base::sync_with_stdio(false);
    stackOrQueue obj{};

    cmdLine cmds{};
    string typeOfMode = "0";

    
    cmds.getMode(argc, argv);
    cin >> typeOfMode;

     if (typeOfMode == "M") {
         obj.readInM();
     }
     else if (typeOfMode == "L") {
         obj.readInL();
     }
     else {
         obj.readInM();
     }

     if (cmds.getStack() == true) {//stack method for spec-M.txt
         obj.stackQueues(cmds);
     }
     else if (cmds.getQueue() == true) {
         obj.stackQueues(cmds);
     }
     else {
         cout << "You must specify a stack or a queue" << "\n";
         return 0;
     }

     obj.printValues(cmds);

     return 0;
}


