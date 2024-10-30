#pragma once
#include <string>
# include "User.h"
# include "EncryptStrategy.h"
# include "VerificationStrategy.h"

class UserProxy
{
    
    public:
    RealUser* ruser;
    EncryptStrategy* encStr;
    VerificationStrategy* verStr;
    
    UserProxy(RealUser* a, EncryptStrategy* b, VerificationStrategy* c)
    {
        ruser = a;
        encStr = b;
        verStr = c;
    };
    void sendMessage(string mes)
    {
        ruser -> sendMessage(encStr->encode(mes));
        cout << verStr->verify(mes) << endl;
    }
};