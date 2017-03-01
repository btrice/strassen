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
#define N 10
void saissir_Matrice(int n,float A[][N],float B[][N],int estpuisanceDe2) {
	int i, j;	
	printf("Entre le elements de la matrice A: \n");
	for(i = 0;i < n; i++) {   
		printf("Entre les elements de la ligne: %d\n",i+1);
		for(j = 0;j < n; j++) {  
			scanf("%f",&A[i][j]);
		}
	}
	printf("\n");
	printf("Entre le elements de la matrice B: \n");
	for(i = 0;i < n; i++) {   
		printf("Entre les elements de la ligne: %d\n",i+1);
		for(j = 0;j < n; j++) { 
			scanf("%f",&B[i][j]);
		}
	}
	/* on la complète par des 0 en la rendant puissance de 2*/
	if(estpuisanceDe2 != 0) {
		for(i = n;i < estpuisanceDe2; i++) {
			for(j = n;j < estpuisanceDe2; j++) { 
				B[i][j]=0;
				A[i][j]=0;
			}
		}
	}
	printf("\n \n");
}

void additionner(int n,float A[][N],float B[][N],float C[][N]) {
	int i,j;
	for(i = 0;i < n; i++)
		for(j = 0;j < n; j++)
			C[i][j] = A[i][j] + B[i][j];
	
}

void affichage(int n,float A[][N]) {
	int i,j;
	for(i = 0;i < n; i++)
		for(j = 0;j < n; j++) {	
			printf("  %f",A[i][j]);
                	if(j > 0 && j % (n-1) == 0)
				printf("\n");
		}
}

void soustraction(int n,float A[][N],float B[][N],float C[][N])
{
	int i,j;
	for(i = 0;i < n; i++)
		for(j = 0;j < n; j++)
		       C[i][j] = A[i][j] - B[i][j];
}
/*opération inverse de partitionner
   | a | b |
   |___|___|=A
   |   |   |
   | c | d |
*/
void fusionner(int n,float A[][N],float a[][N],float b[][N],float c[][N],float d[][N])
{
	int i = 0,j = 0,k = 0,p = 0;
	for(i = 0;i < n/2 ;i++)
		for(j = 0;j < n/2; j++)
		    A[i][j] = a[i][j];
		 
	p =0 ; k = 0;
	for(i = 0;i < n/2; i++) {
        	for(j = n/2; j<n ;j++) {   
			A[i][j] = b[k][p];
			p++;
		}
		p = 0; k++;
	}
	k = 0; p = 0;
	for(i = n/2;i < n; i++) {
		for(j = 0;j < n/2; j++) { 
			A[i][j] = c[k][p];
			p++;
		}
		k++; p = 0;
	}
	k = 0; p = 0;
	for(i = n/2;i < n; i++) {
		for(j = n/2;j < n; j++) {   
			A[i][j] = d[k][p];
			p++;
		}
		k++; p = 0;
	}
}

/*     | a | b | */
/*   A=|___|___| */
/*     |   |   | */
/*     | c | d | */
void partitionner(int n,float A[][N],float a[][N],float b[][N],float c[][N],float d[][N])
{
	int i = 0,j = 0,k = 0,p = 0;
       /*création de la matrice a*/
	for(i = 0;i < n/2; i++)
            for(j = 0;j < n/2; j++)
		   a[i][j] = A[i][j];
        /*création de la matrice b*/
	p = 0; k = 0;
	for(i = 0; i < n/2; i++) {
		for(j = n/2;j < n; j++) {
			b[k][p] = A[i][j];
			p++;
		}
		p = 0; k++;
	}
	/*création de la matrice c*/
	k = 0; p = 0;
	for(i = n/2;i < n; i++) {
		for(j = 0;j < n/2; j++) {
			c[k][p] = A[i][j];
			p++;
		}
		k++; p = 0;
	}
	/*création de la matrice d*/
	k = 0; p = 0;
	for(i = n/2;i < n; i++) {
		for(j = n/2;j < n; j++){   
			d[k][p] = A[i][j];
			p++;
		}
		k++; p = 0;
	}
}

void strassen(int n,float A[][N],float B[][N],float C[][N])
{
	float s1[N][N], s2[N][N], s3[N][N];
	float s4[N][N], s5[N][N], s6[N][N], s7[N][N];
	float add[N][N],add2[N][N],add3[N][N],add4[N][N],sous[N][N],sous2[N][N];
   	if(n == 1) {
		C[0][0] = A[0][0] * B[0][0];
     	} else {     
		float a[N][N], b[N][N], c[N][N], d[N][N];
	      	float e[N][N], f[N][N], g[N][N], h[N][N];
               	partitionner(n,A,a,b,c,d);
	       	partitionner(n,B,e,g,f,h);
                soustraction(n/2,g,h,sous); /* g-h */
		strassen(n/2,a,sous,s1);
                additionner(n/2,a,b,add); /* a+b */
		strassen(n/2,add,h,s2);
		additionner(n/2,c,d,add); /* c+d */
		strassen(n/2,add,e,s3);
		soustraction(n/2,f,e,sous); /* f-e */
		strassen(n/2,d,sous,s4);
		additionner(n/2,a,d,add); /* a+d */
		additionner(n/2,e,h,add2); /* e+h */
		strassen(n/2,add,add2,s5);
		soustraction(n/2,b,d,sous); /* b-d */
		additionner(n/2,f,h,add); /* f+h */
		strassen(n/2,sous,add,s6);
		soustraction(n/2,a,c,sous); /* a-c */
		additionner(n/2,e,g,add); /*e+g */
		strassen(n/2,sous,add,s7);
		/* s5+s4-s2+s6=s5+s4 -(s2-s6) */
         	soustraction(n/2,s4,s2,add);additionner(n/2,s5,s6,add2);additionner(n/2,add,add2,sous);
	  	/* s3+s4 */
	  	additionner(n/2,s3,s4,add);
          	/* s1+s2 */
	  	additionner(n/2,s1,s2,add2);
	  	/* s5+s1-(s3+s7) */
	  	additionner(n/2,s5,s1,add3);additionner(n/2,s3,s7,add4);soustraction(n/2,add3,add4,sous2);
	  	fusionner(n,C,sous,add2,add,sous2); 
	}          
}
void appel_strassen(int n,float A[][N],float B[][N],float C[][N],int tmp)
{
	printf("\t Affichage de la matrice A\n");
	affichage(n,A);
	affichage(n,B);
	printf("\n \n");
	if(tmp == 0) {
		strassen(n,A,B,C);
	} else {
   		strassen(tmp,A,B,C); 
	}
	printf("\t Affichage de la matrice C=A*B\n");
	affichage(n,C); 
}

