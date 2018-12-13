#ifndef TIC_TAC_TOE_PEG_H
#define TIC_TAC_TOE_PEG_H

#include <string>

class Peg
{
public:
	Peg(std::string v) : val(v) {}
	Peg() { val = " "; }
	std::string val;
};

#endif // !TIC_TAC_TOE_PEG_H