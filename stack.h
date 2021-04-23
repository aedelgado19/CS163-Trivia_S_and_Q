/* Author: Allison Delgado
   Class: CS 163 Spring 2021
   stack.h contains the structures and operations
   of the stack class, implemented in a LLL
   
   Last updated: April 23
 */
#include <iostream>

struct trivia {
  char* question;
  char* answer;
  bool is_used;
};

//nodes for the stack (LLL)
struct s_node { 
  s_node(); //Task 1: stack constructor
  ~s_node(); //Task 2: stack destructor
  trivia* array_pointer; 
  s_node* next;
};

//nodes for queue (CLL)
struct q_node { 
  q_node(); //Task 6: queue constructor
  ~q_node(); //Task 7: queue destructor
  q_node* next;
  trivia info;
};

/* all int return type functions return a 0 for failure
   and a 1 for success  */
class game {
 public:
  game(); //Constructor
  ~game(); //Destructor
  
  //Task 3: Push a trivia question at the top
  int push(char* question, char* answer);

  //Task 4: Display questions on the stack
  int display();

  //Task 5: Pop a trivia question from the top
  int pop();
  
  //Task 8: Enqueue a trivia question to rear
  int enqueue(char* question, char* answer);
  
  //Task 9: Display the queue
  int display();

  //Task 10: Dequeue a trivia question from front
  int dequeue();

 private:
  q_node* rear;
  s_node* head;
};
