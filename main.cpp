// Main menu
void travel :: menu(){
 /*   cout<<"             \t\t WELCOME TO TRAVEL BOOKING APP\n\n\n";
    cout<<"             \t\t  TRAVEL BOOKING APP MENU\n\n\n";
    cout<<"             \t\t    PRESS ENTER TO CONTINUE....\n\n";*/
    if(cin.get()=='\n'){
        int choice,ch1,ch2;
        travel obj;
        cout<<"\n Who are You?\n";
        cout<<"1. ADMIN\n";
        cout<<"2. USER\n";
//	cout<<"3.Back to main Menu\n\n";
        cout<<"Enter any other key for exit\n\n\n";
        cout<<"Enter Your Option\n";
        cin>>choice;
        switch(choice){
            case 1:
                obj.login();
                cout<<"\t\tWELCOME ADMIN MENU\n";
                cout<<"1. New trips\n";
                cout<<"2. Display a Trip\n";
                cout<<"3. Display a Reservation\n";
                cout<<"4. Update Trip\n";
                cout<<"5.Back to Main menu\n\n";
                cout<<"Enter your option\n";
                while(1){
                    cout<<"\nENTER UR CHOICE: ";
                    cin>>ch1;
                    switch(ch1){
                        case 1:
                            obj.admin_writedata();
                            break;
                        case 2:
                            obj.admin_display();
                            break;
                        case 3:
                            obj.user_display();
                            break;
                        case 4:
                            obj.admin_modify();
                            break;
			case 5:
			    obj.menu();
			    break;
                        default:
                            exit(0);
                    }
                }
            case 2:
              int choice;
              cout<<"\t\tWELCOME USER MENU\n"<<endl;
              cout<<"\t1. login"<<endl;
              cout<<"\t2. register"<<endl;
              cout<<"\nenter choice"<<endl;
              cin>>choice;

            switch(choice)
            {
            case 1:
            
                obj.user_login();
            Label:
                cout<<"\t\tWELCOME USER\n";
                cout<<"\t1. New Reservation\n";
		cout<<"\t2. choose vehicle\n";
                cout<<"\t3. Search Reservation\n";
                cout<<"\t4. Cancel Reservation\n";
                cout<<"\tEnter any other key for exit\n\n\n";
                cout<<"\tEnter your option\n";
                while(1){
                    cout<<"\nENTER UR CHOICE: ";
                    cin>>ch2;
                    switch(ch2){
                        case 1:
                            cout<<"-----------------------------------";
                            cout<<"\n Choose Your destination\n";
                            cout<<"-----------------------------------\n";
                            obj.admin_display();
                            cout<<"\n";
                            obj.user_writedata();
                            break;
                        case 2:
			    obj.choosevehicle();
                            break;
                        case 3:
			     obj.user_search();
                              break;
			case 4:
                            obj.user_cancel();
                            break;
                        default:
                            exit(0);
                    }
                }
            case 2:
                obj.user_registration();
                goto Label;
                break;
            default:
                
                break;
        }   
/*	    case 3:
	     obj.menu();
	    break; */
        default:

            exit(0);

    }

        
    }
}

