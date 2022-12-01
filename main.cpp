//
//  main.cpp
//  Project 2
//
//  Created by Angela Kan on 1/24/21.
//
//#include "Sequence.h"
//#include <string>
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Sequence s;
//    assert(s.insert(0, "lavash") == 0);
//    assert(s.insert(0, "tortilla") == 0);
//    assert(s.size() == 2);
//    ItemType x = "injera";
//    assert(s.get(0, x)  &&  x == "tortilla");
//    assert(s.get(1, x)  &&  x == "lavash");
//}
//
//int main()
//{
//    test();
//    cout << "Passed all tests" << endl;
//}

//#include "Sequence.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Sequence s;
//    assert(s.insert(0, 10) == 0);
//    assert(s.insert(0, 20) == 0);
//    assert(s.size() == 2);
//    ItemType x = 999;
//    assert(s.get(0, x)  &&  x == 20);
//    assert(s.get(1, x)  &&  x == 10);
//}
//
//int main()
//{
//    test();
//    cout << "Passed all tests" << endl;
//}

//#include "Sequence.h"
//#include <iostream>
//#include <cassert>
//using namespace std;

//int main()
//{
//    Sequence s;
//    assert(s.empty());
//    assert(s.find(42) == -1);
//    assert(s.insert(42) == 0);
//    assert(s.size() == 1  &&  s.find(42) == 0);
//
//
//
// Sequence a;
// a.insert(0, 4);
// a.insert(1, 6);
// a.insert(2, 4);
// a.insert(3, 9);
// a.insert(4, 3);
// a.insert(5, 2);
//    assert(!a.empty());
//    assert(a.size()==6);
//    assert(a.find(9)==3);
//    assert(a.insert(8)==3);
//// a = (4,6,4,8,9,3,2)
//    assert(a.find(3)==5);
//    assert(a.size()==7);
//    assert(a.erase(-1)==false);
//    assert(a.erase(7)==false);
//    assert(a.erase(3)==true);
//   // a = (4,6,4,9,3,2)
//   assert(a.remove(7)==0);
//   assert(a.remove(4)==2);
//   //a = (6,9,3,2)
//   assert(a.size()==4);
//   assert(a.find(9)==1);
//   ItemType testGet = 9;
//    assert(a.get(4,testGet)==false);
//   assert(a.get(3,testGet)==true);
//    assert(testGet==2);
//    testGet = 9;
//    assert(a.set(3,testGet)==true);
//   assert(a.set(-1,testGet)==false);
//   //a = (6,9,3,9)
//Sequence b;
//b.insert(0, 0);
//b.insert(1, 1);
//b.insert(2, 2);
//b.insert(3, 3);
//b.insert(4, 4);
//b.insert(5, 5);
//b.insert(6, 6);
//
//   assert(!b.empty());
//   assert(b.size()==7);
//
//   b.swap(a);
//   assert(b.size()==4);
//   assert(b.find(9)==1);
//   assert(b.find(3)==2);
//
//    assert(a.size()==7);
//        assert(a.find(5)==5);
//        assert(a.find(6)==6);
//    assert(a.find(7)==-1);
//
//
//     cout << "Passed all tests" << endl;
//}

//#include "Sequence.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//int main(){
//    Sequence b;
//    b.insert(0, 30);
//    b.insert(1, 21);
//    b.insert(2, 63);
//    b.insert(3, 17);
//    b.insert(4, 17);
//    b.insert(5, 63);
//    b.insert(6, 17);
//    b.insert(7, 29);
//    b.insert(8, 8);
//    b.insert(9, 32);
//
//    Sequence a;
//    a.insert(0, 63);
//    a.insert(1, 17);
//    a.insert(2, 29);
//
//    Sequence c;
//    c.insert(0, 17);
//    c.insert(1, 63);
//    c.insert(2, 29);
//
//    Sequence d;
//    d.insert(0, 29);
//    d.insert(1, 8);
//    d.insert(2, 32);
//
//    Sequence e;
//    e.insert(0, 32);
//    e.insert(1, 2);
//
//    Sequence f;
//
//    assert(subsequence(b, a) == 5);
//    assert(subsequence(b, b) == 0);
//    assert(subsequence(b, c) == -1);
//    assert(subsequence(b, d) == 7);
//    assert(subsequence(b, e) == -1);
//    assert(subsequence(b, f) == -1);
//    cout << "Passed all tests" << endl;
//}

