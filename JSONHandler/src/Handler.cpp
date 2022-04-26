#include "Handler.h"

#include <iostream>
#include <deque>



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
    m_EntryName = name;
    //m_Data = new json();
   // if (m_Data)
   // {
        //m_Entrys[name] = set;
    //    rv = m_Entrys.size();
   // }
    return rv;
}
uint32_t Handler::addEntry(json & data, std::string& key, std::string& value)
{
    uint32_t rv = 0;
    data[key] = value;
    return rv;
}
uint32_t Handler::removeEntry(json& data, std::string key)
{
    uint32_t rv = data.erase(key);
    return rv;
}
void Handler::addArrayEntry(json& data, std::vector<uint32_t> newarray)
{
    json j_vec(newarray);
    data.merge_patch(j_vec);

}
void Handler::addArrayEntry(json& data, std::deque<float32_t> newarray)
{
    json j_deque(newarray);
    data.merge_patch(j_vec);

}
// [1, 2, 3, 4]

 c_deque{ 1.2, 2.3, 3.4, 5.6 };

// [1.2, 2.3, 3.4, 5.6]

std::list<bool> c_list{ true, true, false, true };
json j_list(c_list);
// [true, true, false, true]

std::forward_list<int64_t> c_flist{ 12345678909876, 23456789098765, 34567890987654, 45678909876543 };
json j_flist(c_flist);
// [12345678909876, 23456789098765, 34567890987654, 45678909876543]

std::array<unsigned long, 4> c_array{ {1, 2, 3, 4} };
json j_array(c_array);
// [1, 2, 3, 4]

std::set<std::string> c_set{ "one", "two", "three", "four", "one" };
json j_set(c_set); // only one entry for "one" is used
// ["four", "one", "three", "two"]

std::unordered_set<std::string> c_uset{ "one", "two", "three", "four", "one" };
json j_uset(c_uset); // only one entry for "one" is used
// maybe ["two", "three", "four", "one"]

std::multiset<std::string> c_mset{ "one", "two", "one", "four" };
json j_mset(c_mset); // both entries for "one" are used
// maybe ["one", "two", "one", "four"]

std::unordered_multiset<std::string> c_umset{ "one", "two", "one", "four" };
json j_umset(c_umset); // both entries for "one" are used
// maybe ["one", "two", "one", "four"]

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
