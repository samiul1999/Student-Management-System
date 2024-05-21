
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void menu();
void add();
void view();
void search();
void update();
void deleterec();
int s=0;
struct student
{
    char name[20];
    char gender[8];
    int idno;
    char department[8];
    char email_ad[30];
    char father_name[15];
    char mother_name[15];
    char blood_group[6];
    char address[20];
};
int main()
{
    printf("::BANGLADESH ARMY UNIVERSITY OF ENGINEERING AND TECHONOLOGY::");
    printf("\n");
    printf ("");
    printf("\n");
    printf("\n");
    printf("::Student Record Management System::");
    printf("\n");
    printf("\n");
    printf("Press any key to continue.");
    getch();
    menu();
    return 0;
}
void menu()
{
    int choice;
    system("cls");

    printf("<--:MENU:-->");
printf("\n");
printf("\n");
    printf("Enter appropriate number to perform following task.");
printf("\n");
printf("\n");
    printf("1 : Add Record.");
printf("\n");
printf("\n");
    printf("2 : View Record.");
printf("\n");
printf("\n");
    printf("3 : Search Record.");
printf("\n");
printf("\n");
    printf("4 : update Record.");
printf("\n");
printf("\n");
    printf("5 : Delete.");
printf("\n");
printf("\n");
    printf("6 : Exit.");
printf("\n");
printf("\n");
    printf("Enter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        update();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        exit(1);
        break;

    default:

        printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){

        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
s=s+1;
        printf("<--:ADD RECORD:-->");
printf("\n");
        printf("Enter details of student.");
printf("\n");
printf("\n");
printf("Enter Id No : ");
        scanf("%d",&std.idno);
printf("\n");
        printf("Enter Name : ");
        fflush(stdin);
        gets(std.name);
printf("\n");
        printf("Enter gender : ");
        fflush(stdin);
        gets(std.gender);
printf("\n");
       printf("Department:");
       fflush(stdin);
       gets(std.department);
       printf("\n");
        printf("Farther's Name: ");
        fflush(stdin);
        gets(std.father_name);
printf("\n");
        printf("Mother's Name: ");
        fflush(stdin);
        gets(std.mother_name);
printf("\n");
        printf("Blood Group: ");
        fflush(stdin);
        gets(std.blood_group);
printf("\n");
        printf ("Email:");
       fflush(stdin);
       gets(std.email_ad);
       printf("\n");
        printf("Address: ");
        fflush(stdin);
        gets(std.address);
        fwrite(&std,sizeof(std),1,fp);
printf("\n");
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
printf("\n");
printf("\n");
    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");

printf("<--:VIEW RECORD:-->");
printf("\n");
printf("\n");
    printf("S.No   ID NO   Name of Student        Gender       Department     Father's name       Mother's name      Blood group    Email.Ad                       Address");
printf("\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){

        printf("Error opening file.");
        exit(1);
    }
    j=s;
    while(fread(&std,sizeof(std),1,fp) == 1){
printf("\n");
printf("\n");
if(j==0)
       {
           break;
       }
       j--;
        printf("%-7d%-9d%-22s%-13s%-15s%-20s%-20s%-15s%-30s%-10s%",i,std.idno,std.name,std.gender,std.department,std.father_name,std.mother_name,std.blood_group,std.email_ad,std.address);
        i++;
    }
    fclose(fp);
printf("\n");
printf("\n");
    printf("Press any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
    char stdepartment[20];
    int id;
    system("cls");
printf("\n");
    printf("<--:SEARCH RECORD:-->");
printf("\n");
    printf("ID No: ");
    scanf ("%d",&id);
    fflush(stdin);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){

        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        //if(strcmp(stname,std.name) == 0)
            //if(strcmp(stdepartment,std.department) == 0)
                if (id==std.idno){


            printf("Name : %s",std.name);
printf("\n");
            printf("gender : %s",std.gender);
printf("\n");
            printf("ID No : %d",std.idno);
printf("\n");
            printf("Deparemet:%s",std.department);
            printf("\n");
            printf("Father's Name: %s",std.father_name);
printf("\n");
            printf("Mother's Name: %s",std.mother_name);
printf("\n");
            printf ("Blood group:%s",std.blood_group);
printf("\n");
            printf ("Email:%s",std.email_ad);
printf("\n");
             printf ("Address:%s",std.address);
             printf ("\n");
             printf("\n");

        }

    }
    fclose(fp);
    printf ("\n");
    printf("\nPress any key to continue.");
    getch();
    menu();
}
void update()
{
    char stname[20];
    char stdepartment [20];
    int id ,o;
    FILE *fp;
    struct student std;
    system("cls");

    printf("<--:MODIFY RECORD:-->");
printf("\n");
    printf("Enter name of student to modify: ");
    fflush(stdin);
    gets(stname);
 printf("\n Enter Department of student to modify:");
    fflush(stdin);
    gets(stdepartment);
    printf ("Enter Id of student to modify: ");
    scanf("%d",&id);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){

        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0)
            //if (strcmp(stdepartment,std.department)==0)
            //if (id==std.idno)
            {
    printf("--------------------------------------------\n");
    printf("                Option for Update            \n");
    printf("--------------------------------------------\n");
    printf("1. Student Name\n");
    printf("2. Gender \n");
    printf("3. Id\n");
    printf("4. Department\n");
    printf("5. Father's Name\n");
    printf("6. Mother's Name\n");
    printf("7. Blood Group");
    printf("8. Email Add");
    printf("9. Address");
    printf("--------------------------------------------\n");
    printf("Chose Option:");
    scanf("%d",&o);
    if(o==1)
    {
        printf("Enter update Name:");
        fflush(stdin);
        gets(std.name);
    }
    else if(o==2)
    {
        printf("Enter update Gender:");
        fflush(stdin);
        gets(std.gender);
    }
     else if(o==3)
    {
        printf("Enter update Id:");
        scanf("%d",&std.idno);
    }
     else if(o==4)
    {
        printf("Enter update Department:");
        fflush(stdin);
        gets(std.department);
    }
      else if(o==5)
    {
        printf("Enter update Father's name:");
        fflush(stdin);
        gets(std.father_name);
    }
    else if(o==6)
    {
        printf("Enter update Mother's name:");
        fflush(stdin);
        gets(std.mother_name);
    }
    else if(o==7)
    {
        printf("Enter update Blood Group:");
        fflush(stdin);
        gets(std.blood_group);
    }
    else if(o==8)
    {
        printf("Enter update Email Add:");
        fflush(stdin);
        gets(std.email_ad);
    }
    else if(o==9)
    {
        printf("Enter update Address:");
        fflush(stdin);
        gets(std.address);
    }

    else{

        printf("\n");
    }
    fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
        }
    }
    fclose(fp);
    printf("\n");
    printf("Press any key to continue.");
    getch();
    menu();
}
void deleterec()
{
    char stname[20];
    char stdepartment[20];
    int id;
    FILE *fp,*ft;
    struct student std;
    system("cls");

    printf("<--:DELETE RECORD:-->");
printf("\n");
printf("Enter ID of student to delete record : ");
    scanf("%d",&id);
    printf("\n");
    //printf("Enter name of student to delete record : ");
    //fflush(stdin);
    //gets(stname);
    //printf("\n");
    //printf("Enter Deparement of student to delete record : ");
    //fflush(stdin);
    //gets(stdepartment);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){

        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){

        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(stname,std.name)!=0)
            if(strcmp(stdepartment,std.department)!=0)
            if(id!=std.idno)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
printf("\n");
    printf("Press any key to continue.");
    getch();
    menu();
}
