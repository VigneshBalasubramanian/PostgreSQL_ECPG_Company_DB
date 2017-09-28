/* Processed by ecpg (4.7.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "vb0018_mini.x"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#line 1 "/usr/include/postgresql/sqlca.h"
#ifndef POSTGRES_SQLCA_H
#define POSTGRES_SQLCA_H

#ifndef PGDLLIMPORT
#if  defined(WIN32) || defined(__CYGWIN__)
#define PGDLLIMPORT __declspec (dllimport)
#else
#define PGDLLIMPORT
#endif   /* __CYGWIN__ */
#endif   /* PGDLLIMPORT */

#define SQLERRMC_LEN	150

#ifdef __cplusplus
extern		"C"
{
#endif

struct sqlca_t
{
	char		sqlcaid[8];
	long		sqlabc;
	long		sqlcode;
	struct
	{
		int			sqlerrml;
		char		sqlerrmc[SQLERRMC_LEN];
	}			sqlerrm;
	char		sqlerrp[8];
	long		sqlerrd[6];
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows processed				*/
	/* after an INSERT, UPDATE or				*/
	/* DELETE statement					*/
	/* 3: empty						*/
	/* 4: empty						*/
	/* 5: empty						*/
	char		sqlwarn[8];
	/* Element 0: set to 'W' if at least one other is 'W'	*/
	/* 1: if 'W' at least one character string		*/
	/* value was truncated when it was			*/
	/* stored into a host variable.             */

	/*
	 * 2: if 'W' a (hopefully) non-fatal notice occurred
	 */	/* 3: empty */
	/* 4: empty						*/
	/* 5: empty						*/
	/* 6: empty						*/
	/* 7: empty						*/

	char		sqlstate[5];
};

struct sqlca_t *ECPGget_sqlca(void);

#ifndef POSTGRES_ECPG_INTERNAL
#define sqlca (*ECPGget_sqlca())
#endif

#ifdef __cplusplus
}
#endif

#endif

#line 5 "vb0018_mini.x"


/* exec sql whenever sqlerror  sqlprint ; */
#line 7 "vb0018_mini.x"


