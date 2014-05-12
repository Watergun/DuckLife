#include "CMap.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include "InfoMessage.h"

CMap::CMap()
{
	m_pSurroundings = NULL;
}

CMap::~CMap()
{
	if(m_pSurroundings != NULL)
		delete[] m_pSurroundings;
	m_pSurroundings = NULL;
}

CSurrounding* CMap::getSurroundings()
{
	return m_pSurroundings;
}

CSurrounding* CMap::getSurroundingObject(int nIndex)
{
	if(m_pSurroundings == NULL)
		REP_ERR("CMap.cpp","CMap","getSurroundingObject(int nIndex)","m_pSurroundings is NULL");
	else if(nIndex >= m_nSize)
		REP_ERR("CMap.cpp","CMap","getSurroundingObject(int nIndex)","nIndex is out of range");
	else
		return &(m_pSurroundings[nIndex]);
	return NULL;
}

bool CMap::LoadSurroundings(const char* cstrFilename)
{
	 /*FILE FORMAT:

        OBJECT_NAME MODEL_FILE POSITION_X POSITION_Y

        */

	if(cstrFilename == NULL)
	{
		REP_ERR("CMap.cpp","CMap","LoadSurroundings(const char* cstrFilename)","cstrFilename is NULL");
		return false;
	}

	std::ifstream fi(cstrFilename);
	if(!fi)
	{
		REP_ERR("CMap.cpp","CMap","LoadSurroundings(const char* cstrFilename)",
			stradd(cstrFilename," cannot be opened!"));
		return false;
	}

	fi.seekg(0, fi.end);
	int size = fi.tellg();
	fi.seekg(0, fi.beg);

	std::vector<char*> lines;
	int nextline = 0;

	while(fi.tellg() < size)
	{
		int newline = 0;
		int currentpos = nextline;
		fi.seekg(currentpos, fi.beg);

		while(fi.tellg() < size)
		{
			if(fi.peek() == 10)
			{
				newline = fi.tellg();
				nextline = newline+1;
				break;
			}
			if(fi.peek() == 13)
			{
				newline = fi.tellg();
				nextline = newline+2;
				break;
			}
			fi.seekg(1, fi.cur);
		}
		fi.seekg(currentpos, fi.beg);

		//If it is just one line, the end is the size
		if(newline == 0)
			newline = size;

		//Reading one line
		int line_length = newline - currentpos;
		char* buffer = new char[line_length+1];
		fi.read(buffer, line_length);

		//Infoing it out
		INFO_MSG("Loading surrounding",buffer);

		//Put it into an array
		buffer[line_length] = 0;
		//char cstr[line_length];
		//strcpy(cstr,);
		lines.push_back(buffer);

		fi.seekg(1,fi.cur);
	}
	//###
	if(m_pSurroundings != NULL)
		delete[] m_pSurroundings;
	m_pSurroundings = new CSurrounding[lines.size()];
	//###
	for(unsigned int i = 0; i < lines.size(); i++)
	{
		unsigned int space = 0;
		unsigned int start = 0;
		char* items[4];
		for(int j = 0; j < 4; j++)
		{
			while(space < strlen(lines[i]))
			{
				if(lines[i][space] == (char)32 || lines[i][space] == '\0')
					break;
				space++;
			}
			items[j] = substr(lines[i],start,space);
			space++;
			start = space;
		}

		if(items[0] == NULL || items[1] == NULL || items[2] == NULL || items[3] == NULL)
		{
			REP_ERR("CMap.h","CMap","LoadSurroundings(char* cstrFilename)",
			stradd("Invalid file format in file: ",cstrFilename));
			return false;
		}

		//Set the name ("tree")
		m_pSurroundings[i].m_cstrName = items[0];
		//Create a new model from the specified file
		m_pSurroundings[i].m_pModel = new CModel(items[1]);
		//Set the coordinates
		m_pSurroundings[i].setPosition(atof(items[2]), atof(items[3]));
	}
	for(unsigned int i = 0; i == lines.size(); i++)
		delete[] lines[i];

	return true;
}
