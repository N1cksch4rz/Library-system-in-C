// Importing Libraries
#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

booklist_t ListaLibri ;

// Main function created
// User message
// Different messages for the user

int main (){
  long int c;
  while(1){
    printf("\n Dear User!\n");                                            // Welcome message
    printf("1: Element at the beginning of the list \n");                 // First message
    printf("2: Element at the end of the list \n");                       // Second message
    printf("3: Print one element \n");                                    // Third message
    printf("4: Remove an element at the beginning of the list \n");       // Fourth message
    printf("5: Remove an element at the end of the list \n");             // Fifth message
    printf("6: Print list element with a specific id \n");                // Sixth message
    printf("7: Delete a specific list element \n");                       // Seventh message 
    printf("8: Find for a book with a specific id \n");                   // Eight message
    printf("9: Loan a book with a specific id \n");                       // Ninth message
    printf("10: Return a book with a specific id \n");                    // Tenth message
    printf("\n• To stop the program execution press ctrl+z\n\n\n");       // Message to stop the program execution
    scanf("%ld",&c);

    switch (c){
        case 1:  {InserisciTestaLista(&ListaLibri); break;}               //  Insert at the beginning of the list
        case 2:  {InserisciCodaLista(&ListaLibri) ; break;}               //  Insert at the end of the list
        case 3:  {StampaLista(&ListaLibri); break;}                       //  Print the list with its elements
        case 4:  {RimuoviTestaLista(&ListaLibri); break;}                 //  Remove element at the beginning of the list
        case 5:  {RimuoviCodaLista(&ListaLibri); break;}                  //  Remove element at the end of the list
        case 6:  {StampaElementoConUnDatoID(&ListaLibri); break;}         //  Print list's element with specific id
        case 7:  {CancellaElementoConUnDatoID(&ListaLibri); break;}       //  Delete list's element with specific id
        case 8:  {CercaLibroLista(&ListaLibri); break;}                   //  Find book with specific id
        case 9:  {PrestaLibroConUnDeterminatoID(&ListaLibri); break;}     //  Loan book with specific id  
        case 10: {RiprendiLibroConUnDeterminatoID(&ListaLibri); break;}   //  Return book with specific id
        Default: break;
  }
 }
}
