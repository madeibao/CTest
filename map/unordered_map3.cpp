


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {

	unordered_map<string, int> map2, mypantry;

	string key = "hello";
	int value = 2;
	mypantry = {{"milk",2},{"flour",5}};

	map2.insert({key, value});

	map2.insert({"bread",2});
 	map2.insert (mypantry.begin(), mypantry.end());
 	map2.insert (make_pair<string,int>("eggs",6));

 	cout<<"Number 1 ---------------------------------------------"<<endl;

 	for(auto i: map2) {
 		cout<<i.first<<" "<<i.second<<endl;
 	}

 	cout<<"Number 2----------------------------------------------"<<endl;

	for ( auto it = map2.begin(); it != map2.end(); ++it ) {
		cout << " " << it->first << ":" << it->second<<endl;
	}

 	cout<<"----------------------------------------------"<<endl;


 	 for(unordered_map<string,int>::iterator iter=map2.begin();iter!=map2.end();iter++)
          cout<<"key value is "<<iter->first<<"  the mapped value is "<< iter->second<<endl;
    cout<<endl;
	return 0;
}
