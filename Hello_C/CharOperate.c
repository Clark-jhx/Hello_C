
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

// �ַ�����
void charArray() {

	// �ַ����� �� �����޸�
	char c[15] = { 'y','e','s',' ','m','a','n' };
	// �ַ��������ֱ����Ϊ�ַ������
	printf("%s\n", c);

	// �޸�
	c[0] = 'a';

	printf("�޸��ַ���%s\n", c);

}

/*�ַ�ָ��*/
void charPointer() {
	// �ڴ��������� , �����޸�
	char* s = "Never give up";

	printf("�ڴ��ַ��%#x\n", s);

	printf("-------------------------------\n��ȡ�ַ�\n");
	// ��ȡ�ַ�
	s += 6;
	while (*s)
	{
		printf("%c", *s);
		s++;
	}
}


/*ƴ�Ӻ���*/
void spliceString() {
	// �ϲ���洢�ַ�������
	char dest[40] = {'h','e','h','e',' '};

	char* c1 = "Never give up ";

	char* c2 = "I blive you ! ";

	// ������ַ�����ԭ�е�����
	//strcpy(dest, c1);
	strcat(dest, c1);
	strcat(dest, c2);

	printf("\nƴ���ַ�����\n%s\n", dest);

}

/*���ҵ����ַ�*/
void searchChar() {
	char* str = "I wanna dont kiss you";
	char* p = strchr(str, 'd');
	
	if (p) {
		printf("����λ�ã�%d\n", p - str);
		printf("��ӡ: ");
		str += p - str;
		while (*str)
		{
			printf("%c",*str);
			str++;
		}
		printf("\n");
	}
	else {
		printf("û���ҵ�\n");
	}
}

/*�����ַ���*/
void sreachChars() {
	char* str = "�仨������ˮ����";
	char* handle = "��";

	char* p = strstr(str, handle);

	if (*p) {
		printf("����λ�ã�%d\n", p - str);
		printf("��ӡ: ");
		str += p - str;
		printf("%s ---- %s\n", str,p);
	}
	else {
		printf("û�ҵ�\n");
	}
}


/*
/-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Narrow String to Number Conversions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
_Check_return_                    _ACRTIMP double    __cdecl atof   (_In_z_ char const* _String);
_Check_return_ _CRT_JIT_INTRINSIC _ACRTIMP int       __cdecl atoi   (_In_z_ char const* _String);
_Check_return_                    _ACRTIMP long      __cdecl atol   (_In_z_ char const* _String);
_Check_return_                    _ACRTIMP long long __cdecl atoll  (_In_z_ char const* _String);
_Check_return_                    _ACRTIMP __int64   __cdecl _atoi64(_In_z_ char const* _String);

_Check_return_ _ACRTIMP double    __cdecl _atof_l  (_In_z_ char const* _String, _In_opt_ _locale_t _Locale);
_Check_return_ _ACRTIMP int       __cdecl _atoi_l  (_In_z_ char const* _String, _In_opt_ _locale_t _Locale);
_Check_return_ _ACRTIMP long      __cdecl _atol_l  (_In_z_ char const* _String, _In_opt_ _locale_t _Locale);
_Check_return_ _ACRTIMP long long __cdecl _atoll_l (_In_z_ char const* _String, _In_opt_ _locale_t _Locale);
_Check_return_ _ACRTIMP __int64   __cdecl _atoi64_l(_In_z_ char const* _String, _In_opt_ _locale_t _Locale);

_Check_return_ _ACRTIMP int __cdecl _atoflt (_Out_ _CRT_FLOAT*  _Result, _In_z_ char const* _String);
_Check_return_ _ACRTIMP int __cdecl _atodbl (_Out_ _CRT_DOUBLE* _Result, _In_z_ char*       _String);
_Check_return_ _ACRTIMP int __cdecl _atoldbl(_Out_ _LDOUBLE*    _Result, _In_z_ char*       _String);

*/
/*�ַ�ת��int*/
void strToInt() {
	char* p = "123";
	int toInt = atoi(p);
	int res = toInt + 123;
	printf("�ַ�ת��int��ֵ: %d\n", res);
}


/* �ַ����� */
/*
void main() {
	

	charArray();

	charPointer();

	spliceString();

	searchChar();

	sreachChars();

	strToInt();

	system("pause");

}
*/