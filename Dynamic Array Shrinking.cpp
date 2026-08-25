#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int* data;
    int size;
    int capacity;
    int initialCapacity;

    void resize(int newCapacity)
    {
        if (newCapacity < initialCapacity)
        {
            newCapacity = initialCapacity;
        }

        int* newData = new int[newCapacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;

        cout << "Capacity changed to " << capacity << '\n';
    }

    void shrinkIfNeeded()
    {
        while (capacity > initialCapacity && size <= capacity / 4)
        {
            int newCapacity = capacity / 2;
            if (newCapacity < initialCapacity)
            {
                newCapacity = initialCapacity;
            }

            if (newCapacity == capacity)
            {
                break;
            }

            resize(newCapacity);
        }
    }

public:
    DynamicArray(int initialCap = 2)
    {
        if (initialCap < 1)
        {
            initialCap = 1;
        }

        data = new int[initialCap];
        size = 0;
        capacity = initialCap;
        initialCapacity = initialCap;
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

    bool removeAt(int position)
    {
        if (position < 0 || position >= size)
        {
            cout << "Invalid position.\n";
            return false;
        }

        for (int i = position; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }

        size--;
        shrinkIfNeeded();
        return true;
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

    for (int i = 1; i <= 10; i++)
    {
        cout << "Append " << i << '\n';
        arr.append(i);
        arr.display();
        cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << "\n\n";
    }

    for (int i = 0; i < 9; i++)
    {
        cout << "Remove last element\n";
        arr.removeAt(arr.getSize() - 1);
        arr.display();
        cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << "\n\n";
    }

    return 0;
}