#ifndef simple_vector
#define simple_vector
#include<cstddef>
#include<utility>
#include<algorithm>

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
	void reserve(size_t new_cap);

	void push_back(const T& element);
	void push_back(T&& element);
	void pop_back();
	void resize(size_t new_size);

private:
	size_t size_ = 0;
	size_t capacity_ = 0;
	T* data_ = nullptr;

	static T* allocate(size_t n) {
		return static_cast<T*>(operator new(n*sizeof(T)));
	}

	static void deallocate(T* buf) {
		operator delete(buf);
	}

	static void construct(void* buf) {
		new(buf) T();
	}
	static void construct(void* buf, const T& element) {
		new(buf) T(element);
	}
	static void construct(void* buf, T&& element) {
		new(buf) T(std::move(element));
	}
	static void destroy(T* buf) {
		buf->~T();
	}
};





template<class T>
SimpleVector<T>::SimpleVector(size_t size)
		 : size_(size),
		   data_(allocate(size)),
		   capacity_(size)
{
	for(size_t i = 0; i < size; ++i) {
		construct(data_ + i);
	}
}


template<class T>
SimpleVector<T>::SimpleVector(const SimpleVector<T>& other)
	: size_(other.size_),
	  capacity_(other.size_),
	  data_(allocate(other.size_))
{
	for(size_t i = 0; i < size_; ++i) {
		construct(data_ + i, other[i]);
	}
}

	
template<class T>
SimpleVector<T>::SimpleVector(SimpleVector<T>&& other)
	: size_(other.size_), 
	  capacity_(other.capacity_),
	  data_(other.data_)
{
	other.data_ = nullptr;
	other.size_ = other.capacity_ = 0;
}


template<class T>
const SimpleVector<T>& SimpleVector<T>::operator=(const SimpleVector<T>& other){
	if(this != &other) {
		delete[] data_;
		size_ = other.size_;
		capacity_ = other.capacity_;
		data_ = new T[capacity_];
		std::copy(other.begin(), other.end(), data_);
	}
		return *this;
}


template<class T>
SimpleVector<T>& SimpleVector<T>::operator=(SimpleVector<T>&& other){
	if(this != &other) {
		delete[] data_;
		data_ = other.data_;
		size_ = other.size_;
		capacity_ = other.capacity_;

		other.data_ = nullptr;
		other.size_ = other.capacity_ = 0;
	}
	return *this;
}


template<class T>
SimpleVector<T>::~SimpleVector(){
	if(data_){
		for(size_t i = 0; i < size_; ++i) {
			destroy(data_ + i);
		}
		deallocate(data_);
	}
}

template<class T>
T* SimpleVector<T>::begin() {
	return data_;
}

template<class T>
T* SimpleVector<T>::end() {
	return data_ + size_;
}

template<class T>
const T* SimpleVector<T>::begin() const {
	return data_;
}

template<class T>
const T* SimpleVector<T>::end() const {
	return data_ + size_;
}

template<class T>
size_t SimpleVector<T>::size() const {
	return size_;
}

template<class T>
size_t SimpleVector<T>::capacity() const {
	return capacity_;
}

template<class T>
const T* SimpleVector<T>::data() const {
	return data_;
}

template<class T>
void SimpleVector<T>::reserve(size_t new_cap) {
	if(new_cap > capacity_) {
		auto data2 = allocate(new_cap);
		for(size_t i = 0; i < size_; ++i) {
			construct(data2 + i, std::move(data_[i]));
		destroy(data_ + i);
		}
		deallocate(data_);
		data_ = data2;
		capacity_ = new_cap;
	}
}

template<class T>
void SimpleVector<T>::push_back(const T& element) {
	if(size_ >= capacity_){
		size_t new_cap = (capacity_ == 0) ? 1 : 2*capacity_;
		T* new_data = new T[capacity_];
		std::copy(begin(), end(), new_data);
		delete[] data_;
		data_ = new_data;
		capacity_ = new_cap;
	}
	data_[size_++] = element;
}

template<class T>
T& SimpleVector<T>::operator[](size_t index) {
	return data_[index];
}

template<class T>
const T& SimpleVector<T>::operator[](size_t index) const {
	return data_[index];
}


#endif
