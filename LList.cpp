#include "LList.h"

/***************************************************************/
/* Programmer: Christian Morales                                  */     
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

   if ( first == NULL || item < first->info )
   {
      p->next = first;
      first = p;
   }
   else
   {
      node<T> *q = first->next;
      node<T> *r = NULL;

      while ( q != first && q->info < item )
        {
           r = q;
           q = q->next;
        }

       p->next = q;
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
      node<T> *p = first;
      if ( item == first->info )
      {
         first = first->next;
         delete p;
         length--;
        }
      else
      {
         node<T> *s = NULL;

         while ( p != first && item < p->info )
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
    node<T> *q;
   p = first->next;
   while (p->next != first)
   {
      p=p->next;
   }

   while ( first != p )
   {
      q = first;
      first = first->next;
      delete q;
   }

      delete p;

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

       while ( p != first->next )
         {
            q->next = new node<T>;
            q = q->next;
            q->info = p->info;
            p = p->next;
         }

        q->next = first;
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
   bool found;

   found = false;
   p = first->next;

   while ( p != first && !found && p->info <= item )
   {
      if ( item == p->info )
         found= true;
      p = p->next;    
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

     p = first->next;

     while ( p != first )
     {
        cout<<p->info<<" ";
        p = p->next;
     }

     cout<<"\n";
    } 
}
