#pragma once
#include"Arreglo_Saludables.h"
#include"Arreglo_Asintomaticos.h"
#include"Ladron.h"
#include"Jugador.h"
class Juego_nivel2_Principiante {
private:
	Arreglo_Saludables* salu;
	Arreglo_Asintomaticos* asi;
	Ladron* ladron;
	Jugador* jugador;
	int tiempo;
	int cool_down_asi;
	int cont;
	int cool_down_salu;
	int cont1;
	int puntos;
	int robados;
	int vidas_ladron;
	clock_t inicio;
public:

	Juego_nivel2_Principiante(int tiempo_inicial,int vidas) {
		asi = new Arreglo_Asintomaticos();
		salu = new Arreglo_Saludables();
		jugador = new Jugador(vidas);
		ladron = new Ladron();
		tiempo = tiempo_inicial;
		cool_down_asi=0;
		cont = 0;
		cool_down_salu = 0;
		cont1 = 0;
		puntos = 0;
		robados = 0;
		vidas_ladron = 15;
	}
	~Juego_nivel2_Principiante() {
		asi = nullptr;
		salu = nullptr;
		jugador = nullptr;
		ladron = nullptr;
	}
	void GuardarTodo() {
		jugador->GuardarTodo();
		ladron->GuardarTodo();
		salu->guardarTodo();
		asi->guardarTodo();
	}
	int getTiempo() {
		if ((double(clock() - inicio) / CLOCKS_PER_SEC) >= 1) {

			tiempo--;
			cool_down_asi++;
			cool_down_salu++;
			inicio = clock();
		}
		return tiempo;
	}
	int getRobados() {
		return robados;
	}
	int getVidas_Jugador() {
		return jugador->getVidas();
	}
	int getPuntos() {
		return puntos;
	}
	int getVidas_Ladron() {
		return vidas_ladron;
	}
	int getContador() {
		return cont;
	}
	int getContador1() {
		return cont1;
	}

	void Tiempo_asintomatico() {

		if (cool_down_asi == 3) {
			cont++;
			asi->agregar_asintomatico(1);
		}
		if (cool_down_asi == 3) {
			cool_down_asi = 0;

		}

	}
	void Tiempo_saludable() {
		if (cool_down_salu == 3) {
			cont1++;
			salu->agregar_Saludable(1);
		}
		if (cool_down_salu == 3) {
			cool_down_salu = 0;

		}
	}


	void disparar(double fx,double fy) {
		jugador->agregar_bala(fx,fy);
	}
	void Mostrar_jugador(Graphics^ g, Bitmap^ img, Bitmap^ bala) {

		jugador->Mostrar(g, img);
		//2.disparar mostrar
		jugador->mostrar_bala(g,bala);
	}
	void Mover_jugador(Keys key, int ancho, int alto) {

		if (key == Keys::Up) {
			jugador->Mover(Direccion::Arriba, ancho, alto);
		}
		else if (key == Keys::Down) {
			jugador->Mover(Direccion::Abajo, ancho, alto);
		}
		else if (key == Keys::Right) {
			jugador->Mover(Direccion::Derecha, ancho, alto);
		}
		else if (key == Keys::Left) {
			jugador->Mover(Direccion::Izquierda, ancho, alto);
		}

	}
	void mover_asintomatico(int ancho1,int alto1) {
		for (int i = 0; i < asi->getcantidad_asintomatico(); ++i) {
			if (asi->getAsintomatico(i)->getX() - 1 > jugador->getX()) {
				asi->getAsintomatico(i)->Mover(Direccion::Izquierda, ancho1,alto1);

			}
			else if (asi->getAsintomatico(i)->getX() < jugador->getX()) {
				     asi->getAsintomatico(i)->Mover(Direccion::Derecha, ancho1, alto1);

			}
			else if (asi->getAsintomatico(i)->getY() - 1 > jugador->getY()) {
				     asi->getAsintomatico(i)->Mover(Direccion::Arriba, ancho1, alto1);
			}
			else if (asi->getAsintomatico(i)->getY() < jugador->getY()) {
				     asi->getAsintomatico(i)->Mover(Direccion::Abajo, ancho1, alto1);
			}

			jugador->mover_bala(ancho1,alto1);
		}
	}
	void mostrar_asintomatico(Graphics^ g, Bitmap^ img,Bitmap^b) {
		asi->mostrar_asintomatico(g, img,b);
	}


