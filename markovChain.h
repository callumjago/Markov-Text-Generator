#ifndef MARKOV_CHAIN
#define MARKOV_CHAIN

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <locale>
#include <string>

using namespace std;

struct word {
	vector<string> c;
	string word;
	int numOfElements;
};

class markovChain {
private:
	string text;
	vector<string> words;
	vector<word> chain;
public:
	markovChain();
	void addSource(string src, int mode);
	void constructChain();
	void processTextWords();
	void processTextChars();
	void addWord(string word);
	string getNext(string word);
	void printWords();
	void printChain();
	void generateText(int length, int mode);
	void letterAnalysis(string a);
};







#endif