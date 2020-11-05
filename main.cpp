#include <iostream>
#include "casset.h"
using namespace std;

int main()
{
       ifstream file;
       int c;
       /*char cc[3];
       casset *cas;
       casset t;
       file.open("init.txt");
       file.getline(cc,3);
       c=stoi(cc);
       cas = new casset[c];
       read(cas,file,c);
       write(cas,c);
       yearFinder(cas,1994,c).toString();
       cout<<"---------------------------------------------------"<<endl;
       out(cas,c);
       binWrite(cas,c);*/
       /**/casset *cas;
       cas = new casset[c=count()];
       binRead(cas);
       write(cas,c);
       yearFinder(cas,1994,c).toString();
       cout<<"---------------------------------------------------"<<endl;
       out(cas,c);
}
