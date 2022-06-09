#pragma once

#include <memory>
#include <iostream>

#include "defines.h"

extern "C"
{
#include "unmmko1.h"
#include "unmbase.h"
}

struct AB_PARAMS
{
	CHANNELS channel;
	int address;
	AB_PARAMS(CHANNELS ch, int adr) : channel(ch), address(adr){}
};

/* class for device control MMKO1 Mezonin */
class AikMmkoInterface
{
public:
    explicit AikMmkoInterface(CARD_NUM card, CORE_NUM core);
    ~AikMmkoInterface();

/* methods of working with mmko1*/

/* Function to form CONTROL WORD MMKO ГОСТ Р 52070-2003 п4.4.1 */
    inline static int form_cmd_word(int _addr, bool _rx_tx, int _subaddr, int _word_count)
    {
        return unmmko1_pack_cw(_addr, _rx_tx, _subaddr, _word_count);
    }
private:
    class PrivateData; //PIMPL
    std::unique_ptr<PrivateData> m_data; //pointer on class PIMPL
};


