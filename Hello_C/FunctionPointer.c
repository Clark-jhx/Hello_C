
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include <time.h>


/*����*/
void message() {
	MessageBox(NULL, "���ǵ�����", "��Ϣ", NULL);
}

int add(int num1, int num2) {
	
	return num1 + num2;
}

int minus(int num1, int num2) {
	
	return num1 - num2;
}

/*������Сֵ*/
int * sreachLeast(int arr[] , int len) {

	int *p = &arr[0];
	int i = 0;
	for (; i < len ; i++)
	{
		if (arr[i] < *p)
		{
			*p = arr[i];
		}
	}

	return p;
}

/*ģ����������ص�*/
void requestNet(char* url , void(*callBack)(char *)) {
	printf("�����ַ��%s , ������������....\n",url);
	// ģ�����������ʱ
	Sleep(2000);
	char* str = "����������������� �� �仨��������ˮ �� ��ˮ�������仨\n";
	callBack(str);
}

/*�ص�����*/
void netCallBack(char *str) {
	printf("��������ص�\n");
	printf("���󵽵����ݣ�%s" ,str);
}

// ������ָ���ֽڶ��嵽������������� �� ����java�еĶ�̬
void showMsg(int(*c)(int num1, int num2), int a, int b) {
		int r = c(a, b);
		printf("�������=%d\n", r);
}

/*
void main() {

	// ����ָ�붨�� , void ����ֵ(����ָ������)(��������) = ��������
	//void(*func_p)() = message;
	//// ���ú���ָ��
	//func_p();
	//// ����ָ��ͨ������ָ��ʵ�е���
	//printf("����ָ���ַ��%#x\n", message);
	//printf("����ָ���ַ��%#x\n", &func_p);

	showMsg(add, 10, 10);

	showMsg(minus, 30, 2);

	char* url = "www.zhuyongit.com";
	requestNet(url, netCallBack);

	//�����������
	//int arr[10];
	//int i = 0;
	//int len = sizeof(arr) / sizeof(int);

	//printf("���������С��%d\n", len);
	//srand(unsigned(time(NULL)));
	//for (; i < len ; i++)
	//{
	//	arr[i] = rand() % 100;

	//	printf("arr[%d] = %d\n", i,arr[i]);
	//}

	//int* p = sreachLeast(arr, len);

	//printf("��Сֵ��%d\n", *p);
	//printf("��Сֵ��ַ��%#x\n", p);

	getchar();
}*/