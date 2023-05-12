#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

// Initialize counters for statistcs
int Small_Counter = 0;

int Medium_Counter = 0;

int Large_Counter = 0;

int SL_Counter = 0;

int ML_Counter = 0;

int LL_Counter = 0;

// Set FILE to stock
FILE *stock;

// Setup Functions
int FileCheck(), FileMake(), FileLoad(), Menu(), Rent(), Return(), ShowStock(), LostMenu(), Lose_Shoe(), Found(), SaveFile(), RentSmall(), RentMedium(), RentLarge(), ReturnSmall(), ReturnMedium(), ReturnLarge(), LostSmall(), LostMedium(), LostLarge(), FoundSmall(), FoundMedium(), FoundLarge(), stats(), Deposit();

// Starts Function to check if data file exists
int FileCheck() {
    stock = fopen("stock.csv", "r");
    
    // Checks if the file exists, if not runs function to create a data file.
    if (stock == NULL) {
        printf("\t\tSTOCK DATA DOES NOT EXIST, GENERATING NEW DATA");
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
    fprintf(stock, "%d\n", Small_Counter);
    fprintf(stock, "%d\n", Medium_Counter);
    fprintf(stock, "%d\n", Large_Counter);
    fprintf(stock, "%d", SL_Counter);
    fprintf(stock, "%d", ML_Counter);
    fprintf(stock, "%d", LL_Counter);
    printf("\t\tDATA FILE FOR STOCK HAS BEEN CREATED");
    
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
        printf("\t\tERROR OPENING FILE");
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
    fscanf(stock, "%d", &Small_Counter);
    fscanf(stock, "%d", &Medium_Counter);
    fscanf(stock, "%d", &Large_Counter);
    fscanf(stock, "%d", &SL_Counter);
    fscanf(stock, "%d", &ML_Counter);
    fscanf(stock, "%d", &LL_Counter);

    // Closes the stock file after the data has been read
    fclose(stock);
    return 0;

    }

int Deposit(){
    system("cls");
    printf("DO YOU HAVE £5: YES (1) / NO (2)\n");
    scanf("%d", &Input);
    if (Input == 1){
        Rent();
    }
    else{
        printf("YOU CANNOT RENT SHOE");
        sleep(5);
        Menu(0);
    }
return 0;
}



// Set up for the Menu Function.
int Menu() {
    system("cls");
    // Prints out all the options in the Menu
    printf("\nBOWL BABY NOWL - MENU");
    printf("\n_____________________");
    printf("\n1) RENT");
    printf("\n2) RETURN");
    printf("\n3) DISPLAY ALL STOCK");
    printf("\n4) CHECK RENTED");
    printf("\n5) LOST");
    printf("\n6) STATS");
    printf("\n0) EXIT");

    // User inout to decide which option they want to select
    printf("\nENTER A MENU OPTION: ");
    scanf("%d", &Input);
    
    // Takes user input and directs the user to the corresponding funtion they have inputed
    if (Input == 1 ){
            Deposit();
    }
    else if (Input == 2){
            Return();
    }
    else if (Input == 3){
            ShowStock();
    }
    else if (Input == 4){
        // Prints all the rented out shoes
        system("cls");
        printf("\nRENTED:\n");
        printf("______________\n");
        printf("\nSMALL:\n");
        for (int x = 0; x < 30; ++x){
            printf("[%d]\t", small_rented[x]);
        }
        printf("\n\nMEDIUM:\n");
        for (int y = 0; y < 20; ++y){
            printf("[%d]\t", medium_rented[y]);
        }
        printf("\n\nLARGE:\n");
        for (int z = 0; z <25; ++z){
            printf("[%d]\t", large_rented[z]);
        }
        printf("\n\nENTER 0 TO RETURN TO MENU: ");
        scanf("%d", &Input);
        if (Shoe_Num == 0){
            system("cls");
            Menu();
        }
    }
    else if (Input == 5){
        LostMenu();
    }
    else if (Input == 6){
        stats();
    }
    else if (Input == 0){
        exit(0);
    }
    else{
        printf("INVALID OPTION");
        Menu();
    }
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
    fprintf(stock, "%d\n", Small_Counter);
    fprintf(stock, "%d\n", Medium_Counter);
    fprintf(stock, "%d\n", Large_Counter);
    fprintf(stock, "%d\n", SL_Counter);
    fprintf(stock, "%d\n", ML_Counter);
    fprintf(stock, "%d\n", LL_Counter);

    fclose (stock);
    return 0;
}

// Function containing logic for renting out a small shoe
int RentSmall(){

    // Clears the screen when the function begins
    system("cls");
    printf("SMALL:\n");

    // For loop to print all the available shoes for rent
    for (int i = 0; i < 30; ++i)
        printf("[%d]\t", small[i]);
    
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\nSELECT WHICH SHOE YOU WOULD LIKE TO RENT OR 0 TO RETURN TO MENU: ");
    scanf("%d", &Shoe_Num);

    // If the input is 0 returns user back to main menu
    if (Shoe_Num == 0){
        Menu();
    }

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
            // Increases Counter for Small
            Small_Counter = Small_Counter + 1;
            SaveFile();
            break;
        }
    }
    // User input to allow for another rental or return to main menu
    printf("ENTER 0 TO RETURN TO MENU\nENTER 1 TO RENT ANOTHER SHOE: ");
    scanf("%d", &Input);
    if (Input == 0){
        Menu();
    }
    else if (Input == 1) {
        Rent();
    }
    return 0;
}

