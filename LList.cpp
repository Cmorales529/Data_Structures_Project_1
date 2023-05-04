#include "LList.h"

/***************************************************************/
/* Programmer: Anna Salvati                                   */        
/* Date: February 2, 2023                                     */        
/* Purpose: Implementation of linked list class                */ 
/* Input: none                                                 */
/* Output: print function prints all items in the list         */
/***************************************************************/

template <class T>
LList<T> :: LList()
{
   first = NULL;
   length = 0;
}

template <class T>     
LList<T> :: ~LList()
{ 
    destroy();
}

template <class T>        
LList<T> :: LList ( const LList<T> & other)
{
   copy(other);
}

template <class T>        
const LList<T> & LList<T> :: operator= (const LList<T> & other)
{
   if ( this != &other )
   {
      destroy();
      copy(other); 
   }
  return *this;
}

template <class T>        
bool LList<T> :: isEmpty()
{
   return first == NULL;
}
      
template <class T>        
void LList<T> :: insertItem(T item)
{
   length++;
   node<T> *p = new node<T>;
   p->info = item;

   if(first == NULL)
   {
      p->next = p;
      first = p;
   }
   if (item < first->info)
   {
      p->next = first;
      first = p;
      
   }
   else
   {
      node<T> *q = first->next;
      node<T> *r = NULL;

      while ( q->next != first && q->info < item )
        {
            q = q->next;
        }
       r = q;
       p->next = first;
       r->next = p;
   }
}
      
template <class T>      
void LList<T> :: deleteItem(T item)
{
   if ( first == NULL || item < first->info )
      cout<<"\nLIST EMPTY OR ITEM NOT IN THE LIST";
   else
   {
      node<T> *p = first->next;
      if ( item == first->info )
      {
         first = first->next;
         delete p;
         length--;
        }
      else
      {
         node<T> *s = NULL;

         while ( p != first && item > p->info )
           {
              s = p;
              p = p->next;
           }

         if ( p == first || p->info > item )
            cout<<"\nITEM NOT IN THE LIST\n";
         else
         {
            s->next = p->next;
            delete p;
            length--;
         }
      }
  }
}


template <class T>
void LList<T> :: destroy()
{
   node<T> *p;
   
   p = first->next;
   
   while ( p->next != first )
   {  
      node<T> *s;
      s = first;
      first = first->next;
      p = p->next;
      delete s;
   }
   delete p;
   delete first;
   length = 0;
}

template <class T>
void LList<T> :: copy ( const LList<T> & other )
{
    length = other.length;
    if ( other.first == NULL )
       first = NULL;
    else
    {
       first = new node<T>;
       first->info = other.first->info;

       node<T> *p = other.first->next;
       node<T> *q = first;

       while ( p != NULL )
         {
            q->next = new node<T>;
            q = q->next;
            q->info = p->info;
            p = p->next;
         }

        q->next = NULL;
    }
}

template <class T>        
int LList<T> :: getLength()
{
   return length;
}

template <class T>        
bool LList<T> :: searchItem(T item)
{
   node<T> *p;
   node<T> *s;
   bool found;
   found = false;
   p = first;
   s = first;

   while(s->next != first)
   {
      s = s->next;
   }

   while ( p != s && !found && p->info <= item )
   {
      if ( item == p->info )
         found= true;
      p = p->next;    
   }

   if (found == true)
   {
      cout << "ITEM FOUND";
   }
   else
   {
      cout << "ITEM NOT FOUND";
   }
   
   return found;
}

template <class T>        
void LList<T> :: printList()
{
  if ( first == NULL )
     cout<<"\nLIST IS EMPTY\n";
  else
  {
     cout<<"\nLIST : ";
     node<T> *p;
     node<T> *s;

     p = first;
     s = first;
     while (s->next != first)
     {
      s = s->next;
     }
     
     while ( p != s )
     {
        cout<<p->info<<" ";
        p = p->next;
     }
      cout<<s->info;
     cout<<"\n";
    } 
}
