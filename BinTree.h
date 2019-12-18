
// ------------------------------- BinTree.h-----------------------------------------------------------------
/* Author: Elias Alabssie
*Class: CSS 343, Section c
*project created: Jan 27, 2019
*Date of Last Modification: Feb 3, 2019
 -------------------------------------------------------------------------------------------------------------
 
 * This BinTree class header creates a declaration for binary search tree implementation. 
 the BST stores the "NodeData" object in its data pointer and the left and the right Node
 pointers point to the left and the right sub trees in the BST. Also, the program takes NodeData
 object files and builds BST. 
--------------------------------------------------------------------------------------------------------------
  
   when BST build from the text file, the program assumes the input text is well formated(space between intries
   and $$ at the end of each line).
--------------------------------------------------------------------------------------------------------------*/

#ifndef BINTREE_H
#define BINTREE_H

#include "NodeData.h" //Notice: N in NodeData is capital unlike the lab2.cpp file 
#include<iostream>
using namespace std;

//class BinTree
class BinTree 
{				// you add class/method comments and assumptions
	// declaring friend classes 
	friend ostream& operator <<(ostream &outStream, BinTree &tree);
	friend istream& operator>>(istream &iStream, BinTree &tree);


	public:
		BinTree();// constructor
		BinTree(const BinTree &);// copy constructor
		~BinTree();		// destructor, calls makeEmpty	
		bool isEmpty() const;// true if tree is empty, otherwise false
		void makeEmpty();	// make the tree empty so isEmpty returns true

		//operator overloads
		BinTree& operator=(const BinTree &);
		bool operator==(const BinTree &) const;
		bool operator!=(const BinTree &) const;
		
		//class methods
		bool insert(NodeData*);//inserts NodeData pointers into the tree and returs bool.
		bool retrieve(NodeData toBeSearched, NodeData* value)const;//returns true if data foound, false otherwise
		void displaySideways() const;	//displays the tree sideways
		
		//added functions
		void inorder(ostream &outStream);//inorder traversal
		int getHeight(const NodeData &) const;//returns the height of the tree as int
		void bstreeToArray(NodeData* []);//builds array from BST 
		void arrayToBSTree(NodeData* []);//builds BST from array

		//int getDepth(const NodeData &comparisonKey) const

		

	private:
		struct Node 
		{
			NodeData* data = nullptr;// pointer to data object
			Node* left = nullptr;	// left subtree pointer
			Node* right = nullptr;	// right subtree pointer
		};
		
		Node* root;			// root of the tree

	
		// utility functions
		void makeEmptyHelper(Node*& );
		void asignmentOverloadHelper(Node *&tree);
		bool equalityHelper(const Node *rootNode, const Node *leftRootNode) const ;
		bool insertHelper(Node *&thisRoot, NodeData *item);
		bool retrieveHelper(Node *&rootNode, NodeData &findThisNode, NodeData *value) const;
		void sideways(Node*, int) const; 
		void inorderHelper(Node*, ostream &outStream ) ;
		int getHeightHelper(Node *, const NodeData &, int )const;
		
		int bstreeToArrayHelper(Node *current, NodeData *theArray[]);
		BinTree::Node* arrayToBSTreeHelper(NodeData *theArray[], int index, int last);
		void copyConstructorHelper(Node *&, Node *&treeNode);
};
#endif//end of class header

