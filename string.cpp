#include "string.h"

#define DEFAULT_STRING_LENGTH 100

string::string(const char * str)
{
	int i = 0;

	if (str != nullptr){
		m_strLen = GetStringLength(str);
	}
	else{
		m_strLen = DEFAULT_STRING_LENGTH;
	}
	m_pStr = new char[m_strLen + 1];
	memset(m_pStr, 0, m_strLen + 1);

	if (str != nullptr){
		strcpy(m_pStr, str);
	}
}


string::~string()
{
	if (m_pStr != nullptr){
		delete[] m_pStr;
		m_pStr = nullptr;
	}
}

string::string(const string &other)
{
	m_strLen = other.m_strLen;
	m_pStr = new char[other.m_strLen + 1];

	strcpy(m_pStr, other.m_pStr);
	m_pStr[m_strLen] = '\0';
}
//重载=
void string::operator=(const string & other)
{
	int i = 0;
	if (other.m_pStr != m_pStr){
		delete[] m_pStr;

		m_strLen = other.m_strLen;
		m_pStr = new char[m_strLen + 1];
		strcpy(m_pStr, other.m_pStr);
		m_pStr[m_strLen] = '\0';
	}
}
//重载<<和>>
std::ostream & operator<<(std::ostream &out, string &obj)
{
    out << obj.m_pStr;
    return out;
}

std::istream & operator>>(std::istream &in, string &obj)
{
	int i;
	char str[1025];
	char c;
	for (i = 0; i < 1024; i++){
		std::cin.get(c);
		if (c == '\n'){
			break;
		}
		str[i] = c;
	}

	str[i] = '\0';
	obj = str;
    return in;
}
// 赋值
string& string::assign(const char *s)
{
	*this = string(s);
	return *this;
}
//从第n个字符开始赋值
string& string::assign(const char *s, int n)
{
	m_pStr[n - 1] = s[n - 1];
	return *this;
}

//实现把c类型字符串s连接到当前字符串结尾
string& string::assign(int n, char c)
{
	int i = 0;
	delete[] m_pStr;            //释放字符串
	m_strLen = n;
	m_pStr = new char[m_strLen + 1];
	
	for (i = 0; i < n; i++){
		m_pStr[i] = c;     
	}
	m_pStr[m_strLen] = '\0';
	
	return *this;
}

//重载+=连接到当前字符串的结尾
string& string::operator+=(const string &s)
{
	int i = 0;
	int len = s.m_strLen + this->m_strLen + 10;
	char *pStr = new char[len];
	memset(pStr, 0, len);
	strcpy(pStr, m_pStr);
	strcpy(pStr + m_strLen, s.m_pStr);

	*this = string(pStr);
	delete[] pStr;

	return *this;
}

//字符串s连接到当前字符串结尾
string &string::append(const char *s)
{
	int i = 0;
	char *pStr = new char[this->GetStringLength(s) + this->m_strLen + 1];
	strcpy(pStr, m_pStr);
	strcpy(pStr + this->m_strLen, s);

	*this = string(pStr);
	delete[] pStr;

	return *this;
}
// 比较函数
int string::Compare(string strA, string strB)
{
	int flag = 1;
	int i = 0;
	while (1){
		if (strA.m_pStr[i] == 0){
			break;
		}
		else if (strB.m_pStr[i] == 0){
			break;
		}
		else if (strA.m_pStr[i] != strB.m_pStr[i]){
			break;
		}

		++i;
	}
	//逐个字符比对
	if (strA.m_pStr[i] > strB.m_pStr[i]){
		return 1;
	}
	else if (strA.m_pStr[i] == strB.m_pStr[i]){
		return 0;
	}
	else{
		return -1;
	}
}

