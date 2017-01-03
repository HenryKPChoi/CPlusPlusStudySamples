// testPolicy.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>

class Formatter
{
public:
	Formatter (const std::string& s):
	  _s(s)
	{}

	virtual std::string GetFormattedResult() = 0;

protected:
	std::string _s;
};

class HtmlFormatter : public Formatter
{
public:
	explicit HtmlFormatter(const std::string& s):
		Formatter(s)
	{}

	std::string GetFormattedResult()
	{
		return std::string("<html><title>Error Page</title><body>" + _s + "</body></html>") ;
	}
};

class PlainTextFormatter : public Formatter
{
public:
	explicit PlainTextFormatter(const std::string& s):
		Formatter(s)
	{
	}
	std::string GetFormattedResult()
	{
		return std::string("PlainText formatted:[" + _s + "]") ;
	}
};

template <typename FormatPolicy>
class FormatterT : private FormatPolicy
{
public:
	FormatterT(const std::string& s):
	  _s(s)
	{
	}
	std::string GetFormattedResult()
	{
		return format(_s);
	}
private:
	std::string _s;
};

class HtmlFormatPolicy
{
public:
	std::string format(const std::string& s) 
	{
		return std::string("<html><title>Error Page</title><body>" + s + "</body></html>") ;
	}
};

class PlainTextFormatPolicy
{
public:
	std::string format(const std::string& s) 
	{
		return std::string("PlainText formatted:[" + s + "]") ;
	}
};


int main(int argc, char* argv[])
{
	std::string err = "error"; 

	HtmlFormatter htmlFormatter(err);
	std::cout << htmlFormatter.GetFormattedResult() << std::endl;
	PlainTextFormatter plainTextFormatter(err);
	std::cout << plainTextFormatter.GetFormattedResult() << std::endl;

	FormatterT<HtmlFormatPolicy> htmlFormatterT(err);
	std::cout << htmlFormatterT.GetFormattedResult() << std::endl;
	FormatterT<PlainTextFormatPolicy> plainTextFormatterT(err);
	std::cout << plainTextFormatterT.GetFormattedResult() << std::endl;
	return 0;
}

