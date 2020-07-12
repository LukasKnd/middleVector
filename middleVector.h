#ifndef MIDDLEVECTOR_H_INCLUDED
#define MIDDLEVECTOR_H_INCLUDED

#include "backVector.h"
#include "frontVector.h"

template <class Type>
class middleVector {

    backVector<Type> first;
    frontVector<Type> second;

    void balance() {

        int balanceFactor = std::abs(first.getSize() - second.getSize());

        while(balanceFactor > 1) {
            if(first.getSize() > second.getSize()) {
                Type tmp = first.getLast();
                first.removeLast();
                second.addFirst(tmp);
            } else {
                Type tmp = second.getFirst();
                second.removeFirst();
                first.addLast(tmp);
            }
            balanceFactor -= 2;
        }
    }


public:

    middleVector() {}
    ~middleVector() {}

    class Iterator : public std::iterator<std::random_access_iterator_tag,
                                         Type,
                                         std::ptrdiff_t,
                                         Type*,
                                         Type&>
    {
        private:
            middleVector<Type> & v;
            int pos;
        public:

            Iterator( middleVector<Type> & v, int pos )
                : v ( v ), pos( pos ) {

            }

            Iterator(const Iterator &rhs)
                : v (rhs.v), pos(rhs.pos) {
            }

            Iterator & operator=(const Iterator &rhs) {
                v = rhs.v;
                pos = rhs.pos;
                return *this;
            }

            Type & operator*() { return v[pos]; }
            Iterator & operator++() { ++pos; return *this; }
            Iterator & operator--() { --pos; return *this; }
            Iterator operator+(int rhs) { return Iterator(v, pos + rhs); }
            Iterator operator-(int rhs) { return Iterator(v, pos - rhs); }
            ptrdiff_t operator-(const Iterator &rhs) { return pos - rhs.pos; }

            bool operator==(const Iterator &rhs) { return pos == rhs.pos; }
            bool operator!=(const Iterator &rhs) { return pos != rhs.pos; }
            bool operator<(const Iterator &rhs) { return pos < rhs.pos; }
    };


    void add(int index, const Type &data) {
        if(index <= first.getSize()) {
            first.add(index, data);
        } else {
            second.add(index - first.getSize(), data);
        }

        balance();
    }

    void addFirst(const Type &data) {
        add(0, data);
    }

    void addLast(const Type &data) {
        add(getSize(), data);
    }

    void remove(int index) {
        if(index < first.getSize()) {
            first.remove(index);
        } else {
            second.remove(index - first.getSize());
        }

        balance();
    }

    void removeLast() {
        remove(getSize() - 1);
    }

    void removeFirst() {
        remove(0);
    }

    Type get(int index) {
        if(index < first.getSize()) {
            return first.get(index);
        } else {
            return second.get(index - first.getSize());
        }
    }

    Type & operator[](int index) {
        if(index < first.getSize()) {
            return first[index];
        } else {
            return second[index - first.getSize()];
        }
    }

    Type getLast() {
        return get(getSize() - 1);
    }

    Type getFirst() {
        return get(0);
    }

    int getSize() const{
        return first.getSize() + second.getSize();
    }

    Iterator begin() {
        return Iterator(*this, 0);
    }

};

#endif // MIDDLEVECTOR_H_INCLUDED
