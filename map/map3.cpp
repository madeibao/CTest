

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int main(int argc, char **argv) {

	map<int, int> map2;

	map2.insert({1,1});
	map2.insert({2,12});
	map2.insert({3,14});


    map<int, int>::iterator it;
    for(it = map2.begin();it != map2.end();it++) {
    	cout << it->first << " " << it->second << endl;
    }

    cout<<"----------------------------------------------------------------"<<endl;


    for(auto i:map2) {
    	cout << i.first << " " << i.second << endl;
    }
	return 0;
}
