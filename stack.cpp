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
  //fill in new trivia array element
  trivia* element = new trivia();
  element->question = new char[strlen(question) + 1];
  element->answer = new char[strlen(answer) + 1];
  strcpy(element->question, question);
  strcpy(element->answer, answer);

  //head doesn't exist
  if(!head){
    head = new s_node();
    head->data = new trivia[SIZE];
    head->data[top_index] = *element;
    head->next = NULL;
    top_index++;
    return 1;
  }

  //head does exist and it's full
  if(top_index == SIZE){
    top_index = 0;
    s_node* new_node = new s_node;
    new_node->next = head;
    new_node->data = new trivia[SIZE];
    new_node->data[top_index] = *element;
    head = new_node;
    top_index++;
    return 1;
  }

  //otherwise, it's not at the max capacity so add regularly
  else {
    head->data[top_index] = *element;
    top_index++;
    return 1;
  }
  return 0; //if not any of those, function failure
}

/* display takes no parameters since it uses the private member head*
   and displays all nodes in the list */ 
int stack::display(){
  s_node* current = head->next;
  std::cout << "t: " << top_index << std::endl;
  
  //head is a special case
  //if it's not completely full, it will display garbage data
  if(top_index != SIZE){
    std::cout << "woo" << std::endl;
    for(int i = 0; i < top_index; i++){
      std::cout << "Question: " << head->data[i].question << std::endl;
      std::cout << "Answer: " << head->data[i].answer << std::endl;
      std::cout << " " << std::endl;
    }
  }
  
  //now just display the rest
  while(current != NULL){
    std::cout << "yay" << std::endl;
    for(int j = 0; j < SIZE; j++){
      std::cout << "Question: " << current->data[j].question << std::endl;
      std::cout << "Answer: " << current->data[j].answer << std::endl;
      std::cout << " " << std::endl;
    }
    current = current->next;
  }
  return 1;
}

/* pop removes a trivia question from the top of the list.
   it needs no parameters since it uses the private data member head* */
int stack::pop(){

  return 0;
}
