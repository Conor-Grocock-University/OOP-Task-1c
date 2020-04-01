#include "DataParser.h"



namespace data
{

	DataParser::DataParser()
	{		
	    file.open("data.txt");
		error = !file.is_open();
		
	    if (file.is_open()) {
	        std::string line;
	        while (getline(file, line)) {
	            lines.emplace_back(line.c_str());
	        }
	    }
	}

	/*DataParser::~DataParser()
	{
		if(file.is_open())
			file.close();
	}*/

	void DataParser::parseFile()
	{
		if (error) return;
		
		for (int i = 0; i < lines.size(); ++i)
		{
			std::string line = lines[i];
			if (line == "GAME")
				games.push_back(processGame(std::vector<std::string>(lines.begin() + i, lines.begin() + i + 5)));
		}
	}

	Game DataParser::processGame(const std::vector<std::string>& dataLines) const
	{
		// 0 - Cat
		// 1 - ID
		// 2 - Name
		// 3 - Description
		// 4 - ???
		// 5 - Price

		int id = std::stoi(dataLines[1]);
		return Game(dataLines[2], dataLines[3], std::stoi(dataLines[4]), std::stoi(dataLines[5]));
	}
}
