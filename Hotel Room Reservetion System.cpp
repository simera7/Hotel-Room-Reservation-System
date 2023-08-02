#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct room{
    int floor;
    char roomNumber[20];
    char roomId[20];
    float rate;
    string status;
    char customerId[20];

}rooms;

struct customer{
    string fname,mname,lname;

    char email[50];
    int phoneNumber;
    char customerId[20];
    char roomIdc[20];
    char password[20];

}customers;
char gomain;
//ADMIN
char menu();
void addRoom();
void displayRoom();
void displayavailableR();
void displayreservedR();
void searchRoom();
void editRoom();

//CUSTMER
char reserveRoom();
void changestatus(char);
void cancel();
void displayCustomer();


int main(){
    char holdwho;
    holdwho=menu();
    switch(holdwho){
        case '1':
            customermenu:
            system("cls");
            char customerOption;

            cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
            cout<<"--------------------------------------MENU FOR CUSTEMER----------------------------------------------"<<endl;
            cout<<"\n\t\t\t\t  1.Display Available Room";
            cout<<"\n\t\t\t\t  2.Reserve Room";
            cout<<"\n\t\t\t\t  3.Cancel Reservation";
            cout<<"\n\t\t\t\t  4.Search For Room";
            cout<<"\n\t\t\t\t  ----------------------";
            cout<<"\n\t\t\t\t  choose Option[1/2/3/4]";
            cout<<"\n\t\t\t\t  ----------------------";
            cout<<"\nEnter your choice: ";
            cin>>customerOption;
            switch(customerOption){
                case '1':displayavailableR();
                cout<<"\n Do You Want To Return To The Customer Menu: ";
                cin>>gomain;
                if(gomain=='y'||gomain=='Y'){
                    goto customermenu;
                }
                    break;
                case '2':{
                    char holdr[100];
                    reserveRoom();
                    cout<<"\n Do You Want To Return To The Customer Menu: ";
                    cin>>gomain;
                    if(gomain=='y'||gomain=='Y'){
                        goto customermenu;
                }
                //changestatus(holdr);
                    break;}
                case '3':cancel();
                        cout<<"\n Do You Want To Return To The Customer Menu: ";
                        cin>>gomain;
                        if(gomain=='y'||gomain=='Y'){
                            goto customermenu;
                        }
                    break;
                case '4':
                    searchRoom();
                    cout<<"\n Do You Want To Return To The Customer Menu: ";
                    cin>>gomain;
                    if(gomain=='y'||gomain=='Y'){
                        goto customermenu;
                    }
                    break;
                default:
                cout<<"\n\t\t\t\t  Invalid Input";

            }
        break;
        case '2':{

                string password="admin";
                string passcode;
                trypass:
                cout<<"\nEnter Your Admin Password: ";
                cin>>passcode;

                if(passcode=="1"){
                    system("cls");
                    cout<<"\n\t\t\t\t  Successfully Exited";
                    cout<<"\n";
                    exit(0);
                }

               else if(password!=passcode){
                    system("cls");
                    cout<<"\n\t\t\t\t  WRONG PASSWORD! pleasw try to  enter the correct password"<<endl;
                    cout<<"\t\t\t\t  If you forget the password communicate with the ICT team."<<endl;
                    cout<<"\t\t\t\t  To exit press [1] "<<endl;
                    goto trypass;
                }
                else if(password==passcode){
                    adminmenu:
                    int adminOption;
                    system("cls");
                    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
                    cout<<"--------------------------------------MENU FOR ADMIN-----------------------------------------------"<<endl;

                    cout<<"\n\t\t\t\t  1.Add Room";
                    cout<<"\n\t\t\t\t  2.Display All Room";
                    cout<<"\n\t\t\t\t  3.Display Available Room";
                    cout<<"\n\t\t\t\t  4.Display Reserved ROOM";
                    cout<<"\n\t\t\t\t  5.Display customer";
                    cout<<"\n\t\t\t\t  6.Edit Room";
                    cout<<"\n\t\t\t\t  7.Search For Room";
                    cout<<"\n\t\t\t\t   --------------------------";
                    cout<<"\n\t\t\t\t   choose Option[1/2/3/4/5/6]";
                    cout<<"\n\t\t\t\t   --------------------------"<<endl;
                    cout<<"\nEnter your choice: ";
                    cin>>adminOption;

                    switch(adminOption){
                        case 1:
                            char x;
                            do{
                                addRoom();
                                cout<<"\n\n\t\t\t\t Add Another Room (Y,N): ";
                                cin>>x;
                            }
                            while(x=='Y' || x=='y');
                           //**** cout<<"\n\t\t\t\t  You Have Successfully Added!"<<endl;
                            goto adminmenu;
                            break;
                        case 2:
                            displayRoom();
                            cout<<"\n Do You Want To Return To The Admin Menu: ";
                            cin>>gomain;
                            if(gomain=='y'||gomain=='Y'){
                                goto adminmenu;
                            }
                        break;
                        case 3:
                            displayavailableR();
                            break;
                        case 4:
                            displayreservedR();
                            cout<<"\n Do You Want To Return To The Admin Menu: ";
                            cin>>gomain;
                            if(gomain=='y'||gomain=='Y'){
                                goto adminmenu;
                            }
                            break;
                        case 5: displayCustomer();
                            cout<<"\n Do You Want To Return To The Admin Menu: ";
                            cin>>gomain;
                            if(gomain=='y'||gomain=='Y'){
                                goto adminmenu;
                            }
                            break;
                        case 6:
                            editRoom();
                            cout<<"\n Do You Want To Return To The Admin Menu: ";
                            cin>>gomain;
                            if(gomain=='y'||gomain=='Y'){
                                goto adminmenu;
                            }
                            break;
                        case 7:
                            searchRoom();
                            cout<<"\n Do You Want To Return To The Admin Menu: ";
                            cin>>gomain;
                            if(gomain=='y'||gomain=='Y'){
                                goto adminmenu;
                            }
                            break;
                        default:
                            cout<<"\n Invalid choice... please try again ...."<<endl;
                        break;
                    }
                }
            break;
        }
        case '3':
            cout<<"\n\t\t\t\t  Successfully Exited";
            cout<<"\n";
           break;
        default:
            cout<<"\n Invalid choice... please try again ...."<<endl;
            break;


    }

    return 0;
}

