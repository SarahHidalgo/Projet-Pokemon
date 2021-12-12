#include "pokemon.h"
#include "typespokemon.h"
#include "bestiaire.h"
#include "Pokedex.h"
#include <iostream>
using namespace std;


int main()
{
	EspecePokemon bestiaire[150];
	initBestiaire(bestiaire);
	const char* typesLabel[18] = { "Normal", "Fighting", "Flying", "Poison", "Ground", "Rock", "Bug", "Ghost", "Steel", "Fire", "Grass", "Water", "Electric",
	"Psychic", "Ice", "Dragon", "Dark", "Fairy" };
	Pokedex* pokedex = initPokedex(3);
	Pokemon a;
	a.nom = "Seadra";
	a.XP = 1;
	a.CP = 4;
	a.evolution = 1;
	a.PV = 23;
	Pokemon b;
	b.nom = "Arbok";
	b.XP = 0;
	b.CP = 123;
	b.evolution = 2;
	b.PV = 134;
	Pokemon c;
	c.nom = "Zubat";
	c.XP = 40;
	c.CP = 300;
	c.evolution = 1;
	c.PV = 223;
	Pokemon d;
	d.nom = "Paras";
	d.XP= 0;
	d.CP = 23;
	d.evolution = 1;
	d.PV = 90;
	Pokemon e;
	e.nom = "Arkanine";
	e.XP = 0;
	e.CP = 23;
	e.evolution = 2;
	e.PV = 290;
	insertPokemon(&pokedex, a);
	cout << "******* Pokedex after inserting pokemon a *********" << endl;
	displayPokedex(pokedex, bestiaire, typesLabel);
	cout << "***************************************************" << endl;
	cout << endl << endl;
	insertPokemon(&pokedex, b);
	cout << "******* Pokedex after inserting pokemon b *********" << endl;
	displayPokedex(pokedex, bestiaire, typesLabel);
	cout << "***************************************************" << endl;
	cout << endl << endl;
	insertPokemon(&pokedex, c);
	cout << "******* Pokedex after inserting pokemon c *********" << endl;
	displayPokedex(pokedex, bestiaire, typesLabel);
	cout << "***************************************************" << endl;
	cout << endl << endl;
	insertPokemon(&pokedex, d);
	cout << "******* Pokedex after inserting pokemon d *********" << endl;
	displayPokedex(pokedex, bestiaire, typesLabel);
	cout << "***************************************************" << endl;
	cout << endl << endl;
	insertPokemon(&pokedex, e);
	cout << "******* Pokedex after inserting pokemon e *********" << endl;
	displayPokedex(pokedex, bestiaire, typesLabel);
	cout << "***************************************************" << endl;
	cout << endl << endl;
}