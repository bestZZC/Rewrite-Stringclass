#ifndef _STRING_H
#define _STRING_H

#include<iostream>

class string
{
public:
	//  构造函数
	string(const char * str = nullptr);
	// 析构函数
	~string();
	//  拷贝构造
	string(const string &other);

public:
	// 重载 =
	void operator=(const string & other);
	// 重载 << 与 >>
	friend std::ostream & operator<<(std::ostream &out, string &obj);
	friend std::istream & operator >> (std::istream &in, string &obj);

public:
	//  编写一个方法，实现用c类型字符串s的赋值
	string &assign(const char *s);
	// 重载以上方法，实现c类型字符串s开始的第n个字符的赋值。
	string &assign(const char *s, int n);
	// 重载以上方法，实现将n个字符c赋值给当前字符串。
	string &assign(int n, char c);
	// 实现把字符串s连接到当前字符串的结尾
	string &operator+=(const string &s);
	//实现把c类型字符串s连接到当前字符串结尾
	string &append(const char *s);

public:
	//比较两个指定的字符串对象
	static int Compare(string strA, string strB);
	// 是否忽视大小写
	static int Compare(string strA, string strB, bool ignoreCase);

public:
	// 返回指定的字符串在此字符串中的第一个匹配项的索引，如果找到该字符，则为value从零开始的索引位置；如未找到，则返回 - 1。
	int Indexof(string value);
	// 返回从指定位置开始的匹配索引结果如未找到，则返回 - 1。
	int Indexof(string value, int startIndex);
	// ，返回从指定位置开始的匹配索引结果，并只检查指定数量的字符位，如果找到该字符，则为value从零开始的索引位置；如未找到，则返回-1。
	int Indexof(string value, int startIndex, int count);
	// 扩充 
	int Indexof(int endIndex, string value, int startIndex);
	// 替换
	string replace(string oldValue, string newValue);
	// 所有空白字符都去除
	string trim(string value);
	//重载以上方法返回去除指定的字符后的结果。
	string trim(string value, string trimString);
	// 从当前字符串中去除指定的前导匹配字符串，并返回去除后的结果。
	string trimStart(string value, string trimString);
	// 从当前字符串中去除指定的尾部匹配字符串，并返回去除后的结果。
	string trimEnd(string value, string trimString);
	// 返回当前字符串的长度
	int getLength(string value);
	// 重载以上方法，加入第二个参数(string insertString)，返回插入新的字符串后，当前字符串的长度
	int getLength(string value, string insertString);
	// 重载以上方法，加入第三个参数(string trimString)，返回插入新的字符串之后，去除掉指定字符串后的当前字符串长度。
	int getLength(string value, string insertString, string trimString);
	// 扩展
	int insertString(string value, int index);
	

public:
	int GetStringLength(const char* str);
	int GetStringLength();
	void strcpy(char *dest, const char* src);

private:
	char *m_pStr;                              //储存字符串
	int m_strLen;                              //储存字符串长度
};

#endif
