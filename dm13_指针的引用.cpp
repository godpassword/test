#include<iostream>
using namespace std;

struct Teacher
{
	char name[64];
	int age;
};


//函数参数二级指针做输出，就在被调用函数分配内存
int getTeacher1(Teacher **p)
{
	Teacher* tmp = NULL;

	tmp = (Teacher*)malloc(sizeof(Teacher));
	if (tmp == NULL) return -2;
	tmp->age = 45;
	//p是实参的地址，*实参地址，去间接修改实参的值。
	*p = tmp;

	return 0;
}


//c++中的引用（指针的引用）
int getTeacher2(Teacher * & myp)
{
	myp = (Teacher*)malloc(sizeof(Teacher));
	if (myp == NULL) return -1;
	myp->age = 545;
	return 0;
}



//在被调用函数 获取资源
int main()
{
	Teacher* t1 = NULL;
	Teacher* t2 = NULL;

	//c语言中的二级指针
	getTeacher1(&t1);
	cout << "age:" <<t1->age<< endl;

	//c++中的引用（指针的引用）
	getTeacher2(t2);//
	cout << "age:" << t2->age << endl;

	free(t1);
	free(t2);
	system("pause");
	return 0;
}