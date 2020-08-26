#include "BSTY.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

BSTY::BSTY() {
	root = NULL;
}

// You write:  insert a new node with data x (a string) into the 
// binary search tree
// This method should return true if a new node is inserted and 
// false if the data x is already in the tree
// Remember to check whether the new node will be the root
// (meaning the root is currently NULL) and if so, set the root
// to be the new node.
// Note: Make sure you make the new node point to its parent!!! 
// Note2: after you've inserted a new node, you should call the 
// adjustHeights method that will update the heights of all the 
// ancestors of the node that was just inserted.
bool BSTY:: insertit(string x) {
	NodeT *tempNode = new NodeT("");		//creates a temporary node to iterate through the tree
	NodeT *newNode = new NodeT(x);			//this node is filled with the data, allows us to alter the location of 'x' in relation to the temporary node
	if(root == NULL){						//if the root node doesn't exist
		root = newNode;					//then the tree must be empty and therefore the new node will be added at the root
	}
	else{
		tempNode = root;					//starts the temp node at the top of the tree
		while(tempNode != NULL){			//while the node exists (allows us to iterate through the tree)
			if(tempNode->data > newNode->data){		//this is what will check the left side of the tree
				if(tempNode->left == NULL){			//if there is no longer a child on the left side of the node
					tempNode->left = newNode;		//the left child is set to the new node
					newNode->parent = tempNode;		//links the data together, making it so the new node has a parent in the tree
					adjustHeights(newNode);
					checkBalance(newNode);
					adjustHeights(newNode);
					return true;
				}
				else{
					tempNode = tempNode->left;		//this iterates through the tree
				}
			}
			else if(tempNode->data < newNode->data){	//this is what will check the right side of the tree
				if(tempNode->right == NULL){			//if there is no longer a child on the right side of the node
					tempNode->right = newNode;			//the right child is set to the new node
					newNode->parent = tempNode;			//links the data together, making it so the new node has a parent in the tree
					adjustHeights(newNode);
					checkBalance(newNode);
					adjustHeights(newNode);
					return true;
				}
				else{
					tempNode = tempNode->right;		//this iterates through the tree
				}
			}
			else{
				return false;
			}
		}
	}
	return false;
}

//This insertit is where we added in the definition parameter
bool BSTY:: insertit(string x, string y) {
	NodeT *tempNode = new NodeT("", "");		//creates a temporary node to iterate through the tree
	NodeT *newNode = new NodeT(x, y);			//this node is filled with the data, allows us to alter the location of 'x' in relation to the temporary node
	if(root == NULL){						//if the root node doesn't exist
		root = newNode;					//then the tree must be empty and therefore the new node will be added at the root
	}
	else{
		tempNode = root;					//starts the temp node at the top of the tree
		while(tempNode != NULL){			//while the node exists (allows us to iterate through the tree)
			if(tempNode->data > newNode->data){		//this is what will check the left side of the tree
				if(tempNode->left == NULL){			//if there is no longer a child on the left side of the node
					tempNode->left = newNode;		//the left child is set to the new node
					newNode->parent = tempNode;		//links the data together, making it so the new node has a parent in the tree
					adjustHeights(newNode);
					checkBalance(newNode);
					adjustHeights(newNode);
					return true;
				}
				else{
					tempNode = tempNode->left;		//this iterates through the tree
				}
			}
			else if(tempNode->data < newNode->data){	//this is what will check the right side of the tree
				if(tempNode->right == NULL){			//if there is no longer a child on the right side of the node
					tempNode->right = newNode;			//the right child is set to the new node
					newNode->parent = tempNode;			//links the data together, making it so the new node has a parent in the tree
					adjustHeights(newNode);
					checkBalance(newNode);
					adjustHeights(newNode);
					return true;
				}
				else{
					tempNode = tempNode->right;		//this iterates through the tree
				}
			}
			else{
				return false;
			}
		}
	}
	return false;
}

// the adjustHeights method updates the heights of every ancestor of the node n.
// This method will be massively useful with our next lab, so make sure you have 
// this working now.  It should be called whenever you change the height of a 
// a particular node.  So, for instance, when a new node is inserted as a leaf, 
// its height is 1.  The adjustHeights method should then check the parent to see
// if the height of the parent changes (the height of each node is the maximum of 
// the height of the left child and the height of the right child, plus 1).  If 
// the parent's height changes, then the grandparent's height should be checked and,
// if necessary, adjusted.  If the grandparent's height is updated, then the great-
// grandparent's height should be adjusted, etc.  The checking stops when either 
// the loop has worked its way up to the root, or until the currently being checked
// ancestor is not changed.  
void BSTY::adjustHeights(NodeT *n) {
	if(n->left != NULL && n->right != NULL){						//if both children of the node exist, we must consider both heights
		n->height = 1 + max((n->left->height),(n->right->height));	//so we take the max of both heights and add one to it (given formula)
	}
	else if(n->left != NULL){									//if only the left child of the node exists
		n->height = 1 + (n->left->height);						//then we simply add one to the height of the left
	}
	else if(n->right != NULL){									//if only the right child of the node exists
		n->height = 1 + (n->right->height);						//then we simply add one to the height of the right
	}
	if(n->parent != NULL){										//as long as the node has a parent node
		adjustHeights(n->parent);								//we can test this function recursively until we reach the top of the tree
	}

}

