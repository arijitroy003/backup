#include<stdio.h>
#include<stdlib.h>
struct student
{
 int rollno;
 char name[30];
 float marks;
}stud;

void insert()
{
 FILE *fp;
 fp = fopen("Record.txt", "a");
 printf("Enter the Roll no   :");
 scanf("%d", &stud.rollno);
 printf("Enter the Name      :");
 scanf("%s", &stud.name);
 printf("Enter the marks      :");
 scanf("%f", &stud.marks);
 fwrite(&stud, sizeof(stud), 1, fp);
 fclose(fp);
}

void disp()
{
 FILE *fp1;
 fp1 = fopen("Record.txt", "r");
 printf("\nRoll Number\tName\tmarks\n\n");
 while (fread(&stud, sizeof(stud), 1, fp1))
 printf("  %d\t\t%s\t%.2f\n", stud.rollno, stud.name, stud.marks);
 fclose(fp1);
}

void deletefile()
{
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("Enter the Roll no you want to delete :");
 scanf("%d", &r);
 if (avlrollno(r) == 0)
  printf("Roll no %d is not available in the file\n", r);
 else
 {
  fpo = fopen("Record.txt", "r");
  fpt = fopen("TempFile.txt", "w");
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   s = stud.rollno;
   if (s != r)
    fwrite(&stud, sizeof(stud), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record.txt", "w");
  fpt = fopen("TempFile.txt", "r");
  while (fread(&stud, sizeof(stud), 1, fpt))
   fwrite(&stud, sizeof(stud), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
 }

}

void update()
{
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter roll number to update:");
 scanf("%d", &r);
 avl = avlrollno(r);
 if (avl == 0)
 {
  printf("Roll number %d is not Available in the file", r);
 }
 else
 {
  fpo = fopen("Record.txt", "r");
  fpt = fopen("TempFile.txt", "w");
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   s = stud.rollno;
   if (s != r)
    fwrite(&stud, sizeof(stud), 1, fpt);
   else
   {
    printf("\n\t1. Update Name of Roll Number %d", r);
    printf("\n\t2. Update marks of Roll Number %d", r);
    printf("\n\t3. Update both Name and marks of Roll Number %d", r);
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter Name:");
     scanf("%s", &stud.name);
     break;
    case 2:
     printf("Enter marks : ");
     scanf("%f", &stud.marks);
     break;
    case 3:
     printf("Enter Name: ");
     scanf("%s", &stud.name);
     printf("Enter marks: ");
     scanf("%f", &stud.marks);
     break;
    default:
     printf("Invalid Selection");
     break;
    }
    fwrite(&stud, sizeof(stud), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record.txt", "w");
  fpt = fopen("TempFile.txt", "r");
  while (fread(&stud, sizeof(stud), 1, fpt))
  {
   fwrite(&stud, sizeof(stud), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
 }
}

int avlrollno(int rno)
{
 FILE *fp;
 int c = 0;
 fp = fopen("Record.txt", "r");
 while (!feof(fp))
 {
  fread(&stud, sizeof(stud), 1, fp);

  if (rno == stud.rollno)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}

int empty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("Record.txt", "r");
 while (fread(&stud, sizeof(stud), 1, fp))
  c = 1;
 fclose(fp);
 return c;
}

void main()
{
 int c, emp;
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. DELETE\n\t4. UPDATE\n\t5. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   break;
  case 2:
   emp = empty();
   if (emp == 0)
    printf("\nThe file is EMPTY\n");
   else
    disp();
   break;
  case 3:
   deletefile();
   break;
  case 4:
   update();
   break;
  case 5:
   exit(1);
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 5);
}
