#include <iostream>
#include <string>
#include <initializer_list>
#include <utility>
#include <stdexcept>
#include <new>
#include <iomanip>

class VException :public std::bad_alloc
{
public:
	virtual const char* what() const noexcept override
	{
		return "Negative array length!!!";
	}
};

template<class T>
class Vector
{
	int m_size{};
	int m_capacity{};
	T* m_data{};

public:
	Vector() = default;
	Vector(int size, const T& value) 
		:m_size{ size }, m_capacity{ m_size }
	{
		if (m_size < 0)
			throw VException();

		if (size > 0)
		{
			m_data = new T[m_capacity];
			for (int i{ 0 }; i < m_size; ++i)
				m_data[i] = value;
		}
	}
	explicit Vector(int size) :m_size{ size }, m_capacity{ m_size }
	{
		if (m_size < 0)
			throw VException();

		if (size > 0)
			m_data = new T[m_capacity]{};
	}
	Vector(std::initializer_list<T> list) :Vector(static_cast<int>(list.size()))
	{
		int i{ 0 };
		for (const T& a : list)
		{
			m_data[i] = a;
			++i;
		}
	}

	virtual ~Vector() { delete[] m_data; }

	Vector(const Vector& other) 
		:m_size{ other.m_size }, m_capacity{ other.m_capacity }
	{
		if (other.m_data)
		{
			m_data = new T[m_capacity]{};

			for (int i{ 0 }; i < m_size; ++i)
				m_data[i] = other.m_data[i];
		}
		else
			m_data = nullptr;
	}

	Vector(Vector&& other) noexcept
		:m_size{ other.m_size }, m_capacity{ other.m_capacity }, m_data{ other.m_data }
	{
		other.m_size = other.m_capacity = 0;
		other.m_data = nullptr;
	}

	Vector& operator= (const Vector& other)
	{
		if (&other == this)
			return *this;
		
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		delete[] m_data;

		if (other.m_data)
		{
			m_data = new T[m_capacity];
			for (int i{ 0 }; i < m_size; ++i)
				m_data[i] = other.m_data[i];
		}
		else
			m_data = nullptr;

		return *this;
	}

	Vector& operator= (Vector&& other) noexcept
	{
		if (&other == this)
			return *this;

		m_size = other.m_size;
		m_capacity = other.m_capacity;
		m_data = other.m_data;
		other.m_size = other.m_capacity = 0;
		other.m_data = nullptr;

		return *this;
	}

	Vector& operator= (std::initializer_list<T> list)
	{
		int listSize{ static_cast<int>(list.size()) };
		if (listSize <= m_capacity)
			m_size = listSize;
		else
		{
			delete[] m_data;
			m_capacity = m_size = listSize;
			m_data = new T[m_capacity];
		}

		int i{ 0 };
		for (const auto& a : list)
		{
			m_data[i] = a;
			++i;
		}

		return *this;
	}

	T& at(int index)
	{
		if (index < 0 || index >= m_size)
			throw std::out_of_range{ "Invalid index!!!" };

			return m_data[index];
	}
	const T& at(int index) const
	{
		if (index >= 0 || index < m_size)
			throw std::out_of_range{ "Invalid index!!!" };

			return m_data[index];
	}
	T& operator[] (int index) { return m_data[index]; }
	const T& operator[] (int index) const { return m_data[index]; }

	T& front () { return m_data[0]; }
	const T& front () const { return m_data[0]; }

	T& back() { return m_data[m_size - 1]; }
	const T& back() const { return m_data[m_size - 1]; }

	bool empty() const { return !m_data; }

	int size() const { return m_size; }
	int capacity() const { return m_capacity; }

	void reserve(int new_cap)
	{
		if (new_cap > m_capacity)
		{
			m_capacity = new_cap;
			T* ptr{ new T[m_capacity]{} };
			for (int i{ 0 }; i < m_size; ++i)
				ptr[i] = std::move(m_data[i]);

			delete[] m_data;
			m_data = ptr;
		}
	}

	void shrink_to_fit()
	{
		if (m_size != m_capacity)
		{
			T* ptr{ new T[m_size] };
			for (int i{ 0 }; i < m_size; ++i)
				ptr[i] = std::move(m_data[i]);

			delete[] m_data;
			m_capacity = m_size;
			m_data = ptr;
		}
	}

	void clear()
	{
		m_size = 0;
	}

	void push_back(const T& value)
	{
		resize(m_size + 1);
		m_data[m_size - 1] = value;
	}

	template< class... Args >
	T* emplace_back(Args&&... args)
	{
		resize(m_size + 1);
		return new(m_data + m_size - 1) T(std::forward<Args>(args)...);
	}

	void pop_back()
	{
		if (m_data)
			--m_size;
	}

	void resize(int count)
	{
		if (count <= m_size)
			m_size = count;
		else if (count <= m_capacity)
		{
			for (int i{ m_size }; i < count; ++i)
				m_data[i] = T();
			m_size = count;
		}
		else
		{
			T* ptr{ new T[count]{} };
			for (int i{ 0 }; i < m_size; ++i)
				ptr[i] = std::move(m_data[i]);

			delete[] m_data;
			m_capacity = m_size = count;
			m_data = ptr;
		}
	}

