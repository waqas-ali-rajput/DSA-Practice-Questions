#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int* data;
    int size;
    int capacity;

    void resize(int newCapacity)
    {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 2)
    {
        if (initialCapacity < 1)
        {
            initialCapacity = 1;
        }

        data = new int[initialCapacity];
        size = 0;
        capacity = initialCapacity;
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    void append(int value)
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }

        data[size] = value;
        size++;
    }

    void display() const
    {
        cout << "Array: [";
        for (int i = 0; i < size; i++)
        {
            cout << data[i];
            if (i < size - 1)
            {
                cout << ", ";
            }
        }
        cout << "]\n";
    }

    int getSize() const
    {
        return size;
    }

    int getCapacity() const
    {
        return capacity;
    }
};

int main()
{
    DynamicArray arr(2);
    int values[] = {10, 20, 30, 40, 50, 60, 70};

    for (int i = 0; i < 7; i++)
    {
        cout << "After inserting " << values[i] << ":\n";
        arr.append(values[i]);
        arr.display();
        cout << "Size: " << arr.getSize() << '\n';
        cout << "Capacity: " << arr.getCapacity() << "\n\n";
    }

    return 0;
}
