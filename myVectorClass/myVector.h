#pragma once

#include<utility>

template<typename itemType>

class myVector
{
private : 
	itemType* m_Data;
	size_t m_Size , m_Capacity;
	void reAlloc(size_t newCapcity);
public:
	 
	// constructors , destructor ;
	myVector <itemType>();
	myVector <itemType> (int);
	myVector <itemType>(int, itemType);
	myVector <itemType> (const myVector<itemType>&);
	~myVector <itemType>();
	
	// get methods ;
	 itemType at(int)const;
	 const itemType operator [] (size_t index) const;
	 itemType operator [] (size_t index);

	 itemType front() const;
	 itemType back() const;


	 size_t getSize() const; 
	 size_t getMaxSize() const;
	 bool empty() const;
	 bool full() const;

	 //int capacity()const;
	 //itemType& begin() const;
	 //itemType& end() const;
	 //itemType& rend() const;
	 //itemType& rbegin() const;


	 void erase(int position);
	 // erase (begin , end)
	 void clear();


	 void insert(size_t , const itemType &, size_t iteration = 1);
	 // void insert  (int position , begin , end );

	 template <class ...Args>
	 itemType& emplaceBack(Args&&...ar) {
		 if (m_Size >= m_Capacity) {
			 reAlloc(m_Capacity + (m_Capacity / 2));
		 }
		 new(&m_Data[m_Size])itemType(std::forward<Args>(ar)...);
		 return m_Data[m_Size++];
	 }

	 void resize(size_t size);
	 void resize(size_t size, const itemType& element);
	 

	 // manipulating the data ;
	 void push_back(const itemType&);
	 void push_back(const itemType&&);

	 void pop_back();
	 void swap(myVector <itemType>&);// swaps tow containers of the same itemType ;



	 void print() const;



	 // operator overloading ;

	 //bool operator == (const myVector<itemType>&)const;
	 //bool operator != (const myVector<itemType>&) const;
	 //bool operator < (const myVector<itemType>&)const;
	 //bool operator > (const myVector <itemType>&) const;
	 //bool operator >= (const myVector<itemType>&) const;
	 //bool operator <= (const myVector<itemType>&) const;
	 bool operator = (const myVector <itemType>&);

};

