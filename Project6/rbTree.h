#pragma once
#include <cstddef>
#include <string>


using namespace std;

struct node
{
    pair<char*, int> key;
    node* parent;
    char color;
    node* left;
    node* right;
};
class RBtree
{

    node* q;
public:
    node* root;
	RBtree()
    {
        q = NULL;
        root = NULL;
    }
    void insert(pair<char*, int>);
    void insertfix(node*);
    void leftrotate(node*);
    void rightrotate(node*);
    void del(const char*);
    node* successor(node*);
    void delfix(node*);
    void disp();
    void display(node* ,int );
    node* search(const char*);
    void constuct( string filename);
};
