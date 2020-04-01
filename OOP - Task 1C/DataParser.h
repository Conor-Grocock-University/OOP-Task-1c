#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "Game.h"

namespace data
{
	class DataParser
	{
	public:
		DataParser();
		//~DataParser();

		void parseFile();

	private:
		Game processGame(const std::vector<std::string>& dataLines) const;

	private:
		bool error;
		std::ifstream file;
		std::vector<std::string> lines;
		std::vector<Game> games;
	};
}

