#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

void error(const char *msg){
	perror(msg);
	exit(1);
}

// argc is the total number of parameter we are passing 

int main(int argc,char *argv[]){
	if(argc < 2){
		fprintf(stderr , "Port not providede . Program Terminated \n");
		exit(1);
	}

	int sockfd,newsockfd,portno,n;
	char buffer[255]; // to store msg ot send

	struct sockaddr_in serv_addr , cli_addr;
	socklen_t clilen; //socklen_t is a datatype in socket.h 32 bit 

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0){
		// if sock fd is resultaing in failure
		error("Error opening socket");
	} 
	
	bzero((char *) &serv_addr,sizeof(serv_addr)); // it clears all the data to what it it reference to 
      
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if(bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
		error("Binding Failed");

	}

	// next step is our server is trying to connect
	
	listen(sockfd,5);
	clilen = sizeof(cli_addr);

	newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr , & clilen);
	if(newsockfd < 0){
		error("Error on Accept");
	}
	int time=0;
	clock_t start_time,end_time;
	int num1,num2,ans,choice,size;
	num1=num2=ans=choice=size=0;
S:	num1 = write(newsockfd,"Enter Number 1 : ",strlen("Enter Number 1"));
	if(num1 < 0){
		error("Error Writing to socket");
	}
	read(newsockfd,&num1,sizeof(int));
	printf("Client Number 1 is : %d\n",num1);

	num2 = write(newsockfd,"Enter Number 2 : ",strlen("Enter Number 1"));
        if(num2 < 0){
                error("Error Writing to socket");
        }
        read(newsockfd,&num2,sizeof(int));
        printf("Client Number 2 is : %d\n",num2);

A:	choice = write(newsockfd,"Enter Your Choice \n 1.Add \n 2.Subtract \n 3.Division \n 4.Multiplication \n 5.Modulus \n 6.Exponentiation\n 7.Exit",strlen("Enter Your Choice \n 1.Add \n 2.Subtract \n 3.Division \n 4.Multiplication \n 5.Modulus \n 6.Exponentiation\n 7.Exit"));
	if(choice < 0){
		error("Error on Writing");
               
	}
	read(newsockfd,&choice,sizeof(int));
	printf("Client - Choice is : %d\n",choice);
	
	
	switch(choice){
	
		case 1:start_time= clock();
			ans = num1 + num2;
			break;
		case 2:start_time= clock();
		        ans = num1-num2;
			break;
		case 3:start_time= clock();
		        ans = num1/num2;	
			break;
		case 4:start_time= clock();
			ans = num1*num2;
			break;
		case 5:start_time= clock();
			ans = num1%num2;
			break;

		case 6:start_time= clock();
			ans = pow(num1,num2);
			break;

		case 7 :
		       goto Q;
	               break;
	       
	               

	}
     	end_time=clock();
     	time=end_time - start_time;
        char len[100];
        sprintf(len,"%d", ans);
	size=strlen(len);
	
	
        printf("Time Taken is :  %d secs \n", time);
        printf("Size of data is :  %d bytes \n", size);
        printf("__________________________________________\n");
        
	write(newsockfd,&ans,sizeof(int)); 
	write(newsockfd,&time,sizeof(int)); 
	write(newsockfd,&size,sizeof(int)); 
	
	if(choice != 7){
		goto S;
	}

Q:	close(newsockfd);
	close(sockfd);
	return 0;
}
