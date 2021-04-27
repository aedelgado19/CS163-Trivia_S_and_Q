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
  
  while(strcmp(input, "q") != 0){
    cout << "---------------------------------------------------" << endl;
    cout << "Stack commands so far: " << endl;
    cout << "   push - push a new trivia question" << endl;
    cout << "   ds - display stack" << endl;
    cout << "   pop - pop a question off the top of the stack" << endl; 

    cout << " " << endl;
    cout << "Queue commands so far: " << endl;
    cout << "   eq - enqueue a trivia question to the rear of the queue" << endl; 
    cout << "   dq - display the queue" << endl;
    cout << "> ";
    cin.get(input, 20);
    cin.get();
    cout << "---------------------------------------------------" << endl;
    
    //change input to lowercase
    for(int i = 0; i < (int) strlen(input); i++){
      input[i] = tolower(input[i]);
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

    if(strcmp(input, "ds") == 0){ 
      success = used_stack->display();
      print_error_messages(success, "display");
    }

    if(strcmp(input, "pop") == 0){ //stack
      success = used_stack->pop();
      print_error_messages(success, "pop");
    }

    if(strcmp(input, "eq") == 0){ //queue
      cout << "Enter the question: " << endl;
      cout << "> ";
      cin.get(question, 40);
      cin.get();
      cout << "Enter the answer: " << endl;
      cout << "> ";
      cin.get(answer, 40);
      cin.get();
      success = new_queue->enqueue(question, answer);
      print_error_messages(success, "eq");
    }
    if(strcmp(input, "dq") == 0){ //queue
      success = new_queue->display();
      print_error_messages(success, "d");
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
    if(strcmp(function_name, "pop") == 0){
      cout << "Popped successfully." << endl;
      cout << " " << endl;
    }
    if(strcmp(function_name, "eq") == 0){
      cout << "Enqueued successfully." << endl;
      cout << " " << endl;
    }
    return;
  } else if (success == -1){ //list is null
    if(strcmp(function_name, "d") == 0){
      cout << "Nothing to display." << endl;
      cout << " " << endl;
      return;
    }
    if(strcmp(function_name, "display") == 0){
      cout << "Nothing to display." << endl;
      cout << " " << endl;
      return;
    }
    if(strcmp(function_name, "pop") == 0){
      cout << "Nothing to pop." << endl;
      cout << " " << endl;
    }
  } else { //return a 0 (failure)
    cout << "Error in function: " << function_name << endl;
  }
}
