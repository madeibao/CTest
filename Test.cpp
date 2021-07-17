#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getNum(vector<multimap<int, int, greater<int>>>&score) {
	unorder_set<int> numPeople;

	for(multimap<int, int, greater<int>>&e:score) {

		auto ite = e.begin();
		auto preScore = 0;
		do {
			numPeople.insert(ite->second);
			preScore = ite->first;
			ite++;
		}while(ite != e.end&&ite->first!=preScore);
	}
	
	return numPeople.size();
}
int main(int argc, char* argv[]) {
	int n=0;
	int m=0;

	cin>>n>>m;

	vector<multimap<int, int, greater<int>>> scoreArr(m,multimap<int,int,greater<int>>());
	int score = 0;
	int time = n*m;
	for(int i=0,j=0;i<time;i++) {
		cin>>score;
		if(i!=0&&i%m==0){
			j++;
		}
		scoreArr.at(i%m).insert(pair<int,int>(score, j));
	}

	cout<<getNum(scoreArr)<<endl;
	system("pause");
	return 0;
}


/**

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {

	int n,m;
	int arr[50][50],arr2[50][50];

	scanf("%d%d",&n,&m);

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			scanf("%d",&arr[i][j]);
			arr2[i][j] = arr[i][j];
		}
	}

	int flag[50] = {0};
	int sum = 0;

	for(int j=0;j<m;j++) {
		for(int i =0;i<n-1;i++) {
			if(arr2[i][j]>arr2[i+1][j]) {
				int temp = arr2[i][j];
				arr2[i][j] = arr2[i+1][j];
				arr2[i+1][j] = temp;
			}
		}

		int tmp = arr2[n-1][j];
		for(int  k =0;k<n;k++) {
			if(arr[k][j]==tmp&&flag[k]==0) {
				flag[k] = 1;

			}
		}
	}



	for(int i=0;i<n;i++) {

		if(flag[i]==1) {

			sum += flag[i];
		}
	}

	cout<<sum<<endl;
	return 0;

}












*/