#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Cluster.h"
#include "ClusterFunctions.h"

int main() 
{
	std::ifstream input_file("ms.txt");
	std::string line;
	std::vector<std::vector<std::string>> mushroom_transactions;

	bool clustering_moved = true;
	std::vector<Cluster> clusters(1);
	int transaction_index = 0;
	double r_value = 2.6;

	while (std::getline(input_file, line)) 
	{
		std::istringstream line_stream(line);
		std::string item;
		std::vector<std::string> transaction;
		while (std::getline(line_stream, item, ',')) 
		{
			transaction.push_back(item);
		}
		mushroom_transactions.push_back(transaction);
	}

	for (std::vector<std::string>& transaction : mushroom_transactions) 
	{
		transaction.erase(std::remove(transaction.begin(), transaction.end(), "?"), transaction.end());
	}

	for (const std::vector<std::string>& transaction : mushroom_transactions) 
	{
		double max_cost = 0.0;
		int best_cluster_choice = 0;

		for (int cluster_index = 0; cluster_index < clusters.size(); cluster_index++) 
		{
			double cost = add_cost(clusters[cluster_index], transaction, r_value);
			if (cost > max_cost) 
			{
				max_cost = cost;
				best_cluster_choice = cluster_index;
			}
		}

		if (clusters[best_cluster_choice].N == 0) clusters.emplace_back();

		move_transaction(transaction, clusters[best_cluster_choice], transaction_index);
		transaction_index++;
	}

	while (clustering_moved) 
	{
		transaction_index = 0;

		for (const std::vector<std::string>& transaction : mushroom_transactions) 
		{
			double max_cost = 0.0;
			int action_cluster = -1;
			if (transaction_index == clusters.size()) break;
			double removal_cost = remove_cost(clusters[transaction_index], transaction, r_value);

			for (int cluster_index = 0; cluster_index < clusters.size(); cluster_index++) 
			{
				if (cluster_index != transaction_index) 
				{
					double addition_cost = add_cost(clusters[cluster_index], transaction, r_value);
					if (addition_cost + removal_cost > max_cost)
					{
						max_cost = addition_cost + removal_cost;
						action_cluster = cluster_index;
					}
				}
			}

			clustering_moved = false;
			if (max_cost > 0) 
			{
				if (clusters[action_cluster].N == 0) 
				{
					clusters.emplace_back();
				}
				replace_transaction(transaction, clusters[transaction_index], clusters[action_cluster], transaction_index);
				clustering_moved = true;
			}
			transaction_index++;
		}
	}

	std::vector<std::unordered_map<std::string, int>> result(clusters.size(), { { "e", 0 }, { "p", 0 } });

	for (int cluster_index = 0; cluster_index < clusters.size(); ++cluster_index) 
	{
		const Cluster& cluster = clusters[cluster_index];
		for (int transaction_index : cluster.transactionSet) 
		{
			if (mushroom_transactions[transaction_index][0] == "e") 
			{
				result[cluster_index]["e"]++;
			}
			else 
			{
				result[cluster_index]["p"]++;
			}
		}
	}

	std::cout << "Clustering Results:" << std::endl;
	for (const auto& res : result) 
	{
		std::cout << "e: " << res.at("e") << ", p: " << res.at("p") << std::endl;
	}

	getchar();
	return 0;
}
