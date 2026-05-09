#pragma once 

#include <iostream>
#include <mutex>
#include <memory>
#include <vector>
#include <optional>
#include <SFML/System/Vector3.hpp>
#include <SFML/System/Vector2.hpp>


class SessionManager
{
private:
	Session* _currentSession;
	
public:
	SessionManager()
	{
		_currentSession = nullptr;
	}


};

class Session
{
private:
	std::string _name;
	std::optional<std::string> _saveFilePath;

	// different container for different types, makes more optimized search 
	// also containers can be used in parallel 
	std::vector<std::pair<std::string, std::string>> _valuesString;
	std::vector<std::pair<std::string, sf::Vector3f>> _valuesVector3;
	std::vector<std::pair<std::string, sf::Vector2f>> _valuesVector2;
	std::vector<std::pair<std::string, float>> _valuesFloat;
	std::vector<std::pair<std::string, int>> _valuesInt;
	std::vector<std::pair<std::string, bool>> _valuesBool;

	// mutex ensures that session can be used in multiple threads
	// multiple mutexes allow 2 threads to write and read different containers at the same time
	std::mutex _mutexString;
	std::mutex _mutexVector3;
	std::mutex _mutexVector2;
	std::mutex _mutexFloat;
	std::mutex _mutexInt;
	std::mutex _mutexBool;

public:
	Session()
	{
		_name = "New game";
		_saveFilePath = std::nullopt;
	}

	bool setString(std::string key, std::string value)
	{
		std::lock_guard lock(_mutexString);
		for (auto it = _valuesString.begin(); it != _valuesString.end(); it++)
		{
			// element is found, exit the loop
			if (it->first == key)
			{
				it->second = value;
				return true;
			}
		}
		// element is not found, create a new one
		_valuesString.push_back(std::make_pair(key, value));
		return true;
	}
	bool setVector3(std::string key, sf::Vector3f value)
	{
		std::lock_guard lock(_mutexVector3);
		for (auto it = _valuesVector3.begin(); it != _valuesVector3.end(); it++)
		{
			// element is found, exit the loop
			if (it->first == key)
			{
				it->second = value;
				return true;
			}
		}
		// element is not found, create a new one
		_valuesVector3.push_back(std::make_pair(key, value));
		return true;
	}
	bool setVector2(std::string key, sf::Vector2f value)
	{
		std::lock_guard lock(_mutexVector2);
		for (auto it = _valuesVector2.begin(); it != _valuesVector2.end(); it++)
		{
			// element is found, exit the loop
			if (it->first == key)
			{
				it->second = value;
				return true;
			}
		}
		// element is not found, create a new one
		_valuesVector2.push_back(std::make_pair(key, value));
		return true;
	}
	bool setFloat(std::string key, float value)
	{
		std::lock_guard lock(_mutexFloat);
		for (auto it = _valuesFloat.begin(); it != _valuesFloat.end(); it++)
		{
			// element is found, exit the loop
			if (it->first == key)
			{
				it->second = value;
				return true;
			}
		}
		// element is not found, create a new one
		_valuesFloat.push_back(std::make_pair(key, value));
		return true;
	}
	bool setInt(std::string key, int value)
	{
		std::lock_guard lock(_mutexInt);
		for (auto it = _valuesInt.begin(); it != _valuesInt.end(); it++)
		{
			// element is found, exit the loop
			if (it->first == key)
			{
				it->second = value;
				return true;
			}
		}
		// element is not found, create a new one
		_valuesInt.push_back(std::make_pair(key, value));
		return true;
	}
	bool setBool(std::string key, bool value)
	{
		std::lock_guard lock(_mutexBool);
		for (auto it = _valuesBool.begin(); it != _valuesBool.end(); it++)
		{
			// element is found, exit the loop
			if (it->first == key)
			{
				it->second = value;
				return true;
			}
		}
		// element is not found, create a new one
		_valuesBool.push_back(std::make_pair(key, value));
		return true;
	}

	// getters //
	std::optional<std::string> getString(std::string key)
	{
		std::lock_guard lock(_mutexString);
		for (auto it = _valuesString.begin(); it != _valuesString.end(); it++)
		{
			// element is found, exit the loop
			if (it->first == key)
			{
				return it->second;
			}
		}
		return std::nullopt;
	}
	std::optional<sf::Vector3f> getVector3(std::string key)
	{
		std::lock_guard lock(_mutexVector3);
		for (auto it = _valuesVector3.begin(); it != _valuesVector3.end(); it++)
		{
			// element is found, exit the loop
			if (it->first == key)
			{
				return it->second;
			}
		}
		return std::nullopt;
	}
	std::optional<sf::Vector2f> getVector2(std::string key)
	{
		std::lock_guard lock(_mutexVector2);
		for (auto it = _valuesVector2.begin(); it != _valuesVector2.end(); it++)
		{
			// element is found, exit the loop
			if (it->first == key)
			{
				return it->second;
			}
		}
		return std::nullopt;
	}
	std::optional<float> getFloat(std::string key)
	{
		std::lock_guard lock(_mutexFloat);
		for (auto it = _valuesFloat.begin(); it != _valuesFloat.end(); it++)
		{
			// element is found, exit the loop
			if (it->first == key)
			{
				return it->second;
			}
		}
		return std::nullopt;
	}
	std::optional<int> getInt(std::string key)
	{
		std::lock_guard lock(_mutexInt);
		for (auto it = _valuesInt.begin(); it != _valuesInt.end(); it++)
		{
			// element is found, exit the loop
			if (it->first == key)
			{
				return it->second;
			}
		}
		return std::nullopt;
	}
	std::optional<bool> getBool(std::string key)
	{
		std::lock_guard lock(_mutexBool);
		for (auto it = _valuesBool.begin(); it != _valuesBool.end(); it++)
		{
			// element is found, exit the loop
			if (it->first == key)
			{
				return it->second;
			}
		}
		return std::nullopt;
	}
};