//#include <iostream>
//#include <utility>
//#include <vector>
//
//using namespace std;
////
////
////class StackOnly
////{
////public:
////    template<class... Args>
////    static StackOnly CreateObj(Args&&... args)
////    {
////        return StackOnly(args...);//���ڷ�����ջ�ϴ�����һ����������ľ�̬��Ա�������������Ͳ���StackOnly*����StackOnly 
////    }
////
////    //ֻ��ס�˸�ֵ����
////    StackOnly& operator=(const StackOnly&) = delete;
////
////    //����һ����ר����operator new����ʱ��ȥnew StackOnly�Ͳ���ȥ����ȫ�ֵ�operator new
////    void* operator new(size_t n) = delete;
////
////private:
////    //�޲�Ĭ�Ϲ��캯��
////    StackOnly() 
////    {
////        cout << "StackOnly()" << endl;
////    };
////    StackOnly(int x,int y)//֧������������Ĭ�Ϲ��캯��
////        :_x(x)
////        ,_y(y)
////    {
////        cout << "StackOnly(int x,int y)" << endl;
////    };
////    int _x;
////    int _y;
////};
////
////int main()
////{
////    StackOnly ho1 = StackOnly::CreateObj();
////    StackOnly ho2 = StackOnly::CreateObj(1, 1);
////
////    StackOnly* ho3 = new StackOnly(ho1);//û��=delete��������,�Ϳ���ʹ��ϵͳ�ṩ��Ĭ�Ͽ�������
////    //ͨ���������Կ�������new�ڶ��Ϸ�����һ��8�ֽڴ�С���ڴ棬Ȼ�󽫵���Ĭ�Ͽ����������ɵ��������������ڴ��У���󷵻ظö���ĵ�ַ��ho3
////    return 0;
////}
//
//namespace hunger 
//{
//	//����:ִ��main֮ǰ�ʹ�����һ������
//	class Singleton
//	{
//	public:
//		static Singleton* GetInstance()
//		{
//			return &_sint;//���ؾ�̬��Ա����ĵ�ַ
//		}
//
//		void Print()
//		{
//			cout << _x << _y << endl;
//
//			for (auto& e : _vstr)
//			{
//				cout << e << " ";
//			}
//			cout << endl;
//		}
//
//		//�޸�����
//		void AddStr(const string& s)
//		{
//			_vstr.push_back(s);
//		}
//
//		//����������͸�ֵ���ؽ�������ֹ�û�*ָ��Ȼ����ÿ��������½�����
//		Singleton(Singleton const&) = delete;
//		Singleton& operator=(Singleton const&) = delete;
//
//	private:
//		//���캯��:���ݱ����������д��
//		Singleton(int x = 0, int y = 0, const vector<string>& vstr = { "yyyyy","xxxx" })
//			:_x(x)
//			,_y(y)
//			,_vstr(vstr)
//		{}
//
//		// ����һЩ���ݣ���ǰ����ֻ��һ�ݣ����԰���Щ���ݷŵ�һ�����Ȼ���ٰ��������Ƴɵ������������ݾ�ֻ��һ����
//		int _x;
//		int _y;
//		vector<string> _vstr;
//
//		//��ľ�̬��Ա�������ڸ���ʵ�����������ж��󣬴����ھ�̬����������������ʹ��ʱ���������ƣ���������
//		static Singleton _sint;
//
//	};
//
//	Singleton Singleton::_sint(1, 1, { "����","�Ĵ�" });
//}
//
//
//namespace lazy
//{
//	class Singleton
//	{
//	public:
//		static Singleton* GetInstance()
//		{
//			// ��һ�ε���ʱ�������������󣬵ڶ���ʱ_psint�Ͳ�Ϊ�գ�����ú���Ҳֻ�Ƿ���_psint
//			//�����̰߳�ȫ���⣬��Ҫ����
//			if (_psint == nullptr)
//			{
//				_psint = new Singleton;//������Ҫ�ͷ�
//			}
//
//			return _psint;
//		}
//
//		static void DelInstance()
//		{
//			//�ͷ� + �ÿ�
//			if (_psint)
//			{
//				delete _psint;
//				_psint = nullptr;
//			}
//		}
//
//		void Print()
//		{
//			cout << _x << endl;
//			cout << _y << endl;
//
//			for (auto& e : _vstr)
//			{
//				cout << e << " ";
//			}
//			cout << endl;
//		}
//
//		void AddStr(const string& s)
//		{
//			_vstr.push_back(s);
//		}
//
//		Singleton(Singleton const&) = delete;
//		Singleton& operator=(Singleton const&) = delete;
//
//	private:
//		Singleton(int x = 0, int y = 0, const vector<string>& vstr = { "yyyyy","xxxx" })
//			:_x(x)
//			, _y(y)
//			, _vstr(vstr)
//		{}
//
//		~Singleton()
//		{
//			// ������д���ļ�
//			cout << "~Singleton()" << endl;
//		}
//
//
//		int _x;
//		int _y;
//		vector<string> _vstr;
//		static Singleton* _psint;
//
//		// �ڲ��࣬���ڷ�ֹ�û�������ʾ����DelInstance�ͷŶ���
//		//ʵ����һ����̬�ڲ����Ա����ȫ���������ڣ������������ʱ�ͻ����GC������������������DelInstance
//		class GC
//		{
//		public:
//			~GC()
//			{
//				Singleton::DelInstance();
//			}
//		};
//		static GC gc;//��ʵ����GC����󣬸���û�ò�����ø������������
//	};
//
//	// ������̬��Ա����������Ķ���
//	Singleton* Singleton::_psint = nullptr;
//	Singleton::GC Singleton::gc;//ʲô������
//}
//
//
//int main()
//{
//	//hunger::Singleton::GetInstance()->Print();
//	//hunger::Singleton::GetInstance()->AddStr("����");
//	//hunger::Singleton::GetInstance()->Print();
//	//hunger::Singleton::GetInstance()->AddStr("����");
//	//hunger::Singleton::GetInstance()->Print();
//
//
//	lazy::Singleton::GetInstance()->Print();
//	lazy::Singleton::GetInstance()->AddStr("����");
//	lazy::Singleton::GetInstance()->Print();
//	lazy::Singleton::GetInstance()->AddStr("����");
//	lazy::Singleton::GetInstance()->Print();
//
//	//lazy::Singleton::DelInstance();//��ʾ����DelInstance�����ͷţ�����ʾҲ���ԣ�ע�ͺͷ�ע������������һ�Լ��ɣ�
//	return 0;
//}
//
//
//#include<iostream>
//#include<vector>
//#include<list>
//#include<string>
//using namespace std;
//
////int main()
////{
////	ostream out(nullptr);
////	ostream copy(out);
////
////	return 0;
////}
//
//// ֻ���ڶ���
////class HeapOnly
////{
////public:
////	template<class... Args>
////	static HeapOnly* CreateObj(Args&&... args)
////	{
////		return new HeapOnly(args...);
////	}
////
////	HeapOnly(const HeapOnly&) = delete;
////	HeapOnly& operator=(const HeapOnly&) = delete;
////private:
////	// ����˽�л�
////	HeapOnly()
////	{}
////
////	HeapOnly(int x, int y)
////		:_x(x)
////		,_y(y)
////	{}
////
////	int _x;
////	int _y;
////	vector<int> _a;
////};
////
////int main()
////{
////	//HeapOnly ho1;
////	//HeapOnly* ho2 = new HeapOnly;
////
////	HeapOnly* ho3 = HeapOnly::CreateObj();
////	HeapOnly* ho4 = HeapOnly::CreateObj(1,1);
////
////	//HeapOnly copy(*ho3);
////
////	return 0;
////}

