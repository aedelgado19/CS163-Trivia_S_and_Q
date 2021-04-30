#include <iostream>
#include "stack.h"
#include "queue.h"
#include <cstring>
using namespace std;

void print_error_messages(int success, const char function_name[]);
void print_success(bool b_success);

int main(){

  int success = 0; // stores success for int return types
  bool b_success = false; // stores success for bool return types
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
    cout << "Valid commands are: " << endl;
    cout << "add - add a trivia question" << endl; // enqueue
    cout << "draw - choose a new trivia question" << endl; //dequeue, push
    cout << "check - check your answer to the question" << endl; //check, push, pop
    cout << "du - display used questions" << endl; //display stack
    cout << "dc - display correctly answered questions" << endl; //display stack
    cout << "dq - display playable questions" << endl; //display queue
    cout << "> ";
    cin.get(input, 20);
    cin.get();
    cout << "---------------------------------------------------" << endl;
    
    //change input to lowercase
    for(int i = 0; i < (int) strlen(input); i++){
      input[i] = tolower(input[i]);
    }

    //check uses queue->check
    if(strcmp(input, "check") == 0){
      cout << "Enter your answer. " << endl;
      cout << "> ";
      cin.get(answer, 40);
      cin.get();
      b_success = new_queue->check(answer);
      print_success(b_success);
    }

    //draw calls dequeue, a print function, and push
    if(strcmp(input, "draw") == 0){
      success = new_queue->draw();
      print_error_messages(success, "draw");
      
    }
    
    //display used uses stack->display()
    if(strcmp(input, "du") == 0){ 
      success = used_stack->display();
      print_error_messages(success, "display");
    }

    //display correct uses stack->display()
    if(strcmp(input, "dc") == 0){
      success = correct_stack->display();
      print_error_messages(success, "display");
    }

    //add uses queue->enqueue()
    if(strcmp(input, "add") == 0){ //queue
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

    //display queue uses queue->display()
    if(strcmp(input, "dq") == 0){ 
      success = new_queue->display();
      print_error_messages(success, "d");
    }
  }
  cout << "Goodbye!" << endl;
  return 0;
}

void print_error_messages(int success, const char function_name[]){
  if(success == 1){ //success!
    if(strcmp(function_name, "add") == 0){
      cout << "Question added successfully." << endl;
      cout << " " << endl;
    }
    return;
  } else if (success == 0){ //list is null
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
  }
}

void print_success(bool b_success){
  if(b_success == true){
    cout << "That's correct!" << endl;
  } else {
    cout << "That was incorrrect." << endl;
  }
}
