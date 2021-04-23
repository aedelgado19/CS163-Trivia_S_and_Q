/* Author: Allison Delgado
   Class: CS 163 Spring 2021
   trivia.h contains the trivia struct used
   in the stack and queue nodes

   Last updated: April 23
 */

#include <iostream>
#pragma once

struct trivia {
  char* question;
  char* answer;
  bool is_used;
};
