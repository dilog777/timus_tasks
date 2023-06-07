#pragma once


template<class T, class Allocator = std::allocator<T>>
class MyVector
{
public:
	MyVector() = default;
	~MyVector();
	
	MyVector(const MyVector &other);
	MyVector(MyVector &&other);

	MyVector &operator=(const MyVector &other);
	MyVector &operator=(MyVector &&other);

	T at(std::size_t pos) const;
	void push_back(const T& item);

	bool isEmpty() const;
	std::size_t size() const;

	void clear();

private:
	std::size_t _size{ 0 };
	std::size_t _capacity{ 0 };
	T *_data{ nullptr };

	Allocator _alloc;
};



template<class T, class Allocator>
MyVector<T, Allocator>::~MyVector()
{
	_alloc.deallocate(_data, _capacity);
}



template<class T, class Allocator>
MyVector<T, Allocator>::MyVector(const MyVector &other)
{
	_size = other._size;
	_capacity = other._capacity;
	_data = _alloc.allocate(_capacity);

	T *ptr = &other._data[other._size];
	std::copy(other._data, ptr, _data);
}



template<class T, class Allocator>
MyVector<T, Allocator>::MyVector(MyVector &&other)
{
	std::swap(_size, other._size);
	std::swap(_capacity, other._capacity);
	std::swap(_data, other._data);
	std::swap(_alloc, other._alloc);
}



template<class T, class Allocator>
MyVector<T, Allocator> &MyVector<T, Allocator>::operator=(const MyVector &other)
{
	if (&other == this)
		return *this;

	_alloc.deallocate(_data, _capacity);

	_size = other.size;
	_capacity = other._capacity;
	_data = _alloc.allocate(_capacity);

	T *ptr = &other._data[other._size];
	std::copy(other._data, ptr, _data);
	return *this;
}



template<class T, class Allocator>
MyVector<T, Allocator> &MyVector<T, Allocator>::operator=(MyVector &&other)
{
	if (&other == this)
		return *this;

	_alloc.deallocate(_data, _capacity);

	std::swap(_size, other._size);
	std::swap(_capacity, other._capacity);
	std::swap(_data, other._data);
	std::swap(_alloc, other._alloc);
	return *this;
}



template<class T, class Allocator>
T MyVector<T, Allocator>::at(std::size_t pos) const
{
	if (pos <= _size)
		return _data[pos];

	return {};
}



template<class T, class Allocator>
void MyVector<T, Allocator>::push_back(const T &item)
{
	if (_size == _capacity)
	{
		std::size_t newCapacity = _capacity * 2 + 1;
		T *newData = _alloc.allocate(newCapacity);
	
		if (_capacity > 0)
		{
			T *ptr = &_data[_size];
			std::copy(_data, ptr, newData);
		}
	
		std::swap(newData, _data);
		_alloc.deallocate(newData, _capacity);
		_capacity = newCapacity;
	}
	
	T *ptr = &_data[_size];
	::new ((void *)ptr) T(item);
	++_size;
}



template<class T, class Allocator>
bool MyVector<T, Allocator>::isEmpty() const
{
	return _size == 0;
}



template<class T, class Allocator>
std::size_t MyVector<T, Allocator>::size() const
{
	return _size;
}



template<class T, class Allocator>
void MyVector<T, Allocator>::clear()
{
	_size = 0;
}
