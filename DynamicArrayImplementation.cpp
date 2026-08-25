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

    bool insertAt(int position, int value)
    {
        if (position < 0 || position > size)
        {
            cout << "Invalid position.\n";
            return false;
        }

        if (size == capacity)
        {
            resize(capacity * 2);
        }

        for (int i = size; i > position; i--)
        {
            data[i] = data[i - 1];
        }

        data[position] = value;
        size++;
        return true;
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
        return true;
    }

    int search(int value) const
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == value)
            {
                return i;
            }
        }

        return -1;
    }

    bool update(int position, int value)
    {
        if (position < 0 || position >= size)
        {
            cout << "Invalid position.\n";
            return false;
        }

        data[position] = value;
        return true;
    }

    int get(int position) const
    {
        if (position < 0 || position >= size)
        {
            cout << "Invalid position.\n";
            return -1;
        }

        return data[position];
    }

    void display() const
    {
        cout << "Array: ";
        if (size == 0)
        {
            cout << "empty";
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << data[i] << " ";
            }
        }
        cout << '\n';
    }

    int getSize() const
    {
        return size;
    }

    int getCapacity() const
    {
        return capacity;
    }

    bool isEmpty() const
    {
        return size == 0;
    }
};

int main()
{
    DynamicArray arr(2);

    arr.append(10);
    arr.append(20);
    arr.append(30);

    arr.display();
    cout << "Search 20: " << arr.search(20) << '\n';

    arr.update(1, 99);
    cout << "Value at index 1: " << arr.get(1) << '\n';

    arr.removeAt(0);
    arr.display();

    cout << "Size: " << arr.getSize() << '\n';
    cout << "Capacity: " << arr.getCapacity() << '\n';
    cout << "Empty: " << (arr.isEmpty() ? "Yes" : "No") << '\n';

    return 0;
}