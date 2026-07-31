# ifndef PATIENT_H
# define PATIENT_H

//Structure d'un patient 
typedef struct{
    int id;
    char nom[51];
    char prenom[51];
    int age;
    char sexe;
    char groupeSanguin[5];
}Patient;

//Liste construit pour les patient;
typedef struct Tdatat{
    Patient donne;
    struct Tdata *suivant;
}Data;

//Creation d'un patient
Data *CreerPatient(Patient p);

//Ajout d'un nouvel patient
void SaisirInfoPatient(Patient p);
Data *AjouterPatient(Data *tete, Patient p);

//Recherche d'un patient par son identifiant
Data *Recherche(Data *tete, Patient p);

//Modification des donne d'un patient par son id
Data *ModifierInfo(Data *tete, Patient p );

//Suppression d'un pation a partir de son id
Data *Supprimer(Data *tete, Patient p);

//Fin du programme liberation de maloc
Data *LibererData(Data *tete);


# endif