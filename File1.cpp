#include <iostream.h>
#include "SMemoria.h"
#include <windows.h>
#include <iostream.h>
#include <iomanip.h>
//-------------------------------------------------------------------------
using namespace std;
CSmemoriaAAL *Mem;
int main(){
  int m,r,s,n,t,ciclo=0;

	cout<<"\tCLASE MEMORIA\n";
	cout<<"1: Crear\n";
	cout<<"2: Pedir Espacio\n";
	cout<<"3: Liberar Espacio\n";
	cout<<"4: Poner Dato\n";
	cout<<"5: Mostrar memoria\n";
	cout<<"6: Salir\n";
   while (ciclo==0){
   cout<<" Elegir una opcion: ";
	cin>>m;
	  switch (m) {
		  case 1:
				Mem=new CSmemoriaAAL;
				cout<<"Memoria creada \n";
				break;


		  case 2:
		  //Pedir Espacio
		  int ele;
		  cout<<"\t\tIngrese la cantidad de espacios que desea: ";
		  cin>>ele;
		  m=Mem->Espacio_Disponible();
		  if (ele>m) {
		   cout<<"\t\tERROR:No hay esa cantidad de memoria disponible";printf("\n");
		  }else{
		   Mem->New_Espacio(ele);
		 //  cout<<"\t\tLa direccion es:";cout<<ele<<endl;
		  }
		  break;

		  case 3:
		   //Liberar espacio
		  cout<<"\t\tIngresar la direccion a liberar: ";cin>>r;
		  if (Mem->Estado(r)){
		   cout<<"\t\tEsta direccion ya esta libre"<<endl;
		  }else{
		  Mem->Delete_Espacio(r);
		  }
		  break;
		  case 4:
		  //poner dato
		  cout<<"\t\tIngresar la direccion: ";cin>>r;
		  cout<<"\t\tIngresar la posicion: ";cin>>n;
		  cout<<"\t\tIngresar el valor: ";cin>>s;
		   if (Mem->Estado(r)){
			cout<<"\t\tERROR:Debe ingresar una direccion que este reservada";
		  }else{
			m=Mem->Cant_Esp(r);
		   if (n>m) {
			cout<<"\t\tERROR:La posicion excede la cantidad de espacios reservados para esta direccion\n ";
		   }else{
		   Mem->PonerDato(r,n,s);
		   }
		  }
			break;

		  case 5: //Mostrar Memoria
			  Mem->Mostrar();
			  printf("\n");
			  break;
			  cin>>ciclo;
			  break;
		  case 7:
		  exit(0);
		  break;
	  default:cout<<"Error esta no es valida"<<endl;
	  break;
	  }
   }



system("pause");

}
