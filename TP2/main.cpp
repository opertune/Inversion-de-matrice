/* MatriceInvers�e
* Saisir une matrice et afficher son inversion
* Date : 09/01/2020
* Author : Romain
*/

#include <iostream>
#include <myconio.h>
#include <string.h>

using namespace std;
#define n 3
int main()
{
// D�claration
float mdep[n][n]; // Matrice de d�part
float mid[n][n] {0}; // Matrice identit�
float mtrans[n][n]; // Matrice de transition
float minv[n][n]; // Matrice invers�e

// Initialisation de la diagonal
for (int i = 0; i < n; i++){
    mid[i][i] = 1;
}
// Affichage de la matrice vide
cout << ".     .     ." << endl << ".     .     ." << endl << ".     .     .";

// Saisie des valeurs dans la matrice de d�part
for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
        gotoxy(i*6+1, j*1+1);
        cin >> mdep[i][j];
    }
}

// Copie de la matrice de d�part dans la matrice de transition
memcpy(mtrans, mdep, sizeof mdep);

// Copie de la matrice identit�e dans la matrice invers�e
memcpy(minv, mid, sizeof mid);

// Traitement
for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
            // Si une valeur null se trouve sur la diagonale
            if(mdep[i][i] == 0){
                gotoxy(15, 4);
                cout << "Inversion impossible";
                    return 0;
            }
            mtrans[i][j] = (mdep[i][j] / mdep[i][i]);
            mid[i][j] = (minv [i][j] / mdep[i][i]);
    }
            // Copie de la matrice de transition dans la matrice de d�part
            memcpy(mdep, mtrans, sizeof mtrans);
            // Copie de la matrice identit� dans la matrice invers�e
            memcpy(minv, mid, sizeof mid);
                    for (int k = 0; k < n; k++){
                            if (k != i){
                                for (int j = 0; j < n; j++){
                                    mtrans[k][j] = (mdep[k][j] - (mdep[i][j]*mdep[k][i]));
                                    mid[k][j] = (minv[k][j] - (minv[i][j] * mdep[k][i]));
                                }
                            }
                }
// Copie de la matrice de transition dans la matrice de d�part
// et la matrice identit� dans la matrice invers�e
memcpy(mdep, mtrans, sizeof mtrans);
memcpy(minv, mid, sizeof mid);
}

// Affichage de la matrice invers�e
for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
        gotoxy(i*6+1, j+7);
        cout << minv[i][j];
    }
}

return 0;
}
