# Calculator-Application-with-Network-Logging-in-C

## **Overview** 
This repository contains two C programs that demonstrate a simple client-server interaction using TCP sockets. The client program connects to the server, exchanges data (two integers and a choice of operation), and receives the result, time taken, and size of the response from the server.



## **Files** 
client.c: The client-side code that connects to a server, sends data, and receives responses.  
server.c: The server-side code that listens for incoming client connections, processes data, and sends responses back to the client.


## **Prerequisites**  
GCC (GNU Compiler Collection) for compiling the C programs.  
Basic knowledge of C programming and socket programming.


## **Compilation** 
To compile the client and server programs, use the following commands in two different terminal:

```bash
gcc -o client client.c

```

```bash
gcc -o server server.c
```


## **Running the Programs** 
### **1. Start the Server**
Run the server first to listen for incoming client connections: 

```bash 
./server <port>
```

Replace <port> with the port number you wish to use, for example:

```bash
./server 12345
```

## **2. Start the Client** 
After the server is running, start the client and connect it to the server: 

```bash
./client <hostname> <port>
```

Replace <hostname> with the server's hostname or IP address and <port> with the same port number used by the server, for example: 

```bash 
./client localhost 12345 
```

## **Interaction**   

The server will send a prompt to the client to enter the first number.  
The client will enter the number, which is sent to the server.  
The server will then ask for the second number, which the client will provide.  
The server will then ask the client to choose an operation (e.g., addition, subtraction).  
The server processes the request, sends back the result, the time taken, and the size of the data to the client.    
The client can continue this process or select the exit option (7) to terminate the connection.   

## **Exit** 
To exit, select option 7 when prompted by the server during the operation selection.  

## **Example Session** 
```
Server: Enter the first number:
Client: 5

Server: Enter the second number:
Client: 10

Server: Choose an operation (1=add, 2=subtract, etc.):
Client: 1

Server: The answer is: 15
Server: The time taken is: 0 sec
Server: The size is: 4 bytes

Server: Enter the first number:
...
```
## **Troubleshooting**
Ensure that the server is running before starting the client.  
Verify that the port number is correct and not blocked by a firewall.  
If the client or server fails to run, check for error messages and address them accordingly.  


