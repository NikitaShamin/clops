#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

class Cluster
{
public:
	Cluster();

	// Добавляет транзакцию и обновляет данные кластера.
	// Параметры:
	// - transaction: Вектор строк, представляющих транзакцию.
	// - i: Индекс транзакции.
	void add(const std::vector<std::string>& transaction, int i);

	// Проверяет, содержит ли кластер указанный элемент.
	// Параметры:
	// - element: Элемент для проверки.
	// Возвращает: true, если элемент содержится в кластере, иначе false.
	bool check_element(const std::string& element) const;

	// Проверяет, содержит ли кластер указанную транзакцию.
	// Параметры:
	// - transactionIndex: Индекс транзакции для проверки.
	// Возвращает: true, если транзакция содержится в кластере, иначе false.
	bool check_transaction(int transactionIndex) const;

	// Добавляет частоту элементов из транзакции к частотной диаграмме кластера.
	// Параметры:
	// - transact: Вектор строк, представляющих транзакцию.
	void add_freq(const std::vector<std::string>& transact);

	// Удаляет транзакцию из кластера и обновляет данные.
	// Параметры:
	// - transaction: Вектор строк, представляющих транзакцию.
	// - index: Индекс удаляемой транзакции.
	void delete_transaction(const std::vector<std::string>& transaction, int index);

	// Переменные для хранения частотной диаграммы, индексов транзакций и других данных кластера.
	std::unordered_map<std::string, int> freqDiagram;
	std::unordered_set<int> transactionSet;
	int N;
	int S;
	int W;
};