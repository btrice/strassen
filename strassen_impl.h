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
#ifndef N
#define N 10
void additionner(int ,float [][N],float [][N],float [][N]);
void affichage(int ,float [][N]);
void soustraction(int ,float [][N],float [][N],float [][N]);
void fusionner(int ,float [][N],float [][N],float [][N],float [][N],float [][N]);
void partitionner(int ,float [][N],float [][N],float [][N],float [][N],float [][N]);
void strassen(int n,float [][N],float [][N],float [][N]);
void saissir_Matrice(int,float [][N],float [][N],int);
void appel_strassen(int ,float [][N],float [][N],float [][N],int);
#endif
