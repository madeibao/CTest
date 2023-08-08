

#include <iostream>
#include <string>
using namespace std;


bool helper(const string str, char ch) {
    if(str.find(ch)!=string::npos) {
        return true;
    }
    return false;
}

int main() {
    std::string str = "Hello, world!";
    char ch = 'o';

    cout<<helper(str,ch)<<endl;
    return 0;
}
