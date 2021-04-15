//
//  anagrams.cpp
//  Summer 2019 CS 32 Project 3
//
//  Created by Jason Guerrero on 7/26/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
#include <cassert>
using namespace std;

const int MAXRESULTS   = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

int loadWords(istream &dictfile, string dict[]);
int recBlends(string word, const string dict[], int size, string
              results[]);
void showResults(const string results[], int size);
void Loop2(int i, unsigned long max, string prefix, string rest);
bool Loop3(int i, unsigned long max, string prefix, string rest, const string dict[], int size, string results[], int  &matches);
void Loop4(int i, unsigned long max, string prefix, string rest, const string dict[], int size, string results[], int &matches);
void Loop5(int i, int max, const string results[]);
void Permute(string prefix, string rest);
void Permute(string prefix, string rest, const string dict[], int size, string results[], int& matches);
bool NotAlreadyInside(int i, int max, string results[], string prefix);



int main()
{
   Permute("", "book");
   // cout << endl;
    string dict[25143];
    ifstream dictfile;
    dictfile.open("words.txt");
    loadWords(dictfile, dict);

    string results[MAXRESULTS];
    
    string iron[24];
    ifstream testfile1;
    testfile1.open("testfile1.txt");
    loadWords(testfile1, iron);
    
    
    cout << endl;
    
    recBlends("book", iron, 24, results);

    
    showResults(results, MAXRESULTS);
    
    dictfile.close();
    testfile1.close();
    
    return 0;
}


int loadWords(istream &dictfile, string dict[])
{
    string line;
    
    if (getline(dictfile, line)) // read in each line until we are out of lines
    {
        dict[0] = line;
        return 1 + loadWords(dictfile, dict + 1);
    }
    
    return 0;
}


void showResults(const string results[], int size)
{
    Loop5(0, size, results);
}
void Loop5(int i, int max, const string results[])
{
    if (i >= max)
        return;
    
    cout << results[i] << endl; // do the work for showResults
    Loop5(i + 1, max, results);
}


void Loop2(int i, unsigned long max, string prefix, string rest)
{
    if (i >= max)
        return;
    
    Permute(prefix + rest[i], rest.substr(0,i) + rest.substr(i + 1)); // find combo
    Loop2(i + 1, max, prefix, rest); // continue
}


void Permute(string prefix, string rest)
{
    if (rest.size() == 0)
    {
        cout << prefix << endl;
    }

    else
    {
        Loop2(0, rest.size(), prefix, rest);
    }
}


bool Loop3(int i, unsigned long max, string prefix, string rest, const string dict[], int size, string results[], int & matches)
{
    if ( i >= size) // we didn't find a match
        return false;
    
    if (dict[i] == prefix) // we have found a match
        return true;
    
    return false || Loop3(i + 1, max, prefix, rest, dict, size, results, matches);
}

void Loop4(int i, unsigned long max, string prefix, string rest, const string dict[], int size, string results[], int &matches)
{
    if (i >= max)
        return;
    
    else
    {
        Permute(prefix + rest[i], rest.substr(0,i) + rest.substr(i + 1), dict, size, results, matches); // next combo
        
        Loop4(i + 1, rest.size(), prefix, rest, dict, size, results, matches); // continue
    }
}

void Permute(string prefix, string rest, const string dict[], int size, string results[], int& matches)
{
    if (rest.size() == 0)
    {
        if(Loop3(0, MAXRESULTS, prefix, rest, dict, size, results, matches)) // check to see if its in dict
        {
            if (NotAlreadyInside(0, MAXRESULTS, results, prefix)) // check to see if its not repeated
            {
                if (matches < MAXRESULTS) // check to see if results is not already full
                {
                    results[matches] = prefix;
                    matches += 1;
                }
            }
        }
    }
    else
    {
        Loop4(0, rest.size(), prefix, rest, dict, size, results, matches);
    }
}

bool NotAlreadyInside(int i, int max, string results[], string prefix) // check to see if I have repeated permutations
{                                                                      // in results[]
    if (i >= max)
        return true;

    if (results[i] == prefix)
    {
        return false;
    }

    return NotAlreadyInside(i + 1, max, results, prefix);
}


int recBlends(string word, const string dict[], int size, string
              results[])
{
    int matchesFound = 0;
    Permute("", word, dict, size, results, matchesFound);
   // cout << matchesFound << endl;
    return matchesFound;
}
