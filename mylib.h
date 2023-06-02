// Linked list
// Build struct
// Build book genres
// Build pointer structures

struct date                     {short year, month, day;};
struct library                  {short inLibrary;};
struct copies                   {short outLibrary;};
struct id                       {short id;};
enum genre {
                thriller,
                novel,
                fantasy,
                horror,
                history
 };

// struct book
 typedef struct book{
                char title[64];
                char author[32];
                enum genre gen;
                struct date publication_year;
                int libraries_copies;
                int unsigned_id;
} t_book;

//  struct Cell
 typedef struct Cell{

        struct book book;
        struct Cell *pnext;

 } Cell_t ;

 // struct Booklist
 typedef struct Booklist {

                 Cell_t *pfirst;
                 Cell_t  *plast;
 } booklist_t ;

void InsertBeginningList(booklist_t *pl);                     //  Creating a fuction which Insert at the beginning of the list
void InsertEndList(booklist_t *pl);                           //  Creating a fuction which Insert at the end of the list
void PrintList(booklist_t *pl);                               //  Creating a fuction which Print the list with its elements
void RemoveBeginningList(booklist_t *pl);                     //  Creating a fuction which Remove element at the beginning of the list
void RemoveEndList(booklist_t *pl);                           //  Creating a fuction which Remove element at the end of the list
void PrintListElementID(booklist_t *pl);                      //  Creating a fuction which Print list's element with specific id
void DeleteListID(booklist_t *pl);                            //  Creating a fuction which Delete list's element with specific id      
void SearchBookID(booklist_t *pl);                            //  Creating a fuction which Find book with specific id
void LoanBookID(booklist_t *pl);                              //  Creating a fuction which Loan book with specific id 
void ReturnBookID(booklist_t *pl);                            //  Creating a fuction which Return book with specific id



