#include <iostream>
#include <cassert>
#include <utility>
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

    int pop(int idx){
        int val = arr[size-1];
        arr[size-1] = 0;
        // Shift all the data to left
		for (int i = idx + 1; i < size; ++i)
			arr[i - 1] = arr[i];
        --size;
        return val; 
    }

    void insert(int idx, int value)
    {
        assert(0 <= idx && idx < size);

        if (size == capacity)
            expand_capacity();

        // shift elements right to open space to the new element 
        for (int i = size - 1; i >= idx; --i)
            arr[i + 1] = arr[i];

        arr[idx] = value;
        ++size;
    }

    void delete_in_mid (int idx){
        arr[idx]=0;
        // shift elements to left (1 2 "3" 4 5) -> (1 2 4 5)
        for (int i=idx;i<size;i++)
        {
            arr[i]=arr[i+1];
        }
        --size;
    }

    void right_rotation(){
        int last = arr[size-1];
        for (int i = size-2;i>=0;i--){
            arr[i+1]=arr[i];
        }
        arr[0] = last;
    }

    void left_rotation(){
        int frist = arr[0];
        for (int i= 0;i<size-1;i++){
            arr[i] = arr[i+1];
        }
        arr[size-1]=frist;
    }

    void right_rotation_with_times(int times){
        times %= size;

        while (times--)
        {
            right_rotation();
        }
        
    }

    int imporved_search (int val){
        
        for (int i =0;i<size;i++){
            if (arr[i]==val){
                if (i==0)
                {
                    return 0;
                }else{
                    swap(arr[i],arr[i-1]);
                    return i-1;
                }
                
            }
        }
        return -1;
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
    
/*    
    v.insert(0, 66);
    v.print();
    v.insert(2, 1);
    v.print();
*/

    v.print();
    v.imporved_search(3);
    v.print();

    
    v.print();
    v.right_rotation_with_times(2000001);
    v.print();

    return 0;
}
