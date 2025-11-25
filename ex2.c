/******************
Name: Adi Katabi
ID: 322906728
Assignment: ex2
*******************/

#include <stdio.h>

int main()
{
    int choice;
    const int TEN = 10;
    do {    
        printf("Welcome to our games, please choose an option:\n"
            "1. Ducky's Unity Game\n"
            "2. The Memory Game\n"
            "3. Professor Pat's Power Calculation\n"
            "4. The Duck Parade\n"
            "5. The Mystery of the Repeated Digits\n"
            "6. Good Night Ducks\n");
        // MAIN MENU LOOP
        scanf(" %d", &choice);
        /*while ((choice < 1 || choice > 6)) {
            printf("Invalid number. please try again\n");
            scanf(" %d", &choice);
        }   */
        switch(choice){
            case 1:
            {
                // TASK 1: Ducky's Unity Game code here
                int dec_num, counter_one = 0, div = 1, rest;
                printf("please enter a positive number:\n");
                scanf("%d", &dec_num);
                while((dec_num < 0) || (dec_num > 255)){
                    printf("Invalid number, please try again\n");
                    scanf("%d", &dec_num);
                }
                while(div != 0){
                    div = dec_num / 2;
                    rest = dec_num % 2;
                    dec_num = div;
                    if(rest == 1){
                        counter_one = counter_one + 1;
                    }
                }
                printf("Ducky earns %d corns\n", counter_one);
                break;
            }
            case 2:
                // TASK 2: The Memory Game code here
                int num_of_ducks, quak_or_sh, do_in_j;
                long do_ducks = 0, right_order_ducks = 0;
                printf("please enter the number of ducks:\n");
                scanf("%d", &num_of_ducks);
                while((num_of_ducks <= 0) || (num_of_ducks > 64)){
                    printf("Invalid number, please try again\n");
                    scanf("%d", &num_of_ducks);
                }
                printf("you entered %d ducks\n", num_of_ducks);
                for(int i= 0; i<num_of_ducks; i++){
                    printf("duck %d do QUAK? 1 for yes, 0 for no\n", i+1);
                    scanf("%d", &quak_or_sh);
                    while((quak_or_sh != 0) && (quak_or_sh != 1)){
                        printf("Invalid input, please try again\n");
                        scanf("%d", &quak_or_sh);
                    }
                    do_ducks = do_ducks | quak_or_sh; //making a binary numberto save the quak or shush of each duck.
                    do_ducks = do_ducks << 1;
                }
                for(int j=0; j<num_of_ducks; j++){
                    right_order_ducks = do_ducks; //initalizing right_order_ducks to do_ducks after each iteration.
                    right_order_ducks = right_order_ducks >> num_of_ducks; //the order of do_ducks is reversed, so I use this to get the right order by shifting to the first relevent bit.
                    do_in_j = right_order_ducks & 1;
                    if(do_in_j == 1){
                        printf("duck number %d do Quak\n", j+1);
                    }
                    else{
                        printf("duck number %d do Sh...\n", j+1);
                    }
                    do_ducks = do_ducks << 1; //shifting do_ducks to get the next duck.
                    
                }
                break;
            case 3:
                // TASK 3: Professor Pat's Power Calculation code here 
                int num, exponent;
                long result = 1;
                printf("please enter the number\n");
                scanf("%d", &num);
                while(num < 0){ 
                    printf("Invalid number, please try again\n");
                    scanf("%d", &num);
                }
                printf("please enter the exponent\n");
                scanf("%d", &exponent);
                while(exponent < 0 ){
                    printf("Invalid number, please try again\n");
                    scanf("%d", &exponent);
                }
                for(int i=0; i<exponent; i++){
                    result = result * num; //doing multiplication directly.
                }
                printf("your power is: %ld\n", result);
                break;

            case 4:
                // TASK 4: The Duck Parade
                int number_of_ducks, i =0, j = 0, l = 0, d = 0, counter_ducks = 0;
                printf("please enter number of ducks:\n");
                scanf("%d", &number_of_ducks);
                while(number_of_ducks < 0){
                    printf("Invalid number, please try again\n");
                    scanf("%d", &number_of_ducks);
                }
                for(i= 0; i<=number_of_ducks/TEN; i++){
                    if(number_of_ducks - counter_ducks <TEN){
                        for(l= 0; l<number_of_ducks - counter_ducks; l++){ 
                            printf("   _\t\t");
                        }
                        printf("\n");
                        for(j= 0; j<number_of_ducks - counter_ducks; j++){
                            printf("__(o)>\t\t");
                        }
                        printf("\n");
                            for(d= 0; d<number_of_ducks - counter_ducks; d++){
                            printf("\\___)\t\t");
                        }
                        if(number_of_ducks == TEN){
                            break;
                        }
                    }
                    
                    else {
                        for(l= 0; l<TEN; l++){ 
                            printf("   _\t\t");
                            }
                        printf("\n");
                        for(j= 0; j<TEN; j++){
                            printf("__(o)>\t\t");}
                        printf("\n");
                        for(d= 0; d<TEN; d++){
                            printf("\\___)\t\t");
                            }
                         printf("\n");
                    counter_ducks = counter_ducks +TEN;
                    }

                }
                printf("\n\n");
                break;

            case 5:
            // TASK 5: The Mystery of the Repeated Digits code here
                int numdig, new_num, digit;
                printf("please enter number\n");
                scanf("%d", &numdig);
                while (numdig <= 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &numdig);
                    }
                
                while(numdig>0){
                    digit = numdig %TEN;
                    new_num = numdig/TEN;
                    while(new_num>0){
                        if(digit == new_num%TEN){
                            printf("%d appears more than once!\n", digit);
                            break;
                        }
                        else new_num = new_num/TEN;
   
                    }
                    numdig=numdig/TEN;
                }
                printf("\n");
                break;

                case 6:
                printf("Good night! See you at the pond tomorrow.\n");
                break;

                default:
                printf("Invalid option, please try again\n");
                break;
                
        }
    }
    while(choice !=6);
    // TASK 6: EXIT


}
    


