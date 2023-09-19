#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct room
{
    int floor;
    char roomNumber[20];
    char roomId[20];
    float rate;
    string status;
    char customerId[20];

} rooms;

struct customer
{
    string fname, mname;
    char email[50];
    char phoneNumber[20];
    char payphone[20];
    int transaction;
    char customerId[20];
    char roomIdc[20];
    char password[20];
    string status;

} customers;
char gomain;
// ADMIN
char menu();
void addRoom();
void displayRoom(char);
bool payment(bool how = true);
void searchRoom();
void editRoom();
void custumer_onhold();
void verify_payment();

void reserveRoom();
void cancel(char* password,string f_name="0",string l_name_1="0");
void displayCustomer(char);


int main()
{
    char holdwho;
    holdwho = menu();
    switch (holdwho)
    {
    case '1':
    customermenu:
        system("cls");
        char customerOption;

        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        cout << "--------------------------------------MENU FOR CUSTEMER----------------------------------------------" << endl;
        cout << "\n\t\t\t\t  1.Display Available Room";
        cout << "\n\t\t\t\t  2.Reserve Room";
        cout << "\n\t\t\t\t  3.Cancel Reservation";
        cout << "\n\t\t\t\t  4.Search For Room";
        cout << "\n\t\t\t\t  5.Payment";
        cout << "\n\t\t\t\t  6.Exit";
        cout << "\n\t\t\t\t  ----------------------";
        cout << "\n\t\t\t\t  choose Option[1/2/3/4]";
        cout << "\n\t\t\t\t  ----------------------";
        cout << "\nEnter your choice: ";
        cin >> customerOption;
        switch (customerOption)
        {
        case '1':
            displayRoom('N');
            cout << "\n Do You Want To Return To The Customer Menu: ";
            cin >> gomain;
            if (gomain == 'y' || gomain == 'Y')
            {
                goto customermenu;
            }
            break;
        case '2':
        {
            char holdr[100];
            reserveRoom();
            cout << "\n Do You Want To Return To The Customer Menu: ";
            cin >> gomain;
            if (gomain == 'y' || gomain == 'Y')
            {
                goto customermenu;
            }

            break;
        }
        case '3':{char paa[20]={'0'};
            cancel(paa);
            cout << "\n Do You Want To Return To The Customer Menu: ";
            cin >> gomain;
            if (gomain == 'y' || gomain == 'Y')
            {
                goto customermenu;
            }
            break;}
        case '4':
            searchRoom();
            cout << "\n Do You Want To Return To The Customer Menu: ";
            cin >> gomain;
            if (gomain == 'y' || gomain == 'Y')
            {
                goto customermenu;
            }
            break;
        case '5':
            payment();
            break;
        case '6':
            system("cls");
            cout << "\n\n\t\t\t\t Successfully Exited\n\n";
            exit(0);
            break;
        default:
            cout << "\n\t\t\t\t  Invalid Input";
        }
        break;

    case '2':// ADMIN
    {

        string password = "admin";
        string passcode;
    trypass:
        cout << "\nEnter Your Admin Password: ";
        cin >> passcode;

        if (passcode == "1")
        {
            system("cls");
            cout << "\n\t\t\t\t  Successfully Exited";
            cout << "\n";
            exit(0);
        }

        else if (password != passcode)
        {
            system("cls");
            cout << "\n\t\t\t\t  WRONG PASSWORD! pleasw try to  enter the correct password" << endl;
            cout << "\t\t\t\t  If you forget the password communicate with the ICT team." << endl;
            cout << "\t\t\t\t  To exit press [1] " << endl;
            goto trypass;
        }
        else if (password == passcode)
        {
        adminmenu:
            int adminOption;
            system("cls");
            cout << "---------------------------------------------------------------------------------------------------" << endl;
            cout << "--------------------------------------MENU FOR ADMIN-----------------------------------------------" << endl;

            cout << "\n\t\t\t\t  1.Add Room";
            cout << "\n\t\t\t\t  2.Display All Room";
            cout << "\n\t\t\t\t  3.Display Available Room";
            cout << "\n\t\t\t\t  4.Display Reserved ROOM";
            cout << "\n\t\t\t\t  5.Customer and Room Control";
            cout << "\n\t\t\t\t  6.Display customer";
            cout << "\n\t\t\t\t  7.Edit Room";
            cout << "\n\t\t\t\t  8.Search For Room";
            cout << "\n\t\t\t\t  9.Display Not Verified Customers";
            cout << "\n\t\t\t\t  10.Display Customers Who haven't Pay";
            cout << "\n\t\t\t\t  11.Exit";
            cout << "\n\t\t\t\t   --------------------------";
            cout << "\n\t\t\t\t   choose Option[1/2/3/4/5/6]";
            cout << "\n\t\t\t\t   --------------------------" << endl;
            default_1:
            cout << "\n Enter your choice: ";
            cin >> adminOption;

            switch (adminOption)
            {
            case 1:
                char addmore;
                do
                {
                    addRoom();
                    cout << "\n\n\t\t\t\t Add Another Room (Y,N): ";
                    cin >> addmore;
                } while (addmore == 'Y' || addmore == 'y');
                //**** cout<<"\n\t\t\t\t  You Have Successfully Added!"<<endl;
                goto adminmenu;
                break;
            case 2:
                displayRoom('A');
                cout << "\n Do You Want To Return To The Admin Menu: ";
                cin >> gomain;
                if (gomain == 'y' || gomain == 'Y')
                {
                    goto adminmenu;
                }
                break;
            case 3:
                displayRoom('N');
                cout << "\n Do You Want To Return To The Admin Menu: ";
                cin >> gomain;
                if (gomain == 'y' || gomain == 'Y')
                {
                    goto adminmenu;
                }
                break;
            case 4:
                displayRoom('R');
                cout << "\n Do You Want To Return To The Admin Menu: ";
                cin >> gomain;
                if (gomain == 'y' || gomain == 'Y')
                {
                    goto adminmenu;
                }
                break;
            case 5:verify_payment();
            cout << "\n Do You Want To Return To The Admin Menu: ";
                cin >> gomain;
                if (gomain == 'y' || gomain == 'Y')
                {
                    goto adminmenu;
                }
                break;
            case 6:
                displayCustomer('A');
                cout << "\n Do You Want To Return To The Admin Menu: ";
                cin >> gomain;
                if (gomain == 'y' || gomain == 'Y')
                {
                    goto adminmenu;
                }
                break;
            case 7:
                editRoom();
                cout << "\n Do You Want To Return To The Admin Menu: ";
                cin >> gomain;
                if (gomain == 'y' || gomain == 'Y')
                {
                    goto adminmenu;
                }
                break;
            case 8:
                searchRoom();
                cout << "\n Do You Want To Return To The Admin Menu: ";
                cin >> gomain;
                if (gomain == 'y' || gomain == 'Y')
                {
                    goto adminmenu;
                }
                break;
            case 9:displayCustomer('C'); //NOT VERIFIED==CONFIRM
                cout << "\n Do You Want To Return To The Admin Menu: ";
                cin >> gomain;
                if (gomain == 'y' || gomain == 'Y')
                {
                    goto adminmenu;
                }
                break;
            case 10:displayCustomer('H'); //HOLD==CUSTOMERS WHO HAVEN'T PAY
                cout << "\n Do You Want To Return To The Admin Menu: ";
                cin >> gomain;
                if (gomain == 'y' || gomain == 'Y')
                {
                    goto adminmenu;
                }
                break;
            case 11:
                system("cls");
                cout << "\n\n\t\t\t\t Successfully Exited\n\n";
                exit(0);
                break;
            default:
                cout << "\n Invalid choice... please try again ...." << endl;
                goto default_1;
                break;

            }
        }
        break;
    }
    case '3':
        cout << "\n\t\t\t\t  Successfully Exited";
        cout << "\n";
        break;
    default:
        cout << "\n Invalid choice... please try again ...." << endl;
        break;
    }

    return 0;
}
char menu()
{
    char who;
mainmenu:
    system("cls");

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t# #     # #   # # # # # #   # # # # # # #   # # # # # #   # #" << endl;
    cout << "\t\t\t\t# #     # #   # # # # # #   # # # # # # #   # # # # # #   # #" << endl;
    cout << "\t\t\t\t# #     # #   # #     # #        # #        # #           # #" << endl;
    cout << "\t\t\t\t# # # # # #   # #     # #        # #        # # # # #     # #" << endl;
    cout << "\t\t\t\t# # # # # #   # #     # #        # #        # # # # #     # #" << endl;
    cout << "\t\t\t\t# #     # #   # #     # #        # #        # #           # #" << endl;
    cout << "\t\t\t\t# #     # #   # # # # # #        # #        # # # # # #   # # # # # #" << endl;
    cout << "\t\t\t\t# #     # #   # # # # # #        # #        # # # # # #   # # # # # #" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t# # # # # #    # # # # # #    # # # # # ##   # # # # # #  # # # # # #    # #           # #       # #       # # # # # # #  # # # # # # #   # # # # # #  # # #        # #  " << endl;
    cout << "\t\t\t# #      # #   # # # # # #   # # # # # # #   # # # # # #  # #      # #    # #         # #       # # #      # # # # # # #  # # # # # # #   # # # # # #  # # # #      # #    " << endl;
    cout << "\t\t\t# #      # #   # #            # #            # #          # #      # #     # #       # #       # # # #          # #            # #        # #     # #  # #  # #     # #    " << endl;
    cout << "\t\t\t# # # # # #    # # # # #        # #          # # # # #    # # # # # #       # #     # #       # #   # #         # #            # #        # #     # #  # #   # #    # #    " << endl;
    cout << "\t\t\t# # # # # #    # # # # #           # #       # # # # #    # # # # # #        # #   # #       # # # # # #        # #            # #        # #     # #  # #    # #   # #   " << endl;
    cout << "\t\t\t# #      # #   # #                    # #    # #          # #      # #        # # # #       # # # # # # #       # #            # #        # #     # #  # #     # #  # #    " << endl;
    cout << "\t\t\t# #      # #   # # # # # #    # # # # # # #  # # # # # #  # #      # #         # # #       # #         # #      # #       # # # # # # #   # # # # # #  # #      # # # #    " << endl;
    cout << "\t\t\t###      ###   # # # # # #    ## # # # # #   # # # # # #  # #      # #          # #       # #           # #     # #       # # # # # # #   # # # # # #  # #        # # #      " << endl;

    cout << "\n\t\t\t\t  LOGIN IN AS";
    cout << "\n\n\t\t\t\t   1.Costumer";
    cout << "\n\t\t\t\t   2.Admin";
    cout << "\n\t\t\t\t   3.Exit";
    cout << "\n\t\t\t\t  --------------------";
    cout << "\n\t\t\t\t  choose Option[1/2/3]";
    cout << "\n\t\t\t\t  --------------------" << endl;
    cout << "\nEnter your choice: ";
    cin >> who;

    return who;
}

