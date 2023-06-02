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
void InsertBeginningList(booklist_t *pl){
    Cell_t *p = malloc(sizeof(Cell_t));
    printf("\nDear user, insert book title \n");
    scanf("%s",p->book.title);
    printf("Dear user, insert name of book's author\n");
    scanf("%s",p->book.author);
    int genre;
    while(1){
      printf("Dear user, please insert the genre of the book, please remember the number that indicates the genre: \n");
      printf("0 Thriller genre");
      printf("1 Novel genre");
      printf("2 Fantasy genre");
      printf("3 Horror genre");
      printf("4 History genre");
      printf("");
      scanf("%d",&genre);
        if(genre > -1 && genre < 5 ){
          p->book.gen=genre;
          break;
        }
    }
    // While loop to insert publication year
    printf("Dear user, insert book's publication year \n");
    scanf("%hd",&(p->book.publication_year.year));
    int month;
    // while loop to check month
      while(1){                                
        printf("Dear user, insert the month, please remember that there are only 12 months\n");
        scanf(" %d",&month);
        // if the user inserts a wrong number, the loop will ask to repeat the action
          if (month>0 && month<13){                   
            p->book.publication_year.month = month;
          break;
          }
      }
      // While loop to insert days
      int days;
          while(1){
              printf("Dear user, insert the day, please remember that the are a maximum of 31 days and a minimum of 1 \n");
              scanf(" %d",&days);
              // if the user inserts a wrong number, the loop will ask to repeat the action
                if (days>0 && days<32){
                  p->book.publication_year.day=days;
                break;
                }
            }
      printf("Dear user, insert the number of copies \n");
      scanf("%d",&(p->book.libraries_copies));
      p->book.unsigned_id= id++;
      // pointers logic to add element at the beginning of the list
      if(pl->pfirst==NULL){
        pl->pfirst= p;
        pl->plast=p;
        p->pnext= NULL;
      }else{
        p->pnext= pl->pfirst;
        pl->pfirst=p;
      }
}

