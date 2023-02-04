# String-class-of-Cplusplus
## c++原型类的设计实现

## 1.Architecture
![image](https://user-images.githubusercontent.com/50736666/119653428-e5b2d000-be59-11eb-98d6-8a3e0e13db34.png)

## 2.1 Dynamic method part
#### 2.1.1. Constructor
The constructor of the string class uses a pointer to point to a certain memory address. When the initialization string does not exist, apply for a space. When the initialization string exists, apply for a space of the same size to store the string.
##### Format：public string (const char * str = null)
#### 2.1.2.Destructors
The destructor of the string class releases the address space
##### Format：public ~string(void method)
#### 2.1.3.Copy constructor
The copy constructor of the string class is similar to the constructor
##### Format：public string(const string & other)
#### 2.1.4. Overloading the equality operator
When the address is the same, return the result directly. When the addresses are not the same, delete the original application address space, restart the construction and return.
##### Format：public string::operator = (const string & other)
#### 2.1.5.Input and output operations
The overloaded operators operator>> and operator<< are used for input and output operations respectively.
#### 2.1.6.Write a method to realize the assignment of a string s of type c.
##### Format：string &assign(const char *s)
#### 2.1.7. 
Overload the above method to realize the assignment of the nth character starting from the c-type string s.
##### Format：string &assign(const char *s, int n)
#### 2.1.8. 
Overload the above method to realize the assignment of n characters c to the current string.
##### Format：string &assign(int n,char c)
#### 2.1.9. 
Overload the operator to connect the string s to the end of the current string
##### Format：string &operator+=(const string &s)
#### 2.1.10. 
Write a method to connect the c-type string s to the end of the current string
##### Format：string &append(const char *s)



## 2.2 Static method part
#### 2.2.1. 
Compares two specified string objects and returns an integer indicating their relative positions in the sort order.
When the return value is less than 0, strA comes before strB in the sort order. When the return value is equal to 0, strA is equal to strB in sort order. When the return value is less than 0, strA comes after strB in the sort order.
##### Format：public static int Compare(string strA, string strB)
#### 2.2.2. 
Overload the above method and add the third parameter value (bool ignoreCase). When this parameter is entered as true, case will be ignored when comparing string objects; when this parameter is entered as false, string objects will be compared case will not be ignored.
##### Format：public static int Compare(string strA, string strB, bool ignoreCase)
#### 2.2.3. 
Return the index of the first occurrence of the specified string in this string. If the character is found, it will be the zero-based index position of value; if not found, it will return -1.
##### Format：public int Indexof(string value)
#### 2.2.4. 
Overload the above method, add the second parameter value (int startIndex), and return the matching index result starting from the specified position. If the character is found, it will return the index position of value starting from zero; if not found, then return -1.
##### Format：public int Indexof(string value, int startIndex)
#### 2.2.5. 
Overload the above method, add the third parameter value (int count), return the matching index result starting from the specified position, and only check the specified number of character bits, if the character is found, the value starts from zero The index position of the , or -1 if not found.
##### Format：public int Indexof(string value, int startIndex, int count)
#### 2.2.6. 
Return a new string in which all specified strings in the current instance are replaced with another specified string
##### Format：public string replace(string oldValue, string newValue)
#### 2.2.7. 
Remove all whitespace characters at the beginning and end of the current string, and return the remaining string after removal
##### Format：public string trim(string value)
#### 2.2.8. 
Overload the above method, add the second parameter (string trimString), and return the result after removing the specified characters.
##### Format：public string trim(string value, string trimString)
#### 2.2.9. 
Remove the specified leading matching string from the current string and return the removed result.
##### Format：public string trimStart(string value, string trimString)
#### 2.2.10. 
Remove the specified tail matching string from the current string, and return the removed result.
##### Format：public string trimEnd(string value, string trimString)
#### 2.2.11. 
Return the length of the current string
##### Format：public string getLength(string value)
#### 2.2.12. 
Overload the above method, add the second parameter (string insertString), return the length of the current string after inserting the new string
##### Format：Public int getLength(string value, string insertString)
#### 2.2.13. 
Overload the above method, add the third parameter (string trimString), and return the current string length after inserting the new string and removing the specified string.
##### Format：public int getLength(string value, string insertString, string trimString)
