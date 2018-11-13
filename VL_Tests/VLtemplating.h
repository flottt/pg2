#include <iostream>
template <typename AA, typename BB> 
struct wicky; //not accept <AA, BB>

template <typename AA, typename BB> 
class mistStack {
  private: 
	const int size; 
	AA aaa; 
	BB bbb; 

  public:
	mistStack(AA, BB, const int); 
	AA operator+ (const BB & bb);
};


int templating_main(); 
//int templating_main2();




template<typename AA, typename BB>
AA mistStack<AA, BB>::operator+(const BB & bb) {
	return this->aaa + bb;
}