void addRoom()
{
    system("cls");
    fstream roomfile;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------Add Room-------------------------------------------------" << endl;
    cout << "\n\t\t\t\t Enter Room Floor: ";
    cin >> rooms.floor;
    cout << "\t\t\t\t Enter Room Number: ";
    cin >> rooms.roomNumber;
    cout << "\t\t\t\t Enter Room Unique Id: ";
    cin >> rooms.roomId;
    cout << "\t\t\t\t Enter Room Rate: ";
    cin >> rooms.rate;
    cout << "\t\t\t\t Enter Room Status: ";
    cin >> rooms.status;

    roomfile.open("roomfile.txt", ios::app | ios::out);

    if (roomfile.fail())
    {
        cout << "\n\t\t\t\tError..File is not Found!" << endl;
    }

    roomfile << " " << rooms.floor << " " << rooms.roomNumber << " " << rooms.roomId << " " << rooms.rate << " " << rooms.status << endl;
    roomfile.close();
}
void displayRoom(char how2_display)
{
    system("cls");
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "----------------------------------------All Room List---------------------------------------------" << endl;
    fstream roomfile;
    string status;
    bool condition= false;
    roomfile.open("roomfile.txt", ios::in);
    if (roomfile.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening the file";
        exit(0);
    }
    switch(how2_display){
    case 'A':condition=true;
        //display ALL room
        break;
     case 'N':status="notreserved";
         //display NOTRESERVED room
        break;
     case 'R':status="reserved";
         //display RESERVED room
        break;
     default:
        cout<<"Error in display function"<<endl;
        break;
    }
    roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
    while (!roomfile.eof())
    {
        if((status==rooms.status)||condition){
        cout << "\n\t\t\t\t\tRoom Floor: " << rooms.floor << endl;
        cout << "\t\t\t\t\tRoom Number: " << rooms.roomNumber << endl;
        cout << "\t\t\t\t\tID: " << rooms.roomId << endl;
        cout << "\t\t\t\t\tRoom Rate: " << rooms.rate << endl;
        cout << "\t\t\t\t\tRoom Status: " << rooms.status << endl;
        }
        roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
    }
    roomfile.close();
}
void searchRoom()
{
    system("cls");
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------Search Room-----------------------------------------------" << endl;
    char searchId[20], searchroomNumber[20];
    float searchroomRate;
    int searchFloor;
    int opp;
    bool check_room = false;
    fstream roomfile;
    cout << "\n\t\t\t\t  1.Search by Id";
    cout << "\n\t\t\t\t  2.Search by Room Number";
    cout << "\n\t\t\t\t  3.Search by Foor";
    cout << "\n\t\t\t\t  4.Search by Rate";
    cout << "\n\n\t\t\t\tEnter Your option: ";
    cin >> opp;
    switch (opp)
    {
    case 1:
    {
        system("cls");
        cout << "---------------------------------------------------------------------------------------------------" << endl;
        cout << "-----------------------------------------Search By Id----------------------------------------------" << endl;
        cout << "\n\n\t\t\t Enter Room Id: ";
        cin >> searchId;

        roomfile.open("roomfile.txt", ios::in);
        if (roomfile.fail())
        {
            cout << "\n\t\t\t\t ERROR while opening the file";
            exit(0);
        }
        roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
        while (!roomfile.eof())
        {

            if (strcmp(rooms.roomId, searchId) == 0)
            {
                cout << "\n\t\t\t\t\tRoom Floor: " << rooms.floor << endl;
                cout << "\t\t\t\t\tRoom Number: " << rooms.roomNumber << endl;
                cout << "\t\t\t\t\tID: " << rooms.roomId << endl;
                cout << "\t\t\t\t\tRoom Rate: " << rooms.rate << endl;
                cout << "\t\t\t\t\tRoom Status: " << rooms.status << endl;
                check_room = true;
            }
            roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
        }
        if (!check_room)
        {
            cout << "\n\t\t\t\t\t There is no such Room " << endl;
        }
        roomfile.close();
        cout << endl;
        break;
    }
    case 2:
    {
        system("cls");
        cout << "---------------------------------------------------------------------------------------------------" << endl;
        cout << "-----------------------------------------Search By Room Number----------------------------------------------" << endl;
        cout << "\n\n Enter Room Id: ";
        cin >> searchroomNumber;
        roomfile.open("roomfile.txt", ios::in);
        if (roomfile.fail())
        {
            cout << "\n\t\t\t\t ERROR while opening the file";
            exit(0);
        }
        roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
        while (!roomfile.eof())
        {
            if (strcmp(rooms.roomNumber, searchroomNumber) == 0)
            {
                cout << "\n\t\t\t\t\tRoom Floor: " << rooms.floor << endl;
                cout << "\t\t\t\t\tRoom Number: " << rooms.roomNumber << endl;
                cout << "\t\t\t\t\tID: " << rooms.roomId << endl;
                cout << "\t\t\t\t\tRoom Rate: " << rooms.rate << endl;
                cout << "\t\t\t\t\tRoom Status: " << rooms.status << endl;
                check_room = true;
            }
            roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
        }
        if (!check_room)
            cout << "\n\t\t\t\t\t There is no such Room " << endl;
        roomfile.close();
        cout << endl;

        break;
    }
    case 3:
    {
        system("cls");
        cout << "------------------------------------------------------------------------------------------------------" << endl;
        cout << "-----------------------------------------Search By Floor----------------------------------------------" << endl;
        cout << "\n\n Enter Floor: ";
        cin >> searchFloor;
        roomfile.open("roomfile.txt", ios::in);
        if (roomfile.fail())
        {
            cout << "\n\t\t\t\t ERROR while opening the file";
            exit(0);
        }
        cout << "\n\t\t\t\t   Rooms on Floor " << searchFloor << ".\n\n";
        roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
        while (!roomfile.eof())
        {
            if (rooms.floor == searchFloor)
            {
                cout << "\n\t\t\t\t\tRoom Floor: " << rooms.floor << endl;
                cout << "\t\t\t\t\tRoom Number: " << rooms.roomNumber << endl;
                cout << "\t\t\t\t\tID: " << rooms.roomId << endl;
                cout << "\t\t\t\t\tRoom Rate: " << rooms.rate << endl;
                cout << "\t\t\t\t\tRoom Status: " << rooms.status << endl;
                check_room = true;
            }
            roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
        }
        if (!check_room)
            cout << "\n\t\t\t\t   There is no such Room Floor" << endl;
        roomfile.close();
        cout << endl;
        break;
    }
    case 4:
    {
        system("cls");
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
        cout << "-----------------------------------------Search By Room Rate----------------------------------------------" << endl;
        cout << "\n\n Enter Room Rate you want: ";
        cin >> searchroomRate;
        roomfile.open("roomfile.txt", ios::in);
        if (roomfile.fail())
        {
            cout << "\n\t\t\t\t ERROR while opening the file";
            exit(0);
        }
        cout << "\n\t\t\t\tRooms With room rate < or = " << searchroomRate << ".\n\n";
        roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
        while (!roomfile.eof())
        {
            if (rooms.rate >= searchroomRate)
            {
                cout << "\n\t\t\t\t\tRoom Floor: " << rooms.floor << endl;
                cout << "\t\t\t\t\tRoom Number: " << rooms.roomNumber << endl;
                cout << "\t\t\t\t\tID: " << rooms.roomId << endl;
                cout << "\t\t\t\t\tRoom Rate: " << rooms.rate << endl;
                cout << "\t\t\t\t\tRoom Status: " << rooms.status << endl;
                check_room = true;
            }
            roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
        }
        if (!check_room)
            cout << "\n\t\t\t\t\t There is no such Room" << endl;
        roomfile.close();
        cout << endl;
        break;
    }
    default:
        cout << "Invalid input" << endl;
    }
}

