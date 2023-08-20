#include<stdio.h>
#include<conio.h>
#include<string.h>

//Structure of the Marks
struct marks
{
    float maths;
    float physics;
    float pc;
    float cti;
    float cs;
};

//Structure of Student details
struct student
{
    char name[100];
    char surname[100];
    int roll_no;
    char branch[100];
    char division[10];
    struct marks m;
}stu[100];

//Function to take input
//first int for no.of inputs and second for previous list
void input(struct student st[100],int a,int n)
{
    int i,j;
    for (i=n;i<n+a;i++)
    {
        printf("Full Name of Student:\n");
        scanf("%s%s",&st[i].name,&st[i].surname);
        printf("Roll No. of student:\n");
        scanf("%d",&st[i].roll_no);
        for(j=0;j<n;j++)
        {
            if(st[j].roll_no==st[i].roll_no)
            {
                printf("Error! Roll no. Already found.\n");
                strcpy(st[i].name,"Error!");
                strcpy(st[i].surname,"Error!");
                st[i].roll_no=0;
                break;
            }
            else
            {
                printf("Branch and division of Student:\n");
                scanf("%s%s",&st[i].branch,&st[i].division);
                printf("Enter maths marks:\n");
                scanf("%f",&st[i].m.maths);
                printf("Enter Physics marks:\n");
                scanf("%f",&st[i].m.physics);
                printf("Enter CTI marks:\n");
                scanf("%f",&st[i].m.cti);
                printf("Enter Programming in C marks:\n");
                scanf("%f",&st[i].m.pc);
                printf("Enter CS marks:\n");
                scanf("%f",&st[i].m.cs);
                printf("Entered %d Students data.\n",i+1);
                break;
            }
        }
    }
}

//take percentage of Marks of students
void per(int n,struct student stu[100])
{
    float per[100];
    per[n]=((stu[n].m.maths+stu[n].m.physics+stu[n].m.cti+stu[n].m.cs+stu[n].m.pc)/5);
    printf("Percentage=%f\n",per[n]);
}

//Print Students data
void display(struct student st[100],int p)
{
    int i; 
    printf("\nThe Students data are:\n");
    for(i=0;i<p;i++)
    {
        printf("\nName of Student:%s %s\n",st[i].name,st[i].surname);
        printf("Roll no. of Student:%d\n",st[i].roll_no);
        printf("Branch and Division of Student:%s %s\n",st[i].branch,st[i].division);
        printf("Maths marks:%f\n",st[i].m.maths);
        printf("Physics marks:%f\n",st[i].m.physics);
        printf("Enter CTI marks:%f\n",st[i].m.cti);
        printf("Programming in C marks:%f\n",st[i].m.pc);
        printf("Enter CS marks:%f\n",st[i].m.cs);
        per(i,stu);
    }
}

