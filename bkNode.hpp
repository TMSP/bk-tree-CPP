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

#ifndef BKNODE_HPP
#define BKNODE_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Node {
public:
	Node(std::string newWord, int newDistance);
	void setWord(std::string newWord);
	void setDistance(int newDistance);
	int setChildren(std::string newWord, int newDistance);
	std::string getWord();
	int getDistance();
	std::vector<Node*> getChildren();
	Node* getChildrenNode(int newDistance); /*Returns the node using the levenshtein's distance as parameter*/
	Node* getChildrenNodePosition(int position); /*Returns the node using the position as parameter*/
private:
	std::string word;
	int distance;
	std::vector<Node*>children;
};

#endif
