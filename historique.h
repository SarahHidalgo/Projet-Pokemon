#pragma once
typedef struct Evolution
{
	const char*  from;
	const char* to;
	Evolution* nextEvol;
} Evolution;


typedef struct Historique 
{
	int nombre;
	Evolution* debut;
} Historique;

void insertionliste(Evolution *evolution,Historique *historique, Pokemon* p, EspecePokemon bestiaire[150]);
void afficherListe(Historique* historique);