int string::Compare(string strA, string strB, bool ignoreCase)
{
	int i = 0;
	int len = 0;
	if (ignoreCase == false){
		return Compare(strA, strB);
	}
	// 化为小写
	len = strA.m_strLen > strB.m_strLen ? strB.m_strLen : strA.m_strLen;
	for (i = 0; i < len; i++){
		if ((strA.m_pStr[i] > 'a') && (strA.m_pStr[i] < 'z')){
			strA.m_pStr[i] -= 32;
		}
		if ((strB.m_pStr[i] > 'a') && (strB.m_pStr[i] < 'z')){
			strB.m_pStr[i] -= 32;
		}
	}
	if (strA.m_strLen > len){
		for (i = len; i < strA.m_strLen; i++){
			if ((strA.m_pStr[i] > 'a') && (strA.m_pStr[i] < 'z')){
				strA.m_pStr[i] -= 32;
			}
		}
	}
	else if (strB.m_strLen > len){
		for (i = len; i < strB.m_strLen; i++){
			if ((strB.m_pStr[i] > 'a') && (strB.m_pStr[i] < 'z')){
				strB.m_pStr[i] -= 32;
			}
		}
	}

	return Compare(strA, strB);
}

int string::Indexof(string value)
{
	int i = 0;
	int j = 0;
	int length = m_strLen - value.m_strLen + 1;
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < value.m_strLen; j++){
			if (m_pStr[i + j] != value.m_pStr[j]){
				break;
			}
		}
		if (j == value.m_strLen){
			return i;
		}
	}
	return -1;
}

int string::Indexof(string value, int startIndex)
{
	int i = 0;
	int j = 0;
	int length = m_strLen - value.m_strLen;
	for (i = startIndex; i < length; i++)
	{
		for (j = 0; j < value.m_strLen; j++){
			if (m_pStr[i + j] != value.m_pStr[j]){
				break;
			}
		}
		if (j == value.m_strLen && value.m_pStr[j - 1] == m_pStr[i + j - 1]) {
			return i;
		}
	}
	return -1;
}

int string::Indexof(string value, int startIndex, int count)
{
	int i = 0;
	int j = 0;
	int length = m_strLen - value.m_strLen + 1;
	if (value.m_strLen < count){
		throw "count > value.length";
	}

	for (i = startIndex; i < length; i++)
	{
		for (j = 0; j < count; j++){
			if (m_pStr[i + j] != value.m_pStr[j]){
				break;
			}
		}
		if (j == count){
			return i;
		}
	}
	return -1;
}


int string::Indexof(int endIndex, string value, int startIndex)
{
	int i = 0;
	int j = 0;
	if (m_strLen < endIndex){
		throw "count > value.length";
	}

	for (i = startIndex; i < endIndex; i++)
	{
		for (j = 0; j < value.m_strLen; j++){
			if (m_pStr[i + j] != value.m_pStr[j]){
				break;
			}
		}
		if (j == value.m_strLen){
			return i;
		}
	}
	return -1;
}
//字符串替换
string string::replace(string oldValue, string newValue)
{
	int index = 0;
	int j = 0, i = 0;
	int k = 0;
	int temp = 0;
	int l = newValue.m_strLen - oldValue.m_strLen;
	char *pStr = new char[m_strLen + l + 10];
	memset(pStr, 0, m_strLen + l + 10);

	index = Indexof(oldValue);
	if (index == -1){                //防止翻车
		return *this;
	}
	while (index != -1 && k < m_strLen){
		for (i = 0; i < index - temp; i++){
			pStr[j ++] = m_pStr[k++];
		}
		k += oldValue.m_strLen;
		for (i = 0; i < newValue.m_strLen; i++){
			pStr[j++] = newValue.m_pStr[i];
		}
		temp = index + oldValue.m_strLen;
		index = Indexof(oldValue, index + 1);
	}
	
	while (m_pStr[k] != 0){
		pStr[j++] = m_pStr[k++];
	}
	pStr[j] = '\0';
	string rStr(pStr);
	delete[] pStr;

	return rStr;
}

