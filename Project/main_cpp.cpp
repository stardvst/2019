////#include <iostream>
////#include <vector>
////#include <ctime>
////#include <algorithm>
////
////#include "Header.h"
////#include "functions_cpp.h"
////
////bool operator<(const Individual &ind1, const Individual &ind2)
////{
////	return ind1.m_fitness < ind2.m_fitness;
////}
////
////int main()
////{
////	srand((unsigned)time(nullptr));
////
////	int generation = 0;
////
////	vector<Individual> population;
////
////	bool found = false;
////
////	for (auto i = 0; i < POPULATION_SIZE; ++i)
////		population.emplace_back(createGnome());
////
////	while (!found)
////	{
////		sort(population.begin(), population.end());
////
////		for (auto i = 0; i < POPULATION_SIZE; ++i)
////			cout << population[i].m_chromosome << '\n';
////
////		if (population[0].m_fitness <= 0)
////		{
////			found = true;
////			break;
////		}
////
////		vector<Individual> newGeneration;
////
////		// save best 10 % in new generation
////		int eliteCount = (10 * POPULATION_SIZE) / 100;
////		for (auto i = 0; i < eliteCount; ++i)
////			newGeneration.push_back(population[i]);
////
////		// the rest
////		eliteCount = POPULATION_SIZE - eliteCount;
////		for (auto i = 0; i < eliteCount; ++i)
////		{
////			// choose 2 parents from best 50 %
////			auto parent1 = population[randomNum(0, 50)];
////			auto parent2 = population[randomNum(0, 50)];
////
////			auto offspring = parent1.mate(parent2);
////			newGeneration.push_back(offspring);
////		}
////
////		population = newGeneration;
////
////		cout << "Generation: " << generation << '\n';
////		cout << "String: " << population[0].m_chromosome << '\n';
////		cout << "Fitness: " << population[0].m_chromosome << '\n';
////
////		++generation;
////	}
////
////	cout << "Generation: " << generation << '\n';
////	cout << "String: " << population[0].m_chromosome << '\n';
////	cout << "Fitness: " << population[0].m_chromosome << '\n';
////
////	cin.get();
////	return 0;
////}
//
////#include <iostream>
////#include <vector>
////
////using namespace std;
////
////struct Filter
////{
////	void setCriteria(const string &crit)
////	{
////		m_criteria = crit;
////	}
////
////	const string &getCriteria() const
////	{
////		return m_criteria;
////	}
////
////	list<string> get()
////	{
////		return m_result;
////	}
////
////	void filter() = 0;
////
////private:
////	string m_criteria;
////	list<string> m_result;
////};
////
////struct CountCalculator
////{
////
////};
////
////struct CellFilterPydb : Filter
////{
////	void filter() override
////	{
////		// returns all unique cells from db
////	}
////};
////
////struct CellNameRegexFilterPydb : Filter
////{
////	void filter() override
////	{
////		// returns all cells from db, matching regex getCriteria()
////	}
////};
////
////struct TopCellFilterPydb : Filter
////{
////	void filter() override
////	{
////	}
////};
////
////struct TopCellNameRegexFilterPydb : Filter
////{
////	void filter() override
////	{
////	}
////};
////
////struct ViolationFilterPydb : Filter
////{
////	void filter() override
////	{
////	}
////};
////
////struct ViolationNameRegexFilterPydb : Filter
////{
////	void filter() override
////	{
////	}
////};
////
////struct FunctionFilterPydb : Filter
////{
////	void filter() override
////	{
////	}
////};
////
////struct FunctionNameRegexFilterPydb : Filter
////{
////	void filter() override
////	{
////	}
////};
////
////using Filters = vector<Filter>;
////using ResultList = list<string>;
////
////enum Column
////{
////	Cell,
////	Violation,
////	FlatErrors,
////	Error,
////	Fixed,
////	Waive,
////	Ignore,
////	Watch,
////	Total,
////};
////
////struct FlatData
////{
////	FlatData(const vector<Filter> &filters)
////		: m_filters(filters)
////	{
////	}
////
////	//void apply(const Filter &filt)
////	//{
////	//	m_result.clear();
////	//	filter(*this, filt, m_result);
////	//}
////
////	//ResultList get(vector<pair<Column, Filter>> filters) const
////	//{
////	//	return m_result;
////	//}
////
////	getTopLevelItems()
////	{
////		return getData(0);
////	}
////
////	get(int level)
////	{
////		auto copyData(m_data);
////		for (auto i = 0; i < level; ++i)
////			copyData.apply(m_filters[i]);
////
////		return copyData.get();
////	}
////
////private:
////	ResultList m_result;
////	Filters m_filters;
////};
////
////void filter(const FlatData &flatData, const Filter &filt, ResultList &result)
////{
////
////}
////
////struct Tree
////{
////
////};
////
////int main()
////{
////	CellFilterPydb cellFilt;
////	cellFilt.setCriteria("CHIP");
////
////	ViolationNameRegexFilterPydb violFilter;
////	violFilter.setCriteria("^L45D1*");
////
////	std::vector<Filter> hier_config{ cellFilt, violFilter };
////
////	FlatData flatData(hier_config);
////	auto topItems = flatData.getTopLevelItems();
////
////	auto secondLvl = flatData.get(1);
////}
//
////#include <iostream>
////#include "BTree.h"
////
////constexpr int MIN_DEGREE = 2;
////
////int main()
////{
////	BTree btree(MIN_DEGREE);
////
////	// insert
////	btree.insert(10);
////	btree.insert(15);
////	btree.insert(8);
////
////	btree.insert(9);
////	btree.insert(7);
////	btree.insert(6);
////
////	btree.insert(11);
////	btree.insert(12);
////	btree.insert(14);
////
////	btree.insert(20);
////
////	btree.print();
////
////	// search
////	auto pair1 = btree.search(12);
////	std::cout << "find 12: " << pair1.first << '\n';
////
////	auto pair2 = btree.search(20);
////	std::cout << "find 20: " << pair2.first << '\n';
////
////	auto pair3 = btree.search(16);
////	std::cout << "find 16: " << pair3.first << '\n';
////
////	// remove
////	btree.remove(15);
////
////	btree.print();
////
////	std::cin.get();
////	return 0;
////}
//
////#include <iostream>
//
////struct VoidFunctionCaller : lambda
////{
////	void operator()()
////	{
////
////	}
////};
//
////using VoidFunctionCaller = void (*)();
////
////void callLambda(VoidFunctionCaller f)
////{
////	f();
////}
////
////int main()
////{
////	auto f = []() { std::cout << "This is a lambda function"; };
////	auto g = [](int i) { std::cout << "i = " << i; };
////	callLambda(f);
////	//callLambda(g);
////	std::cin.get();
////}
//
//#include <iostream>
//#include <vector>
//
//struct iConfig
//{
//	virtual std::vector<std::string> getRoots() = 0;
//};
//
//struct cellConfig : iConfig
//{
//	std::vector<std::string> getRoots() override
//	{
//		std::cout << __FUNCTION__ << '\n';
//		std::vector<std::string> cells;
//		cells.emplace_back("CHIP");
//		cells.emplace_back("MMZIO");
//		return cells;
//	}
//};
//
//struct violConfig : iConfig
//{
//	std::vector<std::string> getRoots() override
//	{
//		std::cout << __FUNCTION__ << '\n';
//		std::vector<std::string> violations;
//		violations.emplace_back("L45D1");
//		violations.emplace_back("L46D1");
//		return violations;
//	}
//};
//
//struct fncConfig : iConfig
//{
//	std::vector<std::string> getRoots() override
//	{
//		std::cout << __FUNCTION__ << '\n';
//		std::vector<std::string> functions;
//		functions.emplace_back("LUP2.1");
//		functions.emplace_back("LUP2.2");
//		return functions;
//	}
//};
//
//using Hierarchy = std::vector<iConfig *>;
//
//struct TreeNode
//{
//	TreeNode(std::string n) : name(n) {}
//
//	std::string name;
//	std::vector<TreeNode *> m_children;
//
//	void createChildren(iConfig *cfg)
//	{
//		//cfg->get();
//	}
//};
////
////struct TreeModel
////{
////	int getColumnCount();
////	std::string getColumnName(int column);
////	type getColumnClass(int column);
////	Object getValueAt(Object node, int column);
////	bool isCellEditable(Object node, int column);
////	void setValueAt(Object aValue, Object node, int column);
////}
//
//struct iDataAccessLayer
//{
//	iDataAccessLayer(const std::vector<std::vector<std::string>> &data,
//		Hierarchy *pHier)
//		: m_data(data), m_hier(*pHier)
//	{
//
//	}
//
//	std::vector<std::vector<std::string>> m_data;
//	Hierarchy m_hier;
//	std::vector<int> m_colMapping;
//
//	std::vector<TreeNode *> getRootNodes()
//	{
//		std::vector<std::string> roots = m_hier[0]->getRoots();
//		for (const auto& s : roots)
//			std::cout << s << std::endl;
//	}
//
//	/*TreeNode *getTree()
//	{
//		return getTree(0, m_data.size() - 1, m_data[0].size() - 1);
//	}*/
//
//	TreeNode *get(int level/*, TreeNode *parent*/)
//	{
//		std::vector<TreeNode *> nodes;
//		if (parent == nullptr)
//		{
//			nodes = getRootNodes();
//		}
//		else
//		{
//			nodes = parent->m_children;
//		}
//
//		/*for (auto node : nodes)
//		{
//
//		}*/
//
//		for (int i = 0; i < level; ++i)
//		{
//			node->createChildren(m_hier[i]);
//		}
//
//		return node;
//		//return parent;
//	}
//};
//
//int main()
//{
//	//std::vector<ColTypes> colTypes = { Cell, Violation, Status, Comment };
//
//	std::vector<std::vector<std::string>> data;
//	data.push_back({ "CHIP", "L45D1", "Fixed", "fx" });
//	data.push_back({ "CHIP", "L45D1", "Waived", "wv" });
//	data.push_back({ "CHIP", "L46D1", "Fixed", "fixed" });
//	data.push_back({ "MMZIO", "L45D1", "Error", "err" });
//	data.push_back({ "MMZIO", "L46D1", "Ignore", "ign" });
//
//	Hierarchy hier;
//	hier.push_back(new cellConfig);
//	hier.push_back(new violConfig);
//
//	iDataAccessLayer layer(data, &hier);
//	auto node = layer.get(2);
//
//	std::cout << "ROOTS" << std::endl;
//	layer.getRootNodes();
//
//	/*auto pRoot = layer.getTree();
//
//	for (auto & i : pRoot->m_children)
//	{
//		std::cout << i->name << '\n';
//	}*/
//
//	std::cin.get();
//}

