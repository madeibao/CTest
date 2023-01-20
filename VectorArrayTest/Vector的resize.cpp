

// resize()后，vector中的原有数据会继续保持，见下例


#include <iostream>
#include<vector>
using namespace std;
void print_vector(vector<vector<int> > v){ //逐行输出vector各元素
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	} 
}

int main(){
	vector<vector<int> > v(2, vector<int> (4,1));//2*4,初始化为1 
	
	cout<<"v.size()="<<v.size()<<endl;
	print_vector(v);
	cout<<"---------------"<<endl;
 
	v.resize(3);
	print_vector(v);
	cout<<"---------------"<<endl;
	
	for(int i = 0; i < v.size(); ++i) {
		v[i].push_back(1);
		v[i].push_back(2);
		v[i].push_back(3);
	}
	print_vector(v);
	cout<<"---------------"<<endl;
	
	v.resize(4); 
	print_vector(v);
	cout<<"---------------"<<endl;
	
	v.resize(2); 
	print_vector(v);
	cout<<"---------------"<<endl;
} 




