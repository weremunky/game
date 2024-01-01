/*
*
* Ian Angel
*
* 
*
* April 2022
*
*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include "Game.h"
using namespace std;

void menu(); //Function that outputs the header and lists the options to the user

void pushWord(Words &); //Function that pushes the word into the stack

void popWord(Words &); //Function that pops off the word from the stack

void capWords(Words &); //Function that capitalizes words in the stack

void displayStack(Words &); //Function that displays the current stack

void makeStory(Words &); //Function that inserts user's words into the story

void exitProgram(); //Function to exit the program


int main() 
{
    cout << "\nFill in the missing words into the story: \n";
    cout << "\nOne fine day I was walking along ______ and saw ______ eating an incredibly delicious looking ______. Seeing this, I involuntarily wanted the same thing and kindly asked to redeem this art of culinary for 6 ______. That's all I had. When I got home, my mother was shocked that I spent everything we had on it. However, she didn't grumble for long. After trying this miracle, she forgot about all the negative thoughts. We had a wonderful time together sharing and eating this ______. The lesson of this story is to ______ in your life.\n";
    
    Words wordGame;
    int option;
    
    while (option != 6)
    {
        menu();
        cin >> option; //User option input
        
	    switch(option) //Switch statement to create a menu loop
        {
            case 1:
                pushWord(wordGame);
                break;
            case 2:
                popWord(wordGame);
                break;
            case 3:
                capWords(wordGame);
                break;
            case 4:
                displayStack(wordGame);
                break;
            case 5:
                makeStory(wordGame);
                break;
            case 6:
                exitProgram();
                break;
                
        }
        
    }
    
}

void menu()
{
  cout << "\n*+* The Story Creator *+*\n\n" << "1. Push a word\n" << "2. Pop a word\n" << "3. Capitalize the words\n" << "4. Display the words\n"<< "5. Make a Story\n" << "6. Exit\n";

  cout << "\nChoose a menu option: ";
}

void pushWord(Words &wordGame) {
  
  string word;
  cout << "\nEnter a word you would like to add: ";
  cin >> word;
  cin.ignore();
 
  while (word.length() == 0 || word.length() > 10) //Checks if the length is more than 10 or equal to 0 letters
  {
    cout << "\nError: The word must be 1-10 characters long.\n";
    cout << "Enter your word: ";
    cin >> word;
    cin.ignore();
  }
  
  wordGame.pushWord(word); //Pushes the word into the stack
  cout << "\nWord has been added succesfully.\n";
}  

void popWord(Words &wordGame) 
{
  if(wordGame.sizeWord() == 0) //Checks if the stack has words
  {
    cout<<"\nYour word stack is empty.\n";
  }
 
  else
  {
    wordGame.popWord();
    cout << "\nThe word has been deleted succesfully.\n";
  }
  
}

void capWords(Words &wordGame) 
{
  if(wordGame.sizeWord() == 0) //Checks if the stack has words
  {
    cout<<"\nYour word stack is empty.\n";
  }
  
  else
  {
    wordGame.capWords();
    cout << "\nThe words has been capitalized succesfully.\n";
  }
}

void displayStack(Words &wordGame) 
{
    wordGame.displayStack();  
}

void makeStory(Words &wordGame)
{
  if(wordGame.sizeWord() >= 6) //Checks if the amount of words is at least 6
  {
    wordGame.makeStory();
  }
  
  else
  {
    cout<<"\nYou must have a minimum of 6 words in order to create the story.\n";  
  }
  
}

void exitProgram()
{
  cout << "\nThank you for using the Story Creator!\n";

  exit (0);
}
