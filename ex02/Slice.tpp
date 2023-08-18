/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Slice.tpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 16:30:50 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/18 16:26:22 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Slice.hpp"

template <typename T>
Slice<T>::Slice() : _nums(nullptr), _start(0), _end(0) {}
template <typename T>
Slice<T>::Slice(T &nums) : _nums(&nums), _start(0), _end(nums.size()) {}
template <typename T>
Slice<T>::Slice(T &nums, size_t start) : _nums(&nums), _start(start), _end(nums.size()) {}
template <typename T>
Slice<T>::Slice(T &nums, size_t start, size_t end) : _nums(&nums), _start(start), _end(end) {}

template<typename T>
Slice<T>::Slice(Slice const & src) {
	*this = src;
}

template<typename T>
Slice<T>::~Slice(void) {
}

template<typename T>
Slice<T> & Slice<T>::operator=(Slice<T> const & src) {
	if (this == &src)
		return (*this);
	_nums = src._nums;
	_start = src._start;
	_end = src._end;
	return (*this);
}

template <typename T>
typename T::value_type &Slice<T>::operator[](size_t index) {
	return (*std::next(_nums->begin(), index + _start));
}

template <typename T>
Slice<T> Slice<T>::slice(size_t start, size_t end) const {
	return (Slice(*_nums, _start + start, _start + end));
}

template <typename T>
Slice<T> Slice<T>::slice(size_t start) const {
	return (Slice(*_nums, _start + start, _end));
}

template <typename T>
size_t Slice<T>::size() const {
	return (_end - _start);
}

template <typename T>
void	Slice<T>::erase(size_t from_index) {
	_nums->erase(std::next(_nums->begin(), _start + from_index));
}

template <typename T>
void	Slice<T>::insert(size_t to_index, typename T::value_type value) {
	_nums->insert(std::next(_nums->begin(), _start + to_index), value);
}

template <typename T>
void	Slice<T>::move(size_t from_index, size_t to_index) {
	if (from_index == to_index) {
		return ;
	}
	int tmp = (*this)[from_index];
	if (from_index < to_index) {
		this->erase(from_index);
		this->insert(to_index, tmp);
	}
	else {
		this->erase(from_index);
		this->insert(to_index + 1, tmp);
	}
}
