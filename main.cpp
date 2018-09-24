#include <iostream>
#include "vmfunctionheader.h"


using namespace std;

void moneyamount (double enter)
{
    double entnum = 0;
    entnum += enter;
    cout << "Amount entered: " << entnum << endl;
}

int main()

{



    bool wantstobuy = false;
    double mymoney;
    char spendmore;
    double track = 0;
    bool dollabill;
    bool cancel;

    char buy;
    cout << "It's a vending machine! Would you like to buy something? (Enter 1 for yes or 0 for no) ";
    cin >> buy;

    //Have user choose yes or no to use vending machine.

    bool error = isiterror(buy);
    while (error == true)
    {
        cout << "Invalid entry. Try again.";
        cin>> buy;
        error = isiterror(buy);
    }

if (buy == '1')
    //enter your money
    {
        wantstobuy = true;

    while (wantstobuy == true)
    {

    cout << "Enter your money. We accept up to $10: ";
    cin >> mymoney;
    dollabill = correctmoney (mymoney);
    //Checks to see if valid money was entered (pennies, nickels, etc.).

                while (dollabill == false)
                {
                    cout << "Money entered is not valid. Try again.\n" << endl;
                    cout << "Enter your money. We accept up to $10: ";
                    cin >> mymoney;
                    dollabill = correctmoney (mymoney);


                }

    //Keeps track of how much money you entered.
    track += mymoney;
    moneyamount (track);

    //Breaks loop if amount of money entered exceeds $10.

    if (track >=10)
    {
        cout << "That's enough money. Buy something!\n" << endl;
        spendmore = '0';

    }

    //Continues loop as long as amount of money is < $10.
    else
    {


    cout << "Enter more? (Enter 1 for yes or 0 for no)";
    cin >> spendmore;

    }

    if (spendmore == '0')
        wantstobuy = false;


    }




    //displays items
    string stuff[10];
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
    char whatitem;
    //Gives user change back.
    double change;

    cout << "Enter the number of the snack that you want to buy: ";
    cin >> whatitem;
    bool goodentry = true;

    goodentry = validitem(whatitem);

    //Checks to see if item entry was valid.
    while (goodentry == false)
    {
        cout <<"Invalid entry. Try again. ";
        cout << "Enter the number of the snack that you want to buy: ";
        cin >> whatitem;
        goodentry = validitem(whatitem);

    }


    int random;

    //Randomizes the item that you choose.
    random = randomize();
    bool outofstock;

    if (random == 0)
    {
        outofstock = true;
    }
    else
    {
        outofstock = false;
    }




    //Pay money
    double howmuch = prices(whatitem);


    //Transaction. If not enough money or out of stock, have user enter more money, choose another item, or give user money back.

    while (track<howmuch || outofstock == true)
    {

        char nogo = '0';

        if (track < howmuch)
        {
            cout << "Insufficient funds. Press 1 to enter more money, 2 to cancel transaction, or 3 to choose another item: ";
            cin >> nogo;
            //Cancels transaction.
            if (nogo == '2')
            {change = track;
            cout << "Your change is: $" << change << ".\n\nGoodbye!" << endl;
            break;
            }

        }
        else if (outofstock == true)
        {

            cout << "Sorry, this item is out of stock. Press 1 to enter more money, 2 to cancel transaction, or 3 to choose another item: ";
        }


        //If user enters more money
        if (nogo == '1')
        {
            wantstobuy = true;
            while (wantstobuy == true)
            {

            cout << "Enter your money. We accept up to $10: ";
            cin >> mymoney;
            dollabill = correctmoney (mymoney);

             while (dollabill == false)
                {
                    cout << "Money entered is not valid. Try again.\n" << endl;
                    cout << "Enter your money. We accept up to $10: ";
                    cin >> mymoney;
                    dollabill = correctmoney (mymoney);


                }

            track += mymoney;
            moneyamount (track);


            if (track >=10)
            {
        cout << "That's enough money. Buy something!\n" << endl;
        spendmore = '0';

            }

            else
                {


            cout << "Enter more? (Enter 1 for yes or 0 for no)";
            cin >> spendmore;
            if (spendmore == '0')
            {
                wantstobuy = false;
            }

                }

            }


        }


    {

        //Displays items if user enters more money or if they choose another item with the money already entered.
        if (nogo == '1' || nogo == '3')
              {

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



                cout << "Enter the number of the snack that you want to buy: ";
                cin >> whatitem;


                goodentry = validitem(whatitem);

                while (goodentry == false)
                {
                    cout <<"Invalid entry. Try again. ";
                    cout << "Enter the number of the snack that you want to buy: ";
                    cin >> whatitem;
                    goodentry = validitem(whatitem);

                }





                //Pay money

                howmuch = prices(whatitem);
                if (track>= howmuch)
                    break;



              }
                // Sets change back equal to amount of money put in if user decides to cancel transaction.
    }





    }

    //Goes through with transaction.
    if (track>= howmuch)
    {


    howmuch = prices(whatitem);








         //Playful message for if the user gets the last of an item.
        if (random == 1)
        {
            cout << "Looks like this was the last one for today. You lucky dog!\n\n" << endl;

        }
        else
        {cout << "There are "<< random << " of this item left in stock today.\n" << endl;}


        cout << "Your price is " << howmuch << ".\n" << endl;
        //gives you the item
        string whatuget = getitem(whatitem);
        cout << whatuget << endl;
       change = track - howmuch;
        cout << "Your change is: " << change << ".\n\nGoodbye!" << endl;
    }



    }



// If user decides not to use vending machine at the beginning.
else
    cout << "Goodbye!" << endl;














    return 0;

    }