void editRoom()
{
    system("cls");
    fstream roomfile, roomfile1;
    int oppchange;
    char id[20];
    string status;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------Edit Room----------------------------------------------" << endl;
    roomfile.open("roomfile.txt", ios::in);
    if (roomfile.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening the file";
        exit(0);
    }
    if (!roomfile)
    {
        cout << "\n\t\t\t\t No Data Present" << endl;
        exit(0);
    }
    else
    {
        cout << "\n\n Enter Id of The Room You Want to Edit: ";
        cin >> id;
        cout << "\nWhat Propriety of Room Id " << id << " Do you want to change" << endl;
        cout << "\n\t\t\t\t\t1.Room Floor" << endl;
        cout << "\t\t\t\t\t2.Room Number" << endl;
        cout << "\t\t\t\t\t3.Room ID" << endl;
        cout << "\t\t\t\t\t4.Room Rate" << endl;
        cout << "\t\t\t\t\t5.Room Status" << endl;
        cout << "\nEnter your choice: ";
        cin >> oppchange;
        roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
        roomfile1.open("roomfilecp.txt", ios::app | ios::out);
        if (roomfile1.fail())
        {
            cout << "\n\t\t\t\t ERROR while opening the file";
            exit(0);
        }
        while (!roomfile.eof())
        {
            if (strcmp(id, rooms.roomId) == 0)
            {
                switch (oppchange)
                {
                case 1:
                    cout << "\n Enter The New Room Floor: ";
                    cin >> rooms.floor;
                    break;
                case 2:
                    cout << "\n Enter The New Room Number: ";
                    cin >> rooms.roomNumber;
                    break;
                case 3:
                    cout << "\n Enter The New Room ID: ";
                    cin >> rooms.roomId;
                    break;
                case 4:
                    cout << "\n Enter The New Room Rate: ";
                    cin >> rooms.rate;
                    break;
                case 5:
                    cout << "\n Enter The New Room Status: ";
                    cin >> rooms.status;

                    break;
                default:
                    cout << "\n\n\t\t\t\t IVALID INPUT";
                    break;
                }
                cout << "\n\t\t\t\t\tRoom Floor: " << rooms.floor << endl;
                cout << "\t\t\t\t\tRoom Number: " << rooms.roomNumber << endl;
                cout << "\t\t\t\t\tID: " << rooms.roomId << endl;
                cout << "\t\t\t\t\tRoom Rate: " << rooms.rate << endl;
                cout << "\t\t\t\t\tRoom Status: " << rooms.status << endl;
            }
            roomfile1 << " " << rooms.floor << " " << rooms.roomNumber << " " << rooms.roomId << " " << rooms.rate << " " << rooms.status << endl;
            roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
        }
        roomfile.close();
        roomfile1.close();
    }
    remove("roomfile.txt");
    rename("roomfilecp.txt", "roomfile.txt");
}
void reserveRoom()
{
    system("cls");
    char paynow;
    bool condition = false;
    fstream customer1;
    fstream roomfile, roomfile2;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------Reserve Room----------------------------------------------" << endl;
    cout << "\n Enter Your Full Name: ";
    cin >> customers.fname >> customers.mname;
    cout << "\n Enter Your Phone Number: ";
    cin >> customers.phoneNumber;
    cout << "\n Enter Your Email: ";
    cin >> customers.email;
    cout << "\n Enter Your Password: ";
    cin >> customers.password;
trynew:
    cout << "\n Enter Id of The Room You Want: ";
    cin >> customers.roomIdc;
    roomfile.open("roomfile.txt", ios::in);
    if (roomfile.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening the file in reserve function";
        exit(0);
    }
    roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
    while (!roomfile.eof())
    {
        if (strcmp(customers.roomIdc, rooms.roomId) == 0)
        {
            if (rooms.status == "reserved" || rooms.status == "hold"||rooms.status=="confirm")
            {
                cout << "\n The room Reserved Please choice Another Room" << endl;
                goto trynew;
            }
        }
        roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
    }
    roomfile.close();
    cout<<"\n Payment For Room is 450 in day."<<endl;
    cout << "\n Do you want to pay Now[y/n]: ";
    cin >> paynow;
    if (paynow == 'y' || paynow == 'Y')
    {
        condition = payment(false);
    }
    else
    {
        cout << "\nYou haven 30 minute to finish the payment" << endl
             << endl;
    }

    customer1.open("customerfile.txt", ios::app | ios::out);
    if (customer1.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening the file in reserve function";
        exit(0);
    }

    if (condition)
    {
        cout << "\n\n\t\t\t\tEnter phone number you payed with: ";
        cin >> customers.payphone;
        cout << "\n\n\t\t\t\tEnter transaction number: ";
        cin >> customers.transaction;
        customer1 << " " << customers.fname << " " << customers.mname << " " << customers.phoneNumber << " " << customers.email << " " << customers.roomIdc << " " << customers.password << " "
                  << "confirm"
                  << " " << customers.payphone << " " << customers.transaction << endl;
    }
    else
        customer1 << " " << customers.fname << " " << customers.mname << " " << customers.phoneNumber << " " << customers.email << " " << customers.roomIdc << " " << customers.password << " "
                  << "hold"
                  << " " << '0' << " " << 0 << endl;
    customer1.close();

    roomfile.open("roomfile.txt", ios::in);
    roomfile2.open("roomfilecp.txt", ios::app | ios::out);
    if (roomfile.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening the roomfile file in reserve function";
        exit(0);
    }
    if (roomfile2.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening the roomfile2 file in reserve function";
        exit(0);
    }
    roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
    while (!roomfile.eof())
    {
        if (strcmp(customers.roomIdc, rooms.roomId) == 0)
        {
            if (condition)
                rooms.status = "confirm";
            else
                rooms.status = "hold";
            cout << "\n\t\t\t Process is Successfully Completed" << endl
                 << endl;
            cout << "\n\t\t\t\t\tRoom Floor: " << rooms.floor << endl;
            cout << "\t\t\t\t\tRoom Number: " << rooms.roomNumber << endl;
            cout << "\t\t\t\t\tID: " << rooms.roomId << endl;
            cout << "\t\t\t\t\tRoom Rate: " << rooms.rate << endl;
            cout << "\t\t\t\t\tRoom Status: " << rooms.status << endl;
        }
        roomfile2 << " " << rooms.floor << " " << rooms.roomNumber << " " << rooms.roomId << " " << rooms.rate << " " << rooms.status << endl;

        roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
    }
    roomfile.close();
    roomfile2.close();
    remove("roomfile.txt");
    rename("roomfilecp.txt", "roomfile.txt");
}

