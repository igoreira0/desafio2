#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./inc/order.h"

void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}

int main(int argc, char *argv[]) {
	char input[201];
        struct node* head = NULL;

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}
                
                if (strncmp(input, "put\n", 3) == 0) {
                    put(&head, getNumber(input));
                    orderListAsc(&head);
                    list(&head);
                }

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}

		print_entry(input);
	}

	return EXIT_SUCCESS;
}