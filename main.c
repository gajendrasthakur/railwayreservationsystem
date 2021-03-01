#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"rlyres.h"
int main()
{
    int choice;
    add_train();
    while(1)
            {
                textcolor(YELLOW);
                clrscr();
                choice=enterchoice();
                switch(choice)
                {


                   case 9:
                  {
                     textcolor(LIGHTBLUE);
                     printf("\t\t\tThankyou!""HAPPY JOURNEY""\n");
                     textcolor(WHITE);
                     return 0;

                   }
                   case 1:
                  {
                     clrscr();
                     view_train();
                     getch();
                     break;
                   }
                   case 2:
                 {
                    clrscr();
                    PASSENGER*p=get_passenger_detail();
                    if(p!=NULL)
                   {
                     int ticketno1 =  book_ticket(*p);
                     if(ticketno1==-1)
                     printf("booking failed");
                    else
                   {textcolor(GREEN);
                    printf("booking SUCCESSFUL\n\n");
                    printf("your ticket no is =%d",ticketno1);
                    }
                    getch();
                    break;

                   }
                   break;
                 }

                 case 3:
                 {
                  int b=accept_ticketno();
                  if(b!=0)
                  {
                    view_ticket(b);
                    getch();
                    break;
                  }
                else
                    break;
                 }
      case 4:
        {clrscr();
            char*p=accept_mob_no();
            if(p!=NULL)
            {
              int*u= get_mob_no(p);
              view_all_ticket(p,u);
            }
            clrscr();
            break;
        }
      case 5:
        view_all_bookings();
        getch();
        break;
      case 6:
        {clrscr();
        char*a=accept_trainno();
        if(a!=NULL)
        {
            view_bookings(a);
            getch();

        }
        break;
        }
        case 7:
        {
            int a=accept_ticketno();
            if(a!=0)
            {
                int b=del_ticket(a);
                if(b==1)
                {
                    textcolor(RED);
                    clrscr();
                    printf("Ticket DELETED successfully");
                    textcolor(YELLOW);
                }
                else
                {
                    textcolor(RED);
                    clrscr();
                    printf("Ticket  not DELETED successfully");
                    textcolor(YELLOW);
                }
                 getch();
                 break;
            }
        }
case 8:
        {
            char* a=accept_trainno();
            if(a!=NULL)
            {
                int b=del_train(a);
                if(b==1)
                {
                    textcolor(RED);
                    clrscr();
                    printf("train CANCELLED succesfully");
                    textcolor(YELLOW);
                }
                else
                {
                    textcolor(RED);
                    clrscr();
                    printf("TRAIN  not CANCELLED succesfully");
                    textcolor(YELLOW);
                }
                 getch();
                 break;
            }
        }

    default:
           {textcolor(LIGHTRED);
               printf("sorry!wrong input\n");
               getch();
         clrscr();
           }


       }

    }


}
