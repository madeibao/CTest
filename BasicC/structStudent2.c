

#include<stdio.h>
typedef struct hero{
	//英雄的名字
	char* name;
	//英雄的血量
	double Health_value;
	//攻击力
	int aggressivity;
}Hero;
int main(){
	//定义一个struct Hero的英雄变量烬
	Hero jin;
	jin.name="烬";
	jin.Health_value=470;
	jin.aggressivity=81;
	printf("烬的名字:%s\n",jin.name);
	printf("烬的生命值:%lf\n",jin.Health_value);
	printf("烬的攻击力:%d\n",jin.aggressivity);
	return 0;
}
