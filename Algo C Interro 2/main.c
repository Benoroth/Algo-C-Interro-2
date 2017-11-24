#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Mastermind
{
    int combiADeviner[4];
    int essaisRestant;
    int partiesWin;
    int partiesLost;
    int combiJoueur[4];
};

int testCombinaison(struct Mastermind joueur)
{
    int i;
    int pieceBP; //bien plac�e
    int pieceMP; //mal plac�e
    pieceBP=0;  //le nombre de fois o� la condition est valid�e
    pieceMP=0;  //
//On doit faire la somme du nombre de pieces mal/bien plac�es

    for (i=0; i>4; i++)
    {
        while (joueur.combiJoueur[i]==joueur.combiADeviner[i]) //On v�rifie si la piece n�i est la m�me que celle � deviner
        {
            pieceBP++;      //On ajoute 1 au compteur de pieces bien plac�es
        }
        while (joueur.combiJoueur!=joueur.combiADeviner)
        {
            pieceMP++;      //On ajoute 1 au compteur de pi�ces mal plac�es
        }
    }
    return printf("Il y a %d pieces bien placees et %d mal placees\n",pieceBP,pieceMP); //On informe le joueurdu nombre de pieces bien/mal plac�es
}
int main()
{
    srand(time(NULL));
    int i,j,k;
    int joueurJoue;
    joueurJoue=1;

//On d�clare une structure joueur
    struct Mastermind joueur;
    //On initialise la structure
    joueur.essaisRestant=10;
    joueur.partiesLost=0;
    joueur.partiesWin=0;

//On g�n�re la combinaison � deviner
    for (i=0; i<4; i++)
    {
        joueur.combiADeviner[i]= rand()%10 ;
    }

//On joue tant qu'on a pas d�couvert la combinaison et tant qu'il nous reste des essais
    while (joueur.essaisRestant!=0 && joueur.combiJoueur!=joueur.combiADeviner && joueurJoue!=0)
    {
//On demande au joueur ses chiffres
        for (j=0; j<4; j++)
        {
            printf(" Choisis le chiffre a la position %d :\n", j+1);
            scanf("%d", &joueur.combiJoueur[j]);
        }
        //On affiche le tableau
        printf("Tu as choisi :\n");

        for (k=0; k<4; k++)
        {
            printf("[%d]  \n", joueur.combiJoueur[k]);
        }
        joueur.essaisRestant--;
        printf("Il te reste %d essais !\n", joueur.essaisRestant);
//On compare avec l'ordinateur
//On doit faire la somme du nombre de pieces mal/bien plac�es


//        while (joueur.combiJoueur!=ordi.combiADeviner)
//        {
//            pieceMP++;
//            return pieceMP;
//        }
//        while (joueur.combiJoueur==ordi.combiADeviner)
//        {
//            pieceBP++;
//            return pieceBP;
//        }
//        printf("Tu as %d pieces bien placees et %d mal placees", pieceBP, pieceMP);
//
//    }

        testCombinaison(joueur);

        if (joueur.essaisRestant==0)
        {
            printf("Tu n'as plus d'essais, tu as donc perdu la partie.\n");
            joueur.partiesLost++;
            printf("Veux tu rejouer ? Oui=1  Non =0\n");
            scanf("%d", &joueurJoue);
            joueur.essaisRestant=10;
        }

        else if (joueur.combiJoueur==joueur.combiADeviner)
        {
            printf("Felicitations tu as gagne une partie !\n");
            joueur.partiesWin++;
            printf("Veux tu rejouer ? Oui=1  Non =0\n");
            scanf("%d", &joueurJoue);
            joueur.essaisRestant=10;
        }
    }
    printf("Au final tu as gagne : %d fois et perdu :%d fois", joueur.partiesWin, joueur.partiesLost);

    return 0;
}




//je desesp�re du coup j'ai plus le temps de tester une boucle while o� � chaque fois d'une valeur de tableau = l'autre on incr�ment le compteur de piece bien/mal placees
