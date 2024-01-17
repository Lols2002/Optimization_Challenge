#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nb_lignes;
    int nb_colonnes;
    int **matrice_adjacence;
} Grille;

void lecture_fichier(Grille *G);
void remplissage_mat_surv(Grille *G, int **matrice_cible, int **matrice_surveillant);
bool sont_couvertes(int **matrice_cible, Grille *G);
int calcul_nbre_cible_par_lignes(int ligne, int colonne, int **matrice_cible, int **matrice_surveillant, int nbre_colonne, Grille *G);
int calcul_nbre_cible_par_colonnes(int colonne, int ligne, int **matrice_cible, int **matrice_surveillant, int nbre_ligne, Grille *G);
void max_surv(int **matrice_surveillant, int nbre_lignes, int nbre_colonnes, int *max_i, int *max_j);
void couvrir_par_colonnes(int colonne, int ligne, int **matrice_cible, int **matrice_surveillant, int nbre_ligne, Grille *G);
void couvrir_par_lignes(int ligne, int colonne, int **matrice_cible, int **matrice_surveillant, int nbre_colonne, Grille *G);
int nbre_surv(Grille *G, int **matrice_cible, int **matrice_surveillant);

#endif