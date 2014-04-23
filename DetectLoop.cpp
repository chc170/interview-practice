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
Node( int value, Node *pre) 
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
    NodePtr find( int value );

    void insert( NodePtr ptr, int value);
    inline void insert_front( int value );
    inline void insert_end( int value );
    void insert_node( NodePtr pre, NodePtr ptr );
    
    int remove ( int value );
    inline void remove_front();
    inline void remove_all();

    int has_loop();

private:
    // Prohibiting assignment and initialization
    List( const List& );
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
insert_front( int value ) {
    NodePtr ptr = new Node( value );

    if ( !_head ) {
        _head = _tail = ptr;
    }
    else {
        ptr->next( _head );
        _head = ptr;
    }

    inc_size();
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

void
List::
insert( NodePtr ptr, int value) {
    if ( !ptr ) {
        insert_front( value );
    }
    else {
        if ( ptr == _tail ) {
            insert_end( value );
        }
        else {
            inc_size();
            new Node( value, ptr );
        }
    }
    new Node( value, ptr);
    ++_size;
}

NodePtr
List::
find ( int value ) {
    NodePtr ptr = _head;
    while ( ptr ) {
        if( ptr->value() == value ){
            break;
        }
        else {
            ptr = ptr->next();
        }
    }
    return ptr;
}

inline void
List::
remove_front() {
    if ( _head ) {
        NodePtr ptr = _head;
        _head = _head->next();

        dec_size();
        delete ptr;
    }
}

void 
List::
remove_all() {
    while ( _head )
        remove_front();
    _size = 0;
    _head = _tail = 0;
}

int 
List::
remove( int value ){
    // Remove from head
    NodePtr ptr = _head;
    int elem_cnt = 0;

    while ( ptr && ptr->value() == value ) {
        ptr = ptr->next();
        remove_front();
        ++elem_cnt;
    }

    if ( !ptr )
        return elem_cnt;

    // Remove from middle
    NodePtr pre = _head;
    ptr = _head->next();

    while ( ptr ) {
        if ( ptr->value() == value ) {
            pre->next( ptr->next() );
            delete ptr;
            ++elem_cnt;
            dec_size();
            ptr = ptr->next();
            if ( !ptr ) {
                _tail = pre;
                return elem_cnt;
            }
        }
        else {
            pre = ptr;
            ptr = ptr->next();
        }
    }
    return elem_cnt;
}

void
List::
insert_node( NodePtr pre, NodePtr ptr ) {
    if ( pre && ptr ) {
        pre->next(ptr);
    }
}

int
List::
has_loop() {
    NodePtr first = _head->next();
    NodePtr second = _head->next();
    if ( second )
        second = second->next();
    else
        return -1;

    while ( first && second ) {
        if ( first == second ) {
            int idx = 0;
            NodePtr third = _head;
            cout << third->value() << ",,," << first->value() << endl;
            while ( third != first ) {
                third = third->next();
                first = first->next();
                cout << third->value() << ",,," << first->value() << endl;
                ++idx;
            }
            return idx;
        }

        first = first->next();
        second = second->next();
        if ( second )
            second = second->next();
        else
            return -1;
    }

    return -1;
}

/****************************************
 * Main
 ****************************************/
int main()
{
   List mylist;

   mylist.insert_front(1);
   mylist.insert_front(1);
   mylist.insert_front(2);
   mylist.insert_front(3);
   mylist.insert_front(4);
   mylist.insert_end(5);
   mylist.display();

   //mylist.remove_front();
   mylist.display();

    if ( mylist.has_loop() >= 0 )
        cout << "Has loop\n";
    else
        cout << "No loop\n";

   NodePtr fork = mylist.find(2);
   NodePtr last = mylist.find(5);
   mylist.insert_node( last, fork );

    int idx = 0;
    if ( (idx = mylist.has_loop()) >= 0 )
        cout << "Has loop (" << idx << ")\n";
    else
        cout << "No loop\n";


   return 0;
}
