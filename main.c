#include "functions.h"

int main()
{
    Grille G;
    lecture_fichier(&G);
    int res;
    
    // matrice cible
    int **matrice_cible = (int **)malloc(G.nb_lignes * sizeof(int *));
    for (int i = 0; i < G.nb_lignes; i++)
    {
        matrice_cible[i] = (int *)malloc(G.nb_colonnes * sizeof(int));
    }

    for (int i = 0; i < G.nb_lignes; i++)
    {
        for (int j = 0; j < G.nb_colonnes; j++)
        {
            matrice_cible[i][j] = 0; // toutes les cibles sont non couvertes
        }
    }

    // matrice surveillant
    int **matrice_surveillant = (int **)malloc(G.nb_lignes * sizeof(int *));
    for (int i = 0; i < G.nb_lignes; i++)
    {
        matrice_surveillant[i] = (int *)malloc(G.nb_colonnes * sizeof(int));
    }

    for (int i = 0; i < G.nb_lignes; i++)
    {
        for (int j = 0; j < G.nb_colonnes; j++)
        {
            if (G.matrice_adjacence[i][j] == -1)
            {
                matrice_surveillant[i][j] = -1; // -1 cad le surveillant ne peut pas prendre cette position
            }
            else
            {
                matrice_surveillant[i][j] = 1; //   1 il peut la prendre
            }
        }
    }
    // printf("cc \n");

    res = nbre_surv(&G, matrice_cible, matrice_surveillant);
    printf("%d", res);
    free(matrice_cible);
    free(matrice_surveillant);

    return 0;
}