char menu(){
    char who;
    mainmenu:
    system("cls");

cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"\t\t\t\t# #     # #   # # # # # #   # # # # # # #   # # # # # #   # #"<<endl;
cout<<"\t\t\t\t# #     # #   # # # # # #   # # # # # # #   # # # # # #   # #"<<endl;
cout<<"\t\t\t\t# #     # #   # #     # #        # #        # #           # #"<<endl;
cout<<"\t\t\t\t# # # # # #   # #     # #        # #        # # # # #     # #"<<endl;
cout<<"\t\t\t\t# # # # # #   # #     # #        # #        # # # # #     # #"<<endl;
cout<<"\t\t\t\t# #     # #   # #     # #        # #        # #           # #"<<endl;
cout<<"\t\t\t\t# #     # #   # # # # # #        # #        # # # # # #   # # # # # #"<<endl;
cout<<"\t\t\t\t# #     # #   # # # # # #        # #        # # # # # #   # # # # # #"<<endl;
cout<<endl;
cout<<endl;
cout<<"\t\t\t# # # # # #    # # # # # #    # # # # # ##   # # # # # #  # # # # # #    # #           # #       # #       # # # # # # #  # # # # # # #   # # # # # #  # # #        # #  "<<endl;
cout<<"\t\t\t# #      # #   # # # # # #   # # # # # # #   # # # # # #  # #      # #    # #         # #       # # #      # # # # # # #  # # # # # # #   # # # # # #  # # # #      # #    "<<endl;
cout<<"\t\t\t# #      # #   # #            # #            # #          # #      # #     # #       # #       # # # #          # #            # #        # #     # #  # #  # #     # #    "<<endl;
cout<<"\t\t\t# # # # # #    # # # # #        # #          # # # # #    # # # # # #       # #     # #       # #   # #         # #            # #        # #     # #  # #   # #    # #    "  <<endl;
cout<<"\t\t\t# # # # # #    # # # # #           # #       # # # # #    # # # # # #        # #   # #       # # # # # #        # #            # #        # #     # #  # #    # #   # #   "<<endl;
cout<<"\t\t\t# #      # #   # #                    # #    # #          # #      # #        # # # #       # # # # # # #       # #            # #        # #     # #  # #     # #  # #    "   <<endl;
cout<<"\t\t\t# #      # #   # # # # # #    # # # # # # #  # # # # # #  # #      # #         # # #       # #         # #      # #       # # # # # # #   # # # # # #  # #      # # # #    "<<endl;
cout<<"\t\t\t###      ###   # # # # # #    ## # # # # #   # # # # # #  # #      # #          # #       # #           # #     # #       # # # # # # #   # # # # # #  # #        # # #      "<< endl;


    cout<<"\n\t\t\t\t  LOGIN IN AS";
    cout<<"\n\n\t\t\t\t   1.Costumer";
    cout<<"\n\t\t\t\t   2.Admin";
    cout<<"\n\t\t\t\t   3.Exit";
    cout<<"\n\t\t\t\t  --------------------";
    cout<<"\n\t\t\t\t  choose Option[1/2/3]";
    cout<<"\n\t\t\t\t  --------------------"<<endl;
    cout<<"\nEnter your choice: ";
    cin>>who;

    return who;
}


