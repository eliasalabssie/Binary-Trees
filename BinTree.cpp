
#include"BinTree.h"

// ------------------------------------ BintTree -------------------------------------
// Description: an empty constructor of the BinTree class
//sets the root pointer to nullptr
// ----------------------------------------------------------------------------------
BinTree::BinTree():root(nullptr)
{


}


// ------------------------------------ BintTree(const Bintree &) -------------------------
// Description: constructor of BST tree from another Tree
//deep copy the values and pointers  of the argument BST to the "this" object
// ----------------------------------------------------------------------------------------
BinTree::BinTree(const BinTree &tree)
{

	
	if(tree.root == nullptr)
	{
		this->root = nullptr;

	}

	//the tree root Node is not nullptr
	else
	{
		//get the root of the source tree
		Node *thisTree = tree.root;
		copyConstructorHelper(this->root, thisTree);

	}
	
}


// ------------------------------------ copyConstructorHelper -------------------------
// Description: a helper function for the copy constructor ree
//deep copy the values and pointers  of the argument BST to the "this" object
// -------------------------------------------------------------------------------------
// @Args: the root Node of the class and the address of the root node of the argument class
//pre: none 
//Post:both tree will have equal values
//------------------------------------------------------------------------------------------
void BinTree:: copyConstructorHelper(Node *&root, Node *&sourceRoot)
{

	if(sourceRoot == nullptr)
	{
		root = nullptr;

	}

	else
	{
		
		root = new Node;

		//get the data element of the source tree
		NodeData *item = new NodeData(*sourceRoot->data);
		
		
		root->data = item;

		//move to left subtree
		copyConstructorHelper(root->left, sourceRoot->left);

		//move to the right subtree
		copyConstructorHelper(root->right, sourceRoot->right);

	}

}



// ------------------------------------ ~BinTree -----------------------------------
// Description: destroys the entire tree by calling the makeEmpty() member function
// -----------------------------------------------------------------------------------
BinTree::~BinTree()		
{

	this->makeEmpty();

}


// ------------------------------------ isEmpty ---------------------------------------
// Description: checks the is the BST is empty or not
//return true if root points to nullptr, false otherwise
// -------------------------------------------------------------------------------------
//pre: none 
//Post:none
//------------------------------------------------------------------------------------
bool BinTree::isEmpty() const	
{
	bool empty = root == nullptr;
	return empty;

}


// ------------------------------------ makeEmpty ----------------------------------------
// Description: destroyes the entire tree by calling helper method
//pre: none 
//Post:the tree is empty and the root pointer points to null
//-------------------------------------------------------------------------------------------
void BinTree::makeEmpty()	
{
	//call the makeEmptyHelper() helper method that deletes the entire tree
	makeEmptyHelper(this->root); 
	root = nullptr;

}	

//------------------------- makeEmptyHelper ---------------------------------------------
// a helper method for makeEmpty to delete the binary search tree ;
// Preconditions: NONE
// Postconditions: the BinTree will destroyed.
//@Arg: the root node of the Tree
//------------------------------------------------------------------------------------------
void BinTree::makeEmptyHelper(Node *&root )
{
	//move to the left child
	if(root != nullptr)
	{
		makeEmptyHelper(root->left);
		makeEmptyHelper(root->right);
	
	// delete the NodeData object and set it to point to nullptr
		delete root->data;
		//root->data = nullptr;

	//delete the root node and set it to point to nullptr
		delete root;
		root = nullptr;
	}

}

//------------------------- operator= ------------------------------------------------
//Description:overloads the assignment operator by calling helper methhod
// return BinTree that contains the values from the argument BinTree
// Preconditions: NONE
// Postconditions: BinTree contains the same values as the argumetn BinTrre.
//-------------------------------------------------------------------------------------
BinTree& BinTree::operator=(const BinTree &tree)
{

	//check self assignment
	if(this != &tree)
	{
		//empty the tree
		this->makeEmpty();

		root = nullptr;


		Node* current = tree.root;
		asignmentOverloadHelper(current);

	}

	return *this;

}


