
#include <iostream>
#include "vmfunctionheader.h"
#include <cstdlib>
#include <ctime>

using namespace std;


int randomize()
{

    int r;
    srand(time(0));
    r = rand();
    while (r>10)
    {
        r = rand();
    }


    return r;
}

bool isiterror(char user)
{
    switch(user)
        {
            case '0':
            return false;

            case '1':
            return false;

            default:
            return true;


        }
}

bool correctmoney (double user)
{

            if (user == 0.01)
                return true;
            else if (user == 0.05)
                return true;
            else if (user == 0.10)
                return true;
            else if (user == 0.25)
                return true;
            else if (user == 1.00)
                return true;
            else if (user == 2.00)
                return true;
            else if (user == 5.00)
                return true;
            else if (user == 10.00)
                return true;
            else
                return false;



}
bool validitem(char user)
{

    switch (user)
        {
        case '1':
            return true;
        case '2':
            return true;
        case '3':
            return true;
        case '4':
            return true;
        case '5':
            return true;
        case '6':
            return true;
        case '7':
            return true;
        case '8':
            return true;
        default:
            return false;
        }
}

std::string getitem(char user)
{


    switch(user)
    {
        case '1':
            return "You received the Cool Ranch Doritos!";
        case '2':
            return "You received the Cheez-Its!";
        case '3':
            return "You received the Pretzels!";
        case '4':
            return "You received the Animal Crackers!";
        case '5':
            return "You received the Baked Lays!";
        case '6':
            return "You received the Snickers!";
        case '7':
            return "You received the Peanut M&Ms!";
        case '8':
            return "You received the Twix!";





    }
}

double prices(char item)
    {
    switch(item)
    {



        case '1':
            return 1.5;
        case '2':
            return 1.35;
        case '3':
            return 1.35;
        case '4':
            return 1.35;
        case '5':
            return 1.50;
        case '6':
            return 1.25;
        case '7':
            return 1.25;
        case '8':
            return 1.00;

    }
    }



