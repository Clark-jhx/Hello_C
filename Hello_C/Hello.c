
#define _CRT_SECURE_NO_WARNINGS // �궨��

/*ͷ�ļ�����ֻ�к��������� �� �����ʱ����ҵ�������ʵ��*/
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/* C������������ �� ֻ�к���������ǿ�Ƶ� �� �����ķ���ֵ������Ҳ������void �� �����Ĳ���
   Ҳ�����Ƕ�� ��
*/

/*
int main() {

	printf("Hello World");
	MessageBox(NULL, "dd", "dd", NULL);
	getchar();

	return 0;
}*/

/*C ���ԵĻ����������� , ���ռλ��

	int - %d 
	short - %d 
	long - %ld 
	float - %f 
	double - %lf 
	char - %c
	�ַ��� - %s
	�˽��� - %o
	ʮ������ - %x

*/

/*
void main() {
	
	int i = 90;
	printf("int ��ռ�ֽڣ�%d\n", sizeof(int));
	printf(" i ��ֵ��%d\n", i);
	
	short sh = 32;
	printf("short ��ռ�ֽ�����%d\n", sizeof(short));
	printf("sh ��ֵ��%d\n", sh);

	long l = 12312;
	printf("long ��ռ�ֽ�����%d\n", sizeof(long));
	printf("l ��ֵ��%ld\n", l);

	float f = 12.3;
	printf("float ��ռ�ֽ�����%d\n", sizeof(float));
	printf("f ��ֵ��%f\n", f);

	double d = 234.345;
	printf("double ��ռ�ֽ�����%d\n", sizeof(double));
	printf("d ��ֵ��%lf\n", d);

	char c = 'c';
	printf("char ��ռ�ֽ�����%d\n", sizeof(char));
	printf("c ��ֵ��%c\n", c);

	// ����ַ���
	printf("����ַ�����%s\n", "����������ַ���");

	// ����˽���
	printf("����˽��ƣ�%#o\n", 023);

	// ���ʮ������
	printf("���ʮ�����ƣ�%#x\n", 0x23443);

	system("pause");

}*/

/*
void main() {

	int i;
	printf("������һ������"); 
	// �ӿ���̨���� �� ʹ��&ȡ��ַ�� �� �����������ֵ
	scanf("%d", &i);
	
	printf("��������ǣ�%d\n", i);

	system("pause");

}*/

/* ��Ҫ�޸Ĵ��������ֵ �� ����Ҫʹ��ָ��ͨ�������ĵ�ַ �� ���޸ı�����ֵ
void changeNum(int* i) {
	 printf("������i�ĵ�ַ��%#x\n", i);
	*i = 300;
} */

/*û��ʹ��ָ��ĺ���
void changeNum(int i) {

	printf("������i�ĵ�ַ��%#d\n", i);
	i = 300;
}*/


// ָ��洢���Ǳ������ڴ��ַ , ֻ�ܴ洢�ڴ��ַ �� ֱ�Ӹ�ֵ����ֵҲ��ת�����ڴ��ַ
// �ڴ��ַ��ϵͳ�����ݷ���ı��
/*
void main() {

	int i = 100;

	int *p = &i;

	//printf("i �ĵ�ַ��%#x\n", &i);
	//printf("i �ĵ�ַ��%#x\n", p);
	//printf("i ��ֵ: %d\n", *p);
	printf("���뺯���� i �ĵ�ַ��%#x\n",&i);
	// ������i���뵽������ , ���Ա���ȥ����ַ
	changeNum(&i);

	printf("�޸ĺ��ֵ��%d\n", i);

	system("pause");

}*/


/*�����ע��*/
/*
void main() {

	int time = 500;
	printf("time �ڴ��ַ��%#x\n", &time);

	while (time > 0) {
		time--;
		printf("��Ϸ������...%d\n", time);
		// ˯һ����
		Sleep(1000);
	}

	system("pause");

}*/

/*ָ������*/
/*
void main() {
	// ָ��ΪʲôҪ������ ��
	// ��ַ�ǿ�ʼ��ȡ��λ�� �� �����Ƕ�ȡ�ĳ���
	// �˴��д����� �� int and float ����4�ֽ��� �� ȴ����ȡ������

	int i = 100;
	int* p = &i;

	float j = 98.4;

	p = &j;

	printf("i �ĵ�ַ��%#x\n", p);
	printf("int size : %d\n", sizeof(int));
	printf("float size:%d\n", sizeof(float));
	printf("p ��ȡ��ֵ��%f\n", *p);

	getchar();
}
*/
/*
void main() {
	int i = 10;
	// pָ������洢����i���ڴ��ַ
	int* p = &i;
	// p1ָ������洢����p���ڴ��ַ
	int** p1 = &p;

	int *p2 = 100;

	printf("ָ����Ϊ��ͨ������%d\n", p2);

	printf("i �ĵ�ַ��%#x\n", &i);

	printf("p ��ַ��%#x\n", &p);

	printf("ͨ��p1ȡ��p�ĵ�ַ��%#x\n", p1);
	printf("ͨ��p1ȡ��i�ĵ�ַ��%#x\n", *p1);
	printf("ͨ��p1ȡ��i��ֵ��%d\n", **p1);

	// ͨ��p1�޸�i��ֵ
	**p1 = 100;

	printf("ͨ��p1�޸Ĺ���i��ֵ��%d\n", i);

	getchar();
}
*/

/*ָ������*/
/*
void main() {
	
	int arr[] = { 89,20,13,45,68 };

	// �����ַ �� Ĭ�����׸�Ԫ�ص��ڴ��ַ
	printf("�������arr��ַ��%#x\n", &arr);
	printf("����Ҳ���Ի�ȡ������ĵ�ַ��%#x\n", arr);
	printf("��һ��Ԫ�صĵ�ַ: %#x\n", &arr[0]);

	//int* p = &arr;
	float *p = &arr;

	printf("ָ������洢��ֵ��%#x -- ȡֵ:%d\n", p,*p);

	int i = 0;
	for (; i < 5; i++)
	{
		printf("����Ԫ�أ�%d == ����Ԫ�ص�ַ��%#x\n", arr[i],&arr[i]);
	}

	printf("\n");

	
	int j = 0; 
	for (; j < 5; j++)
	{
		printf("����Ԫ�ص�ֵ �� %d == ָ��洢�ĵ�ַ��%#x\n", *p,p);
		p++;
	}
	
	int k = 0;
	for (; p < arr + 5; p++) {
		
		*p = k;
		k++;

		printf("*p value : %d\n", *p);
	}

	printf("\n");

	int j = 0;
	for (; j < 5; j++)
	{
		printf("����Ԫ�أ�%d\n", arr[j]);
	}

	getchar();
}
*/