// Function containing logic for renting out a medium shoe
int RentMedium(){

    // Clears the screen when the function begins
    system("cls");
    printf("MEDIUM:\n");

    // For loop to print all the available shoes for rent
    for (int i = 0; i < 20; ++i)
        printf("[%d]\t", medium[i]);
    
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\nSELECT WHICH SHOE YOU WOULD LIKE TO RENT OR ENTER 0 TO RETURN TO MENU: ");
    scanf("%d", &Shoe_Num);
    if (Shoe_Num == 0){
        Menu();
    }    

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

    // Adds the valid user input to the medium rented array
    for (int x = 0; x < 30; ++x){
        if (medium[x] == Shoe_Num){
            medium_rented[x] = Shoe_Num;
            medium[x] = 0;
            printf("SHOE HAS BEEN RENTED\n");
            Medium_Counter = Medium_Counter + 1;
            SaveFile();
            break;
        }
    }
    printf("ENTER 0 TO RETURN TO MENU\nENTER 1 TO RENT ANOTHER SHOE: ");
    scanf("%d", &Input);
    if (Input == 0){
        Menu();
    }
    else if (Input == 1){
        Rent();
    }
    return 0;
}

// Function containing logic for renting out a large shoe
int RentLarge(){

    // Clears the screen when the function begins
    system("cls");
    printf("LARGE:\n");

    // For loop to print all the available shoes for rent
    for (int i = 0; i < 25; ++i)
        printf("[%d]\t", large[i]);
    
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\nSELECT WHICH SHOE YOU WOULD LIKE TO RENT OR ENTER 0 TO RETURN TO MENU: ");
    scanf("%d", &Shoe_Num);
    if (Shoe_Num == 0){
        Menu();
    }

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

    // Adds the valid user input to the large rented array
    for (int x = 0; x < 30; ++x){
        if (large[x] == Shoe_Num){
            large_rented[x] = Shoe_Num;
            large[x] = 0;
            printf("SHOE HAS BEEN RENTED\n");
            Large_Counter = Large_Counter + 1;
            SaveFile();
            break;
        }
    }
    printf("ENTER 0 TO RETURN TO MENU\nENTER 1 TO RENT ANOTHER SHOE: ");
    scanf("%d", &Input);
    if (Input == 0){
        Menu();
    }
    else if (Input == 1) {
        Rent();
    }
    return 0;

}

