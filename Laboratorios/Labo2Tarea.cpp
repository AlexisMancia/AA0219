#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *sig;
}*inicio;

class ListaEnlazada{

	public:	
		Nodo* crearNodo(int valor){
			Nodo *n= new Nodo;
			n->dato = valor;
			n->sig = NULL;
			return n;
		}
		
		void mostrarLista(){
			Nodo *temp = inicio;
			if(!inicio){
				cout<<"La lista no posee nodos"<<endl;
			}else{
				while(temp){
					cout<<temp->dato<<", ";
					temp = temp ->sig;
				}
			}
		}
		
		void agregarElemento(int valor){
			Nodo *n = crearNodo(valor), *temp;
			if(!inicio){
				inicio = n;
			}else{
				for(temp=inicio;temp->sig;temp = temp->sig);
				temp->sig=n;
			}
		}
		
		void cambiarElementos(int a,int b){
			Nodo *temp=inicio;
			int key1;
			int key2;
			int contador = 1;
			while(temp != NULL){
				contador++;
				temp=temp->sig;
			}
			if(a>=contador || b>=contador){
				cout<<"Introdusca un valor que se encuentre entre 1 y la cantidad total de nodos:(en este caso de 1 a 6 porque estan quemados)";
			}else{
				temp=inicio;
				for(int i=1;i<=a;i++){
					if(i==a){
						key1=temp->dato;
					}
					temp=temp->sig;
				}
				temp=inicio;
				for(int i=1;i<=b;i++){
					if(i==b){
						key2=temp->dato;
						temp->dato=key1;
					}
					temp=temp->sig;
				}
				temp=inicio;
				for(int k=1;k<=a;k++){
					if(k==a){
						temp->dato=key2;
					}
					temp=temp->sig;
				}
			}
		}		
	
		ListaEnlazada(){
			inicio=NULL;
		}
};
int main(){
	 ListaEnlazada lista1;
	 
	 lista1.agregarElemento(10);
	 lista1.agregarElemento(1);
	 lista1.agregarElemento(9);
	 lista1.agregarElemento(2);
	 lista1.agregarElemento(8);
	 lista1.agregarElemento(3);
	 lista1.mostrarLista();
	 
	 int a,b;
	 cout<<endl<<"Ingrese la posicion de los nodos a los cuales quiere cambiarle los datos:"<<endl;
	 cout<<"Posicion de Nodo a:";
	 cin>>a;
	 cout<<endl<<"Posicion Nodo b:";
	 cin>>b;
	 lista1.cambiarElementos(a,b);
	 cout<<endl;
	 lista1.mostrarLista();
	
	
	return 0;
}
