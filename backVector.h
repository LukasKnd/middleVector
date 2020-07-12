#ifndef BACKVECTOR_H_INCLUDED
#define BACKVECTOR_H_INCLUDED

#include <iterator>

// throw the following class if index/position out of bounds
class OutOfBoundsException {
};

template <class Type>
class backVector {

    int capacity;
    int current;
    Type* arr;

public:

    backVector()
        : capacity(1), current(0) {
            this->arr = new Type[capacity];
    }

    ~backVector() {
        delete [] this->arr;
    }

    backVector(const backVector &obj)
        : capacity(obj.capacity), current(obj.current) {
        this->arr = new Type[capacity];

        for(int i = 0; i < obj.current; i++) {
            this->arr[i] = obj.arr[i];
        }
    }

    void add(int index, const Type &data);

    void addFirst(const Type &data) {
        this->add(0, data);
    }

    void addLast(const Type &data) {
        this->add(this->current, data);
    }

    void remove(int index);

    void removeLast() {
        this->remove(this->current-1);
    }

    void removeFirst() {
        this->remove(0);
    }

    Type & operator[](int index) {
        return this->arr[index];
    }

    Type get(int index) {
        if(index < 0 || index >= this->current) {
            throw OutOfBoundsException();
        }
        return this->arr[index];
    }

    Type getLast() {
        return this->get(this->current-1);
    }

    Type getFirst() {
        return this->get(0);
    }

    int getSize() const {
        return this->current;
    }

    Type* begin() {
        return this->arr;
    }

};

template <class Type>
void backVector<Type>::add(int index, const Type &data) {
    if(index > this->current || index < 0) {
        throw OutOfBoundsException();
    }

    if(this->current == this->capacity) {

        this->capacity = this->capacity * 2;
        Type *newArr = new Type[this->capacity];

        std::move(this->arr, this->arr + index, newArr);

        newArr[index] = data;

        std::move(this->arr + index, this->arr + this->current, newArr + index + 1);

        delete [] this->arr;

        this->arr = newArr;

    } else {

        std::move_backward(this->arr + index, this->arr + current, this->arr + current + 1);

        this->arr[index] = data;
    }
    this->current++;
}

template <class Type>
void backVector<Type>::remove(int index) {
    if(index < 0 || index >= this->current) {
        throw OutOfBoundsException();
    }
    std::move(this->arr + index + 1, this->arr + this->current, this->arr + index);

    this->current--;
}



#endif // BACKVECTOR_H_INCLUDED
