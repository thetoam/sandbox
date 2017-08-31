#include <cstdlib>
#include <iostream>

#include "list.hh"


List::List()
{
  head = NULL;
  tail = NULL;
}


void List::append(int data)
{
  node *n = new node;
  n->data = data;
  n->next = NULL;

  if (head == NULL)
  {
    head = n;
    tail = n;
  } else {
    tail->next = n;
    tail = n;
  }
  n = NULL;
}


void List::insert_start(int data)
{
  node *n = new node;
  n->data = data;
  n->next = NULL;
  
  if (head == NULL)
  {
    head = n;
    tail = n;
  } else {
    n->next = head;
    head = n;
  }
  n = NULL;
}

void List::insert_end(int data)
{
  append(data);
}


void List::insert(int pos, int data)
{
  node *prev = NULL;
  node *cur = NULL;

  node *n = new node;
  n->data = data;
  n->next = NULL;

  if (head == NULL) // If the list is empty to begin with
  {
    head = n;
    tail = n;
    n = NULL;
    return;
  }

  cur = head;
  for (int i = 0; i < pos && cur != NULL; i++)
  {
    prev = cur;
    cur = cur->next;
   // if (prev == tail) // If inserting beyond the list length, insert at the end of the list.
   // {
   //   break;
   // }
  } 
 
 
  if (prev)
  {
    prev->next = n;
    if (prev == tail) // If inserting at end
    {
      tail = n;
    }
  } else {
    head = n; // If inserting at position 0, there is no previous node!
  }

  n->next = cur;
  n = NULL;
}


void List::remove_start()
{
  node *n = head;

  if (n) // Only take action if the list is non-empty.
  {
    head = n->next;
    if (head == NULL)
    {
      tail = NULL; // If the last element was removed
    } 
  }

  delete n; // Free the memory from the removed node
  n = NULL;
}

void List::remove_end()
{
  node *n = head;
  node *m;

  if (n) // Only take action if the list is non-empty
  {
    while (n !=  tail && n->next != tail)
    {
      n = n->next;
    }
    
    if (n == tail) // If the last element is being removed
    {
      head = NULL;
      tail = NULL;
      m = n;
      n = NULL;
    } else {
      m = tail;
      n->next = NULL;
      tail = n;
      n = NULL; 
    }
   
    delete m;
    m = NULL;
  }
}


void List::remove(int pos)
{
  node *n = head;
  node *m;
  
  if (n)  // Only take action is the list is non-empty
  {
    
    for (int i = 0; i < pos; i++)
    {
      if (n == NULL)
      {
        return; // Cannot remove beyond the end of the list
      }
      m = n;
      n = n->next;
    }
    
    if (m == NULL)  // If the first element is being removed
    {
      head = n->next;
      if (head == NULL)  // If the list is now empty
      {
        tail = NULL;
      }
    } else {
      m->next = n->next;
      if (m->next == NULL) // If the last element is being removed
      {
        tail = m;
      }
    }
    delete n;
    m = NULL;
    n = NULL;

  }
}


void List::display()
{
  node *n = head;
  std::cerr << "List: ";
  if (n != NULL)
  {
    while (true)
    {
      std::cerr << n->data << " ";
      if (n == tail)
      {
        break;
      }
      n = n->next;
    }
  }
  std::cerr << std::endl;
}



