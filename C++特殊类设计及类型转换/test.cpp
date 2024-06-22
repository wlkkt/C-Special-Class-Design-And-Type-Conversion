#include <iostream>
#include <utility>
using namespace std;


class StackOnly
{
public:
    template<class... Args>
    static StackOnly CreateObj(Args&&... args)
    {
        return StackOnly(args...);//用于返回在栈上创建的一个匿名对象的静态成员函数，返回类型不是StackOnly*而是StackOnly 
    }

    //只封住了赋值重载
    StackOnly& operator=(const StackOnly&) = delete;

    //重载一个类专属的operator new，此时再去new StackOnly就不会去调用全局的operator new
    void* operator new(size_t n) = delete;

private:
    //无参默认构造函数
    StackOnly() 
    {
        cout << "StackOnly()" << endl;
    };
    StackOnly(int x,int y)//支持两个参数的默认构造函数
        :_x(x)
        ,_y(y)
    {
        cout << "StackOnly(int x,int y)" << endl;
    };
    int _x;
    int _y;
};

int main()
{
    StackOnly ho1 = StackOnly::CreateObj();
    StackOnly ho2 = StackOnly::CreateObj(1, 1);

    StackOnly* ho3 = new StackOnly(ho1);//没有=delete拷贝构造,就可以使用系统提供的默认拷贝构造
    //通过反汇编可以看到是先new在堆上分配了一个8字节大小的内存，然后将调用默认拷贝构造生成的匿名对象放入该内存中，最后返回该对象的地址给ho3
    return 0;
}
