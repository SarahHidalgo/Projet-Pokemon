#include "pokemon.h"
#include "typespokemon.h"
#include "bestiaire.h"
#include "Pokedex.h"
#include "utils.h"
#include <iostream>
using namespace std;


void printMenu() {
    cout << endl << endl;;
    cout << " 1 - Index des Pokemons" << endl;
    cout << " 2 - Mon Pokedex" << endl;
    cout << " 3 - Attraper un Pokemon" << endl;
    cout << " 4 - Power-up et Evolution" << endl;
    cout << " 5 - Combat" << endl;
    cout << " 6 - Quitter" << endl;
}

void Bestiaire(EspecePokemon bestiaire[]) {
    int newchoice = 0;
    cout << "Choisir l'action à l'action : " << endl;
    cout << "1 - Bestiaire par ordre naturel " << endl;
    cout << "2 - Bestiaire par ordre alphabetique" << endl;
    cout << "3 - Retour au menu principal" << endl;

    do {
        cin >> newchoice;
        if (newchoice != 1 && newchoice != 2 && newchoice != 3) {
            cout << "mauvais choix, saisir 1, 2 ou 3" << endl;
            cout << "saisir 1 ou 2" << endl;
            cin >> newchoice;

        }
    } while (newchoice != 1 && newchoice != 2 && newchoice != 3);

    if (newchoice == 1) {
        initBestiaire(bestiaire);
    }
    else if (newchoice == 2) {
        triBestiaire(bestiaire);
    }
    displayBestiaire(bestiaire);
} 

void powerupAndEvolution(Pokemon p,EspecePokemon bestiaire[150], const char* typesLabel[18]) {
    int newchoice = 0;
    cout << "Choisir l'action à réaliser : " << endl;
    cout << " 1 - Powerup" << endl;
    cout << " 2 - Evolution" << endl;
    cout << " 3 - Retour au menu principal" << endl;

    do {
        cin >> newchoice;
        if (newchoice != 1 && newchoice != 2 && newchoice != 3) {
            cout << "mauvais choix, saisir 1, 2 ou 3";
        }
    } while (newchoice != 1 && newchoice != 2 && newchoice != 3);

    display(p,bestiaire,typesLabel);
    if (newchoice == 1) {
        Powerup(p);
    }
    else if (newchoice == 2) {
        evolve(p);
    }
    cout << "-----------------"<<endl;
    display(p,bestiaire,typesLabel);
}

