#pragma once
#include<string>
#include<fstream>
#include <iostream>
using namespace std;
struct casset{
private:
    string name,author;
    int num,year;
public:
    string getName(){return this->name;}
    string getAuthor(){return this->author;}
    int getNum(){return this->num;}
    int getYear(){return  this->year;}
    void setName(string n){this->name=n;}
    void setYear(int n){this->year=n;}
    void setAuthor(string n){this->author=n;}
    void setNum(int n){this->num=n;}
    void toString() {cout<<num <<"--"<<name<<"--"<<author<<"--"<<year<<endl;}
};
void read(casset *cas,ifstream &file,int c);
void write(casset *cas,int c);
void write(casset *cas,int c);
void numSorting(casset *cas,int c);
void yearSorting(casset *cas,int c);
void authorSorting(casset *cas,int c);
void nameSorting(casset *cas,int c);
casset nameFinder(casset *cas, string key,int c);
casset yearFinder(casset *cas, int key,int c);
casset authorFinder(casset *cas, string key,int c);
casset numFinder(casset *cas, int key,int c);
void out(casset *cas,int c);

void read(casset *cas,ifstream &file,int c)
{
    int n,y;
    char *au, *nu,*nameu,*yu;
    string a,name,yy,nn;
    for(int i=0;i<c;i++)
    {
        au=new char[256];
        nu=new char[256];
        nameu=new char[256];
        yu=new char[256];
        file.getline(nu,256);
        file.getline(yu,256);
        nn=nu;
        yy=yu;
        y=std::stoi(yy);
        n=std::stoi(nn);
        file.getline(au,256);
        a=au;
        file.getline(nameu,256);
        name=nameu;
        cas[i].setNum(n);
        cas[i].setYear(y);
        cas[i].setAuthor(a);
        cas[i].setName(name);
        delete au;
        delete nu;
        delete nameu;
        delete yu;
    }
}
void write(casset *cas,int c)
{
    numSorting(cas,c);
    ofstream file;
    file.open("228.txt",std::ofstream::out|std::ofstream::trunc);
    int n,y;
    string a,name;
    file<<c<<endl;
    for(int i=0;i<c;i++)
    {
        n=cas[i].getNum();
        y=cas[i].getYear();
        a=cas[i].getAuthor();
        name=cas[i].getName();
        file<<n<<endl;
        file<<y<<endl;
        file<<a<<endl;
        file<<name<<endl;
    }
}
void binWrite(casset *cas,int c)
{
    int n,y;
    string a,name;
    numSorting(cas,c);
    ofstream file("bin.bin",ios::binary|ios::trunc);
    file.write(to_string(c).c_str(),3);
    for(int i=0;i<c;i++)
    {
        n=cas[i].getNum();
        y=cas[i].getYear();
        a=cas[i].getAuthor();
        name=cas[i].getName();
        file.write(to_string(n).c_str(),255);
        file.write(to_string(y).c_str(),255);
        file.write(a.c_str(),255);
        if(i==c-1)
            file.write(name.c_str(),256);
        else
            file.write(name.c_str(),255);
    }
}
int binRead(casset *cas)
{
    int n,y,c;
    char *nn,*yy,*aa,*na,*cc;
    string a,name;
    ifstream file("bin.bin",ios::binary);
    cc=new char[3];
    file.read(cc,3);
    c=atoi(cc);
    cas = new casset[c];
    for(int i=0;i<c;i++)
    {
        aa=new char[255];
        nn=new char[255];
        na=new char[255];
        yy=new char[255];
        file.read(nn,255);
        file.read(yy,255);
        file.read(aa,255);
        file.read(na,255);
        cas[i].setNum(atoi(nn));
        cas[i].setYear(atoi(yy));
        a=aa;
        name=nn;
        cas[i].setName(name);
        cas[i].setAuthor(a);
        delete aa;
        delete nn;
        delete na;
        delete yy;
    }
    return c;
}
void numSorting(casset *cas,int c)
{
    casset t;
    for(int i=0;i<c-1;i++)
        for(int j=0;j<c-1-i;j++)
            if(cas[j].getNum()>cas[j+1].getNum())
            {
                t=cas[j];
                cas[j]=cas[j+1];
                cas[j+1]=t;
            }
}
void yearSorting(casset *cas,int c)
{
    casset t;
    for(int i=0;i<c-1;i++)
        for(int j=0;j<c-1-i;j++)
            if(cas[j].getYear()>cas[j+1].getYear())
            {
                t=cas[j];
                cas[j]=cas[j+1];
                cas[j+1]=t;
            }
}
void authorSorting(casset *cas,int c)
{
    casset t;
    for(int i=0;i<c-1;i++)
        for(int j=0;j<c-1-i;j++)
            if(cas[j].getAuthor()>cas[j+1].getAuthor())
            {
                t=cas[j];
                cas[j]=cas[j+1];
                cas[j+1]=t;
            }
}
void nameSorting(casset *cas,int c)
{
    casset t;
    for(int i=0;i<c-1;i++)
        for(int j=0;j<c-1-i;j++)
            if(cas[j].getName()>cas[j+1].getName())
            {
                t=cas[j];
                cas[j]=cas[j+1];
                cas[j+1]=t;
            }
}
casset nameFinder(casset *cas, string key,int c)
{
    nameSorting(cas,c);
    static int l=0;
    c--;
    static int r=c;
    int mid;
    bool flag=false;
        while ((l <= r) && (flag != true)) {
            mid = (l + r) / 2;
            if (cas[mid].getName() == key)
                flag = true;
            if (cas[mid].getName() > key)
                    r = mid - 1;
                else l = mid + 1;

    }
        return cas[mid];
}
casset yearFinder(casset *cas, int key,int c)
{
    yearSorting(cas,c);
    static int l=0;
    c--;
    static int r=c;
    int mid;
    bool flag=false;
        while ((l <= r) && (flag != true)) {
            mid = (l + r) / 2;
            if (cas[mid].getYear() == key)
                flag = true;
                if (cas[mid].getYear() > key)
                    r = mid - 1;
                else l = mid + 1;

    }
        return cas[mid];
}
casset authorFinder(casset *cas, string key,int c)
{
    authorSorting(cas,c);
    static int l=0;
    c--;
    static int r=c;
    int mid;
    bool flag=false;
        while ((l <= r) && (flag != true)) {
            mid = (l + r) / 2;
            if (cas[mid].getAuthor() == key)
                flag = true;
                if (cas[mid].getAuthor() > key)
                    r = mid - 1;
                else l = mid + 1;

    }
        return cas[mid];
}
casset numFinder(casset *cas, int key,int c)
{
    numSorting(cas,c);
    static int l=0;
    c--;
    static int r=c;
    int mid;
    bool flag=false;
        while ((l <= r) && (flag != true)) {
            mid = (l + r) / 2;
            if (cas[mid].getNum() == key)
                flag = true;
                if (cas[mid].getNum() > key)
                    r = mid - 1;
                else l = mid + 1;   
    }
        return cas[mid];
}
void out(casset *cas,int c)
{
    numSorting(cas,c);
    for(int i=0;i<c;i++)
    {
        cas[i].toString();
    }
}
