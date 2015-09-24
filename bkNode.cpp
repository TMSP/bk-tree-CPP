/*The MIT License (MIT)

Copyright (c) 2015 Tiago Meira Silva Pinto

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#include "bkNode.hpp"
//#include "constants.hpp"

static const int OK =  1;
static const int ERROR = -1;

Node::Node(std::string newWord, int newDistance) {
	word = newWord;
	distance = newDistance;
}

void Node::setWord(std::string newWord) {
	word = newWord;
}

void Node::setDistance(int newDistance) {
	distance = newDistance;
}

int Node::setChildren(std::string newWord, int newDistance) {
	/*run throughtout the children vector, in case  there is one
	  children with the same distance, returns ERROR*/
	for(auto &it : children) {
		if(newDistance == it->distance) {
			return ERROR;
		}
	}
	/*Allocate a new children node and insert it in the vector, returns OK*/
	Node *newNode = new Node(newWord, newDistance);
	children.push_back(newNode);
	
	return OK;
}

std::string Node::getWord() {
	return word;
}

int Node::getDistance() {
	return distance;
}

Node* Node::getChildrenNode(int newDistance) {
	/*Returns the children node inside the vector at the position given by the
	  levenshtein distance. This is used to know which children node returned ERROR
	  at the insertion of a new node, and insert it as a children of this node*/
	int position = 0;

	for(auto &it : children) {
		if(it->distance == newDistance) {
			return children[position];
		}
		position++;
	}
}

Node* Node::getChildrenNodePosition(int position) {
	if(position <= children.size()) {
		return children[position];	
	}
}

std::vector<Node*> Node::getChildren() {
	return children;
}
