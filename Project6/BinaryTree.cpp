#include "BinaryTree.h"
#include "file.h"
#include "rbTree.h"

BinaryTree::node::node(char *a, int b) {
	value.first = new char[20];
	for (int i = 0; i < 20; i++) {
		value.first[i] = a[i];
	}

	value.second = b;
	left_node = nullptr;
	right_node = nullptr;
}

BinaryTree::node::~node() {
	delete left_node;
	delete right_node;
}

BinaryTree::BinaryTree() {
	root = nullptr;
}

void BinaryTree::add_node(char *ch, int k) {
	node *cur = root;
	if (cur == nullptr) {
		root = new node(ch, k);
	} else {
		while (cur->left_node != nullptr || cur->right_node != nullptr) {
            if (file::cmp(ch , cur->value.first) > 0)
                if (cur->right_node != nullptr)
                    cur = cur->right_node;
                else
                    break;
            else
                if (cur->left_node != nullptr)
                    cur = cur->left_node;
                else
                    break;
        }
        if (file::cmp(ch, cur->value.first) > 0)
            cur->right_node = new node(ch, k);
        else
            cur->left_node = new node(ch, k);

		}
	}


	BinaryTree::node *BinaryTree::FindMin(node *r) {
		if (r->left_node == nullptr && r->right_node == nullptr)
			return r;

		if (r != nullptr)
			while (r->left_node != nullptr) {
				r = r->left_node;
			}
		return r;
	}


	void BinaryTree::print(node *n, string rpref, string cpref, string lpref) {
		string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-", ch_ddia_hor = "/-", ch_ver_spa = "| ";
		if (!n) return;
		if (n->right_node)
			print(n->right_node, rpref + "  ", rpref + ch_ddia_hor, rpref + ch_ver_spa);
		string ss;
		for (int i = 0; i < 20; i++) {
			ss.push_back(n->value.first[i]);
		}
		cout << cpref << ss << endl;
		if (n->left_node)
			print(n->left_node, lpref + ch_ver_spa, lpref + ch_udia_hor, lpref + "  ");
	}


	void BinaryTree::searchKey(node *&curr, char *key, node *&parent) {

		while (curr != nullptr && file::cmp(curr->value.first, key)) {
			parent = curr;
			if (file::cmp(key, curr->value.first) < 0) {
				curr = curr->left_node;
			} else {
				curr = curr->right_node;
			}
		}
	}

	void BinaryTree::constuct(string filename) {
		int n = file::getCountLineBin(filename);
		for (int i = 0; i < n; i++) {
			factory f;
			file::getDataBin(filename, i, f);
			this->add_node(f.name, i);
		}
	}

	void BinaryTree::del_key(node *&st, char *key) {
		node *parent = nullptr;


		node *curr = st;


		searchKey(curr, key, parent);


		if (curr == nullptr) {
			return;
		}

		if (curr->left_node == nullptr && curr->right_node == nullptr) {

			if (curr != root) {
				if (parent->left_node == curr) {
					parent->left_node = nullptr;
				} else {
					parent->right_node = nullptr;
				}
			} else {
				st = nullptr;
			}
			delete curr;
		} else if (curr->left_node && curr->right_node) {
			node *successor;
			if (curr->right_node != nullptr)
				successor = FindMin(curr->right_node);
			else
				successor = FindMin(curr->left_node);

			pair<char *, int> val = successor->value;


			del_key(st, successor->value.first);

			curr->value = val;
		} else {
			node *child = (curr->left_node) ? curr->left_node : curr->right_node;
			if (curr != root) {
				if (curr == parent->left_node) {
					parent->left_node = child;
				} else {
					parent->right_node = child;
				}
			} else {
				root = child;
			}
		}
	}