#include <iostream>
#include <limits>
#include <vector>

namespace MyLib
{

template <typename T>
class MyAlloc
{
public:
	using value_type = T;
	using pointer = T *;
	using const_pointer = const T *;
	using reference = T &;
	using const_reference = const T &;
	using size_type = std::size_t;
	using difference_type = std::ptrdiff_t;

	MyAlloc() noexcept = default;
	MyAlloc(const MyAlloc &) noexcept = default;

	template <typename U>
	MyAlloc(const MyAlloc<U> &) noexcept {};

	~MyAlloc() = default;

	template <typename U>
	struct rebind
	{
		using other = MyAlloc<U>;
	};

	static pointer address(reference value)
	{
		return &value;
	}

	static const_pointer address(const_reference value)
	{
		return &value;
	}

	pointer allocate(size_type num, const void * = nullptr)
	{
		std::cerr <<
			"allocate " << num << " element(s) of size " << sizeof(T) << '\n';

		auto ret = static_cast<pointer>(::operator new(num * sizeof(T)));
		std::cerr << "allocated at " << static_cast<void *>(ret) << '\n';
		return ret;
	}

	static void construct(pointer p, const T &value)
	{
		std::cerr << "constructing " << value << "...\n";
		new(static_cast<void *>(p)) T(value);
	}

