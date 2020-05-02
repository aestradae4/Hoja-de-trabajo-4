#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
void insertar(); 
void reporte(); 
void malahi(); 
void langos();
void gusanos(); 
void todoloanterior(); 
void salir(); 
void mp(); 
using namespace std; 

int main()
{
	mp(); 
}

void mp(){
	int resp, resp2;
		
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Servicios"<<"\n";
		cout<<" 2 - Reporte "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			insertar();
			do{
				system("CLS"); 
				cout<<"----------------------"<<"\n"; 
				cout<<"Menu de servicios"<<"\n"; 
				cout<<"---------------------"<<"\n";
				cout<<" 1 - Mala hierba"<<"\n";
				cout<<" 2 - Langostas"<<"\n";
				cout<<" 3 - Gusanos"<<"\n";
				cout<<" 4 - Todo lo anterior"<<"\n";
				cout<<" 5 - Regresar al menu anterior"<<"\n";
				cout<<"--------------------------"<<"\n";
				cout<<" Seleccione su opcion: ";
				cin>>resp2; 
				if (resp2==1){		
				system("CLS");
				malahi(); 
			}
			else if (resp2==2){
				system("CLS"); 
				langos(); 
				
			}
			else if (resp2==3){
				system("CLS"); 
				gusanos(); 
				
			}
			else if (resp2==4){
				system("CLS"); 
				todoloanterior(); 
			}
			else if (resp2==5){
				system("CLS"); 
				mp();
			}
			else 
				break; 
				
			
			}	while (resp2!=5); 
					
		}
		else if (resp==2){		
			system("CLS");
			reporte();
		}
		else if (resp==3){		
			system("CLS");
			salir();	
		}
		else 
			break;
		
	} while(resp!=3);	
}

void insertar (){
}

void reporte (){
	int hec=0, calculo=0, des1=0, des2= 0, total = 0, n, mayortotal = -1, suma;
	string nombre, opcion, mayoropcion; 

	ifstream db; //Leeer archivo
	cout<<"Datos del archivo:"<<endl;
	cout<<" Opcion|"<<"	   Nombre	 |"<<"total|"<<endl; 
	try {
	db.open("xterminio.txt",ios::in); //abrir archivo en modo de agregar datos
	while(db>>opcion>>nombre>>total){
	const auto obj = regex{ "_" }; 
	const auto repl = string{ " " }; 
	const auto valor = nombre; 
		cout<<setw(7)<<opcion<<"|"<<setw(20)<<regex_replace(valor, obj, repl)<<"|"<<setw(10)<<total<<"|"<<endl; 
	n++; 
	suma+=total;
	if(total>mayortotal){
		mayortotal = total;
		mayoropcion = opcion; 
		} 
	}
	db.close();

	cout<<"Servicio con mayor demanda: "<<setw(3)<<mayoropcion<<" --- total de demanda:" <<setw(3)<<mayortotal<<" "<<endl; 
	system("Pause");
	}
	catch (exception& X){
		cout <<"Error en la manipulacion del archivo"<<endl; 
		cout<<"Error: "<<X.what()<<endl; 
		system("Pause"); 
		
		}
}

void malahi(){
	cout<<"El precio por Mala Hierba es de 10.00"<<"\n";
	cout<<"-------------------------------------"<<"\n";	
	int hec=0, calculo=0, des1=0, des2= 0, total = 0, t = 0;
	ofstream db; 
	string nombre, opcion; 
	cout<<"Ingrese el numero de Hectareas"<<endl;  
	cin>>hec; 
	fflush(stdin);
	cout<<"Ingrese el nombre del servicio"<<endl;
	getline (cin,nombre); 
	cout<<"Ingrese el numero de la opcion"<<endl; 
	getline (cin, opcion); 
	
	const auto obj = regex{ " " }; 
	const auto repl = string{ "_" }; 
	const auto valor = nombre; 
	
	if (hec >= 500 ){
		calculo = hec * 10; 
		des1 = calculo * 0.05; 
		t = calculo - des1; 
	} else if (hec <= 500){
	
	calculo = hec * 20; 
	
	
	}
	total = calculo; 
	
	if (calculo >= 1500){
		des2 = t * 0.10;
		total = t - des2;  
	}
	
	total = total; 
	
	cout<<"El total a pagar es de"<<"\t"<<total<<endl; 
	cout<<"El descuento 1 es de"<<"\t"<<des1<<endl; 
	cout<<"El descuento 2 es de"<<"\t"<<des2<<endl; 
	system("Pause"); 
	
	try {
	db.open("xterminio.txt",ios::app); //abrir archivo en modo de agregar datos
	db<<opcion<<"\t"<<regex_replace(valor, obj, repl)<<"\t"<<total<<endl;
	db.close();
	
	}
	catch (exception& X){
		cout <<"Error en la manipulacion del archivo"<<endl; 
		cout<<"Error: "<<X.what()<<endl; 
		system("Pause"); 
		
	}
}


