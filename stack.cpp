/* Author: Allison Delgado
   Class: CS 163 Spring 2021
   stack.cpp contains the following member functions:
   constructor, destructor, push, display, pop

 */

#include <iostream>
#include <cstring>
#include "stack.h"
#define SIZE 5

/* the stack constructor sets the head to null */
stack::stack(){
  head = NULL;
}

/* the stack destructor deallocates all dynamic memory */
stack::~stack(){
  s_node* current = head;
  while(current != NULL){
    s_node* hold = current->next;
    delete current;
    current = hold;
  }
  s_node* hold = current->next;
  delete current;
  current = hold;
  head = NULL;
}

/* push adds a new trivia question at the top of the list. 
   it is passed data from main */
int stack::push(char* question, char* answer){
  bool full = false;
  int index = 0;
  
  //copy over data into new trivia element
  trivia* new_trivia = new trivia;
  new_trivia->question = new char[40];
  strcpy(new_trivia->question, question);
  new_trivia->answer = new char[40];
  strcpy(new_trivia->answer, answer);

  //check if head's array is full
  for(int j = 0; j < SIZE; j++){
    if(head->data[j] == NULL){
      full = false; //if even one is used, then it's not completely full
      index = j; //save index for direct insertion later
    }
  }

  //if the array is full, create a new s_node and add it into the array
  if(full == true){
    s_node* new_node = new s_node();
    trivia* array = new trivia[SIZE];

    //initialize all indexes of array to null
    for(int i = 0; i < SIZE; i++){
      array[i] = NULL;
    }
    

    return 1;
  }
  
  //otherwise, insert at the saved index
  else {

    return 1;
  }
  return 0; //function failure
}

/* display takes no parameters since it uses the private member head*
   and displays all nodes in the list */ 
int stack::display(){
  s_node* current = head;

  //head is a special case since if it's not completely full, it will
  //display garbage data
  for(int i = 
  
  while(current != NULL){
    std::cout << "Question: " << current->data->question << std::endl;
    std::cout << "Answer: " << current->data->answer << std::endl;
    std::cout << " " << std::endl;
    current = current->next;
  }
  return 1;
}

/* pop removes a trivia question from the top of the list.
   it needs no parameters since it uses the private data member head* */
int stack::pop(){

  return 0;
}
