#pragma once
#include "Macro.h"
#include "Color.h"
#include "CustomException.h"

#pragma region Defines

#define LOG(_verbosity, _msg) Logger::PrintLog(_verbosity, _msg, DEBUG_INFO)
#define WRITE_IN_LOG(_verbosity)        _verbosity >= Log
#define WRITE_IN_CONSOLE(_verbosity)    _verbosity > Log

#pragma endregion

#ifdef DEBUG
    #define USE_DEBUG 1
#else
    #define USE_DEBUG 0
#endif

#ifdef TIME
    #define USE_TIME 1
#else
    #define USE_TIME 0
#endif

using namespace std;
using openMode = ios_base::openmode;

enum VerbosityType
{
    VeryVerbose,
    Verbose,
    Log,
    Display,
    Warning,
    Error,
    Fatal,

    VT_COUNT
};

struct VerbosityData
{
    string prefix;
    string color;
    string text;
    string debug; 
    bool useDebug;
    bool useTime;

private:
    FORCEINLINE string GetPrefix() const
    {
        return prefix;
    }

public:
    VerbosityData(const VerbosityType& _type, const string& _text, const string& _debug, const bool _displayDebug = false, const bool _useTime = false)
    {
        ComputeUseDebug(_type);
        ComputePrefix(_type);
        ComputeColor(_type);
        ComputeUseTime(_type);
        text = _text;
        debug = _debug;
    }

private:
    void ComputePrefix(const VerbosityType& _type)
    {
        if (_type >= VT_COUNT)
        {
            throw CustomException("Exception => invalid VerbosityType");
        }

        const vector<string>& _verbosityTexts =
        {
            "VeryVerbose",
            "Verbose",
            "Log",
            "Display",
            "Warning",
            "Error",
            "Fatal",
        };

        prefix = _verbosityTexts[_type];
    }
    void ComputeColor(const VerbosityType& _type)
    {
        if (_type == VT_COUNT)
        {
            throw CustomException("Exception => invalid VerbosityType");
        }

        const vector<string>& _verbosityColors =
        {
            WHITE,
            WHITE,
            GRAY,
            BLACK_INTENSE_TEXT,
            YELLOW,
            RED,
            DARK_RED,
        };

        color = _verbosityColors[_type];
    }
    void ComputeUseDebug(const VerbosityType& _type)
    {
        useDebug = set<VerbosityType>({ Warning, Error }).contains(_type);
    }
    void ComputeUseTime(const VerbosityType& _type)
    {
        useTime = set<VerbosityType>({ Warning, Error, Log }).contains(_type);
    }

public:
    string RetrieveFullText(const bool _useColor = true, const bool _useTime = true) const;
};

class Logger
{
    static string logsPath;

private:
    static void WriteInConsole(const string& _text);
    static void WriteInLogs(const string& _text);

public:
    static void Reset();
    static void PrintLog(const VerbosityType& _type, const string& _text, const string& _debug = "");
};