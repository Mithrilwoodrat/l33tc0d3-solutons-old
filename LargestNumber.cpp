#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

bool num_cmp (int a, int b)
{
    string str_a = to_string(a), str_b = to_string(b);
    return str_a + str_b > str_b + str_a;
}
    

int main()
{
    vector<int> num = {99998,99997,99996};
    stringstream s;
    sort(num.begin(),num.end(),num_cmp);
    for (const auto & p : num)
    {
        cout << p << endl;
        s << p;
    }
    
    if ((num[0] == num[num.size()-1]) && num[0] == 0)
        cout << '0' << endl;
    else
        cout << s.str() << endl;
    return 0;
}
