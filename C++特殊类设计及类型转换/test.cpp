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
////        return StackOnly(args...);//用于返回在栈上创建的一个匿名对象的静态成员函数，返回类型不是StackOnly*而是StackOnly 
////    }
////
////    //只封住了赋值重载
////    StackOnly& operator=(const StackOnly&) = delete;
////
////    //重载一个类专属的operator new，此时再去new StackOnly就不会去调用全局的operator new
////    void* operator new(size_t n) = delete;
////
////private:
////    //无参默认构造函数
////    StackOnly() 
////    {
////        cout << "StackOnly()" << endl;
////    };
////    StackOnly(int x,int y)//支持两个参数的默认构造函数
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
////    StackOnly* ho3 = new StackOnly(ho1);//没有=delete拷贝构造,就可以使用系统提供的默认拷贝构造
////    //通过反汇编可以看到是先new在堆上分配了一个8字节大小的内存，然后将调用默认拷贝构造生成的匿名对象放入该内存中，最后返回该对象的地址给ho3
////    return 0;
////}
//
//namespace hunger 
//{
//	//饿汉:执行main之前就创建出一个对象
//	class Singleton
//	{
//	public:
//		static Singleton* GetInstance()
//		{
//			return &_sint;//返回静态成员对象的地址
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
//		//修改数据
//		void AddStr(const string& s)
//		{
//			_vstr.push_back(s);
//		}
//
//		//将拷贝构造和赋值重载禁掉，防止用户*指针然后调用拷贝构造新建对象
//		Singleton(Singleton const&) = delete;
//		Singleton& operator=(Singleton const&) = delete;
//
//	private:
//		//构造函数:数据被放入数组中存放
//		Singleton(int x = 0, int y = 0, const vector<string>& vstr = { "yyyyy","xxxx" })
//			:_x(x)
//			,_y(y)
//			,_vstr(vstr)
//		{}
//
//		// 想让一些数据，当前程序只有一份，可以把这些数据放到一个类里，然后再把这个类设计成单例，这样数据就只有一份了
//		int _x;
//		int _y;
//		vector<string> _vstr;
//
//		//类的静态成员对象，属于该类实例化出的所有对象，存在于静态区，在类中声明，使用时受类域限制（加类名）
//		static Singleton _sint;
//
//	};
//
//	Singleton Singleton::_sint(1, 1, { "陕西","四川" });
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
//			// 第一次调用时，创建单例对象，第二次时_psint就不为空，进入该函数也只是返回_psint
//			//存在线程安全问题，需要加锁
//			if (_psint == nullptr)
//			{
//				_psint = new Singleton;//可能需要释放
//			}
//
//			return _psint;
//		}
//
//		static void DelInstance()
//		{
//			//释放 + 置空
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
//			// 把数据写到文件
//			cout << "~Singleton()" << endl;
//		}
//
//
//		int _x;
//		int _y;
//		vector<string> _vstr;
//		static Singleton* _psint;
//
//		// 内部类，用于防止用户忘记显示调用DelInstance释放对象
//		//实例化一个静态内部类成员对象（全局生命周期），当程序结束时就会调用GC类对象的析构进而调用DelInstance
//		class GC
//		{
//		public:
//			~GC()
//			{
//				Singleton::DelInstance();
//			}
//		};
//		static GC gc;//不实例化GC类对象，该类没用不会调用该类的析构函数
//	};
//
//	// 两个静态成员对象在类外的定义
//	Singleton* Singleton::_psint = nullptr;
//	Singleton::GC Singleton::gc;//什么都不做
//}
//
//
//int main()
//{
//	//hunger::Singleton::GetInstance()->Print();
//	//hunger::Singleton::GetInstance()->AddStr("甘肃");
//	//hunger::Singleton::GetInstance()->Print();
//	//hunger::Singleton::GetInstance()->AddStr("甘肃");
//	//hunger::Singleton::GetInstance()->Print();
//
//
//	lazy::Singleton::GetInstance()->Print();
//	lazy::Singleton::GetInstance()->AddStr("甘肃");
//	lazy::Singleton::GetInstance()->Print();
//	lazy::Singleton::GetInstance()->AddStr("甘肃");
//	lazy::Singleton::GetInstance()->Print();
//
//	//lazy::Singleton::DelInstance();//显示调用DelInstance可以释放，不显示也可以（注释和非注释两次运行试一试即可）
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
//// 只能在堆上
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
////	// 构造私有化
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
////隐式类型转换
//void Insert(size_t pos)
//{
//	int end = 10;
//	// 比较的时候end会隐式类型转换成size_t，再比较
//	while (end >= pos)
//	{
//		cout << end << "挪走" << endl;
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


// 构造函数只支持
// 内置类型->自定义类型之间，本质借助构造 隐式类型转换  如：string和const char*
// 自定义类型之间->内置类型, 本质要重载一个operator类型 隐式类型转换 如：下面的A
// 自定义类型之间->自定义类型之间，本质借助构造，隐式类型转换 如：initializer_list和容器


#include <iostream>
using namespace std;

class A
{
public:
	operator int()
	{
		return _a1 + _a2;
	}
private:
	int _a1 = 1;
	int _a2 = 2;
};

int main()
{
	A aa;
	int a = aa;
	int b = (int)aa;
	cout << a << endl;
	cout << b << endl;
	return 0;
}
	// 单参数的构造函数，支持内置类型隐式转换成自定义类型
	/*string s1 = "111111";
	const string& s2 = "11111";*/


	int main()
	{
		// 建议规范，但是以前的还能用。对应隐式类型转换
		double d = 12.34;
		int a1 = static_cast<int>(d);
		cout << a1 << endl;
	
		int a2 = d;
		cout << a2 << endl;
	
		return 0;
	}

	int main()
	{
		double d = 12.34;
		int a = static_cast<int>(d);
		cout << a << endl;
	
		// 对应的是以前的强制类型转换
		// int* p = static_cast<int*>(a); 报错
		int* p = reinterpret_cast<int*>(a);
		cout << p << endl;
	

		// 强制类型转换，但是为什么要把去掉const属性单独拿出来
		// 就是专门提醒，去掉const属性是有一些内存可见优化的的风险，要注意是否加了volatile
		volatile const int a1 = 2;
		//int* p1 = (int*)&a1;
		int* p1 = const_cast<int*>(&a1);
		*p1 = 3;
		cout << a1 << endl;
		cout << *p1 << endl;
	
		return 0;
	}

class A
{
public:
	virtual void f() {}

	int _a = 0;
};

class B : public A
{
public:
	int _b = 1;
};

void fun(A* pa)
{
	// 向下转换：父->子
	// pa指向子类对象，转回子类，是安全的
	// pa指向父类对象，转回子类，是不安全的，存在越界的风险问题

	// 不安全
	//B* pb = (B*)pa;

	//  pa指向子类对象，转回子类，正常转换
	//  pa指向父类对象，转回子类，转换失败
	B* pb = dynamic_cast<B*>(pa);
	if (pb)
	{
		cout << pb << endl;
		cout << pb->_a << endl;
		cout << pb->_b << endl;
	}
	else
	{
		cout << "转换失败" << endl;
	}
}

int main()
{
	A a;
	B b;

	fun(&a);
	fun(&b);

	return 0;
}

int main()
{
	// 赋值兼容，向上转换，子->父
	B bb;
	A aa = bb;
	A* ptr = &bb;

	return 0;
}