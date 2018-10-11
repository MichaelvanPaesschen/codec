/*
 * Copyright 2014-2018 Neueda Ltd.
 * 
 * Generated 21/09/2018
 */
#ifndef TURQUOISE_HEADER_PACKET_H
#define TURQUOISE_HEADER_PACKET_H

#include <string>
#include <sstream>
#include <stdint.h>
#include "MillenniumPacketUtils.h"
#include "TurquoiseHeaderPacket.h"

namespace neueda
{

PACKED(class TurquoiseHeader
{
    public:
        int8_t mStartOfMessage;
        uint16_t mMessageLength;
        char mMessageType;

        TurquoiseHeader ()
        {
            mStartOfMessage = 2;
            mMessageLength = 0;
        }

        bool setStartOfMessage (int8_t v)
        {
            mStartOfMessage = v;
            return true;
        }

        int8_t getStartOfMessage ()
        {
            return mStartOfMessage;
        }

        bool setMessageLength (uint16_t v)
        {
            mMessageLength = v;
            return true;
        }

        uint16_t getMessageLength ()
        {
            return mMessageLength;
        }

        bool setMessageType (char v)
        {
            mMessageType = v;
            return true;
        }

        char getMessageType ()
        {
            return mMessageType;
        }

        string toString ()
        {
            stringstream ss;
            ss << "Header::"
               << "[StartOfMessage=" << getStartOfMessage () << "],"
               << "[MessageLength=" << getMessageLength () << "],"
               << "[MessageType=" << getMessageType () << "]";
            return ss.str ();
        }
});

} // namespace neueda

#endif
