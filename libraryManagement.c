#include <windows.h>
#include<stdio.h>
#include<time.h>


void Password();
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void issuebooks(void);
void viewbooks(void);

COORD coord = {0, 0}; // sets coordinates to 0,0
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char password[10]={"project"};
char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"};
char findbook;


FILE *fp,*ft;
int s;

struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
};
struct books a;


int main()

{
      Password();
      getch();
   return 0;

}
void mainmenu()
{
    system("cls");
    system("COLOR F2");
    int i;
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Add Books ");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Delete books");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Search Books");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Issue Books");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. View Book list");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Edit Book's Record");
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Close Application");
    gotoxy(20,19);
    printf("------------------------------------------");
    gotoxy(20,21);
    printf("Enter your choice:");
    switch(getch())
    {
        case '1':
        addbooks();
        break;
    case '2':
        deletebooks();
        break;
        case '3':
        searchbooks();
        break;
    case '4':
        issuebooks();
        break;
        case '5':
        viewbooks();
        break;
        case '6':
        editbooks();
        break;
        case '7':
        {
        system("cls");
        gotoxy(16,3);
        printf("Thanks for using the Program..");
        gotoxy(10,7);
        exit(0);
        }
        default:
        {
        gotoxy(10,23);
        printf("\aWrong Entry!!Please re-entered correct option");
        if(getch())
        mainmenu();
        }

    }
}


