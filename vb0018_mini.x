#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EXEC SQL INCLUDE sqlca;

EXEC SQL WHENEVER SQLERROR sqlprint;

int main(int argc, char* argv[]) 
{
EXEC SQL BEGIN DECLARE SECTION;

	char Emp_SSN[10];
	char temp_Emp_SSN[10];
	char F_Name[20];
	char M_Name[20];
	char L_Name[20];
	int Proj_Number;
	double hours;
	double Total_hours;
	double Avg_hours;
	char SSN_Max_Emp[10];
	char Project_name[20];
	char Dept_name[20];
	int emp_ex_ct=0;
	
	int flag = 1;
	int bin = -1;
	int pcount = 0;
	char mode[10];
	
EXEC SQL END DECLARE SECTION;
     EXEC SQL CONNECT TO unix:postgresql://localhost /cs687 USER vb0018 USING "687studentspring2017"; 
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
	EXEC SQL DECLARE Emp_Exists CURSOR FOR 
	
		SELECT COUNT(*), E.fname, E.minit, E.lname, W.hours, P.pname
		FROM vb0018.EMPLOYEE AS E,vb0018.WORKS_ON AS W,vb0018.PROJECT AS P
		WHERE E.Ssn = W.Essn AND W.Pno = P.Pnumber AND W.Essn =:Emp_SSN and W.Pno=:Proj_Number
		GROUP BY E.Ssn,W.Essn,P.Pnumber,E.fname, E.minit, E.lname, W.hours, P.pname;

	EXEC SQL OPEN Emp_Exists;

	
	while (SQLCODE==0)
	{
		EXEC SQL FETCH IN Emp_Exists INTO :emp_ex_ct, :F_Name, :M_Name, :L_Name, :hours, :Project_name;
		
		flag  = emp_ex_ct;
		
	}
	    EXEC SQL CLOSE Emp_Exists;
		
		//Insert if record not exists // 
	if(flag == 0)
	{
		EXEC SQL Select fname,minit,lname INTO :F_Name, :M_Name, :L_Name 
		from vb0018.EMPLOYEE as e where e.ssn = :Emp_SSN;
	
		EXEC SQL Select pname INTO :Project_name 
		from vb0018.PROJECT as p where p.Pnumber = :Proj_Number;
		
		printf("\n\n Employee %s % s %s started working %lf hours on project %s.\n ", F_Name, M_Name, L_Name, hours, Project_name);
		EXEC SQL INSERT INTO vb0018.WORKS_ON (Essn, Pno, Hours)
			VALUES (:Emp_SSN,:Proj_Number,:hours);
		EXEC SQL COMMIT;
	}
	
		//Donot insert if record exists // 
		
    else if (flag == 1){
			printf("\n\n Employee %s % s %s is already working %lf hours on project %s. The operation is rejected.\n ", F_Name, M_Name, L_Name, hours, Project_name);
	}

		//	Fetching project and employee details about queried project number	//
	
		EXEC SQL select * INTO :Project_name, :Proj_Number, :Dept_name, :Total_hours, :Avg_hours, :F_Name, :M_Name, :L_Name, :Emp_SSN, :temp_Emp_SSN, :hours, :Proj_Number FROM (select P.pname, W.pno, D.dname, SUM(W.hours), AVG(W.hours) from vb0018.Project P, vb0018.Department D, vb0018.Works_on W WHERE P.dnum=D.dnumber AND P.pnumber = W.pno GROUP BY W.pno,P.pname,D.dname) one, (SELECT E.fname, E.minit, E.lname,ssn from vb0018.Employee as E, vb0018.WORKS_ON as W where E.SSN=W.essn GROUP BY E.fname, E.minit, E.lname, E.SSN) two, (SELECT W.essn,W.hours,W.pno FROM works_on W, (SELECT pno,MAX(hours)"max" FROM works_on GROUP BY pno) three WHERE three.pno = W.pno AND three.max = W.hours ) four WHERE one.pno = four.pno  AND four.essn = two.ssn AND one.pno = :Proj_Number;
		
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
	
	EXEC SQL Select fname,minit,lname INTO :F_Name, :M_Name, :L_Name 
		from vb0018.EMPLOYEE as e where e.ssn = :Emp_SSN;
		printf("\n\n Employee %s % s %s stopped working on ", F_Name, M_Name, L_Name);
		
	//	Selecting projects the employee works on	//
		
		EXEC SQL DECLARE Proj_works CURSOR FOR
			Select P.Pname from vb0018.WORKS_ON AS W,vb0018.PROJECT AS P
			WHERE W.Pno = P.Pnumber AND W.Essn =:Emp_SSN
			GROUP BY P.Pname, W.Pno,P.Pnumber,W.Essn;
			
			EXEC SQL OPEN Proj_works;

			//	Printing project names// 
			
	while (SQLCODE==0)
	{
		EXEC SQL FETCH IN Proj_works INTO :Project_name;
		if(Project_name!=NULL)
		{
				printf(" %s ",Project_name);
				}
				
				strcpy(Project_name,"");
				
	}
		
					printf("\n");
			EXEC SQL CLOSE Proj_works;
	
		//	Deleting the queried employee's details	//
		
		EXEC SQL DELETE FROM vb0018.WORKS_ON as W
		WHERE W.Essn =:Emp_SSN;
		EXEC SQL COMMIT;
	}

	
	
    EXEC SQL COMMIT;

	EXEC SQL DISCONNECT; 

	return 0;

}