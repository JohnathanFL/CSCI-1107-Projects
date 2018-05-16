/*--- BST.h ----------------------------------------------------------------
  This header file contains the class template BST.
  Basic operations:
     Constructor: Constructs an empty BST
     empty:       Checks if a BST is empty
     search:      Search a BST for an item
     insert:      Inserts a value into a BST
     remove:      Removes a value from a BST
     graph:       Output a grapical representation of a BST
     inorder:     Inorder traversal of a BST -- output the data values
  Private utility helper operations:
     search2:     Used by delete
     inorderAux:  Used by inorder
     graphAux:    Used by graph
  Operations tp be added:
     preorder and  postorder traversals
     destructor
     copy constructor
     assignment operator
     level-by-level traversal (in project)
     level finder (in project)

  Written by:   Larry R. Nyhoff

  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                            Lab #10.1

  Johnathan Lee         CSCI 1107
  Lab 14                Due 05/04/18

---------------------------------------------------------------------------*/

#include <iostream>
#include <new>
#include <vector>

#include "Token.h"
#include "circq.h"

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template <typename T>
class BST {
  public:
   /***** Function Members *****/
   BST();
   /*------------------------------------------------------------------------
     Construct a BST object.

     Precondition:  None.
     Postcondition: An empty BST has been constructed.
    -----------------------------------------------------------------------*/

   bool empty() const;
   /*------------------------------------------------------------------------
     Check if BST is empty.

     Precondition:  None.
     Postcondition: Returns true if BST is empty and false otherwise.
    -----------------------------------------------------------------------*/

   bool search(const T& item) const;
   /*------------------------------------------------------------------------
     Search the BST for item.

     Precondition:  None.
     Postcondition: Returns true if item found, and false otherwise.
    -----------------------------------------------------------------------*/

   void insert(const T& item);
   /*------------------------------------------------------------------------
     Insert item into BST.

     Precondition:  None.
     Postcondition: BST has been modified with item inserted at proper
         position to maintain BST property.
   ------------------------------------------------------------------------*/

   void remove(const T& item);
   /*------------------------------------------------------------------------
     Remove item from BST.

     Precondition:  None.
     Postcondition: BST has been modified with item removed (if present);
         BST property is maintained.
     Note: remove uses private auxiliary function search2() to locate
           the node containing item and its parent.
  ------------------------------------------------------------------------*/

   void graph(ostream& out) const;
   /*------------------------------------------------------------------------
     Graphic output of BST.

     Precondition:  ostream out is open.
     Postcondition: Graphical representation of BST has been output to out.
     Note: graph() uses private auxiliary function graphAux().
  ------------------------------------------------------------------------*/

   void inorder(ostream& out) const;
   /*------------------------------------------------------------------------
     Inorder traversal of BST.

     Precondition:  ostream out is open.
     Postcondition: BST has been inorder traversed and values in nodes
         have been output to out.
     Note: inorder uses private auxiliary function inorderAux().
  ------------------------------------------------------------------------*/

   //--- ADD PROTOTYPES OF preorder() AND postorder() HERE

   //--- ADD PROTOTYPE OF DESTRUCTOR HERE
   ~BST();
   /*------------------------------------------------------------------------
    * Destructor
    *
    * Preconditions: None.
    * Postconditions: Any nodes have had selfDestruct called on them, destroying
    * them.
    */

   //--- ADD PROTOTYPE OF COPY CONSTRUCTOR HERE
   BST(const BST& bst);

   //--- ADD PROTOTYPE OF ASSIGNMENT OPERATOR HERE
   BST& operator=(const BST& rhs);
   /*------------------------------------------------------------------------
    * Assignment operator
    *
    * Preconditions: None.
    * Postconditions: This BST is now an exact clone of rhs.
    */
   //--- ADD PROTOTYPE OF LEVEL-BY-LEVEL TRAVERSAL HERE
   void levelByLevel() const;
   /*------------------------------------------------------------------------
    * levelByLevel
    * Goes through the BST and prints out node contents 1 level at a time
    *
    * Preconditions: None.
    * Postconditions: Printed in the following format:
    * Level <LEVEL>:
    * <COUT ALL NODES IN THIS LEVEL>
    * Level <LEVEL+1>:
    * ...
    */
   //--- ADD PROTOTYPE OF LEVEL FINDER HERE
   unsigned level(const T& val);
   /*------------------------------------------------------------------------
    * level
    * Gets the level of an element.
    *
    * Preconditions: None.
    * Postconditions: If val is somewhere in the BST, returns the level it was
    * found on. If it wasn't, the maximum value for unsigned is returned as a
    * sentinel.
    */

  private:
   /***** Node class *****/
   class BinNode {
     public:
      T        data;
      BinNode* left;
      BinNode* right;