// Menu for renting out shoes
int Rent(){
    system("cls");
    printf("\nRENT A SHOE:");
    printf("\n___________");
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
            Rent();
            break;
    }
    return 0;
}

// Function to run the menu for returning shoes
int Return(){
    system("cls");
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
            Return();
            break;
    }
    return 0;
}

// Function containing logic for returning out a small shoe
int ReturnSmall(){
    system("cls");
    printf("SMALL:\n");

    // For loop to print all the rented out small shoes
    for (int i = 0; i < 30; ++i)
        printf("[%d]\t", small_rented[i]);
    
    // User input to decide which shoe they want to retyrn
    int Shoe_Num;
    printf("\n\nSELECT WHICH SHOE YOU WOULD LIKE TO RETURN OR ENTER 0 TO RETURN TO MENU: ");
    scanf("%d", &Shoe_Num);

    if (Shoe_Num == 0){
        Menu();
    }

    // Checks that the user input is a valid input
    if (Shoe_Num < 1001 || Shoe_Num > 1030 ){
        printf("INVALID NUMBER\n");
        Return();
        return 0;
    }

    // Checks whether the shoes is not rented
    for (int x = 0; x < 30; ++x){
        if (Shoe_Num == small[x]){
            printf("\nSHOE IS NOT RENTED, CANNOT BE RETURNED\n");
            Return();
            return 0;
        }
    }

    // Removes the rented shoe from the rented array and returns it to the small array
    for (int x = 0; x < 30; ++x){
        if (small_rented[x] == Shoe_Num){
            small[x] = Shoe_Num;
            small_rented[x] = 0;
            printf("SHOE HAS BEEN RETURNED\n");
            SaveFile();
            break;
        }
    }
    printf("YOUR DEPOSIT HAS BEEN RETURNED\n");
    printf("ENTER 0 TO RETURN TO MENU\nENTER 1 TO RETURN ANOTHER SHOE: ");
    scanf("%d", &Input);
    if (Input == 0){
        Menu();
    }
    else if (Input == 1){
        Return();
    }
    return 0;
}

// Function containing logic for returning out a medium shoe
int ReturnMedium(){
    system("cls");
    printf("MEDIUM:\n");
    // For loop to print all the rented out medium shoes
    for (int i = 0; i < 30; ++i)
        printf("[%d]\t", medium_rented[i]);
    
    // User input to decide which shoe they want to return
    int Shoe_Num;
    printf("\n\nSELECT WHICH SHOE YOU WOULD LIKE TO RETURN OR ENTER 0 TO RETURN TO MENU: ");
    scanf("%d", &Shoe_Num);

    if (Shoe_Num == 0){
        Menu();
    }

    // Checks that the user input is a valid input
    if (Shoe_Num < 2001 || Shoe_Num > 2020 ){
        printf("INVALID NUMBER\n");
        Menu();
        return 0;
    }

    // Checks whether the shoes is not rented
    for (int x = 0; x < 20; ++x){
        if (Shoe_Num == medium[x]){
            printf("\nSHOE IS NOT RENTED, CANNOT BE RETURNED\n");
            Return();
            return 0;
        }
    }

    // Removes the rented shoe from the medium rented array and returns it to the medium array
    for (int x = 0; x < 30; ++x){
        if (medium_rented[x] == Shoe_Num){
            medium[x] = Shoe_Num;
            medium_rented[x] = 0;
            printf("SHOE HAS BEEN RETURNED\n");
            SaveFile();
            break;
        }
    }
    printf("YOUR DEPOSIT HAS BEEN RETURNED\n");
    printf("ENTER 0 TO RETURN TO MENU\nENTER 1 TO RETURN ANOTHER SHOE: ");
    scanf("%d", &Input);
    if (Input == 0){
        Menu();
    }
    else if (Input == 1) {
        Return();
    }
    return 0;
}