//#include "Sequence.h"
//#include <type_traits>
//
//#define CHECKTYPE(c, f, r, a)  \
//    {  \
//     static_assert(std::is_same<decltype(&c::f), r (c::*)a>::value, \
//         "You did not declare " #c "::" #f " as the spec does");  \
//     r (c::*p) a = &c::f;  \
//     (void) p;  \
//    }
//#define CHECKTYPENONMEMBER(f, r, a)  \
//    {  \
//     static_assert(std::is_same<decltype(&f), r (*)a>::value, \
//         "You did not declare " #f " as the spec does");  \
//     r (*p) a = f;  \
//     (void) p;  \
//    }
//
//static_assert(std::is_default_constructible<Sequence>::value,
//    "Sequence must be default-constructible.");
//static_assert(std::is_copy_constructible<Sequence>::value,
//    "Sequence must be copy-constructible.");
//static_assert(std::is_copy_assignable<Sequence>::value,
//    "Sequence must be assignable.");
//
//void thisFunctionWillNeverBeCalled()
//{
//    CHECKTYPE(Sequence, empty, bool, () const);
//    CHECKTYPE(Sequence, size, int, () const);
//    CHECKTYPE(Sequence, erase, bool, (int));
//    CHECKTYPE(Sequence, remove, int, (const ItemType&));
//    CHECKTYPE(Sequence, get, bool, (int, ItemType&) const);
//    CHECKTYPE(Sequence, set, bool, (int, const ItemType&));
//    CHECKTYPE(Sequence, find, int, (const ItemType&) const);
//    CHECKTYPE(Sequence, swap, void, (Sequence&));
//    CHECKTYPENONMEMBER(subsequence, int, (const Sequence&, const Sequence&));
//    CHECKTYPENONMEMBER(interleave, void, (const Sequence&, const Sequence&, Sequence&));
//    { auto p = static_cast<int (Sequence::*)(int, const ItemType&)>(&Sequence::insert); (void) p; }
//    { auto p = static_cast<int (Sequence::*)(const ItemType&)>(&Sequence::insert); (void) p; }
//}
//
//int main()
//{}

//#include "Sequence.h"
//#include <string>
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Sequence s;
//    assert(s.insert(0, "lavash") == 0);
//    assert(s.insert(0, "tortilla") == 0);
//    assert(s.size() == 2);
//    ItemType x = "injera";
//    assert(s.get(0, x)  &&  x == "tortilla");
//    assert(s.get(1, x)  &&  x == "lavash");
//}
//
//int main()
//{
//    test();
//    cout << "Passed all tests" << endl;
//}
//#include "Sequence.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Sequence s;
//    assert(s.insert(0, 10) == 0);
//    assert(s.insert(0, 20) == 0);
//    assert(s.size() == 2);
//    ItemType x = 999;
//    assert(s.get(0, x)  &&  x == 20);
//    assert(s.get(1, x)  &&  x == 10);
//}
//
//int main()
//{
//    test();
//    cout << "Passed all tests" << endl;
//}

