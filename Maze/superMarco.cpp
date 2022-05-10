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
/*    argc = 0;
    argv = 0*/;
    //string mode;
    //indices in array [3-d vector], if index has '#', do not go, if it has, '.', go!
    cmdLine cmds{};
    string typeOfMode = "0";

    
     cmds.getMode(argc, argv);
    //mode = cmds.getModeVal();// goes with this function where mode is referring to 
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



     //if (cmds.getMap() == true) {
     //    obj.readInM();
     //}
     //else if (cmds.getList()== true){
     //    obj.readInL();
     //}
     //else {
     //    obj.readInM();
     //}

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

// could not run  leak-checking..?// check//Because it exited program
// output the castle room 0 comment?//will not need it ---check
// how  does the stack and queue work?//check// --stack goes from bottom --queue goes from front