      // BinNode constructors
      // Default -- data part is default DataType value; both links are null.
      BinNode() : left(NULL), right(NULL) {
      }

      // Explicit Value -- data part contains item; both links are null.
      BinNode(T item) : data(item), left(NULL), right(NULL) {
      }

      BinNode(const BinNode& other) {
         data  = other.data;
         left  = other.left;
         right = other.right;
      }

      void selfDestruct();
      /*--------------------------------------------------------------------------
       * selfDestruct
       * Traverses this node's subtree in LRP order, freeing all nodes.
       * Precondition: This node exists.
       * Postcondition: This node is history.
       */

      void copyTo(BinNode* node) const;
      /*------------------------------------------------------------------------
       * copyTo
       * Recursively copies this subtree to another subtree.
       * Pre: this node exists.
       * Post: This entire subtree was replicated at node
       */

   };  // end of class BinNode declaration

   typedef BinNode* BinNodePointer;

   /***** Private Function Members *****/

   void search2(const T& item, bool& found, BinNodePointer& locptr,
                BinNodePointer& parent) const;
   /*------------------------------------------------------------------------
     Locate a node containing item and its parent.

     Precondition:  None.
     Postcondition: locptr points to node containing item or is null if
         not found, and parent points to its parent.#include <iostream>
   ------------------------------------------------------------------------*/

   void inorderAux(ostream& out, BinNodePointer subtreePtr) const;
   /*------------------------------------------------------------------------
     Inorder traversal auxiliary function.

     Precondition:  ostream out is open; subtreePtr points to a subtree
         of this BST.
     Postcondition: Subtree with root pointed to by subtreePtr has been
         output to out.
   ------------------------------------------------------------------------*/

   void graphAux(ostream& out, int indent, BinNodePointer subtreeRoot) const;
   /*------------------------------------------------------------------------
     Graph auxiliary function.

     Precondition:  ostream out is open; subtreePtr points to a subtree
         of this BST.
     Postcondition: Graphical representation of subtree with root pointed
         to by subtreePtr has been output to out, indented indent spaces.
   ------------------------------------------------------------------------*/

   /***** Data Members *****/
   BinNodePointer myRoot;

};  // end of class template declaration

//--- Definition of constructor
template <typename DataType>
inline BST<DataType>::BST() : myRoot(NULL) {
}

//--- Definition of empty()
template <typename DataType>
inline bool BST<DataType>::empty() const {
   return myRoot == NULL;
}

//--- Definition of search()
template <typename DataType>
bool BST<DataType>::search(const DataType& item) const {
   BST<DataType>::BinNodePointer locptr = myRoot;
   bool                          found  = false;
   while (!found && locptr != NULL) {
      if (item < locptr->data)  // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else  // item found
         found = true;
   }
   return found;
}

//--- Definition of insert()
template <typename DataType>
inline void BST<DataType>::insert(const DataType& item) {
   BST<DataType>::BinNodePointer locptr = myRoot,  // search pointer
       parent = NULL;   // pointer to parent of current node
   bool found = false;  // indicates if item already in BST
   while (!found && locptr != NULL) {
      parent = locptr;
      if (item < locptr->data)  // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else  // item found
         found = true;
   }
   if (!found) {  // construct node containing item
      locptr = new (nothrow) BST<DataType>::BinNode(item);
      if (locptr == NULL) {
         cerr << "*** Out of memory -- terminating program ***\n";
         exit(1);
      }

      if (parent == NULL)  // empty tree
         myRoot = locptr;
      else if (item < parent->data)  // insert to left of parent
         parent->left = locptr;
      else  // insert to right of parent
         parent->right = locptr;
   } else
      cout << "Item already in the tree\n";
}

//--- Definition of remove()
template <typename DataType>
void BST<DataType>::remove(const DataType& item) {
   bool                          found;  // signals if item is found
   BST<DataType>::BinNodePointer x,      // points to node to be deleted
       parent;                           //    "    " parent of x and xSucc
   search2(item, found, x, parent);

   if (!found) {
      cout << "Item not in the BST\n";
      return;
   }
   // else
   if (x->left != NULL && x->right != NULL) {  // node has 2 children
      // Find x's inorder successor and its parent
      BST<DataType>::BinNodePointer xSucc = x->right;
      parent                              = x;
      while (xSucc->left != NULL)  // descend left
      {
         parent = xSucc;
         xSucc  = xSucc->left;
      }

      // Move contents of xSucc to x and change x
      // to point to successor, which will be removed.
      x->data = xSucc->data;
      x       = xSucc;
   }  // end if node has 2 children

   // Now proceed with case where node has 0 or 2 child
   BST<DataType>::BinNodePointer subtree =
       x->left;  // pointer to a subtree of x
   if (subtree == NULL)
      subtree = x->right;
   if (parent == NULL)  // root being removed
      myRoot = subtree;
   else if (parent->left == x)  // left child of parent
      parent->left = subtree;
   else  // right child of parent
      parent->right = subtree;
   delete x;
}

