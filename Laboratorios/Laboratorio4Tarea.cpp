/*
  TOME ESTE QUICKSORT DE INTERNET DEBIDO QUE EL QUE ESTABA EN LAS GUIAS NO ME FUNCIONO
  
  
  Ejercicio: Algoritmo de Ordenacion Rapida o QuickSort
  Autor:   Joel Fernandez
  Fecha: 13/06/2014 8:45 p.m.
  IDE: CodeBlocks
  Pagina Web: http://codebotic.blogspot.com
  Descripcion: Implementacion de algoritmo de Ordenamiento Rapido o QuickSort
 */
 
#include<iostream>
#include<conio.h>
#define MAX 50
 
using namespace std;
void LeerArreglo(int,int []);
void Quicksort(int [],int,int);
void MuestraArreglo(int,int []);
 
int missingNumber(int a[],int i){
	int numero;
	if(a[i]%2==0){
		numero=a[i];
	}else{
		numero=a[i]+1;
	}
	return numero;
}
 
int main(void)
{
   //system("color 0a");
   int Numeros[MAX];
   int n;
   //cout<<"\t****************************************************\n";
  // cout<<"\t***      ALGORITMO DE ORDENAMIENTO QUICKSORT     ***\n";
   //cout<<"\t***      -----------------------------------     ***\n";
   
   //cout<<"\t****************************************************\n\n\n";
 
   cout<<"\n\nNUMERO DE DATOS A LEER:"; cin>>n;
 
   LeerArreglo(n,Numeros);  //ingreso de datos en array
   Quicksort(Numeros,0,n-1); // '0' es el primer elemento y n-1 es ultimo
   cout<<endl<<"\n\n LOS ELEMENTOS FUERON ORDENADOS \n\n"<<endl;
   MuestraArreglo(n,Numeros); //muestra array ordenado
 

	
	cout<<"Proximo numero divisible entre 2: "<<missingNumber(Numeros,n-1);

 
    getch();
    return 0;
}


 
void Quicksort(int arreglo[],int primero, int ultimo)
 { int i,j,aux, pivote;
 i=primero;
 j=ultimo;
 pivote=arreglo[(primero+ultimo)/2];//es el elemento medio del arreglo
 do {
 
     while(pivote>arreglo[i])
     i++;
     while(pivote<arreglo[j])
     j--;
     if(i<=j)
     { aux=arreglo[i];
     arreglo[i]=arreglo[j];
     arreglo[j]=aux;
      i++;
      j--;
        }
     }while(i<=j);
     if(primero<j)
       Quicksort(arreglo,primero,j);
     if(ultimo>i)
       Quicksort(arreglo,i,ultimo);
 
  }
 
 
void LeerArreglo(int n,int array[])
{ for(int i=0; i<n; i++)
  {cout<<"\n INGRESE ELEMENTO  ["<<i<<"]:  ";  cin>>array[i];}
  }
 
void MuestraArreglo(int n, int array[])
{int i;
 for(i=0; i<n; i++)
     cout<<"["<<array[i]<<"]  ";
}
