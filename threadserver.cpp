 #include <netinet/in.h>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <pthread.h>
#include <signal.h>
#include <iostream>
#include<netdb.h>
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


pthread_t threads[100];
int threadno=0, fd;

 /* Signal handler to handle ctrl+c to close server socket before terminating the server */
 void sig_handler(int signo) {

     if (signo == SIGINT) {
         std::cout << "\t Exiting..." << '\n';
         close (fd);
         exit (1);
     }
 }

 /* Structure to hold the necessary parameters to pass into the threaded reverse_string function */
 struct req {
     int reqno;
     int des;
     char str [2048];
     socklen_t addlen;
     sockaddr_in clientaddr;
 };

 /*
  * Function called in threads to reverse the string and send the packet back to the respective
  * client socket with the string sent reversed
  */
 void* reverse_string (void*);

 int main(int argc, char const *argv[]) {

     /* server name : Misty */
     sockaddr_in mistaddr; // server address
     sockaddr_in clientaddr; // client address

     socklen_t addrlen = sizeof(clientaddr);
     int recvlen, msgcnt = 0;
     char buf [2048]; // Hold buffer sent in udp packet

     /* Create socket */
     if ((fd = socket (AF_INET, SOCK_DGRAM, 0)) == -1) {
         std::cout << "\n\t Socket creation failed...\n\t Exiting..." << '\n';
         return 0;
     }

     std::cout << "\n\t Socket created..." << '\n';

     /* clear the memory allocated */
     memset ((sockaddr*)&mistaddr, 0, sizeof (mistaddr));
     mistaddr.sin_family = AF_INET;   // IPv4 address family
     mistaddr.sin_addr.s_addr = htonl (INADDR_ANY);  // Give the local machine address
     mistaddr.sin_port = htons (1721); // Port at which server listens to the requests

     /* Bind the IP address and the port number to create the socket */
     if (bind (fd, (sockaddr*)&mistaddr, sizeof (mistaddr)) == -1) {
         std::cout << "\n\t Binding failed...\n\t Exiting..." << '\n';
         return 0;
     }

     std::cout << "\n\t Binding succesful" << '\n';

     /* Signal catching */
     signal(SIGINT, sig_handler);
     signal(SIGTSTP, sig_handler);

     /* Infinte server loop */
     while (1) {
         /* Server listing */
         std::cout << "\n\t Waiting on port " << ntohs(mistaddr.sin_port) << '\n';
         /* waiting to recieve the requests from client at port */
         /* Code blocking function */
         recvlen = recvfrom (fd, buf, 2048, 0, (sockaddr*) &clientaddr, &addrlen);
         /* Counting number of messages recieved */
         msgcnt++;

         /* Filling the parameter values of the threaded function */
         req *r = new req;  // allocate memory
         bzero (r, sizeof (req));  // Clear memory
         r->reqno = msgcnt;
         r->addlen = addrlen;
         r->clientaddr = clientaddr;
         r->des = fd;
         strcpy (r->str, buf);

         /* Create thread to execute the client requests paralelly */
         pthread_create (&threads [threadno++], NULL, reverse_string, (void*)r);
         if (threadno == 100)
             threadno = 0;

         memset (buf, 0, sizeof (buf)); // clear buffer
     }

 }

 // Function to reverse the string and send back the packet */
 void* reverse_string (void* r) {

     req rq = *((req*)r); // Type casting
     std::cout << "\n String: " << rq.str; //<< "  | From: " << inet_ntoa (rq.clientaddr.sin_addr) << ":" << ntohs (rq.clientaddr.sin_port);
     std::cout << "  (message count: " << rq.reqno << ")" << '\n';
     std::reverse( rq.str, &rq.str[ strlen( rq.str ) ] ); // reversing the string
     /* Send the reversed string back to the client at its socket */
     sendto (rq.des, rq.str, strlen (rq.str), 0, (sockaddr*) &rq.clientaddr, rq.addlen);

     return NULL;
 }

/*

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
 /*
     close(new_socket);

    // closing the listening socket

    shutdown(server_fd, SHUT_RDWR);
travel t;
t.login();
    return 0;
}

*/