void cancel(char* password,string f_name,string l_name)
{
    system("cls");
trycancel:
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------Cancel Reservation---------------------------------------" << endl;
    cout<<"-----------------"<<password;
    char roomIdcc[20];
    fstream roomfile1, roomfile2, customer1, customer2;
    customer1.open("customerfile.txt", ios::in);
    customer2.open("customerfilecp.txt", ios::app | ios::out);

    if (customer1.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening the file in cancel fun";
        exit(0);
    }
    if (customer2.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening the file in cancel fun";
        exit(0);
    }
if(f_name=="0"&&l_name=="0"){
    cout << "\n\n\n\t\t\tEnter your name: ";
    cin >> f_name >> l_name;
    cout << "\n\t\t\tEnter Your Password: ";
    cin >> password;
    customer1 >> customers.fname >> customers.mname >> customers.phoneNumber >> customers.email >> customers.roomIdc >> customers.password >> customers.status >> customers.payphone >> customers.transaction;
    while (!customer1.eof())
    {
        if (customers.fname != f_name && customers.fname != l_name&& strcmp(password,customers.password)!=0)
        {
            customer2 << " " << customers.fname << " " << customers.mname << " " << customers.phoneNumber << " " << customers.email << " " << customers.roomIdc << " " << customers.password << " " << customers.status << " " << customers.payphone << " " << customers.transaction << endl;
        }
        else
            strcpy(roomIdcc, customers.roomIdc);
        customer1 >> customers.fname >> customers.mname >> customers.phoneNumber >> customers.email >> customers.roomIdc >> customers.password >> customers.status >> customers.payphone >> customers.transaction;
    }

}
else{
    while (!customer1.eof())
    {
        if (customers.fname != f_name && customers.fname != l_name)
        {
            customer2 << " " << customers.fname << " " << customers.mname << " " << customers.phoneNumber << " " << customers.email << " " << customers.roomIdc << " " << customers.password << " " << customers.status << " " << customers.payphone << " " << customers.transaction << endl;
        }
        else
            strcpy(roomIdcc, customers.roomIdc);
        customer1 >> customers.fname >> customers.mname >> customers.phoneNumber >> customers.email >> customers.roomIdc >> customers.password >> customers.status >> customers.payphone >> customers.transaction;
    }

}
    customer1.close();
    customer2.close();
    remove("customerfile.txt");
    rename("customerfilecp.txt", "customerfile.txt");
    roomfile1.open("roomfile.txt", ios::in);
    roomfile2.open("roomfilecp.txt", ios::app | ios::out);

    if (roomfile1.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening the file in cancel";
        exit(0);
    }
    if (roomfile2.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening the file in cancel";
        exit(0);
    }

    roomfile1 >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
    while (!roomfile1.eof())
    {

        if ((strcmp(rooms.roomId, roomIdcc) == 0))
        {
            if(rooms.status!="notreserved"){
            cout<<"\n\n\n\t\t Successfully Canceled"<<endl;
            cout<<"\n\n\n\t\t We will check about the payment and send your payment back in 30 minute"<<endl;
            }
            rooms.status = "notreserved";
        }
        roomfile2 << " " << rooms.floor << " " << rooms.roomNumber << " " << rooms.roomId << " " << rooms.rate << " " << rooms.status << endl;
        roomfile1 >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
    }
    roomfile1.close();
    roomfile2.close();

    remove("roomfile.txt");
    rename("roomfilecp.txt", "roomfile.txt");
}

