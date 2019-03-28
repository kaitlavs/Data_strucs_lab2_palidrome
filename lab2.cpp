// Kaitlyn Lavan
// 10/08/2018
// cisc2200
// checks if the input string is a palindrome
// ** fix all cases of error with stack overflow

#include <iostream>
#include <stack>

using namespace std;

string ProcessInput (string s)
{
  int len = s.length();
  string alnum_str = "";
  
  // checks if each character in a string is either alpha or num and a
  // appends the char to a new string if it is 
  for (int i=0; i < len; i++)
  {
    if(isalnum(s[i]))
    {
	if (isalpha(s[i]))
	    s[i] = tolower(s[i]);
	alnum_str = alnum_str + s[i];
    }
  }
  return alnum_str;
}

int main()
{
  //variables
  string input_str, processed_str;
  stack<char> palstack;
  int str_len;
  bool palidrome = true;

  cout << "Enter a string to check if it is palidrome!" << endl;
  getline(cin, input_str);

  // process input_string
  processed_str = ProcessInput(input_str);
  str_len = processed_str.length();

  // *** check for stack overflow
  for (int i =0; i < str_len; ++i)
  {
    palstack.push(processed_str[i]);
  }

  for (int i=0;i < (str_len/2);i++)
  {
    if (palstack.top() == processed_str[i])
    {
	if (!palstack.empty())
		palstack.pop();
    }
    else 
    {
 	palidrome = false;
        break;
    }
  }

  if (palidrome)
    cout << "Your input is a palidrome!" << endl;
  else
    cout << "Your input is not a palindrome." << endl;


return 0;
}
