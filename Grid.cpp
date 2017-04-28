#include "Grid.h"



template<typename T>
int Grid<T>::x_coord(int index) const {
			return index % size_hor;
}
template<typename T>
int Grid<T>::y_coord(int index) const {
	return static_cast<int> (index / size_vert);
}
template<typename T>
int Grid<T>::coordToIndx(int x, int y) const {
	return (y*size_hor + x);

}
template<typename T>
T& Grid<T>::getElement(int x, int y) {
	return vec.at(coordToIndx(x, y));
}
template<typename T>
T Grid<T>::setElement(int x, int y, T verdi) {
	T temp = vec.at(coordToIndx(x, y));
	vec.at(coordToIndx(x, y)) = verdi;
	return temp;
}
template<typename T>
Row_iterator Grid<T>::begin() {
	return Row_iterator(&row_vec, 0);
}
template<typename T>
Row_iterator Grid<T>::end() {
	return Row_iterator(&row_vec, row_vec.size());
}
template<typename T>
Grid<T>::~Grid() {
	for(auto r: row_vec) delete r;
	std::cout << "Grid::~Grid()\n";
}
template<typename T>
void Grid<T>::init_row_vec() {
	//Horisontale rekker
	for(int y = 0;y < size_vert;++y) {
		Row* r = new Row();
		for(int x = 0; x < size_hor; ++x) {
			r->add_data(std::make_pair(x, y));	
		}

	row_vec.push_back(r);
	}//for(int y ...
	//Vertikale rekker
	for(int x = 0;x < size_vert;++x) {
		Row* r = new Row();
		for(int y = 0; y < size_hor; ++y){
			r->add_data(std::make_pair(x, y));	
		}
		row_vec.push_back(r);
	}//for(int x ...

	if(size_hor == size_vert) { //Dersom kvadratisk Grid
		Row* r1 = new Row();
		Row* r2 = new Row();
		for(int xy = 0;xy < size_hor;++xy) {
			r1->add_data(make_pair(xy, xy));
		}
		row_vec.push_back(r1);
		for(int xy = 0;xy < size_hor;++xy) {
			r2->add_data(make_pair((size_hor-1)-xy, xy));
		}
		row_vec.push_back(r2);
	}//if
}//init_row_vec()

