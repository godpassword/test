#include<iostream>
using namespace std;

struct Teacher
{
	char name[64];
	int age;
};


//������������ָ������������ڱ����ú��������ڴ�
int getTeacher1(Teacher **p)
{
	Teacher* tmp = NULL;

	tmp = (Teacher*)malloc(sizeof(Teacher));
	if (tmp == NULL) return -2;
	tmp->age = 45;
	//p��ʵ�εĵ�ַ��*ʵ�ε�ַ��ȥ����޸�ʵ�ε�ֵ��
	*p = tmp;

	return 0;
}


//c++�е����ã�ָ������ã�
int getTeacher2(Teacher * & myp)
{
	myp = (Teacher*)malloc(sizeof(Teacher));
	if (myp == NULL) return -1;
	myp->age = 545;
	return 0;
}



//�ڱ����ú��� ��ȡ��Դ
int main()
{
	Teacher* t1 = NULL;
	Teacher* t2 = NULL;

	//c�����еĶ���ָ��
	getTeacher1(&t1);
	cout << "age:" <<t1->age<< endl;

	//c++�е����ã�ָ������ã�
	getTeacher2(t2);//
	cout << "age:" << t2->age << endl;

	free(t1);
	free(t2);
	system("pause");
	return 0;
}