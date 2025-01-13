#include <stdio.h>
#include <math.h>

int countdigits(int number){
    int count = 0;
    while (number != 0){
        number = number / 10;
        count++;
    }
    return count;
}
 

void printdigit(int number){
    switch(number){
        case 1:
            printf("one ");
            break;  
        case 2: 
            printf("two ");
            break;  
        case 3: 
            printf("three ");
            break;
        case 4:
            printf("four ");
            break;
        case 5: 
            printf("five ");
            break;
        case 6: 
            printf("six ");
            break;
        case 7:
            printf("seven ");
            break;
        case 8:
            printf("eight ");
            break;  
        case 9:
            printf("nine ");
            break;
        default:
            break;  
    }
}

void printtens(int number){
    switch(number){
        case 1:
            printf("ten ");
            break;
        case 2:
            printf("twenty ");
            break;
        case 3:
            printf("thirty ");
            break;
        case 4:
            printf("fourty ");
            break;
        case 5:
            printf("fifty ");
            break;
        case 6:
            printf("sixty ");
            break;
        case 7:
            printf("seventy ");
            break;
        case 8:
            printf("eighty ");
            break;  
        case 9:
            printf("ninety ");
            break;
        default:    
            break;  
    }
}

void printteens(int number){
    switch(number){
        case 11:
            printf("eleven ");
            break;  
        case 12:    
            printf("twelve ");
            break;
        case 13:    
            printf("thirteen ");
            break;
        case 14:    
            printf("fourteen ");
            break;
        case 15:    
            printf("fifteen ");
            break;
        case 16:
            printf("sixteen ");
            break;
        case 17:
            printf("seventeen ");
            break;
        case 18:
            printf("eighteen ");
            break;
        case 19:
            printf("nineteen ");
            break;
        default:    
            break;
    }
}

void calculate(int number){
        int digits= countdigits(number);
        
        switch(digits){
            case 3:
        if(number % 100 == 0){
            int remainder = number / 100;
            printdigit(remainder);
            printf("hundred ");
        }
        else if(number % 10 == 0){
            int remainder = number / 10;
                printdigit(floor(remainder/10));
                printf("hundred and ");
                printtens(remainder%10);
        }
        else{
            printdigit(floor(number/100));
            printf("hundred and ");
            if (number % 100 < 10){
                printdigit(number%100);
            }
            else if(number % 100 > 20){
                int remainder = number % 100; //21
                printtens(remainder/10);  //2
                printf("-");
                printdigit(number%10);
            }
            else if(number % 100 <20 && number % 100 >9){
            printteens(number%100);
            }
        }
        break;

        
        case 2:
            if(number % 10 == 0){
                printtens(number/10);
            }
            else{
                if(number ==11){
                    printf("eleven ");
                }
                else{
                    printtens(floor(number/10));
                    printf("-");
                    printdigit(number%10);
                }
            }
        
        case 1:
            printdigit(number);
        
        default:    
            break;  
        }
}

int main (void){
    printf("\e[1;1H\e[2J");
    int number;
    int storenum;
    int totaldigits;
    int remainder;
    printf("=================================================\n");
    printf("Enter money value to convert to check format: \n$");
    scanf("%d", &number);
    totaldigits = countdigits(number);
    printf("The number in check format is: \n");

    if(totaldigits > 9){
        remainder = floor(number / 1000000000); 
        printdigit(remainder);
        if (remainder > 0){
            printf("billion, ");
        }
    }
    storenum = number%1000000000;
    if(totaldigits > 6 ){
        remainder = floor(storenum / 1000000);
        calculate(remainder);
        if (remainder > 0){
            printf("million, ");
        }
    }
    storenum = number%1000000;
    if(totaldigits > 3){
        remainder = floor(storenum / 1000);
        calculate(remainder);
        if (remainder > 0) {
            printf("thousand, ");
        }
    }
    storenum = number%1000;
    if(totaldigits > 0){
        calculate(storenum);
    }
    printf("and 00/100 dollars \n");
    printf("=================================================\n");

    return 0;
}