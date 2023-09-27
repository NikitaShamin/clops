#include "ClusterFunctions.h"
#include <algorithm>

double add_cost(const Cluster& c, const std::vector<std::string>& transaction, double r) 
{
	int Sn = c.S + transaction.size();
	int Nn = c.N + 1;
	int Wn = c.W;

	for (const std::string& element : transaction) 
	{
		if (!c.check_element(element)) Wn++;
	}

	if (c.W == 0) return static_cast<double>(Sn * Nn) / pow(Wn, r);

	return (Sn * Nn) / pow(Wn, r) - (c.S * c.N) / pow(c.W, r);
}

double remove_cost(const Cluster& cluster, const std::vector<std::string>& transaction, double r) 
{
	int Sn = cluster.S - transaction.size();
	int Nn = cluster.N - 1;
	int Wn = cluster.W;

	for (const std::string& element : transaction) 
	{
		if (cluster.freqDiagram.count(element) != 0 && cluster.freqDiagram.at(element) == transaction.size()) Wn--;
	}

	if (cluster.W == 0) return static_cast<double>(Sn * Nn) / pow(Wn, r);
	
	if (Wn == 0) return -(cluster.S * cluster.N) / pow(cluster.W, r);
	

	return (Sn * Nn) / pow(Wn, r) - (cluster.S * cluster.N) / pow(cluster.W, r);
}

void move_transaction(const std::vector<std::string>& transaction, Cluster& c, int index) 
{
	c.add(transaction, index);
}

void replace_transaction(const std::vector<std::string>& t, Cluster& sc, Cluster& dc, int index) 
{
	dc.add(t, index);
	sc.delete_transaction(t, index);
}
