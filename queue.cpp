/* Author: Allison Delgado
   Class: CS 163 Spring 2021
   queue.cpp contains the following member functions:
   constructor, destructor, enqueue, display, and dequeue

   Last updated: April 23
 */

#include <iostream>
#include <cstring>
#include "queue.h"

/* Constructor sets rear to null */
queue::queue(){
  q_node* rear = NULL;
}

/* Destructor deallocates all dynamic memory */
queue::~queue(){
  if(!rear) return;
  q_node* current = rear;
  while(current->next != rear){
    q_node* hold = current->next;
    delete current;
    current = hold;
  }
  delete current;
  rear = NULL;
}

/* Enqueue is passed user input from main and creates
   a new node, adding it to the rear */
int queue::enqueue(char* question, char* answer){
  if(!question || !answer) return 0;

  //fill in new trivia array element
  trivia* element = new trivia();
  element->question = new char[strlen(question) + 1];
  element->answer = new char[strlen(answer) + 1];
  strcpy(element->question, question);
  strcpy(element->answer, answer);
  
  //case 1: rear is null
  if(!rear){
    rear = new q_node();
    rear->data = element;
    rear->next = rear;
    return 1;
  }

  //case 2: all other cases where rear isn't null
  q_node* new_node = new q_node();
  new_node->data = element;
  new_node->next = rear->next;
  rear->next = new_node;
  rear = new_node;
  return 1;
}

/* Display takes no parameters since the rear is a private
   data member, and displays all nodes in the list */
int queue::display(){
  q_node* current = rear;

  //there's nothing to display if rear is null
  if(!rear) return -1;
  
  //if the rear is the only node
  if(rear->next == rear){
    std::cout << "Question: " << rear->data->question << std::endl;
    std::cout << "Answer: " << rear->data->answer << std::endl;
    return 1;
  }

  //traverse list, display as you go
  while(current->next != rear){
    std::cout << "Question: " << current->data->question << std::endl;
    std::cout << "Answer: " << current->data->answer << std::endl;
    std::cout << " " << std::endl;
    current = current->next;
  }
  std::cout << "Question: " << current->data->question << std::endl;
  std::cout << "Answer: " << current->data->answer << std::endl;
  return 1;
}

/* Dequeue takes in no parameters since it removes the
   front node */
int queue::dequeue(){

  //if there's nothing to dequeue, return failure
  if(!rear) return -1;

  //if there's only one node to remove
  if(rear->next == rear){
    delete rear;
    rear = NULL;
    return 1;
  }

  //otherwise remove the front node and update rear's next
  q_node* hold = rear->next;
  rear->next = rear->next->next;
  hold->next = NULL;
  delete hold;
  return 1;
}
