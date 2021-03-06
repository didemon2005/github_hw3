//#include "Headers.hpp"
#ifndef _QUEUEL_H
#define _QUEUEL_H
#include "Headers.hpp"
#include "Semaphore.hpp"
// Single Producer - Multiple Consumer queue
template <typename T>class PCQueue
{

public:
//	PCQueue():avail_items(0),producer(1),item_queue(){}
	PCQueue():mutex(),avail_items(0),producer(1),item_queue(){}
	// Blocks while queue is empty. When queue holds items, allows for a single
	// thread to enter and remove an item from the front of the queue and return it. 
	// Assumes multiple consumers.
	T pop(){
		avail_items.down();
		pthread_mutex_lock(&mutex);
		T item=item_queue.front();
		item_queue.pop();
		pthread_mutex_unlock(&mutex);
		return item;
	}
	
	
	// Allows for producer to enter with *minimal delay* and push items to back of the queue.
	// Hint for *minimal delay* - Allow the consumers to delay the producer as little as possible.  
	// Assumes single producer
	void push(const T& item){
		producer.down();
		pthread_mutex_lock(&mutex);
		item_queue.push(item);
		pthread_mutex_unlock(&mutex);
		avail_items.up();
		producer.up();
	}
	

private:
	// Add your class memebers here
	pthread_mutex_t mutex;
	Semaphore avail_items;
	Semaphore producer;
	std::queue<T> item_queue;

};

// Recommendation: Use the implementation of the std::queue for this exercise
#endif