int main(int argc, char* argv[]) 
{
/* exec sql begin declare section */

	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	
	   
	   
	   
	 
	

#line 13 "vb0018_mini.x"
 char Emp_SSN [ 10 ] ;
 
#line 14 "vb0018_mini.x"
 char temp_Emp_SSN [ 10 ] ;
 
#line 15 "vb0018_mini.x"
 char F_Name [ 20 ] ;
 
#line 16 "vb0018_mini.x"
 char M_Name [ 20 ] ;
 
#line 17 "vb0018_mini.x"
 char L_Name [ 20 ] ;
 
#line 18 "vb0018_mini.x"
 int Proj_Number ;
 
#line 19 "vb0018_mini.x"
 double hours ;
 
#line 20 "vb0018_mini.x"
 double Total_hours ;
 
#line 21 "vb0018_mini.x"
 double Avg_hours ;
 
#line 22 "vb0018_mini.x"
 char SSN_Max_Emp [ 10 ] ;
 
#line 23 "vb0018_mini.x"
 char Project_name [ 20 ] ;
 
#line 24 "vb0018_mini.x"
 char Dept_name [ 20 ] ;
 
#line 25 "vb0018_mini.x"
 int emp_ex_ct = 0 ;
 
#line 27 "vb0018_mini.x"
 int flag = 1 ;
 
#line 28 "vb0018_mini.x"
 int bin = - 1 ;
 
#line 29 "vb0018_mini.x"
 int pcount = 0 ;
 
#line 30 "vb0018_mini.x"
 char mode [ 10 ] ;
/* exec sql end declare section */
#line 32 "vb0018_mini.x"

     { ECPGconnect(__LINE__, 0, "unix:postgresql://localhost/cs687" , "vb0018" , "687studentspring2017" , NULL, 0); 
#line 33 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 33 "vb0018_mini.x"
 
     if (sqlca.sqlcode < 0) exit(-1);
     printf("CONNECTED\n");

	strcpy(mode,argv[1]);
	strcpy(Emp_SSN,argv[3]);
	Proj_Number = atoi(argv[5]);
	hours = atof(argv[7]);
	
	printf("Insert Query contains:\n");
	printf("SSN");
	printf("\t\t");
	printf("Project Num");
	printf("\t");
	printf("Hours");
	printf("\n");
	printf("%s\t", Emp_SSN);
	printf("%d\t\t",Proj_Number);
	printf("%lf\n",hours);
	
	if(strcmp(mode,"-insert") == 0)
	{
	ECPGset_var( 0, &( Proj_Number ), __LINE__);\
 ECPGset_var( 1, ( Emp_SSN ), __LINE__);\
 /* declare Emp_Exists cursor for select count ( * ) , E . fname , E . minit , E . lname , W . hours , P . pname from vb0018 . EMPLOYEE as E , vb0018 . WORKS_ON as W , vb0018 . PROJECT as P where E . Ssn = W . Essn and W . Pno = P . Pnumber and W . Essn = $1  and W . Pno = $2  group by E . Ssn , W . Essn , P . Pnumber , E . fname , E . minit , E . lname , W . hours , P . pname */
#line 60 "vb0018_mini.x"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare Emp_Exists cursor for select count ( * ) , E . fname , E . minit , E . lname , W . hours , P . pname from vb0018 . EMPLOYEE as E , vb0018 . WORKS_ON as W , vb0018 . PROJECT as P where E . Ssn = W . Essn and W . Pno = P . Pnumber and W . Essn = $1  and W . Pno = $2  group by E . Ssn , W . Essn , P . Pnumber , E . fname , E . minit , E . lname , W . hours , P . pname", 
	ECPGt_char,(Emp_SSN),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(Proj_Number),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 62 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 62 "vb0018_mini.x"


	
	while (SQLCODE==0)
	{
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch in Emp_Exists", ECPGt_EOIT, 
	ECPGt_int,&(emp_ex_ct),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(F_Name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(M_Name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(L_Name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_double,&(hours),(long)1,(long)1,sizeof(double), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(Project_name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 67 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 67 "vb0018_mini.x"

		
		flag  = emp_ex_ct;
		
	}
	    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close Emp_Exists", ECPGt_EOIT, ECPGt_EORT);
#line 72 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 72 "vb0018_mini.x"

		
		//Insert if record not exists // 
	if(flag == 0)
	{
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select fname , minit , lname from vb0018 . EMPLOYEE as e where e . ssn = $1 ", 
	ECPGt_char,(Emp_SSN),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(F_Name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(M_Name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(L_Name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 78 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 78 "vb0018_mini.x"

	
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select pname from vb0018 . PROJECT as p where p . Pnumber = $1 ", 
	ECPGt_int,&(Proj_Number),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(Project_name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 81 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 81 "vb0018_mini.x"

		
		printf("\n\n Employee %s % s %s started working %lf hours on project %s.\n ", F_Name, M_Name, L_Name, hours, Project_name);
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into vb0018 . WORKS_ON ( Essn , Pno , Hours ) values ( $1  , $2  , $3  )", 
	ECPGt_char,(Emp_SSN),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(Proj_Number),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_double,&(hours),(long)1,(long)1,sizeof(double), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 85 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 85 "vb0018_mini.x"

		{ ECPGtrans(__LINE__, NULL, "commit");
#line 86 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 86 "vb0018_mini.x"

	}
	
		//Donot insert if record exists // 
		
    else if (flag == 1){
			printf("\n\n Employee %s % s %s is already working %lf hours on project %s. The operation is rejected.\n ", F_Name, M_Name, L_Name, hours, Project_name);
	}

		//	Fetching project and employee details about queried project number	//
	
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select * from ( select P . pname , W . pno , D . dname , SUM ( W . hours ) , AVG ( W . hours ) from vb0018 . Project P , vb0018 . Department D , vb0018 . Works_on W where P . dnum = D . dnumber and P . pnumber = W . pno group by W . pno , P . pname , D . dname ) one , ( select E . fname , E . minit , E . lname , ssn from vb0018 . Employee as E , vb0018 . WORKS_ON as W where E . SSN = W . essn group by E . fname , E . minit , E . lname , E . SSN ) two , ( select W . essn , W . hours , W . pno from works_on W , ( select pno , MAX ( hours ) \"max\" from works_on group by pno ) three where three . pno = W . pno and three . max = W . hours ) four where one . pno = four . pno and four . essn = two . ssn and one . pno = $1 ", 
	ECPGt_int,&(Proj_Number),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(Project_name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(Proj_Number),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(Dept_name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_double,&(Total_hours),(long)1,(long)1,sizeof(double), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_double,&(Avg_hours),(long)1,(long)1,sizeof(double), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(F_Name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(M_Name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(L_Name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(Emp_SSN),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(temp_Emp_SSN),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_double,&(hours),(long)1,(long)1,sizeof(double), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(Proj_Number),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 97 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 97 "vb0018_mini.x"

		
		printf("\nPROJECT NAME:\t\t\t%s", Project_name);
		printf("\nDEPARTMENT NAME:\t\t\t%s", Dept_name);
		printf("\nTOTAL HOURS in the project:\t\t %lf ", Total_hours);
		printf("\nAVERAGE HOURS in the project:\t\t %lf ", Avg_hours);
		
		printf("\nFIRST NAME:\t\t\t%s", F_Name);
		printf("\nMIDDLE NAME:\t\t\t%s", M_Name);
		printf("\nLAST NAME:\t\t\t%s", L_Name);
		printf("\nHOURS worked by that employee in this project:\t %lf \n", hours);

	}
	else if(strcmp(mode,"-delete") == 0)
	{
	
	//Fetching employee information based on queried SSN //
	
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select fname , minit , lname from vb0018 . EMPLOYEE as e where e . ssn = $1 ", 
	ECPGt_char,(Emp_SSN),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(F_Name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(M_Name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(L_Name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 116 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 116 "vb0018_mini.x"

		printf("\n\n Employee %s % s %s stopped working on ", F_Name, M_Name, L_Name);
		
	//	Selecting projects the employee works on	//
		
		ECPGset_var( 2, ( Emp_SSN ), __LINE__);\
 /* declare Proj_works cursor for select P . Pname from vb0018 . WORKS_ON as W , vb0018 . PROJECT as P where W . Pno = P . Pnumber and W . Essn = $1  group by P . Pname , W . Pno , P . Pnumber , W . Essn */
#line 124 "vb0018_mini.x"

			
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare Proj_works cursor for select P . Pname from vb0018 . WORKS_ON as W , vb0018 . PROJECT as P where W . Pno = P . Pnumber and W . Essn = $1  group by P . Pname , W . Pno , P . Pnumber , W . Essn", 
	ECPGt_char,(Emp_SSN),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 126 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 126 "vb0018_mini.x"


			//	Printing project names// 
			
	while (SQLCODE==0)
	{
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch in Proj_works", ECPGt_EOIT, 
	ECPGt_char,(Project_name),(long)20,(long)1,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 132 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 132 "vb0018_mini.x"

		if(Project_name!=NULL)
		{
				printf(" %s ",Project_name);
				}
				
				strcpy(Project_name,"");
				
	}
		
					printf("\n");
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close Proj_works", ECPGt_EOIT, ECPGt_EORT);
#line 143 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 143 "vb0018_mini.x"

	
		//	Deleting the queried employee's details	//
		
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from vb0018 . WORKS_ON as W where W . Essn = $1 ", 
	ECPGt_char,(Emp_SSN),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 148 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 148 "vb0018_mini.x"

		{ ECPGtrans(__LINE__, NULL, "commit");
#line 149 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 149 "vb0018_mini.x"

	}

	
	
    { ECPGtrans(__LINE__, NULL, "commit");
#line 154 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 154 "vb0018_mini.x"


	{ ECPGdisconnect(__LINE__, "CURRENT");
#line 156 "vb0018_mini.x"

if (sqlca.sqlcode < 0) sqlprint();}
#line 156 "vb0018_mini.x"
 

	return 0;

}