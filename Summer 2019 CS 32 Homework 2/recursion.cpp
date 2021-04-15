//
//  recursion.cpp
//  Summer 2019 CS 32 HW2
//
//  Created by Jason Guerrero on 7/22/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <string>
using namespace std;


// Returns the product of two non-negative integers, m and n,
// using only repeated addition.
int prod(unsigned int m, unsigned int n)
{
    if (m == 0 || n == 0)
        return 0;
    
    return (m + prod(m, n - 1));
}

// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
//
// Pseudocode Example:
//    numberOfDigits(18838, 8) => 3
//    numberOfDigits(55555, 3) => 0
//    numberOfDigits(0, 0)     => 0 or 1 (either if fine)
//
int numberOfDigits(int num, int digit)
{
    int count = 0;
    
    if (num == 0)
        return 0;
    
    if (num % 10 == digit)
        count++;
    
    return (count + numberOfDigits(num / 10, digit));
}

// Returns a string where the same characters next each other in
// string n are separated by "22"
//
// Pseudocode Example:
//    doubleDouble("goodbye") => "go22odbye"
//    doubleDouble("yyuu")    => "y22yu22u"
//    doubleDouble("aaaa")    => "a22a22a22a"
//
string doubleDouble(string n)
{
    if (n.size() < 2)
        return n;
    
    if (n.at(0) == n.at(1))
        return ( n.at(0) + ( "22" + doubleDouble(n.substr(1,n.size() - 1)) ) );
    
    else
        return ( n.at(0) + doubleDouble(n.substr(1, n.size() - 1)) );
}




// str contains a single pair of curly brackets, return a new
// string made of only the curly brackets and whatever those
// curly brackets contain
//
//  Pseudocode Example:
//     curlyFries("abc{ghj}789") => "{ghj}"
//     curlyFries("{x}7")  => {x}
//     curlyFries("4agh{y}") => {y}
//     curlyFries("4agh{}") => {}
//
string curlyFries(string str)
{
    
    if (str.at(0) == '{' && str.at(str.size() - 1) == '}')
        return str;

    if (str.at(0) != '{')
        return curlyFries(str.substr(1, str.size() - 1));
   else
   {
       return curlyFries(str.substr(0, str.size() - 1));
   }
}

// Return true if the total of any combination of elements in
// the array a equals the value of the target.
//
//  Pseudocode Example:
//     addEmUp([2, 4, 8], 3, 10) => true
//     addEmUp([2, 4, 8], 3, 6) => true
//     addEmUp([2, 4, 8], 3, 11) => false
//     addEmUp([2, 4, 8], 3, 0)  => true
//     addEmUp([], 0, 0)         => true
//
bool addEmUp(const int a[], int size, int target)
{
    if (target == 0)
        return true;
    
    if (size == 0)
        return false;

    return (addEmUp(a + 1, size - 1, target - a[0]) || addEmUp(a + 1, size - 1, target));
}


// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
bool canWeFinish(string maze[], int nRows, int nCols,
                 int sr, int sc, int er, int ec)
{
    
    if (sr == er && sc == ec)
        return true;
    
    maze[sr][sc] = '#';
    
    if (maze[sr-1][sc] == '.')
    {
        if (canWeFinish(maze, nRows, nCols, sr - 1, sc, er, ec))
            return true;
    }

    if (maze[sr+1][sc] == '.')
    {
        if (canWeFinish(maze, nRows, nCols, sr + 1, sc, er, ec))
            return true;
    }
    
    if (maze[sr][sc-1] == '.')
    {
        if (canWeFinish(maze, nRows, nCols, sr, sc - 1, er, ec))
            return true;
    }
    
    if (maze[sr][sc+1] == '.')
    {
        if (canWeFinish(maze, nRows, nCols, sr, sc + 1, er, ec))
            return true;
    }
    
    return false;
}