void langos(){
		cout<<"El precio por Langostas es de 20.00"<<"\n";
	cout<<"-------------------------------------"<<"\n";	
	int hec=0, calculo=0, des1=0, des2= 0, total = 0, t = 0;
	ofstream db; 
	string nombre, opcion; 
	cout<<"Ingrese el numero de Hectareas"<<endl;  
	cin>>hec; 
	fflush(stdin);
	cout<<"Ingrese el nombre del servicio"<<endl;
	getline (cin,nombre); 
	cout<<"Ingrese el numero de la opcion"<<endl; 
	getline (cin, opcion); 
	
	const auto obj = regex{ " " }; 
	const auto repl = string{ "_" }; 
	const auto valor = nombre; 
	
		if (hec >= 500 ){
		calculo = hec * 20; 
		des1 = calculo * 0.05; 
		t = calculo - des1; 
	} else if (hec <= 500){
	
	calculo = hec * 20; 
	 
	}
	total = calculo; 
	
	
	if (calculo >= 1500){
		des2 = t * 0.10;
		total = t - des2;  
	}
	
	total = total;
	
	cout<<"El total a pagar es de"<<"\t"<<total<<endl; 
	cout<<"El descuento 1 es de"<<"\t"<<des1<<endl; 
	cout<<"El descuento 2 es de"<<"\t"<<des2<<endl; 
	system("Pause"); 
	try {
	db.open("xterminio.txt",ios::app); //abrir archivo en modo de agregar datos
	db<<opcion<<"\t"<<regex_replace(valor, obj, repl)<<"\t"<<total<<endl;
	db.close();
	
	}
	catch (exception& X){
		cout <<"Error en la manipulacion del archivo"<<endl; 
		cout<<"Error: "<<X.what()<<endl; 
		system("Pause"); 
		
	}

	
}

void gusanos (){
	cout<<"El precio por gusanos es de 30.00"<<"\n";
	cout<<"-------------------------------------"<<"\n";	
	int hec=0, calculo=0, des1=0, des2= 0, total = 0, t = 0;
	ofstream db; 
	string nombre, opcion; 
	cout<<"Ingrese el numero de Hectareas"<<endl;  
	cin>>hec; 
	fflush(stdin);
	cout<<"Ingrese el nombre del servicio"<<endl;
	getline (cin,nombre); 
	cout<<"Ingrese el numero de la opcion"<<endl; 
	getline (cin, opcion); 
	
	const auto obj = regex{ " " }; 
	const auto repl = string{ "_" }; 
	const auto valor = nombre; 
	
		if (hec >= 500 ){
		calculo = hec * 10; 
		des1 = calculo * 0.05; 
		t = calculo - des1; 
	} else if (hec <= 500){
	
	calculo = hec * 20; 
	
	}
	total = calculo;
	 
	if (calculo >= 1500){
		des2 = t * 0.10;
		total = t - des2;  
	}
	
	total = total;
	
	cout<<"El total a pagar es de"<<"\t"<<total<<endl; 
	cout<<"El descuento 1 es de"<<"\t"<<des1<<endl; 
	cout<<"El descuento 2 es de"<<"\t"<<des2<<endl; 	
	system("Pause"); 
	try {
	db.open("xterminio.txt",ios::app); //abrir archivo en modo de agregar datos
	db<<opcion<<"\t"<<regex_replace(valor, obj, repl)<<"\t"<<total<<endl;
	db.close();
	
	}
	catch (exception& X){
		cout <<"Error en la manipulacion del archivo"<<endl; 
		cout<<"Error: "<<X.what()<<endl; 
		system("Pause"); 
		
	}
}


void todoloanterior(){
	cout<<"El precio por Todo lo anterior es de 50.00"<<"\n";
	cout<<"-------------------------------------"<<"\n";	
	int hec=0, calculo=0, des1=0, des2= 0, total = 0, t=0;
	ofstream db; 
	string nombre, opcion; 
	cout<<"Ingrese el numero de Hectareas"<<endl;  
	cin>>hec; 
	fflush(stdin);
	cout<<"Ingrese el nombre del servicio"<<endl;
	getline (cin,nombre); 
	cout<<"Ingrese el numero de la opcion"<<endl; 
	getline (cin, opcion);
	  
	const auto obj = regex{ " " }; 
	const auto repl = string{ "_" }; 
	const auto valor = nombre; 
		if (hec >= 500 ){
		calculo = hec * 10; 
		des1 = calculo * 0.05; 
		t = calculo - des1; 
	} 
	else if (hec <= 500){
	
	calculo = hec * 20; 
	
	}
	total = calculo; 
	
	if (calculo >= 1500){
		des2 = t * 0.10;
		total = t - des2;
		total = total;   
	}
	
	
	
	cout<<"El total a pagar es de"<<"\t"<<total<<endl; 
	cout<<"El descuento 1 es de"<<"\t"<<des1<<endl; 
	cout<<"El descuento 2 es de"<<"\t"<<des2<<endl; 
	system("Pause"); 	
	
	try {
	db.open("xterminio.txt",ios::app); //abrir archivo en modo de agregar datos
	db<<opcion<<"\t"<<regex_replace(valor, obj, repl)<<"\t"<<total<<endl;
	db.close();
	
	}
	catch (exception& X){
		cout <<"Error en la manipulacion del archivo"<<endl; 
		cout<<"Error: "<<X.what()<<endl; 
		system("Pause"); 
		
	}
}


void salir(){
}
