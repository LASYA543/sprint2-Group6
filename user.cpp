// USER PANEL
//User registration
void travel :: user_registration()
{

        string username,password,user,pass;
        cout<<"Enter the username :";
        cin>>username;
        cout<<"\nEnter the password :";
        cin>>password;

        ofstream registration("database.txt",ios::app);
        registration<<username<<' '<<password<<endl;
        cout<<"\nRegistration Sucessful\n";
        user_login();

}

//User login
void travel :: user_login()
{
        int count;
        string username,password,user,pass;
        cout<<"please enter the following details to login"<<endl;
        cout<<"USERNAME :";
        cin>>username;
        cout<<"PASSWORD :";
        cin>>password;

        ifstream input("database.txt");
        while(input>>user>>pass)
        {
                if(username==user && password==pass)

                {
                        count=1;
                        cout<<("--------------");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello"<<username<<"\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                user_forgot();
        }
       
}

// displays login credentials if user forgot
void travel :: user_forgot()
{
    int ch;
    cout<<"Forgotten ?\n";
    cout<<"1.Search your id by username"<<endl;
    
        cout<<"2.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string search_user,user,password;
                        cout<<"\nEnter your remembered username :";
                        cin>>search_user;

                        ifstream search("database.txt");
                        while(search>>user>>password)
                        {
                                if(user==search_user)
                                {
                                        count=1;
                                }
                        }
                        search.close();
                        if(count==1)
                        {
                                cout<<"\n account found\n";
                                cout<<"\nYour password is "<<password;
                                cin.get();
                                cin.get();
                                user_login();
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                user_registration();
                        }
                        break;
                }
               
                case 2:
                {
                        cin.get();
                        menu();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        user_forgot();
        }
}
//To add data to the user package
void travel :: user_package(tour r){
    fstream fp;
    fp.open(user,ios::out|ios::app);
    if(!fp){
        cout<<"\nFile Not Found";
		exit(0);
    }
    char data[90];
    strcpy(data,r.user_name);
    strcat(data,"|");
    strcat(data,r.user_phone);
    strcat(data,"|");
    strcat(data,r.user_people);
    strcat(data,"|");
    strcat(data,r.user_dcode);
    strcat(data,"|");
    strcat(data,r.user_date);
    strcat(data,"|");
    strcat(data,r.user_payments);
    strcat(data,"|");
    strcat(data,r.user_prices);
    strcat(data,"|");
    strcat(data,r.user_status);
    strcat(data,"|");
    for(int i=0;i<90-strlen(data);i++)
     	strcat(data,"|");
    fp<<data<<endl;
    fp.close();
}

// To read data from the user package
tour travel :: user_showpackage(char data[]){
	tour r;
	int index=0,indexj=0;
	while(data[indexj]!='|')
	      r.user_name[index++]=data[indexj++];
	r.user_name[index]='\0';
	index=0;
	indexj++;
	while(data[indexj]!='|')
	      r.user_phone[index++]=data[indexj++];
	r.user_phone[index]='\0';
	index=0;
	indexj++;
	while(data[indexj]!='|')
	      r.user_people[index++]=data[indexj++];
	r.user_people[index]='\0';
	index=0;
	indexj++;
	while(data[indexj]!='|')
	      r.user_dcode[index++]=data[indexj++];
	r.user_dcode[index]='\0';
	index=0;
	indexj++;
	while(data[indexj]!='|')
	      r.user_date[index++]=data[indexj++];
	r.user_date[index]='\0';
	index=0;
	indexj++;
	while(data[index]!='|')
	      r.user_payments[index++]=data[indexj++];
	r.user_payments[index]='\0';
	index=0;
	indexj++;
	while(data[index]!='|')
	      r.user_prices[index++]=data[indexj++];
	r.user_prices[index]='\0';
	index=0;
	indexj++;
	while(data[indexj]!='|')
	      r.user_status[indexj++]=data[indexj++];
	r.user_status[index]='\0';
	return(r);
}
//To write data to the user package
void travel :: user_writedata(){
    tour r;
  char data[90];
  cout << "ENTER YOUR NAME: ";
  cin >> r.user_name;
  cout << "ENTER YOUR CONTACT NO.: ";
  cin >> r.user_phone;
  cout << "ENTER NO. OF TOURIST: ";
  cin >> r.user_people;
  int People = atoi (r.user_people);
  cout << "ENTER THE DESTINATION CODE: D-";
  cin >> r.user_dcode;
  cout << "ENTER DATE OF JOURNEY (DD/MM/YY): ";
  cin >> r.user_date;
  cout << "ENTER PAYMENT METHOD CASH OR CARD: ";
  cin >> r.user_payments;
  cout << "TOTAL PRICES ";
  
  fstream fp;
  fp.open (admin, ios::in);
       if(r.admin_code==r.user_dcode)
            cout<<r.admin_prices;
    fp.close();        
  int prices = atoi (r.admin_prices);
  cout << "=" << prices * People;
  cout<<"\nPaid amount: ";
  cin>>r.user_prices;
  cout << "\nENTER 'Confirm' TO CONFIRM YOUR RESERVATION: ";
  cin>>r.user_status;
  
  user_package (r);
}

