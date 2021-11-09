#include <conio.h>

#include <cstdio>

#include <iostream>

#include <string.h>

#include <cstdlib>

using namespace std;

static int p = 0;

class a

{

    char trainno[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[50][4][10];

public:

    void input();

    void reserve();

    void empty();

    void show();

    void avail();

}

train[10];

void vline(char ch)

{

    for (int i = 50; i > 0; i--)

        cout << ch;

}

void a::input()

{

    cout << "Enter train no: ";

    cin >> train[p].trainno;

    cout << "\nEnter Driver's name: ";

    cin >> train[p].driver;

    cout << "\nArrival time: ";

    cin >> train[p].arrival;

    cout << "\nDeparture: ";

    cin >> train[p].depart;

    cout << "\nFrom: \t\t\t";

    cin >> train[p].from;

    cout << "\nTo: \t\t\t";

    cin >> train[p].to;

    train[p].empty();

    p++;

}

void a::reserve()

{

    int seat;

    char number[5];
   



    cout << "train no: ";

    cin >> number;

    int n;

    for (n = 0; n <= p; n++)

    {

        if (strcmp(train[n].trainno, number) == 0)

            break;

    }

    while (n <= p)

    {

        cout << "\nSeat Number: ";

        cin >> seat;

        if (seat >= 200) 

        {

            cout << "\nThere are only 200 seats available in this train.";

        }

        else

        {

            if (strcmp(train[n].seat[seat / 4][(seat % 4) - 1], "Empty") != 0)

            {

                cout << "Enter passanger's name: ";

                cin >> train[n].seat[seat / 4][(seat % 4) - 1];

                break;

            }

            else
                cout << "The seat no. is already reserved.\n";
            break;
        }

    }

    if (n > p)

    {

        cout << "Enter correct train no.\n";

        

    }

}


void a::empty()

{

    for (int i = 0; i < 50; i++)

    {

        for (int j = 0; j < 4; j++)

        {

            strcmp(train[p].seat[i][j], "Empty");

        }
         
    }

}

void a::show()

{

    int n;

    char number[5];

    cout << "Enter train no: ";

    cin >> number;

    for (n = 0; n <= p; n++)

    {

        if (strcmp(train[n].trainno, number) == 0)

            break;

    }

    while (n <= p)

    {

        vline('* \t');

        cout << "Train no: \t" << train[n].trainno

            << "\nDriver: \t" << train[n].driver << "\t\tArrival time: \t"

            << train[n].arrival << "\tDeparture time:" << train[n].depart

            << "\nFrom: \t\t" << train[n].from << "\t\tTo: \t\t" <<

            train[n].to << "\n";

        vline('*');

        int a = 1;

        for (int i = 0; i < 50; i++)

        {

            for (int j = 0; j < 4; j++)

            {

                a++;

                if (strcmp(train[n].seat[i][j], "Empty") != 0)

                    cout << "\nThe seat no " << (a - 1) << " is reserved for " << train[n].seat[i][j] << ".";

            }

        }

        break;

    }

    if (n > p)

        cout << "Enter correct train no: ";

}


void a::avail()

{
    

    for (int n = 0; n < p; n++)
   

    {

        vline('*');

        cout << "Train no: \t" << train[n].trainno << "\nDriver: \t" << train[n].driver

            << "\t\tArrival time: \t" << train[n].arrival << "\tDeparture Time: \t"

            << train[n].depart << "\nFrom: \t\t" << train[n].from << "\t\tTo: \t\t\t"

            << train[n].to << "\n";

        vline('*');

       

    }

}

int main()

{

    system("cls");

    int select;

    while (1)

    {

       

        cout << "\n\n";

        cout << "1.Input \n" 

            << "2.Reservation\n" 

            << "3.Show\n"

            << "4.Train Available\n"

            << "5.Exit\n";

        cout << "Choose your option:---> ";

        cin >> select;

        switch (select)

        {

        case 1:  train[p].input();

            break;

        case 2:  train[p].reserve();

            break;

        case 3:  train[0].show();

            break;

        case 4:  train[0].avail();

            break;

        case 5:  exit(0);

        }

    }

    system("pause>0");
    return 0;
   
}