	void mover_Saludable(int ancho1, int alto1) {
		for (int i = 0; i < salu->getcantidad_saludable(); ++i) {
			salu->getSaludable(i)->Mover(ancho1, alto1, 2);
		
		}
	}
	void mostrar_Saludable(Graphics^ g, Bitmap^ img) {
		salu->mostrar_Saludable(g, img);
	}

	void mostar_ladron(Graphics^ g, Bitmap^ img) {
		ladron->mostrar_Ladron(g, img);
	}
	void mover_ladron(int ancho1, int alto1) {
		ladron->mover_Ladron(ancho1, alto1, 1);
	}
	void colision_jugador_asi() {
		Rectangle juga;
		Rectangle Asinto;
		for (int i = 0; i < asi->getcantidad_asintomatico(); ++i) {
			juga = Rectangle(jugador->getX(), jugador->getY(), jugador->getAncho(), jugador->getAlto());
			Asinto = Rectangle(asi->getAsintomatico(i)->getX(), asi->getAsintomatico(i)->getY(), asi->getAsintomatico(i)->getAncho(), asi->getAsintomatico(i)->getAlto());
			if (juga.IntersectsWith(Asinto)) {
				jugador->restarvida();
			}
		}
	}
	void colision_ladron_jugador() {
		Rectangle juga;
		Rectangle la;
		juga = Rectangle(jugador->getX(), jugador->getY(), jugador->getAncho(), jugador->getAlto());
		la = Rectangle(ladron->getX(), ladron->getY(), ladron->getAncho(), ladron->getAlto());
		if (juga.IntersectsWith(la)) {
			jugador->restarvida();
		}
	}
	void colsion_ladron_saludable() {
		Rectangle la;
		Rectangle saluda;
		for (int i = 0; i < salu->getcantidad_saludable(); ++i) {
			la = Rectangle(ladron->getX(), ladron->getY(), ladron->getAncho(), ladron->getAlto());
			saluda= Rectangle(salu->getSaludable(i)->getX(), salu->getSaludable(i)->getY(), salu->getSaludable(i)->getAncho(), salu->getSaludable(i)->getAlto());
			if (la.IntersectsWith(saluda)) {
				salu->eliminar_Saludable(i--);
				robados++;
		}
		}
	}
	void colision_balasjugador_ladron() {
		Bala* bala;
		Rectangle la;
		Rectangle BALITA;

		for (int i = 0; i < jugador->getCantidad_Balas(); ++i) {
			bala = jugador->getBala(i);
			BALITA = Rectangle(bala->getX(), bala->getY(), bala->getAncho(), bala->getAlto());
			la = Rectangle(ladron->getX(), ladron->getY(), ladron->getAncho(), ladron->getAlto());


			if (BALITA.IntersectsWith(la)) {
				jugador->eliminar_bala(i--);
				
				vidas_ladron--;
				puntos += 10;

			}
		}
	}
	void colision_balas_jugador_asi() {

		Rectangle bala;//jugador

		Rectangle enemy;
		Bala* BALA;

		for (int b = 0; b < jugador->getCantidad_Balas(); ++b)
		{
			BALA = jugador->getBala(b);

			bala = Rectangle(BALA->getX(), BALA->getY(), BALA->getAncho(), BALA->getAlto());
			for (int asinto = 0; asinto < asi->getcantidad_asintomatico(); ++asinto)
			{

				enemy = Rectangle(asi->getAsintomatico(asinto)->getX(), asi->getAsintomatico(asinto)->getY(), asi->getAsintomatico(asinto)->getAncho(), asi->getAsintomatico(asinto)->getAlto());
				if (bala.IntersectsWith(enemy))
				{
					
					
					jugador->eliminar_bala(b--);

					puntos += 10;

				}


			}

		}

	}
};