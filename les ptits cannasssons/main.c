/*************************************
* PROJET  : LES PETITS CANASSONS     *
* VERSION : 0.1                      *
* DATE    : 02/02/2020               *
*************************************/

// DECLARATION DES #INCLUDE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


// DECLARATION DES CONSTANTES
#define L 2
#define C 17

// DECLARATION DES PROTOTYPES
int age(void);
int de(void);
int ecurie(int joueur, int face);
int choix(int typechoix);
int resteJ, resteV;
int afficher_tableau(void);
int joueurTour(void);
int possibilite(int reste, int face);
int lancerde(void);

// DECLARATION DES VARIABLES GLOBALES
int premier, face, decision, joueur1, joueur2, encours, resteJ, resteV, inutile; //initialisation des variables
int plateau[L][C];                 //initialisation du plateau de jeu


// PROGRAMME PRINCIPAL

int main()
{
    resteJ=2;
    resteV=2;
    printf("\n     Bienvenue dans le jeu des petits canassons !\n");
    srand(time(NULL)); //initialisation de la fonction random

    premier=age(); //le premier joueur à jouer
    Sleep(1000);
    printf("\n\n\n\n\n\n\n\n                                      Debut de la partie dans 3   ");
    Sleep(1000);
    printf("2   ");
    Sleep(1000);
    printf("1   ");
    Sleep(1000);
    system("cls");

    afficher_tableau();

    ecurie(encours,face);
    ecurie(encours,face);
    ecurie(encours,face);
    ecurie(encours,face);
    ecurie(encours,face);

    return 0;
}

// FONCTIONS PRIVEES

int age (void)
{
    int premier;
    unsigned int age1, age2;
    printf("\n     Age du joueur 1 : ");
    scanf("%i",&age1);
    printf("     Age du joueur 2 : ");
    scanf("%i",&age2);

    if (age1 < age2)
    {
        printf("\n    Le joueur 1 commence et il est dans l'equipe Jaune!");
        premier = 1;
    }

    if (age1 > age2)
    {
        printf("\n    Le joueur 2 comence et il est dans l'equipe Jaune!");
        premier = 2;
    }
    if (age1 == age2)
    {
        int a;
        a=rand()%2;

        if (a==0)
        {
            printf("\n     Le joueur 1 commence et il est dans l'equipe Jaune!");
            premier = 1;
        }
        if (a==1)
        {
            printf("\n     Le joueur 2 comence et il est dans l'equipe Jaune!");
            premier = 2;
        }
    }
    return premier;
}


int de(void)
{
    int face;
    face=rand()%6 +1;
    return face;
}
int ecurie(int joueur, int face)
{
    int reste;

    printf("Lancement du de.");
    face=lancerde();
    reste = resteJ;
    possibilite(reste,face);

    printf("Lancement du de.");
    face=lancerde();
    reste=resteV;
    possibilite(reste,face);

    return 0;
}
int choix(int typechoix)
{
    int option;

    if (typechoix==1)
    {
            while ((option!=1)||(option!=2)||(option!=3))
        {
            printf("Vous avez le choix entre :\n");
            printf("Tapez 1 pour sortir un pion\n");
            printf("Tapez 2 pour bouger l'autre pion \n");
            printf("Tapez 3 pour ne rien faire\n");
            scanf("%d", &option);
        }
        switch (option)
        {
            case 1 : printf("Vous avez sorti un pion\n");
                    break;

            case 2 : printf("Vous avez bougé votre pion\n");
                    break;

            case 3 : printf("Vous avez choisi de ne rien faire\n");

            default : printf("Tapez 1, 2 ou 3");

        }
        if(typechoix==2)
        {
            //while ((option!=1)||(option!=2))
            //{
                printf("Vous avez le choix entre :\n");
                printf("Tapez 1 pour sortir le pion\n");
                printf("Tapez 2 pour ne rien faire\n");
                scanf("%d", &option);
            //}
            switch(option)
            {
                case 1 : printf("Vous avez choisi de sortir le pion\n");
                break;

                case 2 : printf("Vous avez choisi de ne rien faire\n");
                break;

                default : printf("Tapez 1 ou 2");
            }
        }
        if (typechoix==3)
        {
            while ((option!=1)||(option!=2)||(option!=3))
            {
                printf("Vous avez le choix entre :\n");
                printf("Tapez 1 pour bouger le pion 1\n");
                printf("Tapez 2 pour bouger le pion 2\n");
                printf("Tapez 3 pour ne rien faire\n");
                scanf("%d", &option);
            }
            switch(option)
            {
                case 1 : printf("Vous avez choisi de bouger le pion 1\n");
                break;

                case 2 : printf("Vous avez choisi de bouger le pion 2\n");
                break;

                case 3 : printf("Vous avez choisi de ne rien faire\n");
                break;

                default : printf("Tapez 1, 2 ou 3");
            }
        }
    }
    return option;
}

int afficher_tableau(void)
{
    int i,j;

    for (i=0;i<L;i++)
    {
        printf("\n\n");
        for(j=0;j<C;j++)
        {
            if (plateau[i][j] == 0)
            {
                printf(" ");
            } else
            {
                printf("#");
            }
            printf("|");
        }
    }
    printf("\n");
    return 0;
}
int possibilite(int reste,int face)
{
    if (reste==2)
    {
        if (face!=6)
            printf("Vous ne pouvez sortir aucun canasson...\n");
        else
        {
            decision=choix(2);
        }
    }
    if (reste==1)
    {
        if (face!=6)
            decision=choix(1);//appeler fonction bouger pion
        else
        {
            decision=choix(1); //sotir ou bouger un pion ou rien faire

        }
    }
    if (reste==0)
    {
        decision=choix(3);
    }
    return decision;
}
int lancerde(void)
{
    face=de();
    Sleep(600);
    printf(".");
    Sleep(600);
    printf(".");
    Sleep(600);
    printf("\nVous avez fait %d\n", face);
    Sleep(2000);
    return face;
}

