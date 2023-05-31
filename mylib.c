// Importing Libraries
#include <stdio.h>
#include "mylib.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdbool.h>
#include <stdbool.h>

static unsigned int id= 1; // id automatic assignment

//  Creating a fuction which Insert at the beginning of the list
void InserisciTestaLista(booklist_t *pl){
Cell_t *p = malloc(sizeof(Cell_t));
    printf("\nGentile utente inserisca il titolo del libro \n");
    scanf("%s",p->book.titolo);
    printf("Gentile utente inserisca il nome dell'autore del libro\n");
    scanf("%s",p->book.autore);
    int genre;
    while(1){
    printf("Gentile utente inserisca il genere del libro sapendo che al numero 0 corrisponde il genere Thriller,al numero 1 il genere Novel,al numero 2 il genere Fantasy,al numero 3 il genere Horror, al numero 4 il genere History\n");
    scanf("%d",&genre);
    if(genre > -1 && genre < 5 ){
      p->book.gen=genre;
      break;
    }
  }
    printf("Gentile utente inserisca l'anno di pubblicazione del libro \n");
    scanf("%hd",&(p->book.anno_pubblicazione.year));
int month;
 while(1){                                // creo un ciclo while per l'assegnamento dei mesi
    printf("Gentile utente inserisca il mese di pubblicazione del libro tenendo in considerazione che in un anno ci sono un massimo di 12 mesi  \n");
    scanf(" %d",&month);
    if (month>0 && month<13){             // il ciclo è costruito in modo che se viene inserito un numero non esatto esso ripete lo stesso comando
        p->book.anno_pubblicazione.month = month;
        break;
 }
}

// creo un ciclo while per l'assegnamento dei  giorni
// il ciclo è costruito in modo che se viene inserito un numero non esatto esso ripete lo stesso comando
int days;
    while(1){
    printf("Gentile utente inserisca il giorno di pubblicazione del libro tenendo in considerazione che i numeri dei giorni vanno da 1 a 31 \n");
    scanf(" %d",&days);
    if (days>0 && days<32){
        p->book.anno_pubblicazione.day=days;
        break;
 }
}
    printf("Gentile utente inserisca il numero di copie della biblioteca \n");
    scanf("%d",&(p->book.copie_biblioteca));
    p->book.unsigned_id= id++;
// logica puntatori per inserire elementi in cima alla lista
if(pl->pfirst==NULL){
        pl->pfirst= p;
        pl->plast=p;
        p->pnext= NULL;
 } else{
    p->pnext= pl->pfirst;
    pl->pfirst=p;
 }
}

//  Creating a fuction which Insert at the end of the list
// Per compiere questa azione utilizzo i puntatori
void InserisciCodaLista (booklist_t *pl){
Cell_t* p =malloc(sizeof(Cell_t));
    printf("\nGentile utente inserisca il titolo del libro\n");
    scanf("%s",p->book.titolo);
    printf("Gentile utente inserisca il nome dell'autore del libro\n");
    scanf(" %s",p->book.autore);
    int genre;
    while(1){
    printf("Gentile utente inserisca il genere del libro sapendo che al numero 0 corrisponde il genere Thriller,al numero 1 il genere Novel,al numero 2 il genere Fantasy,al numero 3 il genere Horror, al numero 4 il genere History\n");
    scanf("%d",&genre);
    if(genre > -1 && genre < 5 ){
      p->book.gen=genre;
      break;
    }
  }
    printf("Gentile utente inserisca l'anno di pubblicazione del libro \n");
    scanf("%hd",&(p->book.anno_pubblicazione.year));
int month;
 while(1){  // creo un ciclo while per i mesi
    printf("Gentile utente inserisca il mese di pubblicazione del libro tenendo in considerazione che in un anno ci sono un massimo di 12 mesi  \n");
    scanf(" %d",&month);
    if (month>0 && month<13){   // il ciclo è costruito in modo che se viene inserito un numero non esatto esso ripete lo stesso comando
    p->book.anno_pubblicazione.month = month;
    break;
 }
}
int days;
 while(1){ // creo un ciclo while per i giorni
    printf("Gentile utente inserisca il giorno di pubblicazione del libro tenendo in considerazione che i numeri dei giorni vanno da 1 a 31 \n");
    scanf(" %d",&days);
    if (days>0 && days<32){   // il ciclo è costruito in modo che se viene inserito un numero non esatto esso ripete lo stesso comando
        p->book.anno_pubblicazione.day=days;
        break;
 }
}
    printf("Gentile utente inserisca il numero di copie della biblioteca \n");
    scanf("%d",&(p->book.copie_biblioteca));
    p->book.unsigned_id= id++;
 // logica puntatori per inserire elementi in fondo alla lista
 if(pl->pfirst==NULL){
    pl->pfirst= p;
    p->pnext= NULL;
    pl->plast=p;
 } else {
    (pl->plast)->pnext=p;
    pl->plast=p;
    p->pnext=NULL;
  }
 }

