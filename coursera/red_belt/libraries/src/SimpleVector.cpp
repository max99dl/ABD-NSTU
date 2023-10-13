//#include "/home/maxim/git/ABD-NSTU/coursera/red_belt/libraries/src/SimpleVector.h"

template<class T>
SimpleVector<T>::SimpleVector(size_t size)
		 : size_(size), 
		   data_( new T[size_]),
		   capacity_(size) {}

template<class T>
SimpleVector<T>::SimpleVector(const SimpleVector<T>& other)
	: size_(other.size_), 
	  capacity_(other.capacity_),
	  data_(new T[other.capacity_])
{
	std::copy(other.begin(), other.end(), data_);
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
	delete[] data_;
	size_ = other.size_;
	capacity_ = other.capacity_;
	data_ = new T[capacity_];
	std::copy(other.begin(), other.end(), data_);
	
	return *this;
}


template<class T>
SimpleVector<T>& SimpleVector<T>::operator=(SimpleVector<T>&& other){
	delete[] data_;
	data_ = other.data_;
	size_ = other.size_;
	capacity_ = other.capacity_;

	other.data_ = nullptr;
	other.size_ = other.capacity_ = 0;

	return *this;
}


template<class T>
SimpleVector<T>::~SimpleVector(){
	if(data_){
		delete[] data_;
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


/*if we want to build independently we must instantiate all possible types, example
	SimpleVector<int>
	SimpleVector<double>
	SimpleVector<std::string>
	SimpleVector<bool>
*/