//--- Definition of graph()
template <typename DataType>
inline void BST<DataType>::graph(ostream& out) const {
   graphAux(out, 0, myRoot);
}

//--- Definition of search2()
template <typename DataType>
void BST<DataType>::search2(const DataType& item, bool& found,
                            BinNodePointer& locptr,
                            BinNodePointer& parent) const {
   locptr = myRoot;
   parent = NULL;
   found  = false;
   while (!found && locptr != NULL) {
      if (item < locptr->data)  // descend left
      {
         parent = locptr;
         locptr = locptr->left;
      } else if (locptr->data < item)  // descend right
      {
         parent = locptr;
         locptr = locptr->right;
      } else  // item found
         found = true;
   }
}

//--- Definition of graphAux()
#include <iomanip>

template <typename DataType>
void BST<DataType>::graphAux(ostream& out, int indent,
                             BinNodePointer subtreeRoot) const {
   if (subtreeRoot != NULL) {
      graphAux(out, indent + 8, subtreeRoot->right);
      out << setw(indent) << " " << subtreeRoot->data << endl;
      graphAux(out, indent + 8, subtreeRoot->left);
   }
}

//--- Definition of inorder()
template <typename DataType>
inline void BST<DataType>::inorder(ostream& out) const {
   inorderAux(out, myRoot);
}

//--- Definition of inorderAux()
template <typename DataType>
void BST<DataType>::inorderAux(ostream& out, BinNodePointer subtreeRoot) const {
   if (subtreeRoot != NULL) {
      inorderAux(out, subtreeRoot->left);   // L operation
      out << subtreeRoot->data << "  ";     // V operation
      inorderAux(out, subtreeRoot->right);  // R operation
   }
}

//--- PUT DEFINITIONS OF THE ADDED OPERATIONS HERE

template <typename T>
BST<T>::~BST() {
   if (myRoot)
      myRoot->selfDestruct();
   myRoot = NULL;
}

template <typename T>
BST<T>::BST(const BST& bst) {
   this->~BST();

   if (bst.myRoot) {
      myRoot = new BinNode();

      bst.myRoot->copyTo(myRoot);
   }
}

template <typename T>
BST<T>& BST<T>::operator=(const BST& rhs) {
   if (this != &rhs) {
      this->~BST();

      if (rhs.myRoot) {
         myRoot = new BinNode();
         rhs.myRoot->copyTo(myRoot);
      }
   }
   return *this;
}

template <typename T>
void BST<T>::levelByLevel() const {
   bool                endReached = false;
   unsigned            curLevel   = 0;
   CircularQ<BinNode*> curLevelPtrs, curLevelBuff;
   curLevelPtrs.enqueue(myRoot);
   while (!endReached && !curLevelPtrs.empty()) {
      endReached = true;
      cout << "\nLevel " << curLevel++ << ":\n";
      while (!curLevelPtrs.empty()) {
         BinNode* cur = curLevelPtrs.front();
         if (cur) {
            endReached = false;
            cout << cur->data;

            // Make sure we don't enqueue useless data.
            if (cur->left)
               curLevelBuff.enqueue(cur->left);
            if (cur->right)
               curLevelBuff.enqueue(cur->right);
         }
         curLevelPtrs.dequeue();
      }

      curLevelPtrs = curLevelBuff;  // Swap them.
      curLevelBuff.~CircularQ();    // Clear out the buffer for next level.
   }
}

template <typename T>
unsigned BST<T>::level(const T& val) {
   unsigned finalLevel = -1;
   BinNode* cur        = myRoot;
   while (cur) {
      finalLevel++;
      if (cur->data == val)
         return finalLevel;
      else if (val > cur->data)
         cur = cur->right;
      else if (val < cur->data)
         cur = cur->left;
   }
}

// For destructor
template <typename T>
void BST<T>::BinNode::selfDestruct() {
   if (left)
      left->selfDestruct();
   if (right)
      right->selfDestruct();

   left = right = NULL;
   delete this;
}

template <typename T>
void BST<T>::BinNode::copyTo(BST::BinNode* node) const {
   node->data = this->data;
   if (this->left) {
      if (node->left == NULL)
         node->left = new BinNode(left->data);

      left->copyTo(node->left);
   }
   if (this->right) {
      if (node->right == NULL)
         node->right = new BinNode(right->data);

      right->copyTo(node->right);
   }
}

// Specialized for Project-10.1


template <typename T>
ostream& operator<<(ostream& out, const BST<T>& bst) {
   bst.graph(out);
   return out;
}

#endif