//  Creating a fuction which Insert at the end of the list
void InsertEndList(booklist_t *pl){
    Cell_t* p =malloc(sizeof(Cell_t));
    printf("\nDear user, insert book title\n");
    scanf("%s",p->book.title);
    printf("Dear user, insert name of book's author\n");
    scanf(" %s",p->book.author);
    int genre;
    while(1){
      printf("Dear user, please insert the genre of the book, please remember the number that indicates the genre: \n");
        printf("0 Thriller genre");
        printf("1 Novel genre");
        printf("2 Fantasy genre");
        printf("3 Horror genre");
        printf("4 History genre");
        printf("");
    scanf("%d",&genre);
      if(genre > -1 && genre < 5 ){
        p->book.gen=genre;
        break;
      }
    }
  printf("Dear user, insert book's publication year \n");
  scanf("%hd",&(p->book.publication_year.year));
  // While loop to insert months
  int month;
    while(1){ 
      printf("Dear user, insert the month, please remember that there are only 12 months  \n");
      scanf(" %d",&month);
      // if the user inserts a wrong number, the loop will ask to repeat the action
      if (month>0 && month<13){   
        p->book.publication_year.month = month;
        break;
      }
    }
  // While loop to insert days
  int days;
    while(1){ 
      printf("Dear user, insert the day, please remember that the are a maximum of 31 days and a minimum of 1  \n");
      scanf(" %d",&days);
      // if the user inserts a wrong number, the loop will ask to repeat the action
      if (days>0 && days<32){ 
        p->book.publication_year.day=days;
        break;
      }
    }
    printf("Dear user, insert the number of copies \n");
    scanf("%d",&(p->book.libraries_copies));
    p->book.unsigned_id= id++;
    // pointers logic to add element at the beginning of the list
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
void RemoveBeginningList(booklist_t *pl){
  Cell_t *p = pl->pfirst;
  printf("First element of the list has been removed\n");
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
void RemoveEndList(booklist_t *pl){
  Cell_t *p = pl->pfirst ;
  Cell_t *q = p ;
  printf("The element at the end of the list has been removed\n");
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
void PrintList(booklist_t *pl){
  Cell_t *p= pl->pfirst;
  while(p!=NULL){
    printf("\nBook Title : %s \n",p->book.title);
    printf("Author name :%s \n",p->book.author);
    printf("Book genre :%d \n",p->book.gen);
    printf("Publication year of the book : %d \n",p->book.publication_year.year);
    printf("Publication month of the book :%d  \n",p->book.publication_year.month);
    printf("Publication day of the book:%d  \n",p->book.publication_year.day);
    printf("Libraries copies :%d  \n",p->book.libraries_copies);
    printf("Number id :%d \n",p->book.unsigned_id);
    p=p->pnext;                                                                       
  }
}

//  Creating a fuction which Print list's element with specific id
void PrintListElementID(booklist_t *pl){
  Cell_t *p= pl->pfirst;
  int idlocal;
  scanf("%d",&idlocal);                                                                
  while(p!=NULL){                                                                       
    if(p->book.unsigned_id==idlocal){
      printf("\nBook Title : %s \n",p->book.title);
      printf("Author name :%s \n",p->book.author);
      printf("Book genre :%d \n",p->book.gen);
      printf("Publication year of the book : %d \n",p->book.publication_year.year);
      printf("Publication month of the book :%d  \n",p->book.publication_year.month);
      printf("Publication day of the book:%d  \n",p->book.publication_year.day);
      printf("Libraries copies :%d  \n",p->book.libraries_copies);
      printf("Number id :%d \n",p->book.unsigned_id);
      p=p->pnext;   
      break;
    }
    p=p->pnext;
  }
}
                           
//  Creating a fuction which Delete list's element with specific id
void DeleteListID(booklist_t *pl){
  Cell_t *p= pl->pfirst;
  int idlocal;
  printf("Insert l\'id to delete : ");
  scanf("%d",&idlocal);                                   
  // id it is at the beginning
  if (p->book.unsigned_id==idlocal){
     RemoveEndList(pl);
     return;
   }
  while(p!=NULL){            
    if((p->pnext != NULL) && (p->pnext->book.unsigned_id==idlocal)) {
        if (p->pnext == pl->plast) {
          RemoveEndList(pl);         
          return;
        }
      Cell_t *q= p->pnext->pnext;
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
void SearchBookID(booklist_t *pl); {
  Cell_t *p= pl->pfirst;
  int idlocal;
  scanf("%d",&idlocal);                   
  while(p!=NULL){
    if(p->book.unsigned_id==idlocal){
        printf("\nBook Title : %s \n",p->book.title);
        printf("Author name :%s \n",p->book.author);
        printf("Book genre :%d \n",p->book.gen);
        printf("Publication year of the book : %d \n",p->book.publication_year.year);
        printf("Publication month of the book :%d  \n",p->book.publication_year.month);
        printf("Publication day of the book:%d  \n",p->book.publication_year.day);
        printf("Libraries copies :%d  \n",p->book.libraries_copies);
        printf("Number id :%d \n",p->book.unsigned_id);
        p=p->pnext; 
        break;
      }
    p=p->pnext;
  }
}
                            
//  Creating a fuction which Loan book with specific id  
void LoanBookID(booklist_t *pl){
  Cell_t*p=pl->pfirst;
  int idlocal;
  printf("Insert \'id of book to loan:");
  scanf("%d",&idlocal);
  int T = 999 ;
    do {      
      if(p->book.unsigned_id == idlocal){
        if (p->book.libraries_copies > 0)
        p->book.libraries_copies= p->book.libraries_copies  - 1;
      else{
        printf("I cannot give you the book with id number = %d \n", idlocal);
      }
      return;
      } else
        p=p->pnext ;
      } while(T == 999);
      return;
}

//  Creating a fuction which Return book with specific id
void ReturnBookID(booklist_t *pl){
  Cell_t*p=pl->pfirst;
  int idlocal;
  printf("Insert \'id of book to return:");
  scanf("%d",&idlocal);
  int T = 999 ;
      do {                                                                               
          if(p->book.unsigned_id == idlocal){
              p->book.libraries_copies= p->book.libraries_copies  + 1;                    
              printf("Book with a specific id has been returned, the number of the id= %d \n", idlocal);
              return;
          }
          else
            p=p->pnext ;
      } while(T == 999);
      return;
}
