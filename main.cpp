#include <iostream>
#include "vmfunctionheader.h"


using namespace std;

void moneyAmount (double enter)
{
    double entNum = 0;
    entNum += enter;
    cout << "Amount entered: $" << entNum << endl;
}

class VendingItem {

        public:

        string name;

        double price;

};


int main()

{

    VendingItem v1;
    v1.name = "Cool Ranch Doritos";

    cout << v1.name << endl;

    bool wantsToBuy = false;
    double myMoney;
    char spendMore;
    double track = 0;
    bool dollaBill;
    bool cancel;

    char buy;
    cout << "It's a vending machine! Would you like to buy something? (Enter 1 for yes or 0 for no) ";
    cin >> buy;

    //Have user choose yes or no to use vending machine.

    bool error = isItError(buy);
    while (error == true)
    {
        cout << "Invalid entry. Try again.";
        cin>> buy;
        error = isItError(buy);
    }

if (buy == '1')
    //enter your money
    {
        wantsToBuy = true;

    while (wantsToBuy == true)
    {

    cout << "Enter your money. We accept up to $10: ";
    cin >> myMoney;
    dollaBill = correctMoney (myMoney);
    //Checks to see if valid money was entered (pennies, nickels, etc.).

                while (dollaBill == false)
                {
                    cout << "Money entered is not valid. Try again.\n" << endl;
                    cout << "Enter your money. We accept up to $10: ";
                    cin >> myMoney;
                    dollaBill = correctMoney(myMoney);

                }

    //Keeps track of how much money you entered.
    track += myMoney;
    moneyAmount (track);

    //Breaks loop if amount of money entered exceeds $10.

    if (track >=10)
    {
        cout << "That's enough money. Buy something!\n" << endl;
        spendMore = '0';

    }

    //Continues loop as long as amount of money is < $10.
    else
    {


    cout << "Enter more? (Enter 1 for yes or 0 for no)";
    cin >> spendMore;

    }

    if (spendMore == '0')
        wantsToBuy = false;


    }




    //displays items
    string stuff[8];
    stuff[0] = "What would you like?";
    stuff[1] = "1 - Cool Ranch Doritos $1.50";
    stuff[2] = "2 - Cheez-Its $1.35";
    stuff[3] = "3 - Pretzels $1.35";
    stuff[4] = "4 - Animal Crackers $1.35";
    stuff[5] = "5 - Baked Lays $1.50";
    stuff[6] = "6 - Snickers $1.25";
    stuff[7] = "7 - Peanut M&Ms $1.25";
    stuff[8] = "8 - Twix $1.00";




    for (int a = 0; a<=8; a++)
    {

        cout << stuff[a] << endl;
    }





    // Has user choose what item they want.
    char whatItem;
    //Gives user change back.
    double change;

    cout << "Enter the number of the snack that you want to buy: ";
    cin >> whatItem;
    bool goodEntry = true;

    goodEntry = validItem(whatItem);

    //Checks to see if item entry was valid.
    while (goodEntry == false)
    {
        cout <<"Invalid entry. Try again. ";
        cout << "Enter the number of the snack that you want to buy: ";
        cin >> whatItem;
        goodEntry = validItem(whatItem);

    }

    int random;

    //Randomizes the amount left of the item you chose.
    random = randomize();
    bool outOfStock;

    if (random == 0)
    {
        outOfStock = true;
    }

    else
    {
        outOfStock = false;
    }

    //Pay money
    double howMuch = prices(whatItem);


    //Transaction. If not enough money or out of stock, have user enter more money, choose another item, or give user money back.

    while (track<howMuch || outOfStock == true)
    {

        char noGo = '0';

        if (track < howMuch)
        {
            cout << "Insufficient funds. Press 1 to enter more money, 2 to cancel transaction, or 3 to choose another item: ";
            cin >> noGo;
            //Cancels transaction.
            if (noGo == '2')
            {change = track;
            cout << "Your change is: $" << change << ".\n\nGoodbye!" << endl;
            break;
            }

        }
        else if (outOfStock == true)
        {

            cout << "Sorry, this item is out of stock. Press 1 to enter more money, 2 to cancel transaction, or 3 to choose another item: ";
        }


        //If user enters more money
        if (noGo == '1')
        {
            wantsToBuy = true;
            while (wantsToBuy == true)
            {

            cout << "Enter your money. We accept up to $10: ";
            cin >> myMoney;
            dollaBill = correctMoney (myMoney);

             while (dollaBill == false)
                {
                    cout << "Money entered is not valid. Try again.\n" << endl;
                    cout << "Enter your money. We accept up to $10: ";
                    cin >> myMoney;
                    dollaBill = correctMoney (myMoney);


                }

            track += myMoney;
            moneyAmount (track);


            if (track >=10)
            {
        cout << "That's enough money. Buy something!\n" << endl;
        spendMore = '0';

            }

            else
                {


            cout << "Enter more? (Enter 1 for yes or 0 for no)";
            cin >> spendMore;
            if (spendMore == '0')
            {
                wantsToBuy = false;
            }

                }

            }


        }


    {

        //Displays items if user enters more money or if they choose another item with the money already entered.
        if (noGo == '1' || noGo == '3')
              {

                for (int a = 0; a<=8; a++)
                {

                    cout << stuff[a] << endl;
                }



                cout << "Enter the number of the snack that you want to buy: ";
                cin >> whatItem;


                goodEntry = validItem(whatItem);

                while (goodEntry == false)
                {
                    cout <<"Invalid entry. Try again. ";
                    cout << "Enter the number of the snack that you want to buy: ";
                    cin >> whatItem;
                    goodEntry = validItem(whatItem);

                }


                //Pay money

                howMuch = prices(whatItem);
                if (track>= howMuch)
                    break;

              }
                // Sets change back equal to amount of money put in if user decides to cancel transaction.
    }





    }

    //Goes through with transaction.
    if (track>= howMuch)
    {


    howMuch = prices(whatItem);

         //Playful message for if the user gets the last of an item.
        if (random == 1)
        {
            cout << "Looks like this was the last one for today. You lucky dog!\n\n" << endl;

        }
        else
        {cout << "There are "<< random << " of this item left in stock today.\n" << endl;}


        cout << "Your price is " << howMuch << ".\n" << endl;
        //gives you the item
        string whatUGet = getItem(whatItem);
        cout << whatUGet << endl;
       change = track - howMuch;
        cout << "Your change is: " << change << ".\n\nGoodbye!" << endl;
    }

    }


// If user decides not to use vending machine at the beginning.
else
    cout << "Goodbye!" << endl;



    return 0;

    }























