#include <iostream>
#include <list>
#include <stdexcept>
#include <iterator>
using namespace std;

// sorted insert

template <typename T, typename V> // V for comparators
class ListPQ{
    public:
        ListPQ():n(0){}
        int size() const;
        bool empty() const;
        void insert(const T& elem);
        const T& min() const;
        void removeMin();
        void insertionSort(list<T>& L, ListPQ<T, V>& P);
    private:
        list<T> my_list;
        V comparator; // is less
        int n;
};

template <typename T, typename V>
int ListPQ<T, V>::size() const {
    return n;
}

template <typename T, typename V>
bool ListPQ<T, V>::empty() const {
    return (n==0);
}

template <typename T, typename V>
void ListPQ<T, V>::insert(const T& elem){
    typename list<T>::iterator p;
    p = my_list.begin();
    while(p!=my_list.end() && !comparator(elem, *p)){
        ++p;
    }
    my_list.insert(p, elem);
    n++;
}

template <typename T, typename V>
const T& ListPQ<T, V>::min() const{
    if(empty()) throw runtime_error("PQ Empty!");
    return my_list.front();
}

template <typename T, typename V>
void ListPQ<T, V>::removeMin(){
    if(empty()) throw runtime_error("PQ Empty!");
    my_list.pop_front();
    n--;
}

template <typename T, typename V>
void ListPQ<T, V>::insertionSort(list<T>& L, ListPQ<T, V>& P){

    // Phase 1:
    while(!L.empty()){
        T e = L.front();
        L.pop_front();
        P.insert(e);
    }

    // Phase 2:
    while(!P.empty()){
        T e = P.min();
        P.removeMin();
        L.push_back(e);
    }
}

class MyIntComparator{
    public:
        bool operator()(int p, int q){
            return p<q;
        }

};

int main(){

    ListPQ<int, MyIntComparator> myPQ;

    myPQ.insert(20);
    myPQ.insert(10);
    myPQ.insert(15);

    cout << "Smallest element: " << myPQ.min() << endl;
    cout << "PQ size: " << myPQ.size() << endl;
    myPQ.removeMin();
    cout << "Smallest element after previous MIN removed: " << myPQ.min() << endl;

    list<int> sort_list = {1, 4, 8, 2, 10, 23, -4, 0};
    ListPQ<int, MyIntComparator> sorting_PQ;

    cout<<"Before Insertion sort: "<<endl;
    for(list<int>::iterator i = sort_list.begin(); i!=sort_list.end(); ++i){
        cout<<*i<<" ";
    }

    cout<<endl;

    sorting_PQ.insertionSort(sort_list, sorting_PQ);
    
    cout<<"After Insertion sort: "<<endl;
    for(list<int>::iterator i = sort_list.begin(); i!=sort_list.end(); ++i){
        cout<<*i<<" ";
    }

    return 0;
}

#include <iostream>
#include <list>
#include <stdexcept>
#include <iterator>
using namespace std;

// unsorted insert

template <typename T, typename V> // V for comparators
class ListPQ{
    public:
        ListPQ():n(0){}
        int size() const;
        bool empty() const;
        void insert(const T& elem);
        const T& min() const;
        void removeMin();
        void selectionSort(list<T>& L, ListPQ<T, V>& P);

    private:
        list<T> my_list;
        V comparator; // is less
        int n;
};

template <typename T, typename V>
int ListPQ<T, V>::size() const {
    return n;
}

template <typename T, typename V>
bool ListPQ<T, V>::empty() const {
    return (n==0);
}

// change
template <typename T, typename V>
void ListPQ<T, V>::insert(const T& elem){
    my_list.push_back(elem);
    n++;
}

// change
template <typename T, typename V>
const T& ListPQ<T, V>::min() const{
    if(empty()) throw runtime_error("PQ Empty!");
    typename list<T>::const_iterator minimum = my_list.begin();
    for(typename list<T>::const_iterator p = my_list.begin(); p!=my_list.end(); ++p){
        if(comparator(*p, *minimum)){
            minimum = p;
        }
    }
    return *minimum;
}

// change
template <typename T, typename V>
void ListPQ<T, V>::removeMin(){
    if(empty()) throw runtime_error("PQ Empty!");
    typename list<T>::const_iterator minimum = my_list.begin();
    for(typename list<T>::const_iterator p = my_list.begin(); p!=my_list.end(); ++p){
        if(comparator(*p, *minimum)){
            minimum = p;
        }
    }
    my_list.erase(minimum);
    n--;
}

template <typename T, typename V>
void ListPQ<T, V>::selectionSort(list<T>& L, ListPQ<T, V>& P){

    // Phase 1
    while(!L.empty()){
        T e = L.front();
        L.pop_front();
        P.insert(e);
    }

    // Phase 2
    while(!P.empty()){
        T e = P.min();
        P.removeMin();
        L.push_back(e);
    }
}

class MyIntComparator{
    public:
        bool operator()(int p, int q) const{
            return p<q;
        }

};

int main(){

    ListPQ<int, MyIntComparator> myPQ;

    myPQ.insert(20);
    myPQ.insert(10);
    myPQ.insert(15);

    cout << "Smallest element: " << myPQ.min() << endl;
    cout << "PQ size: " << myPQ.size() << endl;
    myPQ.removeMin();
    cout << "Smallest element after previous MIN removed: " << myPQ.min() << endl;

    list<int> sort_list = {1, 4, 8, 2, 10, 23, -4, 0};
    ListPQ<int, MyIntComparator> sorting_PQ;

    cout<<"Before Insertion sort: "<<endl;
    for(list<int>::iterator i = sort_list.begin(); i!=sort_list.end(); ++i){
        cout<<*i<<" ";
    }

    cout<<endl;

    sorting_PQ.selectionSort(sort_list, sorting_PQ);
    
    cout<<"After Insertion sort: "<<endl;
    for(list<int>::iterator i = sort_list.begin(); i!=sort_list.end(); ++i){
        cout<<*i<<" ";
    }

    return 0;
}