void displayCustomer(char which)
{

    system("cls");
    string status;
    bool condition=false;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------Customers-------------------------------------------" << endl;
    int numberofcustomer = 1;
    fstream customerfile;
    switch(which){
    case 'A':condition=true;
    break;
    case 'C':
        status="confirm";
        break;
    case 'H':
        status="hold";
        break;
    }


    customerfile.open("customerfile.txt", ios::in);
    if (customerfile.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening the file display customers";
        exit(0);
    }
    customerfile >> customers.fname >> customers.mname >> customers.phoneNumber >> customers.email >> customers.roomIdc >> customers.password >> customers.status >> customers.payphone >> customers.transaction;
    while (!customerfile.eof())
    {   if(status==customers.status ||condition){
        cout << "\n\t\t\t\t Customer " << numberofcustomer++ << endl;
        cout << "\n\t\t\t Name: " << customers.fname << " " << customers.mname;
        cout << "\n\t\t\t Email: " << customers.email;
        cout << "\n\t\t\t Phone Number: " << customers.phoneNumber;
        cout << "\n\t\t\t Reserved Room ID: " << customers.roomIdc;
        cout << "\n\t\t\t Status: " << customers.status;
        if(customers.status!="hold"){
             cout << "\n\t\t\t Transaction No: " << customers.transaction;
             cout << "\n\t\t\t phone 4 payment: " << customers.payphone;
        }}
        cout<<endl;
        customerfile >> customers.fname >> customers.mname >> customers.phoneNumber >> customers.email >> customers.roomIdc >> customers.password >> customers.status >> customers.payphone >> customers.transaction;
    }
    customerfile.close();
}

