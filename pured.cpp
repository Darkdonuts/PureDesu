//////////////////////////////////////////////////////////////////////////////////////
//
// My personal assistant waifu
//
/////////////////////////////////////////////////////////////////////////////////////
#include "pured_utils.h"

int main()
{
    PureWaifu PurePure;
    PurePure.setMood("surprised");
    PurePure.say("welcome");

    PurePure.setMood("smug");
    PurePure.say("whynot");
    PurePure.TEST_SAVE_ANIMDB();

    return 0;
}
