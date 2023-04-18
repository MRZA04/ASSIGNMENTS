#include <stdio.h>
#include <stdlib.h>

// Initialize arrays for stock
int small[30], medium[20], large[25];

// Initialize arrays for rented stock
int small_rented[30], medium_rented[20], large_rented[25];

// Initialize array for lost stock
int lost_small[30];

int lost_medium[20];

int lost_large[25];

// Initialize input option for Menu
int Input;

// Initialize inpuit for selecting shoe for rent, return and lost
int Shoe_Num;

// Set FILE to stock
FILE *stock;

// Setup Functions
int FileCheck(), FileMake(), FileLoad(), Menu(), Rent(), Return(), ShowStock(), Rented(), LostMenu(), Lose_Shoe(), Found(), SaveFile(), RentSmall(), RentMedium(), RentLarge(), ReturnSmall(), ReturnMedium(), ReturnLarge(), LostSmall(), LostMedium(), LostLarge(), FoundSmall(), FoundMedium(), FoundLarge();

// Starts Function to check if data file exists
int FileCheck() {
    stock = fopen("stock.csv", "r");
    
    // Checks if the file exists, if not runs function to create a data file.
    if (stock == NULL) {
        printf("\t STOCK DATA DOES NOT EXIST, GENERATING NEW DATA");
        FileMake();
    }
    else {

        // If the data file exists, initaites function to load the data from the file.
        FileLoad();

    }
    return 0;
}

int FileMake() {
    
    //Sets FILE to open stock.csv in write mode
    stock = fopen("stock.csv", "w");

    //Set arrays to their respective stock and the data linked with them
    int small[30] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020, 1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028, 1029, 1030};
    int medium[20] = {2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020};
    int large[25] = {3001, 3002, 3003, 3004, 3005, 3006, 3007, 3008, 3009, 3010, 3011, 3012, 3013, 3014, 3015, 3016, 3017, 3018, 3019, 3020, 3021, 3022, 3023, 3024, 3025};
    
    // Writes all the arrays to the CSV file
    fwrite(small, sizeof(int), 30, stock);
    fwrite(medium, sizeof(int), 20, stock);
    fwrite(large, sizeof(int), 25, stock);
    fwrite(small_rented, sizeof(int), 30, stock);
    fwrite(medium_rented, sizeof(int), 20, stock);
    fwrite(large_rented, sizeof(int), 25, stock);
    fwrite(lost_small, sizeof(int), 30, stock);
    fwrite(lost_medium, sizeof(int), 20, stock);
    fwrite(lost_large, sizeof(int), 25, stock);
    printf("DATA FILE FOR STOCK HAS BEEN CREATED");
    
    // Closes the file
    fclose(stock);

    FileLoad();

    // Returns back to File Check Function
    return 1;
}

// Seting up function to load the stock data from the CSV file
int FileLoad(){

    // Opens stock.csv in read mode
    stock = fopen("stock.csv", "r");

    // if the file does not open it will generate a new data file
    if (stock == NULL) {
        printf("ERROR OPENING FILE");
        FileMake();
    }

    // Reads the data from the csv file
    fread(small, sizeof(int), 30, stock);
    fread(medium, sizeof(int), 20, stock);
    fread(large, sizeof(int), 25, stock);
    fread(small_rented, sizeof(int), 30, stock);
    fread(medium_rented, sizeof(int), 20, stock);
    fread(large_rented, sizeof(int), 25, stock);
    fread(lost_small, sizeof(int), 30, stock);
    fread(lost_medium, sizeof(int), 20, stock);
    fread(lost_large, sizeof(int), 25, stock);

    // Closes the stock file after the data has been read
    fclose(stock);
    return 0;

    }

// Set up for the Menu Function.
int Menu() {

    // Prints out all the options in the Menu
    printf("\nBOWL BABY NOWL - MENU");
    printf("\n_____________________");
    printf("\n1) RENT");
    printf("\n2) RETURN");
    printf("\n3) DISPLAY ALL STOCK");
    printf("\n4) CHECK RENTED");
    printf("\n5) LOST");
    printf("\n0) EXIT");

    // User inout to decide which option they want to select
    printf("\nENTER A MENU OPTION: ");
    scanf("%d", &Input);
    
    // Takes user input and directs the user to the corresponding funtion they have inputed
    switch (Input){
        case 1:
            Rent();
            break;
        case 2:
            Return();
            break;
        case 3:
            ShowStock();
            break;
        case 4:
            Rented();
            break;
        case 5:
            LostMenu();
            break;
        case 0:
            exit(0);
        default:
            printf("INVALID OPTION");
            break;
    }
    Menu();
    return 0;

}

