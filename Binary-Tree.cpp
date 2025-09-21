#include <algorithm>
#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *right;
    Node *left;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void print_inorder(Node *curr)
{
    if (!curr) return;
    print_inorder(curr->left);
    cout << curr->val;
    print_inorder(curr->right);
}

void print_pre_order(Node *curr){
    if (!curr) return;
    cout << curr->val;
    print_inorder(curr->left);
    print_inorder(curr->right);
}

void print_post_order(Node *curr){
    if (!curr) return;
    print_inorder(curr->left);
    print_inorder(curr->right);
    cout << curr->val;
}



int main()
{

    Node *ch_left = new Node(2);
    ch_left->left = new Node(1);
    ch_left->right = new Node(3);
    
    
    Node *ch_right = new Node(6);
    ch_right->left = new Node(5);
    ch_right->right = new Node(7);


    Node *root = new Node(4);
    root->left= ch_left;
    root->right = ch_right;


    print_inorder(root);
    cout << endl;
    print_pre_order(root);
    cout << endl;
    print_post_order(root);
    cout << endl;




    
    return 0;
}
