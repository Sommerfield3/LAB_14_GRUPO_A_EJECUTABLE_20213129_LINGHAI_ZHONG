/*2. Dar de baja a un producto. (No hay stock).*/
/*Apellidos y Nombres: Zhong Callasi, Linghai Joaquin*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void darDeAlta(string *datos[],int &posActual,string codigo, string nombre,float precio,int cantidad){
	datos[posActual][0]=codigo;
	datos[posActual][1]=nombre;
	datos[posActual][2]=to_string(precio);
	datos[posActual][3]=to_string(cantidad);
	posActual++;
}
void imprimirProductos(string *datos[],int cantidadProductos){
	cout<<"LISTA DE PRODUCTOS: "<<endl;
	for (int i=0;i<cantidadProductos;i++){
		int cantAux=stof(datos[i][3]);
		cout<<"Código:  "<<datos[i][0]<<endl;
		cout<<"Nombre del producto:  "<<datos[i][1]<<endl;
		cout<<"Precio unitario (S/.):  "<<datos[i][2]<<endl;
		if (cantAux==0){
			cout<<"Unidades disponibles:  Sin stock"<<endl;
		}
		else{
			cout<<"Unidades disponibles:  "<<datos[i][3]<<endl;
		}
		cout<<endl;
	}
}
void imprimirProductosDisponibles(string *datos[],int cantidadProductos){
	cout<<"LISTA DE PRODUCTOS: "<<endl;
	for (int i=0;i<cantidadProductos;i++){
		int cantAux=stof(datos[i][3]);
		if (cantAux!=0){
			cout<<"Código:  "<<datos[i][0]<<endl;
			cout<<"Nombre del producto:  "<<datos[i][1]<<endl;
			cout<<"Precio unitario (S/.):  "<<datos[i][2]<<endl;
			cout<<"Unidades disponibles:  "<<datos[i][3]<<endl;
			cout<<endl;
		}
	}
}

bool esUnico(string *datos[],int posActual,string elemento,int posicion){
	for (int i=0;i<posActual;i++){
		if (datos[i][posicion]==elemento){
			return false;
		}
	}
	return true;
}
void copiar(string *datos[],string *datosAuxint[],int cantidadProductos,int especificaciones){
	for (int i=0;i<(cantidadProductos-1);i++){
		for (int j=0;j<especificaciones;j++){
			datosAuxint[i][j]=datos[i][j];
		}
	}
}
int main(int argc, char *argv[]) {
	int especificaciones=4;
	int cantidadProductos=10; /*Inicialmente son 10*/ 
	int posActual=0;
	string cod;
	string nom;
	float prec=0;
	int cant=0;
	int opc=0;
	string **datos= new string*[cantidadProductos];
	for (int i=0;i<cantidadProductos;i++){
		datos[i]= new string[especificaciones];
	}
	while (true){
		if (posActual>=cantidadProductos){
			cantidadProductos++;
			string **datosAux= new string*[cantidadProductos];
			for (int i=0;i<cantidadProductos;i++){
				datosAux[i]= new string[especificaciones];
			}
			copiar(datos,datosAux,cantidadProductos,especificaciones);
			for (int i=0;i<cantidadProductos;i++){
				delete [] datos[i];
			}
			delete [] datos;
			string **datos= new string*[cantidadProductos];
			for (int i=0;i<cantidadProductos;i++){
				datos[i]= new string[especificaciones];
			}
			copiar(datosAux,datos,cantidadProductos,especificaciones);
			for (int i=0;i<cantidadProductos;i++){
				delete [] datosAux[i];
			}
			delete [] datosAux;
		}
		cout<<"Tienda de ropa: "<<endl<<"1.Dar de alta nuevo producto."<<endl<<"2.Imprimir lista de productos disponibles."<<endl<<"3.Imprimer lista de productos total."<<endl<<"4.Salir"<<endl;
		cout<<"Ingrese una opción (número): ";
		cin>>opc;
		if (opc==1){
			cout<<"NUEVO PRODUCTO: "<<endl;
			while (true){
				cout<<"Ingrese el código del nuevo producto: ";
				cin>>cod;
				if (esUnico(datos,cantidadProductos,cod,0)==0){
					cout<<"El código ya existe"<<endl;
				}
				else if (esUnico(datos,cantidadProductos,cod,0)==1){
					break;
				}
			}
			while (true){
				cout<<"Ingrese el nombre del producto: ";
				getline(cin >> ws, nom);
				cin.clear();
				if (esUnico(datos,cantidadProductos,nom,1)==0){
					cout<<"El nombre ya existe"<<endl;
				}
				else if (esUnico(datos,cantidadProductos,nom,1)==1){
					break;
				}
			}
			while (true){
				cout<<"Ingrese el precio por unidad del producto: ";
				cin>>prec;
				if (prec>0){
					while (true){
						cout<<"Ingrese la cantidad de unidades disponibles: ";
						cin>>cant;
						if (cant>=0){
							break;
						}
						else{
							cout<<"Ingrese una cantidad válida. "<<endl;
						}
					}
					break;
				}
				else{
					cout<<"Ingrese un valor válido. "<<endl;
				}
			}
			darDeAlta(datos,posActual,cod,nom,prec,cant);
		}
		else if (opc==2){
			imprimirProductos(datos,posActual);
		}
		else if (opc==3){
			imprimirProductosDisponibles(datos,cantidadProductos);
		}
		else if (opc==4){
			break;
		}
		else{
			cout<<"Ingrese una opción válida. "<<endl;
		}
	}
	for (int i=0;i<cantidadProductos;i++){
		delete [] datos[i];
	}
	delete [] datos;
	system ("pause");
	return 0;
}

