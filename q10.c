#include <stdio.h>

int main() {
    int choice, i, count = 0;
    float balance = 10000, amount;
    char transactions[5][50];

    while(1) {
        printf("\n\n--- ATM MENU ---");
        printf("\n1. Check Balance");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Display Last 5 Transactions");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Balance = %.2f", balance);
        }

        else if(choice == 2) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            balance = balance + amount;

            if(count < 5) {
                sprintf(transactions[count], "Deposited %.2f", amount);
                count++;
            }

            printf("Money deposited successfully.");
        }

        else if(choice == 3) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if(amount <= balance) {
                balance = balance - amount;

                if(count < 5) {
                    sprintf(transactions[count], "Withdrawn %.2f", amount);
                    count++;
                }

                printf("Money withdrawn successfully.");
            }
            else {
                printf("Insufficient balance.");
            }
        }

        else if(choice == 4) {
            printf("\nLast Transactions:\n");

            for(i = 0; i < count; i++) {
                printf("%s\n", transactions[i]);
            }
        }

        else if(choice == 5) {
            printf("Thank you!");
            break;
        }

        else {
            printf("Invalid choice.");
        }
    }

    return 0;
}