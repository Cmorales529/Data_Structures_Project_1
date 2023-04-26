#include <iostream>
using namespace std;

/***************************************************************/
/* Programmer: Christian Morales                                */        
/* Date: February 2, 2023                                      */        
/* Purpose:  generic linked list class                         */ 
/***************************************************************/

#ifndef LLIST_H
#define LLIST_H

template <class T>
struct node
{
   T info;
   node<T> *next;
};

template <class T>
class LList 
{
   private:
      node<T> *first; 
      int length;
   public:
      //Constructor 
      LList();
      // Destructor
      ~LList();
      //Copy constructor
      LList ( const LList<T> & other);
      //Overload the assignment operator 
      const LList<T> & operator= (const LList<T> & other);
      //Returns current length of list
      int getLength();
      // Returns true if list is empty, false otherwise
      bool isEmpty();
      // Inserts parameter item
      void insertItem(T item);
      //If list is not empty and parameter item is in the list, removes   
      // item from the list and decrements length. If list is empty or 
      // item is not in the list, prints error message
      void deleteItem(T item);
      //Returns true if parameter item is in the list, false otherwise
      bool searchItem(T item);
      //Print all items in the list. Print message if list is empty.
      void printList();
      // function to copy a list
      void copy (const LList<T> & other);
      // Destroy list function
      void destroy();
    
};
#endif