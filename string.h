#ifndef _STRING_H
#define _STRING_H

#include<iostream>

class string
{
public:
	//  ���캯��
	string(const char * str = nullptr);
	// ��������
	~string();
	//  ��������
	string(const string &other);

public:
	// ���� =
	void operator=(const string & other);
	// ���� << �� >>
	friend std::ostream & operator<<(std::ostream &out, string &obj);
	friend std::istream & operator >> (std::istream &in, string &obj);

public:
	//  ��дһ��������ʵ����c�����ַ���s�ĸ�ֵ
	string &assign(const char *s);
	// �������Ϸ�����ʵ��c�����ַ���s��ʼ�ĵ�n���ַ��ĸ�ֵ��
	string &assign(const char *s, int n);
	// �������Ϸ�����ʵ�ֽ�n���ַ�c��ֵ����ǰ�ַ�����
	string &assign(int n, char c);
	// ʵ�ְ��ַ���s���ӵ���ǰ�ַ����Ľ�β
	string &operator+=(const string &s);
	//ʵ�ְ�c�����ַ���s���ӵ���ǰ�ַ�����β
	string &append(const char *s);

public:
	//�Ƚ�����ָ�����ַ�������
	static int Compare(string strA, string strB);
	// �Ƿ���Ӵ�Сд
	static int Compare(string strA, string strB, bool ignoreCase);

public:
	// ����ָ�����ַ����ڴ��ַ����еĵ�һ��ƥ���������������ҵ����ַ�����Ϊvalue���㿪ʼ������λ�ã���δ�ҵ����򷵻� - 1��
	int Indexof(string value);
	// ���ش�ָ��λ�ÿ�ʼ��ƥ�����������δ�ҵ����򷵻� - 1��
	int Indexof(string value, int startIndex);
	// �����ش�ָ��λ�ÿ�ʼ��ƥ�������������ֻ���ָ���������ַ�λ������ҵ����ַ�����Ϊvalue���㿪ʼ������λ�ã���δ�ҵ����򷵻�-1��
	int Indexof(string value, int startIndex, int count);
	// ���� 
	int Indexof(int endIndex, string value, int startIndex);
	// �滻
	string replace(string oldValue, string newValue);
	// ���пհ��ַ���ȥ��
	string trim(string value);
	//�������Ϸ�������ȥ��ָ�����ַ���Ľ����
	string trim(string value, string trimString);
	// �ӵ�ǰ�ַ�����ȥ��ָ����ǰ��ƥ���ַ�����������ȥ����Ľ����
	string trimStart(string value, string trimString);
	// �ӵ�ǰ�ַ�����ȥ��ָ����β��ƥ���ַ�����������ȥ����Ľ����
	string trimEnd(string value, string trimString);
	// ���ص�ǰ�ַ����ĳ���
	int getLength(string value);
	// �������Ϸ���������ڶ�������(string insertString)�����ز����µ��ַ����󣬵�ǰ�ַ����ĳ���
	int getLength(string value, string insertString);
	// �������Ϸ������������������(string trimString)�����ز����µ��ַ���֮��ȥ����ָ���ַ�����ĵ�ǰ�ַ������ȡ�
	int getLength(string value, string insertString, string trimString);
	// ��չ
	int insertString(string value, int index);
	

public:
	int GetStringLength(const char* str);
	int GetStringLength();
	void strcpy(char *dest, const char* src);

private:
	char *m_pStr;                              //�����ַ���
	int m_strLen;                              //�����ַ�������
};

#endif