void addRoom(){
    /*
    int floor;
    char roomNumber[20];
    char roomId[20];
    int roomRate;
    string status;*/
    system("cls");
    fstream roomfile;
    cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"--------------------------------------------Add Room-------------------------------------------------"<<endl;
    cout<<"\n\t\t\t\t Enter Room Floor: ";
    cin>>rooms.floor;
    cout<<"\t\t\t\t Enter Room Number: ";
    cin>>rooms.roomNumber;
    cout<<"\t\t\t\t Enter Room Unique Id: ";
    cin>>rooms.roomId;
    cout<<"\t\t\t\t Enter Room Rate: ";
    cin>>rooms.rate;
    cout<<"\t\t\t\t Enter Room Status: ";
    cin>>rooms.status;

    roomfile.open("roomfile.txt",ios::app | ios::out);

    if(roomfile.fail()){
        cout<<"\n\t\t\t\tError..File is not Found!"<<endl;
    }

    roomfile<<" "<<rooms.floor<<" "<<rooms.roomNumber<<" "<<rooms.roomId<<" "<<rooms.rate<<" "<<rooms.status<<endl;
    roomfile.close();
}
void displayRoom(){
    system("cls");
     /*
    int floor;
    char roomNumber[20];
    char roomId[20];
    int roomRate;
    string status;*/
    cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------All Room List---------------------------------------------"<<endl;
    fstream roomfile;
    roomfile.open("roomfile.txt",ios::in);
    if(roomfile.fail()){
        cout<<"\n\t\t\t\t ERROR while opening the file";
        exit(0);
    }



    roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;
    while(!roomfile.eof()){

    cout<<"\n\t\t\t\t\tRoom Floor: "<<rooms.floor<<endl;
    cout<<"\t\t\t\t\tRoom Number: "<<rooms.roomNumber<<endl;
    cout<<"\t\t\t\t\tID: "<<rooms.roomId<<endl;
    cout<<"\t\t\t\t\tRoom Rate: "<<rooms.rate<<endl;
    cout<<"\t\t\t\t\tRoom Status: "<<rooms.status<<endl;

    roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;
    }
    roomfile.close();
}

void displayavailableR(){
    system("cls");

    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------Available Room---------------------------------------------"<<endl;
    fstream roomfile;
    roomfile.open("roomfile.txt",ios::in);
    if(roomfile.fail()){
        cout<<"\n\t\t\t\t ERROR while opening the file";
        exit(0);
          }


    roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;
    while(!roomfile.eof()){
        if(rooms.status=="notreserved"){
            cout<<"\n\t\t\t\t\tRoom Floor: "<<rooms.floor<<endl;
            cout<<"\t\t\t\t\tRoom Number: "<<rooms.roomNumber<<endl;
            cout<<"\t\t\t\t\tID: "<<rooms.roomId<<endl;
            cout<<"\t\t\t\t\tRoom Rate: "<<rooms.rate<<endl;
            cout<<"\t\t\t\t\tRoom Status: "<<rooms.status<<endl;
        }

roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;    }
    roomfile.close();
    cout<<endl;
}


