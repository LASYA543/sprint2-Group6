#include"header.h"
#include"functions.h"
#include"logger.h"
#include"admin.cpp"
//#include"user.cpp"
#include"main.cpp"
#define PORT 8080

using namespace std;
void travel:: login()
{
        int count = 0;
	int client_fd;
        string username,password,user,pass;
        cout<<"please enter the following details to login"<<endl;
        LOG_INFO("USERNAME :");
        cin>>username;
        LOG_INFO("PASSWORD :");
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
	
                send(client_fd,&count,sizeof(int),0);
                cout<<"\nHello"<<username<<"\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
		
        }
        else
       {

                LOG_ERROR("\nLOGIN ERROR\nPlease check your username and password\n");

        }
}
int main(int argc, char const* argv[])
{

    int sock = 0, valread, client_fd;

    struct sockaddr_in serv_addr;

    char buffer[1024] = { 0 };

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {

        printf("\n Socket creation error \n");

        return -1;

    }
    else {
	    cout<<"Socket created successfully"<<endl;
    }
    serv_addr.sin_family = AF_INET;

    serv_addr.sin_port = htons(PORT);


    // Convert IPv4 and IPv6 addresses from text to binary
// form

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)

		    <= 0) {

        printf( "\nInvalid address/ Address not supported \n");

        return -1;

    }
    else {
	   
	    cout<<"Binding successful"<<endl;
    }

    if ((client_fd

         = connect(sock, (struct sockaddr*)&serv_addr,

                   sizeof(serv_addr)))

        < 0) {

        printf("\nConnection Failed \n");
        return -1;
 }
    else {

	    cout<<"connnection successful"<<endl;
    }
      
   
    LOG_INIT();
       

     /*   LOG_INFO("welcome");
        LOG_INFO("\nLogin");*/
    cout<<"             \t\t WELCOME TO TRAVEL BOOKING APP\n\n\n";
    cout<<"             \t\t  TRAVEL BOOKING APP MENU\n\n\n";
    cout<<"             \t\t    PRESS ENTER TO CONTINUE....\n\n";
      
       

      LOG_DEINIT();

    travel t;
    t.menu();
    return 0;

}
