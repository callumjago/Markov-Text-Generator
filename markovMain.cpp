#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include "markovChain.cpp"

using namespace std;

int main(int argc, char* argv[]) {
	string str = "";
	string tempStr = "";
	string fileName = "";
	//cin >> noskipws;
	/*
	while(getline(cin, tempStr)) {
		//getline(cin, str);
		str += tempStr;
		//str += '\n';
	}*/
	
	fileName += argv[1];
	string in = "";
	string line = "";
	
	ifstream file(fileName.c_str());
	
	if (file.is_open()) {//Reads in key from specified file
    	while(getline(file, line)) {
      		in.append(line+"\n");
    	}
    	file.close();
    }
    //cout << in << endl;
    markovChain *m = new markovChain();
    m->addSource(in, 0);
    m->constructChain();
    //cout << m->getNext("hi");
    //m->printChain();
    
    for(int i = 0; i < 20; i++) {    
    	m->generateText(200, 0);
    	cout << endl << endl;
    }
	
    //m->letterAnalysis("e");
	return 0;
}