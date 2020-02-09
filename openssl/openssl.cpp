#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>

int main( int argc, char * argv[] )
{
    int servfd, connfd;
    socklen_t clilen;
    struct sockaddr_in servaddr, cliaddr;
    char buff[512];
    pid_t chipid;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons( 8888 );
    servaddr.sin_addr.s_addr = htonl( INADDR_ANY );
    SSL_CTX * ctx;
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    if ( (ctx = SSL_CTX_new( SSLv23_server_method() )) == NULL )
    {
        printf( "error1" );
        return 0;
    }
    if ( SSL_CTX_use_certificate_file( ctx, argv[1], SSL_FILETYPE_PEM ) <= 0 )
    {
        printf( "error2" );
        return 0;
    }
    if ( SSL_CTX_use_PrivateKey_file( ctx, argv[2], SSL_FILETYPE_PEM ) <= 0 )
    {
        printf( "error3" );
        return 0;
    }
    if( !SSL_CTX_check_private_key( ctx ) )
    {
        printf( "keyerror" );
        return 0;
    }
    servfd = socket( AF_INET, SOCK_STREAM, 0 );
    bind( servfd, (struct sockaddr *)&servaddr, sizeof(servaddr) );
    listen( servfd, 10 );
    for ( ; ; )
    {
        SSL * ssl;
        clilen = sizeof(cliaddr);
        connfd = socket( AF_INET, SOCK_STREAM, 0 );
        connfd = accept( servfd, (struct sockaddr *)&cliaddr, &clilen );
        chipid = fork();
        if ( chipid != 0 )
            close( connfd );
        else
        {
            close( servfd );
            ssl = SSL_new( ctx );
            SSL_set_fd( ssl, connfd );
            SSL_accept( ssl );
            SSL_read( ssl, buff, 512 );
            printf( "%s\n", buff );
            SSL_shutdown( ssl );
            SSL_free( ssl );
            close( connfd );
            SSL_CTX_free( ctx );
            return 0;
        }
    }
}