//
#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main(){
    //default constructor
    Sequence a;

    assert(a.insert(0, 10) == 0);   //test insert
    assert(a.insert(0, 20) == 0);   //test insert before first obj
    assert(a.size() == 2);  //test size w/ objects
    ItemType x = 999;
    assert(a.get(0, x)  &&  x == 20);
    assert(a.get(1, x)  &&  x == 10);
    assert(a.find(10) == 1); //find at pos 1 (end)
    assert(a.find(20) == 0); //find at pos 0

    Sequence s; //default constructor
    // For an empty sequence:
    assert(s.size() == 0);             // test size
    assert(s.empty());                 // test empty
    assert(s.remove(0) == 0);  // nothing to remove
    assert(s.insert(3) == 0); //insert value into empty seq
    assert(s.insert(4) == 1);   //insert value at end
    assert(s.insert(4) == 1); //insert same value properly
    assert(s.erase(0) && s.get(0, x) && x == 4);    //erase pos 0
    assert(s.erase(2) == false);    //invalid pos for erase
    assert(s.find(4) == 0);     //find returns smallest pos

    Sequence e(s); //copy constructor
    s=a;   //assinment operator
    assert(s.size() == 2);

    Sequence b(a);  //copy constructor
    assert(b.size() == 2 && b.get(0, x)  &&  x == 20 && b.empty() == false);    //test not empty
    assert(b.insert(2, 3) == 2 && b.get(2, x)  &&  x == 3);  //insert at size()
    assert(b.insert(4, 1) == -1); //insert w/ invalid pos
    assert(b.insert(3) == 0);   //insert value at beginning (pos 0)
    assert(b.erase(0) && b.find(3) == 2); //erase item at pos 0
    assert(b.remove(20) == 1);  //remove one element
    assert(b.insert(20) == 2);  //setting up for next remove test
    assert(b.insert(20) == 2); //setting up for next remove test
    assert(b.remove(20) == 2); //remove two consecutive elements
    assert(b.get(0, x) && x == 10); //get pos 0
    assert(b.get(b.size(), x) == false && x == 10); //invalid pos for get
    assert(b.set(0, 20) && b.get(0, x) && x == 20); //set at pos 0
    assert(b.set(b.size(), 20) == false && b.get(0, x) && x == 20);    //invalid pos for set
    assert(b.find(22) == -1); //can't find item

    Sequence d;
    d.swap(e); //swap function
    assert(d.size() == 2 && e.size() == 0 && d.find(4) == 0);  //check if swap function worked

    //setting up tests for subsequence and interleave
        Sequence g;
        g.insert(0, 30);
        g.insert(1, 21);
        g.insert(2, 63);
        g.insert(3, 17);
        g.insert(4, 17);
        g.insert(5, 63);
        g.insert(6, 17);
        g.insert(7, 29);
        g.insert(8, 8);
        g.insert(9, 32);

        Sequence h;
        h.insert(0, 63);
        h.insert(1, 17);
        h.insert(2, 29);

        Sequence i;
        i.insert(0, 17);
        i.insert(1, 63);
        i.insert(2, 29);

        Sequence j;
        j.insert(0, 29);
        j.insert(1, 8);
        j.insert(2, 32);

        Sequence k;
        k.insert(0, 32);
        k.insert(1, 2);

        Sequence f;

        Sequence m;

        Sequence l;
        l.insert(17);

    Sequence n;
    n.insert(18);

    Sequence o;
    o.insert(0, 63);
    o.insert(1, 17);
    o.insert(2, 29);
    o.insert(3, 7);

    Sequence p;

    Sequence q;

        //subsequence tests
        assert(subsequence(g, h) == 5); //subsequence present
        assert(subsequence(g, g) == 0);     //aliasing test
        assert(subsequence(g, i) == -1);    //subsequence doesn't exist consecutively
        assert(subsequence(g, j) == 7); //subsequence exists at end
        assert(subsequence(g, k) == -1);    //k doesn't exist within g (part of k does at end)
        assert(subsequence(g, f) == -1);    //empty seq2
        assert(subsequence(g, l) == 3);   //only earliest pos is returned
        assert(subsequence(f, l) == -1);    //seq1 is empty

    //interleave tests
    interleave(f, m, l);
    assert(l.size() == 0); //empty seq1 and seq2
    interleave(n, n, l);
    assert(l.size() == 2 && l.remove(18) == 2);     //aliasing for seq1 and seq2
    interleave(n, k, n);
    assert(n.find(18) == 0 && n.find(32) == 1 && n.find(2) == 2 && n.size() == 3);  //aliasing for seq1 and result AND seq2>seq1
    n.erase(2);
    n.erase(1);
    interleave(k, n, n); //aliasing for seq2 and result AND seq1>seq2
    assert(n.find(32) == 0 && n.find(18) == 1 && n.find(2) == 2 && n.size() == 3);
    interleave(i, h, m);    //seq1 and seq2 same size
    ItemType y;
    ItemType z;
    assert(m.find(17) == 0 && m.find(63) == 1 && m.get(2, x) && x==63 && m.get(3, y) && y==17 && m.find(29) == 4 && m.get(5, z) && z==29 && m.size() == 6);
    interleave(o, k, p); //seq1>seq2
    assert(p.find(63) == 0 && p.find(32) == 1 && p.find(17) == 2 && p.find(2) == 3 && p.find(29) == 4 && p.find(7) == 5 && p.size() == 6);
    interleave(k, o, p); //seq2>seq1
    assert(p.find(32) == 0 && p.find(63) == 1 && p.find(2) == 2 && p.find(17) == 3 && p.find(29) == 4 && p.find(7) == 5 && p.size() == 6);
    interleave(q, o, p); //seq1 empty
    assert(p.find(63) == 0 && p.find(17) == 1 && p.find(29) == 2 && p.find(7) == 3 && p.size() == 4);
    interleave(o, q, p); //seq2 empty
    assert(p.find(63) == 0 && p.find(17) == 1 && p.find(29) == 2 && p.find(7) == 3 && p.size() == 4);
    interleave(o, q, q); //seq2 empty AND aliasing for seq2+result
    assert(q.find(63) == 0 && q.find(17) == 1 && q.find(29) == 2 && q.find(7) == 3 && q.size() == 4);
    interleave(q, q, q); //aliasing for all 3
    ItemType w;
    assert(q.find(63) == 0 && q.get(1, x) && x==63 && q.find(17) == 2 && q.get(3, y) && y==17 && q.find(29) == 4 && q.get(5, z) && z==29 && q.find(7) == 6 && q.get(7, w) && w==7 && q.size() == 8);

    cout << "Passed all tests" << endl;
}
