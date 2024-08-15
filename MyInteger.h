//Header file for Class MyInteger table and the declarations
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
#ifndef MYINTEGER_H
#define MYINTEGER_H
class MyInteger{
public:
    string a;
    int length;
    char sign;
    MyInteger();
    MyInteger(string s);
    ~MyInteger();
    MyInteger parse(string s);//declaration of the functions
    MyInteger pow(MyInteger n);
    MyInteger Ppow(MyInteger n);
    MyInteger abs(MyInteger n);
    string add(string s2);
    string sub(string s2);
    string mul(string s2);
    string div(string s2);
    string Remove_Front(string s);
    bool stringCompare(string s1,string s2);
    MyInteger operator+(const MyInteger &OtherObject);
    MyInteger operator-(const MyInteger &OtherObject);
    MyInteger operator*(const MyInteger &OtherObject);
    MyInteger operator/(const MyInteger &OtherObject);
    MyInteger operator%(const MyInteger &OtherObject);
    MyInteger operator<<(const MyInteger &OtherObject);
    MyInteger operator>>(const MyInteger &OtherObject);
    // friend ostream& operator<<(ostream& stream,const MyInteger &OtherObject);
    MyInteger operator++();
    MyInteger operator--();
    bool operator<(const MyInteger &OtherObject);
    bool operator>(const MyInteger &OtherObject);
    bool operator==(const MyInteger &OtherObject);
    bool operator!=(const MyInteger &OtherObject);
    bool operator<=(const MyInteger &OtherObject);
    bool operator>=(const MyInteger &OtherObject);
    //  friend ostream &operator<<(ostream &output, const MyInteger &OtherObject);
};
#endif