//#include <iostream>
//using namespace std;
//
////��ʽ����ת��
//void Insert(size_t pos)
//{
//	int end = 10;
//	// �Ƚϵ�ʱ��end����ʽ����ת����size_t���ٱȽ�
//	while (end >= pos)
//	{
//		cout << end << "Ų��" << endl;
//		--end;
//	}
//}
//
//int main()
//{
//	//char s = 'a';
//	//char* ptr1 = &s;
//	//int* ptr2 = (int*)ptr1;
//	//cout << ptr2 << endl;
//	Insert(0);
//
//
//	return 0;
//}
//


// ���캯��ֻ֧��
// ��������->�Զ�������֮�䣬���ʽ������� ��ʽ����ת��  �磺string��const char*
// �Զ�������֮��->��������, ����Ҫ����һ��operator���� ��ʽ����ת�� �磺�����A
// �Զ�������֮��->�Զ�������֮�䣬���ʽ������죬��ʽ����ת�� �磺initializer_list������


#include <iostream>
using namespace std;

//class A
//{
//public:
//	operator int()
//	{
//		return _a1 + _a2;
//	}
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//int main()
//{
//	A aa;
//	int a = aa;
//	int b = (int)aa;
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}
	// �������Ĺ��캯����֧������������ʽת�����Զ�������
	/*string s1 = "111111";
	const string& s2 = "11111";*/


//int main()
//{
//	//C++����ʽ����ת��������
//	double d = 12.34;
//	int a1 = static_cast<int>(d);
//	cout << a1 << endl;
//	
//	//C���Ե���ʽ����ת����������
//	int a2 = d;
//	cout << a2 << endl;
//	
//	return 0;
//}

//int main()
//{
//	int a = 12;
//	// int* p = static_cast<int*>(a); ����,int��int*����������ص�����
//	int* p = reinterpret_cast<int*>(a);
//	cout << p << endl;
//	return 0;
//}

//
//int main()
//{
//	const int a = 10;
//
//	int* p = const_cast<int*>(&a); // ȥ��const����
//	*p = 20; // �����޸�ֵ
//	cout << a << endl;//a == 10
//	cout << *p << endl;//*p == 20
//	return 0;
//}

////���Ը����������ڴ��еķ���λ��
//const int c = 10;
//static int f = 10;
//static const int d = 10;
//
//int main()
//{
//	int a = 10;
//	const int b = 10;
//	static const  int e = 10;
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	cout << &e << endl;
//	return 0;
//}
	


#include <iostream>
using namespace std;

#include <iostream>

class A {
public:
    int baseData;
    A() : baseData(0) {}
    A(int data) : baseData(data) {}
};

class B : public A {
public:
    B() {};

    // �Զ��幹�캯����ʵ�ֻ��ൽ�������ת��
    B(const A& a) : A(a) {
        cout << "hello" << endl;
     }

    // �Զ��帳ֵ�������ʵ�ֻ��ൽ�������ת��
    B& operator=(const A& a) {
        cout << "world" << endl;
        return *this;
    }
};

int main() {
    A aaa(10);
    B bbb;

    bbb = aaa;  // ʹ���Զ��帳ֵ�����
    B bbb2 = aaa;  // ʹ���Զ��幹�캯��
    return 0;
}
