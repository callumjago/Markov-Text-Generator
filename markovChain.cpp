#include "markovChain.h"

using namespace std;

markovChain::markovChain() {
	srand(time(NULL));
}


//Takes in text used as source for constructing markov chain
//mode0 = full words, mode1 = characters
void markovChain::addSource(string src, int mode) {
	text = src;
	if(mode == 0) {//Treat individual words as states
		processTextWords();
		return;
	}
	else if(mode == 1) {//Treat individual letters as states
		processTextChars();
		return;
	}
	else {
		cout << "Invalid mode" << endl;
	}
}

//Separates source text into individual words and adds each word to words vector
void markovChain::processTextWords() {
	int pos = 0;
	string word = "";
	for(int i = 1; i < text.length(); i++) {
		if(text.at(i) == ' ' || text.at(i) == '\n') {
			word = text.substr(pos, i-pos);
			pos = i+1;
			addWord(word);
			
		}
	}
}

//Separate text into individual letters
void markovChain::processTextChars() {
	for(int i = 0; i < text.length(); i++) {
		addWord(text.substr(i, 1));
	}
}

//Construct markov chain from processed text
void markovChain::constructChain() {
	bool duplicate = false;
	
	//Add each word to chain ignoring duplicates
	for(int i = 0; i < words.size(); i++) {
		for(int j = 0; j < chain.size(); j++) {
			if(chain[j].word == words[i]) {
				duplicate = true;
				if(i == words.size()-1) {chain[j].c.push_back("");}
				else {chain[j].c.push_back(words[i+1]);}
				chain[j].numOfElements++;
				break;
			}
		}
		if(duplicate) {
			duplicate = false;
			continue;
		}
		word newWord;
		newWord.word = words[i];
		if(i == words.size()-1) {newWord.c.push_back("");}
		else {newWord.c.push_back(words[i+1]);}
		newWord.numOfElements = 1;
		chain.push_back(newWord);

	}

	//For each word, add following word to its chain
	
}

//adds string to words vector
void markovChain::addWord(string word) {
	locale loc;
	string newWord = "";
	for (string::size_type i=0; i<word.length(); ++i) {
    	newWord += tolower(word[i],loc);
	}
	words.push_back(newWord);
}

void markovChain::printWords() {
	for(int i = 0; i < words.size(); i++) {
		cout << words[i] << endl;
	}
}

void markovChain::printChain() {
	for(int i = 0; i < chain.size(); i++) {
		cout << chain[i].word << endl;
		cout << "c: " << chain[i].c[0] << endl;
	}
}

//Generates new word based on previous
string markovChain::getNext(string word) {
	int r = 0;

	for(int i = 0; i < chain.size(); i++) {
		if(chain[i].word == word) {
			
			r = rand()%chain[i].numOfElements;
			
			return chain[i].c[r];
		}
	}
	
	return "";
}


//mode0 = full words, mode1 = characters
void markovChain::generateText(int length, int mode) {
	string firstWord = chain[rand()%chain.size()].word;
	string word = getNext(firstWord);
	string res = word;
	cout << firstWord << " ";
	if(mode == 0) {
		for(int i = 0; i < length; i++) {
			word = getNext(word);
			res.append(" " + word);
		}
		cout << res;
		return;
	}
	if(mode == 1) {
		for(int i = 0; i < length; i++) {
			word = getNext(word);
			res.append(word);
		}
		cout << res;
		return;
	}
	else {
		cout << "Invalid mode" << endl;
		return;
	}
	cout << res;
	return;
}

//Calculates occurences of each state
void markovChain::letterAnalysis(string a) {
	int pos = -1;
	
	for(int i = 0; i < chain.size(); i++) {
		if(chain[i].word == a) {
			pos = i;
		}
	}
	int size = 0;
	for(int i = 0; i < chain[pos].c.size(); i++) {
		if(*chain[pos].c[i].c_str() >= 'a' && *chain[pos].c[i].c_str() <= 'z') {
			size++;
		}
	}
	cout << "Analyzing letter " << a << endl;
	cout << "Number of occurences: " << size << endl;
	if(pos == -1) {
		cout << "char not found" << endl;
		return;
	}

	
	int count = 0;
	for(char i = 97; i <= 122; i++) {
		for(int j = 0; j < chain[pos].c.size(); j++) {
			if(*chain[pos].c[j].c_str() == i) {
				count++;
			}
		}
		cout << i << ": " << (float)count/(float)size << endl;
		count = 0;
	}
	return;

}