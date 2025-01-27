#pragma once
#include "Macro.h"

static u_int GetUniqueID()
{
	static u_int _id = 0;
	return ++_id;
}

FORCEINLINE string GetCurrentRealTime()
{
	const time_t& _now = std::time(0);

	tm _ltm;
	localtime_s(&_ltm, &_now);

	const string& _date = to_string(_ltm.tm_mday) + "/" + to_string(1 + _ltm.tm_mon) + "/" + to_string(1900 + _ltm.tm_year);
	const string& _time = to_string(_ltm.tm_hour) + ":" + to_string(_ltm.tm_min) + ":" + to_string(_ltm.tm_sec);

	return "[" + _date + "] <" + _time + "> ";
}