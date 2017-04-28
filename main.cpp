#include <iostream>
#include "stdafx.h"
#include "Grid.h"

int main() {
	//	Grid<int> g3(3);
	//	for(auto& r: g3) {
	//		for(auto& p: r.data())
	//			cout << p.first << ", " << p.second << "   ";
	//		cout << endl;
	//	}



	Grid<std::string> g(4, 3); //4x3

	std::string gml1 = g.setElement(0, 0, "hundre");
	std::string gml2 = g.setElement(0, 0, "hundre og en");
	std::string gml3 = g.setElement(2, 1, "hundre og tjueen");
	
	std::cout << "gammel verdi i 0,0 er " << gml1 << " og ny verdi er " << g.getElement(0, 0) << std::endl;
	std::cout << "gammel verdi i 0,0 er " << gml2 << " og ny verdi er " << g.getElement(0, 0) << std::endl;
	std::cout << "gammel verdi i 2,1 er " << gml3 << " og ny verdi er " << g.getElement(2, 1) << std::endl;

	return 0;

}