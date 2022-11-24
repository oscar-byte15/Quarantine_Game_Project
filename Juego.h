#pragma once
#include<fstream>
#include"Jugador.h"
#include"Arreglo_Asintomaticos.h"
#include"Arreglo_Saludables.h"
#include"Ambulancia.h"
#include"Policia.h"

using namespace System::Windows::Forms;

class Juego {
	Jugador* jugador;
	Ambulancia* ambu;
	Policia* poli;
	Arreglo_Asintomaticos* ene;
	Arreglo_Saludables* salu;
	

	int puntos = 0;
	int tiempo;
	int cont; 
	int cont1;
	clock_t inicio;
	int cool_down;
	int cool_down1;
	int cool_down_asi;
	int cool_down_salu;
	bool rojo;
	bool verde;
	int capturados;
	bool sonido;
	int pos_saludable;
	int pos_asinto;


public:
	Juego(int tiempo_inicial, int vidas) {
		Random j;
		cool_down_asi = 0;
		cool_down_salu = 0;

		jugador = new Jugador(vidas);
		ambu = new Ambulancia();
		poli = new Policia();
		ene = new Arreglo_Asintomaticos();
		salu = new Arreglo_Saludables();
		
		sonido = false;
		tiempo = tiempo_inicial;
		cool_down = 0;
		cool_down1 = 0;

		pos_saludable = 0;
		pos_asinto = 0;
		cont = 0;
		cont1 = 0;
		capturados = 0;
		Abrir();
	}
	~Juego() {
		jugador = nullptr;
		ambu = nullptr;
		poli = nullptr;
		ene = nullptr;
		salu = nullptr;
	}
	void Reset(int tiempo_inicial,int vidas) {
		Random j;
		cool_down_asi = 0;
		cool_down_salu = 0;

		jugador = new Jugador(vidas);
		ambu = new Ambulancia();
		poli = new Policia();
		ene = new Arreglo_Asintomaticos();
		salu = new Arreglo_Saludables();


		tiempo = tiempo_inicial;
		cool_down = 0;
		cool_down1 = 0;
		sonido = false;
		pos_saludable = 0;
		pos_asinto = 0;
		cont = 0;
		cont1 = 0;
		capturados = 0;
		Abrir();
	}
	//1.- GENERAL


	int getPuntos() {
		return puntos;

	}
	
	int getCapturados() { return capturados; }
	int getContador() {
		return cont;
	}
	int getContador1() {
		return cont1;
	}
	bool getVerde() {
		return verde;
	}
	bool getSonido() { return sonido; }
	int getPos_Saludable() {
		return pos_saludable;
	}
	int getPos_Asinotmatico() {
		return pos_asinto;
	}
	bool getRojo() {
		return rojo;
	}