int main(int argc, const char* argv[]) {
    EspecePokemon bestiaire[150]; /* tableau de 150 EspecePokemon*/
    initBestiaire(bestiaire); /*on initialise le tableau bestiaire*/

    /*Pokemon p;//nitialisation du Pokemon p
    p.PV = 86;
    p.CP = 1500;
    p.XP = 657;
    p.evolution = 2;
    p.nom = "Seadra";*/
    
    const char* typesLabel[18] = { "Normal", "Fighting", "Flying", "Poison", "Ground", "Rock",
         "Bug", "Ghost", "Steel", "Fire", "Grass", "Water", "Electric", "Psychic",
         "Ice", "Dragon", "Dark", "Fairy" };
   
    Pokedex* pokedex = initPokedex(4);
    Pokemon a;
    a.nom = "Seadra";
    a.xp = 1;
    a.cp = 4;
    a.evolution = 1;
    a.pv = 23;

    Pokemon b;
    b.nom = "Arbok";
    b.xp = 0;
    b.cp = 123;
    b.evolution = 2;
    b.pv = 134;

    Pokemon c;
    c.nom = "Zubat";
    c.xp = 40;
    c.cp = 300;
    c.evolution = 1;
    c.pv = 223;

    Pokemon d;
    d.nom = "Paras";
    d.xp = 0;
    d.cp = 23;
    d.evolution = 1;
    d.pv = 90;

    Pokemon e;
    e.nom = "Arkanine";
    e.xp = 0;
    e.cp = 23;
    e.evolution = 2;
    e.pv = 290;

    insertPokemon(pokedex, a);
    cout << "******* Pokedex after inserting pokemon a *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel);
    cout << "***************************************************" << endl << endl << endl;

    insertPokemon(pokedex, b);
    cout << "******* Pokedex after inserting pokemon b *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel);
    cout << "***************************************************" << endl << endl << endl;

    insertPokemon(pokedex, c);
    cout << "******* Pokedex after inserting pokemon c *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel);
    cout << "***************************************************" << endl << endl << endl;

    insertPokemon(pokedex, d);
    cout << "******* Pokedex after inserting pokemon d *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel);
    cout << "***************************************************" << endl << endl << endl;

    insertPokemon(pokedex, e);
    cout << "******* Pokedex after inserting pokemon e *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel);
    cout << "***************************************************" << endl << endl << endl;



    int choice = 6;
   
    cout << "                                   .::.                            " << endl;
    cout << "                                 .;:**'                            " << endl;
    cout << "                                 `                                 " << endl;
    cout << "     .:XHHHHk.              db.   .;;.     dH  MX                  " << endl;
    cout << "   oMMMMMMMMMMM       ~MM  dMMP :MMMMMR   MMM  MR      ~MRMN       " << endl;
    cout << "   QMMMMMb  \"MMX       MMMMMMP !MX' :M~   MMM MMM  .oo. XMMM 'MMM  " << endl;
    cout << "     `MMMM.  )M> :X!Hk. MMMM   XMM.o\"  .  MMMMMMM X?XMMM MMM>!MMP  " << endl;
    cout << "      'MMMb.dM! XM M'?M MMMMMX.`MMMMMMMM~ MM MMM XM `\" MX MMXXMM   " << endl;
    cout << "       ~MMMMM~ XMM. .XM XM`\"MMMb.~*?**~ .MMX M t MMbooMM XMMMMMP   " << endl;
    cout << "        ?MMM>  YMMMMMM! MM   `?MMRb.    `\"\"\"   !L\"MMMMM XM IMMM    " << endl;
    cout << "         MMMX   \"MMMM\"  MM       ~%:           !Mh.\"\"\" dMI IMMP    " << endl;
    cout << "         'MMM.                                             IMX     " << endl;
    cout << "          ~M!M                                             IMP     " << endl << endl;
    cout << "                            - TSE EDITION -                        " << endl;
    
    printMenu();

    do {
        cin >> choice;
        switch (choice) {
        case 1:
            Bestiaire(bestiaire);
            break;
        case 2:
            displayPokedex(pokedex, bestiaire, typesLabel);
            break;
        case 3:
            int newchoice;
            do
            {
                Pokemon p = genererPokemon(bestiaire, typesLabel);
                cout << endl << endl;;
                cout << " Que voulez-vous faire ? " << endl;
                cout << " 1 - Capturer un pokemon" << endl;
                cout << " 2 - Ne pas attraper le pokemon" << endl;

                do
                {
                    cin >> newchoice;
                    if (newchoice != 1 && newchoice != 2)
                    {
                        cout << "Mauvais choix, saisir 1 ou 2" << endl;
                        cout << "Saisir 1 ou 2" << endl;
                        cin >> newchoice;
                    }
                } while (newchoice != 1 && newchoice != 2);

                if (newchoice == 1)
                {
                    int tirage = random_at_most(100);
                    if (tirage > 60)
                    {
                        insertPokemon(pokedex, p);
                        cout << "Vous avez attraper le pokemon " << endl;
                    }
                    else
                    {
                        cout << "Vous n'avez pas reussi a attraper le pokemon" << endl;
                    }
                }
                else if (newchoice == 2)
                {
                    cout << " Que voules-vous faire ?" << endl;
                    cout << "1 - Attraper un autre pokemon " << endl;
                    cout << "2 - Revenir au menu principal " << endl;
                    cin >> newchoice;
                    if (newchoice == 2)
                    {
                        newchoice = 3;
                    }
                }

            } while (newchoice != 3);
            displayPokedex(pokedex, bestiaire, typesLabel);
            break;
        case 4:
            powerupAndEvolution(a, bestiaire, typesLabel);
            break;
        case 5:
            break;
        case 6:
            std::cout << "Good bye, we will ctach 'em all later!\n";
            return 0;
        default:
            cout << "Veuillez saisir une entrée entre 1 et 6.";
            break;
        }
        printMenu();
    } while (choice != 6);

    std::cout << "Good bye, we will catch 'em all later!\n";
    return 0;
}