// Function containing logic for returning out a large shoe
int ReturnLarge(){
    system("cls");
    printf("LARGE:\n");

    // For loop to print all the rented out shoes
    for (int i = 0; i < 25; ++i)
        printf("[%d]\t", large_rented[i]);
    
    // User input to decide which shoe they want to rent
    int Shoe_Num;
    printf("\n\nSELECT WHICH SHOE YOU WOULD LIKE TO RETURN OR ENTER 0 TO RETURN TO MENU: ");
    scanf("%d", &Shoe_Num);

    if (Shoe_Num == 0){
        Menu();
    }

    // Checks that the user input is a valid input
    if (Shoe_Num < 3001 || Shoe_Num > 3025 ){
        printf("INVALID NUMBER\n");
        Menu();
        return 0;
    }

    // Checks whether the shoes not rented
    for (int x = 0; x < 25; ++x){
        if (Shoe_Num == large[x]){
            printf("\nSHOE IS NOT RENTED, CANNOT BE RETURNED\n");
            Menu();
            return 0;
        }
    }

    // Removes the rented shoe from the large rented array and returns it to the large array
    for (int x = 0; x < 25; ++x){
        if (large_rented[x] == Shoe_Num){
            large[x] = Shoe_Num;
            large_rented[x] = 0;
            printf("SHOE HAS BEEN RENTED\n");
            SaveFile();
            break;
        }
    }
    printf("YOUR DEPOSIT HAS BEEN RETURNED\n");
    printf("ENTER 0 TO RETURN TO MENU\nENTER 1 TO RETURN ANOTHER SHOE: ");
    scanf("%d", &Input);
    if (Input == 0){
        Menu();
    }
    else if (Input == 1){
        Return();
    }
    return 0;
}

// Function to print all the available shoes for renting
int ShowStock() {
    system("cls");
    printf("ALL AVAILABLE STOCK: ");
    printf("\n____________________\n");
    printf("\nSMALL:\n");
    for (int x = 0; x < 30; ++x){
        printf("[%d]\t", small[x]);
    }
    printf("\n\nMEDIUM:\n");
    for (int y = 0; y < 20; ++y){
        printf("[%d]\t", medium[y]);
    }
    printf("\n\nLARGE:\n");
    for (int z = 0; z < 25; ++z){
        printf("[%d]\t", large[z]);
    }

    printf("\nPRESS 0 TO RETURN TO MENU: ");
    scanf("%d", &Input);
    if (Input == 0){
        system("cls");
        Menu();
    }
    else{
        ShowStock();
    }
    return 0;
}

// Function to run menu for lost shoes
int LostMenu(){
    system("cls");
    printf("\nLOST MENU: ");
    printf("\n_____________");
    printf("\n1) SHOW LOST");
    printf("\n2) ADD TO LOST");
    printf("\n3) FOUND");
    printf("\n0) RETURN TO MENU");
    printf("\nINPUT MENU OPTION: ");
    scanf("%d", &Input);
    // If statents to direct to correct function depednding on user input
    if (Input == 1){
        // Prints out all the shoes marked as lost
        system("cls");
        printf("\nLOST SHOES:\n");
        printf("\n________________\n");
        printf("SMALL:\n");
        for (int x = 0; x < 30; ++x){
            printf("[%d]\t", lost_small[x]);
        }
        printf("\nMEDIUM:\n");
        for (int y = 0; y < 20; ++y){
            printf("[%d]\t", lost_medium[y]);
        }
        printf("\nLARGE:\n");
        for (int z = 0; z < 25; ++z){
                printf("[%d]\t", lost_large[z]);
        }
        // User input to return to menu of choice
        printf ("\n\nENTER 0 TO RETURN TO MENU\nENTER 1 FOR LOST MENU: ");
        scanf ("%d", &Input);
        if (Input == 0){
            Menu();
        }
        else if (Input == 1) {
            LostMenu();
        }
    }
    else if (Input == 2){
        Lose_Shoe();
    }
    else if (Input == 3){
        Found();
    }
    else if (Input == 0){
        Menu();
    }
    else{
        LostMenu();
    }
return 0;
}