// ------------------------------------ asignmentOverloadHelper --------------------------------
// Description: a helper function for the = overload
//deep copy the values and pointers  of the argument BST to the "this" object
// ----------------------------------------------------------------------------------------------
// @Args: address of the root node of the argument class
//pre: none 
//Post:both tree will have equal values
//------------------------------------------------------------------------------------------------
void BinTree::asignmentOverloadHelper(Node *&rootNode)
{

	if(rootNode != nullptr)
	{
		
		this->insert(rootNode->data);
		asignmentOverloadHelper(rootNode->left);
		asignmentOverloadHelper(rootNode->right);
	}
	

}

//------------------------- operator== ---------------------------------------------------
// Description: checks if two BinTrees are equal(same) both in values and shape
//by calling helper method.
//returns true if equal, false otherwise
//------------------------------------------------------------------------------------------
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
//---------------------------------------------------------------------------------------------
bool BinTree::operator==( const BinTree &tree) const
{

	const Node* leftRoot = tree.root;
	bool equal = equalityHelper(root, leftRoot);
	return equal;	

}


//----------------------------- equalityHelper ----------------------------------------------
//Description: compares the two BST BinTrees data values for equality;
// return true if equal; false otherwise
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
//---------------------------------------------------------------------------------------------
bool BinTree::equalityHelper(const Node *rootNode, const Node *leftRootNode) const
{
	//empty trees are eqyal
	if( rootNode == nullptr && leftRootNode == nullptr)
	{
		return true;	
	}

	//check the equality of right and left subtrees and each data
	else if(rootNode != nullptr && leftRootNode != nullptr)
	{
		if(*rootNode->data == *leftRootNode->data && 
			equalityHelper(rootNode->left, leftRootNode->left) &&
		 	equalityHelper(rootNode->right, leftRootNode->right))
		{
			//equal
			return true;

		}
	}
	
	//not equal
	return false;		

}


//------------------------- operator!= ------------------------------------------------------------
///Description: compares the two BST BinTrees data values for equality;
// return true if no equal; false otherwise
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
//-------------------------------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree &tree) const
{

	bool  notEqualTo = *this == tree;
	return !notEqualTo;

}


//------------------------- insert ------------------------------------------------------------
// Description: inserts the NodeData pointer objects into the BinTree by calling a helper and 
//returns true for successful insertion, false otherwise(redundent values);
// 
// Preconditions: NONE
// Postconditions: BinTree contains the new values if it is not redundent
//----------------------------------------------------------------------------------------------
bool BinTree::insert(NodeData* rightNode)
{
	
		bool inserted = insertHelper(root, rightNode);
		
		return inserted;

}

	
//------------------------- insertHelper -----------------------------------------------------------
// Description: inserts the NodeData pointer objects into the BinTree and 
//returns true for successful insertion, false otherwise(redundent values);
// 
// Preconditions: NONE
// Postconditions: BinTree contains the new values if it is not redundent
//----------------------------------------------------------------------------------------------
bool BinTree::insertHelper(Node * &thisRoot, NodeData *item)
 {
	
 	if (thisRoot == nullptr) 
 	{
 		//if the root is nullptr, make the Node and set root to point to it
			
			Node *newNode = new Node;
			newNode->data =  new NodeData(*item); 

			thisRoot = newNode;
			//delete dataItem;
			return true;	
	
	 }

	else if (*item < *thisRoot->data )
	{ 	
		//insert to the left subtree
		return insertHelper(thisRoot->left, item);	
	
		
				
	}

	else if (*item > *thisRoot->data) 
	{
		//insert to the right subtree
		return insertHelper(thisRoot->right, item);
	
				
	
	}

	//the data is redudndent; dont't insert it
	else
	{		
		return false;

	}	
}

//--------------------------------- retrive ------------------------------------------------------
// Description: checks if a an object(values) present in the BinTree or not by calling helper method
// returns the values via an argument and bool value true if the object present, false otherwise 
// Preconditions: None
// Postconditions: None
//-------------------------------------------------------------------------------------------------
bool BinTree::retrieve(NodeData toBeSearched, NodeData* value)const
{
	Node *current = this->root;
	return retrieveHelper(current, toBeSearched, value);
	

}