//Find Students from Roll no.
void find(struct student stu[100],int r)
{
    int find,i,roll,j,k,not_found=0;
    printf("Enter Roll no. of Student:\n");
    scanf("%d",&roll);
    for(k=0;k<r;k++)
    {
        if(roll==stu[k].roll_no)
        {
            printf("\nName of Student:%s %s\n",stu[k].name,stu[k].surname);
            printf("Roll no. of Student:%d\n",stu[k].roll_no);
            printf("Branch and Division of Student:%s %s\n",stu[k].branch,stu[k].division);
            printf("Maths marks:%f\n",stu[k].m.maths);
            printf("Physics marks:%f\n",stu[k].m.physics);
            printf("Enter CTI marks:%f\n",stu[k].m.cti);
            printf("Programming in C marks:%f\n",stu[k].m.pc);
            printf("Enter CS marks:%f\n",stu[k].m.cs);
            per(k,stu);
            not_found++;
        }
    }  
    if(not_found==0)
    printf("Error! Roll no. not present in the list.\n");
}
void passfail(int n,struct student stu[100])
{
    int i;
    for(i=0;i<n;i++)
    {
        float percentage[100];
        percentage[i]=((stu[i].m.maths+stu[i].m.physics+stu[i].m.cti+stu[i].m.cs+stu[i].m.pc)/5);
        if(percentage[i]>=35)
        {
            printf("\nName of Student:%s %s\n",stu[i].name,stu[i].surname);
            printf("Roll no. of Student:%d\n",stu[i].roll_no);
            printf("Branch and Division of Student:%s %s\n",stu[i].branch,stu[i].division);
            per(i,stu);  
            printf("The Student has passed.\n");
        }
        else
        {
            printf("\nName of Student:%s\n",stu[i].name,stu[i].surname);
            printf("Roll no. of Student:%d\n",stu[i].roll_no);
            printf("Branch and Division of Student:%s %s\n",stu[i].branch,stu[i].division);
            per(i,stu);  
            printf("The Student has failed.\n");
        }
    }
}
void change(struct student stu[100],int n)
{
    int i,a,j;
    for(i=0;i<n;i++)
    {
        printf("Number %d\n",i+1);
        printf("Name of Student:%s %s\n",stu[i].name,stu[i].surname);
        printf("Roll no. of Student:%d\n",stu[i].roll_no);
        printf("Branch and Division of Student:%s %s\n",stu[i].branch,stu[i].division);
        printf("\n");
    }
    printf("\nWhich Number do you want to change?\n");
    scanf("%d",&a);

    



    printf("Full Name of Student:\n");
    scanf("%s%s",&stu[a-1].name,&stu[a-1].surname);
    printf("Roll No. of student:\n");
    scanf("%d",&stu[a-1].roll_no);
    for(j=0;j<n;j++)
    {
        if(stu[j].roll_no==stu[a-1].roll_no)
        {
            printf("Error! Roll no. Already found.\n");
            strcpy(stu[j].name,"Error!");
            strcpy(stu[j].surname,"Error!");
            stu[j].roll_no=0;
            break;
        }
        else
        {
            printf("Branch and division of Student:\n");
            scanf("%s%s",&stu[a-1].branch,&stu[a-1].division);
            printf("Enter maths marks:\n");
            scanf("%f",&stu[a-1].m.maths);
            printf("Enter Physics marks:\n");
            scanf("%f",&stu[a-1].m.physics);
            printf("Enter CTI marks:\n");
            scanf("%f",&stu[a-1].m.cti);
            printf("Enter Programming in C marks:\n");
            scanf("%f",&stu[a-1].m.pc);
            printf("Enter CS marks:\n");
            scanf("%f",&stu[a-1].m.cs);
            printf("Entered Students data.\n");
            break;
        }
    }
}        

//Main code body
int main()
{
    int i,n,j=0;
    int choice,exit;

    //Predefined data for easier usage of program
    strcpy(stu[0].name,"Keshav");
    strcpy(stu[0].surname,"Sharma");  
    stu[0].roll_no=56;
    strcpy(stu[0].branch,"entc");
    strcpy(stu[0].division,"a");
    stu[0].m.maths=60;
    stu[0].m.physics=70;
    stu[0].m.cti=75;
    stu[0].m.pc=65;
    stu[0].m.cs=85;

    strcpy(stu[1].name,"Ishita");
    strcpy(stu[1].surname,"Sharma");
    stu[1].roll_no=57;
    strcpy(stu[1].branch,"entc");
    strcpy(stu[1].division,"a");
    stu[1].m.maths=63;
    stu[1].m.physics=50;
    stu[1].m.cti=72;
    stu[1].m.pc=62;
    stu[1].m.cs=75.5;
    
    n=2;

    do
    {
        printf("===============================");
        printf("\n");
        printf("\nWhat would you like to do?\n");
        printf("Enter 1 to input data\n");
        printf("Enter 2 to print data\n");
        printf("Enter 3 to find Student data\n");
        printf("Enter 4 to check pass/fail list\n");
        printf("Enter 5 to change data\n");
        printf("\n");
        printf("===============================\n");
        printf("Option:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("How many Students data to be inputted?\n");
            scanf("%d",&i);
            input(stu,i,n);
            break;
    
            case 2:
            display(stu,n);
            break;

            case 3:
            find(stu,n);
            break;

            case 4:
            passfail(n,stu);
            break;

            case 5:
            change(stu,n);
            break;

            default:
            printf("Error! Invalid Input");
            break;
        }
        if(choice==1)
        n=n+i;
        printf("Enter 1 to exit\n");
        printf("Enter 0 to continue\n");
        scanf("%d",&exit);
    }
    while(exit==0);
    return 0;
}