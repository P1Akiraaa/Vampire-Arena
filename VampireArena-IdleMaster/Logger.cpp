#include "Logger.h"
#include "Utilities.h"
//#include "TimerManager.h"

string VerbosityData::RetrieveFullText(const bool _useColor, const bool _useTime) const
{
	const string& _color = _useColor ? color : "";
	const string& _reset = _useColor ? RESET : "";
	string _fullText;

	if (_useTime)
	{
		_fullText = GetCurrentRealTime() + _fullText;
	}

	_fullText += _color + GetPrefix() + " " + _color + text;
	
	if (USE_DEBUG || useDebug)
	{
		_fullText += " " + debug;
	}

	_fullText += _reset;

	return _fullText;
}

string Logger::logsPath = "Logs/Log.txt";

void Logger::WriteInConsole(const string& _text)
{
	cout << _text << endl;
}

void Logger::WriteInLogs(const string& _text)
{
	ofstream _stream = ofstream(logsPath, ios_base::app);
	_stream << _text << "\n";
}

void Logger::Reset()
{
	ofstream(logsPath, ios_base::trunc);
}

void Logger::PrintLog(const VerbosityType& _type, const string& _text, const string& _debug)
{
	if (_type == Fatal)
	{
		assert(false, _text);
	}

	if (WRITE_IN_LOG(_type))
	{
		const VerbosityData& _verbosity = VerbosityData(_type, _text, _debug);
		WriteInLogs(_verbosity.RetrieveFullText(false));

		if (WRITE_IN_CONSOLE(_type))
		{
			WriteInConsole(_verbosity.RetrieveFullText(true));
		}
	}
}