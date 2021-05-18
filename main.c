#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Taxi {
int id;
char[20] driver;
char[20] category;  //standard, Business, Family
char[7] plate;
char[20] color;
float rate;
float minCharge;
char state;
struct Taxi *next;
};

struct Taxi *list = NULL;

void addTripCar();
void setTripCar (char* category, float rate);
void writeCarsInRide (char* fileName);
void printList();



int main()
{
    addTripCar();
    printf("The Available Trip Cars: \n");
    printList();

char *s1 ="Business";
char *s2 ="Family";
char *s3 ="Family";
char *s4 ="standard";
char *s5 ="standard";

setTripCar(s1,4.5);
setTripCar(s2,5.0);
setTripCar(s3,4.0);
setTripCar(s4,3.4);
setTripCar(s5,5.0);

printf("----------------------------------------------------\n The Cars in Ride: \n");
printList();

char *fn = "Taxies.txt";
writeCarsInRide(fn);

    return 0;
}


void addTripCar(){

 struct Taxi *head = NULL;
    struct Taxi *current;

    FILE* f;
    int num = 0,i;
    char *header;

   
    f = fopen("Taxies.txt", "r");
            if (f == NULL)
            return;

    while(getc(f) != EOF)
    if (getc(f) == '\n')
      num++;

      fclose(f);


      FILE* fp= fopen("Taxies.txt", "r");
            if (f == NULL)
            return;

    fgets(header, 70, fp);

    for (i=1; i<num; i++) {
        struct Taxi *temp = (struct Taxi*) malloc(sizeof(struct Taxi));
        fscanf(fp, "%d %s %s %s %s %f %f ", &(temp->id), temp->driver, temp->category, temp->plate, temp->color, &(temp->rate), &(temp->minCharge));
        temp->state = 'A';
        temp->next = NULL;

        if( head == NULL) {
        head = temp;
        current = head;}

        else {
        current->next = temp;
        current = current->next; }}

        list = head;
        fclose(fp);

} //addTripCar End


void setTripCar (char* category, float rate){
    if (list == NULL)
        return;

    struct Taxi *current = list;

     while (current != NULL) {
     if( strcmp( current->category, category ) == 0  &&  current->rate == rate) {
       current->state = 'R';
       return;}
       current = current->next;
     }

} //setTripCar End


void writeCarsInRide (char* fileName){
//1
if( list == NULL) { // if the list null will exit the method
   printf("empty list\n");
   return ;
}
//2
FILE  *foutp;
foutp = fopen(fileName, "a"); // Open a file
//3
if (foutp == NULL){ // if there is error in open the file
printf("Error opening file\n");
return;
}
//4

fprintf(foutp ,"--------------------------------------------------------------------------------------------\n");
fprintf(foutp ,"the cars in Ride:\n");
fprintf(foutp , "%-15s %-15s %-20s %-20s %-15s %-20s \n" , "id","driver","category",	"plate","rate" , "state");

//5
struct Taxi *Available  ;
Available = list ; // to point to the list

// start print the info
while( Available != NULL){
if( Available->state == 'R')
fprintf(foutp,"%-15d %-15s %-20s %-20s %-15.1f  %c \n", (Available->id),Available->driver,Available->category,Available->plate,
(Available->rate),Available->state );
Available = Available->next ; // to print the next Available
}//end while loop
fclose(foutp);
} //end method


void printList()
{
struct Taxi *Available;

if( list == NULL) { // if the list null
printf("empty list\n");
return ; }

Available = list; //make it after the last if condition to ensure the list not null

while( Available != NULL){ // to print the info

printf( "%-20d %-20s %-20s %-20s %-20.1f %-20.2f %c \n", (Available->id) , Available->driver , Available->category , Available->plate ,
(Available->rate) , (Available->minCharge) , Available->state );

Available = Available->next ; // to point to the next
}//end while loop
}//end method



