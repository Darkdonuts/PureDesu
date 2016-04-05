/*
 * My personal assistant waifu
 *
 * TODO: Able to create a file containing a list of interesting animu that are airing
 *       If the list file is empty, ask the user to configure the list for the first
 *       time. Each element in the list should have: date start, date end, airing
 *       hour, and name (for now romaji only).
 */
#include "pured_utils.h"

int main()
{
    PureWaifu PurePure;
    PurePure.setMood("surprised");
    PurePure.say("welcome");
    return 0;
}
