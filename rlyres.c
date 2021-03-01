#include"rlyres.h"
#include<stdio.h>
#include<string.h>
#include"conio2.h"
int enterchoice()
{
     int c ;
     int i=0;
    printf("\t\t\tRAILWAY RESERVATION SYSTEM\n");
    do
    {
        printf("-");
        i++;
    }while(i<=79);

        printf("1- view Train\n");
        printf("2- book Ticket\n");
        printf("3- view Ticket\n");
        printf("4- Search Ticket.No\n");
        printf("5- view all booking\n");
        printf("6- view Train Booking\n");
        printf("7- cancel Ticket\n");
        printf("8- cancel Train\n");
        printf("9- quit\n");
    printf("\n");
    printf("Enter Your Choice  ");
    scanf("%d",&c);
    return c;
}

void add_train()
{ //Train alltrain1;
    FILE*P;
Train alltrain[4]=
{
    {"101","bhopal","indore",1500,1200},
    {"102","bhopal","mumbai",2000,1000},
    {"103","bhopal","gwalio",1500,1200},
    {"104","bhopal","jabalp",2000,1200},
};
P= fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\alltrains.dat","rb");
if(P==NULL)
{
    P=fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\alltrains.dat","wb");
    fwrite(alltrain,4*sizeof(Train),1,P);

}

    fclose(P);
}
void view_train()
{Train s;
printf("TRAIN_NO\tFROM\t\tTO\t\tF-AC-fare\tS-AC-fare\n");
for(int i=0;i<=79;i++)
{
    printf("~");
}
FILE*p;
p=fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\alltrains.dat","rb");
if(p==NULL)
{
    printf("file not opened");
    return ;
}

while(fread(&s,sizeof(s),1,p)==1)
{
    printf("%s \t\t%s \t\t%s \t\t%d \t\t%d\n",s.train_no,s.from,s.to,s.fac_fare,s.sac_fare);
}
 fclose(p);

}
int check_train_no(char*trno)
{
    Train s;
    FILE*p=fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\alltrains.dat","rb");
    if(p==NULL)
{
    printf("file no opened");
    return ;
}
while(fread(&s,sizeof(Train),1,p)==1)
{
    if(strcmp(trno,s.train_no)==0)
       {
           fclose(p);
           return 1;
       }
}
fclose(p);
return 0;
}
int check_mob_no(char*s)
{int i;
if(strlen(s)!=10)
{
    return 0;
}
    for(i=0;i<=9;)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            i++;
        }
        else
            return 0;

    }
    if(i==10)
        return 1;
}
PASSENGER*get_passenger_detail()
{
   static PASSENGER pdetail;
    //char ch;
    gotoxy(59,1);
    textcolor(BLUE);
    printf("!!PRESS 0 TO CANCEL!!");
    gotoxy(1,1);
    textcolor(YELLOW);

    printf("Enter Name of passenger:");
    fflush(stdin);
    fgets(pdetail.p_name,20,stdin);
    char*a=strchr(pdetail.p_name,'\n');
    *a='\0';
   if(pdetail.p_name[0]=='0')
   { gotoxy(1,25);
   textcolor(RED);
   printf("Booking cancelled!return NULL");
   textcolor(YELLOW);
getch();
       return NULL;
   }


    do
    {printf("\rEnter Gender(M\\F): \b");

        fflush(stdin);
        scanf("%c",&pdetail.gender);
        if((pdetail.gender=='M'||pdetail.gender!='F')&&(pdetail.gender=='F'||pdetail.gender!='M'))
       {
        gotoxy(1,25);
        textcolor(RED);
        printf("gender should be (M\\F)!!!!");
        getch();
        }
        printf("\r\t\t\t\t\t");
        gotoxy(19,2);
        textcolor(YELLOW);

        if(pdetail.gender=='0')
   {gotoxy(1,25);
   textcolor(RED);
   printf("booking cancelled!return NULL");
   textcolor(YELLOW);
       return NULL;
   }


    }while((pdetail.gender=='M'||pdetail.gender!='F')&&(pdetail.gender=='F'||pdetail.gender!='M'));
gotoxy(1,3);
do
{

   printf("\rEnter a train no:   \b\b\b");
  scanf("%s",pdetail.train_no);

        if(pdetail.train_no[0]=='0')
       {
         gotoxy(1,25);
         textcolor(RED);
         printf("Booking cancelled!return NULL");
         textcolor(YELLOW);
         return NULL;
        }
         if(check_train_no(pdetail.train_no)==1)
         {
             break;
         }
         gotoxy(1,25);
         textcolor(RED);
         printf("Train Number not found!!TRY AGAIN");
         getch();
         gotoxy(18,3);
         textcolor(YELLOW);
   }while(1);
   gotoxy(1,4);
   do
    {printf("\rEnter class to be travelled(S for second AC\\F for first AC): \b");

        fflush(stdin);
        scanf("%c",&pdetail.p_class);
        if((pdetail.p_class=='S'||pdetail.p_class!='F')&&(pdetail.p_class=='F'||pdetail.p_class!='S'))
       {
        gotoxy(1,25);
        textcolor(RED);
        printf("Class should be (S\\F)!!!!");
        getch();
        }
        printf("\r\t\t\t\t\t");
        gotoxy(61,4);
        textcolor(YELLOW);

        if(pdetail.p_class=='0')
   {gotoxy(1,25);
   textcolor(RED);
   printf("booking cancelled!return NULL");
   textcolor(YELLOW);
       return NULL;
   }


    }while((pdetail.p_class=='S'||pdetail.p_class!='F')&&(pdetail.p_class=='F'||pdetail.p_class!='S'));
gotoxy(1,5);
printf("Enter address of passenger:");
    fflush(stdin);
    fgets(pdetail.address,40,stdin);
    a=strchr(pdetail.address,'\n');
    a='\0';
   if(pdetail.address[0]=='0')
   { gotoxy(1,25);
   textcolor(RED);
   printf("booking cancelled!return NULL");
   textcolor(YELLOW);

       return NULL;
   }

do
{
    printf("\rEnter a age:   \b\b\b");
    scanf("%d",&pdetail.age);
    if(pdetail.age<0||pdetail.age>=120)
    {
        gotoxy(1,25);
        textcolor(RED);
        printf("Input valid age!!");
        getch();
    }
    printf("\r\t\t\t\t");
    gotoxy(13,6);
    textcolor(YELLOW);
    if(pdetail.age==0)
   { gotoxy(1,25);
   textcolor(RED);
   printf("booking cancelled!return NULL");
   textcolor(YELLOW);

       return NULL;
   }
}while(pdetail.age<0||pdetail.age>120);
gotoxy(1,7);
do
{
    printf("\rEnter a Mob.no:                 \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    fflush(stdin);
    fgets(pdetail.mob_no,12,stdin);
    a=strchr(pdetail.mob_no,'\n');
    *a='\0';
    if(pdetail.mob_no[0]=='0')
   { gotoxy(1,25);
   textcolor(RED);
   printf("booking cancelled!return NULL");
   textcolor(YELLOW);
   return NULL;}
    if(check_mob_no(pdetail.mob_no)==0)
    {
        gotoxy(1,25);
        textcolor(RED);
        printf("Enter valid mob no");
        textcolor(YELLOW);
        getch();
    }
    printf("\r\t\t\t\t");
    gotoxy(16,7);


}while((check_mob_no(pdetail.mob_no)==0));
gotoxy(1,8);
return &pdetail;
}
int get_ticket_count(char*trainno,char Pclass)
{PASSENGER pdetail;
int count=0;
    FILE*fp=fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings.dat","rb");
    if(fp==NULL)
    {fclose(fp);
        return 0;
    }
    while(fread(&pdetail,sizeof(PASSENGER),1,fp)==1)
    {
        if((strcmp(trainno,pdetail.train_no)==0)&&(Pclass==pdetail.p_class))
        {
            count=count+1;
        }

    }
    fclose(fp);
    return count;
}
int last_ticketno()
{PASSENGER pdetail;
    FILE*fp=fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings.dat","rb");
    if(fp==NULL)
    {fclose(fp);
        return 0;
    }
    fseek(fp,-1L*sizeof(PASSENGER),SEEK_END);
    fread(&pdetail,sizeof(PASSENGER),1,fp);
    fclose(fp);
    return pdetail.ticket_no;
}
int book_ticket(PASSENGER P)
{
    if(get_ticket_count(P.train_no,P.p_class)==30)
       {textcolor(RED);
           printf("All seats full in train no=%s,class=%c\n",P.train_no,P.p_class);
           textcolor(YELLOW);
           return-1;
       }
    int ticketno=last_ticketno()+1;
    P.ticket_no=ticketno;
    FILE*fp=fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings.dat","ab");
    if(fp==NULL)
        {textcolor(LIGHTRED);
            printf("booking cancelled due some reason");
            textcolor(YELLOW);
            return-1;
        }
        fwrite(&P,sizeof(PASSENGER),1,fp);
        fclose(fp);
        return P.ticket_no;
}

int accept_ticketno()
{clrscr();
textcolor(GREEN);
gotoxy(62,1);
printf("press 0 to cancel");
textcolor(YELLOW);
gotoxy(1,1);
int a;
    do
    { gotoxy(19,1);
        printf("\rEnter a ticket no:\t\t\t");
 gotoxy(19,1);
        scanf("%d",&a);
      if(a==0)
      {
          return 0;
      }
    }while(a<0);

    return a;

}
void view_ticket(int a)
{PASSENGER  P;
 clrscr();


 FILE*p=fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings.dat","rb");
 if(p==NULL)
 {clrscr();
     printf("Not found due to some reasons");
     return;
 }



 while(fread(&P,sizeof(PASSENGER),1,p)==1)
 {
 if(P.ticket_no==a)
     {textcolor(GREEN);

 printf("* NAME : %s\n* GENDER : %c\n* TRAIN.NO : %s\n* CLASS : %c\n* ADDRESS : %s\n* AGE : %d\n* TICKET.NO : %d\n* MOB.NO : %s",P.p_name,P.gender,P.train_no,P.p_class,P.address,P.age,P.ticket_no,P.mob_no);
 return;
         }
 }
 clrscr();
 gotoxy(1,1);
 textcolor(RED);
 printf("sorry booking not found for this ticket no");
 fclose(p);
}
char* accept_mob_no()
{static char mob_no[12];
char*a;
    do
{gotoxy(1,1);
    printf("\rEnter a Mob.no:                 \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    fflush(stdin);
    fgets(mob_no,12,stdin);
    a=strchr(mob_no,'\n');
    *a='\0';
    if(mob_no[0]=='0')
   { gotoxy(1,25);
   textcolor(RED);
   printf("booking cancelled!return NULL");
   textcolor(YELLOW);
   getch();
   return NULL;}

    if(check_mob_no(mob_no)==0)
    {
        gotoxy(1,25);
        textcolor(RED);
        printf("Enter valid mob no");
        textcolor(YELLOW);
        getch();
    }
    printf("\r\t\t\t\t");
    gotoxy(16,7);


}while(check_mob_no(mob_no)==0);
return mob_no;
}
int*get_mob_no(char*pmob_no)
{int count=0;
PASSENGER P;
    FILE*p=fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings.dat","rb");
    if(p==NULL)
    {
        clrscr();
        textcolor(RED);
        printf("sorry not found due to some issue");
    textcolor(YELLOW);
    return NULL;
    }
    while(fread(&P,sizeof(PASSENGER),1,p)==1)
    {
        if(strcmp(P.mob_no,pmob_no)==0)
        {
            count=count+1;
        }
    }
    if(count==0)
    {
        fclose(p);
        return NULL;
    }
    int*a=(int*)malloc((count+1)*sizeof(int));
    rewind(p);
    int i=0;
    while(fread(&P,sizeof(PASSENGER),1,p)==1)
    {if(strcmp(P.mob_no,pmob_no)==0)
       {
        *(a+i)=P.ticket_no;
        i++;
        }
    }
    *(a+i)=-1;
    fclose(p);
    return a;
}
void view_all_ticket(char*mob_no,int*all_ticketno)
{
    if(all_ticketno==NULL)
    {clrscr();
        textcolor(RED);
        printf("no boking found for mob no %s\n ",mob_no);
        textcolor(GREEN);
        printf("press any key to go in main menu");
        textcolor(YELLOW);
        getch();
        return;
        }
        printf("\rfollowing are the booked ticket for mob=%s",mob_no);

    int i;
    printf("\n\nTICKET NO\n");
    printf("---------");
    for(i=0;*(all_ticketno+i)!=-1;i++)
        printf("\n%d",*(all_ticketno+i));
textcolor(WHITE);
printf("\n\nPress any key to go back to the main screen");
textcolor(YELLOW);
getch();
}
char*accept_trainno()
{static char trainno[15];
    do
    {clrscr();
        gotoxy(1,1);
        printf("\rEnter a train no:\t\t");
        gotoxy(18,1);
        fflush(stdin);
        fgets(trainno,15,stdin);
        char*a=strchr(trainno,'\n');
        *a='\0';
        if(trainno[0]=='0')
        {
            gotoxy(1,25);
            textcolor(RED);
            printf("Booking cancelled!return NULL");
            textcolor(YELLOW);
            getch();
            return NULL;
        }
        if(check_train_no(trainno)==1)
        {break;
        }
        textcolor(RED);
        gotoxy(1,25);
            printf("invalid train no!!!");
            textcolor(YELLOW);
            getch();
        printf("\r\t\t\t\t\t");
    }while(1);

    return &trainno;
}
void view_bookings(char*P)
{
    FILE*p=fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings.dat","rb");
    if(p==NULL)
    {
        printf("File not opened due to some reason");
        return;
    }
    PASSENGER pdetail;
    textcolor(WHITE);
    clrscr();
    printf("Ticket.NO    CLASS    NAME                GENDER     AGE    MOBILE.NO");
    gotoxy(1,2);
    for(int i=1;i<=80;i++)
    {textcolor(WHITE);
        printf("-");
        textcolor(YELLOW);
    }
    int i=3;
    while(fread(&pdetail,sizeof(PASSENGER),1,p)==1)
    {
        if(strcmp(pdetail.train_no,P)==0)
        {
            printf("    %d           %c     %s ",pdetail.ticket_no,pdetail.p_class,pdetail.p_name);
        gotoxy(45,i);
        printf("%c        %d     %s\n",pdetail.gender,pdetail.age,pdetail.mob_no);
        i++;
        }
    }
     for(int i=1;i<=80;i++)
    {textcolor(WHITE);
        printf("-");
        textcolor(YELLOW);
    }
    fclose(p);

}
void view_all_bookings()
{PASSENGER pdetail;
    FILE*p=fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings.dat","rb");
    if(p==NULL)
    {
perror("caused by");
return;
    }textcolor(WHITE);
    clrscr();
    printf("Ticket.NO    CLASS    NAME                GENDER     AGE    MOBILE.NO");
    gotoxy(1,2);
    for(int i=1;i<=80;i++)
    {textcolor(WHITE);
        printf("-");
        textcolor(YELLOW);
    }
    int i=3;

    while(fread(&pdetail,sizeof(PASSENGER),1,p)==1)
    {
         printf("    %d           %c     %s ",pdetail.ticket_no,pdetail.p_class,pdetail.p_name);
        gotoxy(45,i);
        printf("%c        %d     %s\n",pdetail.gender,pdetail.age,pdetail.mob_no);
        i++;
    }
    fclose(p);
}
int del_ticket(int a)
{
    PASSENGER pdetail;
    int found=0;
    FILE*P=fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings.dat","rb");
    FILE*S=fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings2.dat","wb");
    while(fread(&pdetail,sizeof(PASSENGER),1,P)==1)
        { if(pdetail.ticket_no!=a)
           {

            fwrite(&pdetail,sizeof(PASSENGER),1,S);
           }
           else
           {
               found=1;
           }
        }
if(!found)
{ remove("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings2.dat");
fclose(P);
fclose(S);
    return -1;
}

    fseek(S,0,SEEK_END);
    int count=ftell(S)/sizeof(PASSENGER);
    fclose(S);
    fclose(P);
    remove("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings.dat");
    if(count!=0)
    {
    rename("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings2.dat","f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings.dat");
    }
    else
    {
        remove("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings2.dat");
    }
    return found;

}
int del_train(char*a)
{
    PASSENGER pdetail;
    int found=0;
    FILE*P=fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings.dat","rb");
    FILE*S=fopen("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings2.dat","wb");
    while(fread(&pdetail,sizeof(PASSENGER),1,P)==1)
        { if(strcmp(a,pdetail.train_no)!=0)
           {

            fwrite(&pdetail,sizeof(PASSENGER),1,S);
           }
           else
           {
               found=1;
           }
        }
if(!found)
{ remove("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings2.dat");
fclose(P);
fclose(S);
    return -1;
}

    fseek(S,0,SEEK_END);
    int count=ftell(S)/sizeof(PASSENGER);
    fclose(S);
    fclose(P);
    remove("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings.dat");
    getch();
    if(count!=0)
    {
    rename("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings2.dat","f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings.dat");
    }
    else
    {
        remove("f:\\RAILWAYRESERVATIONSYSTEM\\railwayreservationsystem\\allbookings2.dat");
    }
    return found;
}
