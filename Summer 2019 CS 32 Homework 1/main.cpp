//
//  main.cpp
//  CS 32 Summer 2019 HW1
//
//  Created by Jason Guerrero on 7/6/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList list1;
    
    list1.insertToFront("4");
    list1.insertToFront("3");
    list1.insertToFront("2");
    list1.insertToFront("1");
    
    LinkedList linky;
    linky.insertToFront("8");
    linky.insertToFront("7");
    linky.insertToFront("6");
    linky.insertToFront("5");
    list1.printList();
    
    LinkedList list2(list1);
    
    list2.printList();
    
    LinkedList list3;
    LinkedList list4;
    

    
    LinkedList list5;
    list5.insertToFront("4");
    list5.insertToFront("3");
    list5.insertToFront("2");
    list5.insertToFront("1");
    
    LinkedList list6;
    list6.insertToFront("7");
    list6.insertToFront("6");
    list6.insertToFront("5");
    
    list5 = list6;
    list5.printList();
    cout << list5.size() << endl;
    cout << list1.size() << endl;
    cout << list6.size() << endl;
    
    linky.swap(list1);
    linky.printList();
    
    LinkedList Stark;
    Stark.insertToFront("Ned");
    Stark.insertToFront("Catelyn");
    
    LinkedList Snow;
    Snow.insertToFront("Ramsay");
    Snow.insertToFront("Jon");
    Snow.swap(Stark);
    Snow.printList();
    Stark.printList();
    Stark.reverseList();
    Stark.printList();
    list2.reverseList();
    list2.printList();
    list2.printReverse();
    
    LinkedList linky1;
    linky1.insertToFront("4");
    linky1.insertToFront("3");
    linky1.insertToFront("2");
    linky1.insertToFront("1");
    
    LinkedList linky2;
    linky2.insertToFront("7");
    linky2.insertToFront("6");
    linky2.insertToFront("5");
    
    LinkedList linky3;
    linky3.insertToFront("8");
    
    linky1.append(linky2);
    linky1.printList();
    linky1.append(linky3);
    linky1.printList();
    linky1.printReverse();
    cout << endl;
    
    LinkedList ls;
    ls.insertToFront("Steve");
    ls.insertToFront("Judy");
    ls.insertToFront("Laura");
    ls.insertToFront("Eddie");
    ls.insertToFront("Hariette");
    ls.insertToFront("Carl");
    for (int k = 0; k < ls.size(); k++)
    {
        string x;
        ls.get(k, x);
        cout << x << endl;
    }
    cout << endl;
    LinkedList ls1;
    ls1.insertToFront("Eric");
    ls1.insertToFront("Shawn");
    ls1.insertToFront("Topanga");
    ls1.insertToFront("Cory");
    ls1.printList();
    ls1.printReverse();

    LinkedList x;
    x.insertToFront("bell");
    x.insertToFront("biv");
    x.insertToFront("devoe");
    LinkedList y;
    y.insertToFront("Andre");
    y.insertToFront("Big Boi");
    x.append(y);  // adds contents of y to the end of x
    string t;
    assert(x.size() == 5  &&  x.get(3, t)  &&  t == "Big Boi");
    assert(y.size() == 2  &&  y.get(1, t)  &&  t == "Andre");
    
    LinkedList e1;
    e1.insertToFront("Sam");
    e1.insertToFront("Carla");
    e1.insertToFront("Cliff");
    e1.insertToFront("Norm");
    e1.reverseList();  // reverses the contents of e1
    string s;
    assert(e1.size() == 4  &&  e1.get(0, s)  &&  s == "Sam");

    
    
    LinkedList u;
    u.insertToFront("A");
    u.insertToFront("B");
    u.insertToFront("C");
    u.insertToFront("D");
    LinkedList v;
    v.insertToFront("X");
    v.insertToFront("Y");
    v.insertToFront("Z");
    u.swap(v);  // exchange contents of u and v
    string q;
    assert(u.size() == 3  &&  u.get(0, q)  &&  q == "Z");
    assert(v.size() == 4  &&  v.get(2, q)  &&  q == "B");

    LinkedList a;
    a.printList();
    a.printReverse();
    
    LinkedList b;
    LinkedList c(b);
    c.printList();
    
    ItemType i;
    LinkedList d;
    d.insertToFront("c");
    d.insertToFront("b");
    d.insertToFront("a");
    assert(d.get(3, i) == false);
    assert(d.get(2, i) == true && i == "c");
    assert(d.get(1, i) == true && i == "b");
    assert(d.get(0,i) == true && i == "a");
    assert(d.get(-1,i) == false);
    assert(a.get(0,i) == false);
    assert(a.size() == 0);
    assert(d.size() == 3);
    a.reverseList();
    a.printList();
    
    LinkedList e;
    e.printReverse();
    e.insertToFront("Jason");
    e.reverseList();
    e.printList();
    e.printReverse();
    e.append(ls1);
    e.printList();
    e.printReverse();
    e.append(a);
    e.printList();
    e.printReverse();
    
    LinkedList ecc;
    ecc.insertToFront("Solomon");
    LinkedList smc;
    smc.insertToFront("Edwin");
    ecc.append(smc);
    ecc.printList();
    ecc.printReverse();
    smc.insertToFront("Howard");
    smc.printList();
    smc.swap(ecc);
    smc.printList();
    ecc.printList();
    return 0;
}
