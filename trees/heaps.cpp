/* @file heap.cpp
 * @author 
 * @description Binary Heap Implementation in C++
 * @date 
 */
#ifndef HEAP_HPP
#define HEAP_HPP
#include<iostream>
#include<exception>
#include<math.h>
#include<ctime>
#include<vector>
#include<iomanip>
#include<sstream>
using namespace std;

class Heap
{
	private:
		vector<int> array;
	public:
		Heap():array(1){}
		void insert(int key);
		int removeMin();
		int getMin();
		int parent(int k);
		int left(int k);
		int right(int k);
		void bubbleup(int k);
		void bubbledown(int k);
		void sort();

		//Part of the starter code
		void display();

		//Required for autorgrader. Do not implment or delete
		void display2(ostream& os);
};

//==================================================================
//This method displays a Heap in 2D format. 
void Heap::display()
{
	if(array.size()>1)
	{
		int levels = int(log2(array.size()));

		int *spaces = new int[levels+1];
		spaces[levels]=0;

		for(int j=levels-1; j>=0; j--)
		{
				spaces[j]=2*spaces[j+1]+1;
		}
		
		int level=0;
		for (int i=0; i<array.size()-1; i++)
		{
			if(i == (pow(2,level)-1))
			{
				cout<<endl<<endl;
			
				for(int k=0; k<spaces[level]; k++)
				cout<<"   ";
				level++;
			}
			cout<<std::left<<setw(3)<<array[i+1];
		
			if(level>1)
			{
				for(int k=0; k<spaces[level-2]; k++)
					cout<<"   ";
			}
			
		}

		cout<<endl;
		for(int i=0; i<spaces[0]*log2(array.size()/2)+4; i++)
			cout<<"__";
		
		cout<<endl;
		delete[] spaces;
	}

}
//==================================================
//Please add your code below this line.
void Heap::insert(int key){
	array.push_back(key);
	bubbleup(array.size()-1);
}

int Heap::removeMin(){
	if(array.size()<=1) throw runtime_error("empty heap");
	int minelem = array[1];
	array[1] = array[array.size()-1];
	array.pop_back();
	if(array.size() > 1){
		bubbledown(1);
	}
	return minelem;
}

int Heap::getMin(){
	if(array.size()<=1) throw runtime_error("empty heap");
	return array[1];
}

int Heap::parent(int k){
	return k/2;
}

int Heap::left(int k){
	return 2*k;
}

int Heap::right(int k){
	return 2*k+1;
}

void Heap::sort(){
	vector<int> sorted;
	while(array.size()>1){
		sorted.push_back(removeMin());
	}

	array.clear();
	array.push_back(-1);

	for(int i = 0; i<sorted.size(); i++){
		array.push_back(sorted[i]);
	}
}


void Heap::bubbleup(int k){
	if(k<=1) return;
	while(k>1 && array[k] < array[parent(k)]){
		swap(array[k], array[parent(k)]);
		k = parent(k);
	}

}

void Heap::bubbledown(int k){
	while(true){
		int lefty = left(k);
		int righty = right(k);
		int smallest = k;

		if(lefty <= array.size() && array[lefty] < array[smallest]){
			smallest = lefty;
		}

		if(righty <= array.size() && array[righty] < array[smallest]){
			smallest = righty;
		}

		if(smallest == k) break;

		swap(array[k], array[smallest]);
		k = smallest;
	}
}
//==================================================
// Do not add any code below this line
#endif


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
    return pos(v.size());
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
    T elem = *p;
    *p = *q;
    *q = elem;
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
    return (idx(p) == 1);
}

template <typename T, typename C>
class HeapPQ{
    public:
        int size() const;
        bool empty() const;
        void insert(int e);
        const int min();
        void removeMin();

    private:
        VectorCompleteTree<T> T;
        C comparator;
        VectorCompleteTree<T>::Position Position;
};

template <typename T, typename V>
int HeapPQ<T, V>::size() const{
    return T.size();
}

template <typename T, typename V>
bool HeapPQ<T, V>::empty() const{
    return (T.size()==0);
}

template <typename T, typename V>
const int HeapPQ<T, V>::min(){
    if(empty()) throw runtime_error("Empty Queue");
    return T.root();
}

template <typename T, typename V>
void HeapPQ<T,V>::insert(int e){
    T.add(e);
    Position u = T.last();
    while(!T.isRoot()){
        Position v = T.parent(u);
        if(!comparator(*u, *v)) break;
        T.swap(u, v);
        u = v;
    }
}

template <typename T, typename V>
void HeapPQ<T, V>::removeMin(){
    if(empty()) throw runtime_error("Empty Queue");
    if(T.size()==1){
        T.remove();
    }else{
        Position u = T.root();
        T.swap(u, T.last());
        T.remove();
        while(T.hasLeft(u)){
            Position v = T.left(u);
            if(T.hasRight(u) && comparator(*(T.right(u), *v))){
                v = T.right(u);
            }
            if(comparator(*v, *u)){
                T.swap(u, v);
                u = v;
            }else{
                break;
            }
        }
    }
}


int main(){
    return 0;
}