// Setup Function to save changes made to the data in the CSV file
int SaveFile(){
    stock = fopen("stock.csv", "w");

    fwrite(small, sizeof(int), 30, stock);
    fwrite(medium, sizeof(int), 20, stock);
    fwrite(large, sizeof(int), 25, stock);
    fwrite(small_rented, sizeof(int), 30, stock);
    fwrite(medium_rented, sizeof(int), 20, stock);
    fwrite(large_rented, sizeof(int), 25, stock);
    fwrite(lost_small, sizeof(int), 30, stock);
    fwrite(lost_medium, sizeof(int), 20, stock);
    fwrite(lost_large, sizeof(int), 25, stock);

    fclose (stock);
    return 0;
}

// Function containing logic for renting out a small shoe
int RentSmall(){
    // For loop to print all the available shoes for rent
    for (int i = 0; i < 30; ++i)
        printf("[%d] \n", small[i]);
    
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\nSELECT WHICH SHOE YOU WOULD LIKE TO RENT: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 1001 || Shoe_Num > 1030 ){
        printf("INVALID NUMBER\n");
        RentSmall();
        return 0;
    }

    // Checks whether the shoes is already rented out
    for (int x = 0; x < 30; ++x){
        if (Shoe_Num == small_rented[x]){
            printf("\nSHOE IS ALREADY RENTED, SELECT DIFFERENT SHOE\n");
            RentSmall();
            return 0;
        }
    }

    // Adds the valid user input to the small rented array
    for (int x = 0; x < 30; ++x){
        if (small[x] == Shoe_Num){
            small_rented[x] = Shoe_Num;
            small[x] = 0;
            printf("SHOE HAS BEEN RENTED\n");
            SaveFile();
            break;
        }
    }

    return 0;
}

// Function containing logic for renting out a small shoe
int RentMedium(){
    // For loop to print all the available shoes for rent
    for (int i = 0; i < 20; ++i)
        printf("[%d] \n", medium[i]);
    
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\nSELECT WHICH SHOE YOU WOULD LIKE TO RENT: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 2001 || Shoe_Num > 2020 ){
        printf("INVALID NUMBER\n");
        RentMedium();
        return 0;
    }

    // Checks whether the shoes is already rented out
    for (int x = 0; x < 20; ++x){
        if (Shoe_Num == medium_rented[x]){
            printf("\nSHOE IS ALREADY RENTED, SELECT DIFFERENT SHOE\n");
            RentMedium();
            return 0;
        }
    }

    // Adds the valid user input to the small rented array
    for (int x = 0; x < 30; ++x){
        if (medium[x] == Shoe_Num){
            medium_rented[x] = Shoe_Num;
            medium[x] = 0;
            printf("SHOE HAS BEEN RENTED\n");
            SaveFile();
            break;
        }
    }

    return 0;
}

// Function containing logic for renting out a small shoe
int RentLarge(){
    // For loop to print all the available shoes for rent
    for (int i = 0; i < 25; ++i)
        printf("[%d] \n", large[i]);
    
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\nSELECT WHICH SHOE YOU WOULD LIKE TO RENT: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 3001 || Shoe_Num > 3025 ){
        printf("INVALID NUMBER\n");
        RentLarge();
        return 0;
    }

    // Checks whether the shoes is already rented out
    for (int x = 0; x < 25; ++x){
        if (Shoe_Num == large_rented[x]){
            printf("\nSHOE IS ALREADY RENTED, SELECT DIFFERENT SHOE\n");
            RentLarge();
            return 0;
        }
    }

    // Adds the valid user input to the small rented array
    for (int x = 0; x < 30; ++x){
        if (large[x] == Shoe_Num){
            large_rented[x] = Shoe_Num;
            large[x] = 0;
            printf("SHOE HAS BEEN RENTED\n");
            SaveFile();
            break;
        }
    }

    return 0;
}

// Menu for renting out shoes
int Rent(){
    printf("\n1) SMALL SHOES");
    printf("\n2) MEDIUM SHOES");
    printf("\n3) LARGE SHOES");
    printf("\n0) RETURN TO MENU");

    // User input for what shoe size they want to rent
    printf("\nSELECT WHICH SIZE YOU WOULD LIKE TO RENT: ");
    scanf("%d", &Input);

    // Sends user to corresponding option they have selected
    switch(Input){
        case 1:
            RentSmall();
            break;
        case 2:
            RentMedium();
            break;
        case 3:
            RentLarge();
            break;
        case 0:
            Menu();
            break;
        default:
            printf("INBALID OPTION");
            break;
    }
    return 0;
}

