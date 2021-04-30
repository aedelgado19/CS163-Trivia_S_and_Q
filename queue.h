/* Author: Allison Delgado
   Class: CS 163 Spring 2021
   queue.h contains the structures and operations
   of the queue class, implemented in a CLL
  
   Last updated: April 23
 */

#include <iostream>
#include "trivia.h"

struct q_node {
  q_node* next;
  trivia* data;
};

/* all int return type functions return a 0 for failure  
   and a 1 for success  */
class queue{
 public:
  queue(); //Task 6: queue constructor
  ~queue(); //Task 7: queue destructor

  //Task 8: Enqueue a trivia question to rear 
  int enqueue(char* question, char* answer);

  //Task 9: Display the queue 
  int display();
  
  //Task 10: Dequeue a trivia question from front 
  int dequeue();

  //check answer
  bool check(char* user_answer);
  
  //display the most recently asked question
  int display_question();
  
  //get data from queue node
  char* get_answer();
  char* get_question();

  //checks if the queue has anything in it
  bool check_exists();
private:
  q_node* rear;
  q_node* question_asked;
};
