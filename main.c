#include <stdio.h>
#include "patient.h"
#include "consultation.h"
#include "menu.h"

int main(){
    int choix;
    Patient p;
    Data *tete =  NULL ;
    Consultation c;
    Consulter *ABR = NULL;

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
                tete = SupprimerPatient(tete);
                break;
            case 4:
                Recherche(tete);
                break;

            case 5:
                SaisirConsultation(tete,&c);
                ABR = AjouterConsultation(ABR, c);

                printf("\nNOM : %s\n", ABR->donne.diagnostic);
                break;
            case 6:
                ABR=RechercherConsultation(tete, ABR, c);
                break;
            
            case 0: 
                LibererData(tete);
                printf("Fin du programme.\n");
                break;

            default:
                printf("Choix invalide !\n");
        }

    }while(choix != 0);

    return 0;
}
