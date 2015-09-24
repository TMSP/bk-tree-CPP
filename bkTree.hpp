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

#ifndef BKTREE_HPP
#define BKTREE_HPP

#include "bkNode.hpp"

namespace bk {
	class Bktree {
	public:
		Bktree(std::string newWord, int newDistance);
		~Bktree();
		void mountTree(); 
		void setRoot(std::string newWord);
		Node* getRoot();
		std::vector<std::string> getWordList();
		int searchWords(Node *current, int distance);   /*show all words with distance == root's distance*/
		std::string getRootName();
		void deallocateTree(Node *root);
	private:
		void insert(Node* current, const std::string &newWord);
		void insertWords(Node *current); /*Insert the suggested words in  vector wordList*/
		Node *root;
		std::vector<std::string>wordList; /*vector with all suggested words starting at the root*/
	};
}

#endif
