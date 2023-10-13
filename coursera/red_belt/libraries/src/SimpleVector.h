#ifndef simple_vector
#define simple_vector
#include<cstddef>

template<class T>
class SimpleVector
{
public:
	SimpleVector() = default;
	explicit SimpleVector(size_t size);
	SimpleVector(const SimpleVector& other);
	SimpleVector(SimpleVector&& other);
	~SimpleVector();
	
	const SimpleVector<T>& operator=(const SimpleVector<T>& other_vector);
	SimpleVector<T>& operator=(SimpleVector<T>&& other_vector);
	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	T* begin();
	T* end();

	const T* begin() const;
	const T* end() const;

	size_t size() const;
	size_t capacity() const;
	const T* data() const;

	void push_back(const T& element);

private:
	size_t size_;
	size_t capacity_;
	T* data_ = nullptr;
};

#include "SimpleVector.cpp"
#endif
