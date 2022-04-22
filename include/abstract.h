#ifndef __ABSTRUACT_H__
#define __ABSTRUACT_H__
#include <string>
#include <nlohmann/json.hpp>
namespace udt
{
struct pluginTest
{
    std::string plugins;
};

struct testPlugins
{
    std::string pluginsName;
};

struct udtTest
{
    std::string str;
};
enum TYPE_NAME
{
    TEST_PLUGINS    = 0,
    UDT_PLUGIN_TEST = 1,
    UDT_TEST        = 2,
};
/**
 * @brief 一个抽象类,用于提供接口层的
 *
 */

class abstract
{
private:
    /* data */
public:
    abstract(testPlugins pluginsInfo, udtTest udtTestInfo) :
        plugins(pluginsInfo), m_test(udtTestInfo)
    {
    }
    abstract() {}
    virtual nlohmann::json set_from_json(void *) {}
    virtual void           set_to_json() {}
    virtual void           set_to_json(void *, TYPE_NAME) {}
    testPlugins            plugins;
    udtTest                m_test;
    void                   setJsonData(void *data) {}

private:
    nlohmann::json setFromJson() {}
    void           setToJson() {}
};


} // namespace udt

#endif