int Return(){
    printf("\nRETURN MENU:");
    printf("\n____________");
    printf("\n1) SMALL");
    printf("\n2) MEDIUM");
    printf("\n3) LARGE");
    printf("\n0) MAIN MENU");
    printf("\n\nSELECT WHICH SIZE SHOE YOU WOULD LIKE TO RETURN: ");
    scanf("%d", &Input);
    switch (Input) {
        case 1:
            ReturnSmall();
            break;
        case 2:
            ReturnMedium();
            break;
        case 3:
            ReturnLarge();
            break;
        case 0:
            Menu();
            break;
        default:
            printf("INVALID OPTION");
            break;
    }
    return 0;
}

// Function containing logic for renting out a small shoe
int ReturnSmall(){
    // For loop to print all the available shoes for rent
    for (int i = 0; i < 30; ++i)
        printf("[%d] \n", small_rented[i]);
    
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\nSELECT WHICH SHOE YOU WOULD LIKE TO RETURN: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 1001 || Shoe_Num > 1030 ){
        printf("INVALID NUMBER\n");
        ReturnSmall();
        return 0;
    }

    // Checks whether the shoes is already rented out
    for (int x = 0; x < 30; ++x){
        if (Shoe_Num == small[x]){
            printf("\nSHOE IS NOT RENTED, CANNOT BE RETURNED\n");
            ReturnSmall();
            return 0;
        }
    }

    // Adds the valid user input to the small rented array
    for (int x = 0; x < 30; ++x){
        if (small_rented[x] == Shoe_Num){
            small[x] = Shoe_Num;
            small_rented[x] = 0;
            printf("SHOE HAS BEEN RENTED\n");
            SaveFile();
            break;
        }
    }

    return 0;
}

// Function containing logic for renting out a small shoe
int ReturnMedium(){
    // For loop to print all the available shoes for rent
    for (int i = 0; i < 30; ++i)
        printf("[%d] \n", medium_rented[i]);
    
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\nSELECT WHICH SHOE YOU WOULD LIKE TO RETURN: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 2001 || Shoe_Num > 2020 ){
        printf("INVALID NUMBER\n");
        ReturnMedium();
        return 0;
    }

    // Checks whether the shoes is already rented out
    for (int x = 0; x < 20; ++x){
        if (Shoe_Num == medium[x]){
            printf("\nSHOE IS NOT RENTED, CANNOT BE RETURNED\n");
            ReturnMedium();
            return 0;
        }
    }

    // Adds the valid user input to the small rented array
    for (int x = 0; x < 30; ++x){
        if (medium_rented[x] == Shoe_Num){
            medium[x] = Shoe_Num;
            medium_rented[x] = 0;
            printf("SHOE HAS BEEN RENTED\n");
            SaveFile();
            break;
        }
    }

    return 0;
}

// Function containing logic for renting out a small shoe
int ReturnLarge(){
    // For loop to print all the available shoes for rent
    for (int i = 0; i < 25; ++i)
        printf("[%d] \n", large_rented[i]);
    
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\nSELECT WHICH SHOE YOU WOULD LIKE TO RETURN: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 3001 || Shoe_Num > 3025 ){
        printf("INVALID NUMBER\n");
        ReturnLarge();
        return 0;
    }

    // Checks whether the shoes is already rented out
    for (int x = 0; x < 25; ++x){
        if (Shoe_Num == large[x]){
            printf("\nSHOE IS NOT RENTED, CANNOT BE RETURNED\n");
            ReturnLarge();
            return 0;
        }
    }

    // Adds the valid user input to the small rented array
    for (int x = 0; x < 25; ++x){
        if (large_rented[x] == Shoe_Num){
            large[x] = Shoe_Num;
            large_rented[x] = 0;
            printf("SHOE HAS BEEN RENTED\n");
            SaveFile();
            break;
        }
    }

    return 0;
}