void displayreservedR(){
    system("cls");

    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------Reserved Room---------------------------------------------"<<endl;
    fstream roomfile;
    roomfile.open("roomfile.txt",ios::in);
    if(roomfile.fail()){
        cout<<"\n\t\t\t\t ERROR while opening the file";
        exit(0);
    }


    roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;
    while(!roomfile.eof()){
        if(rooms.status=="reserved"){
            cout<<"\n\t\t\t\t\tRoom Floor: "<<rooms.floor<<endl;
            cout<<"\t\t\t\t\tRoom Number: "<<rooms.roomNumber<<endl;
            cout<<"\t\t\t\t\tID: "<<rooms.roomId<<endl;
            cout<<"\t\t\t\t\tRoom Rate: "<<rooms.rate<<endl;
            cout<<"\t\t\t\t\tRoom Status: "<<rooms.status<<endl;
        }

    roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;
    }
    roomfile.close();
    cout<<endl;
}
void searchRoom(){
    system("cls");

    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------Search Room-----------------------------------------------"<<endl;
    char searchId[20],searchroomNumber[20];
    float searchroomRate;
    int searchFloor;
    int opp;
    fstream roomfile;

    cout<<"\n\t\t\t\t  1.Search by Id";
    cout<<"\n\t\t\t\t  2.Search by Room Number";
    cout<<"\n\t\t\t\t  3.Search by Foor";
    cout<<"\n\t\t\t\t  4.Search by Rate";
    cout<<"\n Enter Your option: ";
    cin>>opp;

    switch(opp){
        case 1:{
            bool cond=false;
            system("cls");
            cout<<"---------------------------------------------------------------------------------------------------"<<endl;
            cout<<"-----------------------------------------Search By Id----------------------------------------------"<<endl;
            cout<<"\n\n Enter Room Id: ";
            cin>>searchId;

            roomfile.open("roomfile.txt",ios::in);
            if(roomfile.fail()){
                cout<<"\n\t\t\t\t ERROR while opening the file";
                exit(0);
            }


            roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;
            while(!roomfile.eof()){

                if(strcmp(rooms.roomId,searchId)==0){
                    cout<<strcmp(rooms.roomId,searchId)<<endl;
                    cout<<"\n\t\t\t\t\tRoom Floor: "<<rooms.floor<<endl;
                    cout<<"\t\t\t\t\tRoom Number: "<<rooms.roomNumber<<endl;
                    cout<<"\t\t\t\t\tID: "<<rooms.roomId<<endl;
                    cout<<"\t\t\t\t\tRoom Rate: "<<rooms.rate<<endl;
                    cout<<"\t\t\t\t\tRoom Status: "<<rooms.status<<endl;
                    cond=true;
                }
            roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;
            }
            if(!cond) {cout<<"\n\t\t\t\t\t There is no such Room Id"<<endl;}
        roomfile.close();
        cout<<endl;

        break;
        }
        case 2:{
            system("cls");
            cout<<"---------------------------------------------------------------------------------------------------"<<endl;
            cout<<"-----------------------------------------Search By Room Number----------------------------------------------"<<endl;
            cout<<"\n\n Enter Room Id: ";
            cin>>searchroomNumber;
            bool cond=false;
            roomfile.open("roomfile.txt",ios::in);
            if(roomfile.fail()){
                cout<<"\n\t\t\t\t ERROR while opening the file";
                exit(0);
            }


            roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;
            while(!roomfile.eof()){
                if(strcmp(rooms.roomNumber,searchroomNumber)==0){
                    cout<<"\n\t\t\t\t\tRoom Floor: "<<rooms.floor<<endl;
                    cout<<"\t\t\t\t\tRoom Number: "<<rooms.roomNumber<<endl;
                    cout<<"\t\t\t\t\tID: "<<rooms.roomId<<endl;
                    cout<<"\t\t\t\t\tRoom Rate: "<<rooms.rate<<endl;
                    cout<<"\t\t\t\t\tRoom Status: "<<rooms.status<<endl;
                    cond=true;
                }
                if(!cond) cout<<"\n\t\t\t\t\t There is no such Room Number"<<endl;

            roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;
            }
        if(!cond) cout<<"\n\t\t\t\t\t There is no such Room Number"<<endl;
        roomfile.close();
        cout<<endl;

break;
        }
        case 3:{
            system("cls");
            cout<<"------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"-----------------------------------------Search By Floor----------------------------------------------"<<endl;
            cout<<"\n\n Enter Floor: ";
            cin>>searchFloor;
            bool cond=false;
            roomfile.open("roomfile.txt",ios::in);
            if(roomfile.fail()){
                cout<<"\n\t\t\t\t ERROR while opening the file";
                exit(0);
            }

            cout<<"\n\t\t\t\t   Rooms on Floor "<<searchFloor<<".\n\n";
            roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;
            while(!roomfile.eof()){
                if(rooms.floor==searchFloor){
                    cout<<"\n\t\t\t\t\tRoom Floor: "<<rooms.floor<<endl;
                    cout<<"\t\t\t\t\tRoom Number: "<<rooms.roomNumber<<endl;
                    cout<<"\t\t\t\t\tID: "<<rooms.roomId<<endl;
                    cout<<"\t\t\t\t\tRoom Rate: "<<rooms.rate<<endl;
                    cout<<"\t\t\t\t\tRoom Status: "<<rooms.status<<endl;
                    cond=true;
                }



            roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;
            }
            if(!cond) cout<<"\n\t\t\t\t   There is no such Room Floor"<<endl;
        roomfile.close();
        cout<<endl;
            break;
    }
        case 4:{
            system("cls");
            cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"-----------------------------------------Search By Room Rate----------------------------------------------"<<endl;
            cout<<"\n\n Enter Room Rate you want: ";
            cin>>searchroomRate;
            bool cond=false;
            roomfile.open("roomfile.txt",ios::in);
            if(roomfile.fail()){
                cout<<"\n\t\t\t\t ERROR while opening the file";
                exit(0);
            }

            cout<<"\n\t\t\t\tRooms With room rate < or = "<<searchroomRate<<".\n\n";
            roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;
            while(!roomfile.eof()){
                if(rooms.rate>=searchroomRate){
                    cout<<"\n\t\t\t\t\tRoom Floor: "<<rooms.floor<<endl;
                    cout<<"\t\t\t\t\tRoom Number: "<<rooms.roomNumber<<endl;
                    cout<<"\t\t\t\t\tID: "<<rooms.roomId<<endl;
                    cout<<"\t\t\t\t\tRoom Rate: "<<rooms.rate<<endl;
                    cout<<"\t\t\t\t\tRoom Status: "<<rooms.status<<endl;
                    cond=true;
                }
                if(!cond) cout<<"\n\t\t\t\t\t There is no such Room Rate"<<endl;

            roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;
            }
            if(!cond) cout<<"\n\t\t\t\t\t There is no such Room Rate"<<endl;
        roomfile.close();
        cout<<endl;
            break;
    }
        default:
            cout<<"Invalid input"<<endl;

    }
}


