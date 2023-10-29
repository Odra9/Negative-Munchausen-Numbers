/* this program works (and makes sense) only if the range
of number search spans only negative integers

the rule is munch(xyz) = (-x)^x + (-y)^y + (-z)^z
with x,y,z digits and xyz < 0 */

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

const int pow[10] = {1, -1, 4, -27, 256, -3125, 46656, -823543, 16777216, -387420489};  //cache of exponentiation values (pow[i] = i^i)

//start and fin are the search limits (included)
const long long int START = -10000;
const long long int END   =     -1;

int main() {
    string n = "";

    if (START*END<=0) {     //check if the range spans only negatives
        cout << "Error, range of search does not make sense";
        return 1;
    }

    for (long long int i=START;i<=END;i++) {
        n = to_string(i).erase(0,1);        //Converts i to string and removes the negative sign in front of the string

        //for loop to calculate the number following munchausen rules
        long long int total = 0;                
        for (int j=1;j<n.length();j++) {        
            int x = n[j] - '0';                 //conversion between character digit and actual digit
            total+=pow[x];
        }

        if (abs(total) == abs(i)) {             //prints the number if a munchausen number has been found
            cout << i << endl;
        } else {
            //now it checks again but this time with 0^0 = 0
            total = 0;                
            for (int j=1;j<n.length();j++) {        
                int x = n[j] - '0';                 
                if (x!=0)               //the digit 0 is removed from the calculation
                    total+=pow[x];
            }

            if (abs(total) == abs(i)) {            
                cout << i << " warning: this considers 0^0 = 0" << endl;
            }
        }        
    } 

    return 0;
}