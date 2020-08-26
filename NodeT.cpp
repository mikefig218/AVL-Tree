#include "NodeT.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

NodeT::NodeT(string x) {
	data = x;
	definition = "";
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
}

NodeT::NodeT(string x, string def){
	data = x;
	definition = def;
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;

}

NodeT::~NodeT() {
	if ((left != NULL) || (right != NULL)) {
		cout << "deleting may leave dangling SNodes" << endl;
	}
}

void NodeT::printNode() {
	cout << "|"<<data << ", "<< height <<", " << definition << "|" << endl;
}