//int main()
//{
//    assert(prod(1, 1) == 1);
//    assert(prod(1, 0) == 0);
//    assert(prod(0, 1) == 0);
//    assert(prod(1, 2) == 2);
//    assert(prod(2, 1) == 2);
//    assert(prod(2, 2) == 4);
//    assert(prod(2, 3) == 6);
//    assert(prod(3, 2) == 6);
//    assert(prod(3, 3) == 9);
//    assert(prod(7, 8) == 56);
//    assert(prod(9, 9) == 81);
//    assert(prod(12, 12) == 144);
//    assert(prod(1000, 123) == 123000);
//    assert(numberOfDigits(18838, 8) == 3);
//    assert(numberOfDigits(55555, 3) == 0);
//    assert(numberOfDigits(0, 0) == 0);
//    assert(numberOfDigits(1212211, 2) == 3);
//    assert(numberOfDigits(1212211, 1) == 4);
//    assert(numberOfDigits(1234123, 2) == 2);
//    assert(numberOfDigits(1212, 2) == 2);
//    assert(doubleDouble("goodbye") == "go22odbye");
//    assert(doubleDouble("yyuu") == "y22yu22u");
//    assert(doubleDouble("aaaa") == "a22a22a22a");
//    assert(doubleDouble("ababbaaba") == "abab22ba22aba");
//    assert(doubleDouble("aaaaaaaaaaaaaa") == "a22a22a22a22a22a22a22a22a22a22a22a22a22a");
//    assert(doubleDouble("") == "");
//    assert(doubleDouble("   ") == " 22 22 ");
//    assert(doubleDouble("Jason") == "Jason");
//    assert(curlyFries("abc{ghj}789") == "{ghj}");
//    assert(curlyFries("{x}y") == "{x}");
//    assert(curlyFries("4agh{}") == "{}");
//    assert(curlyFries("{Jason}") == "{Jason}");
//
//
//
//    int a[3] = { 2, 4, 8 };
//    int e[0] = {};
//    assert(addEmUp(a, 3, 10) == true);
//    assert(addEmUp(a, 3, 6) == true);
//    assert(addEmUp(a, 3, 11) == false);
//    assert(addEmUp(a, 4, 8) == true);
//    assert(addEmUp(e, 0, 0) == true);
//    cout << "Passed!" << endl;
//
//
//    string maze[10] = {
//        "XXXXXXXXXX",
//        "X.......@X",
//        "XX@X@@.XXX",
//        "X..X.X...X",
//        "X..X...@.X",
//        "X....XXX.X",
//        "X@X....XXX",
//        "X..XX.XX.X",
//        "X...X....X",
//        "XXXXXXXXXX"
//    };
//
//    string maze1[5] = {
//        "XXXXXXX",
//        "X...X@X",
//        "XXX.X.X",
//        "X@....X",
//        "XXXXXXX"
//    };
//
//    string maze2[10] = {
//        "XXXXXXXXXX",
//        "X.......@X",
//        "XX@X@@XXXX",
//        "X..X.X...X",
//        "X..X...@.X",
//        "X....XXX.X",
//        "X@X....XXX",
//        "X..XX.XX.X",
//        "X...X....X",
//        "XXXXXXXXXX"
//    };
//
//    string maze3[10] = {
//        "XXXXXXXXXX",
//        "X.......@X",
//        "XX@X@.XXXX",
//        "X..X.X...X",
//        "X..X...@.X",
//        "X....XXX.X",
//        "X@X....XXX",
//        "X..XX.XX.X",
//        "X...X....X",
//        "XXXXXXXXXX"
//    };
//
//    string maze4[10] = {
//        "XXXXXXXXXX",
//        "X.......@X",
//        "XX@X@..XXX",
//        "X..X.X...X",
//        "X..XX.X@.X",
//        "X....XXX.X",
//        "X@X....XXX",
//        "X..XX.XX.X",
//        "X...X....X",
//        "XXXXXXXXXX"
//    };
//
//    string maze5[10] = {
//        "XXXXXXXXXX",
//        "X.......@X",
//        "XX@X@..XXX",
//        "X..X.X...X",
//        "X..XX.X..X",
//        "X....XX..X",
//        "X@X.....XX",
//        "X..XX.X..X",
//        "X...X....X",
//        "XXXXXXXXXX"
//    };
//
//    assert(canWeFinish(maze1, 5, 7, 1, 1, 3, 5));
//    assert(!canWeFinish(maze2, 10, 10, 6, 4, 1, 1));
//    assert(!canWeFinish(maze3, 10, 10, 6, 4, 1, 1));
//    assert(!canWeFinish(maze4, 10, 10, 6, 4, 1, 1));
//    assert(canWeFinish(maze5, 10, 10, 6, 4, 1, 1));
//    assert(!canWeFinish(maze5, 10, 10, 1, 1, 8, 1));
//    assert(!canWeFinish(maze5, 10, 10, 1, 1, 8, 1));
//    // assert(canWeFinish(maze5, 10, 10, 1, 1, 3, 1));
//
//    if (canWeFinish(maze, 10, 10, 6, 4, 1, 1))
//        cout << "Solvable!" << endl;
//    else
//        cout << "Out of luck!" << endl;
//
//    cout << "Yay!" << endl;
//    return 0;
//}
