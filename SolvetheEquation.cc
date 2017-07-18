#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

string solveEquation(string equation) {
  int left_v=0, right_v=0, left_x=0, right_x=0;
  int *x = &left_x, *v = &left_v;
  bool is_positive  = true;
  string number_str;
  int number;
  char c;
  for(size_t i =0;i<equation.size();){
	c = equation[i];
	if(c =='-') {
	  is_positive = false;
	  i++;
	}
	else if (c =='+') {
	  is_positive = true;
	  i++;
	}
	else if (c == 'x'){
	     *x += is_positive? 1 : -1;
	     is_positive = true;
	     i++;
	} else if (isdigit(c)) {
	     for(;;) {
		  number_str += c;
		  i+=1;
		  c = equation[i];
		  if (!isdigit(c))
		       break;
	     }
	     number = atoi(number_str.c_str());
	     if (c == 'x') {
		  *x += is_positive? number : (-number);
		  number_str = "";
		  number = 0;
		  i++;
	     } else {
		  *v += is_positive? number : (-number);
		  number_str = "";
		  number = 0;
	     }
	     is_positive = true;
	}else if (c == '='){
	  x = &right_x, v = &right_v;
	  i++;
	}
  } 

  cout << left_x << " "<< left_v << " " << right_x << " " << right_v << endl;
  int var = left_x - right_x;
  int val = right_v - left_v;
  if (var == 0) {
       if (val == 0)
	    return "Infinite solutions";
       return "No solution";
  }
  return "x="+to_string(val / var);
}

int main(int argc, char ** argv)
{
  cout << solveEquation(argv[1]) << endl;
}
