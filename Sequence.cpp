//
//  Sequence.cpp
//  Project 2
//
//  Created by Angela Kan on 1/24/21.
//

#include "Sequence.h"

// Constructor: create an empty sequence (i.e., one with no items)
Sequence::Sequence(){
    //head ptr points to a new dummy node
    head = new Node;
    
    head->m_next = head;
    head->m_prev = head;
    
    //0 interesting items in Sequence to start
    m_size = 0;
}

//Destructor: deallocate the nodes in the linked list
Sequence::~Sequence(){
    Node* p = head->m_next;
    
    for (;;){
        //break out of loop if only dummy pointer is left in Sequence
        if (p == head){
            break;
        }
        
        //create tempptr to track location of next node before the current node is deleted
        Node* tempptr = p->m_next;
    
        delete p;   //delete current node p is pointing to
        m_size--;   //decrement size of Sequence
        
        p = tempptr;    //assign p to point to next subsequent node
    }
    
    //delete the dummy node
    delete head;
}

//Copy constructor: allocate enough new nodes to hold a duplicate of the original list
Sequence::Sequence(const Sequence& other){
    m_size = other.m_size;  //copy over m_size
    
    head = new Node;    //create new dummy node and have head point to it
    //have dummy node point to itself
    head->m_next = head;
    head->m_prev = head;
    
    Node* p = head->m_next;
    Node* pother = other.head->m_next;
    for (; pother != other.head; pother = pother->m_next){  //iterating thru other Sequence
        Node* tempptr = new Node;
        tempptr->m_item = pother->m_item;
        //update new node's pointers to next and previous item
        tempptr->m_next = p->m_next;
        tempptr->m_prev = p;
        //update previous and subsequent item's pointers to the new node
        p->m_next = tempptr;
        (tempptr->m_next)->m_prev = tempptr;
        
        p = p->m_next;  //update p to point to the newly allocated node, cycle continues
    }
}

//Assignment operator
Sequence& Sequence::operator=(const Sequence& rhs){
    if (this != &rhs){  //check for aliasing
        Sequence temp(rhs);     //create a temporary copy of Sequence from rhs
        swap(temp);     //swap the temp into the object this ptr is pointing to
    }
    return *this;
}

// Return true if the sequence is empty, otherwise false.
bool Sequence::empty() const {
    if (size() == 0){   //sequence is empty
        return true;
    } else {
        return false;
    }
}

// Return the number of items in the sequence.
int Sequence::size() const {
    return m_size;
}

// Insert value into the sequence so that it becomes the item at
// position pos in the linked list.  The original item at position pos and those that
// follow it end up at positions one higher than they were at before.
// Return pos if 0 <= pos <= size(). Otherwise,
// leave the sequence unchanged and return -1.  Notice that
// if pos is equal to size(), the value is inserted at the end.
int Sequence::insert(int pos, const ItemType& value) {
    if (pos >= 0 && pos <= size()){     //make sure item exists at pos
        Node* p;
        int currentPos;
        for (p = head, currentPos = -1; currentPos < pos-1; p=p->m_next, currentPos++){
            ;   //empty statement, p ends up pointing at node right before the pos we want to insert at
        }
        
        //insert node
        Node* newptr = new Node;    //create newptr pointing at new node
        newptr->m_item = value;     //initialize value of new node
        //update new node's pointers to next and previous item
        newptr->m_next = p->m_next;
        newptr->m_prev = p;
        //update previous and subsequent item's pointers to the new node
        p->m_next = newptr;
        (newptr->m_next)->m_prev = newptr;

        m_size++;   //increment size of Sequence
        return pos;
    }
    return -1;
}

