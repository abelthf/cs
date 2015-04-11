#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef int (*F)(int &x);
int modify(int& x){
    return 3*x;
}
void print(int x){cout<<x<<endl;}
int main(){
   //auto g = modify;
   int sum = 0;
   F g = [](int& x) -> int{
     x = x*x;
     return 2*x;
   };

   g = modify;

   vector<int> myVector, B;
   myVector.push_back(10);
   myVector.push_back(20);
   B = myVector;
   transform(myVector.begin(), myVector.end(), B.begin(), g);
   for_each(B.begin(), B.end(), print);
    return 0;
}

