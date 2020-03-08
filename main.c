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
#include <ctype.h>


// DECLARATION DES CONSTANTES
#define LC 34

// DECLARATION DES PROTOTYPES
int age(void); //Détermine le joueur le plus jeune
int tour(void); //Lance un tour
int possibilite(int situation); //Propose les différents possibilités possibles selon la situation
int afficher_tableau(void); //Affiche le plateau de jeu
int choixJ(int reste, int face); //Détermine le choix effectué par le joueur jaune
int choixV(int reste,int face);//Détermine le choix effectué par le joueur vert
int lancerDe(void); //Simule un lancer de dé
int finTour(void); //Clos le tour
void color(int couleurDuTexte, int couleurDuFond);//Donne la couleur du texte et du fond
void clean_stdin(void); //Vide le buffer
void initplateauJ(int pion);//Initialise le plateau pour le pion Jaune
void initplateauV(int pion);//Initialise le plateau pour le pion Vert
int deplacement(int face, int pion);//Déplace les pions de x cases en fonction de la position precedente (i,j)

// DECLARATION DES VARIABLES GLOBALES
int face; //Initialisation des variables
int plateau[LC];  //initialisation du plateau de jeu
int resteJ=2; //Initialisation du nombre de pion Jaune restant en dehors du plateau
int resteV=2; //Initialisation du nombre de pion Vert restant en dehors du plateau
int reste, reste1, reste2;
int arriveeJ=0;
int arriveeV=0;

// PROGRAMME PRINCIPAL

int main()
{
    system("color F0");
    printf("\n     Bienvenue dans le jeu des petits canassons !\n");
    srand(time(NULL)); //initialisation de la fonction random

    age(); //le premier joueur à jouer
    printf("\n     Appuyez sur ENTER pour continuer...");
    fflush(stdin);
    while (getchar() != '\n')
        ;
    printf("\n\n\n\n\n\n\n                                      Debut de la partie dans 3   ");
    Sleep(1000);
    printf("2   ");
    Sleep(1000);
    printf("1   ");
    Sleep(1000);
    system("cls");

    while ((arriveeJ!=2)&&(arriveeV!=2))
    {
       tour();
    }
    if (arriveeJ == 2)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n");
        printf("                         ");
        color(0,14);
        printf("Bravo au joueur Jaune qui remporte la partie!!!");
        color(0,15);
        printf("\n\n\n\n\n\n\n");
    }
    if (arriveeV == 2)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n");
        printf("                         ");
        color(0,2);
        printf("Bravo au joueur Vert qui remporte la partie!!!");
        color(0,15);
        printf("\n\n\n\n\n\n\n");
    }
    if ((arriveeJ == 2)&&(arriveeV == 2))
    {
        system("cls");
        printf("\n\n\n\n\n\n\n");
        printf("                         ");
        color(0,12);
        printf("Personne ne gagne, il y a egalite");
        color(0,15);
        printf("\n\n\n\n\n\n\n");
    }


    return 0;
}

// FONCTIONS PRIVEES

int age (void)
{
    int age1, age2;


    printf("\n     Age du joueur 1 : ");
    scanf("%d",&age1);
    if (age1<3)
    {
        color(12,15);
        printf("\nWARNING : vous etes trop jeune pour jouer\n");
        color(0,15);
        printf("\n     Appuyez sur ENTER pour continuer à jouer a vos risques et perils...\n");
        fflush(stdin);
        while (getchar() != '\n');
    }
    printf("     Age du joueur 2 : ");
    scanf("%d",&age2);
    if (age2<3)
    {
        color(12,15);
        printf("\nWARNING : vous etes trop jeune pour jouer\n");
        color(0,15);
        printf("\n     Appuyez sur ENTER pour entrer dans la matrice...\n");
        fflush(stdin);
        while (getchar() != '\n');
    }

    if (age1 < age2)
    {
        printf("\n     Joueur 1 commence, il joue les ");
        color(0,14);
        printf("Jaunes");
        color(0,15);
        printf("\n     Joueur 2 joue les ");
        color(0,2);
        printf("Verts\n");
        color(0,15);
    }

    if (age1 > age2)
    {
        printf("\n     Joueur 2 commence, il joue les ");
        color(0,14);
        printf("Jaunes");
        color(0,15);
        printf("\n     Joueur 1 joue les ");
        color(0,2);
        printf("Verts\n");
        color(0,15);
    }
    if (age1 == age2)
    {
        int a;
        a=rand()%2;

        if (a==0)
        {
            printf("\n     Joueur 1 commence, il joue les ");
            color(0,14);
            printf("Jaunes");
            color(0,15);
            printf("\n     Joueur 2 joue les ");
            color(0,2);
            printf("Verts\n");
            color(0,15);
        }
        if (a==1)
        {
            printf("\n     Joueur 2 commence, il joue les ");
            color(0,14);
            printf("Jaunes");
            color(0,15);
            printf("\n     Joueur 1 joue les ");
            color(0,2);
            printf("Verts\n");
            color(0,15);
        }
    }
    return 0;
}

