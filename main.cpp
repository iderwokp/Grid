#include <iostream>
#include "stdafx.h"
//#include "Grid.h"
//#include "Rute.h"
#include "Tboard.h"

int main() {
	//	Grid<int> g3(3);
	//	for(auto& r: g3) {
	//		for(auto& p: r.data())
	//			cout << p.first << ", " << p.second << "   ";
	//		cout << endl;
	//	}

	//Editert 29.04.2017 for testens skyld

//	Grid<std::string> g(4, 3); //4x3
//
//	std::string gml1 = g.setElement(0, 0, "hundre");
//	std::string gml2 = g.setElement(0, 0, "hundre og en");
//	std::string gml3 = g.setElement(2, 1, "hundre og tjueen");
//	
//	std::cout << "gammel verdi i 0,0 er " << gml1 << " og ny verdi er " << g.getElement(0, 0) << std::endl;
//	std::cout << "gammel verdi i 0,0 er " << gml2 << " og ny verdi er " << g.getElement(0, 0) << std::endl;
//	std::cout << "gammel verdi i 2,1 er " << gml3 << " og ny verdi er " << g.getElement(2, 1) << std::endl;
	std::cout << "Tboard tb(3)\n";
	Tboard tb(3);
	std::cout << "tb.fill();\n";
	tb.fill();
	std::cout << "std::cout << tb;\n";
	Tboard tb2{tb};
	std::cout << tb << std::endl;
	tb.set_val(0, 0, Rute_verdi::Kryss);
	tb.set_val(1, 1, Rute_verdi::Kryss);
	tb.set_val(2, 2, Rute_verdi::Kryss);
	std::cout << tb << std::endl;
	std::cout << tb2 << std::endl;
	tb = tb2;
	std::cout << "tb = tb2\n" << tb << std::endl;
	
	return 0;

}
