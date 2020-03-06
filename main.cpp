#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "Header.h"
using namespace std;
const int LINES = 10;
string currentLine[100];
string stateFile[100][100];
string current_tape;
vector <int> tape{-3,1,4,2,5};//This is Tape
int current_square=0;
int current=1;
int mark=true;



void read_stateFile(string FILE){
ifstream inputFile;
inputFile.open(FILE);
for (int line = 0; line < LINES; line++)
{getline(inputFile,currentLine[line]);int n=0;
for (int i=0;i<currentLine[line].size();i++)
{if (currentLine[line][i] == ':'){n++;}
else if(currentLine[line][i] != ',')
{stateFile[line+1][n]=stateFile[line+1][n]+currentLine[line][i];}}n++;}}



int read_tape(int num){
    for (int n=0; n<tape.size(); n++) {
        if (tape[n]== num){return true;}
    }
    return false;}
int chartoint(char a){
    int ia = (int)a;
    /* note that the int cast is not necessary -- int ia = a would suffice */
    return ia-48;
}


void printMachineInfo() {
 sort(tape.begin(), tape.end(), less<int>());
 cout << "Tape:[" ;
 int nums = tape.size();
 for (int i = 0; i < nums; i++) {
     if (i != nums - 1) {cout << tape[i] << "," ;}
     else {cout << tape[i]<<"]"<<endl;}}cout << "Current Square:" << current_square << endl;}

void removetape(int k){
    for(vector<int>::iterator iter= tape.begin();iter!=tape.end();iter++){
         if(*iter==k){tape.erase(iter);break;}}}





    void update(){
    if (read_tape(current_square)){
        if (stateFile[current][1][0]=='0'){removetape(current_square);}
        if  (stateFile[current][1][1]=='L'){current_square--;}
        if  (stateFile[current][1][1]=='R'){current_square++;}
        current = chartoint(stateFile[current][1][2]);}
    else {
        if(stateFile[current][0][0]=='1'){tape.push_back(current_square);}
        if(stateFile[current][0][1]=='L'){current_square--;}
        if(stateFile[current][0][1]=='R'){current_square++;}
        current = chartoint(stateFile[current][0][2]);}
    if (current==0){mark=false;}}
    void run(){while (mark) {update();}}


int main()
{
    printMachineInfo();
    read_stateFile("File");
    run();
    printMachineInfo();
}

