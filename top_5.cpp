#include <iostream>
#include <cstdlib>

using namespace std;

static const int MAX_SIZE = 5;

class Prio_Queue {
public:
	Prio_Queue ();
	void enqueue( int value );
	void dequeue();
	void display();

private:
	int _size;
	int _queue[MAX_SIZE + 1];
};

Prio_Queue::
Prio_Queue() 
	: _size(0) 
{
	for ( int i = 0; i < MAX_SIZE + 1; _queue[i++] = 0 );
}

void
Prio_Queue::
enqueue( int value ) {
	// Add new value
	_queue[_size] = value;

	int idx = _size;
	int parent = (idx - 1) / 2;
	while ( idx != parent && _queue[idx] < _queue[parent] ) {
		int tmp = _queue[idx];
		_queue[idx] = _queue[parent];
		_queue[parent] = tmp;

		idx = parent;
		parent = (idx - 1) / 2;
	}

	++_size;

	// Remove extra
	if ( _size > MAX_SIZE )
		dequeue();
}

void 
Prio_Queue::
dequeue() {
	if ( _size <= 1) {
		_size = 0;
		_queue[0] = 0;
		return;
	}

	--_size;

	_queue[0] = _queue[_size];
	_queue[_size] = 0;

	int idx = 0;
	int child = 2 * idx + 1;

	while ( child < _size ) {

		if ( (child != _size - 1) && (_queue[child] > _queue[child + 1])) {
			++child;
		}

		if ( _queue[idx] > _queue[child] ) {
			int tmp = _queue[idx];
			_queue[idx] = _queue[child];
			_queue[child] = tmp;
		}
		else {
			break;
		}

		idx = child;
		child = 2 * idx + 1;
	}
}

void 
Prio_Queue::
display() {
	for (int i = 0; i < _size; i++){
		cout << _queue[i] << " ";
	}
	cout << endl;
}

int main() {
	srand( time(NULL) );


	// Create raw data
	int my_arr[20];
	for ( int i = 0; i < 20; i++ ){
		my_arr[i] = rand() % 100;
		cout << my_arr[i] << " ";
	}
	cout << endl;

	// Insert to priority queue
	Prio_Queue pq;
	for ( int i = 0; i < 20; i++ ) {
		pq.enqueue(my_arr[i]);
	}

	pq.display();

	return 0;
}