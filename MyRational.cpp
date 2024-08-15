//
//  main.cpp
//  PoplAssingment
//

#include "MyInteger.h"
#include "MyInteger.cpp"
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
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%I64d",&x)
#define sc(x) scanf("%c",&x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define maX(a,b) ((a)>(b)?a:b)
#define miN(a,b) ((a)<(b)?a:b)
#define mem(x,y) memset(x,y,sizeof(x))
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define max_int_value 2147483647
#define max_long_value 9223372036854775807
#define fill(a,v) memset(a, v, sizeof a)
#define mod 1000000007
typedef pair<int, int> ii;
typedef pair<char, ii> iii;
class MyRational{
private:
    MyInteger Num;//private member of the class Myinteger for Denominator and Numerator
    MyInteger Den;
public:
    MyRational();
    MyRational(string s);//constructor
    ~MyRational();//destructor
    MyRational parse(string s);//parsing the string to make a rational instance
    string Remove_Front(string s);//remove the front zeroes
    MyRational pow(MyInteger n);
     void abs();
    MyInteger intVal();
    string floatVal();
    string ToString(int p);
    MyRational create(MyInteger s);//creating a instance of string s of type Myrational
    bool stringCompare(string s1,string s2);//comparing string by equalising the denominators
    MyRational operator+(const MyRational &OtherObject);
    MyRational operator-(const MyRational &OtherObject);
    MyRational operator*(const MyRational &OtherObject);
    MyRational operator/(const MyRational &OtherObject);
    MyRational operator%(const MyRational &OtherObject);
    MyRational operator++();
    MyRational operator--();
    bool operator<(const MyRational &OtherObject);
    bool operator>(const MyRational &OtherObject);
    bool operator==(const MyRational &OtherObject);
    bool operator!=(const MyRational &OtherObject);
    bool operator<=(const MyRational &OtherObject);
    bool operator>=(const MyRational &OtherObject);
    friend ostream &operator<<(ostream &output, const MyRational &OtherObject);
};
MyRational ::MyRational(){
    Num.a.push_back('0');
    Den.a.push_back('1');//basic constructor initialising the value with zero
    Den.sign='+';
    Num.sign='+';
}
MyRational ::~MyRational(){
    Num.a.clear();
    Num.sign='+';
    Den.a.clear();
}
string MyRational::Remove_Front(string s){
    string tmp;
    int i;
    for( i=0;i<s.length();i++){
        if(s[i]!='0')break;
    }
    for(int j=i;j<s.length();j++){
        tmp.push_back(s[j]);
    }
    if(tmp.length()==0)tmp.push_back('0');
    return  tmp;
}
MyRational ::MyRational(string s){
    int i=0;
    if(s[0]=='-'){
        Num.sign='-';
        i++;
    }
    else Num.sign='+';
    int Dpoint=0;//it is number of decimal places after the point
    int flag=0;
    string Temp;
    while(i<(int)s.length()){
        if(s[i]=='.'){
            flag=1;
            i++;
            continue;
        }
        if(flag)Dpoint++;
        Temp.push_back(s[i]);
        i++;
    }
    Temp=Remove_Front(Temp);//removing zeroes from the front
    Num.a=Temp;
    string Another;
    Another.push_back('1');
    for(int i=0;i<Dpoint;i++){
        Another.push_back('0');//making den as pow(10,something)
    }
    Den.a=Another;
    Den.sign='+';
}
MyRational  MyRational ::parse(string s){
    MyRational Object=MyRational(s);//using the constructor
    return Object;
}
void MyRational ::abs(){
    Num.sign='+';   //numerator will be positive
}
string  MyRational::floatVal(){
    string Numer;
    MyRational tmp=*this;
    int l1=(int)tmp.Num.a.length();
    int l2=(int)tmp.Den.a.length();
    if(l2>l1){
        for(int i=0;i<l2-l1-1;i++){
            Numer.pb('0');
        }
    }
    for(int i=0;i<l1;i++){
        Numer.pb(tmp.Num.a[i]);
    }
    ll diff=(int)Numer.length()-(int)tmp.Den.a.length();
    //  cout<<Numer<<endl;
    int i;
    string Ans;
    for(i=0;i<Numer.length();i++){
        if(diff==(i-1))break;
        //   Ans.pb(Numer[i]);
    }
    //  if(i==0)Ans.pb('0');
    Ans.pb('.');
    for(int j=i;j<Numer.length();j++){
        Ans.pb(Numer[j]);
    }
    return Ans;
}
MyInteger MyRational:: intVal(){
    MyRational tmp=*this;
    MyInteger Final;
    int l1=(int)tmp.Num.a.length();
    int l2=(int)tmp.Den.a.length();
    if(l2>l1){
        Final.a.clear();
        Final.a.pb('0');
        Final.length=1;
        Final.sign=tmp.Num.sign;
        return Final;
    }
    else{
        Final.a.clear();
        for(int i=0;i<=l1-l2;i++){
            Final.a.pb(tmp.Num.a[i]);
        }
        Final.sign=tmp.Num.sign;
        Final.length=(int)tmp.Num.a.length();
        return Final;
    }
}
string MyRational::ToString(int p){
    MyRational tmp=*this;
    string Ans;
    MyInteger tmp1;
    tmp1.a.clear();
    tmp1=tmp.intVal();
    string Float_string=tmp.floatVal();
    string Int_string=tmp1.a;
    for(int i=0;i<Int_string.size();i++){
        Ans.pb(Int_string[i]);
    }
    int i;
    for(i=0;i<Float_string.size();i++){
        if(Float_string[i]=='.')break;
    }
    if(p>0)
        Ans.pb('.');
    i++;
    int k=0;
    for(int j=i;j<Float_string.size();j++){
        if(k==p)break;
        Ans.pb(Float_string[j]);
        k++;
    }
    return Ans;
}

