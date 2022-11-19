#include <stdio.h>
#include <stdbool.h>
int main(){
  unsigned int month = 1, day = 1;   // assigned arbitrary numbers because if they are equal to zero they won't enter the while loop
  int year; 
  unsigned int month2, day2;         // copied the original input so that i will be able to recall it in the final printf statement
  int year2;
  printf("\nEnter a date (0 0 0 to quit): ");
  scanf("%u %u %i", &day, &month, &year);
  day2 = day, month2 = month, year2 = year;
  if (month != 0 && day != 0 && year != 0)
  {
    do {
        if (month == 0 && year == 0 && day == 0)
            break;
             // explained in the comment above in line 7
        day++;   //increased the day to see how it will affect the date 
        int maxDay; //define the variable which will store the number of days in the selected month
  
        if (month == 4 || month == 6 || month == 9 || month == 11) {
              maxDay = 30;
         } 

         else if (month == 2) {
           if (year % 400==0) {
            maxDay = 29;                         // more on this part https://www.wikihow.com/Calculate-Leap-Years
            }   
            else if(year % 4==0 & year % 100!=0){
            maxDay = 29;
            }
            else {
            maxDay = 28;
            }
        }  
        else                                     // will look for months out of the valid range in the final printf statement
            maxDay = 31;     

        if (day > maxDay) {       // logic of determining if the day given is the last day of the month
            day = 1;
            month++;
            if (month > 12) {
            month = 1;
            year++;       
            }
        }
  
        if(year !=0 && month != 0 && day != 0){
            if (day2 > maxDay || month > 12 || month <= 0 || day2 <= 0) { // before writing the requested date we check if the input is valid
            printf("This is not a valid date!");
           } else {
            printf("\nThe next day of: %u.%u.%i is %u.%u.%i", day2, month2, year2, day, month, year);  // if so, we proceed
          }
         }
        printf("\nEnter a date (0 0 0 to quit): ");
        scanf("%u %u %i", &day, &month, &year);
        day2 = day, month2 = month, year2 = year; 
    } while( true );

  }
  printf("Thanks for using my program!");
}