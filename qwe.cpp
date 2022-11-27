//
// Created by иван on 27.11.2022.
//

#include "qwe.h"
//#include "headers.h"

int Fractional::gcd(int a,int b){
    if (a%b==0) return b;
    if (b%a==0) return a;
    if (a>b) return gcd(a%b,b);
    return gcd(a,b%a);
}
Fractional::Fractional(int a,int b){
    num=a;
    den=b;
    name=new char[4]{(char(num+'0')), '/' , char(den+'0') , '\0' };
}
Fractional::Fractional(){
   // Fractional(0,1);
    num=0;
    den=0;
    name=new char [1];//new char[num,'/',den];
    name[0]='\0';
}
Fractional::Fractional(int a){
    //Fractional(a,1);
    num=a;
    den=1;
    name=new char[num,'/',den,'\0'];
}
Fractional::Fractional(Fractional &a){
    num=a.num;
    den=a.den;

    int size=0;
    while(a.name[size] != '\0') {
        ++size;
    }
    name=new char[size+1];
    for(int i=0;i<=size;i++){
        name[i]=a.name[i];
    }

}
Fractional::~Fractional(){
    delete []name;

}
void Fractional::Reduction(){
    int t=gcd(num,den);
    num/=t;
    den/=t;
}
void Fractional::print(){
    cout<<num<<"/"<<den<<" or ";
    if(name!=0){
        cout<<name;
    }
    cout<<endl;
}
void Fractional::Sum(Fractional a){
    num+=a.num;
    den+=a.den;
}
Fractional Fractional::operator + (Fractional& t2){
    Fractional temp(this->num*t2.den+t2.num*this->den,this->den*t2.den);
    temp.Reduction();
    //temp.name=NULL;
   // Fractional temp(1,2);
    return temp;
    //return Fractional(1,2);
}
Fractional operator - (Fractional& t1,Fractional& t2){
    Fractional temp(t1.num*t2.den-t2.num*t1.den,t1.den*t2.den);
    temp.Reduction();
    return temp;
};
Fractional:: operator float(){
    return(float(num)/den);
}
Fractional operator ++(Fractional &m1,int n){
    m1.num+=m1.num;
    m1.den+=m1.den;
}
Fractional operator ++(Fractional &m1){
    m1.num+=m1.num;
    m1.den+=m1.den;
}
const Fractional& Fractional:: operator=(const Fractional &a){
    if(&a==this) return *this;
    if(name) delete[] name;
    name=NULL;
    this->num=a.num;
    this->den=a.den;
    // name=NULL;
    if (a.name!=0) {
        int size = 0;
        while (a.name[size] != '\0') {
            ++size;
        }
        name = new char[size + 1];
        for (int i = 0; i <= size; i++) {
            name[i] = a.name[i];
        }
    }
    return *this;
}