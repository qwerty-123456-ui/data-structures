#include<stdio.h>
#include<string.h>

typedef struct
{
	int day;
	int month;
	int year;
}date;
typedef union
{
	char dayscholar[200];
	char hostelite[20];
}stay;
typedef struct 
{
	int rno;
	char name[50];
	char usn[80];
	float cgpa;
	date dob;
	stay place;
	int ch;
}st[50];
void read(st,int);
void printout(st,int);
void search(st,int);
void main()
{
	int i,n,j,c;
	st s2;
	printf("Enter the no. of students \n");
        scanf("%d",&n);
	read( s2,n);
	printout(s2,n);
	for (i=0;i<n;i++)
	{
			
	       if(s2[i].cgpa >9.5)
	       {
	            	printf("%s with %s usn has CGPA > 9.5 \n",s2[i].name,s2[i].usn);
	       }
	}
	search(s2,n);
}
void search(st s1,int n)
{
	int i,j,c;
	char u[50];
	 printf("Enter the student USN to get the fucking CGPA\n");
                        scanf("%s",u);
		 for(i=0;i<n;i++)
                  {
	
	              if(strcmp(u,s1[i].usn)==0)
		      { 
			     j=i; 
			     c=0;
		      }
		      else
			      c=1;
		      
                  }                    

		

	  if(c==0){
		       printf(" The name ,usn,roll no.,date of birth,cgpa is\n ");
                       printf("%s\n",s1[j].name);
                       printf("%s\n",s1[j].usn);
                       printf("%d\n",s1[j].rno);
                       printf("%d",s1[j].dob.day);
                       printf("%d",s1[j].dob.month);
                       printf("%d\n",s1[j].dob.year);
                       printf("%f\n",s1[j].cgpa);
                       if(s1[j].ch == 1)
                               printf("%s\n",s1[j].place.dayscholar);
                       if(s1[j].ch == 2)
			       printf("%s\n",s1[j].place.hostelite);

	  }
	  else
		  printf("invalid USN \n");

}


void printout(st s1,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	             printf(" The name ,usn,roll no.,date of birth,cgpa is\n ");
	             printf("%s\n",s1[i].name);
		     printf("%s\n",s1[i].usn);
		     printf("%d\n",s1[i].rno);
		     printf("%d",s1[i].dob.day);
		     printf("%d",s1[i].dob.month);
		     printf("%d\n",s1[i].dob.year);
		     printf("%f\n",s1[i].cgpa);
		     if(s1[i].ch == 1)
		     printf("%s\n",s1[i].place.dayscholar);
		     if(s1[i].ch == 2)
		     printf("%s\n",s1[i].place.hostelite);
	}
}

void read(st s,int n)
{
	int i=0;
        for(i=0;i<n;i++)
        {
                printf("Enter the Student Name , USN , Roll no., Date of birth DD-MM-YYYY, CGPA for student %d \n",i+1);

                scanf("%s",s[i].name);
                scanf("%s",s[i].usn);
                scanf("%d",&s[i].rno);
                scanf("%d",&s[i].dob.day);
                scanf("%d",&s[i].dob.month);
                scanf("%d",&s[i].dob.year);
                scanf("%f",&s[i].cgpa);

                printf("Enter 1 :DAY SCHOLAR  or 2 :HOSTELITE \n");
                scanf("%d",&s[i].ch);
                switch(s[i].ch)
                {
                   case 1:printf("ENTER YOUR ADDRESS\n");
                       scanf("%s",s[i].place.dayscholar);
                       break;
                   case 2:printf("ENTER YOUR ADDRESS\n");
                       scanf("%s",s[i].place.hostelite);
                       break;
                   default: printf("FUCK OFF\n");
                         break;

               }

        }
}