int tour(void)
{
    afficher_tableau();
    printf("\n                  ");
    color(0,14);
    printf("Au tour de l'equipe Jaune !\n\n");
    color(0,15);
    printf("Vous avez encore %d pion(s) dans l'ecurie\n", resteJ);
    printf("\nLancement du de.");
    face=lancerDe();
    choixJ(resteJ,face);
    resteJ=reste1;
    finTour();

    afficher_tableau();
    printf("\n                  ");
    color(0,2);
    printf("Au tour de l'equipe Verte !\n\n");
    color(0,15);
    printf("Vous avez encore %d pion(s) dans l'ecurie\n", resteV);
    printf("\nLancement du de.");
    face=lancerDe();
    choixV(resteV,face);
    resteV=reste2;
    finTour();

    return 0;
}

int choixJ(int reste,int face)
{
    int decision;
    reste1=reste;
    if (reste==2)
    {
        if (face!=6)
            printf("\n    INFO : Vous ne pouvez sortir aucun canasson.\n");
        else
        {
            decision=possibilite(1); //sortir pion ou ne rien faire
            if (decision == 1)
            {
                if (plateau[17] == 0)
                {
                initplateauJ(1);
                reste1=resteJ-1;
                }
                else
                {
                    color(12,15);
                    printf("Vous ne pouvez pas sortir de pion car la case est occupee!");
                    color(0,15);
                }
            }
        }
    }
    if (reste==1)
    {
        if (face!=6)
        {
            decision=possibilite(2); //bouger pion ou ne rien faire
            if (decision == 1)
            {
                deplacement(face, 1);
            }
        }
        else
        {
            decision=possibilite(3); //sotir, bouger ou ne rien faire
            if (decision == 1)
            {
               if (plateau[17] == 0)
                {
                initplateauJ(2);
                reste1=resteJ-1;
                }
                else
                {
                    color(12,15);
                    printf("Vous ne pouvez pas sortir de pion car la case est occupee!");
                    color(0,15);
                }
            }
            if (decision == 2)
            {
                deplacement(face, 1);
            }
        }
    }
    if (reste==0)
    {
        decision=possibilite(4); //bouger un des deux pions ou ne rien faire
        if (decision == 1)
        {
            deplacement(face, 1);
        }
        if (decision == 2)
        {
            deplacement(face, 2);
        }
    }
    return decision;
    return reste1;
}

int choixV(int reste,int face)
{
    int decision;
    reste2=reste;
    if (reste==2)
    {
        if (face!=6)
            printf("\n    INFO : Vous ne pouvez sortir aucun canasson.\n");
        else
        {
            decision=possibilite(1); //sortir pion ou ne rien faire
            if (decision == 1)
            {
                if (plateau[0] == 0)
                {
                initplateauV(1);
                reste2=resteV-1;
                }
                else
                {
                    color(12,15);
                    printf("Vous ne pouvez pas sortir de pion car la case est occupee!");
                    color(0,15);
                }
            }
        }
    }
    if (reste==1)
    {
        if (face!=6)
        {
            decision=possibilite(2); //bouger(1) pion ou ne rien faire(2)
            if (decision == 1)
            {
                deplacement(face, 3);
            }
        }
        else
        {
            decision=possibilite(3); //sotir, bouger ou ne rien faire
            if (decision == 1)
            {
                if (plateau[0] == 0)
                {
                initplateauV(2);
                reste2=resteV-1;
                }
                else
                {
                    color(12,15);
                    printf("Vous ne pouvez pas sortir de pion car la case est occupee!");
                    color(0,15);
                }
            }
            if (decision == 2)
            {
                deplacement(face, 3);
            }
        }
    }
    if (reste==0)
    {
        decision=possibilite(4); //bouger un des deux pions ou ne rien faire
        if (decision == 1)
        {
            deplacement(face, 3);
        }
        if  (decision == 2)
        {
            deplacement(face, 4);
        }
    }
    return decision;
    return reste2;
}

