#ifndef _ENTIDAD_H_
#define _ENTIDAD_H_
using namespace System::Drawing;
using namespace System::Windows::Forms;
enum Direccion { Arriba, Abajo, Izquierda, Derecha };
class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int fila, columna;
	int ancho, alto;
	int c_filas, c_columnas;

public:

	int getX() { return x; }
	int getDX() { return dx; }
	int getY() { return y; }
	int getDY() { return dy; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getFila() { return fila; }
	int getColumna() { return columna; }
	int getCantidad_Filas() { return c_filas; }
	int getCantidad_Columnas() { return c_columnas; }

	void setX(int v) { x = v; }
	void setY(int v) { y = v; }
	void setDx(int v) { dx = v; }
	void setDy(int v) { dy = v; }

};
#endif