@require(venue, uvenue, message_data, msg_name, header_guard, msg_members,\
msg_get_set, default_constructor, to_string, generation, msg_types)
/*
 * Copyright 2014-2018 Neueda Ltd.
 * 
 * Generated @{generation}
 */
@{header_guard(venue, msg_name)}

#include <string>
#include <sstream>
#include <stdint.h>
@if venue == "Oslo" or venue == "Lse" or venue == "Turquoise" or venue == "BorsaItaliana" or venue =="Jse":
#include "MillenniumPacketUtils.h"
@else:
#include "@{venue}PacketUtils.h"
@end
#include "@{venue}HeaderPacket.h"

namespace neueda
{

PACKED(class @{venue}@{msg_name}
{
    public:
        @if msg_name != 'Header':
        @{venue}Header mHeader;

        @endif
@{msg_members(message_data[msg_name], "        ")}

        @{venue}@{msg_name} ()
        {
            @if msg_name != 'Header':
            mHeader.mMessageLength = (int16_t)sizeof (@{venue}@{msg_name}) - ((int16_t)sizeof (@{venue}Header) - 1);
            mHeader.mMessageType = '@{msg_types[msg_name]}';

            @endif
@{default_constructor(message_data[msg_name], "            ")}
        }

@{msg_get_set(message_data[msg_name], "        ")}

        string toString ()
        {
@{to_string(msg_name, message_data[msg_name], "            ")}
        }
});

} // namespace neueda

#endif
