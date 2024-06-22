#include <iostream>
#include <utility>
using namespace std;


class StackOnly
{
public:
    template<class... Args>
    static StackOnly CreateObj(Args&&... args)
    {
        return StackOnly(args...);//���ڷ�����ջ�ϴ�����һ����������ľ�̬��Ա�������������Ͳ���StackOnly*����StackOnly 
    }

    //ֻ��ס�˸�ֵ����
    StackOnly& operator=(const StackOnly&) = delete;

    //����һ����ר����operator new����ʱ��ȥnew StackOnly�Ͳ���ȥ����ȫ�ֵ�operator new
    void* operator new(size_t n) = delete;

private:
    //�޲�Ĭ�Ϲ��캯��
    StackOnly() 
    {
        cout << "StackOnly()" << endl;
    };
    StackOnly(int x,int y)//֧������������Ĭ�Ϲ��캯��
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

    StackOnly* ho3 = new StackOnly(ho1);//û��=delete��������,�Ϳ���ʹ��ϵͳ�ṩ��Ĭ�Ͽ�������
    //ͨ���������Կ�������new�ڶ��Ϸ�����һ��8�ֽڴ�С���ڴ棬Ȼ�󽫵���Ĭ�Ͽ����������ɵ��������������ڴ��У���󷵻ظö���ĵ�ַ��ho3
    return 0;
}
