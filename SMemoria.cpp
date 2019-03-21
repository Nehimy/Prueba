//--------------------------------------------------------------------------
#include "SMemoria.h"
#include <iostream>
#include <iomanip.h>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------

CSmemoriaAAL::CSmemoriaAAL(){
for (int i=0; i<Max;i++){
 Mem[i].link=i+1;
 Mem[i].dato=0;
}
 Mem[Max].dato=0;
 Mem[Max].link=-1;
 libre=0;
}
//---------------------------------
void CSmemoriaAAL::Crear(){
for(int i=0; i<Max;i++) {
 Mem[i].link=i+1;
 Mem[i].dato=0;
}
  Mem[Max].dato=0;
 Mem[Max].link=-1;
 libre=0;
}
//---------------------------------------------------------------------------
int CSmemoriaAAL::New_Espacio(int cant){
	int dir=libre;
	int d=libre;
	for (int i=1; i<cant; i++){
	  d=Mem[d].link;
	}
	libre=Mem[d].link;
	Mem[d].link=-1;
	return dir;
}
//--------------------------------------------------------------------------
int CSmemoriaAAL::Espacio_Disponible(){
int x=libre;
 int c=0;
  while (x!=-1){
   c=c+1;
   x=Mem[x].link;
  }
 return c;
}
//------------------------------------------------------------------------
int CSmemoriaAAL::Espacio_Ocupado(){
return ((Max+1)-Espacio_Disponible());
}
//------------------------------------------------------------------------
int CSmemoriaAAL::Estado(int dir){
int x=libre;
 bool c=false;
  while ((x!=-1)&&(c==false)){
	if (x==dir){
	  c=true;
	}else{
	  x=Mem[x].link;
	}
  }
  return c;
}
//------------------------------------------------------------------------
void CSmemoriaAAL::PonerDato(int dir,int lug,int nro){
int z=dir;
 for (int i=1; i <lug; i++) {
   z=Mem[z].link;
 }
 Mem[z].dato=nro;
}
//--------------------------------------------------------------------------
int CSmemoriaAAL::Cant_Esp(int dir){
 int x=dir;
 int c=0;
  while (x!=-1){
	c=c+1;
	x=Mem[x].link;
  }
 return c;
}
//----------------------------------
void CSmemoriaAAL::Delete_Espacio(int dir){
 int i=1;
 int x=dir;
  while (Mem[x].link!=-1){
	PonerDato(dir,i,0);
	x=Mem[x].link;
	i++;
  }
 Mem[x].link=libre;
 libre=dir;
}
//-------------------------------------------------------------------------
int CSmemoriaAAL::Obtener_Dato(int dir,int lug){
 int z=dir;
 for (int i=1; i<lug; i++){
   z=Mem[z].link;
 }
 return Mem[z].dato;
}
//--------------------------------------------------------------------------
/*void SMemoria::Mostrar(){
cout<<"\+-------------+\n";
 for (int i=0 ; i<=Max; i++) {
  if(Direccion_Libre(i)){
   printf("| %d | | %d | %d | \n",i,,);
  }else{
   printf("");
  }
 }
 cout<<"\+-------------+\n";
 printf("\n");
 printf("LIBRE = %d",libre);
} */
void CSmemoriaAAL::Mostrar(){
cout<<"libre = "<<libre<<endl;
cout<<"\n";
cout.fill('-');
cout<<"+"<<setw(6)<<"-"<<setw(7)<<"-"<<setw(7)<<"+"<<endl;
cout << "|" << " DIR "<<"|"<<" DATO "<<"| LINK |" << endl;
	for (int i = 0; i < Max+1; i++) {
		 cout.fill('-');
		 cout<<"+"<<setw(6)<<"-"<<setw(7)<<"-"<<setw(7)<<"+"<<endl;
		 cout.fill(' ');
		 cout<<"|";
		 cout.width(5);

		 cout<<i<<"|";
		 cout.width(6);

		 cout <<Mem[i].dato<<"|";
		 cout.width(6);

		 cout <<Mem[i].link<<"|"<<endl;
	}
cout.fill('-');
cout<<"+"<<setw(6)<<"+"<<setw(7)<<"+"<<setw(7)<<"+"<<endl;
cout.fill(' ');

}
