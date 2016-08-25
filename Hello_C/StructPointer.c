
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*�ṹ��*/

/*
	�ṹ����һ�ֹ�����������
	�Ѳ�ͬ��������������������Ϊһ���Զ������������
*/

// ����һ���ṹ��
// һ���ṹ���൱��һ��java�е��� �� �ṹ����ֻ������ �� ����û��ʵ�� �� ����Ҳ���ܳ�ʼ�� �� һ�㶨����ͷ�ļ���
struct Person
{
	char* name;
	int age;
};

struct News {
	// ʹ���ַ����� �� �ڸ�ֵ��ʱ����ַ�ָ�����в�ͬ
	char title[128];
	char* content;
};

/*�ṹ��ļ���д��*/
// �������ṹ���ʱ�� �� ����ṹ�������ָ��
struct Product {
	char* productName;
	char* productDesc;
}product , *productP;

// �����ṹ , û�нṹ������ �� ���Զ������ṹ������� ����Ϊ����ʹ��
struct {
	char * name;
	int age;
}person;


/*�ṹ��Ƕ�� �� ����Ƕ�׷�ʽ*/

// one
struct GoodsBean {
	int total;
	int status;

	struct Goods {
		char* goodsName;
		char* goodsDesc;
	};
};

// two
struct ProductBean
{
	int total;
	int status;

	struct Product product;
};

/*�ṹǶ��ʾ��*/
void nestingStruct() {
	// one
	printf("\n\n\n\n�ṹǶ��ʾ��\n\n");
	// ʹ������������ʽ��ֵ
	struct GoodsBean goodsBean = { 10,0,{ "ȫ��Iphone6s","��ɫȫ��Iphone6s �� ����Android�ֻ�������Iphone6s" } };
	printf("��Ʒ������%d\n��Ʒ״̬��%d\n��Ʒ���ƣ�%s\n��Ʒ������%s\n", goodsBean.total, goodsBean.status, goodsBean.goodsName, goodsBean.goodsDesc);

	// two
	printf("\n\n");
	struct ProductBean productBean;
	productBean.total = 100;
	productBean.status = 0;
	productBean.product.productName = "��ɫ���� �� С��5 �� ��ֵ��ӵ��";
	productBean.product.productDesc = "ȫ�½�ɫС��5 �� ����û������";

	printf("��Ʒ������%d\n��Ʒ״̬��%d\n��Ʒ���ƣ�%s\n��Ʒ������%s\n", productBean.total, productBean.status, productBean.product.productName, productBean.product.productDesc);
}

/*�ṹ���뺯��ָ��*/
struct Dog {
	char* name;
	int age;

	void(*dogWow)(char* wow);
};

void dogWow(char* wow) {
	printf("���ǣ�%s ��\n", wow);
}

/*�ṹ���뺯��ָ���ʹ��*/
void useStructAndFunction() {
	printf("\n\n\n\n");
	printf("�ṹ���У�����û��ʵ�� �� �ڴ����ṹ��ʱ �� ���������Ƹ�ֵ������ָ�뼴��\n");
	struct Dog dog = { "С��",3,dogWow };
	dog.dogWow("����������");
}

/*�ṹ������*/
void useStructArray() {
	printf("\n\n\n\n�ṹ������ʾ��\n\n");
	// �ṹ������
	struct Person persons[] = { {"zeno",20},{"����",24}, {"����",23} };
	struct Person *p = &persons;
	int personArrSize = sizeof(persons) / sizeof(struct Person);
	printf("�����ṹ�����飺\n");
	// ����
	for (; p < persons + personArrSize; p++)
	{
		printf("������%s \t ���䣺%d\n", p->name, p->age);
	}
}

/*�ṹ���붯̬�ڴ����*/
void structAndMalloc() {
	printf("\n\n\n\n�ṹ���붯̬�ڴ����\n\n");
	// ������ڴ�ռ� �� �ռ��ַ��������
	struct Person* person = (struct Person*)malloc(sizeof(struct Person) * 10);
	struct Person* p = person;
	p->name = "С��";
	p->age = 20;
	p++;
	p->name = "����";
	p->age = 24;

	printf("�����ṹ�嶯̬�ڴ棺\n");
	struct Person* loop_p = person;
	// ����
	for (; loop_p < person + 2; loop_p++)
	{
		printf("������%s \t ���䣺%d\n", loop_p->name, loop_p->age);
	}
}



