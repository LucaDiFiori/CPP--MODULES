#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int> deq;

		template<typename T>
		void fordJohnsonSort(T &container, size_t left, size_t right);

		template<typename T>
		void mergeSubarrays(T &container, size_t left, size_t mid, size_t right);

		template<typename T>
		void sortSmallRange(T &container, size_t left, size_t right);

		double getCurrentTimeMicros();
		void printSequence(const std::string &prefix, const std::vector<int> &cont);
		bool isValidPositiveNumber(const std::string &s);

	public:
		PmergeMe();
		~PmergeMe();

		void processArguments(int argc, char *argv[]);
};

#endif
