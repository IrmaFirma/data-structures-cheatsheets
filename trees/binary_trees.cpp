#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<algorithm> 

using namespace std;

class Node
{
    private:
        int data;           // For practice, using int data
        Node* left;         // Link to left child
        Node* right;        // Link to right child
        Node* parent;       // Link to parent (useful for depth)

    public:
        Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
        int getData() { return this->data; }
        ~Node(); 
        friend class BinaryTree;
};

class BinaryTree
{
    private:
        Node *root;

    public:
        BinaryTree();
        ~BinaryTree();
        Node* getRoot();

        // Core Functions to implement
        void insert(Node* p, int val1, int val2); // Insert logic
        void removeAboveExternal(Node* p);       // Insert logic 
        bool isExternal(Node* p);   // No children
        bool isInternal(Node* p);   // Has at least one child
        int size(Node* p);          // Total nodes in subtree
        int depth(Node* p);         // Distance from root
        int height(Node* p);        // Max distance to a leaf

        // Traversals
        void preorder(Node* p);
        void inorder(Node* p);      // Specific to Binary Trees
        void postorder(Node* p);

    private:
        // Optional: Helper for destructor to delete nodes recursively
        void clear(Node* p);
};

// ==========================================================================
// IMPLEMENTATION STUBS
// ==========================================================================

BinaryTree::BinaryTree() {
    this->root = nullptr;
}

BinaryTree::~BinaryTree() {
    clear(root);
}

Node* BinaryTree::getRoot() {
    return root;
}

// Recursively delete nodes to prevent memory leaks
void BinaryTree::clear(Node* p) {
    if (p == nullptr) return;
    clear(p->left);
    clear(p->right);
    delete p;
}

// TO-DO: Implement these for your practice
void BinaryTree::insert(Node* p, int val1, int val2) { // expand external
    Node* x = p;
    x->left = new Node(val1);
    x->left->parent = x;
    x->right = new Node(val2);
    x->right->parent = x;
}

void BinaryTree::removeAboveExternal(Node* p){
    Node* x = p;
    Node* y = p->parent;

    Node* sibling = (x==y->left ? y->right : y->left);

    if(y==root){
        root = sibling;
        sibling->parent = nullptr;
    }
    Node* grandparent = y->parent;
    if(y==grandparent->left) grandparent->left = sibling;
    else grandparent->right = sibling;
    sibling->parent = grandparent;

    delete x;
    delete y;
} 


bool BinaryTree::isExternal(Node* p) {
    if (p==nullptr) return false;
    return (p->left == nullptr && p->right == nullptr);
}

bool BinaryTree::isInternal(Node* p) {
    if(p==nullptr) return false;
    return (p->left != nullptr or p->right != nullptr);
}

int BinaryTree::size(Node* p) {
    if(p==nullptr) return 0;
    int s = 1;
    s += size(p->left);
    s += size(p->right);
    return s;
}

int BinaryTree::depth(Node* p) {
    if(p==nullptr) return -1;
   if(p->parent==nullptr) return 0;
   return 1 + depth(p->parent);
}

int BinaryTree::height(Node* p) {
    if(p==nullptr) return -1;
    if(isExternal(p)) return 0;
    int h = 1 + max(height(p->left), height(p->right));
    return h;
}

void BinaryTree::preorder(Node* p) {
    if(p==nullptr) return;
    cout << p->data << endl;
    preorder(p->left);
    preorder(p->right);
}

void BinaryTree::inorder(Node* p) {
    if(p==nullptr) return;
    inorder(p->left);
    cout << p->data << endl;
    inorder(p->right);
}

void BinaryTree::postorder(Node* p) {
    if(p==nullptr) return;
    postorder(p->left);
    postorder(p->right);
    cout<<p->data;
}

Node::~Node() {
    
}

int main() {
    BinaryTree bt;
    cout << "Binary Tree Practice Initialized." << endl;
    // Add a simple CLI loop here similar to your lab if you'd like to test!
    return 0;
}
