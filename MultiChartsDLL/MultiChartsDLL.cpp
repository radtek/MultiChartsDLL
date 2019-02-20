// MultiChartsDLL.cpp : Defines the exported functions for the DLL application.
//

#include "Python.h"
#include "stdafx.h"
#include "MultiChartsDLL.h"
#include <pyhelper.hpp>

MultiCharts::MultiCharts()
{

}

MultiCharts::~MultiCharts()
{
	delete trainingData;
	delete dateArray;
	delete fileName;
	delete volumeArray;

	trainingData = NULL;
	dateArray = NULL;
	fileName = NULL;
	volumeArray = NULL;
}

/*

		--Member Functions--
char* MultiCharts::GetPythonStringData()
{
	CPyInstance hInstance;

	//CPyObject pName = PyUnicode_FromString("build");
	CPyObject pModule = PyImport_ImportModule("build");
	if (pModule)
	{
		CPyObject pFunc = PyObject_GetAttrString(pModule, "getRandomText");
		if (pFunc)
		{
			CPyObject pValue = PyObject_CallObject(pFunc, NULL);
			pythonStringData = PyUnicode_AsUTF8(pValue);
			return pythonStringData;
		}
		else 
		{
			pythonStringData = new char[4] {"101"};
			return pythonStringData;
		}
	}
	else
	{
		pythonStringData = new char[4] {"102"};
		return pythonStringData;
	}
}
*/

void MultiCharts::InitTrainingData(int size)
{
	this->trainingDataSize = size;
}

void MultiCharts::SetTrainingData(double* trainingData)
{
	this->trainingData = trainingData;
}

void MultiCharts::InitDateArray(int size)
{
	this->dateArray = new char[size][DATE_SIZE];
}

void MultiCharts::SetDateArray(char (*dateArray)[DATE_SIZE])
{
	this->dateArray = dateArray;
}

void MultiCharts::InitVolumeArray(int size)
{
	this->volumeArray = new long[size];
}

void MultiCharts::SetVolumeArray(long* volume)
{
	this->volumeArray = volume;
}

void MultiCharts::InitFileName(int size)
{
	this->fileName = new char[size];
}

void MultiCharts::SetFileName(char* fileName)
{
	this->fileName = fileName;
}

/*

		-- Exported Functions -- 

*/

MultiCharts* CreateMultiCharts()
{
	return new MultiCharts();
}

void DisposeMultiCharts(MultiCharts* multiCharts)
{
	if (multiCharts != NULL)
	{
		delete multiCharts;
		multiCharts = NULL;
	}
}

void SetTrainingData(MultiCharts* multiCharts, double* trainingData)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetTrainingData(trainingData);
	}
}
