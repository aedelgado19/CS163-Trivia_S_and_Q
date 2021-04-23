/* Author: Allison Delgado
   Class: CS 163 Spring 2021
   queue.h contains the structures and operations
   of the queue class, implemented in a CLL
  
   Last updated: April 23
 */

#include <iostream>

struct q_node {
  q_node* next;
  char* question;
  char* answer;
  bool is_used;
};

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

 private:
  q_node* rear;

};
