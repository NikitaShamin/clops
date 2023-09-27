#pragma once

#include "Cluster.h"
#include <vector>

// ������������ ��������� ���������� ���������� � ��������.
// ���������:
// - c: �������, � �������� ����������� ����������.
// - transaction: ������ �����, �������������� ����������.
// - r: ��������, �������� �� ���������.
// ����������: ������������ ��������� ���������� ���������� � ��������.
double add_cost(const Cluster& c, const std::vector<std::string>& transaction, double r);

// ������������ ��������� �������� ���������� �� ��������.
// ���������:
// - cluster: �������, �� �������� ��������� ����������.
// - transaction: ������ �����, �������������� ����������.
// - r: ��������, �������� �� ���������.
// ����������: ������������ ��������� �������� ���������� �� ��������.
double remove_cost(const Cluster& cluster, const std::vector<std::string>& transaction, double r);

// ���������� ���������� � ��������� �������.
// ���������:
// - transaction: ������ �����, �������������� ����������.
// - c: �������, � ������� ������������ ����������.
// - index: ������ ����������.
void move_transaction(const std::vector<std::string>& transaction, Cluster& c, int index);

// �������� ���������� � ����� �������� �� ������ ���������� � ������ ��������.
// ���������:
// - t: ������ �����, �������������� ���������� ��� ������.
// - sc: �������, �� �������� ��������� ����������.
// - dc: �������, � ������� ������������ ����������.
// - index: ������ ���������� ��� ������.
void replace_transaction(const std::vector<std::string>& t, Cluster& sc, Cluster& dc, int index);
