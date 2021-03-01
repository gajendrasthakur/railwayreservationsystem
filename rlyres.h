#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED

struct Train
{char train_no[15];
char from[15];
char to[15];
int fac_fare;
int sac_fare;
};
struct PASSENGER
{
    char p_name[20];
    char gender;
    char train_no[15];
    char p_class;
    char address[40];
    int age;
    int ticket_no;
    char mob_no[15];
};
typedef struct PASSENGER PASSENGER;
typedef struct Train Train;
int enterchoice();
void add_train();
void view_train();
int book_ticket(PASSENGER);
int*get_ticket_no(char*);
void view_ticket(int);
int accept_ticketno();
void view_all_bookings();
void view_bookings(char*);
int del_ticket(int);
int del_train(char*);
int check_train_no(char*);
int check_mob_no(char*);
int get_ticket_count(char*,char);
int last_ticketno();
char* accept_mob_no();
int* get_mob_no(char*);
char* accept_trainno();


PASSENGER*get_passenger_detail();




#endif // RLYRES_H_INCLUDED
