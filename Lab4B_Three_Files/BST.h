#ifndef BST_H
#define BST_H

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v);
};

class Tree {
public:
    Node* root;
    Tree();
    ~Tree();
    Node* insert(Node* n, int v);
    bool search(Node* n, int v);
    Node* findMin(Node* n);
    Node* deleteNode(Node* n, int v);
    void inOrder(Node* n);
    void preOrder(Node* n);
    int height(Node* n);
    void levelOrder();
private:
    void clear(Node* n);
};

#endif
