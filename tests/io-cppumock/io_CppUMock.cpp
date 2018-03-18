#include "CppUTestExt/MockSupport.h"

extern "C"
{
#include "_io.h"
}

void IOWrite(IOAddress addr, IOData data)
{
    mock("IO")
            .actualCall("IOWrite")
            .withParameter("addr", (int)addr)
            .withParameter("data", (int)data);
}

IOData IORead(IOAddress addr)
{
    return (IOData)mock("IO")
            .actualCall("IORead")
            .withParameter("addr", (int)addr)
            .returnValue().getIntValue();
}
