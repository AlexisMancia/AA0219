#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int a [2][3]={{3,2,4},
                  {4,2,5}};
    int t[2][2]={{3,3},
                {2,4}};

    int e [2]={2,3};
    int x [2]={1,2};
    int n=3;
	int f1[3];
	int f2[3];
	f1[0]=e[0]+a[0][0];
    f2[0]=e[1]+a[1][0];
    string r1;
	string r2;
	for (int i=1;i<n;i++){
        if ((f1[i-1]+a[0][i]) <= (f2[i-1]+t[1][i-1] + a[0][i])){
            f1[i]=f1[i-1]+a[0][i];
            stringstream str;
            str<<i;
            string cad =str.str();
            r1=r1+".a1"+cad;

        }else{
            f1[i]=f2[i-1]+t[1][i-1]+a[0][i];
            stringstream str2;
            str2<<i-1;
            string cad2 =str2.str();
            r1=r1+".a2"+cad2+".t2"+cad2;
        }
        if((f2[i-1]+a[1][i]) <= (f1[i-1]+t[0][i-1]+a[1][i])){
            f2[i]=f2[i-1]+a[1][i];
            stringstream str3;
            str3<<i;
            string cad3 =str3.str();
            r2=r2+".a2"+cad3;
        }else{
            f2[i]=f1[i-1]+t[0][i-1]+a[1][i];
            stringstream str4;
            str4<<i-1;
            string cad4 =str4.str();
            r2=r2+".a1"+cad4+".t1"+cad4;
        }
    }
    cout<<"Respuesta 1: "<<r1<<endl;
    cout<<"Respuesta 2: "<<r2<<endl;
    cout<<"Costo: "<<min(f1[n-1]+x[0],f2[n-1]+x[1]);

   return 0;
}
