#include "sequence2.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

namespace main_savitch_4{
	
	// CONSTRUCTORS and DESTRUCTOR
	sequence::sequence(size_type initial_capacity){
		capacity = DEFAULT_CAPACITY;
		used = 0;
		current_index = 0;
		data = new value_type[capacity];		
	}
	
	sequence::sequence(const sequence& source){
		capacity = source.capacity;
		used = source.used;
		current_index = source.current_index;
		data = new value_type[source.capacity];
		copy(source.data, source.data + source.capacity, data);
	}
	
	sequence::~sequence( ){
		delete [] data;;
	}
	
	// MODIFICATION MEMBER FUNCTIONS
	void sequence::resize(size_type new_capacity){
		if (new_capacity > used){
			value_type* new_data = new value_type[new_capacity];
			copy(data, data + used, new_data);
			delete [] data;
			capacity = new_capacity;
			data = new_data;
		}
	};
	
	void sequence::start( ){
		current_index = 0;
	}
	
	void sequence::advance( ){
		if (is_item() == true){
			current_index++;
		}
	}
	
	void sequence::insert(const value_type& entry){
		if (used == capacity){
			resize(capacity + DEFAULT_CAPACITY);
		}
		if (is_item()){
			for (unsigned int i = used ; i > current_index; i-- ){
				data[i] = data[i-1];
			}
			data[current_index] = entry;
			used ++;
		} else{
			current_index = 0;
			data[current_index] = entry;
			used ++;
		}
	}
	
	void sequence::attach(const value_type& entry){
		if (used == capacity){
			resize(capacity + DEFAULT_CAPACITY);
		}
		if (is_item()){
			for (unsigned int i = used ; i > current_index + 1; i -- ){
				data[i] = data[i-1];
			}
			data[current_index + 1] = entry;
			current_index++;
			used ++;
		}
		else {
			current_index = 0;
			data[current_index] = entry;
			used ++;
		}
	}
	
	
	void sequence::remove_current( ){
		if (is_item()){
			if (used == 1){
				used = 0;
				current_index = 0;
			}
			else {
				for (unsigned int i = current_index; i < used; i ++ ){
					data[i] = data[i + 1];
				}
				used--;
			}
		}
	}
	
	
	void sequence::operator =(const sequence& source){
		if (&source == this){
			return;
		}
		else {
			value_type *new_data = new value_type[source.capacity];
			copy(source.data, source.data + source.capacity, new_data);
			delete data;
			data = new_data;
			used = source.used;
			capacity = source.capacity;
			current_index = source.current_index;
		}
	}
	
	// CONSTANT MEMBER FUNCTIONS
	sequence::size_type sequence::size( ) const{
		return used;
	}
	
	bool sequence::is_item( ) const{
		if (current_index >= 0 && current_index < used){
			return true;
		}
		else {
			return false;
		}
	};
	
	
	sequence::value_type sequence::current( ) const{
		return data[current_index];
	}
	
	
};










