#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include "structure.h"
#include "abstract.h"
#include "pluginsDeveloper.h"
#include "developer.hpp"
#include "pluginsUser.hpp"
#include <map>
using namespace nlohmann;
using namespace std;
using namespace udt;

/**
 * @brief
 *
 * @param j
 * @param f
 */
static void map_json(map<string, string> j, shared_ptr<udt::udtTest> f)
{
    // j = json{ { "plugins", f.plugins } };
    j["str"] = f->str;
    std::cout << "users map " << j["str"] << std::endl;
}
static void to_jsons(json &j, udt::pluginTest &f)
{
    j = json{ { "plugins", f.plugins } };
    std::cout << "users funciton " << j << std::endl;
}
static void testShared(json &j, shared_ptr<udt::pluginTest> &p)
{
    j = p;
    std::cout << "test shared = " << j << std::endl;
}
static void testTemp(json &j, std::shared_ptr<udt::udtTest> p)
{
    j = p;
    std::cout << "testTemp = " << j << std::endl;
}
template <typename T>
using toJsonFucntion = std::function<void(json &j, T)>;
template <typename T1, typename T2>
using toJsonFucntionMap = std::function<void(T1 j, T2 m)>;
int main()
{
    udt::testPlugins pluginsInfo{ "哈哈" };
    udt::udtTest     t{ "123" };


    pluginsUser users1(pluginsInfo, t);
    users1.tojson();
    auto tp = reinterpret_cast<udt::udtTest *>(&t);
    users1.tojson(tp, TYPE_NAME::UDT_TEST);
    json js; // 想得到的json

    udt::pluginTest p{ "plugins" };
    pluginsUser     users;
    users.tojson();
    /**
     * @brief 通过用户注册一个function类模板,把自己需要解析的结构体作为function 的模板参数
     * 将自己写好的解析函数,注册进去
     *
     */
    // function<udt::pluginTest(json & j, udt::pluginTest)> funcs;
    //
    toJsonFucntion<udt::pluginTest> f = std::bind(to_jsons, js, p);

    users.setFunctionJson(f); // 设置回调函数
                              /*
                              shared_ptr<udt::pluginTest> s;
                              s.reset(new udt::pluginTest{ "plugins test" });
                              toJsonFucntion<shared_ptr<udt::pluginTest>> f1 = std::bind(testShared, js, s);
                              f1(js, s);
                              users.setFunctionJson(f1);
                              */

    shared_ptr<udt::udtTest> udtest;
    udtest.reset(new udt::udtTest{ "test Temp" });
    map<string, string>                                              m1;
    toJsonFucntionMap<map<string, string>, shared_ptr<udt::udtTest>> fs =
        std::bind(map_json, m1, udtest);
    // fs(m1, udtest);
    users.setFunctionJson(fs);

    toJsonFucntion<shared_ptr<udt::udtTest>> f2 =
        std::bind(testTemp, std::placeholders::_1, std::placeholders::_2);
    users.setFunctionJson(f2);

    // users.setFunctionJson(f1);


    udt::developer<udt::testPlugins> developers;
    developers.setJson();
    return 0;
}
