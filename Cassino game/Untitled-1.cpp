#include <iostream>
#include <cstdlib>
using std::cin, std::cout, std::endl;

double moneyOnAccount, moneyToBet;
int guessingNumber;
char decision;

void Menu ()
{
    cout << "----------------GUESSING NUMBER CASSINO----------------\n";
    cout << "You are guessing number from 1 to 10\n";
    cout << "When you guess, you are getting 10x your betting amount\n";
    cout << "When you loss, you are losimg your betting amount\n";
    cout << "You can't bet more money then you have on your account\n\n";
}

void BettingSystem ()
{   
    do
    {
    cout << "Your current balance is: " << moneyOnAccount << "$\n";
    cout << "Enter amount to bet ($): ";
    cin >> moneyToBet;   
    if (moneyToBet > moneyOnAccount)
        cout << "You don't have enough money on your account!\n";
    else {    
    cout << "Guess number from 1 to 10: ";
    cin >> guessingNumber;
    int randNumb = ((rand() % 10) + 1);
    if (guessingNumber == randNumb)
    {
        moneyToBet*=10;
        cout << "Congratulations! Betting number was " << randNumb << " you have won " << moneyToBet << "$\n";
        moneyOnAccount += moneyToBet;
        cout << "Currently balance: " << moneyOnAccount << "$" << endl;
    } else {
        cout << "Maybe you have more luck next time, betting number was " << randNumb << endl << endl;   
        moneyOnAccount -= moneyToBet;
        cout << "Currently balance: " << moneyOnAccount << "$" << endl;
    }    
    }

    if (moneyOnAccount == 0)
    {   
        cout << "You lost all your money! You can't play again.\n";
        break;
    }
    
    cout << "\nIf you want to play again enter 'Y',\nif you want to end press any other button: ";
    cin >> decision;
    system("cls"); 
    Menu();
    
    } while (decision == 'Y' || decision == 'y');
}

int main ()
{
    cout << "Hello in our Cassino\n";
    cout << "Enter how much $ you want to transfer on your account: ";
    cin >> moneyOnAccount;

    if (moneyOnAccount > 0)
    {
    system("cls");         
    Menu();
    BettingSystem ();
    cout << "Your ending balance is " << moneyOnAccount << "$\n";
    cout << "See you again!";
    } else
        cout << "You can't play with this amount of money! Restart app if you want to play again";    
   
    system("pause>0");
    return 0;
}