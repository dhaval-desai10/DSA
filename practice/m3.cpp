// // Decimal to Binary
// #include <iostream>
// #include <string>
// using namespace std;

// string decimalToBinary(int n) {
//     string binary = "";
//     if (n == 0) return "0";
//     while (n > 0) {
//         binary = char('0' + n % 2) + binary;
//         n /= 2;
//     }
//     return binary;
// }

// // Binary to Decimal

// int binaryToDecimal(const string& binary) {
//     int decimal = 0;
//     for (char c : binary) {
//         decimal = decimal * 2 + (c - '0');
//     }
//     return decimal;
// }

// int main() {
//     int dec = 13;
//     string bin = "1101";
//     cout << "Decimal " << dec << " to Binary: " << decimalToBinary(dec) << endl;
//     cout << "Binary " << bin << " to Decimal: " << binaryToDecimal(bin) << endl;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

// binary tree we taraversal through root to leaf node and print all path 
// how i can traverse through root to leaf node and print all path in binary tree

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// Function to collect all root-to-leaf paths as strings
void collectRootToLeafPaths(TreeNode* root, vector<int>& path, vector<string>& allPaths) {
    if (!root) return;
    path.push_back(root->val);
    if (!root->left && !root->right) {
        // Convert path to string
        stringstream ss;
        for (size_t i = 0; i < path.size(); ++i) {
            ss << path[i];
            if (i != path.size() - 1) ss << " -> ";
        }
        allPaths.push_back(ss.str());
    } else {
        collectRootToLeafPaths(root->left, path, allPaths);
        collectRootToLeafPaths(root->right, path, allPaths);
    }
    path.pop_back();
}



int main() {
    // Example binary tree:
    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);


    vector<int> path;
    vector<string> allPaths;
    collectRootToLeafPaths(root, path, allPaths);
    cout << "All root-to-leaf paths in the binary tree as strings:\n";
    for (const string& s : allPaths) {
        cout << s << endl;
    }

    // Clean up memory (not strictly necessary for short-lived demo)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;
    return 0;
}