#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef map<string, int> StrCounter;
typedef pair<string, int> StrIntPiar;

int main()
{
    StrCounter counter;
    StrCounter::iterator map_it;
    vector<string> ans;
    vector<string>::iterator vec_it;
    stringstream buf;
    string s,key;
    int i,j;
    cin >> s;
    for (i=0;i<s.length()-10;i++)
    {
        buf.str(string()); // clearing buf
        for(j=0;j<10;j++)
        {
            buf << s[j+i];
        }
        key = buf.str();
        if (counter.count(key))//if key exists
        {
            counter[key]++;
        }
        else
        {
            counter.insert(StrIntPiar(key,1));
        }
    }
     
    for (map_it=counter.begin();map_it!=counter.end();map_it++)
    {
        if (map_it->second >= 2)
        {
            ans.push_back(map_it->first);
        }
    }
    for (vec_it=ans.begin();vec_it!=ans.end();vec_it++)
        cout << *vec_it << '\t';
    
    return 0;
}

    
// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

// For example,

// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

// Return:
// ["AAAAACCCCC", "CCCCCAAAAA"].