//--------------------------------- retriveHelper -------------------------------------------------
// Description: checks if a an object(values) present in the BinTree or not
// returns the object(value) via the incoming  NodeData pointer argument and bool value true if
// the object present,false otherwise 
// Preconditions: None
// Postconditions: None
//-------------------------------------------------------------------------------------------------
bool BinTree:: retrieveHelper(Node *&rootNode, NodeData &findThisNode, NodeData *value) const
{

	if (rootNode == nullptr)
	{
		//value not found
	 	value = nullptr;
	 	return false;
	 }

	else if ( *(rootNode->data) == findThisNode)
	{
		//value found 
		value = &findThisNode;
		return true;
	}
	
	else if (findThisNode < *rootNode->data)
	{
		//check in the left subtree
		return retrieveHelper(rootNode->left, findThisNode, value);
	}

	else
	{	
		//check in the rightsubtrr
		return retrieveHelper(rootNode->right, findThisNode, value);

	}

}


//--------------------------------- inorder -------------------------------------------------
// Description: inorder traversal of the BinTree by calling helper method
// Preconditions: None
// Postconditions: the ostream object will initialize with BinTree data values
//-------------------------------------------------------------------------------------------------
void BinTree::inorder(ostream &outStream)
{
	BinTree::Node * current = root;
	inorderHelper(current, outStream);

}

//--------------------------------- inorderHelper -------------------------------------------------
// Description: inorder traversal of the BinTree 
// Preconditions: None
// Postconditions: the ostream object will initialize with BinTree data values
//-------------------------------------------------------------------------------------------------
void BinTree::inorderHelper(Node *current,ostream &outStream) 
{
	if(current != nullptr)
	{
		inorderHelper(current->left, outStream);

		//get the data values
		outStream << *(current->data) << " ";
		inorderHelper(current->right, outStream);

	}

}

//--------------------------------- getHeight -------------------------------------------------
// Description: callls helper method and returns the height of a particular NodeData object 
//if the object present, zero otherwise;
// Preconditions: None
// Postconditions: None
//-------------------------------------------------------------------------------------------------
int BinTree:: getHeight(const NodeData &dataAtHeight) const
{

	return getHeightHelper(root, dataAtHeight, 1);

}

//--------------------------------- getHeightHelper -------------------------------------------------
// Description: callls helper method and returns the height of a particular NodeData object 
//if the object present, zero otherwise;//the height of a node at a leaf is 1, height of a 
//node at the next level is 2, and so on. The height of a value not found is zero.
// Preconditions: None
// Postconditions: None
//-------------------------------------------------------------------------------------------------
int BinTree::getHeightHelper (Node *root, const NodeData &dataAtHeight, int height)const
{
	if(root == nullptr)
	{
		return 0;

	}
	 if(*root->data == dataAtHeight)
	 {
	 	return height;

	 }

	 //go to the left part of the tree
	 int level = getHeightHelper(root->left, dataAtHeight, height+ 1);
		
	if(level != 0 ) 
		{
			return level;
		}
		
	//go to the right subtree
	return getHeightHelper(root->right, dataAtHeight, height + 1);
	
}


//--------------------------------- bstreeToArray -------------------------------------------------
// Description: function to fill an array of Nodedata* by using an inorder traversal of the
//tree. It leaves the BinTree empty. it calls a helper function to do so
// Pre: none
//Post: the tree will be empty
//-------------------------------------------------------------------------------------------------
void BinTree::bstreeToArray(NodeData* theArray[])
{
	
	bstreeToArrayHelper(root , theArray);

	this->makeEmpty();

}

