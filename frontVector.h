#ifndef FRONTVECTOR_H_INCLUDED
#define FRONTVECTOR_H_INCLUDED

#include "backVector.h"

template <class Type>
class frontVector : public backVector<Type> {

public:

    void add(int index, const Type &data) {
        backVector<Type>::add(backVector<Type>::getSize() - index, data);
    }

    void addLast(const Type &data) {
        backVector<Type>::addFirst(data);
    }

    void addFirst(const Type &data) {
        backVector<Type>::addLast(data);
    }

    Type get(int index) {
        return backVector<Type>::get(backVector<Type>::getSize() - index - 1);
    }

    Type & operator[](int index) {
        return backVector<Type>::operator[](backVector<Type>::getSize() - index - 1);
    }

    Type getLast() {
        return backVector<Type>::getFirst();
    }

    Type getFirst() {
        return backVector<Type>::getLast();
    }

    void remove(int index) {
        backVector<Type>::remove(backVector<Type>::getSize() - index - 1);
    }

    void removeLast() {
        backVector<Type>::removeFirst();
    }

    void removeFirst() {
        backVector<Type>::removeLast();
    }

    std::reverse_iterator<Type *> begin() {
        return std::reverse_iterator<Type *> ( backVector<Type>::begin() +  backVector<Type>::getSize() );
    }

};

#endif
