#include <iostream>
using namespace std;

// the following function determines if an inputted year is a leap year, returning true or false
bool isLeap(int a){
    if (a%100 == 0){ 
    // this part is not really needed because the year range is 2023 to 2050
    // but I am including it for the code to be more "correct"
        if (a%400 ==0){
            return true;
        }
        else{
            return false;
        }
    } 
    else{
        if (a%4 == 0){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){

    int year;
    cin >> year;

    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeap(year)) months[1]++; //converting feburary to 29 days if it is a leap year

    // lines 37-48 determine the first weekday of a year given that 2023 starts on a sunday
    // note：I am representing the weekdays in a scale from 0 to 6, so Monday=0,...,Sunday=6

    int x = 0;
    // the following loop adds all the days that passed between 2023-1-1 and the last day of the previous year
    for (int y=2023; y<year; y++){
        if (isLeap(y)){
            x+=366;
        }
        else{
            x+=365;
        }
    } 
    // by taking the modulo 7 of sunday+(numbers of days passed) we can find the weekday the new year starts on
    int year_start_day = (6 + x) % 7;

    cout << 0 << 1; // outputting the first month number

    for (int col = 0; col < year_start_day; col++){
        printf("   "); // start of year spacing
    }

    int month_start_day = year_start_day; //for first month

    for (int month = 0 ; month < 12 ; month++){

        int month_length = months[month];
        
        int col_count = 0; // explained later

        // note: I am distinguishing between day and date
        // where day refers to monday, tuesday...
        // and date refers to the date of the month, i.e. 1st, 15th, 29th...

        for (int date = 1 ; date <= month_length ; date++){
            if (month_start_day==0){ // this if statement avoids cases where (date%7=7) in the following if statement
                month_start_day = 7;
            } 
            if (date%7==(7-month_start_day)){ // condition determines if the week ended, i.e. if there should be a line skip
                printf("%3d\n", date);
                col_count = 0; // explained later (resets the day to zero whenever a new week started)

                // printing the next month number if the next month will start on this same line
                if ((month_length-date < 7) && month!=11){ 
                    if (month < 8){
                        cout << 0 << month+2; 
                        // +2 because it is printing the next month and because i am indexing jan=0, feb=1,...
                    } 
                    else{
                        cout << month+2;
                    }
                }
                else{
                    printf("  "); // adding necessary spacing at the beginning of each line that is not a new month
                }
            }
            else {
                printf("%3d", date);
                col_count++; // keeping count of the day on which a month ends to determine where the next month starts
            }
        }
        month_start_day = col_count; // assigning a start weekday for the next month
    }
}



