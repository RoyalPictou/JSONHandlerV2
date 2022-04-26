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

    uint32_t addEntry(json& data, std::string& key, std::string& value);

    uint32_t removeEntry(json& data, std::string key);

    void addArrayEntry(json& data, std::vector<uint32_t>);

    void parseStringToJson(std::string& data);
    json getJsonFromHexRep(std::vector<uint8_t> data);
    std::vector<uint8_t> getHexRep(json& data);
private:
 std::unordered_map<std::string,json*> m_Entrys;
    std::string m_EntryName;
json m_Data;

};

#endif