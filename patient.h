#ifndef PATIENT_H
#define PATIENT_H

//Structure d'un patient
typedef struct{
    int id;
    char nom[51];
    char prenom[51];
    int age;
    char sexe[2];
    char groupeSanguin[5];
}Patient;


//Liste construit pour les patient;
typedef struct Tdata{
    Patient donne;
    struct Tdata *suivant;
}Data;


//Creation d'un patient
Data *CreerPatient(Patient p);

//Ajout d'un nouvel patient
void SaisirInfoPatient(Patient *p);

Data *AjouterPatient(Data *tete, Patient p);

//Recherche d'un patient par son identifiant
void Recherche(Data *tete);

// //Modification des donne d'un patient par son id
 Data *ModifierInfoPatient(Data *tete);

// //Suppression d'un pation a partir de son id
Data *SupprimerPatient(Data *tete);

// //Fin du programme liberation de maloc
Data *LibererData(Data *tete);


# endif