	void Abrir() {

	std::ifstream archivo("Jugador1.txt");
	int x, y, cant_b,dx, dy,cant_vidas;
	/*cant_vidas = jugador->getVidas();*/
	if (archivo.is_open()) {


		archivo >> x >> y >> cant_b >> dx >> dy >>cant_vidas ;
		jugador->setX(x);
		jugador->setY(y);
		jugador->setDx(dx);
		jugador->setDy(dy);
		/*jugador->setVidas(cant_vidas);*/

	}
	else {
		GuardarTodo();
	}
}
	int Tiempo() {


		if ((double(clock() - inicio) / CLOCKS_PER_SEC) >= 1)
		{
			cool_down++;
			cool_down1++;

			cool_down_asi++;
			cool_down_salu++;
			tiempo--;
			inicio = clock();
		}

		return tiempo;

	}
	void Tiempo_asintomatico() {

		if (cool_down_asi == 3) {
			cont++;
			ene->agregar_asintomatico(1);
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

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//2.-JUGADOR
	void disparar(double fx,double fy) {
		jugador->agregar_bala(fx,fy);
	}
	int getvidasJugador() {
		return jugador->getVidas();
	}


	void Mostrar_jugador(Graphics^ g, Bitmap^ img,Bitmap^bala) {

		jugador->Mostrar(g, img);
	
		jugador->mostrar_bala(g,bala);
	}

	void Mover_jugador(Keys key, int ancho1,int alto1) {

		if (key == Keys::Up) {
			jugador->Mover(Direccion::Arriba, ancho1,alto1);
		}
		else if (key == Keys::Down) {
			jugador->Mover(Direccion::Abajo,ancho1,alto1);
		}
		else if (key == Keys::Right) {
			jugador->Mover(Direccion::Derecha, ancho1,alto1);
		}
		else if (key == Keys::Left) {
			jugador->Mover(Direccion::Izquierda, ancho1,alto1);
		}

	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//3.- asintomatico
	void mover_asintomatico(int ancho1,int alto1) {
		for (int i = 0; i < ene->getcantidad_asintomatico(); ++i) {

			if (ene->getAsintomatico(i)->getX() - 1 > jugador->getX()) {
				ene->getAsintomatico(i)->Mover(Direccion::Izquierda, ancho1,alto1);

			}
			else if (ene->getAsintomatico(i)->getX() < jugador->getX()) {
				ene->getAsintomatico(i)->Mover(Direccion::Derecha, ancho1, alto1);

			}
			else if (ene->getAsintomatico(i)->getY() - 1 > jugador->getY()) {
				ene->getAsintomatico(i)->Mover(Direccion::Arriba, ancho1, alto1);
			}
			else if (ene->getAsintomatico(i)->getY() < jugador->getY()) {
				ene->getAsintomatico(i)->Mover(Direccion::Abajo, ancho1, alto1);
			}
		
			if (cool_down == 3) {
				ene->getAsintomatico(i)->agregar_Bala();

			}
			ene->getAsintomatico(i)->moverbala_ene();
		}
		if (cool_down == 3) {

			cool_down = 0;
		}
		jugador->mover_bala(ancho1,alto1);
	}
	void mostrar_asintomatico(Graphics^ g, Bitmap^ img, Bitmap^b) {
		ene->mostrar_asintomatico(g,img,b);
	}
	void mostrar_Saludable(Graphics^ g, Bitmap^ img) {
		salu->mostrar_Saludable(g,img);
	}




	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//4.-Saludable
	void mover_Saludable(int ancho1, int alto1) {
		for (int i = 0; i < salu->getcantidad_saludable(); ++i) {
			salu->getSaludable(i)->Mover(ancho1,alto1, 1);
		
			if (cool_down1 == 2) {
				salu->getSaludable(i)->agregar_Bala(1);

			}
			salu->getSaludable(i)->moverbala_ene();
		}
		if (cool_down1 == 2) {

			cool_down1 = 0;
		}

	}
	



	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//5.- AMBULANCIA
	void Mostrar_ambulancia1(Graphics^ g, Bitmap^ img) {
		ambu->mostrar_ambulnacia(g, img);
	}

	void Mover_ambulncia1( int pos,int ancho_form,int alto_form) {

		if (ene->getAsintomatico(pos)->getX() >= ambu->getX() + 2) {
			ambu->mover_ambulancia(Direccion::Derecha, ancho_form,alto_form);

		}
		else if (ene->getAsintomatico(pos)->getX() + 2 <= ambu->getX() - 2) {
			ambu->mover_ambulancia(Direccion::Izquierda, ancho_form, alto_form);

		}
		else if (ene->getAsintomatico(pos)->getY() >= ambu->getY()) {
			ambu->mover_ambulancia(Direccion::Abajo, ancho_form, alto_form);
		}
		else if (ene->getAsintomatico(pos)->getY() <= ambu->getY()) {
			ambu->mover_ambulancia(Direccion::Arriba, ancho_form, alto_form);
		}



	}

	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//6.- Policia

	void Mostrar_Policia(Graphics^ g, Bitmap^ img) {
		poli->mostrar_Policia(g, img);
	}


	void Mover_Policia(int ancho1, int alto1, int pos) {
		
		if (salu->getSaludable(pos)->getX() > poli->getX()) {
			poli->mover_Policia(Direccion::Derecha, ancho1,alto1);

		}
	/*	else if (salu->getSaludable(pos)->getX() == poli->getX()) {
			poli->X0();
		}*/
		
		else if (salu->getSaludable(pos)->getY() > poli->getY()) {
			poli->mover_Policia(Direccion::Abajo, ancho1, alto1);
		}
	/*	else if (salu->getSaludable(pos)->getY() == poli->getY()) {
			poli->Y0();
		}*/
		else if (salu->getSaludable(pos)->getY() < poli->getY()) {
			poli->mover_Policia(Direccion::Arriba, ancho1, alto1);
		}
		
	}


	
	//7.- COLISONES
	void colision_jugador_asi() {
		Rectangle juga;
		Rectangle Asinto;
		for (int i = 0; i < ene->getcantidad_asintomatico(); ++i) {
			juga = Rectangle(jugador->getX(), jugador->getY(), jugador->getAncho(), jugador->getAlto());
			Asinto = Rectangle(ene->getAsintomatico(i)->getX(), ene->getAsintomatico(i)->getY(), ene->getAsintomatico(i)->getAncho(), ene->getAsintomatico(i)->getAlto());
			if (juga.IntersectsWith(Asinto)) {
				jugador->restarvida();
			}
		}
	}
	void colision_jugador_salu() {
		Rectangle juga;
		Rectangle saludab;
		for (int i = 0; i < salu->getcantidad_saludable(); ++i) {
			juga = Rectangle(jugador->getX(), jugador->getY(), jugador->getAncho(), jugador->getAlto());
			saludab = Rectangle(salu->getSaludable(i)->getX(), salu->getSaludable(i)->getY(), salu->getSaludable(i)->getAncho(), salu->getSaludable(i)->getAlto());
			if (juga.IntersectsWith(saludab)) {
				jugador->restarvida();
			}
		}
	}

	void colision_balas_asintomaticoxjugador() {

		Rectangle balae;
		Rectangle ju;
		Balaenemigo* BALA;

		for (int enemigo = 0; enemigo < ene->getcantidad_asintomatico(); ++enemigo)
		{
			for (int bene = 0; bene < ene->getAsintomatico(enemigo)->getCantBalasEne(); ++bene)
			{
				BALA = ene->getAsintomatico(enemigo)->getBalita(bene);
				balae = Rectangle(BALA->getX(), BALA->getY(), BALA->getAncho(), BALA->getAlto());
				ju = Rectangle(jugador->getX(), jugador->getY(), jugador->getAncho(), jugador->getAlto());
				if (balae.IntersectsWith(ju)) {
					ene->getAsintomatico(enemigo)->eliminar_bala(bene--);
					jugador->restarvida();

				}


			}
		}

	}
	void colison_balas_desaludable_ajugador() {
		Rectangle bala_salu;
		Rectangle juga;
		BalaEnemigos1* BAL1;


		for (int saludable = 0; saludable < salu->getcantidad_saludable(); ++saludable) {

			for (int bal = 0; bal < salu->getSaludable(saludable)->getCantBalasEne1(); ++bal) {
				BAL1 = salu->getSaludable(saludable)->getBalita1(bal);
				bala_salu = Rectangle(BAL1->getX(), BAL1->getY(), BAL1->getAncho(), BAL1->getAlto());
				juga = Rectangle(jugador->getX(), jugador->getY(), jugador->getAncho(), jugador->getAlto());

				if (bala_salu.IntersectsWith(juga)) {
					salu->getSaludable(saludable)->eliminar_bala(bal--);
					jugador->restarvida();
				}
			}

		}


	}
	void colision_balas_jugador_saludable() {
		Rectangle bala;
		Rectangle saludable;
		Bala* BALA;
		for (int b = 0; b < jugador->getCantidad_Balas(); ++b) {
			BALA = jugador->getBala(b);

			bala = Rectangle(BALA->getX(), BALA->getY(), BALA->getAncho(), BALA->getAlto());
			for (int sa = 0; sa < salu->getcantidad_saludable(); ++sa) {
				saludable = Rectangle(salu->getSaludable(sa)->getX(), salu->getSaludable(sa)->getY(), salu->getSaludable(sa)->getAncho(), salu->getSaludable(sa)->getAlto());


				if (bala.IntersectsWith(saludable)) {
					verde = true;
					sonido = true;
					puntos += 10;
					jugador->eliminar_bala(b--);
					pos_saludable = sa;
				}
				else {
					sonido = false;
				}

			}

		}


	}
	void colision_policia_saludable(Graphics^ g, Bitmap^ img, int ancho1, int alto1) {
		Rectangle saludable;
		Rectangle policia;
		if (getVerde() == true) {
			Mostrar_Policia(g, img);
			Mover_Policia(ancho1, alto1, pos_saludable);
			policia = Rectangle(poli->getX(), poli->getY(), poli->getAncho(), poli->getAlto());
			saludable = Rectangle(salu->getSaludable(getPos_Saludable())->getX(), salu->getSaludable(getPos_Saludable())->getY(), salu->getSaludable(getPos_Saludable())->getAncho(), salu->getSaludable(getPos_Saludable())->getAlto());

			if (policia.IntersectsWith(saludable)) {

				verde = false;
				capturados++;
				poli->setXY();
				salu->eliminar_Saludable(pos_saludable);
				
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
			for (int asinto = 0; asinto < ene->getcantidad_asintomatico(); ++asinto)
			{

				enemy = Rectangle(ene->getAsintomatico(asinto)->getX(), ene->getAsintomatico(asinto)->getY(), ene->getAsintomatico(asinto)->getAncho(), ene->getAsintomatico(asinto)->getAlto());
				if (bala.IntersectsWith(enemy))
				{
					sonido = true;
					rojo = true;
					pos_asinto = asinto;
					jugador->eliminar_bala(b--);

					puntos += 10;

				}
				else {
					sonido = false;
				}


			}

		}

	}
	void colisionambulancia_asi(Graphics^ g, Bitmap^ img, int ancho_form, int alto_form) {
		Rectangle asinto;
		Rectangle ambulancia;
		if (getRojo() == true) {
			Mostrar_ambulancia1(g, img);
			Mover_ambulncia1(pos_asinto, ancho_form, alto_form);
			ambulancia = Rectangle(ambu->getX(), ambu->getY(), ambu->getAncho(), ambu->getAlto());
			asinto = Rectangle(ene->getAsintomatico(getPos_Asinotmatico())->getX(), ene->getAsintomatico(getPos_Asinotmatico())->getY(), ene->getAsintomatico(getPos_Asinotmatico())->getAncho(), ene->getAsintomatico(getPos_Asinotmatico())->getAlto());

			if (ambulancia.IntersectsWith(asinto)) {
				rojo = false;
				capturados++;
				ambu->setXY();
				ene->eliminar_asintomatico(pos_asinto);
		
			}
		}
	}
	void cambiar_rojo(Graphics^ g, Bitmap^ img) {
		if (getRojo() == true) {
			ene->getAsintomatico(getPos_Asinotmatico())->setMostrar(g, img);
		}
	}
	void cambiar_verde(Graphics^ g, Bitmap^ img) {
		if (getVerde() == true) {
			salu->getSaludable(getPos_Saludable())->setMostar(g, img);
		}
	}
	void GuardarTodo() {
		salu->guardarTodo();
		ene->guardarTodo();
		jugador->GuardarTodo();
		ambu->GuardarTodo();
		poli->GuardarTodo();
	}
	
	

};