//B99292359FFD910ED13A7E6C7F9705B8742F0D79
#pragma once
#ifndef stackQueue
#define stackQueue

#include <queue>
#include <stack>
#include <string>
#include <vector>
<<<<<<< HEAD
#include "getopt.h""
=======
#include "getopt.h"
>>>>>>> origin/main
#include <deque>
using namespace std;

class cmdLine {
protected:
    string mode;
    bool queue;
    bool stack;
    bool map;
    bool list;
public:
    bool getQueue() {
        return queue;
    }
    bool getStack() {
        return stack;
    }
    bool getList() {
        return list;
    }
    bool getMap() {
        return map;
    }
  /*  string getModeVal() {
        return mode;
    }*/
    void printHelp(char* argv[]) {
        cout << "Usage: " << argv[0] << " [-m queue|stack]|-h" << endl;
        cout << "This program is to help you learn command-line processing," << endl;
        cout << "reading data into a vector, the difference between stack and queue," << endl;
        cout << "and how to properly read until end-of-file." << endl;
    } // printHelp()


    //optarg => 
    void getMode(int argc, char* argv[]) {//function is void
//        bool modeSpecified = false;
        // These are used with getopt_long()

        opterr = false; // Let us handle all error output for command line options
        int choice;
        int option_index = 0;
        option long_options[] = {
            //  Fill in two lines, for the "mode" ('m') and
            // the "help" ('h') options.
            // ./project0 -m -nosize
            // ./project0 --help
            {"output", required_argument, nullptr, 'o'},
            {"queue", no_argument,        nullptr, 'q'},
            {"stack", no_argument,        nullptr, 's'},
            //required_arugment, = followed by another word 
            // nullptr refers to getopt feature 
            //./project1 --output 
            {"help", no_argument,        nullptr, 'h'},
            { nullptr, 0,             nullptr, '\0' }
        };


        //stackOrQueue obj;
        uint32_t count = 0;
        //  Fill in the double quotes, to match the mode and help options.
        while ((choice = getopt_long(argc, argv, "o:qsh", long_options, &option_index)) != -1) { // colon means required argument
            switch (choice) {
            case 'h':
                printHelp(argv);
                exit(1);
            case 'q':
                queue = true;
                count++;
                if (count == 2) {
                    cout << "Stack or queue can only be specified once" << "\n";
                    exit(1);
                }
                break;
            case 's':
                stack = true;
                count++;
                if (count == 2) {
                    cout << "Stack or queue can only be specified once" << "\n";
                    exit(1);
                }
                break;
            case 'o':
                mode = string(optarg);//optarg, in a class.
                if (mode != "L" && mode != "M") {
                    cout << "Unknown command line option" << endl;
                    exit(1);
                }
                else if (mode == "L") {
                    list = true;
                }
                else if (mode == "M") {
                    map = true;
                }
                //                modeSpecified = true;
                break;

            default:
                map = true;
            } // switch
        } // while

        if (!queue && !stack) {
            cout << "Stack or queue must be specified" << endl;
            exit(1);
        } // if
        

    } // getMode()

};




class Tile {
public:
    char value = '.';
    char direction;
    bool visited;
    uint32_t prevRoom;
};

class Location {
public:
    uint32_t room, row, column;
    char value = '.';
  //  char direction;

};

class stackOrQueue {
private:

    uint32_t numTilesDiscovered;
    uint32_t startRow ;
    uint32_t startColumn;
    uint32_t startRoom;
    //vector<uint32_t> coordinates;
    stack<Location> coords;
    uint32_t n;
    uint32_t numOfRooms;



    uint32_t endRow;
    uint32_t endColumn;
    uint32_t endRoom;
    vector <vector<vector<Tile>>> threeD;//multiple tables
    ///   room/row/column
    //threeD[1][2][3].a;
    deque<Location> d1;
    //uint currentRoomforstackQueues;
    //breadth first search?///<--not doing this, right?
    //deque, will do the breadth first search because it can do back and front insertion/pop
    bool foundPath;
    cmdLine cmdLineObj;
public:
    stackOrQueue():  numTilesDiscovered(0), startRow(0),startColumn(0), 
        startRoom(0), n(0), numOfRooms(0), endRow(0), 
    endColumn(0), endRoom(0), foundPath(false),cmdLineObj(){}
    //bool backTracing(Location&);
    //void list();
    void readInL();
    void readInM();
    bool setValues(char o);
    void stackQueues(cmdLine&);

    void backtracing(Location&);
    void printValues(cmdLine&);

};

#endif // !stackQueue.h