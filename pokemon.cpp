#include"pokemon.h"
#include"typespokemon.h"
#include <iostream>
using namespace std;

void evolve(Pokemon* p, const char* Evolution)
{
	const char* anciennom = p->nom;
	p->nom = Evolution;
	p->evolution += 1;
	cout << endl << "Félicitations, votre " << anciennom << " est devenu un " << Evolution << " ! " << endl << endl;
}

void Powerup(Pokemon* p)
{
	p->cp = (int)(p->cp*1.25);
}

void display(const Pokemon p, EspecePokemon bestiaire[150], const char* typesLabel[18])
{
	cout << endl;
	cout << p.nom << " est du type : ";

	EspecePokemon esp = entierBestiaire(bestiaire, p.nom);
	cout << typesLabel[esp.type] << endl;
	cout << "XP : " << p.xp << endl;
	cout << "Evolution : " << p.evolution << endl;
	cout << "PV : " << p.pv << endl;
	cout << "CP : " << p.cp << endl;

	
}