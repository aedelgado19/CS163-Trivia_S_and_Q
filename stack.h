/* Author: Allison Delgado
   Class: CS 163 Spring 2021
   stack.h contains the structures and operations
   of the stack class, implemented in a LLL
   
   Last updated: April 23
 */
#include <iostream>
#include "trivia.h"

//nodes for the stack (LLL)
struct s_node { 
  trivia* data;
  s_node* next;
};

/* all int return type functions return a 0 for failure
   and a 1 for success  */
class stack {
 public:
  stack(); //Task 1: stack constructor
  ~stack(); //Task 2: stack destructor
  
  //Task 3: Push a trivia question at the top
  int push(char* question, char* answer);

  //Task 4: Display questions on the stack
  int display();

  //Task 5: Pop a trivia question from the top
  int pop();
  
 private:
  s_node* head;
  int top_index; //set to zero initially. When it equals SIZE, the array is full
  trivia* recently_popped;
};
