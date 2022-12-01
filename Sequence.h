//
//  Sequence.h
//  Project 2
//
//  Created by Angela Kan on 1/24/21.
//

#ifndef SEQUENCE_INCLUDED
#define SEQUENCE_INCLUDED

#include <string>
using ItemType = std::string;

class Sequence
{
  public:
    Sequence();
    ~Sequence();
    Sequence(const Sequence& other);
    Sequence& operator=(const Sequence& rhs);
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
  private:
    struct Node {
        ItemType m_item;
        Node* m_next;
        Node* m_prev;
    };
    
    Node* head;
    int m_size;
};

//Non-member function declarations
int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif /* SEQUENCE_INCLUDED */