int Rented() {
    printf("\n1) SMALL");
    printf("\n2) MEDIUM");
    printf("\n3) LARGE");
    printf("\n4) ALL");
    printf("\n0) RETURN TO MENU");
    printf("\nSELECT OPTION: ");
    scanf("%d", &Input);
    switch (Input){
        case 1:
            printf("\nRENTED - SMALL:");
            for (int i = 0; i < 30; ++i){
                printf("[%d] \n", small_rented[i]);
            }
            break;
        case 2:
            printf("\nRENTED - MEDIUM:");
            for (int i = 0; i < 20; ++i){
                printf("[%d] \n", medium_rented[i]);
            }
            break;
        case 3:
            printf("\nRENTED - LARGE:");
            for (int i = 0; i < 25; ++i){
                printf("[%d] \n", large_rented[i]);
            }
            break;
        case 4:
            printf("\nRENTED - ALL:");
            printf("SMALL:\n");
            for (int x = 0; x < 30; ++x){
                printf("[%d] \n", small_rented[x]);
            }
            printf("MEDIUN\n");
            for (int y = 0; y < 20; ++y){
                printf("[%d] \n", medium_rented[y]);
            }
            printf("LARGE\n");
            for (int z = 0; z <25; ++z){
                printf("[%d] \n", large_rented[z]);
            }
            break;
        }
    return 0;
}
int ShowStock() {
    printf("SMALL:\n");
    for (int x = 0; x < 30; ++x){
        printf("[%d] \n", small[x]);
    }
    printf("MEDIUM:\n");
    for (int y = 0; y < 20; ++y){
        printf("[%d] \n", medium[y]);
    }
    printf("LARGE:\n");
    for (int z = 0; z < 25; ++z){
        printf("[%d] \n", large[z]);
    }

    printf("\nENTER 0 TO RETURN TO MENU: ");
    scanf("%d", &Input);
    if (Input == 0){
        Menu();
    }
    else {
        printf("\nINVALID OPTION");
    }
    return 0;
}

int LostMenu(){
    printf("\nLOST MENU: ");
    printf("\n1) SHOW LOST");
    printf("\n2) ADD TO LOST");
    printf("\n3) FOUND");
    printf("\n0) RETURN TO MENU");
    printf("\nINPUT MENU OPTION: ");
    scanf("%d", &Input);
    switch (Input){
        case 1:
            printf("\nLOST SHOES\n");
            printf("SMALL:\n");
            for (int x = 0; x < 30; ++x){
                printf("[%d] \n", lost_small[x]);
            }
            printf("MEDIUM:\n");
            for (int y = 0; y < 20; ++y){
                printf("[%d] \n", lost_medium[y]);
            }
            printf("LARGE:\n");
            for (int z = 0; z < 25; ++z){
                printf("[%d] \n", lost_large[z]);
            }
            break;
        case 2:
            Lose_Shoe();
            break;
        case 3:
            Found();
            break;
        case 0:
            Menu();
            break;
    }
    return 0;
}

int Lose_Shoe(){
    printf("\n1) SMALL");
    printf("\n2) MEDIUM");
    printf("\n3) LARGE");
    printf("\n0) RETURN TO MENU");
    printf("\nSELECT SHOE SIZE: ");
    scanf("%d", &Input);
    switch (Input) {
        case 1:
            LostSmall();
            break;
        case 2:
            LostMedium();
            break;
        case 3:
            LostLarge();
            break;
        case 4:
            Menu();
            break;
    }
    return 0;
}

// Function containing logic for renting out a small shoe
int LostSmall(){
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\n INPUT LOST SHOE: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 1001 || Shoe_Num > 1030 ){
        printf("INVALID NUMBER\n");
        Lose_Shoe();
        return 0;
    }

    // Checks whether the shoes is already rented out
    for (int x = 0; x < 30; ++x){
        if (Shoe_Num == small_rented[x]){
            printf("\nSHOE IS CURRENTLY  RENTED\n");
            Lose_Shoe();
            return 0;
        }
    }

    // Adds the valid user input to the small rented array
    for (int x = 0; x < 30; ++x){
        if (small[x] == Shoe_Num){
            lost_small[x] = Shoe_Num;
            small[x] = 0;
            printf("SHOE HAS BEEN MARKED LOST\n");
            SaveFile();
            break;
        }
    }

    return 0;
}

// Function containing logic for renting out a small shoe
int LostMedium(){
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\n INPUT LOST SHOE: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 2001 || Shoe_Num > 2020 ){
        printf("INVALID NUMBER\n");
        Lose_Shoe();
        return 0;
    }

    // Checks whether the shoes is already rented out
    for (int x = 0; x < 20; ++x){
        if (Shoe_Num == medium_rented[x]){
            printf("\nSHOE IS CURRENTLY  RENTED\n");
            Lose_Shoe();
            return 0;
        }
    }

    // Adds the valid user input to the small rented array
    for (int x = 0; x < 20; ++x){
        if (medium[x] == Shoe_Num){
            lost_medium[x] = Shoe_Num;
            medium[x] = 0;
            printf("SHOE HAS BEEN MARKED LOST\n");
            SaveFile();
            break;
        }
    }

    return 0;
}

