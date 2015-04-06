#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * A simple test driver for the BST class template.
 * P1 CSE 100 2013
 * Author: P. Kube (c) 2013
 */
int main() {

  /* Create an STL vector of some ints */
  vector<int> v;
  v.push_back(3);
  v.push_back(4);
  v.push_back(1);
  v.push_back(100);
  v.push_back(-33);

  /* Create an instance of BST holding int */
  BST<int> b;

  /* Insert a few data items. */
  vector<int>::iterator vit = v.begin();
  vector<int>::iterator ven = v.end();
  cout << "\nTESTING THE INSERT METHOD:\n";
  for(; vit != ven; ++vit) {
    // all these inserts are unique, so should return a std::pair
    // with second part true
    std::pair<BST<int>::iterator,bool> pr = b.insert(*vit);
    if(! pr.second ) {
      cout << "Incorrect bool return value when inserting " << *vit << endl;
      return -1;
    }
    if(*(pr.first) != *vit) {
      cout << "Incorrect iterator return value when inserting " << *vit << endl;
      return -1;
    }  
  } 

  /* Test size. */
  cout << "\nTESTING THE SIZE METHOD\n";
  cout << "Size is: " << b.size() << endl;
  if(b.size() != v.size()) {
    cout << "... which is incorrect." << endl;
    return -1;
  }

  /* Test find return value. */
  cout << "\nTESTING THE FIND METHOD:\n";
  vit = v.begin();
  for(; vit != ven; ++vit) {
    cout << "Looking for an element.\n";
    if(*(b.find(*vit)) != *vit) {
      cout << "Incorrect return value when finding " << *vit << endl;
      return -1;
    }
  }
  int number = -20;
  b.find(number);
  //if(*b.find(number) == nullptr){
  //  cout << "Could not find element " << number << endl; 
  //}
  
  
  /* Sort the vector, to compare with inorder iteration on the BST */
  sort(v.begin(),v.end());

  /* Test BST iterator; should iterate inorder */
  
  cout << "\nTESTING THE BST ITERATOR!\n";
  cout << "traversal using iterator:" << endl;
  vit = v.begin(); // remember, v is a vector
  BST<int>::iterator en = b.end();
  BST<int>::iterator it = b.begin();
  cout << "The beginning node is " << *it << endl;
  //cout << "The end node is " << *en << endl;
  for(; vit != ven; ++vit) {
    if(!(it != en) ) {
      cout << *it << "," << *vit << ": Early termination of BST iteration." << endl;
      return -1;
    }
    //cout << *it << endl;
    else if(*it != *vit) {
      cout << *it << "," << *vit << ": Incorrect inorder iteration of BST." << endl;
      return -1;
    }
    else{
      cout << "The correct element " << *vit << " was found\n";
    }
    ++it;
  }
  cout << "OK." << endl;

  cout << "\nTESTING THE CLEAR METHOD!\n";
  b.clear();
  cout << "\nTESTING DUPLICATE INSERTION\n";
  b.insert(100);
  cout << "\nTESTING THE SIZE METHOD!\n";
  cout << "\nThe number of elements is " << b.size() << endl;
  cout << "TESTING FIND METHOD\n";
  b.find(12);
  b.clear();
  b.find(100);

}