string string::trim(string value)
{
	int i = 0;
	int begin, end;                        //确定字符串的起点终点位置
	string s = value;
	int knum = 0;
	char *pStr = new char[s.m_strLen + 1];
	memset(pStr, 0, s.m_strLen + 1);
	while (s.m_pStr[i++] != ' ' && s.m_pStr[i++] != '\0');       
	begin = i - 1;

	i = value.m_strLen - 1;
	while (s.m_pStr[i--] == ' ');
	end = i + 1;

	for (i = begin; i < end; i++){
		pStr[i - begin] = m_pStr[i];
	}
	pStr[i - begin] = '\0';
	string rStr(pStr);
	delete[] pStr;

	return rStr;
}

string string::trim(string value, string trimString)
{
	int i = 0, j = 0, k = 0;
	int temp = 0;
	int index = value.Indexof(trimString);       //获取trimString位置
	if (index == -1){
		return value;
	}
	char* pStr = new char[value.m_strLen + 1];
	memset(pStr, 0, value.m_strLen + 1);

	while (index != -1){
		for (i = temp; i < index; i++){
			pStr[k] = value.m_pStr[i];
			++k;
		}
		temp = index + 1;
		index = value.Indexof(trimString, temp);
	}
	for (i = temp; i < value.m_strLen; i++){
		pStr[k] = value.m_pStr[i];
		++k;
	}
	pStr[k] = 0;
	string rStr(pStr);
	delete[] pStr;

	return rStr;             
}
//前导匹配字符串替换
string string::trimStart(string value, string trimString)
{
	int i = 0, j = 0;
	int start = value.Indexof(trimString);
	if (start != 0){
		return value;
	}
	char* pStr = new char[value.m_strLen + 1];
	memset(pStr, 0, value.m_strLen + 1);
	while (i < start){
		pStr[j] = value.m_pStr[i];
		++i;
		++j;
	}
	i += trimString.m_strLen;
	while (i < value.m_strLen){
		pStr[j] = value.m_pStr[i];
		++i;
		++j;
	}
	string rStr(pStr);
	delete[] pStr;

	return rStr;
}

string string::trimEnd(string value, string trimString)
{
	int i = 0, j = 0;
	int index = 0;
	int end = -1;
	index = value.Indexof(trimString);
	while (index != -1){
		end = index;
		index = value.Indexof(trimString, index + 1);
	}
	if (end == -1){
		return value;
	}
	char* pStr = new char[value.m_strLen + 1];
	memset(pStr, 0, value.m_strLen + 1);
	while (i < end){
		pStr[j] = value.m_pStr[i];
		++i;
		++j;
	}
	i += trimString.m_strLen;
	while (i < value.m_strLen){
		pStr[j] = value.m_pStr[i];
		++i;
		++j;
	}
	string rStr(pStr);
	delete[] pStr;

	return rStr;
}
// 返回当前字符串的长度
int string::getLength(string value)
{
	return value.m_strLen;
}

int string::getLength(string value, string insertString)
{
	return value.m_strLen + insertString.m_strLen;
}

int string::getLength(string value, string insertString, string trimString)
{
	return value.m_strLen + insertString.m_strLen - trimString.m_strLen;
}

int string::GetStringLength(const char* str){
	int i = 0;
	while (str[i++] != 0);

	return i - 1;
}
//插入字符串
int string::insertString(string value, int index)
{
	int i = 0;
	int j = 0;
	char *pStr = new char[m_strLen + value.m_strLen + 1];
	if (m_strLen < index){                         //判断目标位置和原字符串的长度
		return -1;
	}
	while (i < index){
		pStr[i] = m_pStr[i];
		++i;
	}
	for (j = 0; j  < value.m_strLen; j ++){
		pStr[j + i] = value.m_pStr[j];
	}
	while (i < m_strLen){
		pStr[i + j] = m_pStr[i];
		++i;
	}
	pStr[i + j] = 0;
	*this = pStr;

	return index;
}

int string::GetStringLength(){
	return m_strLen;
}

void string::strcpy(char *dest, const char* src)
{
	int i = 0;
	while (src[i] != '\0'){
		dest[i] = src[i];                //拷贝字符串
		++i;
	}
}
