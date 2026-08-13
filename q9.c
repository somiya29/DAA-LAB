#include <stdio.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int total;
    int available;
};

int main() {
    struct Book b[100];
    int n = 0;
    int choice, id, i, found;

    while(1) {
        printf("\n\n1. Add Book");
        printf("\n2. Search Book");
        printf("\n3. Issue Book");
        printf("\n4. Return Book");
        printf("\n5. Display Unavailable Books");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter book ID: ");
            scanf("%d", &b[n].id);

            printf("Enter title: ");
            scanf(" %[^\n]", b[n].title);

            printf("Enter author: ");
            scanf(" %[^\n]", b[n].author);

            printf("Enter total copies: ");
            scanf("%d", &b[n].total);

            b[n].available = b[n].total;
            n++;

            printf("Book added successfully.");
        }

        else if(choice == 2) {
            printf("Enter book ID: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < n; i++) {
                if(b[i].id == id) {
                    printf("\nTitle: %s", b[i].title);
                    printf("\nAuthor: %s", b[i].author);
                    printf("\nTotal copies: %d", b[i].total);
                    printf("\nAvailable copies: %d", b[i].available);
                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("Book not found.");
        }

        else if(choice == 3) {
            printf("Enter book ID: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < n; i++) {
                if(b[i].id == id) {
                    found = 1;

                    if(b[i].available > 0) {
                        b[i].available--;
                        printf("Book issued successfully.");
                    }
                    else {
                        printf("Book is unavailable.");
                    }

                    break;
                }
            }

            if(found == 0)
                printf("Book not found.");
        }

        else if(choice == 4) {
            printf("Enter book ID: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < n; i++) {
                if(b[i].id == id) {
                    found = 1;

                    if(b[i].available < b[i].total) {
                        b[i].available++;
                        printf("Book returned successfully.");
                    }
                    else {
                        printf("All copies are already available.");
                    }

                    break;
                }
            }

            if(found == 0)
                printf("Book not found.");
        }

        else if(choice == 5) {
            printf("\nUnavailable Books:\n");

            found = 0;

            for(i = 0; i < n; i++) {
                if(b[i].available == 0) {
                    printf("%d - %s\n", b[i].id, b[i].title);
                    found = 1;
                }
            }

            if(found == 0)
                printf("No books are currently unavailable.");
        }

        else if(choice == 6) {
            break;
        }

        else {
            printf("Invalid choice.");
        }
    }

    return 0;
}