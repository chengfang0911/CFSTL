// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once    


#include <stdio.h>
#include <tchar.h>
#include <wtypes.h>
#include <memory>

using namespace std;


class CGraph
{
public:
	CGraph();
	~CGraph();
	void Init();
	void Clear();
	bool Empty();
	void DFS();//deep first search
	void WFS();//wide first search
};

// TODO: reference additional headers your program requires here
