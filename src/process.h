#include "replay-config.h"
#include "replay-clock.h"
#include "message.h"

#include <vector>
#include <random>
#include <algorithm>

class Process
{

public:
    uint32_t nodeId;
    uint64_t m_lc;
    ReplayClock m_rc;

    std::vector<Message> msg_queue;

    Process() {}

    Process(uint32_t pid);
    
    uint32_t GetNodeId();

    ReplayClock GetReplayClock();

    uint64_t GetNodeLC();

    Message Send(uint64_t recv_time);

    void Recv();

    void Tick(uint64_t globalTime);

};