void Password(void) //for password option
{

   system("cls");
   char ch,pass[10];
   int i=0;
   gotoxy(10,4);
   printf("******************** Password Protected ********************");
   gotoxy(15,7);
   printf("Enter Password:");

   while(ch!=13)
   {
	ch=getch();
	if(ch!=13 && ch!=8){
	putch('*');
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {

	gotoxy(15,9);
	printf("Password match");
	gotoxy(17,10);
	printf("Press any key to countinue.....");
	getch();
	mainmenu();
   }
   else
   {
	 gotoxy(15,16);
	 printf("\aWarning!! Incorrect Password");
	 getch();
	 Password();
   }
}
void addbooks(void)    //funtion that add books
{
    system("cls");
    int i;
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Computer");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Electronics");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Electrical");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Civil");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Mechanical");
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Architecture");
    gotoxy(20,19);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
    gotoxy(20,21);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,22);
    printf("Enter your choice:");
    scanf("%d",&s);
    if(s==7)

    mainmenu() ;
    system("cls");
    fp=fopen("Bibek.dat","ab+");
    if(getdata()==1)
    {
    a.cat=catagories[s-1];
    fseek(fp,0,SEEK_END);
    fwrite(&a,sizeof(a),1,fp);
    fclose(fp);
    gotoxy(21,14);
    printf("The record is sucessfully saved");
    gotoxy(21,15);
    printf("Save any more?(Y / N):");
    if(getch()=='n')
        mainmenu();
    else
        system("cls");
        addbooks();
    }
}
int getdata()
{
    int t;
    gotoxy(20,3);
    printf("Enter the Information Below");
    gotoxy(20,4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xB2");gotoxy(46,5);printf("\xB2");
    gotoxy(20,6);
    printf("\xB2");gotoxy(46,6);printf("\xB2");
    gotoxy(20,7);
    printf("\xB2");gotoxy(46,7);printf("\xB2");
    gotoxy(20,8);
    printf("\xB2");gotoxy(46,8);printf("\xB2");
    gotoxy(20,9);
    printf("\xB2");gotoxy(46,9);printf("\xB2");
    gotoxy(20,10);
    printf("\xB2");gotoxy(46,10);printf("\xB2");
    gotoxy(20,11);
    printf("\xB2");gotoxy(46,11);printf("\xB2");
    gotoxy(20,12);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(21,5);
    printf("Category:");
    gotoxy(31,5);
    printf("%s",catagories[s-1]);
    gotoxy(21,6);
    printf("Book ID:\t");
    gotoxy(30,6);
    scanf("%d",&t);
    if(checkid(t) == 0)
    {
        gotoxy(21,13);
        printf("\aThe book id already exists\a");
        getch();
        mainmenu();
        return 0;
    }
    a.id=t;
    gotoxy(21,7);
    printf("Book Name:");gotoxy(33,7);
    scanf("%s",a.name);
    gotoxy(21,8);
    printf("Author:");gotoxy(30,8);
    scanf("%s",a.Author);
    gotoxy(21,9);
    printf("Quantity:");gotoxy(31,9);
    scanf("%d",&a.quantity);
    gotoxy(21,10);
    printf("Price:");gotoxy(28,10);
    scanf("%f",&a.Price);
    gotoxy(21,11);
    printf("Rack No:");gotoxy(30,11);
    scanf("%d",&a.rackno);
    return 1;
}
int checkid(int t)  //check whether the book is exist in library or not
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    if(a.id==t)
    return 0;  //returns 0 if book exits
    return 1; //return 1 if it not
}
void deletebooks(void)    //funtion that add books
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
    system("cls");
    gotoxy(10,5);
    printf("Enter the Book ID to  delete:");
    scanf("%d",&d);
    fp=fopen("Bibek.dat","rb+");
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if(a.id==d)
        {

        gotoxy(10,7);
        printf("The book record is available");
        gotoxy(10,8);
        printf("Book name is %s",a.name);
        gotoxy(10,9);
        printf("Rack No. is %d",a.rackno);
        findbook='t';
        }
    }
    if(findbook!='t')
    {
        gotoxy(10,10);
        printf("No record is found modify the search");
        if(getch())
        mainmenu();
    }
    if(findbook=='t' )
    {
        gotoxy(10,9);
        printf("Do you want to delete it?(Y/N):");
        if(getch()=='y')
        {
        ft=fopen("test.dat","wb+");  //temporary file for delete
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id!=d)
            {
            fseek(ft,0,SEEK_CUR);
            fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
            }                              //we want to delete
        }
        fclose(ft);
        fclose(fp);
        remove("Bibek.dat");
        rename("test.dat","Bibek.dat"); //copy all item from temporary file to fp except that
        fp=fopen("Bibek.dat","rb+");    //we want to delete
        if(findbook=='t')
        {
            gotoxy(10,10);
            printf("The record is sucessfully deleted");
            gotoxy(10,11);
            printf("Delete another record?(Y/N)");
        }
        }
    else
    mainmenu();
    fflush(stdin);
    another=getch();
    }
    }
    gotoxy(10,15);
    mainmenu();
}
void editbooks(void)    //funtion that add books
{
    system("cls");
    printf("This is editbooks");
}
void searchbooks(void)    //funtion that add books
{
    system("cls");
    printf("This is searchbooks");
}
void issuebooks(void)    //funtion that add books
{
    system("cls");
    printf("This is issuebooks");
}
void viewbooks(void)    //funtion that add books
{
   int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*********************************Book List*****************************");
    gotoxy(2,2);
    printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
    j=4;
    fp=fopen("Bibek.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
    gotoxy(3,j);
    printf("%s",a.cat);
    gotoxy(16,j);
    printf("%d",a.id);
    gotoxy(22,j);
    printf("%s",a.name);
    gotoxy(36,j);
    printf("%s",a.Author);
    gotoxy(50,j);
    printf("%d",a.quantity);
    gotoxy(57,j);
    printf("%.2f",a.Price);
    gotoxy(69,j);
    printf("%d",a.rackno);
    printf("\n\n");
    j++;
    i=i+a.quantity;
      }
      gotoxy(3,25);
      printf("Total Books =%d",i);
      fclose(fp);
      gotoxy(35,25);
      returnfunc();
}
void returnfunc(void)
{
    {
    printf(" Press ENTER to return to main menu");
    }
    a:
    if(getch()==13) //allow only use of enter
    mainmenu();
    else
    goto a;
}

