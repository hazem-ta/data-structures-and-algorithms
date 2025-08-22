#include <iostream>
using namespace std;

struct Node
{
    char val;
    Node *right;
    Node *left;

    Node(char v) : val(v), left(nullptr), right(nullptr) {}
};

void print_order(Node *currnt)
{
    if (!currnt)
        return;
    print_order(currnt->left);
    cout << currnt->val;
    print_order(currnt->right);
}

int main()
{
    Node *plus = new Node('+');
    plus->left = new Node('2');
    plus->right = new Node('6');

    Node *div = new Node('/');
    div->left = new Node('8');
    div->right = new Node('4');

    // (9 + (8 / 4))
    Node *minus = new Node('+');
    minus->left = new Node('9');
    minus->right = div;

    // ((2 + 6) * (9 + (8 / 4)))
    Node *multiply = new Node('*');
    multiply->left = plus;
    multiply->right = minus;
 
    // It must be 2+6*9+8/4
    print_order(multiply);
    cout << endl;
    return 0;
}
