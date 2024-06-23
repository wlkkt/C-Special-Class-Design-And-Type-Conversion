#include <iostream>
#include <utility>
#include <vector>

using namespace std;
//
//
//class StackOnly
//{
//public:
//    template<class... Args>
//    static StackOnly CreateObj(Args&&... args)
//    {
//        return StackOnly(args...);//���ڷ�����ջ�ϴ�����һ����������ľ�̬��Ա�������������Ͳ���StackOnly*����StackOnly 
//    }
//
//    //ֻ��ס�˸�ֵ����
//    StackOnly& operator=(const StackOnly&) = delete;
//
//    //����һ����ר����operator new����ʱ��ȥnew StackOnly�Ͳ���ȥ����ȫ�ֵ�operator new
//    void* operator new(size_t n) = delete;
//
//private:
//    //�޲�Ĭ�Ϲ��캯��
//    StackOnly() 
//    {
//        cout << "StackOnly()" << endl;
//    };
//    StackOnly(int x,int y)//֧������������Ĭ�Ϲ��캯��
//        :_x(x)
//        ,_y(y)
//    {
//        cout << "StackOnly(int x,int y)" << endl;
//    };
//    int _x;
//    int _y;
//};
//
//int main()
//{
//    StackOnly ho1 = StackOnly::CreateObj();
//    StackOnly ho2 = StackOnly::CreateObj(1, 1);
//
//    StackOnly* ho3 = new StackOnly(ho1);//û��=delete��������,�Ϳ���ʹ��ϵͳ�ṩ��Ĭ�Ͽ�������
//    //ͨ���������Կ�������new�ڶ��Ϸ�����һ��8�ֽڴ�С���ڴ棬Ȼ�󽫵���Ĭ�Ͽ����������ɵ��������������ڴ��У���󷵻ظö���ĵ�ַ��ho3
//    return 0;
//}

namespace hunger 
{
	//����:ִ��main֮ǰ�ʹ�����һ������
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			return &_sint;//���ؾ�̬��Ա����ĵ�ַ
		}

		void Print()
		{
			cout << _x << _y << endl;

			for (auto& e : _vstr)
			{
				cout << e << " ";
			}
			cout << endl;
		}

		//�޸�����
		void AddStr(const string& s)
		{
			_vstr.push_back(s);
		}

		//����������͸�ֵ���ؽ�������ֹ�û�*ָ��Ȼ����ÿ��������½�����
		Singleton(Singleton const&) = delete;
		Singleton& operator=(Singleton const&) = delete;

	private:
		//���캯��:���ݱ����������д��
		Singleton(int x = 0, int y = 0, const vector<string>& vstr = { "yyyyy","xxxx" })
			:_x(x)
			,_y(y)
			,_vstr(vstr)
		{}

		// ����һЩ���ݣ���ǰ����ֻ��һ�ݣ����԰���Щ���ݷŵ�һ�����Ȼ���ٰ��������Ƴɵ������������ݾ�ֻ��һ����
		int _x;
		int _y;
		vector<string> _vstr;

		//��ľ�̬��Ա�������ڸ���ʵ�����������ж��󣬴����ھ�̬����������������ʹ��ʱ���������ƣ���������
		static Singleton _sint;

	};

	Singleton Singleton::_sint(1, 1, { "����","�Ĵ�" });
}

int main()
{
	hunger::Singleton::GetInstance()->Print();
	hunger::Singleton::GetInstance()->AddStr("����");
	hunger::Singleton::GetInstance()->Print();
	hunger::Singleton::GetInstance()->AddStr("����");
	hunger::Singleton::GetInstance()->Print();
	return 0;
}

