//
//  main.cpp
//  PoplAssingment
//

#include<stdio.h>
#include "MyInteger.h"
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
MyInteger zerop("0");     //definations for some constants
MyInteger zeron("-0");
MyInteger one("1");
MyInteger two("2");
MyInteger ::MyInteger(){   //default constructor
    a.push_back('0');
    length=1;
    sign='+';
}
MyInteger ::~MyInteger(){
    a.clear();
    length=0;
    sign='+';
}
MyInteger ::MyInteger(string s){   ///constructor for  passing strings
    if(s[0]=='-'){      //checking for sign
        sign='-';
        a=s.substr(1,s.length());
        length=(int)s.length()-1;
    }
    else{
        length=(int)s.length();
        sign='+';
        a=s;
    }
}
MyInteger  MyInteger ::parse(string s){ //parsing string
    MyInteger Object=MyInteger(s);
    return Object;
}
MyInteger MyInteger ::abs(MyInteger n){//just changing the sign
    MyInteger Object=MyInteger(n.a);
    Object.sign='+';
    return Object;
}
string MyInteger ::add(string s2){
    string A1=a;
    string A2=s2;
    int Max=(int)max(A1.length(),A2.length());
    char tmp1[Max+3];    //temp_array for addition
    char tmp2[Max+3];
    char Ans[Max+3];
    fill(tmp1,'0'); fill(tmp2,'0'); fill(Ans,'0');//initialising values to zeroes
    int Tmpsize=Max+1;
    int k=(int)A1.length()-1;
    for(int i=Tmpsize;i>=Tmpsize-A1.length()+1;i--){
        tmp1[i]=A1[k];
        k--;
    }
    k=(int)A2.length()-1;
    for(int i=Tmpsize;i>=Tmpsize-A2.length()+1;i--){
        tmp2[i]=A2[k];
        k--;
    }
    int Last=min(Tmpsize-(int)A1.length()+1,Tmpsize-(int)A2.length()+1);
    int carry=0;
    int Finalsize=0;
    for(int i=Tmpsize;i>=Last;i--){
        int t1=tmp1[i]+tmp2[i]+carry-96;//adding with carry
        Ans[i]=t1%10+48;
        carry=t1/10;
        Finalsize=i;
    }
    if(carry>0){
        Finalsize--;
        Ans[Finalsize]=carry+48;
    }
    string Final;
    int Nonzero=0;
    f(i,0,Tmpsize+1){
        if(Ans[i]>48){Nonzero=i;break;}//checking for zeroes and removing them
    }
    f(i,Nonzero,Tmpsize+1){
        Final.push_back(Ans[i]);
    }
    return Final;
}
string MyInteger ::sub(string s2){  //same as addition
    string A1=a;
    string A2=s2;
    int Max=(int)max(A1.length(),A2.length());
    char tmp1[Max+3];
    char tmp2[Max+3];
    char Ans[Max+3];
    fill(tmp1,'0'); fill(tmp2,'0'); fill(Ans,'0');
    int Tmpsize=Max+1;
    if(A2.length()>A1.length()){
        string temp=A2;
        A2=A1;
        A1=temp;
    }
    else if(A2.length()==A1.length()){//checking which one is greater
        int flag=0;
        for(int i=0;i<A1.length();i++){
            if(A2[i]>A1[i]){
                flag=1;
                break;
            }
            if(A2[i]<A1[i]){
                flag=0;
                break;
            }
        }
        if(flag){
            string temp=A2;
            A2=A1;
            A1=temp;
        }
    }
    int k=(int)A1.length()-1;
    for(int i=Tmpsize;i>=Tmpsize-A1.length()+1;i--){
        tmp1[i]=A1[k];   //copying into other array
        k--;
    }
    k=(int)A2.length()-1;
    for(int i=Tmpsize;i>=Tmpsize-A2.length()+1;i--){
        tmp2[i]=A2[k];   //copying into other array
        k--;
    }
    int Last=min(Tmpsize-(int)A1.length()+1,Tmpsize-(int)A2.length()+1);
    int carry=0;//initialising carry
    for(int i=Tmpsize;i>=Last;i--){
        int t1=tmp1[i]-tmp2[i]+carry;
        if(t1<0){    //if less than zero add 10 and make carry =-1
            t1+=10;
            carry=-1;
        }
        else{
            carry=0;
        }
        Ans[i]=t1+48;
    }
    string Final;
    int Nonzero=-1;
    f(i,0,Tmpsize+1){
        if(Ans[i]>48){Nonzero=i;break;}  //checking for zeroes and removing them
    }
    if(Nonzero==-1)Final.push_back('0');
    else{
        f(i,Nonzero,Tmpsize+1){
            Final.push_back(Ans[i]);
        }
    }
    return Final;
}
MyInteger MyInteger::operator+(const MyInteger &OtherObject){
    MyInteger tmp=*this;
    MyInteger tmp1;
    if(tmp.sign=='+'&&OtherObject.sign=='+'){ //checking the sign and then assinging the sign
        tmp1.sign='+';
        string str=tmp.add(OtherObject.a);
        tmp1.a=str;
        tmp1.length=(int)str.length();
        return tmp1;
    }
    else if(tmp.sign=='-' and  OtherObject.sign=='-'){//if both negative then sign is negative
        tmp1.sign='-';
        string str=tmp.add(OtherObject.a);
        tmp1.a=str;
        tmp1.length=(int)str.length();
        return tmp1;
    }
    else if(tmp.sign=='+'&& OtherObject.sign=='-'){
        if(tmp.a.length()>OtherObject.a.length()){
            tmp1.sign='+';
        }
        else if(tmp.a.length()<OtherObject.a.length()){
            tmp1.sign='-';
        }
        else if(OtherObject.a.length()==tmp.a.length()){
            int flag=0;
            for(int i=0;i<tmp.a.length();i++){
                if(OtherObject.a[i]>tmp.a[i]){
                    flag=1;
                    break;
                }
                if(OtherObject.a[i]<tmp.a[i]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                tmp1.sign='-';
            }
            else tmp1.sign='+';
        }
        string str=tmp.sub(OtherObject.a);
        tmp1.a=str;
        tmp1.length=(int)str.length();
        return tmp1;
    }
    else {
        if(tmp.a.length()>OtherObject.a.length()){
            tmp1.sign='-';
        }
        else if(tmp.a.length()<OtherObject.a.length()){
            tmp1.sign='+';
        }
        else if(OtherObject.a.length()==tmp.a.length()){
            int flag=0;
            for(int i=0;i<tmp.a.length();i++){
                if(OtherObject.a[i]>tmp.a[i]){
                    flag=1;
                    break;
                }
                if(OtherObject.a[i]<tmp.a[i]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                tmp1.sign='+';
            }
            else tmp1.sign='-';
        }
        string str=tmp.sub(OtherObject.a);
        tmp1.a=str;
        tmp1.length=(int)str.length();
        return tmp1;
    }
}
MyInteger MyInteger::operator-(const MyInteger &OtherObject){//same as addition and then taking care of the sign
    MyInteger tmp=*this;
    MyInteger tmp1;
    if(tmp.sign=='+'&&OtherObject.sign=='-'){
        tmp1.sign='+';
        string str=tmp.add(OtherObject.a);
        tmp1.a=str;
        tmp1.length=(int)str.length();
        return tmp1;
    }
    else if(tmp.sign=='-'&&OtherObject.sign=='+'){
        tmp1.sign='-';
        string str=tmp.add(OtherObject.a);
        tmp1.a=str;
        tmp1.length=(int)str.length();
        return tmp1;
    }
    else if(tmp.sign=='+'&&OtherObject.sign=='+'){
        if(tmp.a.length()>OtherObject.a.length()){
            tmp1.sign='+';
        }
        else if(tmp.a.length()<OtherObject.a.length()){
            tmp1.sign='-';
        }
        else if(OtherObject.a.length()==tmp.a.length()){
            int flag=0;
            for(int i=0;i<tmp.a.length();i++){
                if(OtherObject.a[i]>tmp.a[i]){
                    flag=1;
                    break;
                }
                if(OtherObject.a[i]<tmp.a[i]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                tmp1.sign='-';
            }
            else tmp1.sign='+';
        }
        string str=tmp.sub(OtherObject.a);
        tmp1.a=str;
        tmp1.length=(int)str.length();
        return tmp1;
    }
    else {
        if(tmp.a.length()>OtherObject.a.length()){
            tmp1.sign='-';
        }
        else if(tmp.a.length()<OtherObject.a.length()){
            tmp1.sign='+';
        }
        else if(OtherObject.a.length()==tmp.a.length()){
            int flag=0;
            for(int i=0;i<tmp.a.length();i++){
                if(OtherObject.a[i]>tmp.a[i]){
                    flag=1;
                    break;
                }
                if(OtherObject.a[i]<tmp.a[i]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                tmp1.sign='+';
            }
            else tmp1.sign='-';
        }
        string str=tmp.sub(OtherObject.a);
        tmp1.a=str;
        tmp1.length=(int)str.length();
        return tmp1;
    }
}
bool MyInteger::stringCompare(string s1, string s2){//comparing strings
    string Check_for_zero=s1;
    string Check_for_zero1=s2;
    int i;
    for(i=0;i<Check_for_zero.length();i++){//removing front zeroes
        if(Check_for_zero[i]>'0')break;
    }
    s1.clear();
    for(int j=i;j<Check_for_zero.size();j++){//removing front zeroes
        s1.push_back(Check_for_zero[j]);
    }
    for(i=0;i<Check_for_zero1.length();i++){//removing front zeroes
        if(Check_for_zero1[i]>'0')break;
    }
    s2.clear();
    for(int j=i;j<Check_for_zero1.size();j++){
        s2.push_back(Check_for_zero1[j]);
    }
    
    if(s1.length()>s2.length())return true;  //checking the length
    else if(s1.length()<s2.length())return false;
    else {
        for(int i=0;i<(int)s1.length();i++){
            if(s1[i]>s2[i]){
                return true;
            }
            else if(s1[i]<s2[i])return false;
        }
        return true;
    }
}
bool MyInteger::operator<(const MyInteger &OtherObject){
    MyInteger tmp=*this;
    if(this->a==OtherObject.a){
        if(this->sign=='+'&&OtherObject.sign=='-')return false;//if sign are different
        if(this->sign=='-'&&OtherObject.sign=='+') return true;
        return false;
    }
    else{
        if(this->sign=='+'&&OtherObject.sign=='-'){
            return false;//if one is positive and other is negative
        }
        else if(this->sign=='-'&&OtherObject.sign=='+'){//same as above
            return true;
        }
        else if(this->sign=='-'&&OtherObject.sign=='-'){
            if(stringCompare(this->a, OtherObject.a)){
                return true;
            }
            else return false;
        }
        else if(this->sign=='+'&&OtherObject.sign=='+'){
            if(stringCompare(this->a, OtherObject.a)){
                return false;
            }
            else return true;
        }
    }
    return false;
}
bool MyInteger::operator>(const MyInteger &OtherObject){//used the above operator
    MyInteger tmp=*this;
    if(this->a==OtherObject.a){
        if(this->sign=='+'&&OtherObject.sign=='-')return true;
        if(this->sign=='-'&&OtherObject.sign=='+') return false;
        return false;
    }
    else{
        if(this->sign=='+'&&OtherObject.sign=='-'){
            return true;
        }
        else if(this->sign=='-'&&OtherObject.sign=='+'){
            return false;
        }
        else if(this->sign=='-'&&OtherObject.sign=='-'){
            if(stringCompare(this->a, OtherObject.a)){
                return false;
            }
            else return true;
        }
        else if(this->sign=='+'&&OtherObject.sign=='+'){
            if(stringCompare(this->a, OtherObject.a)){
                return true;
            }
            else return false;
        }
    }
    return true;
}
bool MyInteger::operator==(const MyInteger &OtherObject){//used the above operator
    MyInteger tmp=*this;
    if(this->a==OtherObject.a&&OtherObject.sign==this->sign){
        return true;
    }
    return false;
}
bool MyInteger::operator!=(const MyInteger &OtherObject){//used the above operator
    MyInteger tmp=*this;
    if(this->a==OtherObject.a&&OtherObject.sign==this->sign){
        return false;
    }
    return true;
}
bool MyInteger::operator<=(const MyInteger &OtherObject){//used the above operator
    MyInteger tmp=*this;
    if(this->a==OtherObject.a){
        if(this->sign=='+'&&OtherObject.sign=='-')return false;
        if(this->sign=='-'&&OtherObject.sign=='+') return true;
        return true;
    }                //just checking for equality with < operator
    else{
        if(this->sign=='+'&&OtherObject.sign=='-'){
            return false;
        }
        else if(this->sign=='-'&&OtherObject.sign=='+'){
            return true;
        }
        else if(this->sign=='-'&&OtherObject.sign=='-'){
            if(stringCompare(this->a, OtherObject.a)){
                return true;
            }
            else return false;
        }
        else if(this->sign=='+'&&OtherObject.sign=='+'){
            if(stringCompare(this->a, OtherObject.a)){
                return false;
            }
            else return true;
        }
    }
    return false;
}
bool MyInteger::operator>=(const MyInteger &OtherObject){
    MyInteger tmp=*this;
    if(this->a==OtherObject.a){
        if(this->sign=='+'&&OtherObject.sign=='-')return true;
        if(this->sign=='-'&&OtherObject.sign=='+') return false;
        return true;
    }                   //just checking for equality with > operator
    else{
        if(this->sign=='+'&&OtherObject.sign=='-'){
            return true;
        }
        else if(this->sign=='-'&&OtherObject.sign=='+'){
            return false;
        }
        else if(this->sign=='-'&&OtherObject.sign=='-'){
            if(stringCompare(this->a, OtherObject.a)){
                return false;
            }
            else return true;
        }
        else if(this->sign=='+'&&OtherObject.sign=='+'){
            if(stringCompare(this->a, OtherObject.a)){
                return true;
            }
            else return false;
        }
    }
    return true;
}
MyInteger MyInteger::operator++(){//increment the integer
    MyInteger tmp=*this;
    MyInteger tmp2;
    string tmp1;
    tmp1.push_back('1');//add one
    tmp2.a=tmp1;
    tmp2.length=1;
    tmp2.sign='+';
    tmp=tmp+tmp2;
    *this=tmp;
    return tmp;
}
MyInteger MyInteger::operator--(){//decrement the integer
    MyInteger tmp=*this;
    MyInteger tmp2;
    string tmp1;
    tmp1.push_back('1');//subtract by 1
    tmp2.a=tmp1;
    tmp2.length=1;
    tmp2.sign='-';
    tmp=tmp+tmp2;
    *this=tmp;
    return tmp;
}
string MyInteger::Remove_Front(string s){//removing the front zeroes
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
string MyInteger::mul(string s2){
    string s1=a;
    int Max=max((int)s1.length(),(int)s2.length());
    string ANS;
    MyInteger tmp;
    tmp.a=s1;
    tmp.sign='+';
    tmp.length=(int)s1.length();
    for(int j=(int)s2.length()-1;j>=0;j--){//multiplication by repeated addition
        if((s2[j]-48)==0)
            continue;
        string tmp2=s1;
        for(int k=1;k<=s2[j]-48-1;k++){
            tmp2=tmp.add(tmp2);
        }
        f(i,0,(int)s2.length()-j-1)tmp2.push_back('0');//pushing zeroes at the end for applying the concept of repeated addition
        MyInteger Temp;
        Temp.a=tmp2;
        Temp.sign='+';
        Temp.length=(int)tmp2.length();
        if(j==Max-1){
            ANS=Temp.a;
        }
        else
            ANS=Temp.add(ANS);
    }
    ANS=Remove_Front(ANS);
    //   cout<<ANS<<endl;
    return ANS;
}
MyInteger MyInteger::operator*(const MyInteger &OtherObject){
    MyInteger tmp=*this;
    MyInteger tmp1;
    if(this->sign==OtherObject.sign){//using the above function and overloading it
        tmp1.sign='+';
    }
    else {
        tmp1.sign='-';
    }
    string s1=this->a;
    string s2=OtherObject.a;
    string Mul;
    Mul=tmp.mul(OtherObject.a);
    tmp1.a=Mul;
    tmp1.length=(int)Mul.length();
    return tmp1;
}
string MyInteger::div(string s2){
    MyInteger tmp=*this;
    MyInteger tmp1,Res;
    tmp1.a=s2;
    tmp1.sign='+';
    tmp.sign='+';//for handling negative number so that < operator works
    tmp1.length=(int)s2.length();
    if(tmp<tmp1){
        Res.a='0';
        Res.sign='+';
        Res.length=1;
        return Res.a;
    }
    else{
        string s1=tmp.a;
        string Temporary,Quotient;
        int i=0;
        while(i<s1.length()){
            Temporary.push_back(s1[i]);
            if(stringCompare(Temporary, s2)){//comparing the string if greater then subtract and push a number in the quotient
                string Another=Temporary;int k=0;
                MyInteger Divide;
                Divide.a=Temporary;
                Divide.sign='+';
                Divide.length=(int)Temporary.length();
                while(1){
                    if(stringCompare(Another, s2)){
                        Another=Divide.sub(s2);
                        Divide.a=Another;
                        Divide.length=(int)Another.length();
                        k++;
                    }
                    else break;
                }
                Quotient.push_back(k+48);
                Temporary.clear();int j;
                for( j=0;j<Another.size();j++){
                    if(Another[j]>'0'){
                        break;
                    }
                }
                for(int m=j;m<Another.size();m++){
                    Temporary.push_back(Another[m]);
                }
            }
            else{
                Quotient.push_back('0');//push zeroes at the quotient
            }
            i++;
        }
        string Check_for_zero=Quotient;
        Quotient.clear();
        for( i=0;i<Check_for_zero.size();i++){
            if(Check_for_zero[i]>'0')break;//  removing zeroes
        }
        for(int j=i;j<Check_for_zero.size();j++){
            Quotient.push_back(Check_for_zero[j]);
        }
        return Quotient;
    }
}
MyInteger MyInteger::operator%(const MyInteger &OtherObject){
    MyInteger tmp=*this;
    MyInteger tmp1=OtherObject;
    while(tmp.sign=='-'){  //checking for negative numbers if negative then add the  number until positive
        tmp=tmp+tmp1;
    }
    MyInteger Div;
    Div=tmp/tmp1;//  divide and then subtract ,a%b= (a/b) * b - a
    MyInteger Mul1;
    Mul1=tmp1*Div;
    MyInteger Ans=tmp-Mul1;
    Ans.sign='+';
    Ans.length=(int)Ans.a.length();
    return Ans.a;
}
MyInteger MyInteger::operator/(const MyInteger &OtherObject){
    MyInteger tmp=*this;
    MyInteger tmp1=OtherObject;
    string Use=tmp1.a;
    string UseNum=tmp.a;//using the divide function used in the
    //  cout<<Use<<" "<<UseNum<<endl;
    int FlagDen=0;
    for(int i=0;i<Use.size();i++){
        if(Use[i]!='0'){     //checking for zero
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
        cout<<"Undefined Value 0/0\n";//if 0/0 format
        return *this;
    }
    if(FlagDen==0&&FlagNum==1){
        cout<<"Division by zero\n";  //of the form a/0
        return *this;
    }
    if(this->sign==OtherObject.sign){
        tmp1.sign='+';
    }
    else {
        tmp1.sign='-';
    }
    string s1=this->a;
    string s2=OtherObject.a;
    string Mul;
    Mul=tmp.div(OtherObject.a);//using the divide function
    tmp1.a=Mul;
    tmp1.length=(int)Mul.length();
    return tmp1;
}
MyInteger MyInteger::Ppow(MyInteger n){//temporary power function
    MyInteger tmp=*this;
    string Check_for;
    Check_for.pb('0');
    if(tmp.a==Check_for && n.a==Check_for){
        cout<<"Undefined value\n";//checking for zero / zero
        return *this;
    }
    if(n.sign=='-'){
        if(tmp.a==Check_for){
            cout<<"Division By Zero\n"; // checking for a/0
            return *this;
        }
        tmp.a.clear();
        tmp.a.push_back('0');
        tmp.sign='+';
        tmp.length=1;
        return tmp;
    }
    else{
        string temp;temp.push_back('0');
        if(n.a==temp){      //base case for the power if(n==0)return 1;
            tmp.a.clear();
            tmp.a.push_back('1');
            tmp.length=1;
            tmp.sign='+';
            return tmp;
        }
        temp.clear();
        temp.push_back('1');//base case for 1 if(n==1) return temp only
        if(n.a==temp){
            return tmp;
        }
        else{
            MyInteger t1;
            string Original;
            Original=n.a;
            string s2;
            s2.push_back('2');
            t1.a=n.div(s2);
            t1.sign='+';
            t1.length=(int)t1.a.length();
            MyInteger tmp2;
            tmp2=tmp.Ppow(t1);     //return pow(n/2)*pow(n/2) if it is even
            string Temp=tmp2.a;
            string Res=tmp2.mul(Temp);
            tmp2.a=Res;
            tmp2.length=(int)tmp2.a.length();
            tmp2.sign='+';
            if(Original[Original.size()-1]%2==1){  //if the n last digit is odd the ans will pow(n/2)*pow(n/2)*temp
                tmp2.a=tmp2.mul(tmp.a);
                tmp2.length=(int)tmp2.a.length();
                tmp2.sign='+';
            }
            return tmp2;
        }
    }
}
MyInteger MyInteger::pow(MyInteger n){//main power calculating function
    MyInteger tmp=*this;
    MyInteger Result;
    Result=tmp.Ppow(n);
    if(tmp.sign=='-'){
        if(n.a[n.a.length()-1]%2==0){//if odd the if sign is negative
            Result.sign='+';
        }
        else Result.sign='-';
    }
    else{
        Result.sign='+';
    }
    return  Result;
}
MyInteger MyInteger ::operator << (const MyInteger &OtherObject){//left shift for
    MyInteger In_class=*this;
    MyInteger tmp("2");
    MyInteger tmp1=OtherObject;
    MyInteger Result;
    Result=tmp.Ppow(OtherObject);// gets multiplied by power of 2 raised to n
    Result=Result*In_class;
    return  Result;
}
MyInteger MyInteger ::operator >> (const MyInteger &OtherObject){
    MyInteger In_class=*this;
    MyInteger tmp("2");
    MyInteger tmp1=OtherObject;
    MyInteger Result;
    Result=tmp.Ppow(OtherObject);
    Result=(In_class/Result); //gets divide by power of 2 raised to n
    return  Result;
}
ostream & operator<<(ostream &output, const MyInteger &OtherObject){
    MyInteger tmp1=OtherObject;
    if(tmp1 != zeron){
        if(OtherObject.sign=='-') output << "-";//output stream function used sign is being outputted otherwise nothing
    }
    output << OtherObject.a;  //printing the string
    return output;
}
/*int main(int argc, const char * argv[]) {
 MyInteger a("-1");
 MyInteger b("-134");
 ++a;
 cout<<a;
 return 0;
 }*/
