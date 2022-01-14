// copyright © 2002-2022 Bob Polis

#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "throw.hpp"
#include "networking.hpp"

void __throw_if_min1(int x, const char* file, unsigned int line, const char* message)
{
    if (x == -1)
    {
        LPSTR buf;
        int iResult = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS, nullptr, WSAGetLastError(), 0, (LPTSTR) &buf, 0, nullptr);
        std::ostringstream msg;
        std::string f{file};
        msg << buf << " (" << f.substr(f.rfind('/') + 1) << ":" << line << ")";
        if (message)
        {
            msg << ", " << message;
        }
        LocalFree((HLOCAL) buf);
        throw std::runtime_error{msg.str()};
    }
}