// Function for marking a shoe as lost (MENU FOR LOSING SHOE)
int Lose_Shoe(){
    system("cls");
    printf("\n1) SMALL");
    printf("\n2) MEDIUM");
    printf("\n3) LARGE");
    printf("\n0) RETURN TO MENU");
    printf("\nSELECT SHOE SIZE: ");
    scanf("%d", &Input);
    if (Input == 1){
        LostSmall();
    }
    else if (Input == 2) {
        LostMedium();
    }
    else if (Input == 3) {
        LostLarge();
    }
    else if (Input == 0) {
        Menu();
    }
    else {
        printf("INVALID OPTION");
        Lose_Shoe();
    }
    return 0;
}

// Function containing logic for marking a small shoe as lost
int LostSmall(){
    system("cls");

    // User input to decide which shoe they want to mark as lost
    int Shoe_Num;
    printf("\n\n INPUT LOST SHOE: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 1001 || Shoe_Num > 1030 ){
        printf("INVALID NUMBER\n");
        Lose_Shoe();
        return 0;
    }

    // Checks whether the shoes is currently rented out
    for (int x = 0; x < 30; ++x){
        if (Shoe_Num == small_rented[x]){
            printf("\nSHOE IS CURRENTLY  RENTED\n");
            Lose_Shoe();
            return 0;
        }
    }

    // Adds the valid user input to the lost small array
    for (int x = 0; x < 30; ++x){
        if (small[x] == Shoe_Num){
            lost_small[x] = Shoe_Num;
            small[x] = 0;
            printf("SHOE HAS BEEN MARKED LOST\n");
            SL_Counter = SL_Counter + 1;
            SaveFile();
            break;
        }
    }
    printf("ENTER 0 TO RETURN TO MENU\nENTER 1 TO MARK ANOTHER SHOE AS LOST: ");
    scanf("%d", &Input);
    if (Input == 0){
        Menu();
    }
    else if (Input == 1){
        Lose_Shoe();
    }
    return 0;
}

// Function containing logic for marking a medium shoe as lost
int LostMedium(){
    system("cls");

    // User input to decide which shoe they want to mark as lost
    int Shoe_Num;
    printf("\n\n INPUT LOST SHOE: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 2001 || Shoe_Num > 2020 ){
        printf("INVALID NUMBER\n");
        Lose_Shoe();
        return 0;
    }

    // Checks whether the shoes is currently rented out
    for (int x = 0; x < 20; ++x){
        if (Shoe_Num == medium_rented[x]){
            printf("\nSHOE IS CURRENTLY  RENTED\n");
            Lose_Shoe();
            return 0;
        }
    }

    // Adds the valid user input to the medium lost array
    for (int x = 0; x < 20; ++x){
        if (medium[x] == Shoe_Num){
            lost_medium[x] = Shoe_Num;
            medium[x] = 0;
            printf("SHOE HAS BEEN MARKED LOST\n");
            ML_Counter = ML_Counter + 1;
            SaveFile();
            break;
        }
    }
    printf("ENTER 0 TO RETURN TO MENU\nENTER 1 TO MARK ANOTHER SHOE AS LOST: ");
    scanf("%d", &Input);
    if (Input == 0){
        Menu();
    }
    else if (Input == 1){
        Lose_Shoe();
    }
    return 0;
}

