 /* This file is part of strassen.
*  
*     strassen is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    Foobar is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with Foobar.  If not, see <http://www.gnu.org/licenses/>. 
*/
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include "strassen_impl.h"
#include <sys/resource.h>
#include <time.h>

double temps_CPU() {
	struct rusage usage;
	getrusage(RUSAGE_SELF, &usage);
	return usage.ru_utime.tv_sec + (usage.ru_utime.tv_usec / 1000000.0);
}

int main() {
	double START, END;
 	int n, i, verif = 1, k, tmp;
	float A[N][N], B[N][N], C[N][N];
	
	printf("Donner la taille de la matrice n : ");
	scanf("%d",&n);
       	if(n>N) {
		printf(" \t ERREUR: n doit être < N =%d\n ou vous pouvez modifier la constante N et recompiler\n",N);
		exit(-1);
	} else { 
		
		/* vérifier que n est une puissance de 2*/
		for(i = 0;i < n && verif == 1;i++) {	
			if( n == pow(2,i))
				verif  = 0;
		}
		if(!verif) {
			printf(" n=%d est une puissance de 2\n",n);
			saissir_Matrice(n,A,B,0);
			START = temps_CPU();
			appel_strassen(n,A,B,C,0);			
		} else { /* on initialise n à la première  puissance de 2  > à  n*/
			printf(" n =%d n'est pas une puissance de 2\n",n);
			i = 0;
			k = pow(2,i);
			while((i < N) && (k < n)) {	
				i++;
				k = pow(2,i);
			}
			tmp = k;
			saissir_Matrice(n,A,B,tmp);
                        appel_strassen(n,A,B,C,tmp);
		}
	}
END = temps_CPU();
printf("\nCPU time : %.4f s\n", END-START);
return 0;
}
