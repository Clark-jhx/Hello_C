
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/*������ �� ö�� �� �ļ�IO*/

/*������*/
/*
	��ͬ���͵ı�������һ���ڴ棨�໥���ǣ� �� ʼ��ֻ��һ����Ա���� �� ���ֵ���Ǹ� �� �����ڽ�ʡ�ڴ�
	�������С����Ա�����ĳ�Ա��ռ���ֽ���
*/
union mValue
{
	int		i;
	short	s;
	long	l;
	float	f;

};

/*������ʾ��*/
void useUnion() {
	union mValue m;
	m.f = 23.4f;
	m.i = 100;  // ���һ�θ�ֵ��Ч

	printf("�����壺\n%f - %d\n", m.f, m.i);
}

/*ö��*/
/*
	ö�٣��о����е������
	�޶�ֵ����֤ȡֵ�İ�ȫ��
*/
enum NetStatus {
	NET_SUCEESS,
	NET_ERROR,
	NOT_NET,
	NET_FAILURE
};

/*ģ����������*/
void requestHttp(char* url, void(*callBack)(enum NetStatus status,char* res)) {
	printf("�����ַ��%s\n", url);
	printf("��������....\n");
	Sleep(2000);
	enum NetStatus status = NET_SUCEESS;
	char* res = "��� ������һ������ ,һ�����ŵĻ���,��ҲҪȥ׷��\n";
	callBack(status, res);
}

/*����ص�����*/
void callBackHttp(enum NetStatus status, char* res) {
	switch (status)
	{
	case NET_SUCEESS:
		printf("�������ݣ�\n%s", res);
		break;
	case NET_ERROR:
		printf("�������\n");
		break;
	case NOT_NET:
		printf("û�����磺\n");
		break;
	case NET_FAILURE:
		printf("�����������\n");
		break;
	default:
		printf("δ֪����\n");
		break;
	}
}

/*ö��ʾ��*/
void useEnum() {
	enum NetStatus status = NET_FAILURE;

	printf("ö����Ԫ�ص�ֵ��%d\n", status);

	char* url = "http://www.zhuyongit.com";
	requestHttp(url, callBackHttp);
}


/*�ļ�IO*/

