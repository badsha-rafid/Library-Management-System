#include <stdio.h>
#include <string.h>

struct Book 
{
    char title[100];
    char author[200];
    char publisher[100];
};

struct Edition 
{
    char serial[100];
    char year[10];
};

int main() 
{
    struct Book books[1000];
    struct Edition editions[1000];
    int numBooks = 0;
    
    FILE *fptr;
    
    fptr = fopen("books.txt", "w");
    
    if (fptr == NULL) 
    {
        printf("Error opening the file.\n");
        return 1;
    }

        fprintf(fptr, "\t\t\t_____________________________________\n");
        fprintf(fptr, "\t\t\t|                                   |\n");
        fprintf(fptr, "\t\t\t|      Lybrary Books Details        |\n");
        fprintf(fptr, "\t\t\t_____________________________________\n");
        fprintf(fptr, "\n\n");

    
    while (1) 
    {
        
        printf("\n\t\t\t\t     Library Management System       \t\t\t\t\t\n\n");
        printf("\t\t\t                 Department Of CSE                 \t\n");
        printf("\t\t\t          United International University        \t\n\n");
        printf("\t\t\t=================================================\t\t\t\t\n\n\n");
        printf("\t\t\t\tSelect The Operation Which You Want \t\t\n\n");
        printf("\t\t____________________________________________________________________\t\t\t\n");
        printf("\t\t|\t\t\t\t          \t\t\t    |\n");
        printf("\t\t|\t\t\t\t          \t\t\t    |\n");
        printf("\t\t|        1 ) Books\t\t\t   2 ) About Us             |\n");
        printf("\t\t|\t\t\t\t          \t\t\t    |\n");
        printf("\t\t|\t\t\t   0 ) Exit    \t\t\t\t    |\n");
        printf("\t\t|\t\t\t\t          \t\t\t    |\n");
        printf("\t\t|___________________________________________________________________|\t\t\t\n\n");
        printf("\t\t==>: ");
        
        int choice;
        scanf("%d", &choice);

        if (choice == 1) 
        {
            if (numBooks < 1000) 
            {
                printf("Book %d Title: ", numBooks + 1);
                getchar();  // Consume newline character from previous input
                fgets(books[numBooks].title, sizeof(books[numBooks].title), stdin);

                printf("Book %d Author: ", numBooks + 1);
                fgets(books[numBooks].author, sizeof(books[numBooks].author), stdin);

                printf("Book %d Publisher: ", numBooks + 1);
                fgets(books[numBooks].publisher, sizeof(books[numBooks].publisher), stdin);

                printf("Book %d Serial: ", numBooks + 1);
                fgets(editions[numBooks].serial, sizeof(editions[numBooks].serial), stdin);

                printf("Book %d Year: ", numBooks + 1);
                fgets(editions[numBooks].year, sizeof(editions[numBooks].year), stdin);

                printf("!----Saved----!\n\n");
                numBooks++;
                
                
                fprintf(fptr, "Book %d:\n", numBooks);
                fprintf(fptr, "Title: %s", books[numBooks - 1].title);
                fprintf(fptr, "Author: %s", books[numBooks - 1].author);
                fprintf(fptr, "Publisher: %s", books[numBooks - 1].publisher);
                fprintf(fptr, "Serial: %s", editions[numBooks - 1].serial);
                fprintf(fptr, "Year: %s\n", editions[numBooks - 1].year);
            } 
            else 
            {
                printf("Maximum number of books reached.\n");
            }
        
        }
        if (choice == 2)
        {
            fprintf(fptr,"\n\n\n\n\n\n\n\n");
            fprintf(fptr,"\t\t\t\t{                  About Us                 }\n\n");
            fprintf(fptr,"\t\t\t\t ___________________________________________\n");
            fprintf(fptr,"\t\t\t\t|                                           |\n");
            fprintf(fptr,"\t\t\t\t|               Rafid Shabab                |\n");
            fprintf(fptr,"\t\t\t\t|                                           |\n");
            fprintf(fptr,"\t\t\t\t|          Programmer & Developer           |\n");
            fprintf(fptr,"\t\t\t\t|             Dept. of CSE, UIU             |\n");
            fprintf(fptr,"\t\t\t\t|                                           |\n");
            fprintf(fptr,"\t\t\t\t| Contact: rpatwary2310071@bscse.uiu.ac.bd  |\n");
            fprintf(fptr,"\t\t\t\t|___________________________________________|\n\n\n\n\n\n\n");
        } 
        else if (choice == 0) 
        {
            break;
        } 
        else 
        {
            printf("Invalid choice. Please enter 1 to add a book or 2 for about us or 0 to exit.\n");
        }
    }
    
    fclose(fptr);
    
    return 0;
}
