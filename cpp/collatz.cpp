#include <iostream>
using namespace std;
/*The Collatz Conjecture begins with any positive integer n:
 * If it is odd, multiply by 3 and add 1, which is 3n+1, which is why it is also called the
 * 3n + 1 problem.
 * If it is even, simply divide by 2. This makes it so that your starting number n is transformed into many
 * numbers, and these are called hailstone numbers because they keep going up and falling back down.
 * Eventually, you will get the number 4, 4/2 = 2, 2/2 = 1, 1.(3n+1) = 4, and we can see that we have an
 * infinitely repeating loop now.
 * The Collatz Conjecture states that applying these steps to any positive integer n will eventually give you 4-2-1 loop,
 * but the problem is that it has never been mathematically proven to be true for all numbers, so the number line
 * is infinite, and scientists have only bruteforce tested numbers upto 2^68.
 * Also, it doesn't hold true for negative integers, only positive integers.
 * This is a fun little thing which you can use to see if the Collatz Conjecture holds true for certain numbers,
 * though it really can't go to 2^68 levels
 */
int main() {
    int c; // variable to iterate through the collatz conjecture
    int num = 0; //number of hailstone numbers/iterations the 3n+1 goes through
    int digitCount[9];
    for (int i = 0; i <9; i++) {
        digitCount[i] = 0; // array to store count of leading digits, all values are initially 0
    }
    int y;
    cout<< "Enter a number" << endl;
    cin>>c;
    cout<< "We're going to check for the Collatz conjecture or 3n+1 problem\n";
    cout<< "This might be a very bad idea\n";
    cout<< "Your starting number : "<< c << endl;
    cout<< "Time to see the hailstone numbers: \n";
    do {
        if( c%2 == 0 ) {
            c = c/2; //if number is even, divide by 2
            cout<< c << " ";
            num++;
            if (c > 10) {
                y = c;
                while(y > 10){ //if c>10, y/10 will eventually give us the leading digit
                    y = y/10;
                }
                digitCount[y-1]++; //y is the number, but array index is 0, so y-1 is the position
            }
            else if(c < 10){ // if c<10, c is the leading digit as it's the only digit
                digitCount[c-1]++; // same logic as y above
            }
        }
        else if( c%2 != 0 ){
            c = (3*c) + 1; //if number is odd, do 3n + 1 where n is the number
            cout<< c << endl;
            num++;
            if (c > 10) {
                y = c;
                while(y > 10){
                    y = y/10;
                }
                digitCount[y-1]++;
            }
            else if(c < 10){
                digitCount[c-1]++;
            }
        }
    }while( c != 1 );
    cout<< endl;
    cout<< "Number of hailstone numbers is : " << num << endl;
    cout<< "Distribution of numbers: \n";
    cout<< "Leading Digit: 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |\n";
    cout<< "Times Appeared";
    for (int j = 0; j< 9 ; j++){
        cout << " " << digitCount[j] << " |";
    }
}
