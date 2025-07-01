// DSA Assignment Solution in C++
// Name: Geetanjali Awasthi 
// Sample Input: [1, 2, 3, 4, 5, 6]

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Build tree from level-order input
Node* buildTree(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* current = q.front(); q.pop();

        if (i < arr.size()) {
            current->left = new Node(arr[i++]);
            q.push(current->left);
        }
        if (i < arr.size()) {
            current->right = new Node(arr[i++]);
            q.push(current->right);
        }
    }

    return root;
}

// Traversals
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front(); q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

// Height
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Count nodes
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaf nodes
int countLeafNodes(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Check if full tree
bool isFullTree(Node* root) {
    if (!root) return true;
    if ((root->left == nullptr) != (root->right == nullptr)) return false;
    return isFullTree(root->left) && isFullTree(root->right);
}

// Check if perfect tree
int calculateDepth(Node* node) {
    int d = 0;
    while (node) {
        d++;
        node = node->left;
    }
    return d;
}

bool isPerfectTree(Node* root, int depth, int level = 0) {
    if (!root) return true;
    if (!root->left && !root->right) return depth == level + 1;
    if (!root->left || !root->right) return false;
    return isPerfectTree(root->left, depth, level + 1) && isPerfectTree(root->right, depth, level + 1);
}

// Check if complete tree
bool isCompleteTree(Node* root) {
    if (!root) return true;
    queue<Node*> q;
    q.push(root);
    bool end = false;
    while (!q.empty()) {
        Node* current = q.front(); q.pop();
        if (!current) {
            end = true;
        } else {
            if (end) return false;
            q.push(current->left);
            q.push(current->right);
        }
    }
    return true;
}

int main() {
    // Sample input
    vector<int> levelOrderInput = {1, 2, 3, 4, 5, 6};
    Node* root = buildTree(levelOrderInput);

    cout << "Inorder: ";
    inorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\nLevel-order: ";
    levelOrder(root);

    cout << "\nHeight: " << height(root);
    cout << "\nTotal Nodes: " << countNodes(root);
    cout << "\nLeaf Nodes: " << countLeafNodes(root);

    cout << "\nFull Tree: " << (isFullTree(root) ? "Yes" : "No");
    cout << "\nPerfect Tree: " << (isPerfectTree(root, calculateDepth(root)) ? "Yes" : "No");
    cout << "\nComplete Tree: " << (isCompleteTree(root) ? "Yes" : "No") << endl;

    return 0;
}
