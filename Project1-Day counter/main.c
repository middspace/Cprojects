/*
Program Name: Project1_JacobSchnitker.c
Programmer: Jacob Schnitker
Class: CS 3335
Project: 01
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool isLeapYear(int year); //declartion
int getMonthDays(int month); //declartion
bool checkInput(int month, int day, int year); //declartion

int main()
{
    int days = 0;
    int month1, day1, year1, month2, day2, year2;

    printf("Enter the first date: ");
    scanf("%d/%d/%d", &month1, &day1, &year1);
    if(checkInput(month1, day1, year1) == false){
        printf("Invalid format, please try again");
        exit(1);
    }
    printf("\nEnter the second date: ");
    scanf("%d/%d/%d", &month2, &day2, &year2);
    if(checkInput(month2, day2, year2) == false){
        printf("Invalid format, please try again");
        exit(1);
    }
    
    if(year2 < year1){
        printf("Please enter the earlier date first");
        exit(1);
    }
   
   
    if(year1 == year2 && month1 == month2){
        days+= (day2 - day1);
    }
    else if(year1 == year2){
        for(int i = month1; i<=month2; i++){
            if(i == month1){
                days+= getMonthDays(month1) - day1;
            }
            else if(i == month2){
                days += day2;
            }
            else{
                days += getMonthDays(i);
            }
        }
        
    }
    
    printf("\nNumber of dates between the two dates is: %d", days+1);

    return 0;
}

bool isLeapYear(int year){ //this method checks to see if one of the inputed years is a Leap Year
    bool flag = false;
    if((year % 4) == 0){
        if((year % 100) != 0){
            flag = true;
            return flag;
        }
        else{
            if((year % 400) == 0){
                flag = true;
                return flag;
            }
            else{
                return flag;
            }
        }
    }
    else{
        return flag;
    }
}

int getMonthDays(int month){ //this method grabs that amounts days that in each month
    switch(month){
        case 1: return 31;
                break;
        case 2: return 28;
                break;
        case 3: return 31;
                break;
        case 4: return 30;
                break;
        case 5: return 31;
                break;
        case 6: return 30;
                break;
        case 7: return 31;
                break;
        case 8: return 31;
                break;
        case 9: return 30;
                break;
        case 10: return 31;
                 break;
        case 11: return 30;
                 break;   
        case 12: return 31;
                 break;
        
    }
}
    
bool checkInput(int month, int day, int year){
    bool flag = true;
    
    if(day == 0){
        flag = false;
        return flag;
    }
    
    if(month > 12 || month < 1){  //checks to see if month is valid
        flag = false;
        return flag;
    }
    
    if(isLeapYear(year) == true && month == 2 && day == 29){ //if feb. 29th is entered when the year is a leap year, it is a valid input
        return flag;
    }
        
    if(getMonthDays(month) < day){ //checks to see if the day of the month exists
        flag = false;
        return flag;
    }
    
    if(year > 9999 || year < 1000){ //checks to se if year follows the yyyy parameter
        flag = false;
        return flag;
    }
    
        
    return flag;
}
    