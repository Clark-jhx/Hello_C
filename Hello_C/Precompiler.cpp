
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*Ԥ����*/

/*
	C����ִ������
	1.���� - ����Ŀ�����(.obj)
	2.���� - ��Ŀ�������C���������Ӻϲ� �� �������տ�ִ���ļ�
	3.ִ��

	Ԥ���루Ԥ������Ϊ������׼�� �� ��ɴ����ı��滻������
*/

//#define Ԥ����ָ�� �� �궨�� �� ���滻
// ���ľ����滻
// ����һ������
#define MAX 100 

// �꺯��
void _jni_define_func_read() {
	printf("read\n");
}

void _jni_define_func_write() {
	printf("write\n");
}

// ����꺯��
#define jni(NAME) _jni_define_func_##NAME() ;

// ģ��Android��־��� , ���ľ����滻
#define LOG(LEVE,FORMAT,...) printf(##LEVE); printf(##FORMAT,__VA_ARGS__) ;
#define LOGI(FORMAT,...) LOG("INFO:",##FORMAT,__VA_ARGS__) ;
#define LOGE(FORMAT,...) LOG("ERROR:",##FORMAT,__VA_ARGS__) ;
#define LOGW(FORMAT,...) LOG("WARN:",##FORMAT,__VA_ARGS__) ;

/**/
void main() {

	int i = 99;
	if (i < MAX) // �ڱ���ʱ�ڣ� �ὫMAX�滻��100
	{
		printf("i С�� MAX\n");
	}


	// �꺯��
	//jni(read); ���Լ򻯺�������

	LOGI("%s", "�Զ�����־��������\n");
	LOGE("%s", "���Ǵ�����־...\n");

	system("pause");
}