#include "bestiaire.h"
#include "pokemon.h"
#include "typespokemon.h"
#include "Pokedex.h"
#include "utils.h"
#include <iostream>
using namespace std;

Pokedex* initPokedex(const int size)
{
	Pokedex* monPokedex = (Pokedex*)malloc(sizeof(Pokedex)); //new Pokedex (autres façons de faire)
	//le pointeur pokedex pointe vers la structure Pokedex
	monPokedex->mesPokemons = new Pokemon[size]; // (Pokemon*)malloc(sizeof(Pokemon) * size) 
	monPokedex->nb = 0;
	monPokedex->capacity = size;

	return monPokedex;
}

void insertPokemon(Pokedex* pokedex, Pokemon p)
{
	if (pokedex->nb == pokedex->capacity)
	{
		//creation du nouveau Pokedex
		const int new_capacity = (int)pokedex->capacity * 1.5;
		Pokemon* newPokedex = new Pokemon[new_capacity];
		//on met l'ancien Pokedex dans le nouveau
		for (int i = 0; i < pokedex->nb; i++)
		{
			newPokedex[i] = pokedex->mesPokemons[i];
		}
		// le tableau de pokemons devient celui nouvellement construit contenant les anciens pokemons.
		delete[] pokedex->mesPokemons;
		pokedex->mesPokemons = newPokedex;

		// sa capacite est mise à jour
		pokedex->capacity = new_capacity;
	}
	//on ajoute le pokemon de manière triée
	if (pokedex->nb == 0)
	{
		pokedex->mesPokemons[0] = p;
	}
	else
	{
		//faut trouver la position du new pokemon
		int i=0;
		while (i < pokedex->nb && strcmp(pokedex->mesPokemons[i].nom, p.nom) < 0)
		{
			i++;
		}

		//on insère le pokemon dans le pokedex
		if (i == pokedex->nb)
		{
			pokedex->mesPokemons[i] = p;
		}
		else
		{//on effectue un décalage à droite des éléments
			for (int j = pokedex->nb - 1; j >= i; j--)
			{
				pokedex->mesPokemons[j + 1] = pokedex->mesPokemons[j];
			}
			pokedex->mesPokemons[i] = p;
		}
	}
	pokedex->nb = pokedex->nb + 1;
}

void displayPokedex(Pokedex * pokedex, EspecePokemon bestiaire[150], const char* typesLabel[18], Ressource Ressources)
{
	cout << "-----------------------" << endl;
	cout << endl << "Mes ressources : " << endl;
	cout << Ressources.candies << " bonbons " << endl;
	cout << Ressources.stardust << " poussieres d'etoiles " << endl;
	cout << "-----------------------" << endl;
	cout << endl << "Contenu du pokedex (Actuellement ";
	cout << pokedex->nb << " pokemons captures)" << endl;
	for (int i = 0; i < pokedex->nb; i++)
	{
		display(pokedex->mesPokemons[i], bestiaire, typesLabel);
		cout << "-----------------------" << endl;
	}
}

Pokemon genererPokemon(EspecePokemon bestiaire[150],const char* typesLabel[18])
{
	int num_pokemon = random_at_most(149); /*tirage aléatoire du num de l'espece dans le bestiaire*/
	EspecePokemon esp;
	do
	{
		num_pokemon = random_at_most(149);
	} while (bestiaire[num_pokemon].estEvolue);
	//esp = bestiaire[num_pokemon];
	Pokemon p; /*generation d'un pokemon*/
	p.xp = 0;
	p.nom = bestiaire[num_pokemon].nom;
	p.pv = 30 + random_at_most(470); /* donne une valeur entre 30 et 500*/
	p.cp = 200 + random_at_most(800); /* donnne une valeur entre 200 et 1000*/
	p.evolution = 0;
	display(p, bestiaire, typesLabel);

	return p;
}

