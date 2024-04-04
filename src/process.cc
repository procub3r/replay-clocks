#include "process.h"

Process::Process(uint32_t nodeId) 
{
    m_lc = 0;
    m_rc = ReplayClock(
        GetNodeLC(),
        nodeId,
        EPSILON,
        INTERVAL
    );
}

uint32_t Process::GetNodeId()
{
    return nodeId;
}

ReplayClock Process::GetReplayClock()
{
    return m_rc;
}

uint64_t Process::GetNodeLC()
{
    return m_lc / INTERVAL;
}

Message Process::Send(uint64_t recv_time)
{
    m_rc.SendLocal(GetNodeLC());
    Message m = Message(
        nodeId,
        m_rc,
        recv_time
    );
    return m;
}

void Process::Recv()
{
    // Sort the message queue
    std::stable_sort(msg_queue.begin(), msg_queue.end(), compareMessage);

    // Process each message according to the earliest received message
    for(uint32_t message = 0; message < msg_queue.size(); ++ message)
    {
        if(msg_queue[message].recv_time < m_lc)
        {
            
            std::cout << "Message received on process " << nodeId << " from " << msg_queue[message].sender << std::endl;

            m_rc.Recv(msg_queue[message].m_rc, GetNodeLC());

            // Erase the message from the queue
            msg_queue.erase(msg_queue.begin() + message);
        }
    }
}

void Process::Tick(uint64_t globalTime)
{
    // Skew clocks within globalTime and globalTime + clockSkew
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, (globalTime + (EPSILON*INTERVAL) - m_lc) - 1);
    m_lc += dis(gen);
}