/*��ȡ�ı��ļ�*/
void readTextFile() {
	char* path = "C:\\Users\\Zeno\\Documents\\Visual Studio 2015\\Projects\\Hello_C\\Hello_C\\StructPointer.c";

	// ���ļ�
	FILE* fp = fopen(path, "r");
	if (fp == NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	// �ַ������� �� ÿ�ζ�һ���ַ��� �� ���Ỻ�浽�ַ�������
	char buffer[1024];
	while (fgets(buffer, 1024, fp)) {
		printf("%s", buffer);
	}

	// �ر��ļ���
	fclose(fp);
}

/*д���ı��ļ�*/
void writeTextFile() {
	char* path = "E:\\document\\write.txt";

	char* content = "��� ������һ������ ,һ�����ŵĻ���,��ҲҪȥ׷��\n��� ������һ������ ,һ�����ŵĻ���,��ҲҪȥ׷��\n";

	// ���ļ�
	/*
		��ֻд�ļ������ļ��������ļ�������Ϊ0�������ļ����ݻ���ʧ�����ļ��������������ļ���
	*/
	FILE* fp = fopen(path, "w");
	if (fp == NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	// д���ļ�
	fputs(content, fp);

	// �ر��ļ���
	fclose(fp);
}

/*��д�������ļ� -- �����ļ�*/
void fileCopy() {
	char* currentPath = "E:\\android_pdf\\��ĥ���ģʽ.pdf";
	char* destPath = "E:\\android_pdf\\��ĥ���ģʽ_new.pdf";

	// ���ļ�
	FILE* currentFile_P = fopen(currentPath, "rb");
	FILE* destFile_P = fopen(destPath, "wb");

	// �ȶ�ȡ��д��
	int buffer[1024]; // ���ݻ�����
	int len; // ÿ�ζ�ȡ���ݵĳ���
	while ((len = fread(buffer,sizeof(int),1024,currentFile_P)) != EOF)
	{
		// ���������������д�뵽�ļ���
		fwrite(buffer, sizeof(int), len, destFile_P);
	}

	// �ر���
	fclose(destFile_P);
	fclose(currentFile_P);
}

/*�����ļ�*/
void encryptFile() {

	// �������ļ�·��
	char* normal_path = "E:\\poto\\xj.jpg";
	// ���ܺ��ļ�·��
	char* encrypt_path = "E:\\poto\\xj_encrypt.jpg";

	//���ļ�
	FILE* normal_fp = fopen(normal_path, "rb");
	FILE* encrypt_fp = fopen(encrypt_path, "wb");
	// ���ļ�
	int buffer;
	while ((buffer = fgetc(normal_fp)) != EOF) {
		// д���ļ�
		fputc(buffer ^ 8, encrypt_fp);
	}

	printf("�ļ����ܳɹ�\n");

	// �ر���
	fclose(encrypt_fp);
	fclose(normal_fp);
}

/*�ļ�����*/
void decryptFile() {
	// �����ļ�·��
	char* encrypt_path = "E:\\poto\\xj_encrypt.jpg";
	// �����ļ�·��
	char* decrypt_path = "E:\\poto\\xj_deencrypt.jpg";

	// ���ļ�
	FILE* encrypt_fp = fopen(encrypt_path, "rb");
	FILE* decrypt_fp = fopen(decrypt_path, "wb");

	// ��ȡ�ļ�
	int buffer;
	while ((buffer = fgetc(encrypt_fp)) != EOF) {
		// д�ļ�
		fputc(buffer ^ 8, decrypt_fp);
	}

	printf("�ļ����ܳɹ�\n");

	// �ر���
	fclose(decrypt_fp);
	fclose(encrypt_fp);
}

/*��������ļ�����*/
void passwordEncryptFile(char password[]) {
	// �������ļ�·��
	char* normal_path = "E:\\poto\\xj.jpg";
	// �����ļ�·��
	char* encrypt_path = "E:\\poto\\xj_encrypt.jpg";

	// ���ļ�
	FILE* normal_fp = fopen(normal_path,"rb");
	FILE* encrypt_fp = fopen(encrypt_path, "wb");

	// ���ļ�
	int buffer;
	int i = 0;
	int passwordCount = strlen(password);
	while ((buffer = fgetc(normal_fp)) != EOF)
	{
		// д�ļ�
		fputc(buffer ^ password[i % passwordCount], encrypt_fp);
		i++;
	}

	printf("�ļ����ܳɹ�\n");

	// �ر���
	fclose(encrypt_fp);
	fclose(normal_fp);
}

void passwordDecryptFile(char password[]) {
	// �����ļ�·��
	char* encrypt_path = "E:\\poto\\xj_encrypt.jpg";
	// �����ļ�·��
	char* decrypt_path = "E:\\poto\\xj_decrypt.jpg";

	// ���ļ�
	FILE* encrypt_fp = fopen(encrypt_path, "rb");
	FILE* decrypt_fp = fopen(decrypt_path, "wb");

	// ���ļ�
	int buffer;
	int i = 0; 
	int passwordCount = strlen(password);
	while ((buffer = fgetc(encrypt_fp)) != EOF) {
		// д�ļ�
		fputc(buffer ^ password[i % passwordCount], decrypt_fp);
		i++;
	}
	printf("�ļ����ܳɹ�\n");


	// �ر���
	fclose(decrypt_fp);
	fclose(encrypt_fp);

}

/*��ȡ�ļ���С*/
void getFileSize() {

	char* path = "E:\\android_pdf\\��ĥ���ģʽ.pdf";
	// ���ļ�
	FILE* fp = fopen(path, "r");
	if (fp == NULL) {
		printf("���ļ�ʧ��\n");
		return;
	}

	// ���¶�λ�ļ�ָ�� , SEEK_END�ļ�ĩβ��0ƫ����
	fseek(fp, 0l, SEEK_END);
	// ���ص�ǰ���ļ�ָ�룬������ļ���ͷ��λ����
	long fileSize = ftell(fp);

	printf("�ļ���С��%ld M\n", fileSize / 1024 / 1024);

}

/*
void main() {

	// ������ʾ��
	//useUnion();
	
	// ʹ��ö��
	useEnum();

	// ��ȡ�ı��ļ�
	//readTextFile();

	// д���ı��ļ�
	//writeTextFile();

	// �������ļ�����
	//fileCopy();

	// ��ȡ�ļ���С
	//getFileSize();

	// �����ļ�
	//encryptFile();

	// �����ļ�
	//decryptFile();

	// ��������ļ�
	//passwordEncryptFile("my love");

	// ��������ļ�
	//passwordDecryptFile("my love");

	system("pause");
}*/