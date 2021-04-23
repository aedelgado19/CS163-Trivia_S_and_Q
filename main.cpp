#include <iostream>
#include "stack.h"
#include "queue.h"
#include <cstring>
using namespace std;

void print_error_messages(int success, const char function_name[]);

int main(){

  int success = 0;
  stack* used_stack = new stack();
  stack* correct_stack = new stack();
  queue* new_queue = new queue();
  char input[20];
  char question[40];
  char answer[40];
  cout << " " << endl;
  cout << "********************************************* " << endl;
  cout << "Welcome to Trivia: stack and queue edition" << endl;
  cout << "Type 'help' to see possible commands." << endl;

  while(strcmp(input, "q") != 0){
    cout << "> ";
    cin.get(input, 20);
    cin.get();

    //change input to lowercase
    for(int i = 0; i < (int) strlen(input); i++){
      input[i] = tolower(input[i]);
    }

    if(strcmp(input, "help") == 0){
      cout << "Commands are: " << endl;
      cout << "'add' - add a trivia question" << endl; //queue
      cout << "'draw' - choose a trivia question" << endl; //queue
      cout << "'du' - display used questions" << endl; //used stack
      cout << "'dc' - display correctly answered questions" << endl; //correct stack
      cout << "'dq' - display playable questions" << endl; // queue
      cout << " " << endl;
      cout << "specifically for submission 1: " << endl;
      cout << "'push' - push a question to the stack" << endl;
      cout << "(and use 'du' to display since we are pretending " << endl;
      cout << "to be moving items from the queue to the used stack) " << endl;
    }
    
    if(strcmp(input, "push") == 0){ //stack testing function
      cout << " " << endl;
      cout << "This is a testing site for the push function. " << endl;
      cout << "Pretend this is a used question being added to the stack" << endl;
      cout << "Enter the question: " << endl;
      cout << "> ";
      cin.get(question, 40);
      cin.get();
      cout << "Enter the answer: " << endl;
      cout << "> ";
      cin.get(answer, 40);
      cin.get();
      success = used_stack->push(question, answer);
      print_error_messages(success, "push");
    }
    
    if(strcmp(input, "add") == 0){ //queue

    }
    
    if(strcmp(input, "draw") == 0){ //queue
      
    }

    if(strcmp(input, "du") == 0){ //used stack
      success = used_stack->display();
      print_error_messages(success, "display");
    }

    if(strcmp(input, "dc") == 0){ //correct stack

    }

    if(strcmp(input, "dq") == 0){ //queue

    }
  }
  cout << "Goodbye!" << endl;
  return 0;
}

void print_error_messages(int success, const char function_name[]){
  if(success == 1){ //success!
    if(strcmp(function_name, "push") == 0){
      cout << "Pushed successfully." << endl;
      cout << " " << endl;
    }
    return;
  } else { //failure
    cout << "Error in function: " << function_name << endl;
  }
  
}