// Let p be the smallest integer such that value <= the item at
// position p in the sequence; if no such item exists (i.e.,
// value > all items in the sequence), let p be size().  Insert
// value into the sequence so that it becomes the item in position
// p.  The original item at position p and those that follow it end
// up at positions one higher than before.  Return p if the value
// was actually inserted.  Return -1 if the value was not inserted
// (should never happen).
int Sequence::insert(const ItemType& value){
    Node* p = head->m_next;
    int currentPos = 0;
    
    //locate and have p end up pointing to first node containing item that value is <= to
    for (; p != head && p->m_item < value; p = p->m_next, currentPos++){
        ;
    }
    
    //move p back so it's pointing at the node right before the pos u want to insert at
    p = p->m_prev;

    //insert node
    Node* newptr = new Node;
    newptr->m_item = value;     //initialize value of new node
    //update new node's pointers to next and previous item
    newptr->m_next = p->m_next;
    newptr->m_prev = p;
    //update previous and subsequent item's pointers to the new node
    p->m_next = newptr;
    (newptr->m_next)->m_prev = newptr;

    m_size++;   //increment size of Sequence
    
    return currentPos;
}

// If 0 <= pos < size(), remove the item at position pos from
// the sequence (so that all items that followed that item end up at
// positions one lower than they were at before), and return true.
// Otherwise, leave the sequence unchanged and return false.
bool Sequence::erase(int pos){
    if (pos >= 0 && pos < size()){  //check that item at pos exists
        Node* p = head->m_next;
        int currentPos = 0;
        //locate node at pos and leave p pointing to it when it exits the for loop
        for (; currentPos < pos; p = p->m_next, currentPos++){
            ;
        }
        //delete node
        (p->m_prev)->m_next = p->m_next;    //update pointers of previous/subsequent nodes
        (p->m_next)->m_prev = p->m_prev; 
        delete p;   //delete node
        
        m_size--;   //decrement size of Sequence
        return true;
    }
    return false;
}

// Erase all items from the sequence that == value.  Return the
// number of items removed (which will be 0 if no item == value)
int Sequence::remove(const ItemType& value){
    int count = 0;  //keep track of number of items removed
    
    //iterate through sequence, update p each time
    for (Node* p = head->m_next; p != head; p = p->m_next){
        if (p->m_item == value){
            Node* tempptr = p->m_prev;  //keep track of location of node prior to p with a temporary pointer
            
            //delete node
            (p->m_prev)->m_next = p->m_next;    //update pointers of previous/subsequent nodes
            (p->m_next)->m_prev = p->m_prev;
            delete p;   //delete node
            
            m_size--;    //decrement size of Sequence
            count++;    //increment count of removed items
            p = tempptr;    //reassign p to point to node right before the node that was just deleted
        }
    }
    return count;
}

// If 0 <= pos < size(), copy into value the item at position pos
// of the sequence and return true.  Otherwise, leave value unchanged
// and return false.
bool Sequence::get(int pos, ItemType& value) const {
    if (pos >= 0 && pos < size()){  //check that pos is within Sequence bounds
        Node* p = head->m_next;
        int currentPos = 0;
        //locate node at pos and leave p pointing to it when it exits the for loop
        for (; currentPos < pos; p = p->m_next, currentPos++){
            ;
        }
        value = p->m_item;  //copy into value item at position pos of the sequence
        return true;
    }
    return false;
}

// If 0 <= pos < size(), replace the item at position pos in the
// sequence with value and return true.  Otherwise, leave the sequence
// unchanged and return false.
bool Sequence::set(int pos, const ItemType& value){
    if (pos >= 0 && pos < size()){  //check that pos is within Sequence bounds
        Node* p = head->m_next;
        int currentPos = 0;
        //locate node at pos and leave p pointing to it when it exits the for loop
        for (; currentPos < pos; p = p->m_next, currentPos++){
            ;
        }
        p->m_item = value;  //replace the item at position pos in Sequence with value
        return true;
    }
    return false;
}

// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.
int Sequence::find(const ItemType& value) const{
    int p;
    Node* ptr = head->m_next;
    //locate and have ptr end up pointing to first node containing item that value is equal to
    for (p=0; ptr != head && ptr->m_item != value; ptr = ptr->m_next, p++){
        ;
    }
    //ptr is now pointing to correct node or the dummy node
    if (ptr == head){   //if ptr is pointing at dummy node, no item == value so update p accordingly
        p = -1;
    }
    return p;   //-1 if no item match, otherwise the position of node with item match
}

