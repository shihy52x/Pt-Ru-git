#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void read_coord(FILE *fp1,int cnatm,double *x) 
{

 int i,j,k;
j=0;
 int skip,skip2;
 int error;
 char s[100];
       

        	fscanf(fp1,"%d\n",&cnatm);
        	fscanf(fp1,"%s\n",s);

	for (j=0;j<cnatm;j++)
		{
   		error=fscanf(fp1," %s %lf %lf  %lf\n",       s,    x+j*3+0,   x+j*3+1,    x+j*3+2)  ;
      //             printf("j=%d, error=%d  x=%lf \n",j,error,*(x+j*3));
                   if (error==-1)
                   {printf("\n\nNot enough data in pt.coord!!!\n\n");exit (0);}
		}
            // printf("%lf %lf %lf\n",*x,*(x+1),*(x+2));


}



void write_coord(FILE *fp2,int ptnatm, int runatm, int cnatm, double *x, double *y, double energy) 
{

 int i,j,k;
j=0;
 int skip,skip2;
 int nskip=12;
 char s[100];

               fprintf(fp2,"%d\n",ptnatm+runatm+cnatm);
               fprintf(fp2,"Atoms.Energy:%lf\n",energy);
	for (j=0;j<ptnatm;j++)
		{fprintf(fp2,"      %6s %12.4lf %12.4lf %12.4lf \n", "Pt",*( x+j*3+0),*(x+j*3+1), *(x+j*3+2) );}
	for (j=ptnatm;j<ptnatm+runatm;j++)
		{fprintf(fp2,"      %6s %12.4lf %12.4lf %12.4lf \n", "Ru",*( x+j*3+0),*(x+j*3+1), *(x+j*3+2) );}
	for (j=0;j<cnatm;j++)
		{fprintf(fp2,"      %6s %12.4lf %12.4lf %12.4lf \n", "C",*( y+j*3+0),*(y+j*3+1), *(y+j*3+2) ); }


}





void write_his(FILE *fp2,int natm,double *x) 
{
 int i,j,k;
j=0;
 int skip,skip2;
 int nskip=12;
 char s[100];

               fprintf(fp2,"%d\n",natm);
               fprintf(fp2,"Atoms. Timestep: 0\n");
	for (j=0;j<natm;j++)
		{
                fprintf(fp2,"      %d %lf %lf %lf \n", 1,*( x+j*3+0),*(x+j*3+1), *(x+j*3+2) );
		}


}

void write_gen(FILE *fp3,int ptnatm,int runatm, int cnatm,double *x, double *y, double *cell, char *name1, char *name2 ,char *name3) 
{

 int i,j,k;
 char s[100];
// printf("%d\n",ptnatm+cnatm);
        fprintf(fp3,"%d   C \n",ptnatm+runatm+cnatm);
        if (ptnatm!=0)   fprintf(fp3,"%5s",name1);
        if (runatm!=0)   fprintf(fp3,"%5s",name2);
        if (cnatm!= 0 )  fprintf(fp3,"%5s",name3);
                       fprintf(fp3,"\n");
	for (j=0;j<ptnatm;j++)
		{fprintf(fp3,"      %d %d %12.4lf %12.4lf %12.4lf \n", j+1              ,1,*( x+j*3+0),*(x+j*3+1), *(x+j*3+2) ); }
	for (j=ptnatm;j<ptnatm+runatm;j++)
		{fprintf(fp3,"      %d %d  %12.4lf %12.4lf %12.4lf \n"  , j+1       ,2,*( x+j*3+0),*(x+j*3+1), *(x+j*3+2) );     }
//		printf("      %d %d %12.4lf %12.4lf %12.4lf \n", j+1              ,1,*( x+j*3+0),*(x+j*3+1), *(x+j*3+2) );}
	for (j=0;j<cnatm;j++)
		{ fprintf(fp3,"      %d %d %12.4lf %12.4lf %12.4lf \n" , j+1+ptnatm+runatm,3,*( y+j*3+0),*(y+j*3+1), *(y+j*3+2) );}
        
//        fprintf(fp3,"%12.6f %12.6f %12.6f\n",0.0,0.0,0.0);
//        ;for (i=0;i<3;i++){
//            fprintf(fp3,"%12.6f %12.6f %12.6f\n", *(cell+i*3+0),*(cell+i*3+1),*(cell+i*3+2));
//        }

}


void read_gen(FILE *fp,int ptnatm, int runatm, int cnatm,double *x, double *y ) 
{


 int i,j,k;
 j=0;
 int skip,skip2;
 double skip3;
 int N=0;
 int Nmetal=ptnatm+runatm;
 char s1[100];
 char s2[100];

        fscanf(fp,"%d %s\n",&N,s1);
        fgets(s1,sizeof(s1),fp);
	for (j=0;j<Nmetal;j++)
		{
    		fscanf(fp, " %d  %d  %lf %lf  %lf\n",       &skip, &skip2,    x+j*3+0,   x+j*3+1,    x+j*3+2)  ;
//                printf("%d %d %12.4lf %12.4lf %12.4lf \n", skip,skip2,*( x+j*3+0),*(x+j*3+1), *(x+j*3+2) );
		}
	for (j=0;j<cnatm;j++)
		{
                fscanf(fp," %d  %d  %lf %lf %lf \n", &skip,&skip2, y+j*3+0,y+j*3+1, y+j*3+2) ;
		}
        
//        fscanf(fp,"%lf %lf %lf\n",&skip3, &skip3, &skip3);
//        for (i=0;i<3;i++){
//            fscanf(fp,"%lf %lf %lf\n", cell+i*3+0,cell+i*3+1,cell+i*3+2);
//        }
}
