//   GreKo chess engine
//   (c) 2002-2021 Vladimir Medvedev <vrm@bk.ru>
//   http://greko.su

#ifndef UTILS_H
#define UTILS_H

#include "types.h"

string CurrentDateStr();
U64    GetProcTime();
void   Highlight(bool on);
void   InitIO();
bool   InputAvailable();
bool   IsPipe();
bool   Is(const string& cmd, const string& pattern, size_t minLen);
U32    Rand32();
U64    Rand64();
U64    Rand64(int bits);
double RandDouble();
void   RandSeed(U64 seed);
void   SleepMillisec(int msec);
void   Split(const string& s, vector<string>& tokens, const string& sep = " ");
string Timestamp();

extern FILE* g_log;

inline void Log(const char* str)
{
	if (g_log == NULL) return;
	fprintf(g_log, "%s ", Timestamp().c_str());
	fprintf(g_log, "%s", str);
	fflush(g_log);
}

inline void Out(const char* str)
{
	printf("%s", str);
	fflush(stdout);

	if (g_log == NULL) return;
	fprintf(g_log, "%s < ", Timestamp().c_str());
	fprintf(g_log, "%s", str);
	fflush(g_log);
}

template<class... Args>
void Log(const char* fmt, Args... args)
{
	if (g_log == NULL) return;
	fprintf(g_log, "%s ", Timestamp().c_str());
	fprintf(g_log, fmt, args...);
	fflush(g_log);
}

template<class... Args>
void Out(const char* fmt, Args... args)
{
	printf(fmt, args...);
	fflush(stdout);

	if (g_log == NULL) return;
	fprintf(g_log, "%s < ", Timestamp().c_str());
	fprintf(g_log, fmt, args...);
	fflush(g_log);
}

#endif
