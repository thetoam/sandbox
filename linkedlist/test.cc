#include <iostream>

#include "list.hh"

using namespace std;

void testAppend();
void testInsertStart();
void testInsert();
void testRemoveStart();
void testRemoveEnd();
void testRemove();

void runForever();

int main()
{
  testAppend();
  testInsertStart();
  testInsert();
  testRemoveStart();
  testRemoveEnd();
  testRemove();
  runForever();
}


void runForever()
{
  cerr << "Running an infinite loop - press ctrl+c to exit" << endl;
  
  List list;

  list.append(1); // 1

  while (true)
  {
    list.append(2); // 1 2
    list.append(3); // 1 2 3    
    list.insert_start(0); // 0 1 2 3
    list.insert(4, 4); // 0 1 2 3 4
    list.insert(100, 5); // 0 1 2 3 4 5

    list.remove_start(); // 1 2 3 4 5
    list.remove_end(); // 1 2 3 4
    list.remove(1); // 1 3 4
    list.remove(1); // 1 3
    list.remove(1); // 1
    list.remove(100);
  }


}


void testRemove()
{
  cerr << "Testing remove() method" << endl;

  List list;
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -
  
  list.remove(0);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -

  list.append(1);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 -
 
  list.remove(0);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -

  list.append(1);
  list.append(2);
  list.append(3);
  list.append(4);
  list.append(5);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 2 3 4 5 -
 
  list.remove(4);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 2 3 4 -

  list.remove(1);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 3 4 -
  
  list.remove(2);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 3 -
  
  list.remove(5);
  list.display();   
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 3 -

  list.remove(1);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 -

  list.remove(0);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -

  list.remove(0);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -



}


void testRemoveEnd()
{
  cerr << "Testing remove_end() method" << endl;

  List list;
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -
  
  list.remove_end();
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -
  
  list.append(1);
  list.append(2);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 2 -

  list.remove_end();
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 -

  list.remove_end();
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -
  
  list.remove_end();
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -

}

void testRemoveStart()
{
  cerr << "Testing remove_start() method" << endl;

  List list;
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -
  
  list.remove_start();
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -
  
  list.append(1);
  list.append(2);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 2 -

  list.remove_start();
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 2 -

  list.remove_start();
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -
  
  list.remove_start();
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -
  



}

void testInsert()
{ 
  cerr << "Testing insert() method" << endl;
  List list;
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -
  
  list.insert(0, 5);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 5 -
  list.insert(0, 1);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 5 -

  list.insert(1, 2);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 2 5 -
  
  list.insert(2, 3);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 2 3 5 -
  
  list.insert(4, 6);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 2 3 5 6 -
  
  list.insert(100, 7);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 2 3 5 6 7 -
  
  list.insert(3, 4);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 2 3 4 5 6 7 -



}

void testInsertStart()
{
  cerr << "Testing insert_start() method" << endl;
  
  List list;
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -

  list.insert_start(2);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 2 -
  
  list.insert_start(1);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 2 -

}

void testAppend()
{
  cerr << "Testing append() / insert_end() method" << endl;
  
  List list;
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: -

  list.append(1);
  list.display(); 
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 -
  list.append(2);
  list.display();
  // Pos: 0 1 2 3 4 5 6 7 8 9
  // Val: 1 2 -


}




