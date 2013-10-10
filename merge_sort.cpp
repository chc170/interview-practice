#include <iostream>

using namespace std;

/****************************************
 * Node
 ****************************************/
class Node {
public:
    // constructor
    Node ( int value, Node *pre = 0);
    
    // get value
    int value() { return _value; }
    Node *next() { return _next; }
    
    // set value
    void value( int new_value ) { _value = new_value; }
    void next( Node *new_next ) { _next = new_next; }
    
private:
    int _value;
    Node *_next;
};

typedef Node* NodePtr;

inline 
Node::
Node( int value, NodePtr pre) 
    : _value( value )
{
    if ( !pre ) {
        _next = 0;
    }
    else {
        _next = pre->_next;
        pre->_next = this;
    }
}

/****************************************
 * List
 ****************************************/
class List {
public:
    List () : _head (0), _tail(0), _size(0) {}
    inline int size();
    void display();

    inline void insert_end( int value );
    NodePtr head() { return _head; }
    

private:
    // Prohibiting assignment and initialization
    //List( const List& );
    List& operator= ( const List& );

    // Members
    NodePtr _head;
    NodePtr _tail;
    int _size;
    void inc_size() { ++_size; }
    void dec_size() { --_size; }
};

inline int 
List::
size() {
    return _size;
}

inline void
List::
display () {
    cout << "\n(" << _size << ")(";

    NodePtr ptr = _head;
    while ( ptr ) {
        cout << ptr->value() << " ";
        ptr = ptr->next();
    }

    cout << ")\n";
}

inline void
List::
insert_end( int value ) {
    if ( !_tail ) {
        _tail = _head = new Node( value );
    }
    else {
        _tail = new Node( value, _tail );
    }

    inc_size();
}

/****************************************
 * Main
 ****************************************/

List *merge( List a, List b) {
	NodePtr ptr_a = a.head();
	NodePtr ptr_b = b.head();

	List *result = new List();

	int status = 0;
	if ( ptr_a ) 
		status = status | 1;
	if ( ptr_b )
		status = status | 2;

	while ( status > 0 ) {
		switch (status) {
			case 1:
				while ( ptr_a ) {
					result->insert_end( ptr_a->value() );
					ptr_a = ptr_a->next();
				}
				return result;
				break;
			case 2:
				while ( ptr_b ) {
					result->insert_end( ptr_b->value() );
					ptr_b = ptr_b->next();
				}
				return result;
				break;
			case 3:
				if ( ptr_a->value() <= ptr_b->value() ) {
					result->insert_end( ptr_a->value() );
					ptr_a = ptr_a->next();
				}
				else {
					result->insert_end( ptr_b->value() );
					ptr_b = ptr_b->next();
				}
				break;
			default:
				return NULL;
		}

		status = 0;
		if ( ptr_a ) 
			status = status | 1;
		if ( ptr_b )
			status = status | 2;
	}
}

 int main() {
 	List list_a;
 	list_a.insert_end(2);
 	list_a.insert_end(5);
 	list_a.insert_end(6);
 	list_a.insert_end(8);
 	list_a.insert_end(9);
 	list_a.insert_end(17);
 	list_a.insert_end(17);
 	list_a.insert_end(17);
 	list_a.insert_end(19);
 	list_a.display();

 	List list_b;
 	list_b.insert_end(1);
 	list_b.insert_end(7);
 	list_b.insert_end(7);
 	list_b.insert_end(7);
 	list_b.insert_end(10);
 	list_b.display();

 	List *a = merge( list_a, list_b );
 	a->display();

 	return 0;
 }