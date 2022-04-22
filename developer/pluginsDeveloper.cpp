#include "pluginsDeveloper.h"
namespace udt
{


} // namespace udt
void testJson()
{
    std::shared_ptr<udt::udtTest> pt;
    pt.reset(new udt::udtTest{ "str" });
    json j;
    j = pt;
    std::cout << "j test = " << j << std::endl;
}