bool payment(bool how)
{
    int user_choice, transaction;
    char password[20], payphone[20],idroom[20];
    string name_1, name_2;
    bool verify = false;
    fstream customer1, customer2,roomfile,roomfile2;

    system("cls");
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------Payment---------------------------------------------" << endl;

    if (how)
    {
        cout << "\n\n\n\t\t\t\t Enter your name: ";
        cin >> name_1 >> name_2;
        cout << "\n\n\n\t\t\t\t Enter your password: ";
        cin >> password;
        customer1.open("customerfile.txt", ios::in);
        if (customer1.fail())
        {
            cout << "\n\t\t\t\t ERROR while opening the file in payment fun";
            exit(0);
        }
        customer1 >> customers.fname >> customers.mname >> customers.phoneNumber >> customers.email >> customers.roomIdc >> customers.password >> customers.status >> customers.payphone >> customers.transaction;
        while (!customer1.eof())
        {
            if (customers.fname == name_1 && customers.fname == name_1 && (strcmp(password, customers.password) == 0))
            {
                verify = true;
            }
            customer1 >> customers.fname >> customers.mname >> customers.phoneNumber >> customers.email >> customers.roomIdc >> customers.password >> customers.status >> customers.payphone >> customers.transaction;
        }
        customer1.close();
    }
    cout<<"\n\n\n We receive payment through Tele birr at the moment."<<endl;
    cout << " So, Transfer the required amount money to +251-987-4464 (Tha is \"Simera\" name which is the service provider)" << endl;
    if (how && verify){
            cout << "\n\n\t\t\t\tEnter phone number you payed with: ";
            cin >> payphone;
            cout << "\n\n\t\t\t\tEnter transaction number: ";
            cin >> transaction;
            cout<<"\n\n\n You have successfully completed the payment system."<<endl;
            cout << " Now our Employee verify the Payment process succession and send you confirmation message with in (30 minute )";


        customer1.open("customerfile.txt", ios::in);
        customer2.open("customerfilecp.txt", ios::app | ios::out);

        if (customer1.fail())
        {
            cout << "\n\t\t\t\t ERROR while opening the customer file 1 in payment fun";
            exit(0);
        }
        if (customer2.fail())
        {
            cout << "\n\t\t\t\t ERROR while opening customer file 2 the file in payment fun";
            exit(0);
        }
        customer1 >> customers.fname >> customers.mname >> customers.phoneNumber >> customers.email >> customers.roomIdc >> customers.password >> customers.status >> customers.payphone >> customers.transaction;
        while (!customer1.eof())
        {
            if (customers.fname != name_1 && customers.fname != name_2 && (strcmp(password, customers.password) != 0))
            {
                customer2 << " " << customers.fname << " " << customers.mname << " " << customers.phoneNumber << " " << customers.email << " " << customers.roomIdc << " " << customers.password << " " << customers.status << " " << customers.payphone << " " << customers.transaction << endl;
            }
            else
            {   strcpy(idroom,customers.roomIdc);
                customer2 << " " << customers.fname << " " << customers.mname << " " << customers.phoneNumber << " " << customers.email << " " << customers.roomIdc << " " << customers.password << " "
                          << "confirm"<< " " << payphone << " " << transaction << endl;
            }

            customer1 >> customers.fname >> customers.mname >> customers.phoneNumber >> customers.email >> customers.roomIdc >> customers.password >> customers.status >> customers.payphone >> customers.transaction;
        }

        customer1.close();
        customer2.close();
        remove("customerfile.txt");
        rename("customerfilecp.txt", "customerfile.txt");

            roomfile.open("roomfile.txt", ios::in);
        roomfile2.open("roomfilecp.txt", ios::app | ios::out);
    if (roomfile.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening the roomfile file in reserve function";
        exit(0);
    }
    if (roomfile2.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening the roomfile2 file in reserve function";
        exit(0);
    }
    roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
    while (!roomfile.eof())
    {
        if (strcmp(customers.roomIdc, rooms.roomId) == 0)
        {
            if (strcmp(idroom,rooms.roomId )==0)rooms.status = "confirm";

            cout << "\n\t\t\t Process is Successfully Completed" << endl
                 << endl;
        }
        roomfile2 << " " << rooms.floor << " " << rooms.roomNumber << " " << rooms.roomId << " " << rooms.rate << " " << rooms.status << endl;
        roomfile >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
    }
    roomfile.close();
    roomfile2.close();
    remove("roomfile.txt");
    rename("roomfilecp.txt", "roomfile.txt");
    }
    return true;
}


