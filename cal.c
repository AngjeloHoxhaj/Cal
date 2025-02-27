//it2024104
//Αγγελο χοτζάι


#include <stdio.h>
#include <stdlib.h>

int get_dow(int, int, int);

void month1(int);

int days_in_month(int, int);

int main(){
    int year, month, w, m=2;
    char a=' ';

    printf("Welcome to the calendar.\n");
    printf("Year: ");
    do {
        if (scanf("%d", &year) != 1 || year<1 || year>10000) {
            printf("Error reading number, try again: ");
            //  Empty scanf buffer
            while (getchar() != '\n');
        } else {
            while (getchar() != '\n');
            break;
        }
    } while (1);

    printf("Month (0 to print entire year): ");
    do {
        if (scanf("%d", &month) != 1 || (month<0 || month>12)) {
            printf("Error reading number, try again: ");
            while (getchar() != '\n');
            //Empty scanf buffer
        } else {
            while (getchar() != '\n');
            break;
        }
    } while (1);

    if (month==0){//If the month input is equal to 0 the program runs a block of code that displays the whole year to the user.
        printf("%36d\n", year);
        m=1;
        int i=1, k=0, k1=0;

        while (m<=4){//A loop that displays three months of the year every time that the while function is true

            month=3*m-2;//initialization of the moth variable so that the for loop can display to the user the correct month
            for (i; i<=3*m; i++){
                month1(i);
            }
            printf("\n");
            printf(" Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa \n");

            int x=days_in_month(month, year);
            int d=1, d2=1, d3=1, y=2, z=2;
            while (d<=x || (d2<=y && k!=1) || (d3<=z && k1!=1)){//loop that displays the days of the first month of the while loop

                if (d<=x){
                    w=get_dow(d, month, year);
                }
                if (d==1){
                    for (int b=1; b<w; b++){//displays spaces depending on the value of w so that it centers the days correctly
                        printf("%3c", a);
                    }
                }

                if (w==0){//in case there is a day that isnt correct or doesnt exist it skips the comands that follow after so that it doesnt display any unwanted day
                    ++d;
                    continue;
                }
                if (d<=x){
                    printf("%3d", d);
                } else {
                    for (int i=0; i<7; i++)
                        printf("%3c", a);
                }
                if (w!=7 && d==x){
                    for (int i=0; i<(7-w); i++)
                        printf("%3c", a);//it prints spaces to correctly ceneter the other months when we finish with the current month 
                }

                if (w==7 || d>=x){//in case the current day is Saturday it jumps to the next month temporarely
                    k=0;
                    ++month;
                    y=days_in_month(month, year);
                    printf("%c", a);
                    while ((d2<=y && k!=1) || (d3<=z && k1!=1)){//loop displays the days of the second month of the while loop
                        if (d2<=y){
                            w=get_dow(d2, month, year);
                        }
                        if (d2==1){
                            for (int b=1; b<w; b++){//displays spaces depending on the value of w so that it centers the days correctly
                                printf("%3c", a);
                            }
                        }

                        if (w==0){//in case there is a day that isnt correct or doesnt exist it skips the comands that follow after so that it doesnt display any unwanted day
                            ++d2;
                            continue;
                        }
                        if (d2<=y){
                            printf("%3d", d2);
                        } else {
                            for (int i=0; i<7; i++)
                                printf("%3c", a);
                        }
                        if (w!=7 && d2==y){
                            for (int i=0; i<(7-w); i++)
                                printf("%3c", a);//it prints spaces to correctly ceneter the other months when we finish with the current month 
                        }

                        if (w==7 && d3>z){//changes line so that it starts the whole process again in a correct line
                            printf("\n");
                            }
                        if (w==7 || d2>=y){//in case the current day is Saturday it jumps to the next month temporarely
                            k1=0;
                            ++month;
                            z=days_in_month(month, year);
                            if (d3<=z){
                                printf("%c", a);
                            }
                            while (d3<=z && k1!=1){//loop that displays the days of the third month of the while loop
                                if (d3<=z){
                                    w=get_dow(d3, month, year);
                                }
                                if (d3==1){
                                    for (int b=1; b<w; b++){//displays spaces depending on the value of w so that it centers the days correctly
                                        printf("%3c", a);
                                    }
                                }

                                if (w==0){//in case there is a day that isnt correct or doesnt exist it skips the comands that follow after so that it doesnt display any unwanted day
                                    ++d3;
                                    continue;
                                }
                                
                                printf("%3d", d3);

                                if (w==7){//changes line so that it starts the whole process again in a correct line
                                    printf("\n");
                                    k1=1;
                                } else if (d3==z){
                                    printf("\n");
                                }
                                ++d3;
                            }
                            k=1;
                        }
                        ++d2;
                    }
                    month-=2;
                }
                ++d;
                if (d2<=y){
                    k=0;
                }
                if (d3<=z){
                    k1=0;
                }    
            }
            printf("\n");
            ++m;
        }
    } else {//If the month input is form 1 to 12 the program runs a block of code that displays the month of the year that the user is asking.
        month1(month);
        printf("\n");
        printf(" Su Mo Tu We Th Fr Sa \n");
        
        int d=1;
        int x=days_in_month(month, year);
        while (d<=x){//loop that displays every day of the month

            w=get_dow(d, month, year);
            if (d==1){
                for (int b=1; b<w; b++){
                    printf("%3c", a);
                }
            }

            if (w==0){//in case there is a day that isnt correct or doesnt exist it skips the comands that follow after so that it doesnt display any unwanted day
                ++d;
                continue;
            }
            printf("%3d", d);
            if (w==7){//changes line so that it can start the next week in a correct line
                printf("\n");
            }
            ++d;
        }
        printf("\n");
    }
    
return 0;
}

