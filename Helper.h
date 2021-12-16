#pragma once
#include "Keeper.h"
#include "IP_manager.h"
#include <string>
#include <iostream>
#include "expt.h"

class Helper {
protected:
	Keeper<IP_man> _IP;
	
public:
	
	Keeper<IP_man>&IP() { return _IP; }

};