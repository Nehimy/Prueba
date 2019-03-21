//---------------------------------------------------------------------------

#ifndef SMemoriaH
#define SMemoriaH
//---------------------------------------------------------------------------
struct NodoM{
 int dato,link;
};
const Max=9;

class CSmemoriaAAL{
  private:
	int libre;
	NodoM Mem[Max+1]; //
  public:
	CSmemoriaAAL();
		void  Crear();
	int New_Espacio(int cant);
	int  Espacio_Ocupado();
	int Espacio_Disponible();
	int Estado(int dir);
	void PonerDato(int dir,int lug,int nro);
	void Delete_Espacio(int dir);
	int Obtener_Dato(int dir,int lug);
	int Cant_Esp(int dir);
	void Mostrar();
};
extern CSmemoriaAAL *Mem;
#endif