//displays the user data
void travel :: user_display(){
 	fstream fp;
   	char data[70];
   	tour r;
    fp.open(user,ios::in);
    if(!fp){
		cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"Sr No.\tNAME\tCONTACT NO\tTOTAL PEOPLE\tDATE\tDEST. CODE\tPAYMENT\tPRICE\tSTATUS\n";
    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
    int serial_no=1;
    while(1){
        fp.getline(data,90);
        if(fp.eof())break;
       		r=user_showpackage(data);
        cout<<serial_no++<<"\t"<<r.user_name<<"\t"<<r.user_phone<<"\t"<<r.user_people<<"\t"<<r.user_date<<"\t"<<r.user_dcode<<"\t"<<r.user_payments<<"\t"<<r.user_prices<<"\t"<<r.user_status<<endl;
    }
    fp.close();
    return;
}
void travel::choosevehicle()
{

    int choice;
    cout<<"\n1.car\n2.Bus";
    cout<<"\nEnter your choice";
    cin>>choice;
    switch(choice)
    {
        case 1:
        int passengers,cabChoice,kilometers,carCost;
        cout<<"You choosed car";
        cout << "\n1.Standard Cab - Rs.15 for 1KM" << endl;
        cout << "\n2.Luxury Cab - Rs.25 per 1KM" << endl;

        cout<<"\n1.Standard car\n2.Luxury car";
        cout << "\nEnter which kind of cab you need: ";
        cin >> cabChoice;
        cout<<"Enter no of passengers";
        cin>>passengers;
        cout << "\nEnter Kilometers you have to travel: ";
        cin >> kilometers;
        if(cabChoice==1){

        carCost = (kilometers * 15)* passengers;
        cout << "\nYour tour will cost " << carCost  << endl;

              //  cout << "\nYou have successfully hired standard cab" << endl;
        }
        else
        {

        carCost = (kilometers * 25)*passengers;
            cout << "\nYour tour will cost " << carCost  << endl;
           // cout << "\nYou have successfully hired luxury cab" << endl;
        }
        break;
        case 2:
        int Tourists,Distance,Buscharge,BusChoice;
        cout<<"You choosed Bus";
        cout << "\n1.Non-Ac Bus - Rs.12 for 1KM" << endl;
        cout << "\n2.Ac Bus- Rs. 30 per 1KM" << endl;

        cout<<"\n1.AC\n2.Non-AC";
        cout << "\nEnter which kind of Busyou need: ";
        cin >> BusChoice;
        cout<<"\nEnter no of passengers";
        cin>>Tourists;
        cout << "\nEnter Kilometers you have to travel: ";
        cin >>Distance;
        if(BusChoice==1){

        Buscharge =(Distance * 12) * Tourists;
        cout << "\nYour tour will cost " << Buscharge << endl;
        //cout<<"You have sucessfully Choosed Ac Bus";
        }
        else
        {

        Buscharge =(Distance * 30) * Tourists;
        cout << "\nYour tour will cost " << Buscharge  << endl;
        //cout<<"Your Booking is sucessful";
        }
        break;

        default:
        cout<<"\nInvalid choice";

    }
    cout<<"\nYour Booking is sucessful";


}
//To cancel the data in user package
void travel :: user_cancel(){
    fstream fp;
    char user_name[15],data[90];
    int index,indexj;
    tour s[100];
    fp.open(user,ios::in);
    if(!fp){
		cout<<"\nFile not Found";
		exit(0);
    }
    cout<<"\nEnter Your name to cancel  your reservation: ";
    cin>>user_name;
    index=0;
   	while(1){
        fp.getline(data,90);
        if(fp.eof())break;
        s[index]=user_showpackage(data);
        index++;
    }
   	for(indexj=0;indexj<index;indexj++){
        if(strcmp(s[indexj].user_name,user_name)==0){
	  		cout<<"\nYour Reservation Details are:\n";
	  		cout<<"\nName: "<<s[indexj].user_name;
	  		cout<<"\nContact No.: "<<s[indexj].user_phone;
	  		cout<<"\nNo.of People: "<<s[indexj].user_people;
	  		cout<<"\nDestination: "<<s[indexj].user_dcode;
	  		cout<<"\nDate of Journey: "<<s[indexj].user_date;
	  		cout<<"\nPayment: "<<s[indexj].user_payments;
	  		cout<<"\nPrice: "<<s[indexj].user_prices;
	  		cout<<"\nStatus: "<<s[indexj].user_status;
	  		cout<<"\n\nENTER 'Cancel' TO CANCEL YOUR TICKET: \n";
	  		cin>>s[indexj].user_status;
	  		cout<<"\nYour Reservation has been Cancelled\n";
	  		cout<<"\n\nName: "<<s[indexj].user_name;
	  		cout<<"\nContact No.: "<<s[indexj].user_phone;
	  		cout<<"\nNo.of People: "<<s[indexj].user_people;
	  		cout<<"\nDestination: "<<s[indexj].user_dcode;
	  		cout<<"\nDate of Journey: "<<s[indexj].user_date;
	  		cout<<"\nPayment: "<<s[indexj].user_payments;
	  		cout<<"\nPrice: "<<s[indexj].user_prices;
	  		cout<<"\nStatus: "<<s[indexj].user_status;
            break;
        }
    }
   	if(indexj==index){
        cout<<"\nRECORD NOT FOUND";
        return;
    }
    fp.close();
    fstream fd;
    fd.open(user,ios::out|ios::in);
    if(!fd){
        cout<<"\nCannot open file";
        exit(0);
    }
   	for(indexj=0;indexj<index;indexj++)
        user_package(s[indexj]);
   	fd.close();
}

// To search the user reservations
void travel :: user_search(){
 	fstream fp;
 	char user_name[15],data[90];
 	int index,indexj;
 	tour s;
    fp.open(user,ios::in);
    if(!fp){
	 	cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"\nENTER THE NAME TO BE SEARCHED: ";
    cin>>user_name;
    index=0;
   	while(1){
        fp.getline(data,90);
        if(fp.eof())break;
        s=user_showpackage(data);
        if(strcmp(s.user_name,user_name)==0){
	  	 	cout<<"\n RESERVATION FOUND\n";
	  		cout<<"\nNAME: "<<s.user_name;
	  		cout<<"\nCONTACT NO.: "<<s.user_phone;
	  		cout<<"\nNO. OF PEOPLE: "<<s.user_people;
	  		cout<<"\nDATE OF JOURNEY: "<<s.user_date;
	  		//cout<<"\nPayment: "<<s.user_payments;
	  		//cout<<"\nPrice: "<<s.user_prices;
	  		cout<<"\nSTATUS: "<<s.user_status;
	  		return;
	 	}
    }
    cout<<"\nRESERVATION NOT FOUND";
    return;
}

