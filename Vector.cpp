#include <iostream>
#include <cassert>
using namespace std;

class Vector
{
private:
    int *arr{nullptr};
    int size{0};
    int capacity{};

    void expand_capacity()
    {
        capacity *= 2;
        int *arr2 = new int[capacity]{};
        for (int i = 0; i < size; ++i)
            arr2[i] = arr[i];
        swap(arr, arr2);
        delete[] arr2;
    }

public:
    Vector(int size) : size(size)
    {
        if (size < 0)
            size = 1;
        capacity = size + 10;
        arr = new int[capacity]{};
    }

    int get_size()
    {
        return size;
    }

    int get(int idx)
    {
        return arr[idx];
    }

    void set(int idx, int val)
    {
        arr[idx] = val;
    }

    void print()
    {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }

    int find(int value)
    {
        for (int i = 0; i < size; ++i)
            if (arr[i] == value)
                return i;
        return -1;
    }

    int get_front()
    {
        return arr[0];
    }

    int get_back()
    {
        return arr[size - 1];
    }

    void push_back(int value)
    {
        if (size == capacity)
            expand_capacity();
        arr[size++] = value;
    }

    void insert(int idx, int value)
    {
        assert(0 <= idx && idx < size);

        if (size == capacity)
            expand_capacity();

        for (int p = size - 1; p >= idx; --p)
            arr[p + 1] = arr[p];

        arr[idx] = value;
        ++size;
    }

    ~Vector()
    {
        delete[] arr;
        arr = nullptr;
    }
};

int main()
{

    int n = 6;
    Vector v(n);
    for (int i = 0; i < n; ++i)
        v.set(i, i);

    v.insert(0, 66);
    v.print();
    v.insert(2, 1);
    v.print();

    return 0;
}
