#include "../include/id.h"

dukpp03::Id::Id()
{
    m_bytes.append(1, 1);
}

const std::string& dukpp03::Id::bytes() const
{
    return m_bytes;
}

void dukpp03::Id::next()
{
    char& last_byte = m_bytes[m_bytes.length() - 1]; 
    if (last_byte == 255)
    {
        m_bytes.append(1, 1);
    }
    else
    {
        last_byte += 1;
    }
}