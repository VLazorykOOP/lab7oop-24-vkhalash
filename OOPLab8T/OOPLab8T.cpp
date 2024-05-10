#include <iostream>
#include <cstring>

using namespace std;
void MenuTask()
{
    cout << "    Menu Task\n";
    cout << "    1.  Task 1\n";
    cout << "    2.  Task 2\n";
    cout << "    3.  Task 3\n";
    cout << "    4.  Task 4\n";
    cout << "    5.  Exit\n";
}

// Find minimum (int)
template <typename T>
T findMin(const pair<T, T> &pair)
{
    return pair.first < pair.second ? pair.first : pair.second;
}

// Find maximum (int)
template <typename T>
T findMax(const pair<T, T> &pair)
{
    return pair.first > pair.second ? pair.first : pair.second;
}

// Find minimum (char*)
template <>
char *findMin<char *>(const pair<char *, char *> &pair)
{
    return strcmp(pair.first, pair.second) < 0 ? pair.first : pair.second;
}

// Find maximum (char*)
template <>
char *findMax<char *>(const pair<char *, char *> &pair)
{
    return strcmp(pair.first, pair.second) > 0 ? pair.first : pair.second;
}

// Console input (int)
template <typename T>
pair<T, T> consoleInput()
{
    T first, second;
    cout << "Input first number ";
    cin >> first;
    cout << "Input second number ";
    cin >> second;
    return pair<T, T>(first, second);
}

// Console input (char*)
template <>
pair<char *, char *> consoleInput<char *>()
{
    char first[100], second[100];
    cout << "Input first string ";
    cin.ignore(); // Ignore the newline character left in the buffer
    cin.getline(first, 100);
    cout << "Input second string ";
    cin.getline(second, 100);
    char *firstPtr = new char[strlen(first) + 1];
    char *secondPtr = new char[strlen(second) + 1];
    strcpy(firstPtr, first);
    strcpy(secondPtr, second);
    return make_pair(firstPtr, secondPtr);
}

// Function template for selection sort
template <typename T>
void selectionSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Specialization of the function template for char*
template <>
void selectionSort<char *>(char *arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (strcmp(arr[j], arr[minIndex]) < 0)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node(T newData) : data(newData), next(nullptr) {}
};

// Parameterized class
template <class T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
    }

    void addFront(T newData)
    {
        Node<T> *newNode = new Node<T>(newData);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void addBack(T newData)
    {
        Node<T> *newNode = new Node<T>(newData);
        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Array iterator
template <typename T>
class Iterator
{
private:
    T *ptr;

public:
    Iterator(T *p) : ptr(p) {}

    T &operator*() const
    {
        return *ptr;
    }

    Iterator &operator++()
    {
        ++ptr;
        return *this;
    }

    Iterator operator++(int)
    {
        Iterator tmp = *this;
        ++ptr;
        return tmp;
    }

    bool operator!=(const Iterator &other) const
    {
        return ptr != other.ptr;
    }
};

template <typename T>
class Array
{
private:
    T *arr;
    int size;

public:
    Array(int n) : size(n)
    {
        arr = new T[size];
    }

    ~Array()
    {
        delete[] arr;
    }

    T &operator[](int index)
    {
        return arr[index];
    }

    Iterator<T> begin()
    {
        return Iterator<T>(arr);
    }

    Iterator<T> end()
    {
        return Iterator<T>(arr + size);
    }
};

int main()
{
    MenuTask();

    int choice;

    do
    {
        cout << "Choice ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Task 1
        {
            pair<int, int> intPair = consoleInput<int>();
            cout << "Min: " << findMin(intPair) << endl;
            cout << "Max: " << findMax(intPair) << endl;

            pair<char *, char *> charPair = consoleInput<char *>();
            cout << "Min: " << findMin(charPair) << endl;
            cout << "Max: " << findMax(charPair) << endl;

            choice = 5;
            break;
        }
        case 2: // Task 2
        {
            int intArr[5];
            cout << "Input int array " << endl;
            for (int i = 0; i < 5; ++i)
            {
                cin >> intArr[i];
            }
            selectionSort(intArr, 5);
            cout << "Sorted int array: ";
            for (int i = 0; i < 5; ++i)
            {
                cout << intArr[i] << " ";
            }
            cout << endl;

            const int MAX_WORDS = 5;
            char *charArr[MAX_WORDS];
            cout << "Input string" << endl;
            for (int i = 0; i < MAX_WORDS; ++i)
            {
                char buffer[100];
                cin >> buffer;
                charArr[i] = new char[strlen(buffer) + 1];
                strcpy(charArr[i], buffer);
            }
            selectionSort(charArr, MAX_WORDS);
            cout << "Sorted array: ";
            for (int i = 0; i < MAX_WORDS; ++i)
            {
                cout << charArr[i] << " ";
                delete[] charArr[i];
            }
            cout << endl;

            choice = 5;
            break;
        }
        case 3: // Task 3
        {
            LinkedList<int> list;
            int value;
            char innerChoice;

            do
            {
                cout << "Input value ";
                cin >> value;
                list.addBack(value);
                cout << "Add another? (y/n) ";
                cin >> innerChoice;
            } while (innerChoice == 'y' || innerChoice == 'Y');

            cout << "List: ";
            list.printList();

            choice = 5;
            break;
        }
        case 4: // Task 4
        {
            int size;
            cout << "Input array size ";
            cin >> size;

            Array<int> arr(size);

            for (int i = 0; i < size; ++i)
            {
                arr[i] = i * 2;
            }

            cout << "Elements: ";
            for (Iterator<int> it = arr.begin(); it != arr.end(); ++it)
            {
                cout << *it << " ";
            }
            cout << endl;

            choice = 5;
            break;
        }
        case 5: // Exit
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
