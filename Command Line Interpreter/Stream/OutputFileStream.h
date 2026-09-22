#ifndef OUTPUTFILESTREAM_H
#define OUTPUTFILESTREAM_H
#include "FileStream.h"
#include <fstream>

class OutputFileStream : public FileStream {
public:

	OutputFileStream(const std::string& fileargument, std::string simbol, Command* comm);

	~OutputFileStream();

	virtual void print(const std::string& line);

	virtual std::string read();

private:

	std::ofstream* file;

	std::string simbol;

	std::string outputline;


};

inline std::string OutputFileStream::read() {
	return "";
};

#endif