void BSTY::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreeIO(root);
	}
}

// Print the tree in order (left child, then parent, then right child).
// Use the slides, but make sure you can understand how the tree is 
// traversed in order
void BSTY::printTreeIO(NodeT *n) {
	if(n == NULL){
		return;
	}
	else{
		printTreeIO(n->left);
		n->printNode();
		printTreeIO(n->right);
	}
}

void BSTY::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePre(root);
	}
}

// Prints the tree using pre-order traversal (parent, then left child, then right
// child.  Use the slides, but make sure you understand how a tree is traversed in
// pre-order
void BSTY::printTreePre(NodeT *n) {
	if(n == NULL){
		return;
	}
	else{
		n->printNode();
		printTreePre(n->left);
		printTreePre(n->right);
	}
}

void BSTY::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePost(root);
		cout << endl;
	}
}

// Prints the tree using pre-order traversal (left child, then right, then parent)
// Use the slides, but make sure you understand how a tree is traversed in
// post-order
void BSTY::printTreePost(NodeT *n) {
	if(n == NULL){
		return;
	}
	else{
		printTreePost(n->left);
		printTreePost(n->right);
		n->printNode();
	}
}
void BSTY::myPrint() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrint(root);
		cout << endl;
	}
}
void BSTY::myPrint(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrint(n->left);
		cout << n->data.length()-1;
		if (mine) {
			cout <<".";
			mine = false;
		}
		myPrint(n->right);
	}
}

// the find method takes as input a string, and finds whether that string is already
// in the tree or not.  If it is in the tree, that node is returned from the tree.
// If it isn't, NULL is returned.  
// NOTE: If the node can't be found, this method prints out that x can't be found.
// if it is found, the printNode method is called for the node.  
NodeT *BSTY::find(string x) {
	NodeT *tempNode = new NodeT("","");		//creates a temporary node to iterate through the tree
	int numcomp = 1;						//A variable that keeps track of the number of comparisons made.
	if(root == NULL){						//if the root node doesn't exist
		return NULL;						//then the tree must be empty and therefore the new node will be added at the root
	}
	else{									//If there is a tree there, it will assign tempnode to be the root.
		tempNode = root;
	}
	while(tempNode != NULL){				//while the node exists (allows us to iterate through the tree)
		if(x == tempNode->data){		//if the data of the temp node is equal to the data given
			cout << numcomp << ": ";
			tempNode->printNode();			//it is already in the tree
			return tempNode;				//so it should be printed and returned
		}
		else if(x < tempNode->data){		//if the data given is less than the temp node's data
			tempNode = tempNode->left;		//then that means the value is on the left side, so we keep moving the temp node in this direction
			numcomp++;
		}
		else if(x > tempNode->data){		//if the data given is greater than the temp node's data
			tempNode = tempNode->right;		//then that means the value is on the right side, so we keep moving the temp node in this direction
			numcomp++;
		}
	}					//after the code has iterated through the entire tree we know for sure it can't be found
	return NULL;							//so we print this and return null
}

