#ifndef HANDLER__H_
#define HANDLER__H_

#include "../include/json.hpp"
#include <string>

#include <vector>
#include <unordered_map>

using nlohmann::json;
class Handler
{
public:
    Handler();
    ~Handler();
    uint32_t createEntry(std::string name);

    void parseStringToJson(std::string& data);
    json getJsonFromHexRep(std::vector<uint8_t> data);
    std::vector<uint8_t> getHexRep(json& data);
private:
 std::unordered_map<std::string,json*> m_Entrys;
    

};

#endif