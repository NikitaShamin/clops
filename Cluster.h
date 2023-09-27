#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

class Cluster
{
public:
	Cluster();

	// ��������� ���������� � ��������� ������ ��������.
	// ���������:
	// - transaction: ������ �����, �������������� ����������.
	// - i: ������ ����������.
	void add(const std::vector<std::string>& transaction, int i);

	// ���������, �������� �� ������� ��������� �������.
	// ���������:
	// - element: ������� ��� ��������.
	// ����������: true, ���� ������� ���������� � ��������, ����� false.
	bool check_element(const std::string& element) const;

	// ���������, �������� �� ������� ��������� ����������.
	// ���������:
	// - transactionIndex: ������ ���������� ��� ��������.
	// ����������: true, ���� ���������� ���������� � ��������, ����� false.
	bool check_transaction(int transactionIndex) const;

	// ��������� ������� ��������� �� ���������� � ��������� ��������� ��������.
	// ���������:
	// - transact: ������ �����, �������������� ����������.
	void add_freq(const std::vector<std::string>& transact);

	// ������� ���������� �� �������� � ��������� ������.
	// ���������:
	// - transaction: ������ �����, �������������� ����������.
	// - index: ������ ��������� ����������.
	void delete_transaction(const std::vector<std::string>& transaction, int index);

	// ���������� ��� �������� ��������� ���������, �������� ���������� � ������ ������ ��������.
	std::unordered_map<std::string, int> freqDiagram;
	std::unordered_set<int> transactionSet;
	int N;
	int S;
	int W;
};