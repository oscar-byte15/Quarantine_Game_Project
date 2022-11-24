#pragma once
#include"Arreglo_Protestantes.h"
#include"Arreglo_Asintomaticos.h"
#include"Ladron.h"
#include"Jugador.h"
#include<ctime>
using namespace System::Windows::Forms;
class Juego_Nivel2_Avanzado {
private:
	Arreglo_Protestantes* ciudadanos;
	Arreglo_Asintomaticos* asi;
	Ladron* ladron;
	Jugador* jugador;
	

	int cool_down_asi;
	int cool_down;
	int cont;
	int tiempo;
	int puntos;
	int robados;
	int pos_asinto;
	int vidas_ladron;
	
	bool rojo;
	clock_t inicio;
public:
	Juego_Nivel2_Avanzado(int tiempo_incial, int vidas) {
	
		cool_down_asi = 0;
		cont = 0;
		cool_down = 0;
		robados = 0;
		pos_asinto = 0;
		puntos = 0;
		vidas_ladron = 20;
		rojo = false;
		asi = new Arreglo_Asintomaticos();
		ciudadanos = new Arreglo_Protestantes();
		ladron = new Ladron ();
		jugador = new Jugador(vidas);
		
		tiempo = tiempo_incial;
		agregar_ciudadano(10);
		
	}
	~Juego_Nivel2_Avanzado() {
		ciudadanos = nullptr;
		asi = nullptr;
		ladron = nullptr;
		jugador = nullptr;
	}
	void GuardarTodo() {
		jugador->GuardarTodo();
		ciudadanos->guardarTodo();
		asi->guardarTodo();
		ladron->GuardarTodo();
	}
	int getTiempo() {
		if ((double(clock() - inicio) / CLOCKS_PER_SEC) >= 1) {
		
			tiempo--;
			cool_down_asi++;
			cool_down++;
			inicio = clock();
		}
		return tiempo;
	}

	int getVidas_Ladron() {
		return vidas_ladron;
	}
	
	int getVidas() {
		return jugador->getVidas();
	}
	int getPuntos() {
		return puntos;
	}
	int getContador() {
		return cont;
	}
	int getRobados() {
		return robados;
	}
	int getPos_Asinotmatico() {
		return pos_asinto;
	}
	bool getRojo() {
		return rojo;
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
	void mover_asintomatico(int ancho1, int alto1) {
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
			///experimiento 1
			if (cool_down == 2) {
				asi->getAsintomatico(i)->agregar_Bala();

			}
			asi->getAsintomatico(i)->moverbala_ene();
		}
		if (cool_down == 2) {

			cool_down = 0;
		}
		jugador->mover_bala(ancho1,alto1);
	}

	void Mostrar_Asintomatico(Graphics^ g, Bitmap^ img,Bitmap^b) {
		asi->mostrar_asintomatico(g,img,b);
	}
	void disparar(double fx,double fy) {
		jugador->agregar_bala(fx,fy);
	}

	void mostrar_ciudadano(Graphics^ g, Bitmap^ img) {
		ciudadanos->mostrar_Protestantes(g,img);
	}
	void agregar_ciudadano(int n) {
		ciudadanos->agregar_protestantes(n);

	}
	
	void mostar_ladron(Graphics^ g, Bitmap^ img){
		ladron->mostrar_Ladron(g,img);
	}
	void mover_ladron(int ancho1, int alto1, int index){
		ladron->mover_Ladron(ancho1,alto1,index);
	}



	void Mostrar_jugador(Graphics^ g, Bitmap^ img, Bitmap^ bala) {

		jugador->Mostrar(g, img);
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
	
	void Mover_Ciudadanos(int ancho1) {
		ciudadanos->mover_protestantes(ancho1);
	}
	void cambiar_rojo(Graphics^ g, Bitmap^ img) {
		if (getRojo() == true) {
			asi->getAsintomatico(getPos_Asinotmatico())->setMostrar(g, img);
		}
	}

	void colision_ladron_ciudadanos() {
		Rectangle lad;
		Rectangle ciud;
		for (int i = 0; i < ciudadanos->getCantidad_Protestantes(); ++i) {
			lad = Rectangle(ladron->getX(), ladron->getY(), ladron->getAncho(), ladron->getAlto());
			ciud = Rectangle(ciudadanos->getProtestante(i)->getX(), ciudadanos->getProtestante(i)->getY(), ciudadanos->getProtestante(i)->getAncho(), ciudadanos->getProtestante(i)->getAlto());
			if (lad.IntersectsWith(ciud)) {
				ciudadanos->eliminar_ciudadano(i--);
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
	void colision_balas_asintomaticoxjugador() {

		Rectangle balae;
		Rectangle ju;
		Balaenemigo* BALA;

		for (int enemigo = 0; enemigo < asi->getcantidad_asintomatico(); ++enemigo)
		{
			for (int bene = 0; bene < asi->getAsintomatico(enemigo)->getCantBalasEne(); ++bene)
			{
				BALA = asi->getAsintomatico(enemigo)->getBalita(bene);
				balae = Rectangle(BALA->getX(), BALA->getY(), BALA->getAncho(), BALA->getAlto());
				ju = Rectangle(jugador->getX(), jugador->getY(), jugador->getAncho(), jugador->getAlto());
				if (balae.IntersectsWith(ju)) {

				
					asi->getAsintomatico(enemigo)->eliminar_bala(bene--);
					jugador->restarvida();

				}


			}
		}

	}

	void colision_balas_jugador_asi() {

		Rectangle bala;//jugador

		Rectangle enemy;
		Bala* BALA;

		for (int b = 0; b < jugador->getCantidad_Balas(); ++b)///balas
		{
			BALA = jugador->getBala(b);

			bala = Rectangle(BALA->getX(), BALA->getY(), BALA->getAncho(), BALA->getAlto());
			for (int zelda = 0; zelda < asi->getcantidad_asintomatico(); ++zelda)
			{

				enemy = Rectangle(asi->getAsintomatico(zelda)->getX(), asi->getAsintomatico(zelda)->getY(), asi->getAsintomatico(zelda)->getAncho(), asi->getAsintomatico(zelda)->getAlto());
				if (bala.IntersectsWith(enemy))
				{
					rojo = true;
					pos_asinto = zelda;
					jugador->eliminar_bala(b--);

					puntos += 20;

				}


			}

		}


	}

	bool Terminar_por_Robados() {
		if(getRobados()==10){
			return true;
		}
		else{
			return false;
		}

	}
	




};