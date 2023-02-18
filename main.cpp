#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "Date.h"
#include "calcDays.h"
using namespace std;
int main(){
    Date userDate;
    string testResult;
    string exposed;
    string secVac; 

    Date datePositive;
    Date dateExposed;
    Date dateSecond;
    
    int mth,dy,year;

    cout << "Do you know if you are you positive or negative? " ;
    cin >> testResult;
    while(testResult == "positive"){  //Case 1
        cout << "Enter date you were positive: "<< endl;
        cin >> mth;
        cin >> dy;
        cin >> year;

        datePositive.setMonth(mth);
        datePositive.setDay(dy);
        datePositive.setYear(year);

        cout << "A positive result was obtained from the test" << endl;
        cout << "A positive test was performed on: " << datePositive.showDate();  
        cout << "Isolation time: 5 days" << endl;
        break;
    }

    while(testResult == "negative"){  //Case 2
        cout << "Were you exposed? ";
        cin >> exposed;
        while(exposed == "No"){
            cout << "A negative result was obtained from the test" << endl;
            cout << "Exposed to positive case: " << exposed << endl;
            cout << "Isolation period: 0 days" << endl;
            break;
        }

        while (exposed == "Yes"){     //Case 3
            cout << "Please enter the date on which you were exposed: " << endl;
            cin >> mth;
            cin >> dy;
            cin >> year;

            dateExposed.setDay(dy);        //Setting for date 2
            dateExposed.setMonth(mth);
            dateExposed.setYear(year);

            cout << "Have you taken a second vaccination? ";
            cin >> secVac;
            while(secVac == "Yes"){
                cout << "The second vaccination date should be entered as follows: " << endl;
                cin >> mth;
                cin >> dy;
                cin >> year; 

                dateSecond.setDay(dy);     //Setting for Date 2
                dateSecond.setMonth(mth);
                dateSecond.setYear(year);

                if (calcDays(dateSecond, dateExposed) > 14){ //Case 3  
                    cout << "A negative result was obtained from the test" << endl;
                    cout << "Exposed to positive case: " << exposed << endl;
                    cout << "Date exposed to positive case: " << dateExposed.showDate();
                    cout << "Second vaccination does received: " << secVac << endl;
                    cout << "Date second vaccination dose received: " << dateSecond.showDate();
                    cout << "Vaccination status at time of exposure: fully vaccinated" << endl;
                    cout << "Isolation time: 5 days" << endl;
                    break;
                }
                else if (calcDays(dateSecond, dateExposed) < 14){    //Case 4a
                    cout << "A negative result was obtained from the test" << endl;
                    cout << "Exposed to positive case: " << exposed << endl;
                    cout << "Date exposed to positive case: " << dateExposed.showDate();
                    cout << "Second vaccination does received: " << secVac << endl;
                    cout << "Date second vaccination: " << dateSecond.showDate();
                    cout << "Not fully vaccinated at time of exposure" << endl;
                    cout << "Isolation period: 10 days" << endl;
                    break;
                }
            }
            
            while(secVac == "No"){    //Case 4b
                cout << "A negative result was obtained from the test" << endl;
                cout << "Exposed to positive case: " << exposed << endl;
                cout << "Date exposed to positive case: " << dateExposed.showDate(); 
                cout << "Second vaccination does received: " << secVac << endl;
                cout << "Not fully vaccinated at time of exposure" << endl;
                cout << "Isolation period: 10 days" << endl;
                break;
            }
        }
    }
    return 0;
}
    
