#include <iostream>
#include "trace.h"

void Last()
{
    CTrace oLast("Last");
    printf("[%d]", CTrace ::GetLevel());
}
void Insider()
{
    CTrace oSecond("Insider");
    printf("[%d]", CTrace ::GetLevel());
    Last();
}
void SomeFunc()
{
    CTrace oSome("SomeFunc");
    printf("[%d]", CTrace ::GetLevel());
    Insider();
}
int main()
{
    CTrace oM("main");
    printf("[%d]", CTrace ::GetLevel());
    SomeFunc();
}