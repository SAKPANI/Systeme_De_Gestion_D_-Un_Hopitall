#include <stdio.h>
#include "patient.h"
#include "menu.h"

int main(){
    int choix;
    Patient p;
    Data *tete =  NULL ;

    do{
        Menu();
        printf("Votre Choix:");
        scanf("%d", &choix);
        switch(choix){

            case 1:
                SaisirInfoPatient(&p);
                tete= AjouterPatient(tete, p);
                printf("\nPatient ajoute avec succes !\n");
                break;

            case 2:
                tete=ModifierInfoPatient(tete);
                break;
            
            case 3:
                tete =SupprimerPatient(tete);
                break;
              
            case 4:
                Recherche(tete);
                break;
            


            case 0:
                printf("Fin du programme.\n");
                break;

            default:
                printf("Choix invalide !\n");
        }

    }while(choix != 0);

    return 0;
}
