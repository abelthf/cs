#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(int i)
{
   cout << " " << i;
}

int main()
{
   int sum = 0;
   auto f = [](int& x) -> int{
     x = x*x;
     return 2*x;
   };
   vector<int> myVector, B;
   myVector.push_back(10);
   myVector.push_back(20);
   B = myVector;
   transform(myVector.begin(), myVector.end(), B.begin(), f);
   for_each(myVector.begin(), myVector.end(), print);
    return 0;
}

