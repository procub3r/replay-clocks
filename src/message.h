#include "replay-clock.h"

class Message
{

public:
    ReplayClock m_rc;
    uint32_t sender;
    uint64_t recv_time;

    Message() {}

    Message(uint32_t nodeId, ReplayClock message_rc, uint64_t receiver_time)
    {
        sender = nodeId;
        m_rc = message_rc;
        recv_time = receiver_time;
    }
};


bool compareMessage(const Message& m1, const Message& m2)
{
    return m1.recv_time < m2.recv_time;
}