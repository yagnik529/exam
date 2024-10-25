// // // 1
// // #include <stdio.h>

// // int main()
// // {
// //     char operator;
// //     double num1, num2, result;

// //     // Display the calculator menu
// //     printf("Simple Calculator\n");
// //     printf("Choose an operator (+, -, *, /): ");
// //     scanf(" %c", &operator);

// //     // Get the numbers from the user
// //     printf("Enter first number: ");
// //     scanf("%lf", &num1);
// //     printf("Enter second number: ");
// //     scanf("%lf", &num2);

// //     // Perform the operation based on the chosen operator
// //     switch (operator)
// //     {
// //     case '+':
// //         result = num1 + num2;
// //         printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
// //         break;
// //     case '-':
// //         result = num1 - num2;
// //         printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
// //         break;
// //     case '*':
// //         result = num1 * num2;
// //         printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
// //         break;
// //     case '/':
// //         // Check for division by zero
// //         if (num2 != 0)
// //         {
// //             result = num1 / num2;
// //             printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
// //         }
// //         else
// //         {
// //             printf("Error: Division by zero is not allowed.\n");
// //         }
// //         break;
// //     default:
// //         printf("Error: Invalid operator.\n");
// //         break;
// //     }

// //     return 0;
// // }

// // 2

// #include <stdio.h>

// int sumArray(int arr[], int size)
// {
//     int sum = 0;
//     for (int i = 0; i < size; i++)
//     {
//         sum += arr[i];
//     }
//     return sum;
// }

// int main()
// {
//     int arr[100], n, result;

//     printf("Enter the number of elements in the array: ");
//     scanf("%d", &n);

//     printf("Enter %d elements:\n", n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     result = sumArray(arr, n);

//     printf("Sum of elements in the array: %d\n", result);

//     return 0;
// }

// 3
#include <stdio.h>

void printReverseAndSum(int arr[], int size)
{
    int sum = 0;

    // Print the elements in reverse order
    printf("Array elements in reverse order:\n");
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
        sum += arr[i]; // Calculate the sum
    }

    printf("\n");
    // Print the sum of the elements
    printf("Sum of all elements: %d\n", sum);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printReverseAndSum(arr, size);

    return 0;
}

// 4
#include <stdio.h>

void calculateCubes(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = *(arr + i) * *(arr + i) * *(arr + i);
    }
}

int main()
{
    int arr[5], i;

    // Input elements in the array
    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Function call to calculate cubes
    calculateCubes(arr, 5);

    // Display the cube of each element
    printf("Cubes of the elements are:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// 5
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

// Structure to represent a book
struct Book
{
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    float price;
};

void inputBookDetails(struct Book *book)
{
    printf("Enter title: ");
    getchar(); // To consume the newline character
    fgets(book->title, TITLE_LENGTH, stdin);
    book->title[strcspn(book->title, "\n")] = 0; // Remove newline character

    printf("Enter author: ");
    fgets(book->author, AUTHOR_LENGTH, stdin);
    book->author[strcspn(book->author, "\n")] = 0; // Remove newline character

    printf("Enter price: ");
    scanf("%f", &book->price);
}

void displayBookDetails(struct Book book)
{
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Price: %.2f\n", book.price);
}

int main()
{
    int N;
    struct Book books[MAX_BOOKS];

    printf("Enter the number of books: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        printf("\nEnter details for book %d:\n", i + 1);
        inputBookDetails(&books[i]);
    }

    printf("\nBook Details:\n");
    for (int i = 0; i < N; i++)
    {
        printf("\nDetails for book %d:\n", i + 1);
        displayBookDetails(books[i]);
    }

    return 0;
}

// 6
#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 3
#define NAME_LENGTH 50
#define ROLE_LENGTH 50

int main()
{
    FILE *file;
    char names[MAX_EMPLOYEES][NAME_LENGTH];
    char roles[MAX_EMPLOYEES][ROLE_LENGTH];

    // Open the file for writing
    file = fopen("data.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1; // Exit with error
    }

    // Input employee details
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        printf("Enter name of employee %d: ", i + 1);
        fgets(names[i], NAME_LENGTH, stdin);
        printf("Enter role (designation) of employee %d: ", i + 1);
        fgets(roles[i], ROLE_LENGTH, stdin);
    }

    // Write to the file
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        // Remove newline characters from the input
        names[i][strcspn(names[i], "\n")] = 0;
        roles[i][strcspn(roles[i], "\n")] = 0;
        fprintf(file, "Employee %d: Name: %s, Role: %s\n", i + 1, names[i], roles[i]);
    }

    // Close the file
    fclose(file);

    printf("Employee data written to data.txt successfully.\n");
    return 0;
}
