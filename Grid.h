// Grid.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
int vec_indx = game_size + (i*game_size) - (i + 1);
k.x = vec_indx % game_size;
k.y = static_cast<int> (vec_indx / game_size);
*/
using namespace std;
class Row;
class Row_iterator {
	int pos;
	Row* row;
	//int Rows_size;
	std::vector<Row*>* rows;
public:
	Row_iterator(std::vector<Row*>* r, int p) : rows{ r }, pos{ p } {}
	Row& operator*() {
		return *rows->at(pos);
	}
	Row_iterator& operator++() {
		++pos;
		return *this;
	}
	Row_iterator& operator--() {
		--pos;
		return *this;
	}
	bool operator==(const Row_iterator& other) const { return pos == other.pos; }
	bool operator!=(const Row_iterator& other) const { return !(*this == other); }

};

class Row {
	std::vector<std::pair<int, int>> row_data{};
public:
	void add_data(std::pair<int, int> p) {
		row_data.push_back(p);
	}
	std::pair<int, int> row_coords(int pos) {
		return row_data.at(pos);
	}
	const std::vector<std::pair<int, int>>& data() {
		return row_data;
	}

};
template<typename T>
class Grid {
	int size_hor, size_vert;
	std::vector<T> vec{};
	std::vector<Row*> row_vec{};

public:
	Grid() :Grid(0) {};
	Grid(int sz) :Grid(sz, sz) {}
	Grid(int h, int v) : size_hor{ h }, size_vert{ v } {
		vec.resize(size_hor*size_vert);
		init_row_vec();
	}
	Grid(const Grid& src) = delete;
	Grid& operator=(const Grid& src) = delete;
	Grid(Grid&& src) = delete;
	Grid& operator=(Grid&& src) = delete;
	
	int num_rows() const {return size_vert;}
	int num_columns() const {return size_hor;}

	int x_coord(int index) const;
	int y_coord(int index) const;

	int coordToIndx(int x, int y) const;
	T& getElement(int x, int y);
	T setElement(int x, int y, T verdi);
	Row_iterator begin();
	Row_iterator end();
	~Grid();

private:
	void init_row_vec();

};






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
	for (auto r : row_vec) delete r;
	std::cout << "Grid::~Grid()\n";
}
template<typename T>
void Grid<T>::init_row_vec() {
	//Horisontale rekker
	for (int y = 0; y < size_vert; ++y) {
		Row* r = new Row();
		for (int x = 0; x < size_hor; ++x) {
			r->add_data(std::make_pair(x, y));
		}

		row_vec.push_back(r);
	}//for(int y ...
	 //Vertikale rekker
	for (int x = 0; x < size_vert; ++x) {
		Row* r = new Row();
		for (int y = 0; y < size_hor; ++y) {
			r->add_data(std::make_pair(x, y));
		}
		row_vec.push_back(r);
	}//for(int x ...

	if (size_hor == size_vert) { //Dersom kvadratisk Grid
		Row* r1 = new Row();
		Row* r2 = new Row();
		for (int xy = 0; xy < size_hor; ++xy) {
			r1->add_data(make_pair(xy, xy));
		}
		row_vec.push_back(r1);
		for (int xy = 0; xy < size_hor; ++xy) {
			r2->add_data(make_pair((size_hor - 1) - xy, xy));
		}
		row_vec.push_back(r2);
	}//if
}//init_row_vec()

template <typename T>
std::ostream& operator<<(std::ostream& os, Grid<T> &grid) {
	//for(auto r = std::begin(grid);r<std::begin(grid)+num_rows();r++) {
	for(int y = 0;y<grid.num_rows();++y) 
		for(int x = 0;x<grid.num_columns();++x)
			os << grid.getElement(x, y);
			
	return os;	
		
	
	
}




