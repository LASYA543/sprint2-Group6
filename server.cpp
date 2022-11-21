 #include <netinet/in.h>
#include <iostream>
#include <stdlib.h>
//#include "Logger.h"
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
//#include <headers.cpp>

using namespace std;

#define PORT 8080
#define MAX_length 30
char admin[MAX_length]="Tour.txt";
char user[MAX_length]="Reservation.txt";

struct tour{
        char admin_place[MAX_length],admin_code[MAX_length],admin_country[MAX_length],admin_days[MAX_length],admin_prices[MAX_length],admin_payments[MAX_length];
        char user_phone[MAX_length],user_name[MAX_length],user_people[MAX_length],user_date[MAX_length],user_status[MAX_length],user_dcode[MAX_length],user_prices[MAX_length],user_payments[MAX_length];
};
class travel{
	public:
		travel(){
			cout<<"travel booking app";
		}
		void login();
};

void travel::login(){
	int count=0;
	int client_fd;
	recv(client_fd, &count, sizeof(count),0 );

     cout<<"login succesful and u can proceed with your bookings/n"<<endl;

}


int main(int argc, char const* argv[])
{

	int count=0;
    int server_fd, client_fd, new_socket, valread;

    struct sockaddr_in address;
int opt = 1;

    int addrlen = sizeof(address);

    char buffer[1024] = { 0 };


    // Creating socket file descriptor

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
             perror("socket failed");

        exit(EXIT_FAILURE);

    }
    else {
	    cout<<"socket created succesfully"<<endl;
    }


    // Forcefully attaching socket to the port 8080

    if (setsockopt(server_fd, SOL_SOCKET,

                   SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt))) {
             perror("setsockopt");

        exit(EXIT_FAILURE);

    }

    address.sin_family = AF_INET;

    address.sin_addr.s_addr = INADDR_ANY;

    address.sin_port = htons(PORT);


    // Forcefully attaching socket to the port 8080

    if (bind(server_fd, (struct sockaddr*)&address,sizeof(address))

                            < 0) {

        perror("bind failed");

        exit(EXIT_FAILURE);
  }
    else {
	    cout<<"binding succesful"<<endl;
    }

    if (listen(server_fd, 3) < 0) {

        perror("listen");
        exit(EXIT_FAILURE);

    }
    else 
    { 
	    cout<<"listening for client"<<endl;
    }




    if ((new_socket  = accept(server_fd, (struct sockaddr*)&address,

                  (socklen_t*)&addrlen))

        < 0) {

        perror("accept");

        exit(EXIT_FAILURE);

    }
    else {
	    
	    cout<<"connection accepted"<<endl;
    }

 valread = read(new_socket, buffer, 1024);

   /*
  recv(client_fd, &count, sizeof(count),0 );

     cout<<"login succesful and u can proceed with your bookings/n"<<endl;
*/
     close(new_socket);

    // closing the listening socket

    shutdown(server_fd, SHUT_RDWR);
travel t;
t.login();
    return 0;
}
