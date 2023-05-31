// Linked list
// Costruisco le strutture
// Costruisco i generi del libro
// Costruisco le strutture per i puntatori


struct data                     {short year, month, day;};
struct biblioteca               {short inLibrary;};
struct copie                    {short outLibrary;};
struct identificatore           {short id;};
enum genere {
                thriller,
                novel,
                fantasy,
                horror,
                history
 };

// dichiaro la struct libro con i suoi relativi componenti
 typedef struct libro{
                char titolo[64];
                char autore[32];
                enum genere gen;
                struct data anno_pubblicazione;
                int copie_biblioteca;
                int unsigned_id;
} t_libro;

// creo una struct Cell
 typedef struct Cell{

        struct libro book;
        struct Cell *pnext;

 } Cell_t ;

 // creo una struct Booklist
 typedef struct Booklist {

                 Cell_t *pfirst;
                 Cell_t  *plast;
 } booklist_t ;

 void InserisciTestaLista(booklist_t *pl);                     //  Creating a fuction which Insert at the beginning of the list
 void InserisciCodaLista(booklist_t *pl);                      //  Creating a fuction which Insert at the end of the list
 void StampaLista(booklist_t *pl);                             //  Creating a fuction which Print the list with its elements
 void RimuoviTestaLista(booklist_t *pl);                       //  Creating a fuction which Remove element at the beginning of the list
 void RimuoviCodaLista(booklist_t *pl);                        //  Creating a fuction which Remove element at the end of the list
 void StampaElementoConUnDatoID(booklist_t *pl);               //  Creating a fuction which Print list's element with specific id     
 void CancellaElementoConUnDatoID(booklist_t *pl);             //  Creating a fuction which Delete list's element with specific id      
 void CercaLibroLista(booklist_t *pl);                         //  Creating a fuction which Find book with specific id
 void PrestaLibroConUnDeterminatoID(booklist_t *pl);           //  Creating a fuction which Loan book with specific id 
 void RiprendiLibroConUnDeterminatoID(booklist_t *pl);         //  Creating a fuction which Return book with specific id



//  Creating a fuction which Insert at the beginning of the list
//  Creating a fuction which Insert at the end of the list
//  Creating a fuction which Print the list with its elements
//  Creating a fuction which Remove element at the beginning of the list
//  Creating a fuction which Remove element at the end of the list
//  Creating a fuction which Print list's element with specific id
//  Creating a fuction which Delete list's element with specific id
//  Creating a fuction which Find book with specific id
//  Creating a fuction which Loan book with specific id  
//  Creating a fuction which Return book with specific id