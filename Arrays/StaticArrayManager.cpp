#include <iostream>
using namespace std;

int main() {
    const int CAPACITY = 20;
    int arr[CAPACITY];
    int size = 0;
    int choice, value, position;

    do {
        cout << "\n===== Static Array Manager =====\n";
        cout << "1. Display all elements\n";
        cout << "2. Insert at beginning\n";
        cout << "3. Insert at end\n";
        cout << "4. Insert at position\n";
        cout << "5. Delete first element\n";
        cout << "6. Delete last element\n";
        cout << "7. Delete from position\n";
        cout << "8. Search for a value\n";
        cout << "9. Update value at index\n";
        cout << "10. Display size and capacity\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        // 1. Display all elements
        case 1:
            if (size == 0) {
                cout << "Array is empty.\n";
            } else {
                cout << "Array elements: ";
                for (int i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            break;

        // 2. Insert at beginning
        case 2:
            if (size == CAPACITY) {
                cout << "Error: Array is full.\n";
            } else {
                cout << "Enter value: ";
                cin >> value;

                for (int i = size; i > 0; i--) {
                    arr[i] = arr[i - 1];
                }

                arr[0] = value;
                size++;

                cout << "Element inserted at beginning.\n";
            }
            break;

        // 3. Insert at end
        case 3:
            if (size == CAPACITY) {
                cout << "Error: Array is full.\n";
            } else {
                cout << "Enter value: ";
                cin >> value;

                arr[size] = value;
                size++;

                cout << "Element inserted at end.\n";
            }
            break;

        // 4. Insert at position
        case 4:
            if (size == CAPACITY) {
                cout << "Error: Array is full.\n";
            } else {
                cout << "Enter position (0 to " << size << "): ";
                cin >> position;

                if (position < 0 || position > size) {
                    cout << "Error: Invalid position.\n";
                } else {
                    cout << "Enter value: ";
                    cin >> value;

                    for (int i = size; i > position; i--) {
                        arr[i] = arr[i - 1];
                    }

                    arr[position] = value;
                    size++;

                    cout << "Element inserted successfully.\n";
                }
            }
            break;

        // 5. Delete first element
        case 5:
            if (size == 0) {
                cout << "Error: Array is empty.\n";
            } else {
                for (int i = 0; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }

                size--;

                cout << "First element deleted.\n";
            }
            break;

        // 6. Delete last element
        case 6:
            if (size == 0) {
                cout << "Error: Array is empty.\n";
            } else {
                size--;

                cout << "Last element deleted.\n";
            }
            break;

        // 7. Delete from position
        case 7:
            if (size == 0) {
                cout << "Error: Array is empty.\n";
            } else {
                cout << "Enter index (0 to " << size - 1 << "): ";
                cin >> position;

                if (position < 0 || position >= size) {
                    cout << "Error: Invalid index.\n";
                } else {
                    for (int i = position; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }

                    size--;

                    cout << "Element deleted successfully.\n";
                }
            }
            break;

        // 8. Search for a value
        case 8:
            if (size == 0) {
                cout << "Array is empty.\n";
            } else {
                cout << "Enter value to search: ";
                cin >> value;

                bool found = false;

                for (int i = 0; i < size; i++) {
                    if (arr[i] == value) {
                        cout << "Value found at index " << i << ".\n";
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Value not found.\n";
                }
            }
            break;

        // 9. Update value at index
        case 9:
            if (size == 0) {
                cout << "Array is empty.\n";
            } else {
                cout << "Enter index (0 to " << size - 1 << "): ";
                cin >> position;

                if (position < 0 || position >= size) {
                    cout << "Error: Invalid index.\n";
                } else {
                    cout << "Enter new value: ";
                    cin >> value;

                    arr[position] = value;

                    cout << "Value updated successfully.\n";
                }
            }
            break;

        // 10. Display size and capacity
        case 10:
            cout << "Logical size: " << size << endl;
            cout << "Physical capacity: " << CAPACITY << endl;
            break;

        case 0:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Error: Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