int possibilite(int situation)
{
    int option;


    if(situation==1)
    {
        while ((option!=1)&&(option!=2))
        {
            printf("\n         Tapez :\n\n");
            printf("   1 pour sortir le pion\n");
            printf("   2 pour ne rien faire\n");
            scanf("%d", &option);
        }
        switch(option)
        {
            case 1 : printf("Vous avez choisi de sortir le pion\n");
            break;

            case 2 : printf("Vous avez choisi de ne rien faire\n");
            break;

            default : printf("Tapez 1 ou 2");
        }
    }

    if(situation==2)
    {
        while ((option!=1)&&(option!=2))
        {
            printf("\n         Tapez :\n\n");
            printf("   1 pour bouger le pion\n");
            printf("   2 pour ne rien faire \n");
            scanf("%d", &option);
        }
        switch(option)
        {
            case 1 : printf("Vous avez choisi de bouger le pion\n");
            break;

            case 2 : printf("Vous avez choisi de ne rien faire\n");
            break;

            default : printf("Tapez 1 ou 2");
        }
    }
    if (situation==3)
    {
        while ((option!=1)&&(option!=2)&&(option!=3))
        {
            printf("\n         Tapez:\n\n");
            printf("   1 pour sortir un pion\n");
            printf("   2 pour bouger le pion \n");
            printf("   3 pour ne rien faire\n");
            scanf("%d", &option);
        }
        switch (option)
        {
            case 1 : printf("Vous avez choisi de sortir un pion\n");
            break;

            case 2 : printf("Vous avez choisi de bouger votre pion\n");
            break;

            case 3 : printf("Vous avez choisi de ne rien faire\n");
            break;

            default : printf("Tapez 1, 2 ou 3");
        }
    }

    if (situation==4)
    {
        while ((option!=1)&&(option!=2)&&(option!=3))
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
    return option;
}


int afficher_tableau(void)
{
    int i;
    printf("__________________________________");
    printf("\n\n");
    for (i=0;i<LC/2;i++)
    {
        if (plateau[i] == 0)
        {
            printf(" ");
        }
        if (plateau[i] == 1)
        {
            color(0,14); // jaune
            printf("1");
            color(0,15);
        }
        if (plateau[i] == 2)
        {
            color(0,14); // jaune
            printf("2");
            color(0,15);
        }
        if (plateau[i] == 3)
        {
            color(0,2);  // vert
            printf("1");
            color(0,15);
        }
        if (plateau[i] == 4)
        {
            color(0,2);  // vert
            printf("2");
            color(0,15);
        }
        printf("|");
    }
    printf("\n\n");
    for (i=LC-1; i>=LC/2; i--)
    {
        if (plateau[i] == 0)
        {
            printf(" ");
        }
        if (plateau[i] == 1)
        {
            color(0,14); // jaune
            printf("1");
            color(0,15);
        }
        if (plateau[i] == 2)
        {
            color(0,14); // jaune
            printf("2");
            color(0,15);
        }
        if (plateau[i] == 3)
        {
            color(0,2);  // vert
            printf("1");
            color(0,15);
        }
        if (plateau[i] == 4)
        {
            color(0,2);  // vert
            printf("2");
            color(0,15);
        }
        printf("|");
    }
    printf("\n");
    printf("__________________________________\n");
    return 0;
}

int lancerDe(void)
{
    face=rand()%6 +1;
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf("vous avez fait %d !\n", face);
    Sleep(500);
    return face;
}
int finTour(void)
{
    printf("\nAppuyez sur ENTER pour continuer...");
    fflush(stdin);
    while (getchar() != '\n')
    ;
    system("cls");
    return 0;
}
void color (int couleurDuTexte, int couleurDuFond)
{
     HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}
void initplateauJ(int pion)
{
    plateau[17]=pion;
}
void initplateauV(int pion)
{
    plateau[0]=2+pion;
}

int deplacement(int face, int pion)
{
int x, i;

x=0;
for (i=0; i<LC; i++)
        if (plateau[i]== pion)
            x=i;

    if (pion>2)  // pion vert
    {
        if (plateau[x+face] == 0)
        {
            if ((x+face-34)== 0)
            {
                plateau[x]=0;
                color(12,15);
                printf("Bravo, le pion est arrive !");
                color(0,15);
                arriveeV = arriveeV+1;
            }
            else
            {
                plateau[x]=0;
                if (x+face<34)
                plateau[x+face]=pion;
                else
                plateau[x+face-34]=pion;
            }
        }
        else
        {
            color(12,15);
            printf("Vous ne pouvez pas avancer car la case est occupee!");
            color(0,15);
        }

    }
    else  //pion jaune
    {
        if (plateau[x+face] == 0)
        {
            if ((x+face)== 17)
            {
                plateau[x]=0;
                color(12,15);
                printf("Bravo, le pion est arrive !");
                color(0,15);
                arriveeJ = arriveeJ+1;
            }
            else
            {
                plateau[x]=0;
                if (x+face<34)
                plateau[x+face]=pion;
                else
                plateau[x+face-34]=pion;
            }
        }
        else
        {
            color(12,15);
            printf("Vous ne pouvez pas avancer car la case est occupee!");
            color(0,15);
        }
    }
    return arriveeV;
    return arriveeJ;
}

