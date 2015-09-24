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

#include "bkTree.hpp"
#include "levenshtein.hpp"
//#include "constants.hpp"

static const int OK =  1;
static const int ERROR = -1;

bk::Bktree::Bktree(std::string newWord, int newDistance) {
	root = new Node(newWord, newDistance);
}

Node* bk::Bktree::getRoot() {
	return root;
}

std::vector<std::string> bk::Bktree::getWordList() {
	return wordList;
}

void bk::Bktree::setRoot(std::string newWord) {
	root->setWord(newWord);
}

void bk::Bktree::insert(Node* current, const std::string &newWord) {
	/*The levenshteinDistance function is in levenshtein.hpp but it's not included in
	  my repository because it's a public code, you can search it very easily*/
	int result = levenshtein::levenshteinDistance(current->getWord(), newWord);

	/*Insert words with levenshtein distance <= 4*/
	if(result <= 4) {
		 /*ERROR: in case you try to insert a children where there is already
		   a word with the same distance, in this case you make a recursive call
		   to insert this node as the children of the node with the same distance*/
		if(current->setChildren(newWord, result) == ERROR) {
			insert(current->getChildrenNode(result), newWord);
		}
	}
}

void bk::Bktree::mountTree() {
	/*The tree is feeded with words from a dictionary, you can create a .txt file with the words you
	  want to use to mount the tree, or change this method the way you prefer*/
	std::ifstream input("dictionary.txt");

	/*Open the file with the words to feed the tree*/
	for(std::string line; getline(input, line); ) {
		insert(root, line);
	}
}

void bk::Bktree::insertWords(Node *current) {
	/*wordlist is the vector containing all the words from the root with distance defined at searchWords() method*/
	wordList.push_back(current->getWord());
	
	if(current->getChildren().size() == 0) {
		return;
	}
	for(int i = 0; i < current->getChildren().size(); i++) {
		insertWords(current->getChildrenNodePosition(i));
	}
}

int bk::Bktree::searchWords(Node *current, int distance) {
	
	/*Search all the childrens from the current node, searching the one with distance == distance on this method's parameter list.
	  When you find it calls the insertWords() method where it's going to feed the vector, returns ERROR in case the distance from the
	  parameter list is different from the one you wanted*/
	for(int i = 0; i < current->getChildren().size(); i++) {
		if(current->getChildrenNodePosition(i)->getDistance() == distance) {
			insertWords(current->getChildrenNodePosition(i));
			return OK;
		}
	}
	return ERROR;
}

void bk::Bktree::deallocateTree(Node* root) {
	if(root->getChildren().size() == 0) {
		delete root;
		return;
	}
	for(int i = 0; i < root->getChildren().size(); i++) {
		 deallocateTree(root->getChildrenNodePosition(i));
	}
}

std::string bk::Bktree::getRootName() {
	return root->getWord();
}

bk::Bktree::~Bktree() {
	deallocateTree(root);
}
