


//排序结构体
#include<stdio.h>
struct Student
{
	char name[20];
	int age;
	double score;
};

// 按照姓名排序
int cmp_name(const void* e1, const void* e2) {
	return strcmp(((struct Student*)e1)->name, ((struct Student*)e2)->name);
}


int main()
{
	struct Student arr[] = { {"zhang",17,80.6},{"wang",20,85.2},{"li",19,92.0} };
	int sz = sizeof (arr) / sizeof (arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_name);

    int i=0;
    for(i=0;i<sz;i++) {
        printf("%s,__%d,__%f\n",arr[i].name,arr[i].age,arr[i].score);
    }
	return 0;
}



