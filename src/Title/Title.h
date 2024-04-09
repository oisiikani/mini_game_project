#pragma once
#include <stdio.h>
#include "DxLib.h"
#include "../Common.h"

class Title
{
public:
	Title();
	~Title();
	void InitTitle();
	void StepTitle();
	void DrawTitle();
	void FinTitle();
private:

	int TitleHndl;

};