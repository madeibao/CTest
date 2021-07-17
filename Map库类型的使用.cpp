#include <stdio.h>
#include <string.h>
#include <string>
#include <utility>
using namespace std;

int main(){
   pair<int, string> p1(0, "Hello");
   printf("%d, %s\n", p1.first, p1.second.c_str());
   pair<int, string> p2 = make_pair(1, "World");
   printf("%d, %s\n", p2.first, p2.second.c_str());
   return 0;
}
