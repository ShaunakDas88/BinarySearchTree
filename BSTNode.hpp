#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

using namespace std;


/** This class template defines a node type for the BST container.
 *  Note that all members are public. So, the BST implementation should
 *  take care not to expose any BSTNode objects.
 */
template<typename Data>
class BSTNode {

public:

  /** Member variables. */
  BSTNode<Data>* parent;
  BSTNode<Data>* left;
  BSTNode<Data>* right;
  const Data data;  // the const Data in this node
  int info;  // variable used in advanced algorithms 

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d): data(d) {
    left = right = parent = nullptr;
  }


  /** Return the inorder successor of this BSTNode in a BST,
   *  or nullptr if none.
   *  PRECONDITION: this BSTNode is a node in a BST.
   *  POSTCONDITION:  the BST is unchanged.
   *  RETURNS: the BSTNode that is the inorder successor of this BSTNode,
   *  or nullptr if there is none.
   */ // TODO
  BSTNode<Data>* successor() {
    BSTNode<Data>* successorNode;
    
    // if node has a right child
    if(right != nullptr){
     	successorNode = right;
	// go all the way left!
	while(successorNode->left != nullptr){
	  successorNode = successorNode->left;
	}
        return successorNode;
    }
    // if node has no right child
    else{
      if(parent == nullptr){
	return nullptr;
      }
      // this does have a parent
      else{	
    	// if this is a left child of its parent
	if(parent->left == this){
	  successorNode = parent;
	  return successorNode;
        } 
        // if this is a right child of its parent, keep going up
        else{
          successorNode = parent;
          while(successorNode->parent != nullptr){
            // case that we finally have successorNode is a left child
            if(successorNode->parent->left == successorNode){
              successorNode = successorNode->parent;
	      return successorNode;  // break out of while loop
	    }
            // case that successorNode is a still a right child
            else{
   	      successorNode = successorNode->parent;
 	    } // closes up else statement
          } // closes up while loop
          return nullptr; 
	} // closes up else statement
      } // closes up else statement 
    } // closes up else statement 
  } // closes up successor() method
}; // closes up the class

/** Overload operator<< to insert a BSTNode's fields in an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; i:" << std::setw(10) << n.info;   // its info field
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
