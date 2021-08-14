#include "myVector.h"

#include<iostream>
#include <algorithm>
#include<cmath>

using std::fill_n;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

// the utility function first : 
template <class itemType>
void myVector<itemType> :: reAlloc(size_t newCapcity) {
	itemType *newBlock = (itemType*)::operator new (newCapcity * sizeof(itemType));
	
	if (newCapcity < m_Size) {
		m_Size = newCapcity;
	}
	for (size_t i = 0; i < m_Size; i++) {
		newBlock[i] = std :: move (m_Data[i]);
	}
	for (size_t i = 0; i < m_Size; i++) {
		m_Data[i].~itemType();
	}
	::operator delete (m_Data , m_Capacity * sizeof (itemType)) ;// deallocating the old m_Data ;
	m_Data = newBlock; 
	m_Capacity = newCapcity;
}


// constructors , destructor ;
template <class itemType>
myVector <itemType> ::myVector() {
	m_Size = 0;
	m_Capacity = 2;
	cout << m_Capacity * sizeof(itemType) << endl;
	m_Data = (itemType*)::operator new (m_Capacity * sizeof(itemType));
}

template <class itemType>
myVector <itemType> ::myVector(int s) { // paramterized constructor;
	if (s > 0) {
		m_Size = 0;
		m_Capacity = s;
		m_Data = (itemType*)::operator  new (m_Capacity * sizeof(itemType));
	}
}

template <class itemType>
myVector <itemType> ::myVector(int s, itemType value) { // paramterized constructor;
	if (s > 0) {
		m_Size = s;
		m_Capacity = s;
		m_Data = (itemType*)::operator  new (m_Capacity * sizeof(itemType));
		fill_n(m_Data, m_Size, value);
	}
}

template <class itemType>
myVector <itemType> ::myVector(const myVector<itemType>&otherObject) { // copy constructor;
	if (this != otherObject) {
		m_Size = otherObject.m_Size;
		m_Capacity = otherObject.m_Capacity;
		m_Data = (itemType*)::operator  new (m_Capacity * sizeof(itemType));

		for (size_t counter = 0; counter < m_Size; counter++) {
			m_Data[counter] = otherObject.m_Data[counter];
		}
	}
}


template <class itemType>
myVector<itemType> :: ~myVector <itemType>() { // destructor;
	clear();
	::operator delete (m_Data, m_Capacity * sizeof(itemType));
}





// get methods ;

template <class itemType>
itemType  myVector<itemType> :: at(int index)const {
	return m_Data[index];
}

template <class itemType>
const itemType  myVector <itemType> :: operator []  (size_t index) const {
	if (index < m_Size && index >= 0) {
		return m_Data[index];
	}
}

template <class itemType>
itemType  myVector <itemType> :: operator []  (size_t index) {
	if (index < m_Size && index >= 0) {
		return m_Data[index];
	}
}

template <class itemType>
itemType  myVector <itemType> ::front() const {
	return m_Data[m_Size];
}

template <class itemType>
itemType myVector <itemType> ::back() const {
	return m_Data[0];
}


template <class itemType>
size_t myVector <itemType> ::getSize() const {
	return m_Size;
}

template <class itemType>
size_t myVector<itemType> ::getMaxSize() const{
	return m_Capacity;
}

template <class itemType>
bool myVector <itemType> :: empty() const {
	return m_Capacity != m_Size;
}

template <class itemType>
bool myVector <itemType>::full() const {
	return m_Size == m_Capacity;
}





// Clear methods ;
template <class itemType>
void  myVector <itemType>::erase(int position) {
	if (position > 0 && position < m_Size && m_Size > 0 ) {
		copy(m_Data + position + 1, m_Data + m_Size, m_Data + position);
		m_Size--;
	}
}

// erase (begin , end)
template <class itemType>
void myVector <itemType>::clear() {
	for (size_t i = 0; i < m_Size; i++)
		m_Data[i].~itemType();
	m_Size = 0;
}


// insert method ;
template <class itemType>
void myVector <itemType>::insert(size_t position, const itemType& element, size_t iteration) {
	if (position > m_Size) {
		cerr << "the position is invalid" << endl;
	}
	else if (m_Size == 0 && iteration == 1 , position == 0) {
		m_Data[m_Size] = element;
	}
	else if (m_Size ==0 && iteration > 1 , position == 0){
		fill_n(m_Data, iteration, element);
	}

	else if (position < m_Size && m_Size > 0 && position > 0) {
		size_t counter;
		cout << "inside the if statment" << endl; 
		// allocates memory if the container is small;
		if (m_Size + iteration > m_Capacity) {
			reAlloc((m_Size + iteration));
		}
		m_Size += iteration;

		// shiffting the elements ;
		for (counter = m_Size; counter >(position + iteration) ; counter-- ) {
			m_Data[counter] = m_Data[counter - iteration];
		}
		// inserting the new elements ;
		fill_n(m_Data + position, iteration, element);
	}


}
// void insert  (int position , begin , end );


// resize : 


template <typename itemType>
void myVector <itemType>::resize(size_t size) {
	reAlloc(size);
}


template<class itemType>
void myVector <itemType> ::resize(size_t size , const itemType& element) {
	reAlloc(size);
	fill_n(m_Data, m_Capacity - m_Size, element);
}



// manipulating the data ;
template <class itemType>
void myVector <itemType>::push_back(const itemType& element) {
	if (m_Size >= m_Capacity) 
		reAlloc(m_Capacity + ceil(m_Capacity /2) );
	m_Data[m_Size++] = element;
}

template <typename itemType>
void myVector <itemType>::push_back(const itemType&& element) {
	if (m_Size >= m_Capacity)
		reAlloc(m_Capacity + (m_Capacity / 2));

	 m_Data[m_Size++]= std::move(element);
}



template <class itemType>
void myVector <itemType>::pop_back() {
	if (m_Size > 0) {
		m_Size--;
		m_Data[m_Size].~itemType();
	}
}
template <class itemType>

void swap(myVector <itemType>&obj) {
	myVector <itemType> temp (obj);
	obj = *this;
	this = temp;
}// swaps tow containers of the same itemType ;

// print ;

template <class itemType>
void myVector <itemType>::print() const {
	if (m_Size > 0) {
		copy(m_Data, m_Data + m_Size, std::ostream_iterator <itemType>(cout, "   "));
		cout << endl;
	}
	else if (m_Size == 0) {
		cerr << "the vector is empty" << endl;
	}
	
}


// operator overloading ;
//template <class itemType>
//
//bool operator == (const myVector<itemType>&)const;
//bool operator != (const myVector<itemType>&) const;
//bool operator < (const myVector<itemType>&)const;
//bool operator > (const myVector <itemType>&) const;
//bool operator >= (const myVector<itemType>&) const;
//bool operator <= (const myVector<itemType>&) const;

template <class itemType>
bool myVector <itemType> :: operator = (const myVector <itemType> &obj) {
	if (this != obj) {
		if (m_Size != 0) {
			::operator delete (m_Data, m_Capacity * sizeof(itemType));
		}
		m_Size = obj.m_Size;
		m_Capacity = obj.m_Capacity;
		m_Data = (itemType*)::operator new (m_Capacity * sizeof(itemType));
		copy(obj.m_Data, obj.m_Data + m_Size, m_Data);
	}
}