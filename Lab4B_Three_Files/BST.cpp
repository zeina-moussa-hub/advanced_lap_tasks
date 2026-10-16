#include "BST.h"
#include <iostream>
#include <queue>
using namespace std;

Node::Node(int v) : data(v), left(nullptr), right(nullptr) {}
Tree::Tree() { root = nullptr; }
Tree::~Tree() { clear(root); }

Node* Tree::insert(Node* n, int v) {
        if (n == nullptr) return new Node(v);
        if (v < n->data) n->left = insert(n->left, v);
        else if (v > n->data) n->right = insert(n->right, v);
        return n;
    }

bool Tree::search(Node* n, int v) {
        if (n == nullptr) return false;
        if (n->data == v) return true;
        if (v < n->data) return search(n->left, v);
        return search(n->right, v);
    }

Node* Tree::findMin(Node* n) {
        while (n != nullptr && n->left != nullptr) n = n->left;
        return n;
    }

Node* Tree::deleteNode(Node* n, int v) {
        if (n == nullptr) return nullptr;
        if (v < n->data) n->left = deleteNode(n->left, v);
        else if (v > n->data) n->right = deleteNode(n->right, v);
        else {
            if (n->left == nullptr) {
                Node* next = n->right;
                delete n;
                return next;
            }
            if (n->right == nullptr) {
                Node* next = n->left;
                delete n;
                return next;
            }
            Node* next = findMin(n->right);
            n->data = next->data;
            n->right = deleteNode(n->right, next->data);
        }
        return n;
    }

void Tree::inOrder(Node* n) {
        if (n == nullptr) return;
        inOrder(n->left);
        cout << n->data << " ";
        inOrder(n->right);
    }

void Tree::preOrder(Node* n) {
        if (n == nullptr) return;
        cout << n->data << " ";
        preOrder(n->left);
        preOrder(n->right);
    }

int Tree::height(Node* n) {
        if (n == nullptr) return -1;
        int leftHeight = height(n->left);
        int rightHeight = height(n->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }

void Tree::levelOrder() {
        if (root == nullptr) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            cout << n->data << " ";
            if (n->left != nullptr) q.push(n->left);
            if (n->right != nullptr) q.push(n->right);
        }
    }

void Tree::clear(Node* n) {
        if (n == nullptr) return;
        clear(n->left);
        clear(n->right);
        delete n;
    }
