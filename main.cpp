#include <iostream>
#include <cstdlib>
#include <ctime>
#include "generator.h"
using std::string, std::cout, std::endl, std::cin;
int getPlace(){
    int placeValue;
    cout<<"What place value would you like to round to?(Default is 1)\n1. All\n2. 10's\n3. 100's\n4. 1000's"<<endl;
    cin >> placeValue;
    return placeValue;
}
int getRoundedNumber(int start, int place){
    int rounded = 0, remainder = 0;
    if(place == 2){
        remainder=start%10;
        if (remainder>=5){
            rounded = start+(10-remainder);
        }
        else if(remainder<5){
            rounded = start-remainder;
        }
    }
    else if(place == 3){
        remainder=start%100;
        if (remainder>=50){
            rounded = start+(100-remainder);
        }
        else if(remainder<50){
            rounded = start-remainder;
        }
    }
    else if(place == 4){
        remainder=start%1000;
        if (remainder>=500){
            rounded = start+(1000-remainder);
        }
        else if(remainder<500){
            rounded = start-remainder;
        }
    }
    return rounded;
}
bool getAnswer(int answer, int orig, int place){
    int input, print=10;
    place-=2;
    while(place != 0){
        print*=10;
        --place;
    }
    cout << "Round " << orig << " to the nearest " << print << endl;
    cin >> input;
    if(answer==input)
        return true;
    else
        return false;
}
int main() {
    bool correct;
    int number, place, rounded, tempPlace, random, tempCounterThatWillBeDeleted=0;
    place = getPlace();
    generator gen(place);
    if (place==1) {
        while (tempCounterThatWillBeDeleted < 1000) {
            random = rand();
            srand(time(0));
            tempPlace = rand() % 3 + 2;
            number = gen.getNumber(random, tempPlace);
            rounded = getRoundedNumber(number, tempPlace);
            for (int i = 0; i < 3; ++i) {
                correct = getAnswer(rounded, number, tempPlace);
                if (correct) {
                    cout << "Correct!" << endl;
                    break;
                } else {
                    cout << "Sorry, thats wrong" << endl;
                }
            }
            tempCounterThatWillBeDeleted++;
        }
    }
    else{
        while (tempCounterThatWillBeDeleted < 1000) {
            random = rand();
            srand(time(0));
            number = gen.getNumber(random, place);
            rounded = getRoundedNumber(number, place);
            for (int i = 0; i < 3; ++i) {
                correct = getAnswer(rounded, number, place);
                if (correct) {
                    cout << "Correct!" << endl;
                    break;
                } else {
                    cout << "Sorry, thats wrong" << endl;
                }
            }
            tempCounterThatWillBeDeleted++;
        }
    }
    return 0;
}