#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {};
};

class Linked_List
{
private:
    Node *Head;
    Node *Tail;
    int length = 0;

public:
    Linked_List(Node *head, Node *tail, int length) : Head(head), Tail(tail), length(length) {}

    int get_length()
    {
        return length;
    }

    void print()
    {
        for (Node *curr = Head; curr; curr = curr->next)
            cout << curr->data << " ";
        cout << "\n";
    }

    void insert_to_end(int value)
    {
        Node *new_node = new Node(value);
        if (!Head)
        {
            Head = Tail = new_node;
        }
        else
        {
            Tail->next = new_node;
            Tail = new_node;
        }
        length++;
    }

    void insert_in_front(int value)
    {
        Node *new_node = new Node(value);
        if (!Head)
        {
            Head = Tail = new_node;
        }
        else
        {
            new_node->next = Head;
            Head = new_node;
        }
        length++;
    }

    Node *get_nth_node(int number)
    {
        if (number > length)
            return nullptr;

        if (number == 1)
            return Head;

        if (number == length)
            return Tail;

        int index = 0;
        for (Node *curr = Head; curr; curr = curr->next)
        {
            if (++index == number)
                return curr;
        }

        return nullptr;
    }
};

int main()
{
    Linked_List gg(nullptr, nullptr, 0);
    gg.insert_to_end(50);
    gg.insert_to_end(51);
    gg.insert_to_end(52);
    gg.insert_to_end(53);

    gg.insert_in_front(200);
    gg.insert_in_front(600);

    gg.print();

    cout << gg.get_length() << endl;

    cout << gg.get_nth_node(2)->data << endl;
}