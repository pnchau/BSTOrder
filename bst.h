#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* right;
    Node* left;
};

class BST {
        struct Node {
            int key;
            Node* right;
            Node* left;
        };

        Node* root;

        Node* makeEmpty(Node* node) {
        if(node == NULL)
            return NULL;
        {
            makeEmpty(node->left);
            makeEmpty(node->right);
            delete node;
        }
        return NULL;
        }

        Node* insert(int value, Node* node) {
            if(node == NULL) {
                node = new Node;
                node->key = value;
                node->left = NULL;
                node->right = NULL;
            }
            if(value < node->key) {
                node->left = insert(value, node->left);
            }
            if(value > node->key) {
                node->right = insert(value, node->right);
            }
            return node;
        }
        Node* remove(int value, Node* node) {
            if(node == NULL) {
                return NULL;
            }
            else if(value < node->key) {
                node->left = remove(value, node->left);
            }
            else if(value > node->key) {
                node->right = remove(value, node->right);
            }
            else {
                if(node->left == NULL && node->right == NULL) {
                    delete node;
                    node = NULL;
                }
                else if(node->left == NULL) {
                    struct Node* temp = node;
                    node = node->right;
                    delete temp;
                }
                else if(node->right == NULL) {
                    struct Node* temp = node;
                    node = node->left;
                    delete temp;
                }
                else {
                    Node* temp = min(node->right);
                    node->key = temp->key;
                    node->left = remove(temp->key, node->right);               
                }
            }
            return node;
        }
        Node* min(Node* node) {
            while(node->left != NULL) {
                node = node->left;
            }
            return node;
        }
        void inOrder(Node* node, string& s) const {
            if(node == NULL) {
                return;
            }
            inOrder(node->left, s);
            s += to_string(node->key); s += " ";
            inOrder(node->right, s);
        }

        void preOrder(Node* node, string& s) const {
            if(node == NULL){
                return;
            }
            s += to_string(node->key); s += " ";
            preOrder(node->left, s);
            preOrder(node->right, s);
        }

        void postOrder(Node* node, string& s) const {
            if(node == NULL) {
                return;
            }
            postOrder(node->left, s);
            postOrder(node->right, s);
            s += to_string(node->key); s += " ";
        }
    public:
        BST() { root = NULL; }
        ~BST() {
        root = makeEmpty(root);
        }
        void insert(int num) {
            root = insert(num, root);
        }
        void remove(int num) {
            root = remove(num, root);
        }
        void inOrder(string& nums) {
            inOrder(root, nums);
        }
        void preOrder(string& nums) {
            preOrder(root, nums);
        }
        void postOrder(string& nums) {
            postOrder(root, nums);
        }
};

#endif