	static void deallocate(pointer p, size_type num)
	{
		std::cerr <<
			"deallocate " << num << " element(s) of size " << sizeof(T)
			<< " at " << static_cast<void *>(p) << '\n';

		::operator delete(static_cast<void *>(p));
	}

	static void destroy(pointer p)
	{
		std::cerr << "destroying " << *p << "...\n";
		p->~T();
	}

	[[nodiscard]] static size_type max_size() noexcept
	{
		return std::numeric_limits<std::size_t>::max() / sizeof(T);
	}
};

template <typename T1, typename T2>
bool operator==(const MyAlloc<T1> &t1, const MyAlloc<T2> &t2) noexcept
{
	return true;
}

template <typename T1, typename T2>
bool operator!=(const MyAlloc<T1> &t1, const MyAlloc<T2> &t2) noexcept
{
	return false;
}

}

int main() noexcept
{
	std::vector<int, MyLib::MyAlloc<int>> vec;

	std::cout << "insert 42:\n";
	vec.push_back(42);

	std::cout << "\ninsert 56:\n";
	vec.push_back(56);

	std::cout << "\ninsert 11:\n";
	vec.push_back(11);

	std::cout << "\ninsert 22:\n";
	vec.push_back(22);

	std::cout << "\ninsert 33:\n";
	vec.push_back(33);

	std::cout << "\ninsert 44:\n";
	vec.push_back(44);

	std::cin.get();
	return 0;
}