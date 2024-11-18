#include <stdio.h>
#include<conio.h>
#include <string.h>
#define MAX_LEN 16

int setu[MAX_LEN], u;

// Function to check if an element belongs to the universal set
int is_element_in_universal(int element) {
    int i;
    for (i = 0; i < u; i++) {
	if (setu[i] == element)
	    return 1;
    }
    return 0;
}

// Function to create a set, ensuring elements belong to the universal set
void set_creation(int setn[], int *n, int is_universal) {
    int i, temp;
    printf("Enter the number of elements in the SET: ");
    scanf("%d", n);
    printf("Enter the elements in the SET:\n");
    for (i = 0; i < *n; i++) {
	scanf("%d", &temp);

	// If creating a subset, ensure elements are in the universal set
	if (!is_universal && !is_element_in_universal(temp)) {
	    printf("Element %d is not in the universal set! Try again.\n", temp);
	    i--; // Retry current element
	} else {
	    setn[i] = temp;
	}
    }
}

void bitString(int setn[], int n, char bitstr[]) {
    int i, j;
    for (i = 0; i < u; i++)
	bitstr[i] = '0';
    for (i = 0; i < n; i++) {
	for (j = 0; j < u; j++) {
	    if (setn[i] == setu[j]) {
		bitstr[j] = '1';
		break;
	    }
	}
    }
    bitstr[u] = '\0';
    printf("Bitstring form: %s\n", bitstr);
}

void setUnion(char strbit1[], char strbit2[]) {
    int i, j = 0, resultset[MAX_LEN];
    char result[MAX_LEN];
    for (i = 0; i < u; i++) {
	if (strbit1[i] == '1' || strbit2[i] == '1') {
	    result[i] = '1';
	    resultset[j++] = setu[i];
	} else {
	    result[i] = '0';
	}
    }
    result[u] = '\0';
    printf("UNION as bitstring: %s\n", result);
    printf("UNION as set values: ");
    for (i = 0; i < j; i++)
	printf("%d ", resultset[i]);
    printf("\n");
}

void setInter(char strbit1[], char strbit2[]) {
    int i, j = 0, resultset[MAX_LEN];
    char result[MAX_LEN];
    for (i = 0; i < u; i++) {
	if (strbit1[i] == '1' && strbit2[i] == '1') {
	    result[i] = '1';
	    resultset[j++] = setu[i];
	} else {
	    result[i] = '0';
	}
    }
    result[u] = '\0';
    printf("INTERSECTION as bitstring: %s\n", result);
    printf("INTERSECTION as set values: ");
    for (i = 0; i < j; i++)
	printf("%d ", resultset[i]);
    printf("\n");
}

void setDiff(char strbit1[], char strbit2[]) {
    int i, j = 0, resultset[MAX_LEN];
    char result[MAX_LEN];
    for (i = 0; i < u; i++) {
	if (strbit1[i] == '1' && strbit2[i] == '0') {
	    result[i] = '1';
	    resultset[j++] = setu[i];
	} else {
	    result[i] = '0';
	}
    }
    result[u] = '\0';
    printf("DIFFERENCE as bitstring: %s\n", result);
    printf("DIFFERENCE as set values: ");
    for (i = 0; i < j; i++)
	printf("%d ", resultset[i]);
    printf("\n");
}

int main() {
    int seta[MAX_LEN], a, setb[MAX_LEN], b, c;
 clrscr();
    char bitstr1[MAX_LEN + 1], bitstr2[MAX_LEN + 1];

    printf("UNIVERSAL SET:\n");
    set_creation(setu, &u, 1); // is_universal = 1
    printf("SET A:\n");
    set_creation(seta, &a, 0); // is_universal = 0
    bitString(seta, a, bitstr1);
    printf("SET B:\n");
    set_creation(setb, &b, 0); // is_universal = 0
    bitString(setb, b, bitstr2);

    printf("\n1. UNION\n2. INTERSECTION\n3. DIFFERENCE\n4. EXIT\n");
    do {
	printf("\nEnter your choice: ");
	scanf("%d", &c);
	switch (c) {
	case 1:
	    setUnion(bitstr1, bitstr2);
            break;
        case 2:
            setInter(bitstr1, bitstr2);
            break;
        case 3:
            setDiff(bitstr1, bitstr2);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid input.\n");
        }
    } while (c != 4);

    return 0;
}