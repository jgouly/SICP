// -std=c++11
template<int Row, int Column>
struct Pascal {
  constexpr static unsigned Value = 
    Pascal<Row - 1, Column - 1>::Value + Pascal<Row - 1, Column>::Value; 
};

template<int Column>
struct Pascal<1, Column> {
  constexpr static unsigned Value = 1;
};

template<int Row>
struct Pascal<Row, 1> {
  constexpr static unsigned Value = 1;
};

template<int Same>
struct Pascal<Same, Same> {
  constexpr static unsigned Value = 1;
};

constexpr int pascal(int row, int column)
{
	return (1 == row || 1 == column || row == column) ? 1 :
		pascal(row - 1, column - 1) + pascal(row - 1, column);
}

int main()
{
  //return Pascal<4, 3>::Value;
	return pascal(4, 3);
}
