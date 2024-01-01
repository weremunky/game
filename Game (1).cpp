#include <iostream>
#include <cstring>
#include <cctype>
#include "Game.h"

Words::~Words() //Destructor
{
  stackNode *nodePtr = nullptr; //Pointer to the node
  stackNode *nextNode = nullptr; //Node to the next
  
  nodePtr = top; //Node pointer to the top of the stack

  while(nodePtr != nullptr) //Goes through list to delete nodes
    {
      nextNode = nodePtr->next;
      delete nodePtr;
      nodePtr = nextNode;
    }
}

Words::Words() //Constructor
{
  top = nullptr;
}


//Linked list functions

void Words::pushWord(string userWord)
{
  if(userWord.length() == 0 || userWord.length() > 10) //Checks if the length is more than 10 or equal to 0 letters
  {
    exit(EXIT_FAILURE);
  }
  
  stackNode *newNode = nullptr; //Pointer to the new node

  newNode = new stackNode; //Creates a new node in stack
  newNode->word = userWord;  //Stores the word into the stack node

  if(isEmpty()) //If the stack currently contains no elements
  {
    top = newNode;
    size = 1;
    newNode->next = nullptr;
  }
  
  else 
  {
    size++;
    newNode->next = top; //The new stack node becomes the new top node
    top = newNode;
  }
}

void Words::popWord()
{
  stackNode *temp = nullptr;

  if(isEmpty()) //If the stack currently contains no elements
  {
    exit(EXIT_FAILURE);
  }
  
  else
  {
    userWord = top->word;  
    temp = top->next;
    delete top;
    size--;
    top = temp;
  }
}

void Words::capWords()
{
  stackNode *temp;
  temp = top;
  
  if(!temp)
  {
    exit(EXIT_FAILURE);
  }
  
  while(temp != nullptr) //Goes through each character of the string and capitalizes it 
    {
      if(temp->word.length() == 0 || temp->word.length() > 10) //Checks if the length is more than 10 or equal to 0 letters
      {
        exit(EXIT_FAILURE);
      }
      
      for(int i = 0; i < temp->word.length(); i++) //For loop for the capitalization
        {
          temp->word[i] = toupper(temp->word[i]);
        }
        
      temp = temp->next;
      
    }
  
}

void Words::displayStack()
{
    stackNode *display;
    display = new stackNode;
    display = top;

    if(display == nullptr) //Checks if there are words present in the stack
    {
      cout<<"\nThere are currently no words present. Please try again.\n";
      
    }
    
    else
    {
      cout<<"\nWords:\n\n";
      
      while(display != nullptr) //Runs until reaching the end of the stack and displays the words held
        {
            cout << display->word << endl;
            display = display->next;
        }
    }
    
}

void Words::makeStory()
{
  if(size >= 6) //if the size of the word amount held is at least 6
  {
    cout << userWord << "One fine day I was walking along ";
    popWord();
    
    cout << userWord << " and saw ";
    popWord();
    
    cout << userWord << " eating an incredibly delicious looking ";
    popWord();
    
    cout << userWord << ". Seeing this, I involuntarily wanted the same thing and kindly asked to redeem the art of culinary for 6 ";
    popWord();
    
    cout << userWord << ". That's all I had. When I got home, my mother was shocked that I spent everything we had on it. However, she didn't grumble for long.After trying this miracle, she forgot about all the negative thoughts. We had a wonderful time together sharing and eating this ";
    popWord();
    
    cout << userWord << ". The lesson of this story is to ";
    popWord();
    
    cout << userWord << " in your life.\n";
  }
}
  
bool Words::isEmpty()const
{
  bool empty;

  if(!top) //"if" loop for checking if the current stack is either empty or full 
  {
    empty = true;
  }
  else
  {
    empty = false;
  }
  return empty;
}

int Words::sizeWord()
{
  return size;
}