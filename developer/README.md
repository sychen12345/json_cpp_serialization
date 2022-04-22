# developer 插件开发者专用


#### 一个架构demo示例介绍
此时:developer就在扮演"C"的角色
```cpp
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
class A
{
public:
    virtual void Sub() = 0;
private:
    void setSub(){}
};
class B : public A
{
public:
    void seSub(){ Sub();}
private:
    virtual void Sub() override final{}
};
class C : public A
{
public:
    C():pmil_(std::make_unique<B>())
    {
        pmil_->Sub();
    }
    virtual void Sub()override final{}
    std::unique_ptr<A> pmil_;
};
class D : public B
{};
int main() {
    C c;
    c.Sub();
    D d;
    d.seSub();
    return 0;
}