// Function containing logic for marking a large shoe as lost
int LostLarge(){
    system("cls");

    // User input to decide which shoe they want to mark as lost
    int Shoe_Num;
    printf("\n\n INPUT LOST SHOE: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 3001 || Shoe_Num > 3025 ){
        printf("INVALID NUMBER\n");
        Lose_Shoe();
        return 0;
    }

    // Checks whether the shoes is currently rented out
    for (int x = 0; x < 25; ++x){
        if (Shoe_Num == large_rented[x]){
            printf("\nSHOE IS CURRENTLY  RENTED\n");
            Lose_Shoe();
            return 0;
        }
    }

    // Adds the valid user input to the large lost array
    for (int x = 0; x < 25; ++x){
        if (large[x] == Shoe_Num){
            lost_large[x] = Shoe_Num;
            large[x] = 0;
            printf("SHOE HAS BEEN MARKED LOST\n");
            LL_Counter = LL_Counter + 1;
            SaveFile();
            break;
        }
    }
    printf("ENTER 0 TO RETURN TO MENU\nENTER 1 TO MARK ANOTHER SHOE AS LOST: ");
    scanf("%d", &Input);
    if (Input == 0){
        Menu();
    }
    else if (Input == 1){
        Lose_Shoe();
    }
}

// Function to find shoe that has been lost (MENU FOR FINDING LOST SHOE)
int Found(){
    system("cls");
    printf("FOUND MENU: \n");
    printf("\n_____________");
    printf("\n1) SMALL");
    printf("\n2) MEDIUM");
    printf("\n3) LARGE");
    printf("\n0) RETURN TO MENU");
    printf("\nSELECT OPTION");
    scanf("%d", &Input);
    if (Input == 1){
        FoundSmall();
    }
    else if (Input == 2){
        FoundMedium();
    }
    else if (Input == 3){
        FoundLarge();
    }
    else if (Input == 0){
            Menu();
    }
    else{
        printf("INVALID OPTION TRY AGAIN");
        Found();
    }
    return 0;
}

// Function containing logic for finding a lost small shoe
int FoundSmall(){
    system("cls");

    // For loop to print all the lost small shoes
    for (int i = 0; i < 30; ++i)
        printf("[%d]\t", lost_small[i]);
    
    // User input to decide which shoe have found
    int Shoe_Num;
    printf("\n\nINPUT FOUND SHOE NUMBER: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 1001 || Shoe_Num > 1030 ){
        printf("INVALID NUMBER\n");
        FoundSmall();
        return 0;
    }

    // Checks whether the shoes has already been found or is not lost
    for (int x = 0; x < 30; ++x){
        if (Shoe_Num == small[x]){
            printf("\nSHOE IS NOT LOST, CANNOT BE FOUND\n");
            FoundSmall();
            return 0;
        }
    }

    // Removes the shoe from the lost small array and adds it back to the small array
    for (int x = 0; x < 30; ++x){
        if (lost_small[x] == Shoe_Num){
            small[x] = Shoe_Num;
            lost_small[x] = 0;
            printf("SHOE HAS BEEN FOUND\n");
            SaveFile();
            break;
        }
    }
    printf("ENTER 0 TO RETURN TO MENU\nENTER 1 TO FIND ANOTHER SHOE: ");
    scanf("%d", &Input);
    if (Input == 0){
        Menu();
    }
    else if (Input == 1){
        Lose_Shoe();
    }
}

// Function containing logic for finding a lost medium shoe
int FoundMedium(){
    system("cls");

    // For loop to print all the lost medium shoes
    for (int i = 0; i < 20; ++i)
        printf("[%d]\t", lost_medium[i]);
    
    // User input to decide which shoe they have found
    int Shoe_Num;
    printf("\n\nINPUT FOUND SHOE NUMBER: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 2001 || Shoe_Num > 2020 ){
        printf("INVALID NUMBER\n");
        FoundMedium();
        return 0;
    }

    // Checks whether the shoe has already been found or is not lost
    for (int x = 0; x < 20; ++x){
        if (Shoe_Num == medium[x]){
            printf("\nSHOE IS NOT LOST, CANNOT BE FOUND\n");
            FoundMedium();
            return 0;
        }
    }

    // Removes the shoe from the lost mediun array and adds it back to the medium array
    for (int x = 0; x < 20; ++x){
        if (lost_medium[x] == Shoe_Num){
            medium[x] = Shoe_Num;
            lost_medium[x] = 0;
            printf("SHOE HAS BEEN FOUND\n");
            SaveFile();
            break;
        }
    }
    printf("ENTER 0 TO RETURN TO MENU\nENTER 1 TO FIND ANOTHER SHOE: ");
    scanf("%d", &Input);
    if (Input == 0){
        Menu();
    }
    else if (Input == 1){
        Lose_Shoe();
    }
}

