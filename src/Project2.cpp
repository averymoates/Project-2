//============================================================================
// Name        : Project2.cpp
// Author      : Avery Moates
// Version     :	0.0.1
// Description : Project 2 Data Structure
//============================================================================

#include <iostream>
using namespace std;

class myString;

class myString{
	friend ostream& operator <<(ostream& s, myString& A);

protected:
	char* strArray;
	int size;
	void strCpy (char* A, char* B, int n);
public:
	myString();
	myString(char* inpStr);
	myString(myString& B);
	int Size();

	bool operator == (myString& B);
	bool operator > (myString& B);
	bool operator < (myString& B);
	myString& operator = (myString& B);
	myString& operator = (char* B);

};

class bagOfWords{
private:
	int binarySearchAndInsert(myString& W);
protected:
	myString* _words;
	int* _frequencies;
	int _size;
public:
	bagOfWords();
	void addWord(myString& W); //Insert word w into the array _words - keep it sorted alphabetically
	void sortFreq(); //Sort words array based on frequency
	void sortWords(); //Sort words array alphabetically
	void display(); //Print word followed by a colon followed by a single space and frequency
	bagOfWords* removeStopWords(myString* stopWords); //Remove all the words in the array
	~bagOfWords();
};

int main(){

	int numStopWords;
	char* token;
	myString* tokenString;

	//Read the first number from the file that contains the number of stop words

	cin >> numStopWords;
	myString* stopWordsList = new myString[numStopWords];

	//Read the stop words
	for(int i=0; i<numStopWords; ++i){
		token = getNextToken();
		stopWordsList[i] = token; //Calls the overloaded = operator on myString class

	}

	//Now read a text and out them in the bagOfWords instance
	bagOfWords* myBag = new bagOfWords();
	token = getNextToken(); //First read the token as an array of characters
	tokenString = new myString(token); //Create a myString object with the token
	while(token != NULL){
		(*myBag).addWord(*tokenString); //Add token to myBag
		token = getNextToken();
	}

	//This should display the token and frequency
	//note that because you are using binary search and insert the tokens will be sorted alphabetically
	(*myBag).display();

	(*myBag).sortFreq();
	(*myBag).display();
	(*myBag).sortWords();
	(*myBag).display();
	bagOfWords* newBag = (*myBag).removeStopWords(stopWordsList);
	(*myBag).display();
	(*myBag).sortFreq();
	(*myBag).display();

	delete stopWordsList;
	delete myBag;
	delete newBag;

	return 0;
}
