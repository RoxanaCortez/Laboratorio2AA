#include <iostream>
#include <cstdlib>
#include <array>
using namespace std;

struct Nodo{
	int dato;
	Nodo *sig;
}*inicio, *first;

bool NumeroPar(int num){
    if(num % 2 == 0){
        return true;
    }
	else{
        return false;
    }
}

class ContenedorImpar{
    public:
        Nodo* crearNodoI(int valor){
            Nodo *n = new Nodo;
            n -> dato = valor;
            n -> sig = nullptr;
            return n;
        }
        //Apila el elemento impar
        void apilarImpar(int valor){
            Nodo *n = crearNodoI(valor);
            n->sig = first;
            first = n;
        }
        //Muestra la lista de numeros impares
        void mostrarContenedorImpar(){
            Nodo *temp = first;
            if(!first){
                cout<<"El contenedor impar se encuentra vacío";
            } else{
            	cout<<endl;
                cout<<"Contenedor impar: ";
                while(temp){
                    cout<<temp->dato;
					cout<<" ";
                    temp = temp->sig;
                }
            }
        }
};

class ContenedorPar{
    public:
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n -> dato = valor;
            n -> sig = nullptr;
            return n;
        }
		//Apila el elemento par
        void apilarPar(int valor){
            Nodo *n = crearNodo(valor);
            n->sig = inicio;
            inicio = n;
        }
        //Muestra la lista de numeros pares
        void mostrarContenedorPar(){
            Nodo *temp = inicio;
        	if(!inicio){
                cout<<"El contenedor par se encuentra vacío";
            } 
			else{
				cout<<endl;
                cout<<"Contenedor par: ";
                while(temp){
                    cout<<temp->dato;
					cout<<" ";
                    temp = temp->sig;
                }
            }
        }
};

int main(){
    int n=0;
	int numero=0;
	int i=0;
	int arr[n];
	int par=0; 
	int impar=0;
	int j=0;
	
    cout<<"Cantidad de numeros a ingresar: ";
    cin >> n;
    
    while(i<n){
    	cout<<"Ingrese el numero en la posicion "<< i+1<<" :";
        cin >> numero;
        arr[i] = numero;
        i++;
    }
    
    ContenedorPar contenedorPar;
    ContenedorImpar contenedorImpar;
    
    for (j;j<n;j++){
        if(NumeroPar(arr[j])){
            contenedorPar.apilarPar(arr[j]);
            par++;
        }
		else{
            contenedorImpar.apilarImpar(arr[j]);
            impar++;
        }
    }
    
    contenedorPar.mostrarContenedorPar();
    contenedorImpar.mostrarContenedorImpar();
    
    cout<<endl;
    cout<<endl;
    if(par==impar){
    	cout<<"Se eccontro la misma cantidad de numeros pares e impares igual a "<<par<<".";
	}
	else{
		cout<<endl;
		cout<<"En el arreglo se encontraron "<<par<<" numeros pares y "<<impar<<" numeros impares.";	
	}
}
