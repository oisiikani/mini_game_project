#pragma once

#include <stdio.h>
#include "DxLib.h"
#include "../Common.h"

class Result
{
public:
	Result();
	~Result();
	void InitResult();
	void StepResult();
	void DrawResult();
	void FinResult();
private:

	int ResultHndl;

};