NodeT *BSTY::rotateRight(NodeT *n){
	cout << n->data << " must rotate right (" << findBalance(n) << ")" << endl;	//Prints each node and it's balance
	NodeT *m = n->left;									//new node is the input node's left
	m->parent = n->parent; 								//gives both nodes the same parent
	NodeT *tempNode = m->right;							//new node is on the right of m
	n->left = tempNode;									//the left node of the input is the temp node
	//the above statements are all essential to link the nodes together for rotation
	if(n->left != NULL ){								//the left node can't be null or it can't be rotated left
		n->left->parent = n;							//moves n up to a place it can be rotated
	}
	m->right = n;										//m is on the right of n
	n->parent = m;										//n's parent is also m
	if(m->parent != NULL){								//as long as there is a parent of m, or n's parent (at least 3 nodes are required to do a rotation)
		if(m->parent->left == n){						//does some re-adjusting so that n is set to m (left side)
			m->parent->left = m;

		}
		else{											//else m is on the right side
			m->parent->right = m;
		}
	}
	else{												//if there aren't three nodes then we must be at the root
		root = m;
	}
	if(n->left != NULL && n->right != NULL){			//if the right and left nodes exist
		if(n->left->height > n->right->height){			//and the data on the left is larger than the data on the right
			n->height = n->left->height + 1;			//the height gets adjusted to the left's height (higher height)
		}
		else{											//data on the right is larger, height is set to this
			n->height = n->right->height + 1;
		}
	}
	else if(n->left != NULL && n->right == NULL){		//if the right is null, the height must be to the left
		n->height = n->left->height + 1;
	}
	else if(n->left == NULL && n->right != NULL){		//if the left is null, the height must be to the right
		n->height = n->right->height + 1;
	}
	else{												//must be the root if both are null
		n->height = 1;
	}
	if(m->left != NULL){								//the code below essentially does the same as the code above with m instead of n
		if(m->left->height > m->right->height){
			m->height = m->left->height + 1;
		}else{
			m->height = m->right->height + 1;
		}
	}else{
		m->height = m->right->height + 1;
	}
	return m;
}

NodeT *BSTY::rotateLeft(NodeT *n){
	cout << n->data << " must rotate left (" << findBalance(n) << ")" << endl;	//Prints each node and it's balance
	NodeT *m = n->right;									//new node is the input node's right
	m->parent = n->parent; 									//gives both nodes the same parent
	NodeT *tempNode = m->left;								//new node is on the left of m
	n->right = tempNode;									//the right node of the input is the temp node
	//the above statements are all essential to link the nodes together for rotation
	if(n->right != NULL ){									//the right node can't be null or it can't be rotated right
		n->right->parent = n;								//moves n up to a place it can be rotated
	}
	m->left = n;											//m is on the left of n
	n->parent = m;											//n's parent is also m
	if(m->parent != NULL){									//as long as there is a parent of m, or n's parent (at least 3 nodes are required to do a rotation)
		if(m->parent->right == n){							//does some re-adjusting so that n is set to m (right side)
			m->parent->right = m;

		}
		else{												//else m is on the left side
			m->parent->left = m;
		}
	}
	else{													//if there aren't three nodes then we must be at the root
		root = m;
	}
	if(n->left != NULL && n->right != NULL){				//if the right and left nodes exist
		if(n->left->height > n->right->height){				//and the data on the left is larger than the data on the right
			n->height = n->left->height + 1;				//the height gets adjusted to the left's height (higher height)
		}
		else{												//data on the right is larger, height is set to this
			n->height = n->right->height + 1;
		}
	}
	else if(n->left != NULL && n->right == NULL){			//if the right is null, the height must be to the left
		n->height = n->left->height + 1;
	}
	else if(n->left == NULL && n->right != NULL){			//if the left is null, the height must be to the right
		n->height = n->right->height + 1;
	}
	else{													//must be the root if both are null
		n->height = 1;
	}
	if(m->right != NULL){									//the code below essentially does the same as the code above with m instead of n
		if(m->left->height > m->right->height){
			m->height = m->left->height + 1;
		}else{
			m->height = m->right->height + 1;
		}
	}else{
		m->height = m->left->height + 1;
	}
	return m;
}


int BSTY::findBalance(NodeT *n){
	int balance = 0;									//we will return the balance of each node
	if(n->left != NULL && n->right != NULL){			//both nodes exist
		balance = n->left->height - n->right->height;	//balance = left - right
	}
	else if(n->left != NULL){							//left node exists
		balance = n->left->height;						//balance = left - 0
	}
	else if(n->right != NULL){							//right node exists
		balance = -n->right->height;					//balance = 0 - right
	}
	return balance;										//returns balance
}

void BSTY::checkBalance(NodeT *n){
	bool balanced = false;								//we were getting an error where it would balance multiple times when a single node was added, this ensures it only happens once
	if(n != root && n->parent != root){					//grandparent must exist (3 nodes for rotation)
		NodeT *z = n->parent->parent;					//new node as grandparent
		NodeT *y = n->parent;							//new node as parent
		if(y->height <= n->height){						//sometimes the height of the parent node gets messed up, this fixes it
			y->height = n->height + 1;
		}
		while(y != root && balanced == false){			//works way up the tree (y isn't root)
			if(findBalance(z) <= -2){					//Left rotation
				if(findBalance(y) >= 1){				//LR rotation
					//code below is what we figured out was needed to rotate (based off of class slides)
					y = rotateRight(y);
					y = rotateLeft(y->parent);
					z = y->parent;
					balanced = true;
				}
				else{									//LL rotation
					//code below is what we figured out was needed to rotate (based off of class slides)
					y = rotateLeft(z);
					z = y->parent;
					balanced = true;
				}
			}
			else if(findBalance(z) >= 2){				//Right rotation
				if(findBalance(y) >= 1){				//RR rotation
					//code below is what we figured out was needed to rotate (based off of class slides)
					y = rotateRight(z);
					z = y->parent;
					balanced = true;
				}
				else{									//RL rotation
					//code below is what we figured out was needed to rotate (based off of class slides)
					y = rotateLeft(y);
					y = rotateRight(y->parent);
					z = y->parent;
					balanced = true;
				}
			}
			else{										//if the tree has been balanced, we work our way up the tree
				y = z;
				z = z->parent;
			}
		}
	}
}