// Function containing logic for renting out a small shoe
int LostLarge(){
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\n INPUT LOST SHOE: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 3001 || Shoe_Num > 3025 ){
        printf("INVALID NUMBER\n");
        Lose_Shoe();
        return 0;
    }

    // Checks whether the shoes is already rented out
    for (int x = 0; x < 25; ++x){
        if (Shoe_Num == large_rented[x]){
            printf("\nSHOE IS CURRENTLY  RENTED\n");
            Lose_Shoe();
            return 0;
        }
    }

    // Adds the valid user input to the small rented array
    for (int x = 0; x < 25; ++x){
        if (large[x] == Shoe_Num){
            lost_large[x] = Shoe_Num;
            large[x] = 0;
            printf("SHOE HAS BEEN MARKED LOST\n");
            SaveFile();
            break;
        }
    }

    return 0;
}

int Found(){
    printf("\n1) SMALL");
    printf("\n2) MEDIUM");
    printf("\n3) LARGE");
    printf("\n0) RETURN TO MENU");
    printf("\nSELECT OPTION");
    scanf("%d", &Input);
    switch (Input){
        case 1:
            FoundSmall();
            break;
        case 2:
            FoundMedium();
            break;
        case 3:
            FoundLarge();
            break;
        case 4:
            Menu();
            break;
    }
    return 0;
}

// Function containing logic for renting out a small shoe
int FoundSmall(){
    // For loop to print all the available shoes for rent
    for (int i = 0; i < 30; ++i)
        printf("[%d] \n", lost_small[i]);
    
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\nINPUT FOUND SHOE NUMBER: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 1001 || Shoe_Num > 1030 ){
        printf("INVALID NUMBER\n");
        FoundSmall();
        return 0;
    }

    // Checks whether the shoes is already rented out
    for (int x = 0; x < 30; ++x){
        if (Shoe_Num == small[x]){
            printf("\nSHOE IS NOT LOST, CANNOT BE FOUND\n");
            FoundSmall();
            return 0;
        }
    }

    // Adds the valid user input to the small rented array
    for (int x = 0; x < 30; ++x){
        if (lost_small[x] == Shoe_Num){
            small[x] = Shoe_Num;
            lost_small[x] = 0;
            printf("SHOE HAS BEEN FOUND\n");
            SaveFile();
            break;
        }
    }

    return 0;
}

// Function containing logic for renting out a small shoe
int FoundMedium(){
    // For loop to print all the available shoes for rent
    for (int i = 0; i < 20; ++i)
        printf("[%d] \n", lost_medium[i]);
    
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\nINPUT FOUND SHOE NUMBER: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 2001 || Shoe_Num > 2020 ){
        printf("INVALID NUMBER\n");
        FoundMedium();
        return 0;
    }

    // Checks whether the shoes is already rented out
    for (int x = 0; x < 20; ++x){
        if (Shoe_Num == medium[x]){
            printf("\nSHOE IS NOT LOST, CANNOT BE FOUND\n");
            FoundMedium();
            return 0;
        }
    }

    // Adds the valid user input to the small rented array
    for (int x = 0; x < 20; ++x){
        if (lost_medium[x] == Shoe_Num){
            medium[x] = Shoe_Num;
            lost_medium[x] = 0;
            printf("SHOE HAS BEEN FOUND\n");
            SaveFile();
            break;
        }
    }

    return 0;
}

// Function containing logic for renting out a small shoe
int FoundLarge(){
    // For loop to print all the available shoes for rent
    for (int i = 0; i < 25; ++i)
        printf("[%d] \n", lost_large[i]);
    
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\nINPUT FOUND SHOE NUMBER: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 3001 || Shoe_Num > 3025 ){
        printf("INVALID NUMBER\n");
        FoundLarge();
        return 0;
    }

    // Checks whether the shoes is already rented out
    for (int x = 0; x < 25; ++x){
        if (Shoe_Num == large[x]){
            printf("\nSHOE IS NOT LOST, CANNOT BE FOUND\n");
            FoundLarge();
            return 0;
        }
    }

    // Adds the valid user input to the small rented array
    for (int x = 0; x < 25; ++x){
        if (lost_large[x] == Shoe_Num){
            large[x] = Shoe_Num;
            lost_large[x] = 0;
            printf("SHOE HAS BEEN FOUND\n");
            SaveFile();
            break;
        }
    }

    return 0;
}


int main(){
    FileCheck();
    Menu();
    return 0;
}