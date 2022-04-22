//
// Created by Siyuan.Chen on 2022/4/11.
//

#ifndef JSONTEMP_STRUCTURE_H
#define JSONTEMP_STRUCTURE_H
#include <string>
#include <vector>
using std::string;

namespace udt
{
/**
 * 需要反序列化的结构体必须跟to_json from_json 处于同一个命名空间中
 */
struct ConnectConfigSync
{
    string plugins;
    string sync;
    string period;
    string timeout;
    string timeLiness;
};
struct ConnectConfigChronous
{
    string plugins;
    string sync;
};
struct AcquisitionTcp
{
public:
    AcquisitionTcp() = default;

    string id;
    string key;
    string port;
    string ip;
    string name;
};

struct CoreDatas
{
    string id;
    string name;
    string startPos;
    string dataType;
    string mod;
    string registerNum;
    string script;
};
struct AcquisitionSerialComm
{
    string id;
    string key;
    string name;
};
struct Acquisitions
{
    std::vector<CoreDatas> coredatas;
    void                  *acquisitionOption;
};
};     // namespace udt
#endif // JSONTEMP_STRUCTURE_H
