#pragma once 

#include <iostream>
#include <mutex>
#include <memory>
#include <vector>
#include <optional>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <SFML/System/Vector3.hpp>
#include <SFML/System/Vector2.hpp>
#include <shared_mutex>


/*
class ConfigInterface
{
protected:

};

//template <typename... Ts>
class Config
{
protected:
	// path to the file where DataStorage data was received from 
	std::optional<std::string> _filePath;

	// 
	// NOTE! Derived class have to declare own _values 
	// 
	// tuple holds vectors for each providen template with string key and value
	//std::tuple<std::vector<std::pair<std::string, Ts>>...> _values;
	
	// tuple holds pairs of mutex and corresponding type to support multithreading
	// for each providen template 
	//std::tuple<std::pair<std::shared_ptr<std::mutex>, Ts>...> _mutexes;

	// only one mutex for every vector
	std::mutex _mutex;

	Config(std::string filePath)
	{
		_filePath = filePath;
	}

public:
	Config(ConfigTypes configTypes)
	{
		_filePath = std::nullopt;
		_values = configTypes;
	}
	

	template <typename T>
	bool set(std::string key, T value)
	{
		auto& Tvalues = std::get < std::vector<std::pair<std::string, T>>>(_values);

		std::lock_guard lock(_mutex);

		for (auto TvaluesIterator : Tvalues)
		{
			if (TvaluesIterator.first == key)
			{
				TvaluesIterator.second = value;
				return true;
			}
		}

		// if value does not exist, create one
		std::get < std::vector<std::pair<std::string, T>>>(_values).push_back(std::make_pair(key, value));
		return false;
	}

	template <typename T>
	std::optional<T> get(std::string key) const
	{
		auto& Tvalues = std::get < std::vector<std::pair<std::string, T>>>(_values);

		std::lock_guard lock(_mutex);

		for (auto TvaluesIterator : Tvalues)
		{
			if (TvaluesIterator.first == key)
			{
				return TvaluesIterator.second;
			}
		}

		return std::nullopt;
	}
};
*/

class Config
{
private:
	class AbstractConfigStorage
	{
	protected:

	public:
		AbstractConfigStorage() = default;
		~AbstractConfigStorage() = default;
	};

	template <typename T>
	struct ConfigStorage : public AbstractConfigStorage
	{
	private:
		mutable std::shared_mutex _mutex;
		std::unique_ptr<std::vector<std::pair<std::string, T>>> _Tvalues;

	public:
		ConfigStorage()
		{
			_Tvalues = std::make_unique<std::vector<std::pair<std::string, T>>>(std::vector<std::pair<std::string, T>>());
		}
		ConfigStorage(ConfigStorage<T>& configStorage)
		{
			_Tvalues = std::move(_Tvalues);
		}

		void set(std::string& key, T value)
		{
			std::unique_lock lock(_mutex);


			for (auto it = _Tvalues->begin(); it != _Tvalues->end(); it++)
			{
				if (it->first == key)
				{
					it->second = std::move(value);
					return;
				}
			}

			_Tvalues->push_back(std::make_pair(key, std::move(value)));
			return;
		}

		std::optional<T> get(std::string key)
		{
			std::shared_lock lock(_mutex);

			for (auto it = _Tvalues->begin(); it != _Tvalues->end(); it++)
			{
				if (it->first == key)
				{
					return it->second;
				}
			}
			return std::nullopt;
		}
	};
	mutable std::shared_mutex _mutex;
	std::unordered_map < std::type_index, std::unique_ptr<AbstractConfigStorage>> _storages;

public:
	template <typename T>
	bool registerType()
	{
		std::type_index typeIndex = typeid(T);
		std::unique_lock lock(_mutex);

		if (_storages.count(typeIndex) > 0)
		{
			return false;
		}

		_storages[typeIndex] = std::make_unique<ConfigStorage<T>>(ConfigStorage<T>());
		return true;
	}

	template <typename T>
	bool set(std::string key, T value)
	{
		std::type_index typeIndex = typeid(T);
		std::unique_lock lock(_mutex);

		if (_storages.count(typeIndex) > 0)
		{
			return false;
		}

		ConfigStorage<T>* Tstorage = static_cast<ConfigStorage<T>*>(_storages[typeIndex].get());
		Tstorage->set(key, value);
		return true;
	}

	template <typename T>
	std::optional<T> get(std::string key) const
	{
		std::type_index typeIndex = typeid(T);
		std::unique_lock lock(_mutex);

		if (_storages.count(registerType) > 0)
		{
			return std::nullopt;
		}

		ConfigStorage<T>* Tstorage = static_cast<ConfigStorage<T>*>(_storages[typeIndex].get());
		return Tstorage->get(key);
	}
};