//  Creating a fuction which Remove element at the beginning of the list
// Per compiere questa azione utilizzo i puntatori
void RimuoviTestaLista(booklist_t *pl){
Cell_t *p = pl->pfirst;
printf("É stato rimosso l'elemento in testa alla lista\n");
if(pl->pfirst!=NULL){
    p=pl->pfirst->pnext;
    free(pl->pfirst);
    pl->pfirst=p;
    if (pl->pfirst==NULL){
        pl->plast=NULL;
    }
 }
}

//  Creating a fuction which Remove element at the end of the list
void RimuoviCodaLista (booklist_t *pl){
Cell_t *p = pl->pfirst ;
Cell_t *q = p ;
printf("É stato rimosso l'elemento in coda alla lista\n");
int T = 999 ;
if(pl->pfirst!=pl->plast){
    do {
        if(p->pnext == pl->plast)
          T=0 ;
        else
          p=p->pnext ;
    } while(T == 999);
    p->pnext = NULL;
    free(pl->plast);
    pl->plast = p;
    return;
} else{
    if (pl->pfirst != NULL) {
        pl->pfirst = NULL;
        free(pl->plast);
        pl->plast = NULL;
        return;
    }
    return;
}
}

//  Creating a fuction which Print list's element
// Utilizzo un ciclo while in modo che mi stampi tutti i campi della lista
void StampaLista (booklist_t *pl){
Cell_t *p= pl->pfirst;
 while(p!=NULL){
    printf("\nTitolo del libro : %s \n",p->book.titolo);
    printf("Nome autore :%s \n",p->book.autore);
    printf("Genere libro :%d \n",p->book.gen);
    printf("Anno pubblicazione libro : %d \n",p->book.anno_pubblicazione.year);
    printf("Mese pubblicazione libro :%d  \n",p->book.anno_pubblicazione.month);
    printf("Giorno pubblicazione libro :%d  \n",p->book.anno_pubblicazione.day);
    printf("Copie biblioteca :%d  \n",p->book.copie_biblioteca);
    printf("Numero id :%d \n",p->book.unsigned_id);
    p=p->pnext;                                                                       // scrivo così per tutti i campi finchè non arrivo all'ultimo e scrivo p=p->pnext
 }
}

//  Creating a fuction which Print list's element with specific id
void StampaElementoConUnDatoID (booklist_t *pl){
 Cell_t *p= pl->pfirst;
  int idlocale;
  scanf("%d",&idlocale);                                                                // Uso scanf in modo da selezionare l'id che intendo prendere
 while(p!=NULL){                                                                        // Scorro la lista con un ciclo while e una volta trovato lo stampo
    if(p->book.unsigned_id==idlocale){
    printf("\nTitolo del libro : %s \n",p->book.titolo);
    printf("Nome autore :%s \n",p->book.autore);
    printf("Genere libro :%d \n",p->book.gen);
    printf("Anno pubblicazione libro : %d \n",p->book.anno_pubblicazione.year);
    printf("Mese pubblicazione libro :%d  \n",p->book.anno_pubblicazione.month);
    printf("Giorno pubblicazione libro :%d  \n",p->book.anno_pubblicazione.day);
    printf("Copie biblioteca :%d  \n",p->book.copie_biblioteca);
    printf("Numero id :%d \n",p->book.unsigned_id);
    p=p->pnext;
    break;
 }
    p=p->pnext;
  }
}

