#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Words //Words class declaration
{
private:
  struct stackNode //Declares a node
  {
    string word;
    stackNode *next; //Pointer to the next element
  };

  stackNode *top; //Pointer to the top of the stack
  
public:
    
    string userWord;
    int size = 0;
    
    ~Words(); //Destructor
    Words(); //Constructor
    
    //Linked list operations
    void pushWord(string);
    void popWord();
    void capWords();
    void displayStack();
    void makeStory();
    bool isEmpty() const;
    int sizeWord();
};

#endif