void editRoom(){
    system("cls");
    fstream roomfile,roomfile1;
    int oppchange;
    char id[20];
    string status;
     cout<<"---------------------------------------------------------------------------------------------------"<<endl;
     cout<<"--------------------------------------------Edit Room----------------------------------------------"<<endl;
    roomfile.open("roomfile.txt",ios::in);
    if(roomfile.fail()){
          cout<<"\n\t\t\t\t ERROR while opening the file";
            exit(0);
            }
    if(!roomfile){
        cout<<"\n\t\t\t\t No Data Present"<<endl;
    }

else{
    cout<<"\n\n Enter Id of The Room You Want to Edit: ";
    cin>>id;
    cout<<"\What Propriety of Room Id "<<id<<" Do you want to change"<<endl;
    cout<<"\n\t\t\t\t\t1.Room Floor"<<endl;
    cout<<"\t\t\t\t\t2.Room Number"<<endl;
    cout<<"\t\t\t\t\t3.Room ID"<<endl;
    cout<<"\t\t\t\t\t4.Room Rate"<<endl;
    cout<<"\t\t\t\t\t5.Room Status"<<endl;
    cout<<"\nEnter your choice: ";
    cin>>oppchange;
    roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;
    roomfile1.open("roomfilecp.txt",ios::app | ios:: out);
    if(roomfile1.fail()){
        cout<<"\n\t\t\t\t ERROR while opening the file";
        exit(0);
    }
    while(!roomfile.eof()){
        if(strcmp(id,rooms.roomId)==0){

            switch(oppchange){
                case 1:
                        cout<<"\n Enter The New Room Floor: ";
                        cin>>rooms.floor;

                    break;
                case 2:
                        cout<<"\n Enter The New Room Number: ";
                        cin>>rooms.roomNumber;

                    break;

                case 3:
                        cout<<"\n Enter The New Room ID: ";
                        cin>>rooms.roomId;

                        break;
                case 4:
                        cout<<"\n Enter The New Room Rate: ";
                        cin>>rooms.rate;

                    break;
                case 5:
                        cout<<"\n Enter The New Room Status: ";
                        cin>>rooms.status;

                        break;

                default:
                    cout<<"\n\n\t\t\t\t IVALID INPUT";
                    break;
            }
                cout<<"\n\t\t\t\t\tRoom Floor: "<<rooms.floor<<endl;
                cout<<"\t\t\t\t\tRoom Number: "<<rooms.roomNumber<<endl;
                cout<<"\t\t\t\t\tID: "<<rooms.roomId<<endl;
                cout<<"\t\t\t\t\tRoom Rate: "<<rooms.rate<<endl;
                cout<<"\t\t\t\t\tRoom Status: "<<rooms.status<<endl;

        }
        roomfile1<<" "<<rooms.floor<<" "<<rooms.roomNumber<<" "<<rooms.roomId<<" "<<rooms.rate<<" "<<rooms.status<<endl;
        roomfile>>rooms.floor>>rooms.roomNumber>>rooms.roomId>>rooms.rate>>rooms.status;

    }

    roomfile.close();
    roomfile1.close();
}

    remove("roomfile.txt");
    rename("roomfilecp.txt","roomfile.txt");

}
