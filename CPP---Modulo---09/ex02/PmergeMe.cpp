#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

double PmergeMe::getCurrentTimeMicros()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

template<typename T>
void PmergeMe::sortSmallRange(T &container, size_t left, size_t right)
{
	for (size_t i = left + 1; i <= right; i++) {
		typename T::value_type key = container[i];
		int j = i - 1;
		while (j >= static_cast<int>(left) && container[j] > key) {
			container[j + 1] = container[j];
			j--;
		}
		container[j + 1] = key;
	}
}

template<typename T>
void PmergeMe::mergeSubarrays(T &container, size_t left, size_t mid, size_t right)
{
	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;

	T L(container.begin() + left, container.begin() + mid + 1);
	T R(container.begin() + mid + 1, container.begin() + right + 1);

	size_t i = 0, j = 0, k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			container[k] = L[i];
			i++;
		}
		else
		{
			container[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		container[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		container[k] = R[j];
		j++;
		k++;
	}
}

template<typename T>
void PmergeMe::fordJohnsonSort(T &container, size_t left, size_t right)
{
	if (right - left <= 10)
	{
		sortSmallRange(container, left, right);
		return ;
	}

	size_t mid = left + (right - left) / 2;
	fordJohnsonSort(container, left, mid);
	fordJohnsonSort(container, mid + 1, right);
	mergeSubarrays(container, left, mid, right);
}

bool PmergeMe::isValidPositiveNumber(const std::string &str)
{
	if (str.empty())
		return false;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

void PmergeMe::printSequence(const std::string &prefix, const std::vector<int> &container)
{
	std::cout << prefix;
	for(size_t i = 0; i < container.size(); i++) {
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::processArguments(int argc, char *argv[])
{
	if (argc < 2)
		throw std::runtime_error("Error: No input provided");


	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		if (!isValidPositiveNumber(arg))
			throw std::runtime_error("Error: Invalid input");

		int n = std::atoi(arg.c_str());
		vec.push_back(n);
		deq.push_back(n);
	}


	printSequence("Before: ", vec);

	double startVec = getCurrentTimeMicros();
	fordJohnsonSort(vec, 0, vec.size() - 1);
	double timeVec = getCurrentTimeMicros() - startVec;

	double startDeq = getCurrentTimeMicros();
	fordJohnsonSort(deq, 0, deq.size() - 1);
	double timeDeq = getCurrentTimeMicros() - startDeq;

	printSequence("After: ", vec);

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vec.size()
			  << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
			  << " elements with std::deque : " << timeDeq << " us" << std::endl;
}
