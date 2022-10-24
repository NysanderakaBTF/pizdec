#pragma once

#include <utility>
#include <iostream>

using namespace std;

class BinaryTree {
protected:
	class node {
	public:
		node *left_node;
		node *right_node;
		pair<char *, int> value;

		node(char *a, int b = 0);

		~node();
	};

public:
	node *root;

	BinaryTree();

	void add_node(char *ch, int k);

	node *FindMin(node *root);

	void print(node *n, string rpref = "", string cpref = "", string lpref = "");

	void del_key(node *&st, char *key);

	void searchKey(node *&curr, char *key, node *&parent);

	void constuct(string filename);
};
