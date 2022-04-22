#ifndef __DEVELOPER_H__
#define __DEVELOPER_H__
#include <memory>
#include "pluginsDeveloper.h"
#include "abstract.h"
namespace udt
{
template <typename T>
class developer : public udt::abstract
{
private:
    std::unique_ptr<abstract> p_impl;
    /**
     * @brief Set the from json object 隐藏实现接口
     *
     */
    virtual json set_from_json(void *p) {}
    virtual void set_to_json() {}
    /* data */
public:
    developer() : p_impl(std::make_unique<udt::pluginsDeveloper<T>>()), udt::abstract({}, {}) {}
    // 默认构造函数
    developer(udt::testPlugins &plugins, udt::udtTest &utest) :
        p_impl(std::make_unique<udt::pluginsDeveloper<T>>(plugins, utest)), udt::abstract({}, {})
    {
        this->plugins = plugins;
    }
    void           setJson() { p_impl->set_to_json(); }
    nlohmann::json fromJson(void *p) { p_impl->set_from_json(p); }
};
} // namespace udt


#endif
