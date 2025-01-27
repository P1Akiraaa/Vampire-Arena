#pragma once
#include "Macro.h"

class CustomException : public exception
{
	using Error = char const*;

public:
	CustomException(const Error _error) : exception(_error)
	{

	}

private:
	NO_DISCARD virtual Error what() const
	{
		return (CAST(string, DEBUG_INFO) 
			  + CAST(string, SUPER::what())).c_str();
	}

public:
	NO_DISCARD virtual Error What() const
	{
		return what();
	}
};