void verify_payment(){
    system("cls");
    bool for_room=false;
    int dowhat;
     cout << "---------------------------------------------------------------------------------------------------" << endl;
     cout << "---------------------------------------Customer Control-------------------------------------------" << endl;
     cout<<endl<<endl;
     cout<<"\n\n\n\t\t\t1.Verify Customer"<<endl;
     cout<<"\t\t\t2.Remove Customer"<<endl;
     cout<<"\t\t\t  Who haven't payed"<<endl;
     cout<<"\n\nChoose what to do: ";
     cin>>dowhat;
        string name_1,name_2;
        char room_id[20];
        fstream customerfile1,customerfile2,roomfile1,roomfile2;
        customerfile1.open("customerfile.txt", ios::in);
        customerfile2.open("customerfilecp.txt", ios::out |ios::app);

        if(customerfile1.fail()){
            cout<<"Error to open customer file1 in verify payment function"<<endl;
            exit(1);
            }
        if(customerfile2.fail()){
            cout<<"Error to open customer file1 in verify payment function"<<endl;
            exit(1);
        }
        cout<<"Enter name of the customer: ";
        cin>>name_1>>name_2;
        customerfile1 >> customers.fname >> customers.mname >> customers.phoneNumber >> customers.email >> customers.roomIdc >> customers.password >> customers.status >> customers.payphone >> customers.transaction;
        if (dowhat==1){
        while (!customerfile1.eof())
        {

           if(name_1==customers.fname&&name_2==customers.mname&&customers.status=="confirm"){
            for_room=true;
            strcpy(room_id,customers.roomIdc);
                cout<<"\n\n\t\t Current state"<<endl;
                customers.status="verified";
            cout << "\n\t\t\t Name: " << customers.fname << " " << customers.mname;
            cout << "\n\t\t\t Phone Number: " << customers.phoneNumber;
            cout << "\n\t\t\t Reserved Room ID: " << customers.roomIdc;
            cout << "\n\t\t\t Status: " << customers.status;
            cout << "\n\t\t\t Transaction No: " << customers.transaction;
            cout << "\n\t\t\t phone 4 payment: " << customers.payphone;
        }

        customerfile2 << " " << customers.fname << " " << customers.mname << " " << customers.phoneNumber << " " << customers.email << " " << customers.roomIdc << " " << customers.password << " " << customers.status << " " << customers.payphone << " " << customers.transaction << endl;
        customerfile1 >> customers.fname >> customers.mname >> customers.phoneNumber >> customers.email >> customers.roomIdc >> customers.password >> customers.status >> customers.payphone >> customers.transaction;
        }
        }
       else if(dowhat==2&&name_1==customers.fname&&name_2==customers.mname){
            cout<<"\n\n\Do what\n\n";
                if(customers.status=="hold"){
                    cout<<"\n\n\Do Cancel\n\n";
                        cancel(customers.password,name_1,name_2);}
                else cout<<"\n\n\n\\t\t\tCustomer status is not HOLD"<<endl;
                }
        customerfile1.close();
        customerfile2.close();
        remove("customerfile.txt");
        rename("customerfilecp.txt","customerfile.txt");

   if(for_room){
    roomfile1.open("roomfile.txt", ios::in);
    roomfile2.open("roomfilecp.txt", ios::app | ios::out);

    if (roomfile1.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening room file 1 in verify payment function";
        exit(1);
    }
    if (roomfile2.fail())
    {
        cout << "\n\t\t\t\t ERROR while opening room file 2 in verify payment function";
    }

    roomfile1 >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
    while (!roomfile1.eof())
    {

        if ((strcmp(rooms.roomId, room_id) == 0))
        {
            rooms.status = "reserved";
        }
        roomfile2 << " " << rooms.floor << " " << rooms.roomNumber << " " << rooms.roomId << " " << rooms.rate << " " << rooms.status << endl;
        roomfile1 >> rooms.floor >> rooms.roomNumber >> rooms.roomId >> rooms.rate >> rooms.status;
    }
    roomfile1.close();
    roomfile2.close();

    remove("roomfile.txt");
    rename("roomfilecp.txt", "roomfile.txt");
   }
}
