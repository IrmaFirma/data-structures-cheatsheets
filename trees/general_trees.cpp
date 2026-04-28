// Irma Preldzic (ip2557) Lab 8
#ifndef TREE_HPP
#define TREE_HPP
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<vector>
using namespace std;

class Node
{
	private:
		string name;				//name of the Node
		vector<Node*> children;		//Children of Node
		Node* parent; 				//link to the parent 

	public:
		Node(string name, Node* parent = nullptr) : name(name), parent(parent)
		{ }
		string getName()
		{
			return this->name;
		}
		~Node();
		friend class Tree;
};
//==========================================================
class Tree
{
	private:
		Node *root;				//root of the Tree
		Node *curr_Node;			//current Node
		
	public:	
		//Methods that are part of the starter-code	
		Tree();	
		~Tree();
		Node* getRoot();
		Node* getCurrentNode();
		void cd(string name);
		void print();			//Print entire tree
	private:	//Helper methods
		void print_helper(string padding, string pointer,Node *node);
		bool isLastChild(Node *ptr);
	public:
		//Required Methods
		void add(Node* parent,string child_name);
		void remove(Node* parent,string child_name);
		bool isExternal(Node* node);
		bool isInternal(Node* node);
		int size(Node* node);
		int depth(Node* node);
		int height(Node *node);
		int treeHeight();
		void preorder(Node *node);
		void postorder(Node *node);
	public:
		/* Required for Autograder — Do not remove or implement */
		void display2(stringstream&, Node*);
};
//========================================================================
Tree::Tree()
{
	this->root = new Node("root");
	this->curr_Node = this->root;
}
Tree::~Tree()
{
	delete this->root;
}
//========================================================================
Node* Tree::getRoot()
{
	return root;
}
//========================================================================
Node* Tree::getCurrentNode()
{
	return curr_Node;
}
//========================================================================
void Tree::cd(string name)
{
	if(name=="..")
	{
		if(curr_Node!=root)	curr_Node = curr_Node->parent;
	}
	else
	{
		for(int i=0; i<curr_Node->children.size(); i++)
			if(name == curr_Node->children[i]->name)
			{
				curr_Node = curr_Node->children[i];						//update current working directory
				return;
			}

		cout<<name<<": child not found"<<endl;
	}
}
//==========================================================================
void Tree::print()
{
	print_helper("","",root);
}
//==========================================================================
void Tree::print_helper(string padding, string pointer,Node *node)
{
    if (node != nullptr) 
    {
        if(node == curr_Node)	//print current Node in blue color
        	cout <<padding<<pointer<<"\x1B[33m"<<node->name<<"\x1B[0m"<<endl;
        else 
        	cout <<padding<<pointer<<node->name<<endl;

		if(node!=root)	padding+=(isLastChild(node)) ? "   " : "│  ";


        for(int i=0; i<node->children.size(); i++)
		{
			string marker = isLastChild(node->children[i]) ? "└──" : "├──";
			print_helper(padding,marker, node->children[i]);

		}
    }
}
//==========================================================================
bool Tree::isLastChild(Node *ptr)
{
	if(ptr!=root and ptr == ptr->parent->children[ptr->parent->children.size()-1])
		return true;
	return false;
}
//==========================================================================
// Implement/define required methods below this line

// method to check if the current node is a leaf
bool Tree::isExternal(Node* node){
	// if the current node is a leaf its children vector
	// should be empty or size 0
	if(node == nullptr) return false;
	return (node->children.size() == 0);
}

// method to check if the current node is an internal node
bool Tree::isInternal(Node* node){
	// if the current node is not a leaf its children vector
	// should NOT be empty
	if(node == nullptr) return false;
	return (node->children.size() != 0);
}

// method to get the size of the entire tree -> # of nodes
int Tree::size(Node* node){
	if(node==nullptr) return 0;
	//set size variable to 1 (count current)
	int s = 1;
	// go through all children 
	vector<Node*>& ch = node->children;
	for(int i = 0; i<ch.size(); i++){
	// recursively increase size value by calling size on current Node
		s += size(ch[i]);
	}
	return s;
}

// method to get the depth of the current node -> distance from root
int Tree::depth(Node* node){
	if(node == nullptr) throw runtime_error("Node nullptr.");
	// root has depth of 0 always
	if(node == root) return 0;
	// else recursively call depth on node's parent 
	return 1 + depth(node->parent);
}

// method to get the height of the current node
int Tree::height(Node *node){
	if(node == nullptr) throw runtime_error("Node nullptr.");
	// leaves have a default height of 0
	if (isExternal(node)) return 0;
	// initialize height variable
	int h = 0;
	vector<Node*>& ch = node->children;
	// go through children of the node
	for(int i = 0; i<ch.size(); i++){
	// recursively call height on current node
		h = max(h, height(ch[i]));
	}
	return 1 + h;
}

// height of the entire tree is the height of the root
int Tree::treeHeight(){
	return height(root);
}

// method to print elements in preorder
// root -> children 
void Tree::preorder(Node *node){
	if(node == nullptr) return;
	// perform visit action on curr_node first
	cout << node->name << " ";
	vector<Node*>& ch = node->children;
	// go through its children recursively
	for(int i = 0; i<ch.size(); i++){
		preorder(ch[i]);
	}
}

// method to print elements in postorder
// children -> root
void Tree::postorder(Node *node){
	if(node == nullptr) return;
	// go through all children
	vector<Node*>& ch = node->children;
	for(int i = 0; i<ch.size(); i++){
		postorder(ch[i]);
	}
	// come back up and perform visit action on parent
	cout << node->name << " ";
}

// remove child with specified name
void Tree::remove(Node* parent,string child_name){
	if(parent == nullptr) return;
	vector<Node*>& ch = parent->children;
	// go through all the children and erase if name matches
	for(int i = 0; i<ch.size(); i++){
		if(ch[i]->name == child_name){
			Node* deleted = ch[i];
			// takes in iterator as parameter
			ch.erase(ch.begin() + i);
			delete deleted;
			return;
		}
	}
	// child with the specified name DNE
	cout << "child not found." << endl;
}

// insert new child node under specified parent
void Tree::add(Node* parent,string child_name){
	if(parent==nullptr) return;

	// go through all the children to check if child
	// with specified name already exists
	vector<Node*>& ch = parent->children;
	for(int i = 0; i<ch.size(); i++){
		if(ch[i]->name == child_name){
			cout << "child already exists." <<endl;
			return;
		}
	}

	// create new Node and push back to children list
	Node* x = new Node(child_name);
	x->parent = parent;
	ch.push_back(x);
}

// destructor for Node class
Node::~Node(){
	// remove all children of curr_node
	for(int i = 0; i<children.size(); i++){
		delete children[i];
	}
}

//Do not write any code below this line
//==========================================================================
#endif
