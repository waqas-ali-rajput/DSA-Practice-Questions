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

    DynamicArray(const DynamicArray& other)
    {
        size = other.size;
        capacity = other.capacity;
        data = new int[capacity];

        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this != &other)
        {
            delete[] data;

            size = other.size;
            capacity = other.capacity;
            data = new int[capacity];

            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }

        return *this;
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

    bool update(int position, int value)
    {
        if (position < 0 || position >= size)
        {
            return false;
        }

        data[position] = value;
        return true;
    }

    void display() const
    {
        cout << "[";
        for (int i = 0; i < size; i++)
        {
            cout << data[i];
            if (i < size - 1)
            {
                cout << ", ";
            }
        }
        cout << "]";
    }
};

int main()
{
    DynamicArray first(2);
    first.append(10);
    first.append(20);
    first.append(30);

    DynamicArray second = first; // copy constructor

    first.update(0, 99);

    cout << "First array: ";
    first.display();
    cout << '\n';

    cout << "Second array: ";
    second.display();
    cout << '\n';

    DynamicArray third(2);
    third.append(1);
    third = first; // assignment operator

    first.update(1, 77);

    cout << "First array after another change: ";
    first.display();
    cout << '\n';

    cout << "Third array: ";
    third.display();
    cout << '\n';

    return 0;
}
