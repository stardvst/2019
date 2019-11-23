//#include <cstdlib>
//#include <ctime>
//#include <cmath>
//#include <ostream>
//#include <string>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <random>
//
//class City
//{
//public:
//	City()
//	{
//		srand(static_cast<unsigned>(time(nullptr)));
//		m_x = std::rand() % 200;
//		m_y = std::rand() % 200;
//		m_id = ++id;
//	}
//
//	City(const int aX, const int aY) : m_x(aX), m_y(aY) {}
//
//	// getters
//	int getX() const { return m_x; }
//	int getY() const { return m_y; }
//	int getID() const { return m_id; }
//
//	// distance to
//	double distanceTo(const City &city) const
//	{
//		const auto cityX = std::abs(getX() - city.getX());
//		const auto cityY = std::abs(getY() - city.getY());
//		return std::sqrt(cityX * cityX + cityY * cityY);
//	}
//
//	std::string toStr() const
//	{
//		return  std::to_string(m_x) + ", " + std::to_string(m_y);
//	}
//
//private:
//	int m_x{};
//	int m_y{};
//	int m_id = 0;
//
//	inline static int id;
//};
//
//class Cities
//{
//public:
//	static void addCity(const City &city)
//	{
//		m_vecCities.push_back(city);
//	}
//
//	static const City &getCity(const int index)
//	{
//		return m_vecCities.at(index);
//	}
//
//	static int numberOfCities()
//	{
//		return (int)m_vecCities.size();
//	}
//
//private:
//	inline static std::vector<City> m_vecCities{};
//};
//
//class Tour
//{
//public:
//	Tour();
//	Tour(const Tour &tour);
//
//	const City &getCity(int index) const;
//	void setCity(int index, const City &city);
//
//	const std::vector<City> &getTour() const { return m_vecTour; }
//	int tourSize() const;
//	double getDistance() const;
//
//	void generateIndividual();
//
//private:
//	std::vector<City> m_vecTour{};
//	mutable double m_nDistance = 0;
//};
//
//inline Tour::Tour()
//{
//	for (auto idx = 0; idx < Cities::numberOfCities(); ++idx)
//		m_vecTour.emplace_back();
//}
//
//inline Tour::Tour(const Tour &tour) : m_vecTour(tour.m_vecTour), m_nDistance(tour.m_nDistance)
//{
//}
//
//inline const City &Tour::getCity(const int index) const
//{
//	return m_vecTour.at(index);
//}
//
//inline void Tour::setCity(const int index, const City &city)
//{
//	m_vecTour.at(index) = city;
//	m_nDistance = 0;
//}
//
//inline int Tour::tourSize() const
//{
//	return (int)m_vecTour.size();
//}
//
//inline double Tour::getDistance() const
//{
//	if (m_nDistance == 0)
//	{
//		double tourDistance = 0;
//		for (auto idx = 0; idx < tourSize(); ++idx)
//		{
//			auto fromCity = getCity(idx);
//			auto destinationCity = idx + 1 < tourSize() ? getCity(idx + 1) : getCity(0);
//			tourDistance += fromCity.distanceTo(destinationCity);
//		}
//		m_nDistance = tourDistance;
//	}
//	return m_nDistance;
//}
//
//inline void Tour::generateIndividual()
//{
//	for (auto idx = 0; idx < Cities::numberOfCities(); ++idx)
//		setCity(idx, Cities::getCity(idx));
//
//	// shuffle
//	std::random_device r;
//	std::seed_seq seed{ r(), r(), r(), r(), r(), r(), r(), r() }; // 2
//	std::mt19937 gen(seed);
//	std::shuffle(m_vecTour.begin(), m_vecTour.end(), gen);
//}
//
//inline std::ostream &operator<<(std::ostream &os, const Tour &tour)
//{
//	std::string route("|");
//	for (auto idx = 0; idx < tour.tourSize(); ++idx)
//		route += tour.getCity(idx).toStr() + "| -> |";
//	route = route.substr(0, route.size() - 5);
//	return os << route;
//}
//
//inline std::ostream &operator<<(std::ostream &os, const City &city)
//{
//	os <<  << city.getX() << ", " << city.getY();
//	return os;
//}
//
//double acceptanceProbability(const double energy, const double newEnergy, const double temperature)
//{
//	if (newEnergy < energy)
//		return 1;
//	return std::exp((static_cast<double>(energy) - static_cast<double>(newEnergy)) / temperature);
//}
//
//int main()
//{
//	srand(static_cast<unsigned>(time(nullptr)));
//
//	const City city1(60, 200);
//	Cities::addCity(city1);
//	const City city2(180, 200);
//	Cities::addCity(city2);
//	const City city3(80, 180);
//	Cities::addCity(city3);
//	const City city4(140, 180);
//	Cities::addCity(city4);
//	const City city5(20, 160);
//	Cities::addCity(city5);
//	const City city6(100, 160);
//	Cities::addCity(city6);
//	const City city7(200, 160);
//	Cities::addCity(city7);
//	const City city8(140, 140);
//	Cities::addCity(city8);
//	const City city9(40, 120);
//	Cities::addCity(city9);
//	const City city10(100, 120);
//	Cities::addCity(city10);
//	const City city11(180, 100);
//	Cities::addCity(city11);
//	const City city12(60, 80);
//	Cities::addCity(city12);
//	const City city13(120, 80);
//	Cities::addCity(city13);
//	const City city14(180, 60);
//	Cities::addCity(city14);
//	const City city15(20, 40);
//	Cities::addCity(city15);
//	const City city16(100, 40);
//	Cities::addCity(city16);
//	const City city17(200, 40);
//	Cities::addCity(city17);
//	const City city18(20, 20);
//	Cities::addCity(city18);
//	const City city19(60, 20);
//	Cities::addCity(city19);
//	const City city20(160, 20);
//	Cities::addCity(city20);
//
//	double temperature = 10000;
//	const auto coolingRate = 0.003;
//
//	Tour currentSolution;
//	currentSolution.generateIndividual();
//
//	std::cout << "Initial solution distance: " << currentSolution.getDistance() << '\n';
//
//	// current best
//	Tour best(currentSolution);
//
//	while (temperature > 1)
//	{
//		Tour newSolution = currentSolution;
//
//		// random position in tour
//		const auto pos1 = std::rand() % newSolution.tourSize();
//		const auto pos2 = std::rand() % newSolution.tourSize();
//
//		// cities to swap
//		const auto cityToSwap1 = newSolution.getCity(pos1);
//		const auto cityToSwap2 = newSolution.getCity(pos2);
//
//		// swap!
//		newSolution.setCity(pos1, cityToSwap2);
//		newSolution.setCity(pos2, cityToSwap1);
//
//		// energies of solutions
//		const auto currentEnergy = currentSolution.getDistance();
//		const auto neighborEnergy = newSolution.getDistance();
//
//		// accept the neighbor?
//		if (acceptanceProbability(currentEnergy, neighborEnergy, temperature) > std::rand() % 1)
//			currentSolution = newSolution;
//
//		// is it the best so far?
//		if (currentSolution.getDistance() < best.getDistance())
//			best = currentSolution;
//
//		temperature *= 1 - coolingRate;
//	}
//
//	std::cout << "Final solution distance: " << best.getDistance() << '\n';
//	std::cout << "Tour: " << best << '\n';
//
//	std::cin.get();
//}