MyRational MyRational::operator+(const MyRational &OtherObject){
    MyRational tmp=*this;
    ll Len_to_multiply=0;
    if(tmp.Den.a.length()>OtherObject.Den.a.length()){  //equalisng the denominator
        Len_to_multiply=tmp.Den.a.length()-OtherObject.Den.a.length();
        string Tmp_for=OtherObject.Num.a;
        string To_multiply;
        To_multiply.pb('1');
        MyInteger tmp1;
        for(ll i=1;i<=Len_to_multiply;i++){
            To_multiply.pb('0');
        }
        tmp1.a=Tmp_for;//Numerator of the smaller den
        tmp1.sign=OtherObject.Num.sign;
        tmp1.length=(int)Tmp_for.length();//creating an  integer object to multiply
        string Ans=tmp1.mul(To_multiply);
        tmp1.a=Ans;
        MyInteger tmp2;
        tmp2.a=tmp.Num.a;
        tmp2.sign=tmp.Num.sign;
        tmp2.length=(int)tmp.Num.a.length();
        tmp1=tmp1+tmp2;//adding from the integer class
        MyRational Ret_Ans;
        Ret_Ans.Num.a=tmp1.a;
        Ret_Ans.Den=tmp.Den;
        Ret_Ans.Num.sign=tmp1.sign;
        return Ret_Ans;
    }
    else{   //equilising the denominators
        Len_to_multiply=OtherObject.Den.a.length()-tmp.Den.a.length();
        string Tmp_for=tmp.Num.a;
        string To_multiply;
        To_multiply.clear();
        To_multiply.pb('1');
        MyInteger tmp1;
        for(ll i=1;i<=Len_to_multiply;i++){
            To_multiply.pb('0');
        }
        // cout<<To_multiply<<endl;
        tmp1.a=Tmp_for;//Numerator of the smaller den
        tmp1.sign=tmp.Num.sign;
        tmp1.length=(int)Tmp_for.length();//creating an  integer object to multiply
        string Ans=tmp1.mul(To_multiply);
        tmp1.a=Ans;
        MyInteger tmp2;
        tmp2.a=OtherObject.Num.a;
        tmp2.sign=OtherObject.Num.sign;
        tmp2.length=(int)OtherObject.Num.a.length();
        tmp1=tmp1+tmp2;//adding with den equal
        MyRational Ret_Ans;
        Ret_Ans.Num.a.clear();Ret_Ans.Den.a.clear();
        Ret_Ans.Num.a=tmp1.a;
        Ret_Ans.Den=OtherObject.Den;
        Ret_Ans.Num.sign=tmp1.sign;
        return Ret_Ans;
    }
}
MyRational MyRational::operator-(const MyRational &OtherObject){
    MyRational tmp=*this;
    MyRational tmp1=OtherObject;
    if(tmp1.Num.sign=='-')tmp1.Num.sign='+';
    else tmp1.Num.sign='-';
    MyRational Ans=tmp+tmp1;//using addition in subtration
    return Ans;
}
MyRational MyRational::operator*(const MyRational &OtherObject){
    MyRational tmp=*this;
    MyRational tmp1=OtherObject;
    MyRational Ans;
    MyInteger A1,A2;
    A1.a=tmp.Num.a;        //creating instance of MyInteger object and then using the overloaded operator *
    A1.sign=tmp.Num.sign;
    A1.length=(int)tmp.Num.a.length();
    A2.a=tmp1.Num.a;
    A2.sign=tmp1.Num.sign;
    A2.length=(int)tmp1.Num.a.length();
    A1=A1*A2;
    Ans.Num.a=A1.a;
    Ans.Num.sign=A1.sign;
    A1.a=tmp.Den.a;
    A1.sign=tmp.Num.sign;
    A1.length=(int)tmp.Den.a.length();
    A2.a=tmp1.Den.a;
    A2.sign=tmp1.Num.sign;
    A2.length=(int)tmp1.Den.a.length();//lenght of the resulting denominator
    A1=A1*A2;
    Ans.Den.a=A1.a;
    return  Ans;
}
bool MyRational::operator<(const MyRational &OtherObject){
    MyRational tmp=*this;
    MyRational tmp1=OtherObject;
    if(tmp.Den.a.length()>tmp1.Den.a.length()){
        ll Len_to_multiply=tmp.Den.a.length()-tmp1.Den.a.length();//equilising the denomiators
        string Mul;
        Mul.pb('1');
        for(ll i=1;i<=Len_to_multiply;i++){
            Mul.pb('0');
        }
        MyInteger Atmp;
        Atmp.a=tmp1.Num.a;
        Atmp.sign=tmp1.Num.sign;
        Atmp.length=(int)tmp1.Num.a.length();
        Atmp=Atmp.mul(Mul);
        tmp1.Num.a=Atmp.a;
    }
    else{
        ll Len_to_multiply=tmp1.Den.a.length()-tmp.Den.a.length();
        string Mul;
        Mul.pb('1');
        for(ll i=1;i<=Len_to_multiply;i++){
            Mul.pb('0');
        }
        MyInteger Atmp;
        Atmp.a=tmp.Num.a;
        Atmp.sign=tmp.Num.sign;
        Atmp.length=(int)tmp.Num.a.length();
        Atmp=Atmp.mul(Mul);
        tmp.Num.a=Atmp.a;
    }
    MyInteger C1,C2;
    C1.a=tmp.Num.a;
    C1.sign=tmp.Num.sign;
    C1.length=(int)tmp.Num.a.length();
    C2.a=tmp1.Num.a;
    C2.sign=tmp1.Num.sign;
    C2.length=(int)tmp1.Num.a.length();//comparing by creating MyInteger object
    if(C1<C2)return true;
    else return false;
}
bool MyRational::operator>(const MyRational &OtherObject){//same as above operator equalising first and then comparing using integer objects
    MyRational tmp=*this;
    MyRational tmp1=OtherObject;
    if(tmp.Den.a.length()>tmp1.Den.a.length()){
        ll Len_to_multiply=tmp.Den.a.length()-tmp1.Den.a.length();
        string Mul;
        Mul.pb('1');
        for(ll i=1;i<=Len_to_multiply;i++){
            Mul.pb('0');
        }
        MyInteger Atmp;
        Atmp.a=tmp1.Num.a;
        Atmp.sign=tmp1.Num.sign;
        Atmp.length=(int)tmp1.Num.a.length();
        Atmp=Atmp.mul(Mul);
        tmp1.Num.a=Atmp.a;
    }
    else{
        ll Len_to_multiply=tmp1.Den.a.length()-tmp.Den.a.length();
        string Mul;
        Mul.pb('1');
        for(ll i=1;i<=Len_to_multiply;i++){
            Mul.pb('0');
        }
        MyInteger Atmp;
        Atmp.a=tmp.Num.a;
        Atmp.sign=tmp.Num.sign;
        Atmp.length=(int)tmp.Num.a.length();
        Atmp=Atmp.mul(Mul);
        tmp.Num.a=Atmp.a;
    }
    MyInteger C1,C2;
    C1.a=tmp.Num.a;
    C1.sign=tmp.Num.sign;
    C1.length=(int)tmp.Num.a.length();
    C2.a=tmp1.Num.a;
    C2.sign=tmp1.Num.sign;
    C2.length=(int)tmp1.Num.a.length();
    if(C1>C2)return true;
    else return false;
}
bool MyRational::operator==(const MyRational &OtherObject){//same as above operator equalising first and then comparing using integer objects
    MyRational tmp=*this;
    MyRational tmp1=OtherObject;
    if(tmp.Den.a.length()>tmp1.Den.a.length()){
        ll Len_to_multiply=tmp.Den.a.length()-tmp1.Den.a.length();
        string Mul;
        Mul.pb('1');
        for(ll i=1;i<=Len_to_multiply;i++){
            Mul.pb('0');
        }
        MyInteger Atmp;
        Atmp.a=tmp1.Num.a;
        Atmp.sign=tmp1.Num.sign;
        Atmp.length=(int)tmp1.Num.a.length();
        Atmp=Atmp.mul(Mul);
        tmp1.Num.a=Atmp.a;
    }
    else{
        ll Len_to_multiply=tmp1.Den.a.length()-tmp.Den.a.length();
        string Mul;
        Mul.pb('1');
        for(ll i=1;i<=Len_to_multiply;i++){
            Mul.pb('0');
        }
        MyInteger Atmp;
        Atmp.a=tmp.Num.a;
        Atmp.sign=tmp.Num.sign;
        Atmp.length=(int)tmp.Num.a.length();
        Atmp=Atmp.mul(Mul);
        tmp.Num.a=Atmp.a;
    }
    MyInteger C1,C2;
    C1.a=tmp.Num.a;
    C1.sign=tmp.Num.sign;
    C1.length=(int)tmp.Num.a.length();
    C2.a=tmp1.Num.a;
    C2.sign=tmp1.Num.sign;
    C2.length=(int)tmp1.Num.a.length();
    if(C1==C2)return true;
    else return false;
    
}
bool MyRational::operator!=(const MyRational &OtherObject){//same as above operator equalising first and then comparing using integer objects
    MyRational tmp=*this;
    MyRational tmp1=OtherObject;
    if(tmp.Den.a.length()>tmp1.Den.a.length()){
        ll Len_to_multiply=tmp.Den.a.length()-tmp1.Den.a.length();
        string Mul;
        Mul.pb('1');
        for(ll i=1;i<=Len_to_multiply;i++){
            Mul.pb('0');
        }
        MyInteger Atmp;
        Atmp.a=tmp1.Num.a;
        Atmp.sign=tmp1.Num.sign;
        Atmp.length=(int)tmp1.Num.a.length();
        Atmp=Atmp.mul(Mul);
        tmp1.Num.a=Atmp.a;
    }
    else{
        ll Len_to_multiply=tmp1.Den.a.length()-tmp.Den.a.length();
        string Mul;
        Mul.pb('1');
        for(ll i=1;i<=Len_to_multiply;i++){
            Mul.pb('0');
        }
        MyInteger Atmp;
        Atmp.a=tmp.Num.a;
        Atmp.sign=tmp.Num.sign;
        Atmp.length=(int)tmp.Num.a.length();
        Atmp=Atmp.mul(Mul);
        tmp.Num.a=Atmp.a;
    }
    MyInteger C1,C2;
    C1.a=tmp.Num.a;
    C1.sign=tmp.Num.sign;
    C1.length=(int)tmp.Num.a.length();
    C2.a=tmp1.Num.a;
    C2.sign=tmp1.Num.sign;
    C2.length=(int)tmp1.Num.a.length();
    if(C1!=C2)return true;
    else return false;
    
}
bool MyRational::operator<=(const MyRational &OtherObject){//same as above operator equalising first and then comparing using integer objects
    MyRational tmp=*this;
    MyRational tmp1=OtherObject;
    if(tmp.Den.a.length()>tmp1.Den.a.length()){
        ll Len_to_multiply=tmp.Den.a.length()-tmp1.Den.a.length();
        string Mul;
        Mul.pb('1');
        for(ll i=1;i<=Len_to_multiply;i++){
            Mul.pb('0');
        }
        MyInteger Atmp;
        Atmp.a=tmp1.Num.a;
        Atmp.sign=tmp1.Num.sign;
        Atmp.length=(int)tmp1.Num.a.length();
        Atmp=Atmp.mul(Mul);
        tmp1.Num.a=Atmp.a;
    }
    else{
        ll Len_to_multiply=tmp1.Den.a.length()-tmp.Den.a.length();
        string Mul;
        Mul.pb('1');
        for(ll i=1;i<=Len_to_multiply;i++){
            Mul.pb('0');
        }
        MyInteger Atmp;
        Atmp.a=tmp.Num.a;
        Atmp.sign=tmp.Num.sign;
        Atmp.length=(int)tmp.Num.a.length();
        Atmp=Atmp.mul(Mul);
        tmp.Num.a=Atmp.a;
    }
    MyInteger C1,C2;
    C1.a=tmp.Num.a;
    C1.sign=tmp.Num.sign;
    C1.length=(int)tmp.Num.a.length();
    C2.a=tmp1.Num.a;
    C2.sign=tmp1.Num.sign;
    C2.length=(int)tmp1.Num.a.length();
    if(C1<=C2)return true;
    else return false;
    
}
bool MyRational::operator>=(const MyRational &OtherObject){//same as above operator equalising first and then comparing using integer objects
    MyRational tmp=*this;
    MyRational tmp1=OtherObject;
    if(tmp.Den.a.length()>tmp1.Den.a.length()){
        ll Len_to_multiply=tmp.Den.a.length()-tmp1.Den.a.length();
        string Mul;
        Mul.pb('1');
        for(ll i=1;i<=Len_to_multiply;i++){
            Mul.pb('0');
        }
        MyInteger Atmp;
        Atmp.a=tmp1.Num.a;
        Atmp.sign=tmp1.Num.sign;
        Atmp.length=(int)tmp1.Num.a.length();
        Atmp=Atmp.mul(Mul);
        tmp1.Num.a=Atmp.a;
    }
    else{
        ll Len_to_multiply=tmp1.Den.a.length()-tmp.Den.a.length();
        string Mul;
        Mul.pb('1');
        for(ll i=1;i<=Len_to_multiply;i++){
            Mul.pb('0');
        }
        MyInteger Atmp;
        Atmp.a=tmp.Num.a;
        Atmp.sign=tmp.Num.sign;
        Atmp.length=(int)tmp.Num.a.length();
        Atmp=Atmp.mul(Mul);
        tmp.Num.a=Atmp.a;
    }
    MyInteger C1,C2;
    C1.a=tmp.Num.a;
    C1.sign=tmp.Num.sign;
    C1.length=(int)tmp.Num.a.length();
    C2.a=tmp1.Num.a;
    C2.sign=tmp1.Num.sign;
    C2.length=(int)tmp1.Num.a.length();
    if(C1>=C2)return true;
    else return false;
    
}
MyRational MyRational::operator++(){//increment operator done by adding one
    MyRational tmp=*this;
    MyRational One;
    One.Num.a=tmp.Den.a;
    One.Den.a=tmp.Den.a;
    tmp=tmp+One;
    return tmp;
}
MyRational MyRational::operator--(){//decrement operator done by subtracting one
    MyRational tmp=*this;
    MyRational One;
    One.Num.a=tmp.Den.a;
    One.Den.a=tmp.Den.a;
    tmp=tmp-One;
    return tmp;
}
/**/
MyRational MyRational::operator/(const MyRational &OtherObject){
    MyRational tmp=*this;
    MyRational tmp1=OtherObject;
    string Use=tmp1.Num.a;
    string UseNum=tmp.Num.a;
    int FlagDen=0;
    for(int i=0;i<Use.size();i++){
        if(Use[i]!='0'){
            FlagDen=1;
            break;
        }
    }
    int FlagNum=0;
    for(int i=0;i<UseNum.size();i++){
        if(UseNum[i]!='0'){
            FlagNum=1;
            break;
        }
    }
    if(FlagDen==0&&FlagNum==0){
        cout<<"Undefined Value 0/0\n";//checking for zeroe/ zero format
        return *this;
    }
    // cout<<FlagNum<<" "<<FlagDen<<endl;
    if(FlagDen==0&&FlagNum==1){
        cout<<"Division by zero\n";//checking for a/0
        return *this;
    }
    MyInteger Another,Another1;
    string Div1,Div2;
    Another.a=tmp.Num.a;
    Another.sign=tmp.Num.sign;
    Another.length=(int)tmp.Num.a.length();
    string _tmp=tmp1.Den.a;
    _tmp=Another.mul(_tmp);
    Another.a=_tmp;
    string _tmp1=tmp1.Num.a;
    Another1.a=_tmp1;
    Another.sign=tmp1.Num.sign;
    Another.length=(int)tmp1.Num.a.length();
    string Offset;
    Offset.pb('1');
    int Extra_zero=0;
    Extra_zero+=(tmp.Den.a.length()+tmp1.Num.a.length()-tmp.Num.a.length()-tmp1.Den.a.length());
    Extra_zero+=25;//first equalising the num and den and then multiplyiing by pow(10,25)  for very good precision
    for(int i=1;i<=Extra_zero;i++){
        Offset.pb('0');
    }
    _tmp=Another.mul(Offset);
    Another.a=_tmp;
    MyInteger Divide;
    Divide=Another/Another1;
    MyRational Final;
    Final.Num.a=Divide.a;
    Final.Num.sign=Divide.sign;
    int Total_zero=0;
    Total_zero=(Extra_zero+(int)tmp.Den.a.length()-1);
    Final.Den.a.clear();//final den
    Final.Den.a.pb('1');
    for(int i=1;i<=Total_zero;i++){
        Final.Den.a.pb('0');
    }
    return Final;
}
MyRational MyRational::pow(MyInteger n){//done by using the pow function in MyInteger
    string Check_for;
    Check_for.pb('0');
    MyRational tmp=*this;
    string A11=tmp.Num.a;
    int Flag_=0;
    for(int i=0;i<A11.size();i++){
        if(A11[i]!='0'){
            Flag_=1;
            break;
        }
    }
    if(Flag_==0){
        if(n.sign=='-'){
            cout<<"Division By Zero\n";//checking for a /zero format
            return *this;
        }
        if(n.a==Check_for){
            cout<<"Undefined  value\n"; //checking for zero /zero format
            return *this;
        }
    }
    MyInteger Another,Another1;
    Another.a=tmp.Num.a;
    Another.sign=tmp.Num.sign;
    Another.length=(int)tmp.Num.a.length();
    MyInteger Pow_in_int_Num;
    MyInteger for_n=n;
    for_n.sign='+';
    Pow_in_int_Num=Another.pow(for_n);     //power of numerator
    Another1.a=tmp.Den.a;
    Another1.sign='+';
    Another1.length=(int)tmp.Den.a.length();
    MyInteger Pow_in_int_Den;
    Pow_in_int_Den=Another1.pow(for_n);    //power of den
    MyRational Final;
    Final.Num.a=Pow_in_int_Num.a;
    Final.Num.sign=Pow_in_int_Num.sign;
    Final.Den.a=Pow_in_int_Den.a;
    MyRational f1("1.000000000000000000000000");//dividing by one to keep good precision
    if(n.sign=='-')
        Final=f1/Final;
    return Final;
    /* f1.Num.a=Pow_in_int_Den.a;
     f1.Num.sign='+';
     f1.Den.a.clear();
     f1.Den.a.pb('1');
     f2.Num.a=Pow_in_int_Num.a;
     f2.Num.sign=Pow_in_int_Num.sign;
     f2.Den.a.clear();
     f2.Den.a.pb('1');
     //   cout<<f2.Num.a.length()<<endl;
     //     cout<<f2;
     Final=f1/f2;
     //   cout<<Final.Num.a<<endl;
     //   cout<<Final.Den.a<<endl;*/
    return Final;
}
ostream & operator<<(ostream &output, const MyRational &OtherObject){
    MyRational tmp1=OtherObject;
    tmp1.Num.a=tmp1.Remove_Front(tmp1.Num.a);
    if(tmp1.Num.a.length()==1&&tmp1.Num.a[0]=='0'){
        output << tmp1.Num.a;
    }
    else{//in this we have to round upto 20 decimal places
        if(tmp1.Num.sign=='-')cout<<"-";
        int l1=(int)tmp1.Num.a.length();
        int l2=(int)tmp1.Den.a.length();
        //   cout<<l1<<" "<<l2<<endl;
        string Main;
        for(int i=1;i<=l2-l1;i++){//putting zeroes at the starting
            Main.pb('0');
        }
        for(int i=0;i<l1;i++){
            Main.pb(tmp1.Num.a[i]);//,main string
        }
        string to_be_printed;
        string Rounded_one;
        int Point_to_be_at=(int)Main.size()-(l2-1);
        for(int i=0;i<Main.size();i++){
            if((i)==Point_to_be_at){
                to_be_printed.pb('.');
            }
            to_be_printed.pb(Main[i]);
            //to_be_printed is the string that stores the actual answer with very highj precision
        }
        //   output<<to_be_printed<<endl;
        for(int i=0;i<Point_to_be_at;i++){
            Rounded_one.pb(to_be_printed[i]);
        }
        Rounded_one.pb('.');
        int how_many_after=0;int i;
        for (i=Point_to_be_at+1;i<to_be_printed.size();i++){
            if(how_many_after==20)break;
            Rounded_one.pb(to_be_printed[i]);
            how_many_after++;
        }
        if(how_many_after==0)Rounded_one.pop_back();
        
        int digit_21 =to_be_printed[i]-48;
        if(digit_21>5){  //if last digit is greater than five round it off
            MyRational t1(Rounded_one);
            MyRational t2;
            t2.Num.a.clear();t2.Den.a.clear();
            t2.Num.a.pb('1');
            t2.Num.sign='+';//creating an object of Myrational class
            t2.Den.sign='+';
            t2.Den.a.pb('1');
            for(int i=1;i<=20;i++){
                t2.Den.a.pb('0');
            }
            t1=t1+t2;  // below are many case handling for printing
            int l1=(int)t1.Num.a.length();
            int l2=(int)t1.Den.a.length();
            string _temp1;
            if((l2-1)>l1){
                for(int i=1;i<=l2-1-l1;i++){
                    _temp1.pb('0');
                }
            }
            for(int i=0;i<t1.Num.a.length();i++){
                _temp1.pb(t1.Num.a[i]);
            }
            t1.Num.a=_temp1;
            //    output << t1.Num.a<<endl;
            l1=(int)t1.Num.a.length();
            Rounded_one.clear();
            for(int i=0;i<l1-20;i++){
                Rounded_one.pb(t1.Num.a[i]);
            }
            Rounded_one.pb('.');
            for(int i=l1-20;i<=l1-1;i++){
                Rounded_one.pb(t1.Num.a[i]);
            }
            //      output << Rounded_one <<endl;
            if(Rounded_one[0]=='.'){
                cout<<"0";
            }
            /*int Len=(int)Rounded_one.size()-1;
             while(Rounded_one[Len]=='0'){
             Rounded_one.pop_back();
             Len--;
             }
             if(Rounded_one[Len]=='.')Rounded_one.pop_back();*/
            output << Rounded_one;
        }
        else{
            /*  int Len=(int)Rounded_one.size()-1;
             while(Rounded_one[Len]=='0'){
             Rounded_one.pop_back();
             Len--;
             }
             if(Rounded_one[Len]=='.')Rounded_one.pop_back();*/
            output << Rounded_one;
        }
    }
    return output;
}
MyRational MyRational::create(MyInteger AnsI){
    MyRational temp=*this;
    temp.Num.a.clear();
    temp.Den.a.clear();
    temp.Num.sign=AnsI.sign;
    temp.Den.sign='+';
    temp.Num.a=AnsI.a;
    temp.Den.a.pb('1');
    return temp;
}
//All the file are in codeforces Practice and then POPL Assingment
int main(){
    
    string str,prev1;
    cin>>str;
    prev1=str;
    string Opert;
    MyRational AnsR(str);
    MyInteger AnsI(str);
    int flag=0;
    if(str.find('.')!=string::npos){
        flag=1;
    }
    while(1){
        cin>>Opert;
        if(Opert[0]=='$'&&Opert.length()==1)break;
        cin>>str;
        if(!flag){
            if(str.find('.')==string::npos){
                MyInteger tmp(str);
                if(Opert[0]=='+'){
                    AnsI=AnsI +tmp;
                }
                if(Opert[0]=='-'){
                    AnsI=AnsI - tmp;
                }
                if(Opert[0]=='*'){
                    AnsI=AnsI * tmp;
                }
                if(Opert[0]=='/'){
                    AnsI=(AnsI/tmp);
                }
                if(Opert[0]=='p'){
                    MyInteger tmp1(str);
                    if(tmp1.a[0]=='1'&& tmp1.a.length()==1&&AnsI.a.length()==1&&AnsI.a[0]=='1'){
                        AnsI=AnsI;
                    }
                    else
                        AnsI=AnsI.pow(tmp1);
                }
                if(Opert[0]=='%'){
                    AnsI=AnsI%tmp;
                }
                cout<<AnsI<<endl;
            }
            else{
                MyRational temp;
                temp=temp.create(AnsI);
                AnsR=temp;
                MyRational tmp(str);
                if(Opert[0]=='+'){
                    AnsR=AnsR + tmp;
                }
                if(Opert[0]=='-'){
                    AnsR=AnsR - tmp;
                }
                if(Opert[0]=='*'){
                    AnsR=AnsR * tmp;
                }
                if(Opert[0]=='/'){
                    AnsR=(AnsR/tmp);
                }
                if(Opert[0]=='p'){
                    MyInteger tmp1(str);
                    AnsR=AnsR.pow(tmp1);
                }
                cout<<AnsR<<endl;
                flag=1;
            }
        }
        else{
            MyRational tmp(str);
            if(Opert[0]=='+'){
                AnsR=AnsR + tmp;
            }
            if(Opert[0]=='-'){
                AnsR=AnsR - tmp;
            }
            if(Opert[0]=='*'){
                AnsR=AnsR * tmp;
            }
            if(Opert[0]=='/'){
                AnsR=(AnsR/tmp);
            }
            if(Opert[0]=='p'){
                MyInteger tmp1(str);
                AnsR=AnsR.pow(tmp1);
            }
            cout<<AnsR<<endl;
        }
    }
    
    return 0;
    
}
//-12851297100041381259230001083145073473169563614556209878104709553048286810540435034262678289.83541892081629051880

//45345.3424234666
