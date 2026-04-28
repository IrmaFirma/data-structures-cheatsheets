#include <iostream>
#include <vector>
using namespace std;

template <typename E>
class VectorCompleteTree{
    private:
        vector<E> v;
    protected:
        Position pos(int i){
            return v.begin() + i;
        }
        int idx(const Position& p){
            return p - v.begin();
        }

    public:
        // whenever I say Position I actually mean: 
        typedef typename vector<E>::iterator Position;
        // constructor
        VectorCompleteTree():v(1){}; // initialize vector v with initial size of 1
        int size() const;
        // getters
        Position left(const Position& p);
        Position right(const Position& p);
        Position parent(const Position& p);
        Position root();
        Position last();
        // checkers
        const bool hasLeft(const Position& p);
        const bool hasRight(const Position& p);
        const bool isRoot(const Position& p);
        // modifiers
        const void add(const E& e);
        void remove();
        void swap(const Position& p, const Position& q);
};

template <typename T>
int VectorCompleteTree<T>::size() const{
    return v.size()-1;
}

template <typename T>
VectorCompleteTree<T>::Position VectorCompleteTree<T>::left(const Position& p){
    return pos(2*idx(p));
}
    

template <typename T>
VectorCompleteTree<T>::Position VectorCompleteTree<T>::right(const Position& p){
    return pos(2*idx(p)+1);
}

template <typename T>
VectorCompleteTree<T>::Position VectorCompleteTree<T>::parent(const Position& p){
    return pos(idx(p)/2);
}

template <typename T>
VectorCompleteTree<T>::Position VectorCompleteTree<T>::root(){
    return pos(1);
}

template <typename T>
VectorCompleteTree<T>::Position VectorCompleteTree<T>::last(){
    return pos(v.size()-1);
}

template <typename E>
const void VectorCompleteTree<E>::add(const E& e){
    v.push_back(e);
}

template <typename T>
void VectorCompleteTree<T>::remove(){
    v.pop_back();
}

template <typename T>
// swap values
void VectorCompleteTree<T>::swap(const Position& p, const Position& q){
    T e = *p;
    *p = *q;
    *q = e;
}

template <typename T>
const bool VectorCompleteTree<T>::hasLeft(const Position& p){
    return (2*idx(p) <= size());
}

template <typename T>
const bool VectorCompleteTree<T>::hasRight(const Position& p){
    return (2*idx(p)+1 <= size());
}

template <typename T>
const bool VectorCompleteTree<T>::isRoot(const Position& p){
    return (idx(p)==1);
}

int main(){
    
}