/*************************************************************************************/
/* Extra Credit Methods                                                              */
/* Challenging: worth 35 EC pts to go towards labs                                   */
/* NOTE: IF YOU CHOOSE NOT TO IMPLEMENT THESE METHODS, YOU ARE STILL RESPONSIBLE FOR */
/* UNDERSTANDING HOW THEY WORK!!                                                     */
/*************************************************************************************/
/* When removing a node from a binary search tree, the resulting tree MUST BE a binary
/* search tree.  
/*
/* When removing a node, there are 3 conditions:
/* 1: when the node being removed has no children, in which case the node is deleted,
/* the node's parent is set to NULL, and the node's parent's height is adjusted (if
/* necessary) and heights on up are adjusted.
/* 2: when the node being removed has one child, in which case the node's parent points
/* to the node's child, and the node's child points to the node's parent, and the node
/* is deleted (and the height of the parent on up as necessary is adjusted)
/* 3: when the node has 2 children, in which case the left-most child of the node's 
/* right child replaces the node.  
/* A couple of notes about this one: you are replacing a node with a node that is lower
/* down in the tree.  That means that you are, in essence, removing the node from that
/* lower position and moving it up to the old node's location.  Thus the replacing node
/* must be removed using 1 or 2 above (why not 3?).  The heights must be adjusted after 
/* the replacing node is removed from its old location but before it is inserted into its 
/* new location.  Equally, the replacing node's height must be adjusted to be the larger of
/* its two children's heights before you adjust heights above that.  
/*****************************************************************************************/
/* remove(): takes as input a string, uses the find method to find the node in the tree that
/* holds that string, and then calls replace1, replace2, or replace3 depending on what type
/* of replacing should be done.  It adjusts the heights, deletes teh node, and returns 
/* true if the removal was successful.
*/
bool BSTY::remove(string s) {

}

/* remove1(): called when the node to be removed has no children. Takes as input the 
/* node to be removed, and sets the parent of the node to point to NULL.
/* helpful hint: if (n->parent->left == n) is true, then n is its parent's left child.
/* Make sure you check to whether n is the root or not.
*/
void BSTY::remove1(NodeT *n) {

}

/* remove2(): called when the node to be removed has 1 child only.  Takes as input
/* the node to be removed and bypasses it by making the parent point to the node's
/* one child, and makes the node's one child point to the node's parent.  
/* This one needs a bunch of checking - you need to see if the node is the parent's
/* left or right child, and you need to see if the node's child is its left or its
/* right child.
/* Also, make sure you check that if the node to be removed is the root, then the 
/* one child becomes the root.
*/ 
void BSTY::remove2(NodeT *n) {

}

/* remove3(): called when the node to be removed has 2 children.  Takes as input the
/* node to be removed.  The node to replace the node to be removed should be the 
/* left-most descendent of the node's right child.  That way the binary search tree
/* properties are guaranteed to be maintained.
/* When replacing the node to be removed with the replacing node, the replacing node
/* is, in essence, being removed from its place in the tree, and thus replace1 or 
/* replace2 methods should be used.
/* The new node's parent must be set to the removed node's parent, the removed node's
/* parent must point to the new node, the new node's left child must point to the 
/* removed node's left child (and the child must point to the new node as a parent), 
/* and the same for teh right child.
/* Remember to take into account that the node being removed might be the root.
*/
void BSTY::remove3(NodeT *n) {

}

/* findMin(): takes as input a node, and finds the left-most descendant of its 
/* right child.  The left-most descendent is returned.
*/
NodeT *BSTY::findMin(NodeT *n) {

}

void BSTY::myPrintEC() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrintEC(root);
		cout << endl;
	}
}
void BSTY::myPrintEC(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrintEC(n->left);
		cout << alpha[n->data.length()-2];
		myPrintEC(n->right);
	}
}


/************************************************************************/
