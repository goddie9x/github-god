#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Vector {
private :
    int size;
    int capacity;
    T* array;
    void expand(int newCapacity) {
        if (newCapacity <= capacity) {
            return;
        }
        T* old = array;
        array = new T[newCapacity];
        for (int i = 0; i < capacity; i++) {
            array[i] = old[i];
        }
        delete[]old;
        capacity = newCapacity;
    }
public:
    Vector(int initCapacity = 100) {
        size = 0;
        capacity = initCapacity;
        array = new T[capacity];
    }
    ~Vector() {
        delete[]array;
    }
    Vector& operator=(T* obj) {
        if (this != obj) {
            delete[]array;
            size = obj.size;
            capacity = obj.capacity;
            array = new T[capacity];
            for (int i = 0; i < capacity; i++) {
                array[i] = obj.array[i];
            }
        }
        return *this;
    }
    int Size() {
        return size;
    }
    bool empty() {
        return (size==0);
    }
    T &operator[](int i) {
        return array[i];
    }
    void push_back(T newElement) {
        if (size==capacity) {
            expand(2*size);
        }
        array[size] = newElement;
        size++;
    }
    void pop_back() {
        size--;
    }
    void insert(int position, T newElement) {
        if (size == capacity) {
            expand(2 * size);
        }
        for (int i = size; i > position; i--) {
            array[i] = array[i - 1];
        }
        array[position] = newElement;
        size++;
    }
    void erase(int position) {
        for (int i = position; i < size;i++) {
            array[i] = array[i + 1];
        }
        size--;
    }
    void clean() {
        size = 0;
    }
};

int main()
{
    Vector<int>a;
    for (int i = 0; i < 5; i++) {
        cout << "vui long nhap vao cac phan tu thu " <<i+1<< " cua mang" << endl;
        int temp;
        cin >> temp;
        a.push_back(temp);
        cout << a.Size()<<endl;
    }
    cout << a[3];
}  