//--------------------------------- bstreeToArrayHeler -----------------------------------------------
// Description: function to fill an array of Nodedata* by using an inorder traversal of the
//tree. It leaves the BinTree empty.
// Pre: none
//Post: the tree will be empty
//-------------------------------------------------------------------------------------------------
int BinTree::bstreeToArrayHelper(Node *current, NodeData *theArray[])
{

	
		if(current == nullptr)
		{
			return 0;

		}
		
		int left = bstreeToArrayHelper(current->left, theArray) ;
		
		NodeData *data = current->data;
		current->data = nullptr;

		//fill the array with data pointer
		*(theArray + left) = data;
		data = nullptr;

		int right = bstreeToArrayHelper(current->right, theArray + left +1);

		//return position for the array to insert data values
		return left + right + 1;
}

//------------------------------------- arrayToBSTree --------------------------------------------
//Description: calls a helper function that builds a balanced BinTree from a sorted array of NodeData*
//leaving the array filled with NULLs.
//pre:none
//Post: the array will be empty(point to NULLS)
//--------------------------------------------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData* theArray[])
{
	
	int lastIndex = 0;
	this->makeEmpty();
	//determining how many non-NULL value are in the array
	while(theArray [lastIndex] != nullptr )
	{
		lastIndex++;

	}


	root = arrayToBSTreeHelper(theArray, 0, lastIndex - 1 );

	//set the array to NULL
	for(int i = 0; i < lastIndex; i++)
	{
		theArray[i] = nullptr;
	}

}


//------------------------------------- arrayToBSTreeHelper --------------------------------------------
//Description: function to builds a balanced BinTree from a sorted array of NodeData*
//leaving the array filled with NULLs.
//pre:none
//Post: the array will be empty(point to NULLS)
//--------------------------------------------------------------------------------------------------
BinTree::Node* BinTree::arrayToBSTreeHelper(NodeData *theArray[], int lowerIndex, int lastIndex)
{

	if(lowerIndex > lastIndex)
	{
		
		return nullptr ;
	}
	
	//get the mid index for each array
	int mid = (lowerIndex + lastIndex) /2;

	//construct a pointer to NodeData object from the value at theArray[mid]
	NodeData *newItem = new NodeData(*theArray[mid]);
	
	//creat Node pointer that its data pointer points to newItem 
	Node *root = new Node;
	root->data = newItem;

	//fill the left subtree with values from index 0 to the mid-1
	root->left = arrayToBSTreeHelper(theArray, lowerIndex, mid- 1 );

	//fill the right subtree with values from index mid +1 to lastIndex
	root->right = arrayToBSTreeHelper(theArray,mid+1, lastIndex );
	
	//return the root pointer
	return root;
}


//------------------------- displaySideways -------------------------------------------
//Description:displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
//-------------------------------------------------------------------------------------------
void BinTree::displaySideways() const 
{
	sideways(root, 0);
}


//---------------------------- Sideways ----------------------------------------------------
// Description: Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
//--------------------------------------------------------------------------------------------
void BinTree::sideways(Node* current, int level) const
 {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}


//------------------------- operator << --------------- ---------------------------------
// Description: calls the inoredr() method to initialize the ostream object with the BinTree contents
//by traversing inorder, and return the ostream object
// Preconditions: NONE
// Postconditions: BinTree remains unchanged and the ostream object contains the BinTree values.
//------------------------------------------------------------------------------------------
ostream&  operator <<(ostream &outStream, BinTree &tree)
{
	

	if(tree.root != nullptr)
	{	
		//call inorder ()function
		tree.inorder(outStream);

	}
	
	return outStream;


}


//--------------------------------- operator >> --------------------- ---------------------------------
// Description: overloads >> operator to take NodeData objects from a text data and call
// the insert() method to to buld the BinTree, and returns the istream object
// Preconditions: lines should ende with $$ and each string should be space separated
// Postconditions: BinTree contains the text files as its data members. The istream object
//------------------------------------------------------------------------------------------------------
istream& operator>>(istream &iStream, BinTree &tree)
{

	string data = "";
	while(data != "$$")
	{
		//take each lines word by word
		iStream >> data;

		//construct NodeData object from the string
		 NodeData nodes(data);

		 //call inseert to build the BinTree from the NOdeData object
		tree.insert(&nodes);

	}
	return iStream;

}
