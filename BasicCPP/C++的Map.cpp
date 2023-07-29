



#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> mymap = {
        {"beta", 0}, {"gamma", 0},{"alpha", 0}, {"aaa",1}};

    mymap.at("alpha") = 10;
    mymap.at("beta") = 20;
    mymap.at("gamma") = 30;

    for (auto& x : mymap) {
        std::cout << x.first << ": " << x.second << '\n';
    }

    return 0;
}
/*
alpha: 10
beta: 20
gamma: 30
*/

// Map是有序的，会自动的排序