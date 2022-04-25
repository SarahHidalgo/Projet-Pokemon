#include "pokemon.h"
#include "typespokemon.h"
#include "bestiaire.h"
#include "Pokedex.h"
#include "utils.h"
#include "historique.h"
#include <iostream>
using namespace std;


void insertionliste(Evolution *evolution, Historique *historique, Pokemon* p, EspecePokemon bestiaire[150])
{
	int i = 0;
	while (strcmp(bestiaire[i].nom, p->nom) != 0 && i < 150) 
	{
		i++;
	}

	if (evolution->to == NULL) 
	{
		evolution->from = bestiaire[i].nom;
		evolution->to = bestiaire[i].evolvesTo;
		historique->debut = evolution;
	}
	else 
	{
		Evolution* nouveau = (Evolution*)malloc(sizeof(struct Evolution));
		nouveau->from = bestiaire[i].nom;
		nouveau->to= bestiaire[i].evolvesTo;
		nouveau->nextEvol = evolution;
		historique->debut = nouveau;
	}
	historique->nombre += 1;
}

void afficherListe(Historique* historique)
{
	Evolution* actuel = historique->debut;

	cout << historique->nombre;
	cout << " -> ";

	while (actuel != NULL)
	{
		cout << actuel->from;
		cout << " -> ";
		cout << actuel->to;
		cout << " -> ";
		actuel = actuel->nextEvol;
	}
	
}