/*�ṹ�����д����ʹ��*/
void defineMultiStruct() {
	// �������ṹ���ʱ����ṹ���� �� �������� �� �����ٶ���һ��
	product.productName = "ȫ��Xϵ�б��� �� X5";
	product.productDesc = "�޹κ� �� ȫ��Xϵ�б��� �� ���ܼ�ʻ���� �� �Ϳ�����γ�";

	printf("\n\n\n\n");
	printf("��Ʒ��Ϣ��\n��Ʒ���ƣ�%s\n��Ʒ������%s\n",product.productName,product.productDesc);


	printf("\n\n\nʹ�ýṹ��ָ�� , ʹ�ýṹ��ָ�벻��.���� �� ʹ��->�����������ṹ���Ա , ->��������(*p).�ļ�д \n\n");
	productP = &product;
	printf("��Ʒ��Ϣ��\n��Ʒ���ƣ�%s\n��Ʒ������%s\n", productP->productName, productP->productDesc);

	/*ʹ�������ṹ�� �� ʼ��ֻ��һ���ṹ��ʵ�� , ������Ϊ������ʹ��*/
	person.name = "����";
	person.age = 23;
	printf("\n\n");
	printf("�û���Ϣ��\n�û�������%s\n�û����䣺%d\n", person.name, person.age);
}

/*��ʹ�ýṹ��*/
void makeSimpleStruct() {

	// ʹ�ýṹ�� �� ʹ������������ʽ����һ���ṹ��
	struct Person person = { "zeno",21 };
	// ��ӡ
	printf("��������� - %s ; ���� - %d\n", person.name, person.age);


	//��һ�ִ����ṹ��ķ�ʽ
	struct Person person2;
	person2.name = "����";
	person2.age = 23;

	printf("\n��������� - %s ; ���� - %d\n", person2.name, person2.age);

	struct News news;
	//news.title ���ַ����� �� ����ֱ�� news.title = "xxx" �� ��Ҫʹ��strcpy()����
	strcpy(news.title, "�������ű���");
	news.content = " ������������";

	printf("\n\n�����\n���� \n %s \n���ģ�\n  %s\n", news.title, news.content);
}

/*���ͱ��� �ؼ��֣�typedef*/
/*
	1.��ͬ���ƴ����ڸɲ�ͬ������typedef int jint;
	2.��ͬ����£�ʹ�ò�ͬ�ı���
	3.��д���
*/
// �򵥱���

typedef char* Name;

// �ṹ�����
typedef struct ImageInfo {
	char* name;
	int size;
	char* path;
}ImageInfo , *ImageInfo_P;

/*�޸��ļ�����*/
void reFileName(ImageInfo_P imgeInfo_p, char* reName) {
	imgeInfo_p->name = reName;
}

/*���ͱ���ʾ��*/
void useTypedef() {
	// ��ͨ��������ʹ��
	printf("\n\n\n\n���ͱ���ʾ��\n\n");
	Name name = "zeno";
	printf("���ͱ�����Name = %s\n", name);

	/*�ṹ�����ʹ�� , ��ʹ��java��������*/
	ImageInfo imageInfo;
	char pathStr[120] = {"D://imag//"};
	imageInfo.name = "�����羰.jpg";
	// �޸��ļ�����
	reFileName(&imageInfo, "���й�.jpg");

	imageInfo.size = 2333;
	// ƴ���ַ���
	strcat(pathStr, imageInfo.name);
	imageInfo.path = pathStr;


	printf("\n\n�ļ���Ϣ��\n�ļ�����%s\n�ļ���С��%d kb\n�ļ�·����%s\n", imageInfo.name, imageInfo.size, imageInfo.path);

}



//void main() {
//	
//	/*��ʹ�ýṹ��*/
//	makeSimpleStruct();
//
//	/*�ṹ�����д����ʹ��*/
//	defineMultiStruct();
//
//	/*�ṹǶ��ʾ��*/
//	nestingStruct();
//
//	/*�ṹ������*/
//	useStructArray();
//
//	/*�ṹ���붯̬�ڴ����*/
//	structAndMalloc();
//
//	/*�ṹ���뺯��ָ���ʹ��*/
//	useStructAndFunction();
//
//	/*���ͱ���ʾ��*/
//	useTypedef();
//
//	system("pause");
//}

