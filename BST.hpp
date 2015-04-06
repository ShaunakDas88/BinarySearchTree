#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <utility> // for std::pair
#include <iostream>
#include <stdio.h>

using namespace std;

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or nullptr if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;


public:

  /** iterator is an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(nullptr), isize(0)  {
  }


  /** Default destructor.
   *  It is virtual, to allow appropriate destruction of subclass objects.
   *  Delete every node in this BST.
   */ // TODO
  virtual ~BST() {
        // call to clear method will delete all node
	clear();
  }

  /** Insert a Data item in the BST.
   *  Return a pair, with the pair's first member set to an
   *  iterator pointing to either the newly inserted element
   *  or to the equivalent element already in the set.
   *  The pair's second element is set to true
   *  if a new element was inserted or false if an
   *  equivalent element already existed.
   */ // TODO
  virtual std::pair<iterator,bool> insert(const Data& item) {
   
    BSTNode<Data>* tempNode = root; 
    if(root == nullptr){
      BSTNode<Data>* inserted  = new BSTNode<Data>(item);
      root = inserted;
      isize = isize + 1;
      return std::make_pair(BST<Data>::iterator(inserted), true);
    }
    else{
     	// traverse through the tree, looking for the item
    	while(tempNode->data != item){
          if(item < tempNode->data){
	    if(tempNode->left != nullptr)
    	    {
	      tempNode = tempNode->left;
	    }
            else{
	      // new instance of BSTNode class; new returns pointer
              BSTNode<Data>* inserted = new BSTNode<Data>(item);
	      // update pointers
              inserted->parent = tempNode;
	      tempNode->left = inserted;
	      isize = isize + 1;
              return std::make_pair(BST<Data>::iterator(inserted), true); 
            }
          }
	  else{
            if(tempNode->right != nullptr){
              tempNode = tempNode->right;
            }
            else{
              // new instance of BSTNode class; new returns pointer
              BSTNode<Data>* inserted = new BSTNode<Data>(item);
	      // update pointers
	      inserted->parent = tempNode;
	      tempNode->right = inserted;
	      isize = isize + 1;
              return std::make_pair(BST<Data>::iterator(inserted), true);
	    }   // close up else
	  } // close up else
  	} // close up while loop
	// made it out of while loop, check if an insertion occurred
    	return std::make_pair(BST<Data>::iterator(tempNode), false);  
   }
}
        

  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or the end
   *  iterator if the item is not in the BST.
   */ // TODO
  iterator find(const Data& item) const {
    BSTNode<Data>* tempNode = root;
    while(tempNode != nullptr){
      //cout << "This is an iteration of the while loop.\n";
      if(item < tempNode->data){
	tempNode = tempNode->left; 
      }	  
      else if(item > tempNode->data){
	tempNode = tempNode->right;
      }
      else{
        iterator returniterator(tempNode);
        return returniterator;
      }
    } //close of while loop
    iterator returniterator(nullptr);
    return returniterator;
}
  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
	return isize;
  }

  /** Remove all elements from this BST, and destroy them,
   *  leaving this BST with a size of 0.
   */ // TODO
  void clear(){
    if(root == nullptr){
       return;
    }
    deleteNode(root);
    root = nullptr; 
    isize = 0;
    return;
  } 
	
  /** This will be a helper method that deletes a passed in BSTNode. 
   *  This will be called by the clear() method 
   */
  void deleteNode(BSTNode<Data>* node){
    if(node->left != nullptr){
      deleteNode(node->left);
    }
    if(node->right != nullptr){
      deleteNode(node->right);
    }
    delete node;
    return; 
  }
  

  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
    //if number of data items stored is > 0
    if (isize > 0){
      return false;
    }
    // the number of data items stored is 0
    else{
      return true;
    }
  }

  /** Return an iterator pointing to the first item in the BST.
   */ // TODO
  iterator begin() const {
    BSTNode<Data>* tempNode = root;
    //cout << "\nThis is the begin() method\n";
    //the case of an empty tree
    if(tempNode == nullptr){
      iterator beginiterator(tempNode);
      return beginiterator;
    }
    else{
      while(tempNode->left != nullptr){
	tempNode = tempNode->left;	 
      } // close while loop
      iterator beginiterator(tempNode);
      return beginiterator;
    }// close else statement
  } // close method  


  /** Return an iterator pointing past the last item in thiiiie BST.
   */
  iterator end() const {
    BSTNode<Data>* tempNode = root;
    //cout << "\nThis is the end() method.\n";
    // the case of an empty tree
    if(tempNode == nullptr){
      iterator enditerator(tempNode);
      return enditerator;
    }
    // the case that the tree is not empty
    else{
      while(tempNode->right != nullptr){
        tempNode= tempNode->right;
      } // close while loop
      iterator enditerator(tempNode->right);
      return enditerator;
    }
  } 
};


#endif //BST_HPP
