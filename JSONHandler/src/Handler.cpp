#include "Handler.h"

#include <iostream>



Handler::Handler()
{
    std::string jsonData = "{ \"happy\": true, \"pi\" : 3.141 }";
    parseStringToJson(jsonData);

}

Handler::~Handler()
{
}

uint32_t Handler::createEntry(std::string name)
{
    uint32_t rv = 0;
    json* set = new json();
    if (set)
    {
        m_Entrys[name] = set;
        rv = m_Entrys.size();
    }
    return rv;
}

void
Handler::parseStringToJson(std::string& data)
{
    json j3 = json::parse(data);
    std::cout << j3 << std::endl;
}

json Handler::getJsonFromHexRep(std::vector<uint8_t> data)
{
    json rv = json::from_cbor(data);
    return rv;
}
std::vector<uint8_t> Handler::getHexRep(json& data)
{
    std::vector<uint8_t> rv = json::to_cbor(data);
return rv;
}