// Exchange the contents of this sequence with the other one.
void Sequence::swap(Sequence& other){
    //swap the nodes the head pointers are pointing to
    Node* tempPtr = head; //use a temporary ptr to hold what head is currently pointing to
    head = other.head;
    other.head = tempPtr;
    
    //swap the int values for m_size
    int tempSize = size();  //use a temporary variable to hold the m_size
    m_size = other.size();
    other.m_size = tempSize;
}

//Non-member function implementations

int subsequence(const Sequence& seq1, const Sequence& seq2){
    if (seq2.empty()){  //if seq2 has no elements
        return -1;
    }
    if (&seq1 == &seq2){    //account for aliasing case
        return 0;
    }
    bool isSubsequence = false;     //boolean to track presence of subsequence
    ItemType match2start;
    seq2.get(0, match2start);   //assign first element at pos 0 in seq2 to match2start
    //iterate through seq 1 elements
    for (int i=0; i<seq1.size(); i++){
        ItemType match1;
        seq1.get(i, match1);
        //if any element in seq 1 matches match2start, continue checking the rest of the subsequence
        if (match1 == match2start){
            isSubsequence = true;   //update isSubsequence to true
            int j;  //keep track of position in seq2
            //iterate through seq2 while making sure you don't surpass bounds of seq1, checking for continued subsequence match
            for (j=1; j<seq2.size() && (i+j)<seq1.size(); j++){
                ItemType match2all;
                seq2.get(j, match2all);
                seq1.get(i+j, match1);
                //if at any point of checking subsequence doesn't match, update isSubsequence to false
                if (match1 != match2all){
                    isSubsequence=false;
                }
            }
            //if made it through the entire seq2 and there is a complete match for it in seq1, return pos of match beginning in seq1
            if (j == seq2.size() && isSubsequence){
                return i;
            }
        }
    }
    //otherwise, if no match, return -1
    return -1;
}

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result){
    Sequence tempSeq;   //create a temporary Sequence
    //find sizes of seq1 and seq2
    int s1size = seq1.size();
    int s2size = seq2.size();
    
    for (int i=0; i < (s1size+s2size); i++){    //iterate through as many times as there are elements to insert (size 1 + 2)
        ItemType tempVal;   //create tempVal to store values
        //for when seq1 is bigger
        if (s1size > s2size){
            if (i<s2size*2){      //portion of i when both s1 and s2 have elements
                if (i%2 == 0){      //insert s1 elements for even positions
                    seq1.get(i/2, tempVal);
                    tempSeq.insert(i, tempVal);
                    continue;
                } else if (i%2 == 1){    //insert s2 elements for odd positions
                    seq2.get(i/2, tempVal);
                    tempSeq.insert(i, tempVal);
                    continue;
                }
            } else if (i>=s2size*2){
                seq1.get(i-s2size, tempVal);    //portion of i when only s1 is left, insert all those remaining elements
                tempSeq.insert(i, tempVal);
                continue;
            }
        //execute when s2 is bigger
        } else if (s1size < s2size){
            if (i<s1size*2){      //portion of i when both s1 and s2 have elements
                if (i%2 == 0){  //insert s1 elements for even positions
                    seq1.get(i/2, tempVal);
                    tempSeq.insert(i, tempVal);
                    continue;
                } else if (i%2 == 1){    //insert s2 elements for odd positions
                    seq2.get(i/2, tempVal);
                    tempSeq.insert(i, tempVal);
                    continue;
                }
            } else if (i>=s1size*2){    //portion of i when only s2 is left, insert all those remaining elements
                seq2.get(i-s1size, tempVal);
                tempSeq.insert(i, tempVal);
                continue;
            }
        //if seq1 length = seq2 length
        } else if (s1size == s2size){
            if (i%2 == 0){  //insert s1 elements for even positions
                seq1.get(i/2, tempVal);
                tempSeq.insert(i, tempVal);
                continue;
            } else if (i%2 == 1){    //insert s2 elements for odd positions
                seq2.get(i/2, tempVal);
                tempSeq.insert(i, tempVal);
                continue;
            }
        }
    }
    
    //swap the tempSeq into result
    result.swap(tempSeq);
}
