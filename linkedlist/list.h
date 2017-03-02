/*
Coty Hamilton
*/

#pragma once

using namespace std;

template <typename Object>
class List
{
private:
    struct Node
    {
        Object data;
        Node *next;
        Node *prev;

        Node(Object d = 0, Node *p = NULL, Node *n = NULL)
        {
            data = d;
            prev = p;
            next = n;
        }
    };
public:
    class iterator
    {
        public:
            iterator()
            {
                current = NULL;
            }

            Object & operator*()
            {
                return retrieve();
            }

            iterator & operator--()
            {                       // overload -- to point to previous node
                current = current->prev;
                return *this;
            }

            iterator operator--(int)
            {
                iterator old = *this;
                --(*this);
                return old;
            }

            iterator & operator++()
            {                       // overload ++ to point iterator to next node
                current = current->next;
                return *this;
            }

            iterator operator++(int)
            {
                iterator old = *this;
                ++(*this);
                return old;
            }
            
            bool operator== (iterator & rhs)
            {                       // overload == to check if two iterators are equal
                return current == rhs.current;
            }

            bool operator!= (iterator & rhs)
            {                       // overload != to check if two nodes are not equal
                return !(*this == rhs);
            }
        protected:
            Node *current;

            Object & retrieve()     // returns data from node iterator is pointing to
            {
                return current->data;
            }

            iterator(Node *p)
            {
                current = p;
            }

            friend class List<Object>;
    };

    List()
    {
        head = new Node();          // create dummy nodes head and tail
        tail = new Node();

        head->next = tail;          // link head and tail
        tail->prev = head;

        listSize = 0;               // intialize size of zero
    }

    ~List()
    {
        clear();                    // delete all nodes in list
        delete head;
        delete tail;
    }

    Object & front()
    {
        return *begin();
    }

    Object & back()
    {
        return *--end();
    }

    void push_front(Object x)       // passes first node and data to insert method
    {
        insert(begin(),x);
    }

    void push_back(Object x)        // passes tail to insert and data to insert method
    {
        insert(end(),x);
    }

    void pop_front()                // passes first node to erase
    {
        erase(begin());
    }

    void pop_back()                 // passes last node to erase
    {
        erase(--end());
    }

    int size()                      // return number of nodes in list
    {
        return listSize;
    }

    void print()
    {
        iterator q = end();

        for (iterator p = begin(); p != q; ++p)
        {
            cout << p.retrieve() << " ";
        }

        cout << endl;

    }

    bool empty()                    // returns true if list is empty, false otherwise
    {
        return (size() == 0);
    }

    void clear()                    // deletes every node in list except for head and tail
    {
        while (!empty())
        {
            pop_front();
        }
    }

    iterator begin()                // returns pointer to first node
    {
        return iterator(head->next);
    }
    
    iterator end()                  // returns pointer to tail node
    {
        return iterator(tail);
    }
    
    iterator insert(iterator itr, Object x)
    {                               // inserts a node before the iterator
        Node *p = itr.current;

        listSize++;                 // update list size

        return (p->prev = p->prev->next = new Node (x, p->prev, p));
    }

    iterator erase(iterator itr)
    {                               // deletes node current iterator points to
        Node *p = itr.current;

        iterator retVal(p->next);

        p->prev->next = p->next;
        p->next->prev = p->prev;

        delete p;

        listSize--;

        return retVal;
    }

    iterator erase(iterator from, iterator to)
    {                               // calls erase to delete nodes from one iterator to another
        for (iterator itr = from; itr != to;)
        {
            itr = erase(itr);
        }
        return to;
    }

private:
    int listSize;                   // number of nodes
    Node *head;                     // pointer to the first node
    Node *tail;                     // pointer to the last node
};