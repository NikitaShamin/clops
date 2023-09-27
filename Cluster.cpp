#include "Cluster.h"
#include <cmath>

Cluster::Cluster() : N(0), S(0), W(0) {}

void Cluster::add(const std::vector<std::string>& transaction, int index) 
{
	add_freq(transaction);
	transactionSet.insert(index);

	N++; S += transaction.size(); W = freqDiagram.size();
}

bool Cluster::check_element(const std::string& element) const
{
	return freqDiagram.count(element) > 0;
}

bool Cluster::check_transaction(int transactionIndex) const 
{
	return transactionSet.count(transactionIndex) > 0;
}

void Cluster::add_freq(const std::vector<std::string>& transact) 
{
	for (const std::string& element : transact) freqDiagram[element]++;
}

void Cluster::delete_transaction(const std::vector<std::string>& transaction, int index) 
{
	for (const std::string& element : transaction) freqDiagram[element] -= transaction.size();
	
	transactionSet.erase(index); 
	N--; S -= transaction.size(); W -= freqDiagram.size();
}
