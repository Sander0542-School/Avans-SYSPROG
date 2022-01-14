#ifndef NETWORKING_H_
#define NETWORKING_H_

#if defined(WIN32) || defined(WIN64)
    #include <ws2tcpip.h>

    // Tell linker to use these libraries
    #pragma comment (lib, "Ws2_32.lib")
    #pragma comment (lib, "Mswsock.lib")
    #pragma comment (lib, "AdvApi32.lib")

    //=============================================================================
    class WSA
    //=============================================================================
    // ONLY NEEDED IN MS-WINDOWS
    //
    // An instance of this class is created globally.
    // So constructor is automatically called before main()
    // and destructor is automatically called after main().
    // Result: Windows Socket API is active when needed.
    //=============================================================================
    {
        WSADATA data;
        static WSA instance;
    public:
        WSA();
        ~WSA();
    };
#else // assume POSIX
    #include <sys/socket.h>
    #include <sys/ioctl.h>
    #include <net/route.h>
    #include <net/if.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <sys/types.h>
    #include <netdb.h>
    #include <ifaddrs.h>
    #include <unistd.h>
    int closesocket(int sock);
#endif

#endif // NETWORKING_H_
