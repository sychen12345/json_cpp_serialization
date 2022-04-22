#ifndef __PLUGINS_USER_H__
#define __PLUGINS_USER_H__
#include "pluginsDeveloper.h"
namespace udt
{
/**
 * @brief json插件使用者,不需要知道json的实现方法,用lib封装后，也不会知道
 *
 */

class pluginsUser : public pluginsDeveloper<udt::pluginTest>
{
private:
    /* data */
public:
    void tojson() { setToJson(); }
    void tojson(void *p, TYPE_NAME name) { setToJson(p, name); }
    json fromjson(void *p) { setFromJson(p); }
    pluginsUser() {}
    pluginsUser(udt::testPlugins t, udt::udtTest utest) : pluginsDeveloper(t, utest) {}
    ~pluginsUser() {}
};


} // namespace udt
#endif