int get_dow(int day, int month, int year){// a function that returns the day of the week corresponding to the date given
    int w;

    if (day<1 || day>31 || month<1 || month>12 || year<1 || year>9999){
        return 0;
    }
    if (month==1){//it corrects the month and year value so that the function gives a correct value
        month=13;
        year-=1;
    } else if (month==2){
        month=14;
        year-=1;
    }

    if (year>1752){// uses a version of Zeller's congruence to calculate the day of the week
        
        w=(day + (13*(month+1))/5 + year + year/4 - year/100 + year/400) % 7;

    } else if (year<=1752) {
        if (year==1752 && month>=9){
            if (month==9 && day>=14){
                w=(day + (13*(month+1))/5 + year + year/4 - year/100 + year/400) % 7;
                if (w==0){
                    w=7;
                }
                return w;
            } else if (month==9 && day<=2){
                w=(day + (13*(month+1))/5 + year + year/4 + 5) % 7;
                if (w==0){
                    w=7;
                }
                return w;
            } else if (month==9 && (day<14 && day>2)){
                return 0;
            }

            w=(day + (13*(month+1))/5 + year + year/4 - year/100 + year/400) % 7;
            if (w==0){
                w=7;
            }
            return w;

        }

        w=(day + (13*(month+1))/5 + year + year/4 + 5) % 7;    
    }

    if (w==0){
        w=7;
    }

    return w;
}

void month1(int month){//this function returns the month based on the number entered
    if (month==1){
        printf("          Jan         ");
    } else if (month==2){
        printf("          Feb         ");
    } else if (month==3){
        printf("          Mar         ");
    } else if (month==4){
        printf("          Apr         ");
    } else if (month==5){
        printf("          May         ");
    } else if (month==6){
        printf("          Jun         ");
    } else if (month==7){
        printf("          Jul         ");
    } else if (month==8){
        printf("          Aug         ");
    } else if (month==9){
        printf("          Sep         ");
    } else if (month==10){
        printf("          Oct         ");
    } else if (month==11){
        printf("          Nov         ");
    } else if (month==12){
        printf("          Dec         ");
    }
} 

int days_in_month(int month, int year){//this function retuns the number of days in a specific month and year
    if (year<=1752){
            if (month==4 || month==6 || month==9 || month==11){
                return 30;
            } else if ((month==2)&&(year%4==0)){
                return 29;
            } else if (month==2){
                return 28; 
            } else {
                return 31;
            }
    } else {
        if (month==4 || month==6 || month==9 || month==11){
            return 30;
        } else if ((month==2)&&((year%4==0 && year%100!=0) || (year%400==0))){
            return 29;        
        } else if (month==2){
            return 28;
        } else {
            return 31;
        }
    }
}