//  Creating a fuction which Delete list's element with specific id
void CancellaElementoConUnDatoID (booklist_t *pl){
  Cell_t *p= pl->pfirst;
  int idlocale;
  printf("Inserisci l\'id da cancellare : ");
  scanf("%d",&idlocale);                                   // Utilizzo scanf in modo da poter prendere l'elemento con l'id interessato
  // vuol dire che l'id è in testa.
  if (p->book.unsigned_id==idlocale){
     RimuoviTestaLista(pl);
     return;
   }
  while(p!=NULL){            // Utilizzo un ciclo per scorrere la lista
    if((p->pnext != NULL) && (p->pnext->book.unsigned_id==idlocale)) {
      if (p->pnext == pl->plast) {
        RimuoviCodaLista(pl);         // Trovato l'elemento e selezionato lo cancello
        return;
      }
    Cell_t *q= p->pnext->pnext; // Aggiorno la lista
    free(p->pnext);
    p->pnext=q;
    break;
    } 
    else {
    p=p->pnext;
    }
  }
}

//  Creating a fuction which Find book with specific id
void CercaLibroLista (booklist_t *pl){

  Cell_t *p= pl->pfirst;
  int idlocale;
  scanf("%d",&idlocale);                   // Per fare questo utilizzo la funzione scanf in modo da poter scegliere l'id che cercavo e poi selezionarlo
  while(p!=NULL){
    if(p->book.unsigned_id==idlocale){
      printf("\nTitolo del libro : %s \n",p->book.titolo);
      printf("Nome autore :%s \n",p->book.autore);
      printf("Genere libro :%d \n",p->book.gen);
      printf("Anno pubblicazione libro : %d \n",p->book.anno_pubblicazione.year);
      printf("Mese pubblicazione libro :%d  \n",p->book.anno_pubblicazione.month);
      printf("Giorno pubblicazione libro :%d  \n",p->book.anno_pubblicazione.day);
      printf("Copie biblioteca :%d  \n",p->book.copie_biblioteca);
      printf("Numero id :%d \n",p->book.unsigned_id);
      p=p->pnext;
      break;
    }
 p=p->pnext;  // Una volta selezionato la lista si aggiorna automaticamente
 }
}

//  Creating a fuction which Loan book with specific id  
void PrestaLibroConUnDeterminatoID(booklist_t *pl){
  Cell_t*p=pl->pfirst;
  int idlocale;
  printf("Inserisci l\'id del libro da prendere in prestito:"); // selezione l’elemento da trovare
  scanf("%d",&idlocale);
  int T = 999 ;
    do {      // scorro tutta la lista uso ciclo do-while per trovare l’elemento in questione
      if(p->book.unsigned_id == idlocale){
        if (p->book.copie_biblioteca > 0)
        p->book.copie_biblioteca= p->book.copie_biblioteca  - 1;    // trovato l’elemento faccio aggiornare la lista in modo di avere la lista senza l’elemento uscito
      else{
        printf("Non posso prestarti il libro con id= %d \n", idlocale );
      }
        return;
      }
      else
        p=p->pnext ;
        } while(T == 999);
        return;
}

//  Creating a fuction which Return book with specific id
void RiprendiLibroConUnDeterminatoID (booklist_t *pl){
  Cell_t*p=pl->pfirst;
  int idlocale;
  printf("Inserisci l\'id del libro da restituire:"); // Selezione elemento da trovare
  scanf("%d",&idlocale);
  int T = 999 ;
      do {                                                                                // Uso un ciclo do-while per scorrere la lista
          if(p->book.unsigned_id == idlocale){
              p->book.copie_biblioteca= p->book.copie_biblioteca  + 1;                    // Trovato l’ elemento aggiorno la lista in modo di avere la lista con l’elemento incrementato
              printf("E\' stato riportato il libro con id= %d \n", idlocale );
              return;
          }
          else
            p=p->pnext ;
      } while(T == 999);
      return;
}