// Function containing logic for fidning a lost large shoe
int FoundLarge(){
    system("cls");

    // For loop to print all the lost large shoes
    for (int i = 0; i < 25; ++i)
        printf("[%d]\t", lost_large[i]);
    
    // User input to decide which shoe they have found
    int Shoe_Num;
    printf("\n\nINPUT FOUND SHOE NUMBER: ");
    scanf("%d", &Shoe_Num);

    // Checks that the user input is a valid input
    if (Shoe_Num < 3001 || Shoe_Num > 3025 ){
        printf("INVALID NUMBER\n");
        FoundLarge();
        return 0;
    }

    // Checks whether the shoes has already been found or is not lost
    for (int x = 0; x < 25; ++x){
        if (Shoe_Num == large[x]){
            printf("\nSHOE IS NOT LOST, CANNOT BE FOUND\n");
            FoundLarge();
            return 0;
        }
    }

    // Removes the shoe from the lost large array and adds it back to the large array
    for (int x = 0; x < 25; ++x){
        if (lost_large[x] == Shoe_Num){
            large[x] = Shoe_Num;
            lost_large[x] = 0;
            printf("SHOE HAS BEEN FOUND\n");
            SaveFile();
            break;
        }
    }
    printf("ENTER 0 TO RETURN TO MENU\nENTER 1 TO FIND ANOTHER SHOE: ");
    scanf("%d", &Input);
    if (Input == 0){
        Menu();
    }
    else if (Input == 1){
        Lose_Shoe();
    }
}

