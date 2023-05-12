#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#include <cctype>
#include <vector>


using namespace std;

class TaskManger{

private:
    string proccess;

public:

    TaskManger(){
        proccess = exec("tasklist");
    }
    string get_proccess(){
        return proccess;
    }
    void print(){
        cout << proccess << endl;
    }

    string exec(const char* cmd);


void sort_name(){
    
    for(int k = 0; k < proccess.size(); k++){
        for (int i = 155; i < proccess.length(); i += 77){
            if (toupper(proccess[i]) > toupper(proccess[i + 77])){
                for(int j = 0; j < 77; j++)
                {
                    swap(proccess[i+j], proccess[i + 77 +j]);
                    
                }
                
            }
            
        }
    }
}

void sort_pid(){
    vector<string> pids (proccess.length() / 77);
    int counter = 0;
            for (int i = 184; i < proccess.length(); i += 77){
                for (int j = 0; j < 5; j++)
                {
                    pids[counter] += proccess[i + j];
                }
                counter++;
            }
            sort(pids.begin(), pids.end());
            counter = 0;

        for (int i = 184; i < proccess.length(); i += 77){
            
                for (int j = 0; j < 5; j++)
                {
                    swap(proccess[i+j], pids[counter][j]);
                }
                
                counter++;

        }
}

void sort_mem(){
    vector<string> mems (proccess.length() / 77);
    int counter = 0;
            for (int i = 219; i < proccess.length(); i += 77){
                for (int j = 0; j < 7; j++)
                {
                    mems[counter] += proccess[i + j];
                }
                counter++;
            }
            sort(mems.begin(), mems.end());
            counter = 0;

        for (int i = 219; i < proccess.length(); i += 77){
            
                for (int j = 0; j < 7; j++)
                {
                    swap(proccess[i+j], mems[counter][j]);
                    
                }
                
                counter++;

        }
    }
};




int main(){

    TaskManger test;
    int choice;

    cout << "Hi user, this is a program that will show you the current running processes on your computer :)" << endl;
    cout << "The processes will be sorted by name, pid and memory usage." << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Show the processes" << endl;
    cout << "2. Sort the processes by name" << endl;
    cout << "3. Sort the processes by pid" << endl;
    cout << "4. Sort the processes by memory usage" << endl;
    cin >> choice;
    if (choice == 1){
        test.print();
    }
    else if (choice == 2){
        test.sort_name();
        test.print();
    }
    else if (choice == 3){
        test.sort_pid();
        test.print();
    }
    else if (choice == 4){
        test.sort_mem();
        test.print();
    }
    else{
        cout << "Invalid input" << endl;
    }

    return 0;
    

}



string TaskManger:: exec(const char* cmd) {
    char buffer[128];
    string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}