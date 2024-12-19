//
//  main.c
//  HW1.8_Exercise1
//
//  Created by Zhihao Shan on 2023/6/4.
//

#include <stdio.h>

// Structure definition for Article
struct Article {
    int articleNumber; // Article number as an integer
    int quantity; // Quantity as an integer
    char description[20]; // Decription as an integer of length 21 maximum
};

// Function to print the details of an article
int Print(const struct Article* article) {
    // Use pointer access struct contents
    printf("Article Number: %d\n", article->articleNumber);
    printf("Quantity: %d\n", article->quantity);
    printf("Description: %s\n", article->description);
    
    return 0;
}

int main() {
    // Create an instance of the Article structure
    struct Article article = { 34959, 15, "Example Article" };

    // Call the Print function and pass the address of the article
    Print(&article);

    return 0;
}