// Function to display Stats
int stats(){
    system("cls");
    printf("STATISTCS");
    printf("\n_________\n\n");

    // Compares the Counters of the 3 sizes and displays the most popular one accordingly
    if (Small_Counter > Medium_Counter && Small_Counter > Large_Counter){
        printf("MOST POPULAR: SMALL (%d)\n", Small_Counter);
    }
    else if (Medium_Counter > Small_Counter && Medium_Counter > Large_Counter){
        printf("MOST POPULAR: MEDIUM (%d)\n", Medium_Counter);
    }
    else if (Large_Counter > Small_Counter && Large_Counter > Medium_Counter){
        printf("MOST POPULAR: LARGE (%d)\n", Large_Counter);
    }
    else if (Small_Counter == Medium_Counter && Small_Counter ==! Large_Counter){
        printf("MOST POPULAR: SMALL (%d), MEDIUM (%d)\n", Small_Counter, Medium_Counter);
    }
    else if (Small_Counter == Large_Counter && Small_Counter ==! Medium_Counter){
        printf("MOST POPULAR: SMALL (%d), LARGE (%d)\n", Small_Counter, Large_Counter);
    }
    else if (Medium_Counter == Large_Counter && Medium_Counter ==! Small_Counter){
        printf("MOST POPULAR: MEDIUM (%d), LARGE (%d)\n", Medium_Counter, Large_Counter);
    }
    else{
        printf("MOST POPULAR: NONE\n");
    }

    // Compares the Counters of the 3 sizes and displays the Most lost shoe size
    if (SL_Counter > ML_Counter && SL_Counter > LL_Counter){
        printf("MOST LOST: SMALL (%d)\n", SL_Counter);
    }
    else if (ML_Counter > SL_Counter && ML_Counter > ML_Counter){
        printf("MOST LOST: MEDIUM (%d)\n", ML_Counter);
    }
    else if (LL_Counter > SL_Counter && LL_Counter > LL_Counter){
        printf("MOST LOST: LARGE (%d)\n", LL_Counter);
    }
    else if (SL_Counter == ML_Counter && SL_Counter ==! LL_Counter){
        printf("MOST LOST: SMALL (%d), MEDIUM (%d)\n", SL_Counter, ML_Counter);
    }
    else if (SL_Counter == LL_Counter && SL_Counter ==! ML_Counter){
        printf("MOST LOST: SMALL (%d), LARGE (%d)\n", SL_Counter, LL_Counter);
    }
    else if (ML_Counter == LL_Counter && ML_Counter ==! SL_Counter){
        printf("MOST LOST: MEDIUM (%d), LARGE (%d)\n", ML_Counter, LL_Counter);
    }
    else {
        printf("MOST LOST: NONE\n");
    }

    // Compares the sizes and displays least popular
    if (Small_Counter < Medium_Counter && Small_Counter < Large_Counter){
        printf("LEAST POPULAR: SMALL (%d)\n", Small_Counter);
    }
    else if (Medium_Counter < Small_Counter && Medium_Counter < Large_Counter){
        printf("LEAST POPULAR: MEDIUM (%d)\n", Medium_Counter);
    }
    else if (Large_Counter < Small_Counter && Large_Counter < Medium_Counter){
        printf("LEAST POPULAR: LARGE (%d)\n", Large_Counter);
    }
    else if (Small_Counter == Medium_Counter && Small_Counter ==! Large_Counter){
        printf("LEAST POPULAR: SMALL (%d), MEDIUM (%d)\n", Small_Counter, Medium_Counter);;
    }
    else if (Small_Counter == Large_Counter && Small_Counter ==! Medium_Counter){
        printf("LEAST POPULAR: SMALL (%d), LARGE (%d)\n", Small_Counter, Large_Counter);
    }
    else if (Medium_Counter == Large_Counter && Medium_Counter ==! Small_Counter){
        printf("LEAST POPULAR: MEDIUM (%d), LARGE (%d)\n", Medium_Counter, Large_Counter);
    }
    else{
        printf("LEAST POPULAR: NONE\n");
    }

    // Compares the sizes and displays least lost
    if (SL_Counter < ML_Counter && SL_Counter < LL_Counter){
        printf("LEAST LOST: SMALL (%d)\n", SL_Counter);
    }
    else if (ML_Counter < SL_Counter && ML_Counter < LL_Counter){
        printf("LEAST LOST: MEDIUM (%d)\n", ML_Counter);
    }
    else if (LL_Counter < SL_Counter && LL_Counter < ML_Counter){
        printf("LEAST LOST: LARGE (%d)\n", LL_Counter);
    }
    else if (SL_Counter == ML_Counter && SL_Counter ==! LL_Counter){
        printf("LEAST LOST: SMALL (%d), MEDIUM (%d)\n", SL_Counter, ML_Counter);
    }
    else if (SL_Counter == LL_Counter && SL_Counter ==! ML_Counter){
        printf("LEAST LOST: SMALL (%d), LARGE (%d)\n", SL_Counter, LL_Counter);
    }
    else if (ML_Counter == LL_Counter && ML_Counter ==! SL_Counter){
        printf("LEAST LOST: MEDIUM (%d), LARGE (%d)\n", ML_Counter, LL_Counter);
    }
    else {
        printf("LEAST LOST: NONE\n");
    }
    printf("ENTER 0 TO RETURN TO MAIN MENU: ");
    scanf("%d", &Input);
    if (Input == 0){
        Menu();
    }
    else{
        stats();
    }
}

// Starts the porgram
int main(){
    FileCheck();
    Menu();
    return 0;
}