	void swap(Vector& other)
	{
		int temp{ m_capacity };
		m_capacity = other.m_capacity;
		other.m_capacity = temp;
		temp = m_size;
		m_size = other.m_size;
		other.m_size = temp;
		T* ptr{ m_data };
		m_data = other.m_data;
		other.m_data = ptr;
	}
};

class SampleClass
{
	int m_x{};
	double m_y{};
	char m_z{};
public:
	SampleClass() = default;
	SampleClass(int x, double y, char z): m_x{x}, m_y{y}, m_z{z} {}
	friend std::ostream& operator<< (std::ostream& out, const SampleClass& s)
	{
		out << s.m_x << " " << s.m_y << " " << s.m_z;
		return out;
	}
};

template<typename T>
void print(const Vector<T> v)
{
	for (int i{ 0 }; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << '\n';
}


int main()
{
	std::cout << "---------------- Constructors ----------------" << '\n';
	Vector<std::string> v1;
	Vector<int> v2(4);
	Vector<int> v3(5, 18);
	Vector<std::string> v4{ "AB", "CD", "EF" };
	Vector v5(v4);
	Vector v6(std::move(v4));

	std::cout << "v1: "; print(v1); std::cout << "v2: "; print(v2);
	std::cout << "v3: "; print(v3); std::cout << "v4: "; print(v4);
	std::cout << "v5: "; print(v5); std::cout << "v6: "; print(v6);

	std::cout << "---------------- Assignment -----------------" << '\n';
	v4 = { "GH", "IJ", "KL", "MN", "OP", "QR" };
	v1 = v5;
	v2 = { 1, 2, 3, 4, 5, 6, 7 };
	v5 = std::move(v4);

	std::cout << "v1: "; print(v1); std::cout << "v2: "; print(v2);
	std::cout << "v3: "; print(v3); std::cout << "v4: "; print(v4);
	std::cout << "v5: "; print(v5); std::cout << "v6: "; print(v6);

	std::cout << "-------------- Element access ---------------" << '\n';
	std::cout << "v2.at(0): " << v2.at(0) << '\n';
	std::cout << "v2[6]: " << v2[6] << '\n';
	std::cout << "v2.front(): " << v2.front() << '\n';
	std::cout << "v2.back(): " << v2.back() << '\n';

	std::cout << "----------------- Capacity ------------------" << '\n';
	{
		std::cout << std::boolalpha << "v4.clear(): " << v4.empty() << " ";
		std::cout << "v3.clear(): " << v3.empty() << " " << "\n";
	}
	v4.reserve(10); v3.reserve(1); v6.reserve(10);
	std::cout << "v4: "; print(v4); 
	std::cout << "Capcity: " << v4.capacity() << ", " << "Size: " << v4.size() << '\n';
	std::cout << "v3: "; print(v3); 
	std::cout << "Capcity: " << v3.capacity() << ", " << "Size: " << v3.size() << '\n';
	std::cout << "v6: "; print(v6);
	std::cout << "Capcity: " << v6.capacity() << ", " << "Size: " << v6.size() << '\n';
	v6.shrink_to_fit(); 
	std::cout << "Capcity: " << v6.capacity() << ", " << "Size: " << v6.size() ;
	std::cout << " - after v6.shrink_to_fit()" << '\n';

	std::cout << "----------------- Modifiers ------------------" << '\n';
	v6.clear();
	std::cout << "v6 after clear(): "; print(v6);
	std::cout << "Capcity: " << v6.capacity() << ", " << "Size: " << v6.size() << '\n';
	v6.reserve(10);
	std::cout << "v6 after reserve(10): "; print(v6);
	std::cout << "Capcity: " << v6.capacity() << ", " << "Size: " << v6.size() << '\n';
	v6.push_back("An element added!!!");
	std::cout << "v6 after push_back(): "; print(v6);
	std::cout << "Capcity: " << v6.capacity() << ", " << "Size: " << v6.size() << '\n';
	v6.pop_back();
	std::cout << "v6 after pop_back(): "; print(v6);
	std::cout << "Capcity: " << v6.capacity() << ", " << "Size: " << v6.size() << '\n';
	v6.resize(6);
	std::cout << "v6 after resize(6): "; print(v6);
	std::cout << "Capcity: " << v6.capacity() << ", " << "Size: " << v6.size() << '\n';
	
	std::cout << "Before swap():" << '\n';
	std::cout << "v6: "; print(v6);
	std::cout << "v5: "; print(v5);
	v6.swap(v5);
	std::cout << "After swap():" << '\n';
	std::cout << "v6: "; print(v6);
	std::cout << "v5: "; print(v5);
	Vector<SampleClass> v7;
	v7.emplace_back(3, 4.9, 'f');
	std::cout << "v7 after emplace_back(): "; print(v7);
	std::cout << "Capcity: " << v7.capacity() << ", " << "Size: " << v7.size() << '\n';

	std::cout << "----------------- Exceptions -----------------" << '\n';
	try
	{
		v7.at(4);
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Vector v8(-6, 'c');
	}
	catch (std::bad_alloc& e)
	{
		std::cout << e.what() << '\n';
	}
}